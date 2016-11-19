#include "functions.hpp"

using std::begin;
using std::cin;
using std::cout;
using std::end;
using std::endl;
using std::string;

/*
 * Functions are named blocks of code that can be reused making programs more 
 * manageable. Programs have at least one function called main that can have 
 * arguments.
 * 
 * To differentiate functions from objects, the call operator is used '()'. 
 * Within the call operator parameters can be defined. The initialization of 
 * arguments correspond to the parameters passed when the function is called. 
 * The order in which the arguments are evaluated is up to the compiler.
 * 
 * When a function is called control is handed over to the function that was 
 * called. All objects defined within a function are called "local variables" 
 * or "automatic objects, meaning that they existing only while the program is 
 * executing that code block and visible only to the code within the function. 
 * This similar to compound statements with the exception that the parent is not 
 * aware of the objects within the curly braces.
 * 
 * There is a way around this an object can be declared as static, which causes 
 * its value to persist after the function is done executing. Typically when a 
 * function is done all local objects are freed. 
 */

#include "functions.hpp"

static int ctr;

/*
 * The static keyword tells the compiler that the object's value should 
 * persist after the function has finished executing.
 */
void count_times_called()
{
  
  ctr++;
  
}

int main(int argv, char **argc)
{
  
    simple_void_function1();
    
    simple_void_function2();
  
    /**** Argument function demonstration ****/
    string tmp_string = "String";
    
    cout << "Calling argument_function()" << endl;
    
    argument_function(tmp_string);
    /**** End of argument function demonstration ****/
    
    
    
    /**** Reference argument function demonstration ****/
    reference_argument_function(tmp_string);
    
    cout << "New value of tmp_string: " << tmp_string << endl;
    /**** End of reference argument function demonstration ****/
    
    
    /**** Const reference argument function demonstration ****/
    const_reference_argument_function(tmp_string);
    /**** End const reference argument function demonstration ****/
    
    cout << "Number of times count_times_called function has been called: "
      << ctr << endl;
    for(int i = 0; i < 10; i++) {
      
      count_times_called();
      
    }
    
    cout << ctr << endl << endl;
    
    /**** Multiple return function demonstration ****/
    int num_replacements = 0;
    string needle = "a";
    string replace = "#";
    
    multiple_return_values_function(needle, replace, tmp_string, 
      num_replacements);
    
    cout << "'" << needle << "' was found " <<  num_replacements 
      << " time(s) and replaced with '" << replace << "' new string: " 
      << tmp_string << endl << endl;
   /**** End multiple return function demonstration ****/
   
   
   
   /**** Recursive function demonstration ****/
   string haystack = "alabama";
   
   cout << "Recursive Function" << endl;
   cout << "Looking for \"" << needle << "\" to be replaced with \"" 
    << replace << "\" in \"" << haystack << endl;
   
   cout << "Recurive function result: " 
    << recursive_function(needle, replace, haystack, 0) << endl << endl;
   /**** End recursive function demonstration ****/ 
   
   
   
   /***** Pointer function demonstration *****/
    cout << "Value passed to pointer_argument_function(): " << haystack << endl;
    pointer_argument_function(&haystack);
    cout << "Value of object after call to pointer_argument_function(): " 
      << haystack << endl << endl;
    /***** End Pointer function demonstration *****/
    
    
    /***** Pointer function demonstration - C-Style *****/
    cout << "Pointer fucntion demonstration using C-Style method." << endl;
    
    const char carr[7] = { 'C', '+', '+', ' ', '1', '1', '\0' };
    
    array_argument_function_1(carr);
    cout << endl << endl;
    /***** End pointer function demonstration - C-Style *****/
    
    
    
    /***** Pointer function demonstration - STD Library conventions *****/
    cout << "Pointer function demonstration using standard library conventions:"
      << endl;
      
    int iarr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    
    array_argment_function_2(begin(iarr), end(iarr));
    
    cout << endl << endl;
    /***** End pointer function demonstration - STD Library conventions *****/
    
    
    
    /***** Pointer function demonstration - using size as an argument *****/
    cout << "Pointer function using array size as an argument." << endl;
    
    /* The correct size of the array needs to be passed or else the program 
     * will access access memory beyond the array. Retrieving the size of the 
     * array should be done within the function and not passed as an argument.
     */
    array_argument_function_3(iarr, (sizeof(iarr)/sizeof(*iarr)));
    
    /***** End pointer function demonstration - using size as an argument *****/
    
  /*
   * Even though we have indicated that main will return an integer but 
   * omitted the return statement, the compiler will implicitly add a 
   * 'return 0;'. 
   * 
   * Note: The stdlib library defines two macros defined as EXIT_SUCCESS and 
   * EXIT_FAILURE. When a program has completed successfully, it will return 0
   * where a failure is indicated by 1. The definition of EXIST_FAILURE and
   * EXIT_SUCCESS ensure that the intended result is achieved. 
   * 
   * Had we omitted a return statement for a function declared to have a return 
   * type, the compiler would not have compiled the program.
   */
  
}

