#include <iostream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::ends;
using std::flush;
using std::nounitbuf;
using std::ostream;
using std::unitbuf;

int main(int argc, char **argv)
{
    int val = 0;

    cout << "Using 'endl' to flush the buffer. " << endl;
    cout << "Using 'flush' to flush the buffer. " << flush;
    cout << "Using 'ends' to flush the buffer. " << ends;
    cout << "Using 'endl' again." << endl;

    cout << "Beginning 'unitbuf'.." << endl;
    cout << unitbuf;
    cout << "Line one...";
    cout << "Line two...";
    cout << "Line three...";
    cout << "Ending unitbuf...";
    cout << nounitbuf;
    cout << "Line four";
    cout << "Line five";
    cout << "Line six";

    cout << "Tying streams together: " << endl;
    cout << "cout address: " << (&cout) << endl;
    cout << "cin address: " << (&cin) << endl;
    cout << "cerr address: " << (&cerr) << endl;
    cout << "Address of stream tied to cin: " << cin.tie() << endl;
    cout << "Untying cout from cin" << endl;
    ostream *prev_steram = cin.tie(nullptr);
    cout << "Address of stream tied to cin: " << cin.tie() << endl;
    cout << "Tying cerr to cin." << endl;
    cout << "Address of stream tied to cin: " << cin.tie(&cerr); << endl;
    cout << "Restoring stream: " << cin.tie(prev_steram) << endl;
}