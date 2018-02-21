# Struct
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