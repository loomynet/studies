-- MySQL dump 10.13  Distrib 8.0.36, for Linux (x86_64)
--
-- Host: 127.0.0.1    Database: ST84816_Project_Consultancy
-- ------------------------------------------------------
-- Server version	8.0.40-0ubuntu0.24.04.1

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `Employees`
--

DROP TABLE IF EXISTS `Employees`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Employees` (
  `emp_id` varchar(6) NOT NULL,
  `shop_id` int NOT NULL,
  `position_id` varchar(4) NOT NULL,
  `emp_name` varchar(30) NOT NULL,
  `emp_surname` varchar(30) NOT NULL,
  `emp_date_of_birth` date NOT NULL,
  `emp_gender` varchar(10) NOT NULL,
  `emp_salary` int NOT NULL,
  `emp_phone_number` varchar(20) DEFAULT NULL,
  `emp_email` varchar(50) CHARACTER SET armscii8 COLLATE armscii8_general_ci DEFAULT NULL,
  PRIMARY KEY (`emp_id`),
  UNIQUE KEY `emp_surname_UNIQUE` (`emp_surname`),
  KEY `shop_id` (`shop_id`),
  KEY `position_id` (`position_id`),
  CONSTRAINT `Employees_ibfk_1` FOREIGN KEY (`shop_id`) REFERENCES `Shops` (`shop_id`),
  CONSTRAINT `Employees_ibfk_2` FOREIGN KEY (`position_id`) REFERENCES `Positions` (`position_id`),
  CONSTRAINT `Employees_chk_1` CHECK (regexp_like(`emp_id`,_utf8mb4'^[A-Z]{2}[0-9]{4}$'))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Employees`
--

LOCK TABLES `Employees` WRITE;
/*!40000 ALTER TABLE `Employees` DISABLE KEYS */;
INSERT INTO `Employees` VALUES ('CA0101',1,'AD01','Anna','Egle','2001-08-24','F',2200,'+37123234545','ae@inbox.lv'),('CB0102',1,'WA01','Bertran','Kuper','2002-04-12','M',900,'+37156678756',NULL),('CN0103',2,'AD01','Norah','Liepa','2001-05-13','F',2000,'+37176458734',NULL),('CP0104',2,'CL01','Peter','Long','2004-05-10','M',700,NULL,'pl@gmail.com'),('CP0105',3,'AD01','Paul','Thin','2001-09-10','M',2400,NULL,'pt@inbox.lv'),('CT0106',3,'WA01','Tina','Grube','1995-12-12','F',1400,'+37134567654',NULL);
/*!40000 ALTER TABLE `Employees` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Feedbacks`
--

DROP TABLE IF EXISTS `Feedbacks`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Feedbacks` (
  `feedback_id` int NOT NULL AUTO_INCREMENT,
  `emp_id` varchar(6) NOT NULL,
  `feedback_type` varchar(20) NOT NULL,
  `feedback_comment` varchar(255) NOT NULL,
  `feedback_date` date NOT NULL,
  `feedback_contact_details` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`feedback_id`),
  KEY `emp_id` (`emp_id`),
  CONSTRAINT `Feedbacks_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `Employees` (`emp_id`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Feedbacks`
--

LOCK TABLES `Feedbacks` WRITE;
/*!40000 ALTER TABLE `Feedbacks` DISABLE KEYS */;
INSERT INTO `Feedbacks` VALUES (1,'CA0101','Suggestion','More tables needed in the Coffee Shop','2023-05-07','nn@mail.lt'),(2,'CB0102','Complaint','Slow service','2023-02-01',NULL),(3,'CT0106','Complaint','Cold food','2023-08-08',NULL),(4,'CP0105','Suggestion','Better choice of cakes required','2023-02-03','+37145676543');
/*!40000 ALTER TABLE `Feedbacks` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `OrderProduct`
--

DROP TABLE IF EXISTS `OrderProduct`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `OrderProduct` (
  `order_product_id` int NOT NULL AUTO_INCREMENT,
  `order_id` varchar(6) NOT NULL,
  `product_id` int NOT NULL,
  `order_product_quantity` int NOT NULL,
  PRIMARY KEY (`order_product_id`),
  KEY `OrderProduct_ibfk_1` (`order_id`),
  KEY `OrderProduct_ibfk_2` (`product_id`),
  CONSTRAINT `OrderProduct_ibfk_1` FOREIGN KEY (`order_id`) REFERENCES `Orders` (`order_id`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `OrderProduct_ibfk_2` FOREIGN KEY (`product_id`) REFERENCES `Products` (`product_id`)
) ENGINE=InnoDB AUTO_INCREMENT=10 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `OrderProduct`
--

LOCK TABLES `OrderProduct` WRITE;
/*!40000 ALTER TABLE `OrderProduct` DISABLE KEYS */;
INSERT INTO `OrderProduct` VALUES (1,'AS0001',2,30),(2,'AS0001',3,40),(4,'AS0003',6,3),(5,'AS0003',7,5),(6,'AS0004',4,10),(7,'AS0005',6,15),(8,'AS0006',6,5),(9,'AS0006',7,4);
/*!40000 ALTER TABLE `OrderProduct` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Orders`
--

DROP TABLE IF EXISTS `Orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Orders` (
  `order_id` varchar(6) NOT NULL,
  `shop_id` int NOT NULL,
  `supplier_id` varchar(4) NOT NULL,
  `order_issue_date` date NOT NULL,
  `order_delivery_date` date NOT NULL,
  `order_total_cost` decimal(10,2) DEFAULT NULL,
  PRIMARY KEY (`order_id`),
  KEY `shop_id` (`shop_id`),
  KEY `supplier_id` (`supplier_id`),
  CONSTRAINT `Orders_ibfk_1` FOREIGN KEY (`shop_id`) REFERENCES `Shops` (`shop_id`),
  CONSTRAINT `Orders_ibfk_2` FOREIGN KEY (`supplier_id`) REFERENCES `Suppliers` (`supplier_id`),
  CONSTRAINT `Orders_chk_1` CHECK (regexp_like(`order_id`,_utf8mb4'^[A-Z]{2}[0-9]{4}$'))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Orders`
--

LOCK TABLES `Orders` WRITE;
/*!40000 ALTER TABLE `Orders` DISABLE KEYS */;
INSERT INTO `Orders` VALUES ('AS0001',1,'SU01','2022-12-01','2022-12-15',NULL),('AS0002',1,'SU02','2022-12-20','2023-01-15',NULL),('AS0003',1,'SU04','2023-01-10','2023-01-18',NULL),('AS0004',2,'SU03','2023-01-05','2023-02-02',NULL),('AS0005',3,'SU03','2023-01-07','2023-02-01',NULL),('AS0006',3,'SU04','2023-01-10','2023-01-15',NULL);
/*!40000 ALTER TABLE `Orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Positions`
--

DROP TABLE IF EXISTS `Positions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Positions` (
  `position_id` varchar(4) NOT NULL,
  `position_title` varchar(30) NOT NULL,
  `position_min_salary` int NOT NULL,
  `position_max_salary` int NOT NULL,
  PRIMARY KEY (`position_id`),
  CONSTRAINT `Positions_chk_1` CHECK (regexp_like(`position_id`,_utf8mb4'^[A-Z]{2}[0-9]{2}$'))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Positions`
--

LOCK TABLES `Positions` WRITE;
/*!40000 ALTER TABLE `Positions` DISABLE KEYS */;
INSERT INTO `Positions` VALUES ('AD01','Administrator',1200,2500),('CL01','Cleaner',550,1000),('WA01','Waiter',700,1500);
/*!40000 ALTER TABLE `Positions` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Products`
--

DROP TABLE IF EXISTS `Products`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Products` (
  `product_id` int NOT NULL AUTO_INCREMENT,
  `product_name` varchar(50) NOT NULL,
  `product_specification` varchar(100) DEFAULT NULL,
  `product_price` decimal(10,2) NOT NULL,
  PRIMARY KEY (`product_id`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Products`
--

LOCK TABLES `Products` WRITE;
/*!40000 ALTER TABLE `Products` DISABLE KEYS */;
INSERT INTO `Products` VALUES (1,'White Bread',NULL,2.00),(2,'Coffee beans Arabica','higher quality beans',17.00),(3,'Coffee beans Robusta','double the amout of caffeine',15.00),(4,'Coffee beans Liberica','unique in their aroma',14.00),(5,'Coffee beans Excelsa','recently been classified',16.00),(6,'Strawberry Cake',NULL,13.00),(7,'Honey Cake',NULL,10.00);
/*!40000 ALTER TABLE `Products` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Shops`
--

DROP TABLE IF EXISTS `Shops`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Shops` (
  `shop_id` int NOT NULL AUTO_INCREMENT,
  `shop_city` varchar(50) NOT NULL,
  `shop_street` varchar(100) NOT NULL,
  `shop_phone_number` varchar(20) NOT NULL,
  PRIMARY KEY (`shop_id`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Shops`
--

LOCK TABLES `Shops` WRITE;
/*!40000 ALTER TABLE `Shops` DISABLE KEYS */;
INSERT INTO `Shops` VALUES (1,'Rezekne','Alejas str.,34','+37129345678'),(2,'Ventspils','Krasta str., 25','+37126345679'),(3,'Valmiera','Akas str., 4','+37129345674');
/*!40000 ALTER TABLE `Shops` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `Suppliers`
--

DROP TABLE IF EXISTS `Suppliers`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `Suppliers` (
  `supplier_id` varchar(4) NOT NULL,
  `supplier_name` varchar(50) NOT NULL,
  `supplier_city` varchar(20) DEFAULT NULL,
  `supplier_street` varchar(40) DEFAULT NULL,
  `supplier_phone_number` varchar(20) DEFAULT NULL,
  `supplier_email` varchar(50) DEFAULT NULL,
  PRIMARY KEY (`supplier_id`),
  CONSTRAINT `Suppliers_chk_1` CHECK (regexp_like(`supplier_id`,_utf8mb4'^[A-Z]{2}[0-9]{2}$'))
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `Suppliers`
--

LOCK TABLES `Suppliers` WRITE;
/*!40000 ALTER TABLE `Suppliers` DISABLE KEYS */;
INSERT INTO `Suppliers` VALUES ('SU01','Arabica Supllier',NULL,NULL,'+97123658767','as@as.com'),('SU02','World of Coffee',NULL,NULL,'+37265436789','wc@cw.co.lt'),('SU03','Eastern Coffee',NULL,NULL,'','ec@ec.com'),('SU04','Local Bakery',NULL,NULL,'+37134567856','lb@inbox.lv');
/*!40000 ALTER TABLE `Suppliers` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2024-12-02  6:27:10
