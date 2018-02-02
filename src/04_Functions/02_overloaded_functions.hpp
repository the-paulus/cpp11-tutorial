#ifndef __02_OVERLOADED_FUNCTIONS_H__
#define __02_OVERLOADED_FUNCTIONS_H__

#include <string>
#include <initializer_list>
#include <typeinfo>

using std::initializer_list;
using std::string;

/*
 * All default arguments must be declared at the end of the parameter list,
 * by not doing so will cause the compiler to generate an error. 
 * 
 * Default values can be declared only once for each parameter but default 
 * values don't necessarily need to be declared all at once. When declaring
 * default values in this manner, parameters with default values must be 
 * declared in the order from right to left.
 * 
 * func(int i, int j, int k=0);
 * func(int i, int j=0, int k);
 * func(int i=0, int j, int k);
 * 
 * Unless there is a very good reason to declare the function's default 
 * parameters with multiple statements you should avoid it. As mentioned
 * above default parameters can only be declared once, meaning the
 * following is invalid:
 *
 * void setSize(int width, int height = 80);
 *
 * void setSize(int width, int height = 80)
 * {
 *  // ...
 * }
 */
void setSize(int width, int height = 80);
void setSize(int width = 60, int height);

/*
 * Demonstrates how overloading works with scope.
 */
void scope_function();

/*
 * Example of creating a function that takes an unspecified number of 
 * arguments using a variadic template.
 */
void print_numbers(const initializer_list<int> numbers);

/*
 * Another example of creating a function that takes at least one string
 * and an unspecified number of integers. All variadic parameters need to 
 * be specified last. 
 * 
 * To use initializer_lists the initializer_list header must be included.
 */
void print_message_with_numbers(const string message, 
                                const initializer_list<int> numbers);

/*
 * The '...' (elipsis operator) is another way of handling an unspecified
 * number of arguments.
 */
void elipsis_function(const int count, ...);


const char* print_parameter_type(int param);
const char* print_parameter_type(short param);
const char* print_parameter_type(string param);
const char* print_parameter_type(float param);
const char* print_parameter_type(double param, int dparam = 1);

#endif
