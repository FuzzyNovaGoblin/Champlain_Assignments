/**
 * @file main.cpp
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief driver file for FuzCalc
 * @version 0.1
 * @date 2020-12-08
 */
#include <gtk/gtk.h>

#include "FuzCalcApp.hpp"
#include <iostream>

using namespace std;


int main(int argc, char** argv) {

   FuzCalc::FuzCalcApp app;

   app.start();
}