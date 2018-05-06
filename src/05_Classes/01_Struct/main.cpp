#include <exception>
#include <iomanip>
#include <iostream>
#include "sale.hpp"

using namespace std;

char print_menu()
{
    int choice = 0;

    cout << "***** Main Menu *****" << endl;
    cout << "1. Add Product" << endl;
    cout << "2. Edit Product" << endl;
    cout << "3. Remove Product" << endl;
    cout << "4. List Products" << endl;
    cout << "5. Complete Sale" << endl;
    cout << "6. Cancel Sale" << endl;
    cout << "[1-6]: ";

    try {

        cin >> choice;

    } catch(const invalid_argument &invalid_argument_ex) {

        cerr << "Input must be numeric." << endl;

    }

    if( choice < 1 && choice > 6 ) {

        choice = 0;

    }

    return choice;

}

int main(int argc, char **argv) {
    Sale sale(cin);
    Product *product = nullptr;
    string line, input, choice;
    bool complete = false;
    unsigned int p_sel, pidx = 0;

    while( !complete ) {

        switch(print_menu()) {
            case 1:
                cout << "***** Add Product *****" << endl;
                product = new Product();
                try {
                    newProduct(cin, product);
                    sale.addProduct(product);
                } catch(const invalid_argument &ia) {
                    cerr << "Input is not numeric." << endl;
                } catch(const out_of_range &oor) {
                    cerr << "Input is out of range." << endl;
                }
                break;
            case 2:
                cout << "Edit Product:" << endl << endl;
                product = sale.products->first();
                if(product == nullptr) {
                    cout << "There are no products on this order yet." << endl;
                } else {
                    while(product != nullptr) {
                        cout << ++pidx << ") " << setw(8) << left << product->identifier << "|" << setw(32) << product->name << endl;
                        product = product->next;
                    }
                    cout << "Enter 1-" << pidx << " to edit product or 0 to cancel: ";
                    cin >> p_sel;
                    if(p_sel > pidx) {
                        cout << "Invalid selection." << endl;
                    } else {
                        product = sale.products->first();
                        pidx = 1;
                        while( product != nullptr ) {
                            if(pidx == p_sel) {
                                cout << "Product Name: ";
                                cin >> input;
                                product->name = input;
                                cout << "Description: ";
                                cin >> input;
                                product->description = input;

                                break;
                            }

                            product = product->next;
                        }
                    }
                }
                break;
            case 3:
                cout << "Remove Product:" << endl;
                break;
            case 4:
                cout << "List Products:" << endl << endl;
                product = sale.products->first();
                while(product != nullptr) {
                    cout << setw(8) << left << product->identifier << "|" << setw(32) << product->name << "|" << setw(10) << product->price << "|" << setw(4) << product->qty << "|" << setw(8) << product->ext_price() << endl;
                    cout << right << setw(9) << "|" << product->description << endl;
                    product = product->next;
                }
                break;
            case 5:
                printReceipt(cout, sale);
                cout << "Printing receipt..." << endl;
                complete = true;
                break;
            case 6:
                complete = true;
                break;
            default:
                cout << "Invalid selection." << endl;
        }
    }
}