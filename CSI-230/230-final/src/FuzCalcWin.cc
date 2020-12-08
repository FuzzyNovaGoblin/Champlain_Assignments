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

   // mMathEntry.

   mMainVBox.add(mMathEntry);

   add(mMainVBox);

   mMainVBox.show();
   mMathEntry.show();
}

FuzCalc::FuzCalcWin::~FuzCalcWin() {
}
