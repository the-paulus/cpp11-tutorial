# Pointer Functions
Pointer functions are just like regular pointers but they point to functions rather than objects in memory. The type
of the pointer function is determined by the return type. 

The following is declares a pointer function that takes two const string references and that returns a bool.
```cpp
bool (*pf)(const string &str1, const string &str2);
```
**Important:** The parenthentheses around `*pf` are necessary. Omitting them would mean that we are declaring a 
function that returns a pointer to `bool`.

To define pf, there are two ways of doing so:
```cpp
pf = compareString;
pf = &compareString;
```

There are three different ways to call the `compareString` function now:
```cpp
bool b1 = pf(string("one"), string("two"));
bool b2 = (*pf)(string("one"), string("one"));
bool b3 = compareString(string("one"), string("one"));
```

There is no conversion between pointers to one function type and pointers to another function type. However, a nullptr 
can be assigned to the pointer function:
```
string::size_type getTotalLength(const string &, const string &);
bool cstringGetTotalLength(const char*, const char*);

pf = nullptr;
pf = getTotalLength;
pf = cstringGetTotalLength;
```
Assigning `getTotalLength` to `pf` will return an error because the return type differs while the 
`cstringGetTotalLength` will fail because the parameter types differ.

## Overloaded Functions
When working with overloaded functions and pointer functions, the pointer must point to a function that matches *exactly*:
```
int getTotal(int, int);
int getTotal(int *, int *);
int (*pf)(unsigned int, unsigned int);  
```
The pointer function must have it's parameters defined as either `(int, int)` or `(int *, int *)`.

## Pointer Function Parameters
A pointer function parameter parameter cannot have the function type. Instead the parameter can be a pointer to a function.
There are two ways of doing this, but the results are the same:
```cpp
string getLargerString(const string &str1, const string &str2, bool pf(const string &, const string &))
string getLargerString(const string &str1, const string &str2, bool (*pf)(const string &, const string &))
```
To save time, type aliases and `decltype` can be used
```cpp
typedef unsigned int func_t1(const string &, const string &);

// Usage:
void printTotalLength(const string &str1, const string &str2, func_t f)
{
    std::cout << "Total length of \"" <<  str1 << "\" and \"" << str2 << "\" is " << f << std::endl;
}

// This is an even shorter method of defining a type and is equivalent to typedef unsigned int func_t1(const string &, const string &);
typedef decltype(getTotalLength) func_t2;

// Usage:
void printTotalLength(const string &str1, const string &str2, func_t2 f)
{
    std::cout << "Total length of \"" <<  str1 << "\" and \"" << str2 << "\" is " << f << std::endl;
}

// Another way of defining a type.
typedef unsigned int (*pf)(const string &, const string &);
typedef decltype(getTotalLength) getTotalLength2;
```

## Returning a Function Pointer
It is not possible to return a function type but it is possible to return a pointer to a function type. The return type 
must be a pointer type. Keep in mind that the compiler will not treat the return type as the corrosponding pointer type.
The easiest way to declare a function that returns a function pointer is by using a type alias:
```cpp
using F = int(int *, int);
using FP = int(*)(int *, int);
```
When returning a function type, it is not converted like it is when being used as a parameter.
```cpp
FP func(int);   // func returns a function pointer and FP is a function pointer.
F func(int);    // Error: can't convert a function type to a function pointer.
F *func(int);   // Explicitly specifying that the return type is a function pointer.
``` 
To simplify declarations of functions that return function pointers, we use a trailing return
```
auto func(int) -> int (*)(int *, int);
```
When it is known which function(s) that are to be returned, the `decltype` can be used to simplify writing the function.
```
string::size_type sumLength(const string &, const string &);
decltype(sumLength) *getSumLength(const string &);
```