# Class
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

## Literal Classes
Functions that return a `constexpr` must have its parameters and return type be literal types. Some classes may be 
considered a literal type, in addition to arithmetic types, references, and pointers. One distinction of a normal class
and a literal class is that they may have function members that are `constexpr`. Those members need to meet the 
requirements of a `constexpr` function and will are implicitly `const`.

Aggregate classes that has only literal type data members is a literal class. Nonaggregate classes must meet the 
following criteria in order to be a literal class:

- Data members are all literal types.
- Class must have at least one `constexpr` constructor.
- Data members that have an in-class initializer, the initializer for that member that is a built-in type must be a
`constexpr`. If the member is a class type, the initializer must use the member's own `constexpr` constructor.
- The destructor that is used to destroy objects of the class type must be the default.