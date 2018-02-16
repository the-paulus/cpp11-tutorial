# 02. Overloaded Functions

## Function Matching
Most of the time, finding the correct overloaded function is straight forward when each instance has a different number 
of parameters. When overloaded functions have the same number of parameters but have different types or combinations
the compiler must find the correct function to use.

```
void function();
void function(int);
void function(double, double = 3.14);
```

To determine the function to use the following steps are taken by the compiler:
1. Identify the set of overloaded functions to consider for the particular call.
2. Identify the set of overloaded functions that can be called with the arguments in the given call, **viable function.**
Viable functions are defined to be a function that has the same number of parameters and can be converted to.

When calling `function(5.2)` the best match is `void function(double, double = 3.13)` because the argument passed is a 
double.

### Order of Argument Type Conversions
1. Exact match
    - Argument and parameter types are identical.
    - Argument is converted from an array or function type to the corresponding pointer type.
    - Top-level `const` is added to or discarded from the argument.
2. Match through const conversion.
3. Match through promotion.
4. Match through an arithmetic or pointer conversion.
5. Match through a class-type conversation.