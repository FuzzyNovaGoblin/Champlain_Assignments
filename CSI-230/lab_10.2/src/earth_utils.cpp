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
      kmlFile << KML_OPEN;

      getline(inFile, buff);
      while (getline(inFile, buff))
      {
         buffStream.str(buff);
         getline(buffStream, country, ',');
         getline(buffStream, capital, ',');
         getline(buffStream, lat, ',');
         getline(buffStream, lon, ',');

         writePlacemark(kmlFile, capital + ", " + country, lat, lon);
         recordCount++;
      }
      kmlFile << KML_CLOSE;
   }
   return recordCount;
}

void writePlacemark(std::ofstream &kmlFile, std::string name, std::string latitude, std::string longitude)
{
   kmlFile << PLACEMARK_OPEN
           << NAME_OPEN << name << NAME_CLOSE
           << POINT_COORD_OPEN << longitude << "," << latitude << POINT_COORD_CLOSE
           << PLACEMARK_CLOSE;
}