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
#include "widget.h"
using namespace std;

int Widget::widgetCount = INITIAL_WIDGET_ID;

Widget::Widget( WidgetType type )
{
   wType = type;
	wID = widgetCount++;
   generateModelName();
}

Widget::Widget(const Widget& widget)
{
   wType = widget.wType;
   wID = widgetCount++;
   generateModelName();
}

void Widget::generateModelName()
{
   stringstream modelNameStream;
   modelNameStream << WIDGET_NAMES[wType] << " " << wID << " " << this;
   wModelName = modelNameStream.str();
}