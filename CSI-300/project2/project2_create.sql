-- MySQL Workbench Forward Engineering

SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0;
SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0;
SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION';

-- -----------------------------------------------------
-- Schema twater
-- -----------------------------------------------------

-- -----------------------------------------------------
-- Schema twater
-- -----------------------------------------------------
CREATE SCHEMA IF NOT EXISTS `twater` ;
USE `twater` ;

-- -----------------------------------------------------
-- Table `twater`.`postType`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`postType` (
  `type_id` INT NOT NULL,
  `type_name` VARCHAR(45) NOT NULL,
  PRIMARY KEY (`type_id`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`user`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`user` (
  `UID` INT NOT NULL AUTO_INCREMENT,
  `UNAME` VARCHAR(45) NOT NULL,
  `UFN` VARCHAR(45) NULL,
  `ULN` VARCHAR(45) NULL,
  `join_date` DATE NOT NULL,
  `pass_hash` VARCHAR(45) NOT NULL,
  `email` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`UID`))
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`post`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`post` (
  `PID` INT NOT NULL AUTO_INCREMENT,
  `UID` INT NOT NULL,
  `post_type_id` INT NOT NULL,
  `time` DATETIME NULL,
  PRIMARY KEY (`PID`),
  INDEX `UID_idx` (`UID` ASC) VISIBLE,
  INDEX `type_ID_idx` (`post_type_id` ASC) VISIBLE,
  CONSTRAINT `fk_post_uuid`
    FOREIGN KEY (`UID`)
    REFERENCES `twater`.`user` (`UID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `type_ID`
    FOREIGN KEY (`post_type_id`)
    REFERENCES `twater`.`postType` (`type_id`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`retweet`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`retweet` (
  `PID` INT NOT NULL,
  `original_post_id` INT NOT NULL,
  PRIMARY KEY (`PID`),
  INDEX `OG_PID_idx` (`original_post_id` ASC) VISIBLE,
  CONSTRAINT `fk_retweet_PID`
    FOREIGN KEY (`PID`)
    REFERENCES `twater`.`post` (`PID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_OG_PID`
    FOREIGN KEY (`original_post_id`)
    REFERENCES `twater`.`post` (`PID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`tweet`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`tweet` (
  `PID` INT NOT NULL,
  `text` VARCHAR(255) NOT NULL,
  PRIMARY KEY (`PID`),
  CONSTRAINT `fk_tweet_PID`
    FOREIGN KEY (`PID`)
    REFERENCES `twater`.`post` (`PID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`follow`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`follow` (
  `follower_id` INT NOT NULL,
  `followed_id` INT NOT NULL,
  INDEX `UID_idx` (`follower_id` ASC) VISIBLE,
  INDEX `followed_id_idx` (`followed_id` ASC) VISIBLE,
  CONSTRAINT `fk_follower_id`
    FOREIGN KEY (`follower_id`)
    REFERENCES `twater`.`user` (`UID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_followed_id`
    FOREIGN KEY (`followed_id`)
    REFERENCES `twater`.`user` (`UID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


-- -----------------------------------------------------
-- Table `twater`.`likes`
-- -----------------------------------------------------
CREATE TABLE IF NOT EXISTS `twater`.`likes` (
  `UID` INT NOT NULL,
  `PID` INT NOT NULL,
  INDEX `UID_idx` (`UID` ASC) VISIBLE,
  INDEX `PID_idx` (`PID` ASC) VISIBLE,
  CONSTRAINT `fk_like_UID`
    FOREIGN KEY (`UID`)
    REFERENCES `twater`.`user` (`UID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE,
  CONSTRAINT `fk_like_PID`
    FOREIGN KEY (`PID`)
    REFERENCES `twater`.`post` (`PID`)
    ON DELETE CASCADE
    ON UPDATE CASCADE)
ENGINE = InnoDB;


SET SQL_MODE=@OLD_SQL_MODE;
SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS;
SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS;

                                                                                                                                                                                                                                                                                                                                                                            
INSERT INTO twater.postType value (0, "tweet");                                                                                                                                                                                                                                                                                                                              
INSERT INTO twater.postType value (1, "retweet"); 
