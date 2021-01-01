-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jan 01, 2021 at 01:54 PM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.4.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `dbgoatfarm`
--

-- --------------------------------------------------------

--
-- Table structure for table `feed`
--

CREATE TABLE `feed` (
  `FeedID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `FeedType` varchar(50) COLLATE utf8mb4_bin DEFAULT NULL,
  `Calcium` decimal(4,2) DEFAULT NULL,
  `Phosphorus` decimal(4,2) DEFAULT NULL,
  `Potassium` decimal(4,2) DEFAULT NULL,
  `Copper` decimal(4,2) DEFAULT NULL,
  `Zinc` decimal(4,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `feed`
--

INSERT INTO `feed` (`FeedID`, `FeedType`, `Calcium`, `Phosphorus`, `Potassium`, `Copper`, `Zinc`) VALUES
('BF-1996-21', 'Alfalfa Hay', '16.80', '2.60', '24.60', '9.00', '30.00'),
('DG-1356-90', 'Maize Grain', '0.50', '3.00', '3.90', '2.00', '21.00'),
('FR-5632-17', 'Sweet Potato Vine', '9.50', '2.90', '24.90', '2.00', '70.00'),
('HY-3232-19', 'Sunflower Seed', '2.60', '6.00', '9.10', '0.00', '0.00');

-- --------------------------------------------------------

--
-- Table structure for table `feedingrecord`
--

CREATE TABLE `feedingrecord` (
  `GoatID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `FeedID` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL,
  `StaffID` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL,
  `FeedingTime` datetime DEFAULT NULL,
  `Quantity` decimal(4,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `feedingrecord`
--

INSERT INTO `feedingrecord` (`GoatID`, `FeedID`, `StaffID`, `FeedingTime`, `Quantity`) VALUES
('A1F213', 'HY-3232-19', 'S33-49804F', '2020-11-01 12:00:10', '3.40'),
('D1F870', 'FR-5632-17', 'S02-17534F', '2020-11-01 12:00:18', '3.10'),
('G4B019', 'DG-1356-90', 'S33-49804F', '2020-11-01 12:00:01', '3.60'),
('K1H434', 'BF-1996-21', 'S02-17534F', '2020-11-01 12:00:21', '3.25'),
('P6F997', 'FR-5632-17', 'S05-19623F', '2020-11-01 12:00:23', '3.44'),
('S2J186', 'BF-1996-21', 'S02-17534F', '2020-11-01 12:00:15', '3.22'),
('T0H129', 'HY-3232-19', 'S05-19623F', '2020-11-01 12:00:22', '3.56'),
('W2D143', 'DG-1356-90', 'S33-49804F', '2020-11-01 12:00:03', '3.33');

-- --------------------------------------------------------

--
-- Table structure for table `goatbirth`
--

CREATE TABLE `goatbirth` (
  `GoatID` varchar(6) COLLATE utf8mb4_bin NOT NULL,
  `GoatType` varchar(20) COLLATE utf8mb4_bin DEFAULT NULL,
  `GoatGender` varchar(7) COLLATE utf8mb4_bin DEFAULT NULL,
  `ParentGoatID` varchar(6) COLLATE utf8mb4_bin DEFAULT NULL,
  `HealthStatus` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL,
  `GoatDOB` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `goatbirth`
--

INSERT INTO `goatbirth` (`GoatID`, `GoatType`, `GoatGender`, `ParentGoatID`, `HealthStatus`, `GoatDOB`) VALUES
('A1F213', 'Angora', 'Billy', 'S9L144', 'Healthy', '2019-09-21'),
('D1F870', 'Pygmy', 'Billy', 'K1H434', 'Sick', '2019-08-13'),
('G4B019', 'Katjang', 'Nanny', 'D2F213', 'Die', '2019-04-23'),
('K1H434', 'Saanen', 'Nanny', 'H5H208', 'Healthy', '2020-08-28'),
('P6F997', 'Pgymy', 'Billy', 'J8H432', 'Sick', '2020-10-27'),
('S2J186', 'Boer', 'Nanny', '2M8288', 'Healthy', '2019-12-21'),
('T0H129', 'Pgymy', 'Billy', 'T4D567', 'Sick', '2020-09-12'),
('W2D143', 'Ibex', 'Billy', 'A6K256', 'Healthy', '2019-03-19');

-- --------------------------------------------------------

--
-- Table structure for table `goatshed`
--

CREATE TABLE `goatshed` (
  `GoatShedID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `Title` varchar(30) COLLATE utf8mb4_bin DEFAULT NULL,
  `Description` varchar(80) COLLATE utf8mb4_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `goatshed`
--

INSERT INTO `goatshed` (`GoatShedID`, `Title`, `Description`) VALUES
('GS01', 'Goat House A', 'Feed and resting place for adult goat'),
('GS02', 'Goat House B', 'Feed and resting place for adult goat'),
('GS03', 'Goat House C', 'Feed and resting place for adult goat'),
('GS04', 'Goat House D', 'Feed and resting place for adult'),
('GS05', 'Grazing Land', 'A field covered with grass or herbage'),
('GS06', 'Milking Parlor', 'Allow efficient milking'),
('GS07', 'Quarantine Pen', 'New goat arrival, Separation of infected one from healthy goats');

-- --------------------------------------------------------

--
-- Table structure for table `goatshedinout`
--

CREATE TABLE `goatshedinout` (
  `GoatShedID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `GoatID` varchar(6) COLLATE utf8mb4_bin DEFAULT NULL,
  `DateIn` datetime DEFAULT NULL,
  `DateOut` datetime DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `goatshedinout`
--

INSERT INTO `goatshedinout` (`GoatShedID`, `GoatID`, `DateIn`, `DateOut`) VALUES
('GS01', 'D1F870', '2019-08-13 09:07:22', '2019-08-13 10:02:32'),
('GS01', 'A1F213', '2020-08-13 09:10:25', '2019-08-13 10:10:05');

-- --------------------------------------------------------

--
-- Table structure for table `healthhistory`
--

CREATE TABLE `healthhistory` (
  `HealthHistoryID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `Sickness` varchar(30) COLLATE utf8mb4_bin DEFAULT NULL,
  `Treatment` varchar(150) COLLATE utf8mb4_bin DEFAULT NULL,
  `DateOfRecord` date DEFAULT NULL,
  `Symptom` varchar(150) COLLATE utf8mb4_bin DEFAULT NULL,
  `GoatID` varchar(6) COLLATE utf8mb4_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `healthhistory`
--

INSERT INTO `healthhistory` (`HealthHistoryID`, `Sickness`, `Treatment`, `DateOfRecord`, `Symptom`, `GoatID`) VALUES
('H0001', 'Anthrax', 'High doses of penicillin administered', '2019-09-24', 'Dark color bloody discharge from nose, sudden fever and death', 'G4B019'),
('H0002', 'Zinc Deficiency', 'Give zinc sulfate orally, avoid feeding grain', '2020-01-05', 'Excessive salivating, stiff joint', 'W2D143'),
('H0003', 'Goat Pox', 'No treatment', '2020-02-14', 'Lack of appetite, Inflammation of nose and eyelids', 'D1F870'),
('H0004', 'Parasite (roundworm)', 'Use antiparasitic drug', '2020-10-21', 'Weight loss, rough hair coat, and diarrhea', 'P6F997'),
('H0005', 'Lice', 'Shearing', '2020-11-30', 'Reduced growth, skin allergy and wound', 'P6F997'),
('H0006', 'Urinari Calculi', 'Providing a feed which contains a ammonium chloride', '2020-12-05', 'Tail-twitching, restlessness, anxiety', 'T0H129');

-- --------------------------------------------------------

--
-- Table structure for table `milkcollection`
--

CREATE TABLE `milkcollection` (
  `GoatID` varchar(6) COLLATE utf8mb4_bin NOT NULL,
  `StaffID` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL,
  `GoatShedID` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL,
  `DateCollect` date DEFAULT NULL,
  `Quantity` decimal(4,2) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `milkcollection`
--

INSERT INTO `milkcollection` (`GoatID`, `StaffID`, `GoatShedID`, `DateCollect`, `Quantity`) VALUES
('G4B019', 'S02-17534F', 'GS01', '2020-12-12', '2.79'),
('S2J186', 'S33-49804F', 'GS02', '2020-12-12', '2.75'),
('K1H434', 'S05-19623F', 'GS03', '2020-12-12', '2.96'),
('G4B019', 'S05-19623F', 'GS01', '2020-12-13', '3.91'),
('S2J186', 'S02-17534F', 'GS02', '2020-12-13', '2.84'),
('K1H434', 'S05-19623F', 'GS03', '2020-12-13', '3.76'),
('G4B019', 'S33-49804F', 'GS01', '2020-12-15', '2.93'),
('S2J186', 'S05-19623F', 'GS02', '2020-12-15', '3.12'),
('K1H434', 'S33-49804F', 'GS03', '2020-12-15', '2.88');

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `StaffID` varchar(10) COLLATE utf8mb4_bin NOT NULL,
  `Name` varchar(30) COLLATE utf8mb4_bin DEFAULT 'NOT NULL',
  `StaffType` varchar(15) COLLATE utf8mb4_bin DEFAULT NULL,
  `Password` varchar(15) COLLATE utf8mb4_bin DEFAULT NULL,
  `TelNo` varchar(15) COLLATE utf8mb4_bin DEFAULT NULL,
  `Gender` varchar(10) COLLATE utf8mb4_bin DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_bin;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`StaffID`, `Name`, `StaffType`, `Password`, `TelNo`, `Gender`) VALUES
('S02-17534F', 'Gustaf Daren', 'Farmer', '14125@!1', '011-3278450', 'Male'),
('S05-19623F', 'Thum Sze Khai', 'Farmer', 'EeeewW32', '012-5584694', 'Male'),
('S05-28021A', 'Lim Ker Xin', 'Administrator', 'KerXinAplus12', '017-4528791', 'Female'),
('S23-9786BV', 'Pang Jia Mei', 'Veterinarian', 'S1567250D', '012-5640451', 'Female'),
('S33-49804F', 'Joshua Bryan', 'Farmer', 'M96021402ac', '012-5631697', 'Male'),
('S48-79628S', 'Ooi Xue Ting', 'Supervisor', 'P@s$w0rd', '018-3254508', 'Female');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `feed`
--
ALTER TABLE `feed`
  ADD PRIMARY KEY (`FeedID`);

--
-- Indexes for table `feedingrecord`
--
ALTER TABLE `feedingrecord`
  ADD KEY `FeedingRecord_Feed_FK` (`FeedID`),
  ADD KEY `FeedingRecord_Staff_FK` (`StaffID`),
  ADD KEY `FeedingRecord_GoatBirth_FK` (`GoatID`);

--
-- Indexes for table `goatbirth`
--
ALTER TABLE `goatbirth`
  ADD PRIMARY KEY (`GoatID`);

--
-- Indexes for table `goatshed`
--
ALTER TABLE `goatshed`
  ADD PRIMARY KEY (`GoatShedID`);

--
-- Indexes for table `goatshedinout`
--
ALTER TABLE `goatshedinout`
  ADD KEY `GoatShedInOut_GoatBirth_FK` (`GoatID`),
  ADD KEY `GoatShedInOut_GoatShed_FK` (`GoatShedID`);

--
-- Indexes for table `healthhistory`
--
ALTER TABLE `healthhistory`
  ADD PRIMARY KEY (`HealthHistoryID`),
  ADD KEY `fk_goatID_healthistory` (`GoatID`);

--
-- Indexes for table `milkcollection`
--
ALTER TABLE `milkcollection`
  ADD KEY `MilkCollection_Staff_FK` (`StaffID`),
  ADD KEY `MilkCollection_GoatShed_FK` (`GoatShedID`),
  ADD KEY `MilkCollection_Goat_FK` (`GoatID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`StaffID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `feedingrecord`
--
ALTER TABLE `feedingrecord`
  ADD CONSTRAINT `FeedingRecord_Feed_FK` FOREIGN KEY (`FeedID`) REFERENCES `feed` (`FeedID`),
  ADD CONSTRAINT `FeedingRecord_GoatBirth_FK` FOREIGN KEY (`GoatID`) REFERENCES `goatbirth` (`GoatID`),
  ADD CONSTRAINT `FeedingRecord_Staff_FK` FOREIGN KEY (`StaffID`) REFERENCES `staff` (`StaffID`);

--
-- Constraints for table `goatshedinout`
--
ALTER TABLE `goatshedinout`
  ADD CONSTRAINT `GoatShedInOut_GoatBirth_FK` FOREIGN KEY (`GoatID`) REFERENCES `goatbirth` (`GoatID`),
  ADD CONSTRAINT `GoatShedInOut_GoatShed_FK` FOREIGN KEY (`GoatShedID`) REFERENCES `goatshed` (`GoatShedID`);

--
-- Constraints for table `healthhistory`
--
ALTER TABLE `healthhistory`
  ADD CONSTRAINT `fk_goatID_healthistory` FOREIGN KEY (`GoatID`) REFERENCES `goatbirth` (`GoatID`);

--
-- Constraints for table `milkcollection`
--
ALTER TABLE `milkcollection`
  ADD CONSTRAINT `MilkCollection_GoatShed_FK` FOREIGN KEY (`GoatShedID`) REFERENCES `goatshed` (`GoatShedID`),
  ADD CONSTRAINT `MilkCollection_Goat_FK` FOREIGN KEY (`GoatID`) REFERENCES `goatbirth` (`GoatID`),
  ADD CONSTRAINT `MilkCollection_Staff_FK` FOREIGN KEY (`StaffID`) REFERENCES `staff` (`StaffID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
