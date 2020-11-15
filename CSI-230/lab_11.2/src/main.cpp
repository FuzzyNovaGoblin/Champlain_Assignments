#include <boost/program_options.hpp>
#include <iostream>
#include <boost/python.hpp>
#include <fstream>
#include <sstream>

using namespace std;
using namespace boost::python;
using namespace boost::program_options;

int main(int argc, const char **argv)
{
   Py_Initialize();

   float arg1, arg2;
   char op;
   string path;
   try
   {
      options_description desc{};
      desc.add_options()("help,h", "show this help page")("1,1", value<float>(), "float, first operand")("2,2", value<float>(), "float, second operand")("op", value<char>()->default_value('+'), "operator to use ['+', '-', 'x','*', '/']")("path,p", value<string>()->default_value("./bin/"), "path to directory containing the math_stuff.py file");

      variables_map vm;
      store(parse_command_line(argc, argv, desc), vm);

      if (vm.count("help"))
      {
         cout << desc << endl;
         return 0;
      }
      else
      {
         path = vm["path"].as<string>();

         if (!(vm.count("1") || vm.count("2")))
         {
            cout << "nothing to do\n";
            return 0;
         }
         arg1 = vm["1"].as<float>();
         arg2 = vm["2"].as<float>();
         op = vm["op"].as<char>();
      }
   }
   catch (error &e)
   {
      cerr << e.what() << '\n';
      return 1;
   }

   boost::python::object main = import("__main__");
   boost::python::object global(main.attr("__dict__"));

   stringstream fileName;
   fileName << path;
   if (path[path.length() - 1] != '/')
      fileName << '/';
   fileName << "math_stuff.py";
   cout << fileName.str() << endl;
   exec_file(fileName.str().c_str(), global, global);

   stringstream expr;
   expr << "print(";
   switch (op)
   {
   case '+':
      expr << "add(" << arg1 << ", " << arg2 << ")";
      break;
   case '-':
      expr << "sub(" << arg1 << ", " << arg2 << ")";
      break;
   case '*':
   case 'x':
      expr << "mult(" << arg1 << ", " << arg2 << ")";
      break;
   case '/':
      expr << "div(" << arg1 << ", " << arg2 << ")";
      break;
   default:
      cerr << "invalid operator char\n";
      return 3;
   }

   expr << ")";
   cout << expr.str().c_str() << "\n";

   exec(expr.str().c_str(), global, global);
}