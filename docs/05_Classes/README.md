# Classes
Classes are used to define new data types. There are two ways of defining classes, the first is using `struct` and 
the other is using `class`. The biggest difference between the two is that `struct` will default all objects and 
functions to public while a `class` has the default of private. 

1. [struct](Struct.md)
2. [class](Class.md)
3. [Constructors](Constructors.md)
4. [Member Functions](MemberFunctions.md)
5. [Friends](Friends.md)
    1. [Friendscope](Friends.md#friendscope)
    
### Type Member
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

### Inline Member Functions
Inline functions can be leveraged to increase the performance of an application. Instead of referring to a function 
that is being called, the compiler can replace the function defined as `inline` with the actual code of that function.
This is only a suggestion to the compiler and may be ignored for a number of reasons such as if the inline function 
is too large.

### Overloaded Member Functions
As with regular functions member functions can be overloaded. The same rules apply to overloaded member functions as 
regular overloaded functions.

Overloaded `const` member functions are called depending on the type of object, `const` or non`const`. If the 
object is defined as `const`, only `const` member functions can be called. For non`const` objects, either member 
function can be called but the best match for the function will be the non`const`. 

```
class Screen {
public:
    Screen &display(ostream &os) { render(os); return *this; }
    const Screen &display(ostream &os) const { render(os); return *this; }
private:
    void render(ostream &os) const { os << contents; }
};
```  

Above, we have an overloaded member function called **display**. Both functions call a `const` function called 
**render**. This makes the program cleaner and versitile as we can promote a non`const` object but cannot demote it.
There are two possible scenarios that we take into account when implicitly passing `this` to the object:
1. The non`const` version implicitly converts `this` pointer to `const`, performs its task and returns a pointer to a
non`const` object.
2. The `const` version does the same thing, with the exception of not having to convert the `this` pointer. 
```
Screen ncs("nonconst screen", dimensions, position);
const Screen cs("const screen", dimensions, position);
ncs.rename("nonconst screen - renamed").display(cout); // calls const Screen &display(ostream &os) const;
cs.display(cout);  // calls Screen &display(ostream &os);
```
### mutable Data Members
Sometimes it may be necessary to have a data member be modified even though it is within a `const` member function. 
Using the `mutable` keyword, indicates that the data member can be modified regardless if it lives within a `const`
member function.

```
```

### Class Type Data Member Initialization
Under the C++11 standard, the best way to initialize a data member of type `class` is to use an in-class initializer.
Use of the assignment operator(`=`) or initialization list assignment is valid.

```
// Prefered way
vector<Screen> screens{ Screen(1920,1080, "primary") };
// Also acceptible
vector<Screen> screens = { Screen(1920, 1080, "primary") };
```

### Returning *this
Member functions that perform an operation on data within the class and returns itself when completed must 
be defined as a reference. 

```
Window& Window::move(position_t position) {
    this->position = position;
    return *this;
}

// Usage:
Window w = new Window();
w.move(pos).resize(dim); 
```
If the function was declared and defined as having a nonreference return type, then the return value would be a copy 
of the object with the modifications.
```
Window Window::move(position_t position) {
    this->position = position;
    return *this;
}
Window w = new Window();
Window tmp = w.move(pos);
```   