#include "product.hpp"

double Product::ext_price() const {
    return (this->price * this->qty);
}

Product * Product::first() const {
    Product *ptr_product = const_cast<Product *>(this);

    while(ptr_product->previous != nullptr) {
        ptr_product = ptr_product->previous;
    }

    return ptr_product;
}

Product *Product::last() const {
    Product *ptr_product = const_cast<Product *>(this);

    while(ptr_product->next != nullptr) {
        ptr_product = ptr_product->next;
    }

    return ptr_product;
}

Product & Product::update(const Product *p) {
    name = p->name;
    description = p->description;
    identifier = p->identifier;
    qty = p->qty;
    price = p->price;
    return *this;
}

istream &newProduct(istream &is, Product *product) {
    string input;
    string::size_type sz;

    cout << "Product Name: ";
    is >> input;
    product->name = input;

    cout << "Description: ";
    is >> input;
    product->description = input;

    cout << "Product Identifier: ";
    is >> input;
    product->identifier = input;

    cout << "Quantity: ";
    is >> input;
    product->qty = stoi(input, &sz);

    cout << "Price: ";
    is >> input;
    product->price = stod(input, &sz);

    return is;
}