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

const std::string KML_OPEN = "<?xml version=\"1.o\" encoding=\"UTF-8\"?>\n"
                              "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n"
                              "<Document>\n";

const std::string KML_CLOSE = "</Document>\n</kml>";

const std::string PLACEMARK_OPEN = "<Placemark>\n";
const std::string PLACEMARK_CLOSE = "</Placemark>\n";


const std::string NAME_OPEN = "<name>\n";
const std::string NAME_CLOSE = "</name>\n";

const std::string POINT_COORD_OPEN = "<Point><coordinates>";
const std::string POINT_COORD_CLOSE = "</coordinates></Point>\n";

#endif