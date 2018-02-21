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