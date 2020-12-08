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
#include <gtkmm/label.h>
#include <gtkmm/window.h>

#include <iostream>
#include <string>
#include <vector>

namespace FuzCalc {

class FuzCalcWin : public Gtk::Window {
protected:
   Gtk::VBox                mMainVBox;         // all widgets go in this
   Gtk::Entry               mMathEntry;        // text filed to take in equations
   Gtk::VBox                mHistoryListVbox;  // list to place history in
   Pango::FontDescription   mFontDescription;  // main font discription to use
   std::vector<std::string> mHistoryListVec;   // holds the stings that make up the history

   Gtk::Label tst1;
   Gtk::Label tst2;
   Gtk::Label tst3;

   

public:
   /**
    * @brief Construct a new Fuz Calc Win object
    */
   FuzCalcWin();

   /**
    * @brief Destroy the Fuz Calc Win object
    */
   ~FuzCalcWin();
};

}  // namespace FuzCalc

#endif  // FUZCALCWIN_HPP
