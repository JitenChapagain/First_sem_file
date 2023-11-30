-- phpMyAdmin SQL Dump
-- version 5.1.3
-- https://www.phpmyadmin.net/
--
-- Host: 127.0.0.1
-- Generation Time: Jul 27, 2022 at 11:03 AM
-- Server version: 10.4.24-MariaDB
-- PHP Version: 7.4.29

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `library`
--

-- --------------------------------------------------------

--
-- Table structure for table `author`
--

CREATE TABLE `author` (
  `Author_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Phone_num` int(11) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `author`
--

INSERT INTO `author` (`Author_ID`, `Name`, `Address`, `Phone_num`, `Email`) VALUES
('ATH007', 'Markus Zusak', 'Japan', 283267, 'Zusak07@'),
('ATH010', 'Thomas Connolly', 'America', 423728, 'Thomas10@'),
('ATH018', 'C.J.Date', 'Canada', 19287654, 'C.J.Date18@'),
('ATH033', 'Bhoj Raj', 'Nepal', 2147483647, 'Raj33@'),
('ATH045', 'Ramez Elmasari', 'England', 2673215, 'Ramez45@');

-- --------------------------------------------------------

--
-- Table structure for table `bill`
--

CREATE TABLE `bill` (
  `Bill_no` int(11) NOT NULL,
  `Amount` int(11) DEFAULT NULL,
  `Purpose` varchar(50) DEFAULT NULL,
  `Pay_date` date DEFAULT NULL,
  `Member_ID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `bill`
--

INSERT INTO `bill` (`Bill_no`, `Amount`, `Purpose`, `Pay_date`, `Member_ID`) VALUES
(6, 50, 'Fine', '2022-04-01', 1),
(7, 20, 'Fine', '2022-04-01', 9);

-- --------------------------------------------------------

--
-- Table structure for table `book`
--

CREATE TABLE `book` (
  `Book_ID` varchar(50) NOT NULL,
  `Title` varchar(50) DEFAULT NULL,
  `ISBN` int(11) DEFAULT NULL,
  `Published_date` int(11) DEFAULT NULL,
  `Price` int(11) DEFAULT NULL,
  `Author_ID` varchar(50) DEFAULT NULL,
  `Category_ID` varchar(50) DEFAULT NULL,
  `Publisher_ID` varchar(50) DEFAULT NULL,
  `Subject_area` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `book`
--

INSERT INTO `book` (`Book_ID`, `Title`, `ISBN`, `Published_date`, `Price`, `Author_ID`, `Category_ID`, `Publisher_ID`, `Subject_area`) VALUES
('Bk10', 'Database', 6, 2022, 150, 'ATH010', 'CT01', 'Pb09', 'Algorithm'),
('Bk11', 'Database', 66, 2022, 250, 'ATH018', 'CT04', 'pb102', 'Normalization'),
('Bk12', 'Software', 76, 2019, 300, 'ATH045', 'CT02', 'Pb06', 'Computing'),
('Bk13', 'Software', 69, 2019, 1000, 'ATH010', 'CT03', 'pb102', 'Computing'),
('Bk14', 'Hardware', 178, 2018, 975, 'ATH018', 'CT03', 'Pb06', 'Computing'),
('Bk15', 'Hardware', 932, 2018, 825, 'ATH07', 'CT02', 'Pb99', 'Computing'),
('Bk16', 'Electricity', 800, 2010, 665, 'ATH045', 'CT04', 'Pb22', 'Voltage'),
('Bk17', 'Electricity', 645, 2010, 553, 'ATH07', 'CT01', 'Pb99', 'Ohm'),
('Bk18', 'Poem', 1010, 2001, 442, 'ATH033', 'CT02', 'Pb09', 'Love'),
('Bk19', 'Poem', 167, 2001, 400, 'ATH045', 'CT03', 'Pb06', 'Adventure');

-- --------------------------------------------------------

--
-- Table structure for table `book_loan`
--

CREATE TABLE `book_loan` (
  `Book_Id` varchar(50) DEFAULT NULL,
  `Publisher_ID` varchar(50) DEFAULT NULL,
  `Member_ID` int(11) DEFAULT NULL,
  `Lend_date` date DEFAULT NULL,
  `Due_date` date DEFAULT NULL,
  `Return_date` date DEFAULT NULL,
  `Fine` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `book_loan`
--

INSERT INTO `book_loan` (`Book_Id`, `Publisher_ID`, `Member_ID`, `Lend_date`, `Due_date`, `Return_date`, `Fine`) VALUES
('Bk10', 'Pb09', 1, '2022-01-10', '2022-01-20', '2022-02-01', 100),
('Bk12', 'Pb06', 3, '2022-01-15', '2022-01-20', '2022-01-19', 0),
('Bk14', 'Pb06', 6, '2022-01-25', '2022-01-30', '2022-01-29', 0),
('Bk16', 'Pb22', 8, '2022-01-30', '2022-02-20', '2022-02-19', 0);

-- --------------------------------------------------------

--
-- Table structure for table `category`
--

CREATE TABLE `category` (
  `Category_ID` varchar(50) NOT NULL,
  `Type` varchar(50) DEFAULT NULL,
  `Name` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `category`
--

INSERT INTO `category` (`Category_ID`, `Type`, `Name`) VALUES
('CT01', 'Open-stack', 'First'),
('CT02', 'Yellow-tagged', 'Second'),
('CT03', 'Red-tagged', 'Third'),
('CT04', 'Green-tagged', 'Fourth');

-- --------------------------------------------------------

--
-- Table structure for table `department`
--

CREATE TABLE `department` (
  `Department_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Head` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `department`
--

INSERT INTO `department` (`Department_ID`, `Name`, `Head`) VALUES
('DP01', 'Aerospace', 'Maxwell'),
('DP010', 'medical', 'Virat'),
('DP04', 'Education', 'Bhumra'),
('DP06', 'Engineering', 'Rohit'),
('DP45', 'Science', 'Bhuvi');

-- --------------------------------------------------------

--
-- Table structure for table `member`
--

CREATE TABLE `member` (
  `Member_ID` int(11) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Phone_num` int(11) DEFAULT NULL,
  `No_of_book_borrw` int(11) DEFAULT NULL,
  `Staff_ID` int(11) DEFAULT NULL,
  `Student_ID` varchar(50) DEFAULT NULL,
  `Member_Status` varchar(50) DEFAULT NULL,
  `Department_ID` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `member`
--

INSERT INTO `member` (`Member_ID`, `Name`, `Address`, `Phone_num`, `No_of_book_borrw`, `Staff_ID`, `Student_ID`, `Member_Status`, `Department_ID`) VALUES
(1, 'Ishan', 'Pokhara', 2147483647, 2, 10, 'NULL', NULL, NULL),
(2, 'Hardik', 'Kushma', 2147483647, 3, 16, 'NULL', NULL, NULL),
(3, 'Kurnal', 'Lakeside', 2147483647, 4, 19, 'NULL', NULL, NULL),
(4, 'Malinga', 'Chitwan', 2147483647, 7, 32, 'NULL', NULL, NULL),
(5, 'Anil', 'Baglung', 2147483647, 9, 66, 'NULL', NULL, NULL),
(6, 'Kapil', 'Parbat', 985463642, 3, NULL, 'STD01', 'Active', 'DP06'),
(7, 'Akshya', 'Kaski', 98231696, 1, NULL, 'STD10', 'Active', 'DP45'),
(8, 'Deepika', 'Kathmandu', 2147483647, 2, NULL, 'STD33', 'Active', 'DP010'),
(9, 'Ranbir', 'Mustang', 983216459, 5, NULL, 'STD36', 'Active', 'DP010'),
(10, 'Sagar', 'Lalitpur', 2147483647, 0, NULL, 'STD69', 'Inactive', 'DP45');

-- --------------------------------------------------------

--
-- Table structure for table `publisher`
--

CREATE TABLE `publisher` (
  `Publisher_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Phone_num` int(11) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `publisher`
--

INSERT INTO `publisher` (`Publisher_ID`, `Name`, `Address`, `Phone_num`, `Email`) VALUES
('Pb06', 'Prentice Hall', 'America', 5453489, 'Prentice06@'),
('Pb09', 'Ricky Pointing', 'Australia', 45692321, 'Ricky09@'),
('pb102', 'Son', 'Japan', 57543281, 'Son1026@'),
('pb22', 'Ben Stock', 'England', 213628, 'Ben22@'),
('pb99', 'Tilak Poudel', 'Nepal', 98023462, 'Tilak99@');

-- --------------------------------------------------------

--
-- Table structure for table `report`
--

CREATE TABLE `report` (
  `Report_no` int(11) NOT NULL,
  `Issue_date` date DEFAULT NULL,
  `Return_date` date DEFAULT NULL,
  `Due_date` date DEFAULT NULL,
  `Reservation_no` int(11) DEFAULT NULL,
  `Member_ID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `report`
--

INSERT INTO `report` (`Report_no`, `Issue_date`, `Return_date`, `Due_date`, `Reservation_no`, `Member_ID`) VALUES
(4, '2022-01-02', '2022-03-01', '2022-04-01', 8, 1),
(6, '2022-02-06', '0000-00-00', '2022-04-01', 10, 9);

-- --------------------------------------------------------

--
-- Table structure for table `reservation`
--

CREATE TABLE `reservation` (
  `Reservation_no` int(11) NOT NULL,
  `Date` date DEFAULT NULL,
  `Book_status` varchar(50) DEFAULT NULL,
  `Book_ID` varchar(50) DEFAULT NULL,
  `Member_ID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `reservation`
--

INSERT INTO `reservation` (`Reservation_no`, `Date`, `Book_status`, `Book_ID`, `Member_ID`) VALUES
(6, '2022-01-10', 'Available', 'BK15', 6),
(8, '2021-12-03', 'Loanedout', 'BK10', 1),
(9, '2022-02-14', 'Available', 'BK13', 9),
(10, '2022-03-16', 'Loanout', 'Bk11', 4);

-- --------------------------------------------------------

--
-- Table structure for table `staff`
--

CREATE TABLE `staff` (
  `Staff_ID` int(11) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Phone_num` int(11) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL,
  `Department_ID` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `staff`
--

INSERT INTO `staff` (`Staff_ID`, `Name`, `Address`, `Phone_num`, `Email`, `Department_ID`) VALUES
(10, 'Ishan', 'Pokhara', 2147483647, 'Ishan10@', 'DP01'),
(16, 'Hardik', 'Kushma', 2147483647, 'Hardik16@', 'DP04'),
(19, 'Kurnal', 'Lakeside', 2147483647, 'Kurnal19@', 'DP06'),
(32, 'Malinga', 'Chitwan', 2147483647, 'Malinga32@', 'DP010'),
(66, 'Anil', 'Baglung', 2147483647, 'Anil66@', 'DP45');

-- --------------------------------------------------------

--
-- Table structure for table `student`
--

CREATE TABLE `student` (
  `Student_ID` varchar(50) NOT NULL,
  `Name` varchar(50) DEFAULT NULL,
  `Address` varchar(50) DEFAULT NULL,
  `Phone_num` int(11) DEFAULT NULL,
  `Email` varchar(50) DEFAULT NULL,
  `Department_ID` varchar(50) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

--
-- Dumping data for table `student`
--

INSERT INTO `student` (`Student_ID`, `Name`, `Address`, `Phone_num`, `Email`, `Department_ID`) VALUES
('STD01', 'Kapil', 'Parbat', 985463642, 'Kapil01@', 'DP06'),
('STD10', 'Akshya', 'Kaski', 98231696, 'Akshya10@', 'DP45'),
('STD33', 'Deepika', 'Kathmandu', 2147483647, 'Deepika33@', 'DP010'),
('STD36', 'Ranbir', 'Mustang', 983216459, 'Ranbir36@', 'DP010'),
('STD69', 'Sagar', 'Laltipur', 2147483647, 'Sagar69@', 'DP45');

--
-- Indexes for dumped tables
--

--
-- Indexes for table `author`
--
ALTER TABLE `author`
  ADD PRIMARY KEY (`Author_ID`);

--
-- Indexes for table `bill`
--
ALTER TABLE `bill`
  ADD PRIMARY KEY (`Bill_no`),
  ADD KEY `Member_ID` (`Member_ID`);

--
-- Indexes for table `book`
--
ALTER TABLE `book`
  ADD PRIMARY KEY (`Book_ID`),
  ADD KEY `Author_ID` (`Author_ID`),
  ADD KEY `Category_ID` (`Category_ID`),
  ADD KEY `Publisher_ID` (`Publisher_ID`);

--
-- Indexes for table `book_loan`
--
ALTER TABLE `book_loan`
  ADD KEY `Publisher_ID` (`Publisher_ID`),
  ADD KEY `Member_ID` (`Member_ID`),
  ADD KEY `Book_Id` (`Book_Id`);

--
-- Indexes for table `category`
--
ALTER TABLE `category`
  ADD PRIMARY KEY (`Category_ID`);

--
-- Indexes for table `department`
--
ALTER TABLE `department`
  ADD PRIMARY KEY (`Department_ID`);

--
-- Indexes for table `member`
--
ALTER TABLE `member`
  ADD PRIMARY KEY (`Member_ID`),
  ADD KEY `Staff_ID` (`Staff_ID`),
  ADD KEY `Student_ID` (`Student_ID`),
  ADD KEY `Department_ID` (`Department_ID`);

--
-- Indexes for table `publisher`
--
ALTER TABLE `publisher`
  ADD PRIMARY KEY (`Publisher_ID`);

--
-- Indexes for table `report`
--
ALTER TABLE `report`
  ADD PRIMARY KEY (`Report_no`),
  ADD KEY `Reservation_no` (`Reservation_no`),
  ADD KEY `Member_ID` (`Member_ID`);

--
-- Indexes for table `reservation`
--
ALTER TABLE `reservation`
  ADD PRIMARY KEY (`Reservation_no`),
  ADD KEY `Book_ID` (`Book_ID`),
  ADD KEY `Member_ID` (`Member_ID`);

--
-- Indexes for table `staff`
--
ALTER TABLE `staff`
  ADD PRIMARY KEY (`Staff_ID`),
  ADD KEY `Department_ID` (`Department_ID`);

--
-- Indexes for table `student`
--
ALTER TABLE `student`
  ADD PRIMARY KEY (`Student_ID`),
  ADD KEY `Department_ID` (`Department_ID`);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `bill`
--
ALTER TABLE `bill`
  ADD CONSTRAINT `bill_ibfk_1` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`);

--
-- Constraints for table `book`
--
ALTER TABLE `book`
  ADD CONSTRAINT `book_ibfk_1` FOREIGN KEY (`Author_ID`) REFERENCES `author` (`Author_ID`),
  ADD CONSTRAINT `book_ibfk_2` FOREIGN KEY (`Category_ID`) REFERENCES `category` (`Category_ID`),
  ADD CONSTRAINT `book_ibfk_3` FOREIGN KEY (`Publisher_ID`) REFERENCES `publisher` (`Publisher_ID`);

--
-- Constraints for table `book_loan`
--
ALTER TABLE `book_loan`
  ADD CONSTRAINT `book_loan_ibfk_1` FOREIGN KEY (`Publisher_ID`) REFERENCES `publisher` (`Publisher_ID`),
  ADD CONSTRAINT `book_loan_ibfk_2` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`),
  ADD CONSTRAINT `book_loan_ibfk_3` FOREIGN KEY (`Book_Id`) REFERENCES `book` (`Book_ID`);

--
-- Constraints for table `member`
--
ALTER TABLE `member`
  ADD CONSTRAINT `member_ibfk_1` FOREIGN KEY (`Staff_ID`) REFERENCES `staff` (`Staff_ID`),
  ADD CONSTRAINT `member_ibfk_2` FOREIGN KEY (`Student_ID`) REFERENCES `student` (`Student_ID`),
  ADD CONSTRAINT `member_ibfk_3` FOREIGN KEY (`Department_ID`) REFERENCES `department` (`Department_ID`);

--
-- Constraints for table `report`
--
ALTER TABLE `report`
  ADD CONSTRAINT `report_ibfk_1` FOREIGN KEY (`Reservation_no`) REFERENCES `reservation` (`Reservation_no`),
  ADD CONSTRAINT `report_ibfk_2` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`);

--
-- Constraints for table `reservation`
--
ALTER TABLE `reservation`
  ADD CONSTRAINT `reservation_ibfk_1` FOREIGN KEY (`Book_ID`) REFERENCES `book` (`Book_ID`),
  ADD CONSTRAINT `reservation_ibfk_2` FOREIGN KEY (`Member_ID`) REFERENCES `member` (`Member_ID`);

--
-- Constraints for table `staff`
--
ALTER TABLE `staff`
  ADD CONSTRAINT `staff_ibfk_1` FOREIGN KEY (`Department_ID`) REFERENCES `department` (`Department_ID`);

--
-- Constraints for table `student`
--
ALTER TABLE `student`
  ADD CONSTRAINT `student_ibfk_1` FOREIGN KEY (`Department_ID`) REFERENCES `department` (`Department_ID`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
