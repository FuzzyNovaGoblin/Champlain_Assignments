/*
Author:       Grant Hedley
Class: 	      CSI-281 - 01
Assignment:    PP2
Due Date:
Description:
A brief description of the purpose of the program.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given fully
-
documented references to the work of others. I und
erstand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
-
Reproduce  this  assignment  and  provide  a  copy  to  another  member  of
academic staff; and/or
-
Communicate a copy of this assignment to a plagiarism checking service
(which may then retain a copy of this assignment on its database for
the purpose of future plagiarism checking
*/


#include "stubs.h"
    /*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test swapvalues
*/
    void
    testSwapValues()
{
   int v1 = 8, v2 = 10;
   swapValues(v1, v2);
   cout << "output: " << v1 << " | " << v2 << endl;
   cout << "corect: " << 10 << " | " << 8 << endl;

   double v3 = 9.4, v4 = 8.4;
   swapValues(v3, v4);
   cout << "output: " << setw(4) << v3 << " | " << setw(4) << v4 << endl;
   cout << "corect: " << setw(4) << 8.4 << " | " << setw(4) << 9.4 << endl;

   string v5 = "World", v6 = "Hello";
   swapValues(v5, v6);
   cout << "output: " << v5 << " | " << v6 << endl;
   cout << "corect: "
        << "Hello"
        << " | "
        << "World" << endl;
}

/*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test printArr
*/
void testPrintArr()
{
   int arr1[] = {1, 24, 54, 8, 36, 7, 4, 74, 74, 26, 633};

   printArr(arr1, 11);
}
/*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test first overload of swapvalues
*/
void testSwapValues2()
{
   string arr1[] = {"a", "b", "c"};
   string arr2[] = {"d", "e", "f"};
   string arr1Ans[] = {"d", "e", "f"};
   string arr2Ans[] = {"a", "b", "c"};

   swapValues(arr1, arr2, 3);
   cout << "output: \n";
   printArr(arr1, 3);
   printArr(arr2, 3);

   cout << "correct: \n";
   printArr(arr1Ans, 3);
   printArr(arr2Ans, 3);
}

/*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test second overload of swap values
*/
void testSwapValues3()
{
   string arr1[] = {"a", "b", "c"};
   string arr2[] = {"d", "e", "f", "stay in arr2"};
   string arr1Ans[] = {"d", "e", "f"};
   string arr2Ans[] = {"a", "b", "c", "stay in arr2"};

   swapValues(arr1, arr2, 3, 4);
   cout << "output: \n";
   printArr(arr1, 3);
   printArr(arr2, 4);

   cout << "correct: \n";
   printArr(arr1Ans, 3);
   printArr(arr2Ans, 4);
}

/*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test sum function
*/
void testSum()
{
   int v1 = 34, v2 = 2;
   cout << " output: " << sum(v1, v2) << endl;
   cout << "correct: " << v1 + v2 << "\n\n";

   string v3 = "Hello", v4 = " World";
   cout << " output: " << sum(v3, v4) << endl;
   cout << "correct: Hello World\n\n";

   char v5 = '#', v6 = '$';
   cout << " output: " << sum(v5, v6) << endl;
   cout << "correct: " << 'G' << "\n\n";
}

/*    pre: none
     post: prints the output of the function and the correct output
  purpose: to test overload of sum function
*/
void testSum2()
{

   int v1 = 34, v2 = 2, v3 = 9;
   cout << " output: " << sum(v1, v2, v3) << endl;
   cout << "correct: " << v1 + v2 + v3 << "\n\n";

   string v4 = "Hello", v5 = " World", v6 = "!";
   cout << " output: " << sum(v4, v5, v6) << endl;
   cout << "correct: Hello World!\n\n";

   char v7 = '#', v8 = '$', v9 = ' ';
   cout << " output: " << sum(v7, v8, v9) << endl;
   cout << "correct: " << 'g' << "\n\n";
}