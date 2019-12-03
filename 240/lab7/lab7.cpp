// Author: Grant Hedley
// Class: CSI-240 - Advanced Programming
// Assignment: lab7
// Date assigned: 10/31/19
// Due Date: 11/6/19
// Description: inheritance
// Certification of Authenticity :
// I  certify  that  this  is  entirely  my  own  work, except  where  I  have  given fully
// documented  references  to  the  work  of  others. I  understand  the
// definition and consequences of plagiarism and acknowledge that the assessor
// of this assignment may, for the purpose of assessing this assignment:
// - Reproduce  this  assignment and provide  a  copy  to  another  member  of
// academic staff; and/or
// - Communicate  a  copy  of  this  assignment  to  a  plagiarism  checking
// service(which  may  then  retain  a  copy  of  this  assignment  on  its
// database for the purpose of future plagiarism checking)


#include <iostream>
#include <string>

using namespace std;

enum Discipline
{
   COMPUTER_SCIENCE,
   COMPUTER_SCIENCE_INNOVATION
};

const string DISCIPLINE_STRINGS[2] = {
    "Computer Science", "Computer Science And Innovation"};

class Person
{
public:
   Person()
   {
      name = "NO NAME";
      cout << "Person object created using the default Person constructor \n";
   }

   Person(string name)
   {
      this->name = name;
      cout << "Person object created using the alternate Person constructor \n";
   }

   ~Person()
   {
      cout << "Person object destroyed!\n";
   }

   string getName()
   {
      return name;
   }
   void setName(string name)
   {
      this->name = name;
   }

protected:
   string name;
};

class Faculty : public Person
{
public:
   Faculty() : Person()
   {
      department = COMPUTER_SCIENCE;
      cout << "Faculty object created using the default Faculty constructor \n";
   }
   Faculty(string name, Discipline department)
   {
      this->name = name;
      this->department = department;
      cout << "Faculty object created using the alternate Faculty constructor \n";
   }
   ~Faculty()
   {
      cout << "Faculty object destroyed!\n";
   }

   string getDepartment()
   {
      return DISCIPLINE_STRINGS[department];
   }

   void setDepartment(Discipline department)
   {
      this->department = department;
   }

private:
   Discipline department;
};

class Student : public Person
{
public:
   Student()
   {
      major = COMPUTER_SCIENCE;
      cout << "Student object created using the default Student constructor \n";
   }
   Student(string name, Discipline major)
   {
      this->name = name;
      this->major = major;
      cout << "Student object created using the alternate Student constructor \n";
   }
   ~Student()
   {
      cout << "Student object destroyed!\n";
   }

   string getMajor()
   {
      return DISCIPLINE_STRINGS[major];
   }

   void setMajor(Discipline major)
   {
      this->major = major;
   }

private:
   Discipline major;
};

int main()
{

   Faculty prof("Murat Gungor", COMPUTER_SCIENCE);
   Student stu("Grant Hedley", COMPUTER_SCIENCE_INNOVATION);

   cout << endl
        << "I, " << stu.getName() << ", am majoring in " << stu.getMajor() << "." << endl;
   cout << "I am taking CSI 240 with Prof. " << prof.getName() << ", who teaches "
        << prof.getDepartment() << " courses." << endl
        << endl;

   return 0;
}
