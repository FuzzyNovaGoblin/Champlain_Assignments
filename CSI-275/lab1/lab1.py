"""
Author: Grant Hedley
Class: CSI-275-1
Assignment: Lab1
Due Date: January 20 11:59PM

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition
and consequences of plagiarism and acknowledge that the assessor of this
assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic
- staff; and/or Communicate a copy of this assignment to a plagiarism checking
- service (which may then retain a copy of this assignment on its database for
- the purpose of future plagiarism checking)
"""

def build_list():
   """Asks user for numbers and returns a list

   The user is prompted to enter a number repetedly until an empty
   string is returned. Every line that can be cast to an int or float
   is added to a list.
   """
   done = False
   nums = []

   while not done:
      buff = input("Enter a number or just press Enter to stop\n")
      if buff == "":
         done = True
      else:
         try:
            nums.append(int(buff))
         except:
            try:
               nums.append(float(buff))
            except:
               print("That is not a number")

   return nums

def sort_list(arr):
   """sorts a list

   calls the built in list sort method on the argument
   """

   arr.sort()
   return arr

def main():
   arr = sort_list(build_list())
   print(arr)

if __name__ == "__main__":
   main()