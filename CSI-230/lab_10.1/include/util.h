/**
 * @file util.h
 * @brief Week 10, C++ Review and warmup from CSI-230
 * @author Grant Hedley
 * @assignment lab 10.1
 * @date 11/06/20
 *
*/

#include <vector>
#include <iostream>

using namespace std;

//returns the sum of doubles in vector
double sum(vector<double> &arr);

//returns the average of doubles in vector
double avg(vector<double> &arr);

//returns the lowest double in vector
double lowest(vector<double> &arr);

//takes a multi word string
void camelCase(string &str);

// returns reference to random elelment of sting vector
string& randomElement(vector<string> &arr);

// prints elements of vector then new line
void printVector(vector<string> &arr);
void printVector(vector<double> &arr);