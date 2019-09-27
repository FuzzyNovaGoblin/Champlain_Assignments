// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: PA - Advanced Book
// Date assigned: 9/5/2019
// Due Date: 9/11/2019
// Description: hold values for books stored in books.txt
// Certification of Authenticity :
// I  certify  that  this  is  entirely  my  own  work, except  where  I  have  given fully
// documented  references  to  the  work  of  others. I  understand  the
// definition and consequences of plagiarism and acknowledge that the assessor
// of this assignment may, for the purpose of assessing this assignment:
// - Reproduce  this  assignment and provide  a  copy  to  another  member  of
// academic staff; and/or
// - Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking
// service(which  may  then  retain  a  copy  of  this  assignment  on  its
// database for the purpose of future plagiarism checking)

#include "book.h"
#include <sstream>
#include <fstream>

using namespace std;

const int OUNCES_TO_LBS_FACTOR = 16;

Book::Book()
{
	bName = "";
	bType = Type(-1);
	bPages = 0;
	bOunces = 0;
	for (int i = 0; i < 5; i++)
		bReviews[i] = 0;
}

Book::Book(const string& name, Type type, int pages, float ounces, const string& reviewFileName)
{
	bName = name;
	bType = type;
	bPages = pages;
	bOunces = ounces;
	for (int i = 0; i < 5; i++)
		bReviews[i] = 0;
	addReviews(reviewFileName);
}

string Book::formatReportLine()
{
	stringstream ss;

	ss << bName << "  | Type: " << getTypeName() << "  Pages: "
		<< bPages << "  Weight(lbs):" << getWeightLbs()
		<< "  Average stars: " << calculateAverageReview() << "  Most frequent review: " << getMostFrequentReview();

	return ss.str();
}

float Book::getWeightLbs()
{
	return bOunces / OUNCES_TO_LBS_FACTOR;
}

string Book::getTypeName()
{
   if(bType < 0)
   {
      return "UNKNOWN";
   }

   return TYPE_WORDS[bType];
}

void Book::addReviews(const string& reviewFile) {
	ifstream input(reviewFile);
	int reviews[5];
	int i;


	for (i = 0; i < 5 && !input.eof(); i++) {
		input >> reviews[i];
	}

	for (int i = 0; i < 5; i++) {
		bReviews[4 - i] = reviews[i];
	}
}

float Book::calculateAverageReview(){
	int count = 0;
	float sum = 0;

	for (int i = 0; i < 5; i++) {
		count += bReviews[i];
		sum += bReviews[i] * (i + 1);
	}

	return sum / count;
}

int Book::getMostFrequentReview() {
	int most = 0;

	for (int i = 1; i < 5; i++) {
		if (bReviews[i] > bReviews[most])
			most = i;
	}

	return most + 1;
}

void Book::getReviews(int reviewsArray[], int size) {
	for (int i = 0; i < 5; i++) {
		reviewsArray[i] = bReviews[i];
	}
}