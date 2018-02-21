# Constructors
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

## Default Constructor
When creating constructors and the default constructor does the same thing as a synthesized default constructor then it 
can be defined as `Sale() = default`. In order to use the `= default` all data members with a built-in type must be 
initialized.

## Constructor Initializer Lists
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