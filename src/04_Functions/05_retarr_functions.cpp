#include <iostream>

#include "05_retarr_functions.hpp"

using std::cout;
using std::endl;

int *return_array_function(int *ai, int size, int increment)
{
  
  int *tai = ai;
  
  for(int i = 0; i < size; i++)
  {
    /*
     * Dereference the variable so we can set a new value for it. Equivilent to:
     * ai[i] = ai[i] + increment;
     */
    *(tai+i) = *(tai+i)+increment;
  }
  
  /*
   * We could modify ai directly, but this demonstrates that we can return a 
   * local pointer, so to speak, as long as it points to a pointer that is not
   * local.
   */
  return tai;
}
