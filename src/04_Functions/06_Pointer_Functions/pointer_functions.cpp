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