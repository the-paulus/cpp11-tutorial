#include <iostream>
#include <string>

#include "04_refret_functions.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
  string string_one = "Short string.";
  string string_two = "Longer string";
  string shorter_string = shorterString(string_one, string_two);
  
  cout << "\"" << shorter_string << "\" is the shorter string." << endl;
  
}
