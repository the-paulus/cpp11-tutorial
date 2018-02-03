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
typedef decltype(compareString) func_t3;
typedef bool (*func_t4) (const string &, const string &);

bool function_pointer_t1(const string &, const string &, func_t1);
bool function_pointer_t2(const string &, const string &, func_t2);
bool function_pointer_t3(const string &, const string &, func_t3);
bool function_pointer_t4(const string &, const string &, func_t4);
#endif