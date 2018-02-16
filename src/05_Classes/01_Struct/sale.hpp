#ifndef __SALE_HPP__
#define __SALE_HPP__

#include <ctime>
#include "product.hpp"

using std::istream;
using std::ostream;
using std::string;

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

istream &newSale(istream &is, Sale &sale);
ostream &printReceipt(ostream &os, const Sale &sale);

#endif