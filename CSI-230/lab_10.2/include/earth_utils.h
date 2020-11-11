/**
 * @file earth_utils.h
 * @author Grant Hedley
 * @brief lab 10.2
 * @version 1.0
 * @date 2020-11-11
 */

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H

#include <string>
#include <fstream>

/**
 * @brief process a country capital CSV file
 * @param inFile ifstream to an opened and validated csv file
 * @param kmlFileName teh name of the kml file yoi qish to produce
 * @return int returns the number of records processed
 */
int processCSV(std::ifstream &inFile, std::string kmlFileName);


/**
 * @brief writes a placemark Record into an existing kmlfile
 * @param kmlFile ref to kmlfile to write to
 * @param name string "capital, country"
 * @param latitude string "latitude "
 * @param longitude string "longitude"
 */
void writePlacemark(std::ofstream &kmlFile, std::string name, std::string latitude, std::string longitude);
#endif