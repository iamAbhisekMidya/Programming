-- MySQL dump 10.13  Distrib 8.0.27, for Linux (x86_64)
--
-- Host: localhost    Database: DB_CMSA
-- ------------------------------------------------------
-- Server version	8.0.27-0ubuntu0.20.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Account`
--

DROP TABLE IF EXISTS `Account`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Account` (
  `account_number` varchar(10) NOT NULL,
  `branch_id` varchar(10) DEFAULT NULL,
  `balance` decimal(10,0) DEFAULT NULL,
  PRIMARY KEY (`account_number`),
  KEY `branch_id` (`branch_id`),
  CONSTRAINT `Account_ibfk_1` FOREIGN KEY (`branch_id`) REFERENCES `Branch` (`branch_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Account`
--

LOCK TABLES `Account` WRITE;
/*!40000 ALTER TABLE `Account` DISABLE KEYS */;
INSERT INTO `Account` VALUES ('A-002','B-04',11400),('A-005','B-01',510),('A-009','B-04',5000),('A-052','B-05',15000),('A-101','B-01',75000),('A-105','B-04',400),('A-108','B-02',96400),('A-111','B-02',4000),('A-451','B-03',310),('A-456','B-03',64000),('A-767','B-03',9150);
/*!40000 ALTER TABLE `Account` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Borrower`
--

DROP TABLE IF EXISTS `Borrower`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Borrower` (
  `customer_id` varchar(10) DEFAULT NULL,
  `loan_number` varchar(10) DEFAULT NULL,
  KEY `customer_id` (`customer_id`),
  KEY `loan_number` (`loan_number`),
  CONSTRAINT `Borrower_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `Customer` (`customer_id`),
  CONSTRAINT `Borrower_ibfk_2` FOREIGN KEY (`loan_number`) REFERENCES `Loan` (`loan_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Borrower`
--

LOCK TABLES `Borrower` WRITE;
/*!40000 ALTER TABLE `Borrower` DISABLE KEYS */;
INSERT INTO `Borrower` VALUES ('C-01','L-01'),('C-08','L-02'),('C-05','L-03'),('C-03','L-04'),('C-09','L-05');
/*!40000 ALTER TABLE `Borrower` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Branch`
--

DROP TABLE IF EXISTS `Branch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Branch` (
  `branch_id` varchar(10) NOT NULL,
  `branch_name` varchar(20) DEFAULT NULL,
  `branch_city` varchar(10) DEFAULT NULL,
  `assets` decimal(10,0) DEFAULT NULL,
  PRIMARY KEY (`branch_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Branch`
--

LOCK TABLES `Branch` WRITE;
/*!40000 ALTER TABLE `Branch` DISABLE KEYS */;
INSERT INTO `Branch` VALUES ('B-01','BHOWANIPORE','KOLKATA',90000),('B-02','JADAVPUR','KOLKATA',67000),('B-03','BEHALA','KOLKATA',298000),('B-04','GARIA','KOLKATA',30000),('B-05','SILIGURI','SILIGURI',35000);
/*!40000 ALTER TABLE `Branch` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Customer`
--

DROP TABLE IF EXISTS `Customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Customer` (
  `customer_id` varchar(10) NOT NULL,
  `customer_name` varchar(20) DEFAULT NULL,
  `customer_street` varchar(20) DEFAULT NULL,
  `customer_city` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Customer`
--

LOCK TABLES `Customer` WRITE;
/*!40000 ALTER TABLE `Customer` DISABLE KEYS */;
INSERT INTO `Customer` VALUES ('C-01','ABHISEK MIDYA','JADAVPUR','KOLKATA'),('C-02','AHIN SUBHRA HALDER','GARIA','KOLKATA'),('C-03','ARNAB DEY','TOLLYGUNGE','KOLKATA'),('C-04','KRISHNENDU GANGULI','AC HOWRAH','HOWRAH'),('C-05','SUBHAJIT GARAI','DHAKURIA','KOLKATA'),('C-06','SAGNIK KUMAR GHOSH','BHOWANIPORE','KOLKATA'),('C-07','SUVAM PAL','SILIGURI','SILIGURI'),('C-08','RAKESH DAS','BEHALA','KOLKATA'),('C-09','SUPRIO SAHA','BEHALA','KOLKATA'),('C-10','BUDHADITTYA SARKAR','HAZRA','KOLKATA');
/*!40000 ALTER TABLE `Customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Depositor`
--

DROP TABLE IF EXISTS `Depositor`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Depositor` (
  `customer_id` varchar(10) DEFAULT NULL,
  `account_number` varchar(10) DEFAULT NULL,
  KEY `customer_id` (`customer_id`),
  KEY `account_number` (`account_number`),
  CONSTRAINT `Depositor_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `Customer` (`customer_id`),
  CONSTRAINT `Depositor_ibfk_2` FOREIGN KEY (`account_number`) REFERENCES `Account` (`account_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Depositor`
--

LOCK TABLES `Depositor` WRITE;
/*!40000 ALTER TABLE `Depositor` DISABLE KEYS */;
INSERT INTO `Depositor` VALUES ('C-01','A-101'),('C-02','A-002'),('C-03','A-005'),('C-04','A-451'),('C-05','A-108'),('C-06','A-767'),('C-07','A-009'),('C-08','A-456'),('C-09','A-108'),('C-10','A-105');
/*!40000 ALTER TABLE `Depositor` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Loan`
--

DROP TABLE IF EXISTS `Loan`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Loan` (
  `loan_number` varchar(10) NOT NULL,
  `branch_id` varchar(10) DEFAULT NULL,
  `amount` decimal(10,0) DEFAULT NULL,
  PRIMARY KEY (`loan_number`),
  KEY `branch_id` (`branch_id`),
  CONSTRAINT `Loan_ibfk_1` FOREIGN KEY (`branch_id`) REFERENCES `Account` (`branch_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Loan`
--

LOCK TABLES `Loan` WRITE;
/*!40000 ALTER TABLE `Loan` DISABLE KEYS */;
INSERT INTO `Loan` VALUES ('L-01','B-01',9089),('L-02','B-02',908),('L-03','B-04',2000),('L-04','B-04',9000),('L-05','B-03',3500);
/*!40000 ALTER TABLE `Loan` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Payment`
--

DROP TABLE IF EXISTS `Payment`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Payment` (
  `loan_number` varchar(10) DEFAULT NULL,
  `payment_number` varchar(10) DEFAULT NULL,
  `payment_date` date DEFAULT NULL,
  `payment_amount` decimal(10,0) DEFAULT NULL,
  KEY `loan_number` (`loan_number`),
  CONSTRAINT `Payment_ibfk_1` FOREIGN KEY (`loan_number`) REFERENCES `Loan` (`loan_number`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Payment`
--

LOCK TABLES `Payment` WRITE;
/*!40000 ALTER TABLE `Payment` DISABLE KEYS */;
INSERT INTO `Payment` VALUES ('L-01','P-01','2021-11-30',2000),('L-02','P-02','2019-07-19',9000),('L-03','P-04','2018-08-12',8000),('L-04','P-03','2020-06-21',100),('L-05','P-05','2019-02-17',2050);
/*!40000 ALTER TABLE `Payment` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-07 12:56:20
