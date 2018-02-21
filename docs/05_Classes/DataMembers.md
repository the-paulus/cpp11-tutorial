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