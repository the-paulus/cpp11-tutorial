#include <cstdarg>
#include <iostream>

#include "02_overloaded_functions.hpp"

using std::cout;
using std::to_string;
using std::endl;

/*
 * setSize is an overloaded function. One taking two integer parameters
 * and the other taking a single string.
 */
void setSize(int width, int height)
{
  
    cout << "setSize(int,int): Dimensions are set to " << width << " x " 
        << height << endl;
}

void setSize(string size)
{
    cout << "setSize(string): Dimensions are set to " << size << endl;
}

/*
 * Functions can only be overridden if they are in the same scope.
 * Attempting to override a function by declaring a new variant within a 
 * different scope will re-declare the function as a whole new one.
 */
void scope_function()
{
  /*
   * The following declaration of setSize(string) is legal, but it is not 
   * recommended. Calling setSize(int,int) will fail because the compiler 
   * uses the most recent definition of the function that is within scope.
   *
   * setSize(60, 80); <- Error 
   */
  void setSize(string size);
  
  setSize("60 x 80");
  
}


void print_numbers(const initializer_list<int> numbers)
{
    cout << "Here are the numbers you entered: " << endl;
    
    for(auto number : numbers)
    {
        cout << number << endl;
    }
   
}

void print_message_with_numbers(const string message, 
                                const initializer_list<int> numbers)
{
    string numbers_out;
    
    for(auto number : numbers)
    {
        numbers_out += string(" " + to_string(number));
    }
    
    cout << "Message: " << message << endl;
    cout << "Numbers: " << numbers_out << endl;
}

/*
 * The ellipsis operator is also found in C and thus allows C++ programs to be
 * compatible with C code. In order for this to work, the cstdarg header 
 * must be included.
 * 
 * Like the variadic parameter, the ellipsis must be the last argument in the
 * function declaration.
 * 
 * It's important to note that most C++ types are not copied properly when
 * passed.
 * 
 * Functions that utilize the ellipsis must have at least one argument that is
 * a non-ellipsis argument. 
 * 
 * Although the use of ellipsis offer the programmer a lot of flexibility the
 * use of ellipses is dangerous. There is no type checking for the ellipses,
 * which can create adverse effects as well as security vulnerabilities.
 */
void elipsis_function(const int count, ...)
{
    
    /*
     * In order to access the arguments within the elipsis, a va_list object
     * is created. 
     */
    va_list l;
    
    /* 
     * The va_start is a macro that allows access to the variable list of
     * arguments. The second argument of the va_start macro helps indicate
     * where the elipsis starts.
     */
    va_start(l, count);
    
    cout << "(elipses) You've entered:";
    
    for(int i = 0; i < count; i++)
    {

        cout << " " << va_arg(l, int);
        
    }
    
    /* 
     * Cleans up the va_list object. If this is not called before 
     * another va_start or va_copy call, the behavior is undefinned.
     */
    va_end(l);
}


const char* print_parameter_type(int param)
{
    return typeid(param).name();
}

const char* print_parameter_type(string param)
{
    return typeid(param).name();
}

const char* print_parameter_type(float param)
{
    return typeid(param).name();
}

const char* print_parameter_type(double param, int dparam)
{
    return string(string(typeid(param).name()) + " " + string(typeid(dparam).name())).data();
}