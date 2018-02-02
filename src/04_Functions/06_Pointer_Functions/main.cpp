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



    func_t1 fp_td_1;
    /*fp_td_1 = compareString;
    fp_td_1(string("larger"), string("smaller"));
    func_t2 fp_td_2 = compareString;
    fp_td_2(string("really big"), string("small"));
    fp_t1 fp_td_3 = compareString;
    fp_td_3(string("one"), string("two"));
    fp_t2 fp_td_4 = compareString;
    fp_t2(string("hi"), string("bye"));*/

    return 0;
}