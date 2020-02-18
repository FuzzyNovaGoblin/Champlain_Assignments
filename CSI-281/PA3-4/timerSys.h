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

#ifndef TIMER_SYS_H
#define TIMER_SYS_H

#include <chrono>

using namespace std;

class Timer
{
private:
   chrono::milliseconds mStartTime, mEndTime, mPauseTime, mResumeTime;
   bool mPaused, mStoped;

public:
   Timer();
   bool start();
   bool pause();
   bool resume();
   bool stop();
   bool isPaused();
   long getTime();
};

#endif