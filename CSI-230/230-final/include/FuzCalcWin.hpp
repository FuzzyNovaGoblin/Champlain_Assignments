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
#include <gtkmm/button.h>
#include <gtkmm/entry.h>
#include <gtkmm/label.h>
#include <gtkmm/window.h>
#include <libqalculate/Calculator.h>

#include <iostream>
#include <string>
#include <vector>

namespace FuzCalc {

class CalcWin : public Gtk::Window {
protected:
   Gtk::VBox                 mMainVBox;            // all widgets go in this
   Gtk::Entry                mMathEntry;           // text filed to take in equations
   Gtk::VBox                 mHistoryListVbox;     // list to place history in
   Pango::FontDescription    mFontDescription;     // main font discription to use
   std::vector<std::string>  mHistoryTextListVec;  // holds the stings that make up the history
   std::vector<Gtk::Widget*> mWidgetPtrs;          // holdt the pointers to dynamicly created widgets to be destroyed later
   
   /**
    * @brief build a history button that displays [text]
    * @param text text to be displayed
    * @return Gtk::Button& reference to teh created button
    */
   Gtk::Button& historyButtonBuilder(std::string text);

public:
   /**
    * @brief handle the signal of keypress for [mMathEntry]
    * @param event pass through the GdkEventKey
    * @return true if the key was enter and was handled,
    *         false if the key press was not handled
    */
   bool onMathEnter(GdkEventKey* event);

   /**
    * @brief hanle the pree of history button, call on history button pressed
    * @param btn GdkEventButton to be passed
    * @param copyVal string to be copied to clipboard with `xclip -i -selection clipboard`
    * @return true if the event was handled,
    *         false if the button press was not handled
    */
   bool onHistoryBtnPressed(GdkEventButton* btn, std::string copyVal);

   /**
    * @brief hanle the pree of history button, call on history button pressed
    * @param btn GdkEventButton to be passed
    * @param copyVal string to be copied to clipboard with `xclip -i -selection clipboard`
    * @return true if the key was enter and was handled,
    *         false if the key press was not handled
    */
   bool onHistoryBtnEnterPressed(GdkEventKey* event, std::string copyVal);


   /**
    * @brief Construct a new Fuz Calc Win object
    */
   CalcWin();

   /**
    * @brief Destroy the Fuz Calc Win object
    */
   ~CalcWin();
};

}  // namespace FuzCalc

#endif  // FUZCALCWIN_HPP
