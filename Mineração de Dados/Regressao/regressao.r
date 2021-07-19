# configuracao do modelo

modelLookup("svmLinear") #visualizar hyperparametros
modelLookup("svmRadial") #visualizar hyperparametros

trainCtrl <- trainControl(method="repeatedcv", number=10, repeats=5)

modelSvmL <- train(dias_internacao ~., data=trainData, trControl=trainCtrl,
                     method="svmLinear", preProcess = c("center", "scale"),
                     tuneLength=10) 

# ajustando manualmente os melhores valores do hiperparametro C com base no resultado anterior 
# modelSvmL <- train(dias_internacao ~., data=trainData, trControl=trainCtrl,
#                      method="svmLinear", preProcess = c("center", "scale"),
#                      tuneGrid=expand.grid(C = c(0.01, 0.025, 0.05, 0.1, 0.25))) 					 
 
# modelSvmR <- train(dias_internacao ~., data=trainData, trControl=trainCtrl,
#                   method="svmRadial", preProcess = c("center", "scale"),
#                   tuneLength=10)  

 
# ajustando manualmente os melhores valores do hiperparametro C com base no resultado anterior 
modelSvmR <- train(dias_internacao ~., data=trainData, trControl=trainCtrl,
                      method="svmRadial", preProcess = c("center", "scale"),
                     tuneGrid=expand.grid(C = c(0,05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35), sigma = c(0.25, 0.275, 0.3, 0.325, 0.35)))  

plot(modelSvmL)
plot(modelSvmR)

#treinar mais um kernel svmPoly degree (Polynomial Degree) scale (Scale) C (Cost)
# predizer e avaliar RMSE
# alterar os valores dos >60 +- ver hist
  
library("ModelMetrics")

predictionsL <- predict(modelSvmL, testData)
RMSEL <- rmse(testData$dias_internacao,predictionsL)

predictionsR <- predict(modelSvmR, testData)
RMSER <- rmse(testData$dias_internacao,predictionsR)
