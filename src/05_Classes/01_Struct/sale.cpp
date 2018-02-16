#include <iomanip>
#include <iostream>
#include "sale.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::left;
using std::right;


Sale::Sale(istream &is) {
    cout << "Customer Name: ";
    getline(is,this->customer);
}

double Sale::total() const {
    double total = 0.0;
    Product *p = this->products->first();

    while(p->next != nullptr) {
        total += p->next->ext_price();
        p = p->next;
    }

    return total;
}

void Sale::addProduct(Product *p) {
    Product *ptr_product = nullptr;

    if(this->products == nullptr) {
        this->products = new Product(p->name, p->description, p->identifier, p->qty, p->price);
    } else {
        ptr_product = this->products->last();
        ptr_product->next = new Product(p->name, p->description, p->identifier, p->qty, p->price);
        ptr_product->next->previous = ptr_product;
    }

}

void Sale::removeProduct(Product *p) {
    Product *ptr_product = this->products->first();
    Product *ptr_temp = nullptr;

    while(ptr_product->next != p || ptr_product->next != nullptr) {
        if(ptr_product == p) {
            ptr_product->previous->next = ptr_product->next;
            delete ptr_product;
        }
    }
}

string Sale::printDate() const {
    char pstr[80];
    strftime(pstr, 80, "%D", localtime(&this->date));
    return string(pstr);
}

istream &newSale(istream &is, Sale &sale) {
    cout << "Customer Name: ";
    getline(is, sale.customer);
    return is;
}

ostream &printReceipt(ostream &os, const Sale &sale) {
    cout << std::setw(12) << left << "Customer:" << sale.customer << endl;
    cout << std::setw(12) << left << "Date:" << sale.printDate() << endl;
}