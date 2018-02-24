# Struct
The majority of the time `struct` is used to define plain old data types. `struct` offers compatibility with C, which 
may be of importance. To define a class and it's methods using the `struct` keyword: 
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

## Aggregate Classes
Classes that defined using the `struct` keyword are also known as **aggregate classes**. The criteria for a class to be 
an **aggregate class** are

- all data members are `public`.
- it doesn't have any constructors defined.
- no in-class initializers.
- no base classes or `virtual` functions.

The following is an example of an aggregate class:

```
struct Product {
    string identifier;
    string name;
    string description;
    unsigned double price;
};
```

An aggregate class' data members can be initialized by using a list of member initializers. For that to work
the order of the initial values must align with the declaration order of the data members. The number of initializers 
cannot exceed the number of data members but there can be fewer. When the number of initializers is fewer the 
remaining data members are default initialized.

```
Product p = { "identifier", "product name", "product description", 100.00 };
```

There are three major drawbacks to explicitly intializing members of an object of class type:

1. All data members of the class must be public.
2. The burden is on the user of the class to correctly initialize all members of every object correctly.
3. Modification to the order or number of data members of the class requires all initialization statements to be 
updated.