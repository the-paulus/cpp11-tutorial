#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::ios;

int main(int argc, char **argv)
{
    auto old_state = cin.rdstate();
    cout << "cin's old state: " << old_state << endl;
    cin.setstate(ios::eofbit);
    cout << "Setting cin's state to " << ios::eofbit << endl;
    cout << "cin's current state: " << cin.rdstate() << endl;
    cout << "clearing cin's state using clear()" << endl;
    cin.clear();
    cout << "cin's state: " << cin.rdstate() << endl;
}