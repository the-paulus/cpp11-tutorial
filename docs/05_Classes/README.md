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
    time_t date;
    Product products = new Product;
    double total() const;
    void addProduct(Product *p) const;
    void removeProduct(Product *p) const;
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
