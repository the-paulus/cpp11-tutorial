#include "pointer_functions.hpp"

using std::string;

bool compareString(const string &str1, const string &str2)
{
    return str1.compare(str2);
}

int getTotal(int x, int y)
{
    return x + y;
}

int getTotal(int *x, int *y)
{
    return (*x) + (*y);
}

string getLargerString(const string &str1, const string &str2, bool pf(const string &, const string &))
{
    return pf(str1, str2) ? str1 : str2;
}

bool function_pointer_t1(const string &str1, const string &str2, func_t1 f)
{
    return f(str1, str2);
}

bool function_pointer_t2(const string &str1, const string &str2, func_t2 f)
{
    return f(str1, str2);
}
bool function_pointer_t3(const string &str1, const string &str2, func_t3 f)
{
    return f(str1, str2);
}

bool function_pointer_t4(const string &str1, const string &str2, func_t4 f)
{
    return f(str1, str2);
}