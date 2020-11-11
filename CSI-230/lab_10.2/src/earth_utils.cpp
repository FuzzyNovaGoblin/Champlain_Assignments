/**
 * @file earth_utils.cpp
 * @author Grant Hedley
 * @brief lab 10.2
 * @version 1.0
 * @date 2020-11-11
 */

#include <earth_utils.h>
#include <sstream>

using namespace std;

int processCSV(std::ifstream &inFile, std::string kmlFileName)
{
   string country, capital, lat, lon, buff;
   stringstream buffStream;
   int recordCount = 0;

   if (inFile)
   {
      ofstream kmlFile(kmlFileName);
      kmlFile << "<?xml version=\"1.o\" encoding=\"UTF-8\"?>\n"
              << "<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n"
              << "<Document>\n";

      getline(inFile, buff);
      while (getline(inFile, buff))
      {
         buffStream.str(buff);
         getline(buffStream, country, ',');
         getline(buffStream, capital, ',');
         getline(buffStream, lon, ',');
         getline(buffStream, lat, ',');

         writePlacemark(kmlFile, capital + ", " + country, lat, lon);
         recordCount++;
      }
      kmlFile << "</Document>\n</kml>";
   }
   return recordCount;
}

void writePlacemark(std::ofstream &kmlFile, std::string name, std::string latitude, std::string longitude)
{
   kmlFile << "<Placemark>\n"
           << "<name>" << name << "</name>\n"
           << "<Point><coordinates>" << latitude << "," << longitude << "</coordinates></Point>\n"
           << "</Placemark>\n";
}