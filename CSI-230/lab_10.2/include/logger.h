/**
 * @file logger.h
 * @author Grant Hedley
 * @brief Week 10, lab 10.2
 * @version 1.0
 * @date 2020-11-11
 */


#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>


/**
 * @brief creates a discreete syslog message
 * @param msg message to be written
 * @param programName name of binary
 * @param logFile file stream of file to be written to
 * @return returns a bool indicatiing if the message was written
 */
bool log(std::string msg, std::string programName, std::ofstream &logFile);

/**
 * @brief max size of a hostname
 */
const int MAX_HOSTNAME_LEN = 30;

#endif