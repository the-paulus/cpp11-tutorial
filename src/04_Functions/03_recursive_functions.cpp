#include "03_recursive_functions.hpp"

/*
 * Recursive function need a way to bail out or else they will
 * execute forever. Each time the recursive function is called
 * more and more memory is needed to execute it because the data
 * from the previous call is still in memory.
 * 
 * The only function that cannot call itself is the main function.
 */
long long factoral(const int number)
{
    if(number > 1)
    {
        return factoral(number - 1) * number;
    }
    
    return 1;
}
