#include <string>

#include "04_refret_functions.hpp"

using std::string;

/*
 * Returning a reference from a function is like working with object references. 
 * When returning a reference, it's important to never return a reference to a
 * local object. Local objects will be destroyed when the function completes and
 * the object will be invalidated.
 */
const string &shorterString(const string& string_one, const string& string_two)
{
  return (string_one.size() <= string_two.size()) ? string_one : string_two;
  
  string local_object = "Return value";
  
  /*
   * local_object will be destroyed after the following statement. 
   */
  return local_object;
  
  /*
   * This creates a temporary string object and will be destroyed after the 
   * return statement finishes executing.
   */
  return "Return value";
}
