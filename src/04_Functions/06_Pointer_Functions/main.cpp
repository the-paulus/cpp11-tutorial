#include "pointer_functions.hpp"

using std::cout;
using std::string;
using std::endl;

int main(int argv, char *argc[])
{
    bool (*pf) (const string &, const string &);

    cout << "pf = compareString" << endl;
    pf = compareString;

    cout << "calling pf(string(\"one\"), string(\"two\")): " << pf(string("one"), string("two")) << endl;

    cout << "pf = &compareString" << endl;
    pf = &compareString;

    cout << "calling pf(string(\"one\"), string(\"one\")): " << pf(string("one"), string("one")) << endl;

    cout << "pf(string(\"one\"), string(\"one\")): " << pf(string("one"), string("one")) << endl;
    cout << "(*pf)(string(\"one\"), string(\"one\")): " << (*pf)(string("one"), string("one")) << endl;
    cout << "compareString(string(\"one\"), string(\"one\")): " <<  compareString(string("one"), string("one")) << endl;

    unsigned int x = 1;
    unsigned int y = 2;
    int (*pf1)(int,int);
    pf1 = getTotal;
    cout << "int x = 1" << endl;
    cout << "int y = 2" << endl;
    cout << "pf1 = getTotal" << endl;
    cout << "pf1(x,y): " << pf1(x,y) << endl;

    cout << getLargerString(string("larger string"), string("string"), compareString) << endl;

    cout << function_pointer_t1(string("string1"), string("another string"), compareString) << endl;
    cout << function_pointer_t2(string("string1"), string("another string"), compareString) << endl;
    cout << function_pointer_t3(string("string1"), string("another string"), compareString) << endl;
    cout << function_pointer_t4(string("string1"), string("another string"), compareString) << endl;

    func_t1 (*pft) = compareString;
    pft("one", "two");
    return 0;
}