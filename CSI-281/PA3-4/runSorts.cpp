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

#include "runSorts.h"

using namespace std;

/*      Pre:  timer, string name of output file, and bool array which sorts to run
 *     Post:  calls all of the other functions in the file with every posible
 *            set of paramaters
 *  Purpose:  To determine the efficency of the algorithems
 ************************************************************************/
void runAllSorts(Timer &timer, string fileName, bool runSorts[7])
{
  ofstream outFile(fileName, ios_base::app);
  string dataSet;
  for (int i = 0; i < 7; i++)
  {

    switch (i)
    {
    case 0:
      if (!runSorts[0])
        break;
      cout << "\n\nBubbleSort:\n";
      outFile << "\n\nBubbleSort:\n";
      break;
    case 1:
      if (!runSorts[1])
        break;
      cout << "\n\nCycleSort:\n";
      outFile << "\n\nCycleSort:\n";
      break;
    case 2:
      if (!runSorts[2])
        break;
      cout << "\n\nInsertionSort:\n";
      outFile << "\n\nInsertionSort:\n";
      break;
    case 3:
      if (!runSorts[3])
        break;
      cout << "\n\nShellSort:\n";
      outFile << "\n\nShellSort:\n";
      break;
    case 4:
      if (!runSorts[4])
        break;
      cout << "\n\nSelectionSort:\n";
      outFile << "\n\nSelectionSort:\n";
      break;
    case 5:
      if (!runSorts[5])
        break;
      cout << "\n\nMergeSort:\n";
      outFile << "\n\nMergeSort:\n";
      break;
    case 6:
      if (!runSorts[6])
        break;
      cout << "\n\nQuickSort:\n";
      outFile << "\n\nQuickSort:\n";
      break;
    default:
      break;
    }
    for (int j = 0; j < 3; j++)
    {
      dataSet = DATA_SETS[j];
      for (int k = 0; k < 3; k++)
      {
        switch (i)
        {
        case 0:
          if (!runSorts[0])
            break;
          outFile << runBubbleSort(N_LIST[k], dataSet, timer);
          break;
        case 1:
          if (!runSorts[1])
            break;
          outFile << runCycleSort(N_LIST[k], dataSet, timer);
          break;
        case 2:
          if (!runSorts[2])
            break;
          outFile << runInsertionSort(N_LIST[k], dataSet, timer);
          break;
        case 3:
          if (!runSorts[3])
            break;
          outFile << runShellSort(N_LIST[k], dataSet, timer);
          break;
        case 4:
          if (!runSorts[4])
            break;
          outFile << runSelectionSort(N_LIST[k], dataSet, timer);
          break;
        case 5:
          if (!runSorts[5])
            break;
          outFile << runMergeSort(N_LIST[k], dataSet, timer);
          break;
        case 6:
          if (!runSorts[6])
            break;
          outFile << runQuickSort(N_LIST[k], dataSet, timer);
          break;
        default:
          break;
        }
      }
    }
  }
  outFile.close();
}

/*    -------All Functions That Follow-------
 *      Pre:  int size of array, inputFile name, timer
 *     Post:  The function prints the sorting function that was called, how
 *            long the array was, which data set was used, and how
 *            many milliseconds it took to complete
 *  Purpose:  To determine the efficency of the algorithem
 ************************************************************************/

string runBubbleSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  betterBubbleSort(array, N);
  timer.stop();

  stringstream ss;
  cout << setw(15) << right << "BubbleSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "BubbleSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runCycleSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  cycleSort(array, N);
  timer.stop();

  stringstream ss;
  cout << setw(15) << right << "CycleSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "CycleSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runInsertionSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  insertionSort(array, N);
  timer.stop();

  stringstream ss;
  cout << setw(15) << right << "InsertionSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "InsertionSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runShellSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  shellSort(array, N);
  timer.stop();

  stringstream ss;
  cout << setw(15) << right << "ShellSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "ShellSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runSelectionSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  selectionSort(array, N);
  timer.stop();

  stringstream ss;
  cout << setw(15) << right << "SelectionSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "SelectionSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runMergeSort(int N, string inputFileName, Timer &timer)
{

  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  mergeSort(array, 0, N - 1);
  timer.stop();
  stringstream ss;
  cout << setw(15) << right << "MergeSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "MergeSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}

string runQuickSort(int N, string inputFileName, Timer &timer)
{
  int *array = new int[N];
  readFileToArray(array, N, inputFileName);

  timer.start();
  quickSort(array, 0, N - 1);
  timer.stop();

  stringstream ss;

  cout << setw(15) << right << "QuickSort | "
       << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  ss << setw(15) << right << "QuickSort | "
     << "N: " << left << setw(10) << N << " | Dataset:" << setw(15) << inputFileName << "Time: " << timer.getTimeReadable() << " (" << timer.getTime() << ") " << endl;
  delete[] array;
  return ss.str();
}