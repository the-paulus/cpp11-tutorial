Classes are used to define new data types. There are two ways of defining classes, the first is using `struct` and 
the other is using `class`. The biggest difference between the two is that `struct` will default all objects and 
functions to public while a `class` has the default of private. 

## Struct
The majority of the time `struct` is used to define plain old data types. `struct` offers compatibility with C, which 
may be of importantance. To define a class and it's methods using the `struct` keyword: 
```
struct Product {
    std::string name;
    std::string description;
    std::string identifier;
    unsigned int qty = 0;
    double price = 0.0;
    double ext_price() const; 
};

double Product::ext_price() const {
    return (this->price * this->qty);
}
```

## Constructors
The job of a constructor is to initialize the newly created object with data rather than having to call or set data 
members. A constructor is a function that doesn't have a return type nor can it be declared as const. It doesn't need 
to have any parameters just like a normal one. By default, when a class is defined without explicitly naming a 
constructor, the compiler will add a **default constructor** that takes no arguments. The compiler-generated constructor 
is called a **synthesized default constructor**. The following class definition has a synthesized default constructor 
assigned to it.

```
struct Sale {
    Sale() = default;
    Sale(istream &is);
    double total() const;
    void addProduct(Product *p);
    void removeProduct(Product *p);
    string printDate() const;
    string customer = string();
    time_t date = time(0);
    Product *products = nullptr;
};
```

It's important to know that if there are any constructors defined, then the compiler will not define a synthesized 
default constructor.

When dealing with objects of built-in or compound types are undefined and must either be default initialized or asigned 
a value right off the bat.

Classes that have members of a class type may not have a default constructor. Therefore the compiler cannot initialize 
that member. In that instance, a constructor must be defined.  

### Default Constructor
When creating constructors and the default constructor does the same thing as a synthesized default constructor then it 
can be defined as `Sale() = default`. In order to use the `= default` all data members with a built-in type must be 
initialized.

### Constructor Initializer Lists
Creating constructors that's only job is to initialize data members can be done using in-class initializers. That is
providing that the compiler being used supports it. 
```
Product(const string &pn) : name(pn) {}
Product(const string &pn, const string &d) : name(pn), description(d) {}
Product(const string &pn, const string &d, const string &i) : name(pn), description(d), identifier(i) {}
Product(const string &pn, const string &d, const string &i, unsigned int q) : name(pn), description(d), identifier(i), qty(q) {}
Product(const string &pn, const string &d, const string &i, unsigned int q, double p) : name(pn), description(d), identifier(i), qty(q), price(p) {}
``` 
The list of initializers sits between the semicolon and opening curly bracket. Each data member is is assigned the 
value of the object within its corresponding parenthesies. For example, the `Product(const string &pn) : name(pn) {}` 
constructor assigns the value of `pn` to the `name` data member. This equivolent to:
```
struct Product {
    Product(const string &pn);
    // ...
}

Product::Product(const string &pn) {
    name = pn;
}
```  
In the first constructor declaration, you will notice that there is no initializer list. It isn't that there is not one, 
but that the initializer list is empty. Members that do not appear in the constructor initializer list are initialized 
by the corresponding in-class intializer, providing there is one, or default initialized. 

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

## Class
Defining classes using the `struct` keyword does not force another developer from accessing data members or using it 
as intended. In order to enforce encapsulation, **access specifiers** can be used.

- Members that are defined after the `public` specifier are accessible to all parts of the program. 
- All members defined after the `private` specifier are only accessible to all other members in the class.

**Notes**
- Each class is different even if they have the same exact data and function members.
- Classes can be declared without being defined, also known as **forward declaration**. Forward declared classes can 
be used but in a limited way.
    - Pointers or references can be used on **incomplete types**.
    - Functions that use **incomplete types** can be declare, just not used.

```
class Sale {
public:
    Sale() = default;
    Sale(istream &is);
    double total() const;
    void addProduct(Product *p);
    void removeProduct(Product *p);
    string printDate() const;
private:
    string customer = string();
    time_t date = time(0);
    Product *products = nullptr;
};
```

### Friends
When using `struct` to define classes, all members are globally accessible which doesn't need to adhere to the rules of
encapsulation. Classes defined with `class` can no longer have "unclassified" or other class functions accessing 
nonpublic members. For example, the following will no longer work:

```
class Sale {
public:
    Sale() = default;
    Sale(istream &is);
    double total() const;
    void addProduct(Product *p);
    void removeProduct(Product *p);
    string printDate() const;
private:
    string customer = string();
    time_t date = time(0);
    Product *products = nullptr;
};

// The following no longer works:
istream &newSale(istream &is, Sale &sale);
ostream &printReceipt(ostream &os, const Sale &sale);
```

To get around that, you can define a class or function as a `friend` which only specifies access. `friend` declarations 
can only appear inside the class definition.

```
class Sale {
firend istream &newSale(istream &is, Sale &sale);
friend ostream &printReceipt(ostream &os, const Sale &sale); 
public:
    Sale() = default;
    Sale(istream &is);
    double total() const;
    void addProduct(Product *p);
    void removeProduct(Product *p);
    string printDate() const;
private:
    string customer = string();
    time_t date = time(0);
    Product *products = nullptr;
};

// Now works since the following functions were defined as friends.
istream &newSale(istream &is, Sale &sale);
ostream &printReceipt(ostream &os, const Sale &sale);
```

Classes can also be friends with other classes or have functions from other classes that were declared as friends.

For classes that are friends, they are able to share private information among themselves. 
```
class Screen {
// ....
}

class Window {
friend class Screen;
// ...
```

Classes that share member functions are a bit different in that they require additional steps to allow other classes
to access data or function members. 

```
class Screen {
public:
    // ...
    void clear(unsigned long wid);
    // ...
}

class Window {
public:
    // ...
    friend void Screen::clear(unsigned long wid);
    // ...
}
```
For the above to properly work the following must be done in listed order.
1. Declare but do not define the friend function in the class that is to be shared among others. 
2. Define the class that will be using the friend function that also includes the declaration the friendship function
from the first class.
3. Define the friend function that refers to the first class. 

#### Friendscope
Classes and nonmember functions do not need to be declared before they are used when declaring friendship. During that
declaration, it's assumed to be a part of the surrounding scope, yet the function is not declared within the scope that 
we are alluding to. Therefore it must be also declared where we say it is.

```
class Screen {
public:
    // standard class definition with no friends. AKA Forever alone.
}

class Window {
public:
    friend void Screen::clear() { // function definition goes here. }
    // rest of class definition...
}
// The following code will error due to the fact that no link has been made between friend functions.
Window new_window;
new_window.clear();
``` 
The proper way to fix this is as follows.
```
class Screen {
public:
    friend void clear();
    // standard class definition...
}

class Window {
public:
    friend void Screen::clear() { // function definition goes here. }
    // rest of class definition...
}
// Now, the following code will work.
Window new_window;
new_window.clear();
```


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