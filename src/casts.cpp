#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    
    double dval = 10.0;
    double *ptr_dval = &dval;
    void *adr_dval = &dval;
    
    cout << "dval: " << dval << endl;
    cout << "dval address: " << ptr_dval << endl;
    cout << "void *: " << adr_dval << endl;
    
}
