########################################
############## SELECAO #################
########################################

#setwd("C:/Users/enbor/aula")

library(doParallel)
cl <- makePSOCKcluster(8) # numero dnucleos do processador
registerDoParallel(cl)
#stopCluster(cl)
#registerDoSEQ()
#remove(cl)

library(foreign)

data <- read.arff('./labor.arff')

dim(data) # dimensions rows,columns
table(data$class)
summary(data)

colnames(data) <- make.names(colnames(data))

# Caso carregado CSV, devem ser atribuídos os tipos para cada atributo

# para variaveis categoricas nominais
#   data$var <- factor(dataset$var)
# para variaveis numericas, tanto discretas quanto continuas
#   data$var <- numeric(data$var)
# para variaveis categoricas ordinais
#   data$var <- ordered(data$var)
#
# verificar com o summary e no glabal environment

################################################
############ PRE-PROCESSAMENTO #################
######## LIDANDO COM VALORES MISSING ########### 
################################################

library(VIM) #missPlot

ppData <- data
missPlotData <- aggr(ppData, numbers=TRUE, sortVars=TRUE, labels=names(ppData), cex.axis=0.4, gap=2)

# removendo instancias com classe missing
ppData <- ppData[!is.na(ppData$class),]

# Analisando tuplas com p% de atributos = missing
p <- 0.5
missingCount <- rowSums(is.na(ppData[,]))
plot(missingCount)
maxMissing <- max(missingCount)
{ hist(missingCount, breaks=maxMissing)
  abline(v=p*maxMissing, col="blue")
}

ppDataRemHalfMiss <- ppData[missingCount <= p*maxMissing,]
missPlotData <- aggr(ppDataRemHalfMiss, numbers=TRUE, sortVars=TRUE, labels=names(ppDataRemHalfMiss), cex.axis=0.4, gap=2)

# Removendo atributos com mais de p% das tuplas = missing"
p <- 0.3
atribP <- missPlotData$missings[missPlotData$missings$Count <= p*(nrow(ppDataRemHalfMiss)),] 
ppDataRemHalfMissRemAtt <- ppDataRemHalfMiss[,atribP$Variable]

missPlotData <- aggr(ppDataRemHalfMissRemAtt, numbers=TRUE, sortVars=TRUE, labels=names(ppDataRemHalfMissRemAtt), cex.axis=0.4, gap=2)

dataset <- ppDataRemHalfMissRemAtt

library(caret)

# Dividindo em treino e teste para imputar valores missing

set.seed(123)
particao <- createDataPartition(dataset$class, p=0.74, list=FALSE)
trainData <- dataset[particao,]
testData <- dataset[-particao,]

#imputando variaveis numericas no treino com a media
missPlotTrain <- aggr(trainData, numbers=TRUE, sortVars=TRUE, labels=names(trainData), cex.axis=.6, gap=3)
val<-NA
for(i in 1:ncol(trainData)){
  if (is.numeric(trainData[,i]))
    val[i] <- mean(trainData[,i], na.rm = TRUE)
  trainData[is.na(trainData[,i]), i] <- val[i]
}
missPlotTrain <- aggr(trainData, numbers=TRUE, sortVars=TRUE, labels=names(trainData), cex.axis=.6, gap=3)

#imputando variaveis categoricas no treino com a moda
Moda <- function(x) {
  ux <- unique(x)
  ux[which.max(tabulate(match(x, ux)))]
}

for(i in 1:ncol(trainData)){
  if (is.factor(trainData[,i]) & !is.ordered(trainData[,i]))
    trainData[is.na(trainData[,i]), i] <- Moda(trainData[,i])
}  
missPlotTrain <- aggr(trainData, numbers=TRUE, sortVars=TRUE, labels=names(trainData), cex.axis=.6, gap=3)

#imputando variaveis numericas no teste media previamente calculada
missPlotTest <- aggr(testData, numbers=TRUE, sortVars=TRUE, labels=names(testData), cex.axis=.6, gap=3)
for(i in 1:ncol(testData)){
  if (is.numeric(testData[,i]))
    testData[is.na(testData[,i]), i] <- val[i]
}
missPlotTrain <- aggr(trainData, numbers=TRUE, sortVars=TRUE, labels=names(trainData), cex.axis=.6, gap=3)
#imputando variaveis categoricas no teste moda previamente calculada  
for(i in 1:ncol(testData)){
  if (is.factor(testData[,i]) & !is.ordered(testData[,i]))
    testData[is.na(testData[,i]), i] <- Moda(trainData[,i])
}  
missPlotTrain <- aggr(trainData, numbers=TRUE, sortVars=TRUE, labels=names(trainData), cex.axis=.6, gap=3)



  
  ###########################################################
  ############# TRANSFORMACAO ###############################
  ############# Feature Selection ###########################
  ###########################################################
  
  #library(mlbench) # detach(package:mlbench)

  numericCol <- unlist(lapply(trainData, is.numeric))
  numericTrainData <- trainData[,numericCol]
  
  correlationMatrix <- cor(numericTrainData)
  p <- 0.6 # apenas um exemplo. Correlacao muito forte deve ser maior que 0.9 
  highlyCorrelated <- findCorrelation(correlationMatrix, cutoff = p, names = TRUE)
  
  # analisar as diferencas para os atributos numericos com alta correlacao
  
  for (i in 1:length(highlyCorrelated)){
    boxplot(trainData[,highlyCorrelated[i]] ~ trainData$class)
  }
  
  # remover o atributo que menos distingue a classe
  remVar <- "wage.increase.second.year"
  trainData <- trainData[,!(names(trainData) %in% remVar)]
  testData <- testData[,!(names(testData) %in% remVar)]

  #### Recursive Feature Elimination - Pode ser usado qq classificador
  
  rfeCrtl <- rfeControl(functions=rfFuncs, method="repeatedcv", number=3, repeats=1, returnResamp="all", seeds=set.seed(1234))
  
  #Rprof()
  rfeResults <- rfe(class ~., data=trainData,  
                    sizes=seq(2,  ceiling( min( max(2/3*(ncol(trainData)-1),sqrt(nrow(trainData))) ,ncol(trainData)) ), by=1),
                    rfeControl=rfeCrtl, method="glm")
  
  #Rprof(NULL)
  #summaryRprof()
  rfeResults
  plot(rfeResults, type = c("o", "g"))
  predictors(rfeResults) 
  cols <- c("vacation", "statutory.holidays", "wage.increase.first.year", "class")
  trainData <- trainData[,cols]
  testData <- testData[,cols]

  ###########################################################################
  #### Aplicando C4.5 sobre dados imputados 
  ###########################################################################
  
  
  modelLookup("rpart") # 
  
  trainCtrl <- trainControl(method="cv", number=3, savePredictions=TRUE, # none, cv (number=10), repeatedcv (repeats=5), p
                            classProbs=TRUE, summaryFunction=twoClassSummary , # multiClassSummary
                            sampling=NULL, seed=set.seed(123)) 
  
  #Rprof()
  
  modelTree <- train(class ~., data=trainData, trControl=trainCtrl, method="rpart", metric = "ROC", tuneLength = 5)  
  # investigaros melhores dos 5 valores e fazer o ajuste manual
  modelTree$results
  modelTree <- train(class ~., data=trainData, trControl=trainCtrl, method="rpart", metric = "ROC", tuneGrid=expand.grid(cp = c(0.01, 0.15, 0.2) ) )  
  modelTree$results
  #Rprof(NULL)
  #summaryRprof()
  
  # Avaliando o modelo sobre os dados de teste
  print("\n avaliando nos dados de teste")
  
  predictions <- predict(modelTree, testData) 
  cm <- confusionMatrix(predictions, testData$class)
  cm
  
  # plotando curvas ROC
  
  library(pROC)
  
  predictionsProb <- predict(modelTree, testData, type = "prob") 
  predictionsProb
  roc = roc(testData$class, predictionsProb[,"good"])
  
  roc
  
  plot (roc)
  plot(x = roc, print.thres = T, print.auc = T, auc.polygon = T, max.auc.polygon=T, identity=T, print.auc.x= 0.4, print.auc.y = 0.3)
  
  # Configuracoes dos modelos aprendidos
  
  plot(modelTree)
  modelTree$bestTune
  modelTree$finalModel
  library("rpart.plot")
  rpart.plot(modelTree$finalModel)
  print(varImp(modelTree, scale=TRUE))
  plot(varImp(modelTree, scale=TRUE))
  
  
  ###########################################################################
  #### Aplicando Random Forest sobre dados imputados 
  ###########################################################################
  
  # configuracao do modelo
  
  modelLookup("rf") #visualizar hyperparametros
  
  trainCtrl <- trainControl(method="cv", number=3, savePredictions=TRUE, # none, cv (number=5), repeatedcv (repeats=5), p
                            classProbs=TRUE, summaryFunction=twoClassSummary , # multiClassSummary
                            sampling=NULL, seed=set.seed(123)) 
  
  #Another major difference is that we only consider a Random subset of predictors m each time we do a split on training examples. Whereas usually in Trees we find all the predictors while doing a split and choose best amongst them. Typically m=sqrt(p) where p are the number of predictors.
  
  #Rprof()
  modelRF <- train(class ~., data=trainData, trControl=trainCtrl, method="rf", metric = "ROC", tuneGrid=expand.grid(.mtry = seq(1, ceiling(1.5*sqrt(ncol(trainData)-1)), by=1) ) )  
  #Rprof(NULL)
  #summaryRprof()
  
  # Avaliando o modelo sobre os dados de teste
  print("\n avaliando nos dados de teste")
  
  predictions <- predict(modelRF, testData) 
  cm <- confusionMatrix(predictions, testData$class)
  cm
  cmpr <- confusionMatrix(predictions, testData$class, mode = "prec_recall")
  cmpr
  # plotando curvas ROC
  
  library(pROC)
  
  predictionsProb <- predict(modelRF, testData, type = "prob") 
  predictionsProb
  roc = roc(testData$class, predictionsProb[,"good"])
  
  roc
  
  plot (roc)
  plot(x = roc, print.thres = T, print.auc = T, auc.polygon = T, max.auc.polygon=T, identity=T, print.auc.x= 0.4, print.auc.y = 0.3)
  
  # Configuracoes dos modelos aprendidos
  
  plot(modelRF)
  modelRF$bestTune
  modelRF$finalModel
  plot(modelRF$finalModel)
  print(varImp(modelRF, scale=TRUE))
  plot(varImp(modelRF, scale=TRUE))
  