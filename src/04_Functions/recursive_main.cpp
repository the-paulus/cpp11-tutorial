#include <iostream>

#include "03_recursive_functions.hpp"

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    int number;
    long long result;
    
    cout << "Enter an integer value: ";
    cin >> number;
    
    result = factoral(number);
    
    cout << endl << "The factoral of " << number << " is " << result;
    
    return EXIT_SUCCESS;
}
