//
// Created by Paulus on 1/26/18.
//
#include <cassert>
#include <iostream>
#ifdef __GNUG__
#include <cstdlib>
#include <memory>
#include <cxxabi.h>
#endif

#define NDEBUG

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;

const int MAX_SIZE = 12;

string print_string(string str)
{
    #ifndef NDEBUG

    if ( str.size() > MAX_SIZE )
    {
        // __func__ is a variable defined by the compiler in each function that is a local static array of const char.
        cerr << __func__ << ": string is larger than the maximum length specified. length is: " << str.size() << endl;
    }

    return "";

    #endif

    return str;
}

/*string demangle(const char* name);
template <class T>
string type(const T& t) {
    return demangle(typeid(t).name());
}

#ifdef __GNUG__
string demangle(const char* name)
{
    int status = -4;
    std::unique_ptr<char[], void(*)(void*)> res {
            abi::__cxa_demangle(name, NULL, NULL, &status), std::free
    };
    return ( status == 0 ) ? string(res.get()) : name;
}
#else
string demangle(const char* name)
{
    return name;
}
#endif */

int main(int argv, char *argc[])
{

    string my_string;

    cout << "Enter a string: ";
    cin >> my_string;

    /*
     * The assert macro will not be included in the compiled code if the NDEBUG is defined. The NDEBUG can be also
     * defined by defining it on the command line:
     * gcc -D NDEBUG debugging.cpp -o debugging
     */
    assert( my_string.size() < MAX_SIZE);

    cout << endl << "Your string: " << my_string << endl;

    // Variables defined by the compiler to help with debugging:
    cout << "Compiler Variable\t\tValue" << endl;
    cout << "__func__\t\t\t" << __func__ << endl;
    cout << "__FILE__\t\t\t" << __FILE__ << endl;
    cout << "__LINE__\t\t\t" << __LINE__ << endl;
    cout << "__TIME__\t\t\t" << __TIME__ << endl;
    cout << "__DATE__\t\t\t" << __DATE__ << endl;

    return 0;
}