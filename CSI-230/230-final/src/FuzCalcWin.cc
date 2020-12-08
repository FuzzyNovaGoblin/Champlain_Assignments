/**
 * @file FuzCalcWin.cc
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief handles the window of the fuzycalc package
 * @version 0.1
 * @date 2020-12-07
 */

#include "FuzCalcWin.hpp"

FuzCalc::CalcWin::CalcWin() {
   new Calculator();
   CALCULATOR->loadExchangeRates();
   CALCULATOR->loadGlobalDefinitions();
   CALCULATOR->loadLocalDefinitions();

   set_border_width(10);
   mFontDescription = Pango::FontDescription("mono 20");
   add(mMainVBox);

   mMathEntry.override_font(mFontDescription);
   mMathEntry.set_alignment(0);
   mMathEntry.set_size_request(1200, -1);
   mMathEntry.signal_key_press_event().connect(sigc::mem_fun(*this, &FuzCalc::CalcWin::onMathEnter), false);
   mMainVBox.add(mMathEntry);

   mMainVBox.add(mHistoryListVbox);

   show_all_children();
}

FuzCalc::CalcWin::~CalcWin() {
   for(size_t i = 0; i < mWidgetPtrs.size(); i++) {
      delete mWidgetPtrs[i];
   }
}

Gtk::Button& FuzCalc::CalcWin::historyButtonBuilder(std::string text) {
   Gtk::Button* tmpButton = new Gtk::Button;
   Gtk::Label*  tmpLabel  = new Gtk::Label;
   mWidgetPtrs.push_back(tmpButton);
   mWidgetPtrs.push_back(tmpLabel);

   EvaluationOptions eo;
   MathStructure     result;
   CALCULATOR->calculate(&result, text, 2000, eo);

   std::string resultStr = result.print();

   tmpButton->signal_button_press_event().connect(sigc::bind(sigc::mem_fun(*this, &FuzCalc::CalcWin::onHistoryBtnPressed), resultStr), false);
   tmpButton->signal_key_release_event().connect(sigc::bind(sigc::mem_fun(*this, &FuzCalc::CalcWin::onHistoryBtnEnterPressed), resultStr), false);

   mHistoryListVbox.pack_end(*tmpButton);

   tmpLabel->set_text(text + " = " + resultStr);
   tmpButton->add(*tmpLabel);

   mHistoryListVbox.show_all_children();

   return *tmpButton;
}

bool FuzCalc::CalcWin::onHistoryBtnPressed(GdkEventButton* btn, std::string copyVal) {
   std::cout << "(" << copyVal << ")"
             << "btn pressed\n";

   system(("echo -ne \"" + copyVal + "\" | xclip -i -selection clipboard").c_str());
   return false;
}

bool FuzCalc::CalcWin::onHistoryBtnEnterPressed(GdkEventKey* event, std::string copyVal) {
   if(event->keyval != 65293)
      return false;

   std::cout << "(" << copyVal << ")"
             << "btn pressed\n";

   system(("echo -ne \"" + copyVal + "\" | xclip -i -selection clipboard").c_str());
   return false;
}

bool FuzCalc::CalcWin::onMathEnter(GdkEventKey* event) {
   if(event->keyval != 65293)
      return false;
   if(mMathEntry.get_text() == "")
      return false;

   mHistoryTextListVec.push_back(mMathEntry.get_text());
   std::cout << "hello there mr math\nsize: " << mHistoryTextListVec.size() << "\nlast one: " << mHistoryTextListVec.back() << std::endl;

   historyButtonBuilder(mMathEntry.get_text());

   return true;
}
