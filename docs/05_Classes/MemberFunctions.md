# Member Functions
## const Member Functions
Defining methods as const by using a trailing `const` modifier changes the pointer `this` to a const. Without the use 
of the modifier, `this` is of type `class_type * const`. This allows us to bind `this` to a `const` object or call 
ordinary member functions on a `const` object. Since, `this` is implicitly defined, we use the trailing `const` 
modifier. If `this` was defined as a parameter, it would look like this:

```
double ext_price(const Product * const this);
```

Since the body of the function, `ext_price` doesn't change the object to which `this` is pointing to, we can define it
as such allowing the function to be more flexible. 

## Returning 'this'
Additional steps need to be taken when modifying `this` using a member function. In order to return the modified object
we have to dereference it.

```
Product & Product::update(const Product &p) {
    name = p.name;
    description = p.description;
    identifier = p.identifier;
    qty = p.qty;
    price = p.price;
    return *this;
}

Product p = new Product;
p.update(otherProduct); // P now contains the data in otherProduct.
```

## Nonmember Class-Related Functions
Functions that define operations that are conceptually part of a class but part of the interface are defined as
nonmember class functions. These are defined as normal functions and should follow the same guidelines when being 
defined. The same guidelines for constructors also apply to constructors defined outside the class body.

```
struct Product {
    Product(std::istream &is);
    // ...
};

Product::Product(std::istream &is) {
    // Work goes here.
}
```

## Inline Member Functions
Inline functions can be leveraged to increase the performance of an application. Instead of referring to a function 
that is being called, the compiler can replace the function defined as `inline` with the actual code of that function.
This is only a suggestion to the compiler and may be ignored for a number of reasons such as if the inline function 
is too large.

## Overloaded Member Functions
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

## Returning *this
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

## Out of Scope Members
Since a class is a scope, we must provide the class name in addition to the function when defining a member function 
outside of the class since the names of its members are hidden. After providing the scope, or name of the class, using 
class members is possible without qualification (`::`).

```
// Window.hpp
class Window {
public:
    typedef unsigned long window_id;
    window_id getWindowID();
    void setWindowID(window_id id);
    // ....
private:
    window_id window_id;
}

// Window.cpp
#include "Window.hpp"

Window::window_id Window::getWindowID() {
    return this->window_id;
}

void Window::setWindowID(Window::window_id id) {
    this->window_id = id;
}
```

Since we provided the scope, `Window::`, we do not have to type `Window::window_id` to specify the object's type. 
When defining the `getWindowID` function, which returns a `window_id` object, we must specify the scope because the 
return. This is still the case with the `Window::getWindowID` functions because the return type is outside the scope.

## Block-Scope within Member Definitions
When using a name within the body of a member function the resolution process takes the following steps:
1. Look for a declaratoin of the name inside the member function's body.
2. When no declaration is found within the member function body, look for the declaration inside the class.
3. If the declaration is still not found, then look in the global scope.

It is consider *bad practice* to use the same name for both a parameter and data member.
```
class Window {
public:
    // ...
    void setContent(string content) { content = content; }
    void setPosition(position_t position) { this->position = position; }
    void setWindowID(window_id_t window_id) { ::window_id = window_id; }
    void setDimensions(dimensions_t dms) { dimensions = dms; }
    // ...
private:
    window_id_t window_id;
    string content;
    position_t position;
    diemensions_t diemensions;
}
```

When the `setContent` function is called, the value passed in through the parameter, is reassigned to the parameter. 
The `setPosition` function works as it should, in that a new position is assigned to the window properly. In the 
`setWindowID` function, instead of using `this`, we use the scope operator (`::`). To be a good programmer, name the 
parameter something other than a data member as demonstrated in `setDimensions`. 

## `static` Class Member Functions
When functions provide functionality to all objects of a particular class rather than individual objects, they can be 
declared as `static`.

```
class WindowManager {
public:
    static unsigned long GetScreenCount() 
    // Other member functions can access static members without using the scope operator (::)
    void printScreenCount() { cout << GetScreenCount() << endl; }
     // ....
};

// The static keyword only appears when declaring the function.
unsigned long WindowManager::GetScreenCount() { return this->screens.length; }

unsigned long screen_count = WindowManager::GetScreenCount(); // accessing a static member through the scope operator.
```

Any function or data member declared as `static` exists outside of any object and do not contain any data associated with 
`static` data members. Member functions defined in this manner are not bound to any object and therefore they do not have 
a `this` pointer which also means they cannot be declared as `const`.

Even though `static` members exist outside of any object, objects that are defined by the class type containing a `static` 
member may still access it.

```
WindowManager wm;
WindowManager *wm2 = &wm;
cout << wm.GetScreenCount() << endl;
cout << wm2->GetScreenCount() << endl;
```