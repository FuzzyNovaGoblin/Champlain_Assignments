/**
 * @file FuzCalcWin.cc
 * @author Grant Hedley (FuzzyNovaGoblin@fuzytech.com)
 * @brief handles the window of the fuzycalc package
 * @version 0.1
 * @date 2020-12-07
 */

#include <FuzCalcWin.hpp>

using namespace FuzCalc;

FuzCalc::FuzCalcWin::FuzCalcWin() {
   set_border_width(10);
   mFontDescription = Pango::FontDescription("mono 20");
   add(mMainVBox);

   mMathEntry.override_font(mFontDescription);
   mMathEntry.set_alignment(0);
   mMathEntry.set_size_request(1200, -1);
   // mMathEntry.set_font_options()
   // mMathEntry.
   mMainVBox.add(mMathEntry);

   mMainVBox.add(mHistoryListVbox);

   tst1.set_text("hello there");
   tst1.override_font(mFontDescription);
   tst2.set_text("hello there");
   tst2.override_font(mFontDescription);
   tst3.set_text("hello there");
   tst3.override_font(mFontDescription);
   mHistoryListVbox.add(tst1);
   mHistoryListVbox.add(tst2);
   mHistoryListVbox.add(tst3);

   show_all_children();
}

FuzCalc::FuzCalcWin::~FuzCalcWin() {
}
