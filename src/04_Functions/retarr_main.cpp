#include <iostream>

#include "05_retarr_functions.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int ai[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int *pai = nullptr;
    
    pai = return_array_function(ai, 10, 1);
    
    for(int i = 0; i < 10; i++)
    {
      cout << *(pai+i) << endl;
    }
}
