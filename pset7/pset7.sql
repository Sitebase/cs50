-- phpMyAdmin SQL Dump
-- version 4.0.10deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Nov 30, 2015 at 11:35 PM
-- Server version: 5.5.46-0ubuntu0.14.04.2-log
-- PHP Version: 5.5.9-1ubuntu4.14

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `pset7`
--

-- --------------------------------------------------------

--
-- Table structure for table `history`
--

CREATE TABLE IF NOT EXISTS `history` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `transaction` varchar(10) COLLATE utf8_unicode_ci NOT NULL,
  `datetime` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `symbol` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(11) NOT NULL,
  `price` decimal(65,4) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=4 ;

--
-- Dumping data for table `history`
--

INSERT INTO `history` (`id`, `user_id`, `transaction`, `datetime`, `symbol`, `shares`, `price`) VALUES
(1, 6, 'BUY', '2015-11-30 22:08:46', 'FREE', 4, 0.1200),
(2, 6, 'SELL', '2015-11-30 22:09:46', 'PRO', 200, 4824.0000),
(3, 6, 'BUY', '2015-11-30 22:18:30', 'FREE', 500, 15.0000);

-- --------------------------------------------------------

--
-- Table structure for table `portfolio`
--

CREATE TABLE IF NOT EXISTS `portfolio` (
  `id` int(11) NOT NULL,
  `symbol` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `shares` int(11) NOT NULL,
  PRIMARY KEY (`id`,`symbol`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci;

--
-- Dumping data for table `portfolio`
--

INSERT INTO `portfolio` (`id`, `symbol`, `shares`) VALUES
(6, 'FREE', 1504);

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `id` int(10) unsigned NOT NULL AUTO_INCREMENT,
  `username` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `hash` varchar(255) COLLATE utf8_unicode_ci NOT NULL,
  `cash` decimal(65,4) NOT NULL DEFAULT '0.0000',
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 COLLATE=utf8_unicode_ci AUTO_INCREMENT=16 ;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`id`, `username`, `hash`, `cash`) VALUES
(1, 'belindazeng', '$1$50$oxJEDBo9KDStnrhtnSzir0', 10000.0000),
(2, 'caesar', '$1$50$GHABNWBNE/o4VL7QjmQ6x0', 10000.0000),
(3, 'jharvard', '$1$50$RX3wnAMNrGIbgzbRYrxM1/', 10000.0000),
(4, 'malan', '$1$50$lJS9HiGK6sphej8c4bnbX.', 10000.0000),
(5, 'rob', '$1$HA$l5llES7AEaz8ndmSo5Ig41', 10000.0000),
(6, 'skroob', '$1$t1JWTFMw$VApBn.r1UCPM3gmqKD6qZ0', 9954.8800),
(7, 'zamyla', '$1$50$uwfqB45ANW.9.6qaQ.DcF.', 10000.0000),
(8, 'jefke', '$1$1l/RRxew$pzwHlkiPq4beXBwawtLeH0', 10000.0000),
(11, 'frans', '$1$5XXVRdeW$8uF6orohB9YEY85RA.a3V1', 10000.0000),
(12, 'willy', '$1$XOtkFB4J$WmYvGJb0QYh1AESHsO78M1', 10000.0000),
(13, 'wim', '$1$O9GBOyHU$XvjCbtuhM7pT.r8KHSvnD/', 10000.0000),
(15, 'pimp', '$1$RKdMQcdc$vWFJ82BfkoDxIHYliPpjK/', 10000.0000);

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
