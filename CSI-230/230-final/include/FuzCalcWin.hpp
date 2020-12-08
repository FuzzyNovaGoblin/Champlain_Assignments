/**
 * @file FuzCalcWin.hpp
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief dinfine the main instenc of the window for the FuzyCalc package
 * @version 0.1
 * @date 2020-12-07
 */

#if !defined(FUZCALCWIN_HPP)
#define FUZCALCWIN_HPP

#include <gtkmm/application.h>
#include <gtkmm/box.h>
#include <gtkmm/entry.h>
#include <gtkmm/window.h>

#include <iostream>
#include <string>

namespace FuzCalc {

class FuzCalcWin : public Gtk::Window {
protected:
   Gtk::VBox mMainVBox;   // all widgets go in this
   Gtk::VBox mMathEntry;  // text filed to take in equations

public:
   /**
    * @brief Construct a new Fuz Calc Win object
    * @param mApplication_id the id for the aplications main window, defaults to "com.fuzytech.fuzcalc"
    */
   FuzCalcWin();

   /**
    * @brief Destroy the Fuz Calc Win object
    */
   ~FuzCalcWin();
};

}  // namespace FuzCalc

#endif  // FUZCALCWIN_HPP
