// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: Lab5
// Date assigned: 9/26/19
// Due Date: 10/2/19
// Description: Compleete the class definition and implement the functions of the widget class
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
//
//  widget.h
//  widget
//
//
//  Modified by: Murat K. Gungor
//  Thanks to Brian R. Hall

#ifndef __widget__widget__
#define __widget__widget__

#include <string>
#include <sstream>

using namespace std;

enum WidgetType
{
	INVALID_TYPE = -1,
	WEATHER,
	QUOTE,
	STOCK,
	NUM_WIDGET_TYPES
};


const string WIDGET_NAMES[NUM_WIDGET_TYPES] = {	"Weather2000",
   "Of-The-Day",
   "Ups-and-Downs"
};

const int INITIAL_WIDGET_ID = 1;


class Widget
{
public:
	Widget( WidgetType type );
	Widget(const Widget& widget);//add copy constructor

	string getModelName() const { return wModelName; };

private:
	WidgetType wType;
	int wID;
	string wModelName;
   static int widgetCount;//add static data member

	void generateModelName();
};


#endif /* defined(__widget__widget__) */
