/**
 * @file FuzCalcApp.cc
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief wrapper class for GTK::Application
 * @version 0.1
 * @date 2020-12-07
 */

#include <FuzCalcApp.hpp>

using namespace FuzCalc;

FuzCalcApp::FuzCalcApp(std::string id) {
   mApp    = Gtk::Application::create(id);
   mWindow = new CalcWin();
}
FuzCalcApp::~FuzCalcApp() {
   delete mWindow;
}
int FuzCalcApp::start() {
   return mApp->run(*mWindow);
}