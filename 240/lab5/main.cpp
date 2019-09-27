//
//  main.cpp
//  widget
//
//
//  Modified by: Murat K. Gungor 
//  Thanks to Brian R. Hall

#include <iostream>
#include <string>
#include "widget.h"

using namespace std;


int main()
{
	//makes three widgets using the regular constructor
	const Widget weather( WEATHER );
	const Widget quote( QUOTE );
	const Widget stock( STOCK );
   
	cout << "weather widget 1: " << weather.getModelName() << endl;
	cout << "quote widget 1: " << quote.getModelName() << endl;
	cout << "stock widget 1: " << stock.getModelName() << endl;
   
	//makes three widgets using the copy constructor
    Widget weather2 = weather;
	Widget quote2 = quote;
	Widget stock2 = stock;
   
	cout << "weather widget 2: " << weather2.getModelName() << endl;
	cout << "quote widget 2: " << quote2.getModelName() << endl;
	cout << "stock widget 2: " << stock2.getModelName() << endl;
   
	cin.get();
   
   return 0;
   
}

