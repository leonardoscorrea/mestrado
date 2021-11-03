-- MariaDB dump 10.19  Distrib 10.5.12-MariaDB, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: ri
-- ------------------------------------------------------
-- Server version	10.5.12-MariaDB-0ubuntu0.21.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `collection`
--

DROP TABLE IF EXISTS `collection`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `collection` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `collection`
--

LOCK TABLES `collection` WRITE;
/*!40000 ALTER TABLE `collection` DISABLE KEYS */;
INSERT INTO `collection` VALUES (1,'trabalho1'),(2,'PageRank');
/*!40000 ALTER TABLE `collection` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `file_word`
--

DROP TABLE IF EXISTS `file_word`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `file_word` (
  `file_id` int(10) NOT NULL,
  `word_id` int(10) NOT NULL,
  `frequence` int(10) DEFAULT NULL,
  `tf` float DEFAULT 0,
  `tfidf` float DEFAULT 0,
  PRIMARY KEY (`file_id`,`word_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `file_word`
--

LOCK TABLES `file_word` WRITE;
/*!40000 ALTER TABLE `file_word` DISABLE KEYS */;
INSERT INTO `file_word` VALUES (1,1,0,0,0),(1,2,2,1,0.39794),(1,3,0,0,0),(1,4,0,0,0),(1,5,0,0,0),(1,6,1,0.5,0.349485),(1,7,0,0,0),(1,8,1,0.5,0.349485),(1,9,1,0.5,0.110924),(1,10,1,0.5,0.349485),(1,11,0,0,0),(1,12,0,0,0),(1,13,0,0,0),(1,14,0,0,0),(1,15,1,0.5,0.19897),(2,1,0,0,0),(2,2,0,0,0),(2,3,1,1,0.69897),(2,4,1,1,0.69897),(2,5,0,0,0),(2,6,0,0,0),(2,7,0,0,0),(2,8,0,0,0),(2,9,1,1,0.221849),(2,10,0,0,0),(2,11,0,0,0),(2,12,1,1,0.69897),(2,13,0,0,0),(2,14,1,1,0.69897),(2,15,0,0,0),(3,1,1,1,0.69897),(3,2,0,0,0),(3,3,0,0,0),(3,4,0,0,0),(3,5,0,0,0),(3,6,0,0,0),(3,7,1,1,0.69897),(3,8,0,0,0),(3,9,1,1,0.221849),(3,10,0,0,0),(3,11,0,0,0),(3,12,0,0,0),(3,13,0,0,0),(3,14,0,0,0),(3,15,0,0,0),(4,1,0,0,0),(4,2,1,1,0.39794),(4,3,0,0,0),(4,4,0,0,0),(4,5,0,0,0),(4,6,0,0,0),(4,7,0,0,0),(4,8,0,0,0),(4,9,0,0,0),(4,10,0,0,0),(4,11,0,0,0),(4,12,0,0,0),(4,13,1,1,0.69897),(4,14,0,0,0),(4,15,0,0,0),(5,1,0,0,0),(5,2,0,0,0),(5,3,0,0,0),(5,4,0,0,0),(5,5,1,1,0.69897),(5,6,0,0,0),(5,7,0,0,0),(5,8,0,0,0),(5,9,0,0,0),(5,10,0,0,0),(5,11,1,1,0.69897),(5,12,0,0,0),(5,13,0,0,0),(5,14,0,0,0),(5,15,1,1,0.39794);
/*!40000 ALTER TABLE `file_word` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `files`
--

DROP TABLE IF EXISTS `files`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `files` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `link` varchar(500) DEFAULT NULL,
  `content` varchar(1000) DEFAULT NULL,
  `collection_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `files`
--

LOCK TABLES `files` WRITE;
/*!40000 ALTER TABLE `files` DISABLE KEYS */;
INSERT INTO `files` VALUES (1,'xadrez.txt',NULL,'O peão e o cavalo são peças do xadrez. O cavalo é melhor do jogo.',1),(2,'jogo.txt',NULL,'A jogada envolveu a torre, o peão e o rei',1),(3,'rodeio.txt',NULL,'O peão laçou o boi',1),(4,'fazenda.txt',NULL,'Cavalo de rodeio!',1),(5,'policia.txt',NULL,'Policiais o jogaram no xadrez',1);
/*!40000 ALTER TABLE `files` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `page_link`
--

DROP TABLE IF EXISTS `page_link`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `page_link` (
  `page_origin_id` int(10) NOT NULL,
  `page_target_id` int(10) NOT NULL,
  PRIMARY KEY (`page_origin_id`,`page_target_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `page_link`
--

LOCK TABLES `page_link` WRITE;
/*!40000 ALTER TABLE `page_link` DISABLE KEYS */;
INSERT INTO `page_link` VALUES (42,41),(43,41),(43,46),(44,41),(44,43),(45,41),(45,44),(46,44);
/*!40000 ALTER TABLE `page_link` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pages`
--

DROP TABLE IF EXISTS `pages`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `pages` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `link` varchar(500) DEFAULT NULL,
  `collection_id` int(10) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=47 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pages`
--

LOCK TABLES `pages` WRITE;
/*!40000 ALTER TABLE `pages` DISABLE KEYS */;
INSERT INTO `pages` VALUES (41,'paginaD','paginaD.html',2),(42,'paginaF','paginaF.html',2),(43,'paginaC','paginaC.html',2),(44,'paginaB','paginaB.html',2),(45,'paginaE','paginaE.html',2),(46,'paginaA','paginaA.html',2);
/*!40000 ALTER TABLE `pages` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `words`
--

DROP TABLE IF EXISTS `words`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `words` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `word` varchar(100) DEFAULT NULL,
  `df` int(11) DEFAULT 0,
  `idf` float DEFAULT 0,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=16 DEFAULT CHARSET=utf8mb4;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `words`
--

LOCK TABLES `words` WRITE;
/*!40000 ALTER TABLE `words` DISABLE KEYS */;
INSERT INTO `words` VALUES (1,'boi',1,0.69897),(2,'cavalo',2,0.39794),(3,'envolveu',1,0.69897),(4,'jogada',1,0.69897),(5,'jogaram',1,0.69897),(6,'jogo',1,0.69897),(7,'lacou',1,0.69897),(8,'melhor',1,0.69897),(9,'peao',3,0.221849),(10,'pecas',1,0.69897),(11,'policiais',1,0.69897),(12,'rei',1,0.69897),(13,'rodeio',1,0.69897),(14,'torre',1,0.69897),(15,'xadrez',2,0.39794);
/*!40000 ALTER TABLE `words` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-11-03 17:06:06
