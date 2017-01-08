#include <iostream>
#include <initializer_list>

#include "02_overloaded_functions.hpp"

using std::cout;
using std::to_string;
using std::endl;

int main(int argv, char *argc[])
{
  
  /*
   * However, If the below function was declared within the same scope then it 
   * would be overloaded. When compiling, the compiler does a name lookup piror 
   * to type checking.  
   */
  cout << "Overloaded function with default parameteres: " << endl; 
  
  setSize();
  
  cout << "setSize() is called from within the scope_function call but has "
    << "also been declared as taking a string rather than two integers. " 
    << endl << endl;
    /*
     * Calling the scope function which has setSize redefined as setSize(string)
     */
    scope_function();
    
    /*
     * When a parameter is declared as an initializer_list you must enclose 
     * your arguments within curly braces.
     */
    print_numbers( { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 } );
   
    /*
     * We are defining an initializer_list variable named numbers for
     * cleanliness. We could also define like this:
     *
     * auto numbers = { 1, 3, 5, 7, 9 }; 
     */
    initializer_list<int> numbers = { 1, 3, 5, 7, 9 };
    
    print_message_with_numbers("You've entered " + to_string(numbers.size()) 
        + " odd numbers you entered", numbers);
    
    elipsis_function(10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    
}


