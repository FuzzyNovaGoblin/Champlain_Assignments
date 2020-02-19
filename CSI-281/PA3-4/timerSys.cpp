/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment: PA3
Date Assigned: 2/14/20
Due Date: 2/28/20
Description: quick sort and merge sort algorithems

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
andconsequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
  retain a copy of this assignment on its database for the purpose of future plagiarism
  checking)
*/
#include "timerSys.h"

using namespace std::chrono;

/*      Pre:  none
 *     Post:  none
 *  Purpose:  to initiate the timer object
 ************************************************************************/
Timer::Timer()
{
   mPaused = false;
   mStoped = true;
   mStartTime = microseconds(0);
   mEndTime = microseconds(0);
}

bool Timer::isPaused()
{
   return mPaused;
}

/*      Pre:  none
 *     Post:  returns true if the timer sucsesfuly started
 *  Purpose:  to start the timer
 ************************************************************************/
bool Timer::start()
{
   if (!mStoped)
      return false;
   mStoped = false;
   mPaused = false;
   mStartTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
   return true;
}

/*      Pre:  none
 *     Post:  returns true if the timer sucsesfuly paused
 *  Purpose:  to pause the timer
 ************************************************************************/
bool Timer::pause()
{
   if (mPaused || mStoped)
   {
      return false;
   }
   mPauseTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
   mPaused = true;
   return true;
}

/*      Pre:  none
 *     Post:  returns true if the timer sucsesfuly resumed
 *  Purpose:  to resume the timer if it is paused
 ************************************************************************/
bool Timer::resume()
{
   if (!mPaused)
      return false;

   mResumeTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
   microseconds diff = mResumeTime - mPauseTime;
   mStartTime += diff;
   mPaused = false;
   return true;
}

/*      Pre:  none
 *     Post:  returns true if the timer sucsesfuly stoped
 *  Purpose:  to stop the timer
 ************************************************************************/
bool Timer::stop()
{
   if (mStoped)
      return false;

   mEndTime = duration_cast<microseconds>(system_clock::now().time_since_epoch());
   mStoped = true;
   mPaused = false;
   return true;
}

/*      Pre:  none
 *     Post:  returns the number of microseconds the timer has recorder
 *            up ot this point
 *  Purpose:  to get the time from the timer
 ************************************************************************/
long Timer::getTime()
{
   if (mStoped)
   {
      return (mEndTime - mStartTime).count();
   }
   else if (mPaused)
   {
      return (mPauseTime - mStartTime).count();
   }
   else
   {
      microseconds now = duration_cast<microseconds>(system_clock::now().time_since_epoch());
      return (now - mStartTime).count();
   }
}