#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;
 
int main(int argc, char **argv)
{

    /*
     * References are aliases of another object and do not have an address.
     * Therefore, they must have an object assigned to them. The type of alias
     * must match the type of the object that it is being initialized with.
     * Below we create an alias' for the object 'ival' by using the '&'
     * modifier.
     */

    int ival = 42;
    int &rival = ival;
    
    cout << "ival\t: " << ival << endl;
    cout << "rival\t: " << rival << endl << endl;
    
    rival++;
    
    cout << "ival\t: " << ival << endl;
    cout << "rival\t: " << rival << endl << endl;
    
    ival++;
    
    cout << "ival\t: " << ival << endl;
    cout << "rival\t: " << rival << endl << endl;
}
