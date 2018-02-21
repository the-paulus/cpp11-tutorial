# Friends
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

## Friendscope
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