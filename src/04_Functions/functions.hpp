#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
#include <string>

using std::string;

/*
 * Functions are declared in a header file and defined a file with the same 
 * name with a different extension. In this case, functions are defined in a
 * file called functions.cpp.
 */

/*
 * When declaring functions, known as function declarations or function 
 * prototypes, it's not necessary to specify the arguments but it is helpful to 
 * do so. When defining a function, instead of adding the body of the function
 * you use a semicolon.
 * 
 * The definition of the following functions are stored in the functions.cpp 
 * file. It is legal to declare and define functions where ever the function
 * is used. However, declaring functions in a header and defining them in a 
 * separate file makes maintaining the code easier.
 *
 */

void simple_void_function1();

void simple_void_function2(void);

void argument_function(string output);

void reference_argument_function(string &output);

void const_reference_argument_function(const string &large_object);

void multiple_return_values_function(const string &needle, 
                                     const string &replace,
                                     string &haystack,    
                                     int &num_replacements);

string recursive_function(const string &needle, const string &replace, 
                          string &haystack, string::size_type pos);

void pointer_argument_function(string *ptr_arg);

void count_times_called();

void array_argument_function_1 (const char[]);

void array_argment_function_2(const int *begin, const int *end);

void array_argument_function_3(const int ptr_arg[], size_t size);

/*
 * Declaring functions and not defining them is legal. Functions must be defined
 * if they are called.
 */
void declared_not_defined_function(void);

#endif
