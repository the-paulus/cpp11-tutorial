#include <iostream>
#include <fstream>

using std::istream;
using std::ostream;
using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::string;
using std::ios;

istream &read(istream &is, string &line) {
    getline(is, line);
    return is;
}

ostream &write(ostream &os, string &line) {
    os << line;
    return os;
}

int main(int argc, char **argv) {
    ifstream input;
    ofstream output;
    string input_filename("input.txt");
    string line;
    string output_filename("output.txt");

    cout << "Opening input.txt and adding text." << endl;
    output.open("input.txt");
    cout << "Is " << input_filename << " open? " << output.is_open() << endl;
    output << "This is an input file." << endl << "This is line 2." << endl;
    cout << "Closing " << input_filename << "..." << endl;
    output.close();
    cout << "Is " << input_filename << " still open? " << output.is_open() << endl;
    cout << "Opening " << input_filename << " for reading..." << endl;
    input.open(input_filename);
    cout << "Opening " << output_filename << " for writing..." << endl;
    output.open(output_filename);

    while(getline(input, line)) {
        cout << "Writing to file: " << line << endl;
        output << line << endl;
    }

    // Input file has the eofbit turned on and no longer can be read from. We must clear it before reading from it again.
    input.clear();
    // Clearing the bit eofbit does not reset the file position back to the beginning. We use the seekg passing 0 to
    // set it back to the beginning of the file.
    input.seekg(0);

    cout << "Writing file using functions" << endl;
    output << endl << "Writen using functions:" << endl;

    while(read(input, line)) {
        write(output, line) << endl;
    }
}
