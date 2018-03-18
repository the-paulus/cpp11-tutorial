# Data Members

## Class Type Data Member Initialization
Under the C++11 standard, the best way to initialize a data member of type `class` is to use an in-class initializer.
Use of the assignment operator(`=`) or initialization list assignment is valid.

```
// Prefered way
vector<Screen> screens{ Screen(1920,1080, "primary") };
// Also acceptible
vector<Screen> screens = { Screen(1920, 1080, "primary") };
```

## mutable Data Members
Sometimes it may be necessary to have a data member be modified even though it is within a `const` member function. 
Using the `mutable` keyword, indicates that the data member can be modified regardless if it lives within a `const`
member function.

```
class Screen {
public:
    void const_function() const;
private:
    mutable unsigned long access_ctr;
};

void Screen::const_function() const
{
    ++access_ctr;
}
```

## Type Members
Classes can define their own local names for types which are subject to the same access control rules as any other 
member. 

**Important:** Members that define types must appear before they are used.
 
```
class Screen {
public:
    typedef std::string::size_type pos;
private:
    pos cursor = 0;
    pos height = 0;
    std::string contents;
};
```

Another way to define a type member is by implementing the `using` keyword.

```
using pos = std::string::size_type;
```

After defining new member types, they can be used in other sections of the program.

```
// ...
#include "WindowManager.hpp"

WindowManager::dimensions_t dimensions;

using WindowManager::dimensions_t;
dimensions_t dimensions;
```

## Name Lookup and Class Scope
When looking up the name of a class, the process is relatively straight forward.
1. Look for the declaration of the name in the block of which the name was used. Names that have been 
declared prior are the only considerations.   
2. If the name is not found, look within the enclosing scope.
3. If the class is not found there, then the program will throw an error.

The exception to the above is during resolution while in member functions of a class. In that instance the 
process is as follows:
1. Member declarations are compiled first.
2. Function bodies are compiled only after the entire class has been seen.

Since the member function bodies are not processed until after the entire class is observed, they can use any 
name defined inside the class. However, this does not apply to member declarations that use class types. This is 
because the declarations are processed before the entire class is observed.

Ordinarily, code within an inner scope can redefine a name from an outer scope but there is an exception when it comes 
to classes. 

```
typedef unsigned long window_id_t;

class Window {
public:
    typedef unsigned long window_id_t; // Not valid
    // ...
}
```  