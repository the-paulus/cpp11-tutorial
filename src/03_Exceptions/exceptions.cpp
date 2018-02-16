#include <exception>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::runtime_error;

int main(int argc, char **argv)
{
    int ival_one = 0;
    int ival_two = 0;
    
    try
    {
        cout << "Enter a value between 1 and 10: ";
        cin >> ival_one;
        cout << "Enter another value between 1 and 10: ";
        cin >> ival_two;
        
        if(
        
    } 
    catch(runtime_error err)
    {
        cout << err.what() << endl;
    }
    
    cout << ival;
    return 0;
    
}
