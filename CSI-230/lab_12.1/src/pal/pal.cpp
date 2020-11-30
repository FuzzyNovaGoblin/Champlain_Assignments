/**
 * @file pal.cpp
 * @author Grant Hedley
 * @brief Palindrome Library Implementation
 * @credit https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
 * @date 2020-11-30
 */

#include <pal.h>
#include <string.h>

bool isPalindrome(char *word)
{
   bool ret = true;

   char *p = word;
   int len = strlen(word);
   char *q = &word[len - 1];

   for (int i = 0; i < len; ++i, ++p, --q)
   {
      if (*p != *q)
      {
         ret = false;
      }
   }

   return ret;
}