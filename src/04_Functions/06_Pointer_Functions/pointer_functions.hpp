#ifndef __POINTER_FUNCTIONS_HPP__
#include <iostream>
#include <string>

using std::string;

bool compareString(const string &str1, const string &str2);
int getTotal(int x, int y);
int getTotal(int *x, int *y);
string getLargerString(const string &str1, const string &str2, bool pf(const string &, const string &));

typedef decltype(compareString) func_t1;
typedef bool func_t2(const string &, const string &);
typedef decltype(compareString) fp_t1;
typedef bool (*fp_t2) (const string &, const string &);

#endif