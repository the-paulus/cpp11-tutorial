#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <iostream>
#include <string>
#include <cstdlib>

using std::cin;
using std::cout;
using std::istream;
using std::string;
using std::stod;
using std::stoi;

struct Product {
    Product() = default;
    Product(const string &pn) : name(pn) {}
    Product(const string &pn, const string &d) : name(pn), description(d) {}
    Product(const string &pn, const string &d, const string &i) : name(pn), description(d), identifier(i) {}
    Product(const string &pn, const string &d, const string &i, unsigned int q) : name(pn), description(d), identifier(i), qty(q) {}
    Product(const string &pn, const string &d, const string &i, unsigned int q, double p) : name(pn), description(d), identifier(i), qty(q), price(p) {}
    Product *first() const;
    Product *last() const;
    Product &update(const Product *p);
    string name;
    string description;
    string identifier;
    int qty = 1;
    double price = 0.0;
    double ext_price() const;
    Product *previous = nullptr;
    Product *next = nullptr;
};

istream &newProduct(istream &is, Product *product);

#endif