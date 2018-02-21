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