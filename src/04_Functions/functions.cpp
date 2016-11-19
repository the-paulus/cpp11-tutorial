
#include "functions.hpp"

using std::cout;
using std::endl;
using std::string;

/*
 * Defining the function called simple_void_function1. When called, it simply 
 * prints "sample_void_function1() was called."
 */
void simple_void_function1()
{
  
  cout << "sample_void_function1() was called." << endl << endl;

}

/*
 * This is another way to define a function that doesn't return anything nor 
 * does it accept any arguments.
 */
void simple_void_function2(void)
{
  cout << "simple_void_function2() was called." << endl << endl;
}

/*
 * This function demonstrates taking an argument of type "string" and printing
 * it. There is no returned value so the function is defined as "void".
 * 
 * Arguments hold copies of of the parameter that was passed when the function 
 * was called. In this case we are passing by value and the function was called
 * by value.
 */
void argument_function(string output)
{
  
  cout << "Argument passed: " << output << endl << endl;
  
}

/*
 * Any changes to a reference arguments changes the value of the object that
 * was passed when the function was called. Reference arguments should be used
 * when you want to return more than one value and for large objects.
 * 
 * The argument of this function is a reference and therefore cannot use a
 * literal such as reference_argument_function("string") because literals do
 * not have addresses. In order to for that to work the function would need to
 * be reference_argument_function(const string output).
 */
void reference_argument_function(string &output)
{
  
  cout << "Argument passed by reference: " << output << endl << endl;
  
  output = "Changed";
  
}

/*
 * When working with large objects, you want to pass them to the function by 
 * reference. To ensure that the object passed is not modified you declare the
 * argument as a constant. Declaring an argument as a constant not only protects
 * the argument but it also indicates that the intention is to not modify the 
 * value.
 * 
 * When an argument is declared as a constant, the top-level const is ignored. 
 * Even though an argument is defined as a constant, you can pass either a const
 * or non-const object.
 * 
 * Since the top-level const is ignored there is no need to declare and define
 * another function with a non-const parameter. Doing so is redefining the 
 * non-const definition because the compiler is doing that task for you.
 */
void const_reference_argument_function(const string &large_object)
{
  
  cout << "const_refernce_argument_function() called with: " << large_object 
    << endl << endl;;
    
}

/*
 * Functions can only return a single value. To get around this, one way is to
 * use references. In this instance, we want to modify the haystack by replacing
 * all needles we find. We also want to know how many times the replacement 
 * happened.
 */
void multiple_return_values_function(const string &needle, 
                                     const string &replace,
                                     string &haystack,    
                                     int &num_replacements)
{
  cout << "Calling multiple_return_values_function" << endl;
  cout << "Looking for \"" << needle << "\" and replacing with \"" << replace 
    << "\" in " << "\"" << haystack << "\"" << endl;
    
  for(string::size_type pos = haystack.find(needle); 
      pos != string::npos;
      pos = haystack.find(needle, pos))
  {
     
    haystack.replace(pos, replace.size(), replace);
    num_replacements++; 
  }
  
}

/*
 * A recursive function is a function that calls itself. When writing recursive
 * functions, it's critical that it stops calling itself when its 
 * done otherwise it will result in an infinite loop. The only function that
 * cannot call itself is main().
 */
string recursive_function(const string &needle, const string &replace, 
                          string &haystack, string::size_type pos)
{
    string::size_type next_pos = haystack.find(needle);
    
    if(next_pos != string::npos)
    {
        haystack.replace(next_pos, replace.size(), replace);
        recursive_function(needle, replace, haystack, next_pos);
    }
    
    return haystack;
}

/*
 * Pointer parameters behave just like other non-reference types, passed by
 * value. When other types are passed by value, there is no way to modify 
 * the original object, only its copy. With pointers, there are two copies of 
 * the pointer that is created. One that can modify the original 
 * while the other is local. 
 */
void pointer_argument_function(string *ptr_arg)
{
    cout << "*ptr_arg = " << *ptr_arg << endl;
    cout << "ptr_arg = " << ptr_arg << endl;
    
    // This is modifying the original object.
    *ptr_arg = "Changed";
    
    /*
     * We're creating a local variable that is used to modify the "copy" of
     * the pointer. 
     */
    string local_str = "Ponies";
    ptr_arg = &local_str;
    
    cout << "Setting *ptr_arg = \"Changed\"" << endl;
    cout << "Setting ptr_arg = &local_str (\"Ponies\")" << endl;
    
    cout << "*ptr_arg = " << *ptr_arg << endl;
    cout << "ptr_arg = " << ptr_arg << endl;
}

/*
 * When working with array arguments, they cannot be copied. Instead they are
 * treated as pointers to the first object. The three ways of passing arrays are as follows:
 * 
 * print_array_elements(const string *arr);
 * print_array_elements(const string *arr[]);
 * print_array_elements(const string *arr[10]);
 * 
 * The second and third methods of indicating that a function takes an array 
 * as an argument is the best way. Specifying the array size is for 
 * documentation purproses at best. 
 * 
 * When dealing with arrays, extra caution needs to be exercised to ensure that
 * access to the elements stay within bounds.
 */

/*
 * Demonstrates iterating through a character array using the C-Style method.
 */
void array_argument_function_1(const char carr[])
{
  if(carr)
  {
    while(*carr)
    {
      cout << *carr++ << endl;
    }
  }
}

/*
 * Demonstrates iterating through an array using the standard library.
 */
void array_argment_function_2(const int *begin, const int *end)
{
  while(begin != end)
  {
    cout << *begin++ << endl;
  }
}

/*
 * Demonstrates iterating through an array using the size of the array as an
 * argument. 
 */
void array_argument_function_3(const int ptr_arg[], size_t size)
{
  for(size_t i = 0; i < size; i++)
  {
    cout << ptr_arg[i] << endl;
  }
}
