#include <iostream>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) 
{

  std::unordered_map<std::type_index, std::string> type_names;
  type_names[std::type_index(typeid(bool))] = "Boolean";
  type_names[std::type_index(typeid(char))] = "Character";
  type_names[std::type_index(typeid(wchar_t))] = "Wide Character";
  type_names[std::type_index(typeid(char16_t))] = "Unicode Character";
  type_names[std::type_index(typeid(char32_t))] = "Unicode Character";
  type_names[std::type_index(typeid(short))] = "Short Integer";
  type_names[std::type_index(typeid(int))] = "Integer";
  type_names[std::type_index(typeid(long))] = "Long Integer";
  type_names[std::type_index(typeid(long long))] = "Long Long Integer";
  type_names[std::type_index(typeid(float))] = "Single-percision";
  type_names[std::type_index(typeid(double))] = "Double-precision";
  type_names[std::type_index(typeid(long double))] = "Long Double";

  cout << "Type ID\t\t" << "Type\t\tMeaning\t\t\t\tGuaranteed Size in bytes" << endl;
  cout << typeid(bool).name() << "\t\tbool\t\tboolean\t\t\t\t" << sizeof(bool) << endl;
  cout << typeid(char).name() << "\t\tchar\t\tcharacter\t\t\t" << sizeof(char) << endl;
  cout << typeid(wchar_t).name() << "\t\twchar_t\t\twide character\t\t\t" << sizeof(wchar_t) << endl;
  cout << typeid(char16_t).name() << "\t\tchar16_t\tunicode character\t\t" << sizeof(char16_t) << endl;
  cout << typeid(char32_t).name() << "\t\tchar32_t\tunicode character\t\t" << sizeof(char32_t) << endl;
  cout << typeid(short).name() << "\t\tshort\t\tshort\t\t\t\t" << sizeof(short) << endl;
  cout << typeid(int).name() << "\t\tint\t\tinteger\t\t\t\t" << sizeof(int) << endl;
  cout << typeid(long).name() << "\t\tlong\t\tLong integer\t\t\t" << sizeof(long) << endl;
  cout << typeid(long long).name() << "\t\tlong long\tLong integer\t\t\t" << sizeof(long long) << endl;
  cout << typeid(float).name() << "\t\tfloat\t\tsingle-precision\t\t" << sizeof(float) << endl;
  cout << typeid(double).name() << "\t\tdouble\t\tdouble-precision\t\t" << sizeof(double) << endl;
  cout << typeid(long double).name() << "\t\tlong double\tLong double\t\t\t" << sizeof(long double) << endl
    << endl;

  cout << "==================" << endl;
  cout << "Numeric Literals" << endl;
  cout << "==================" << endl;
  
  cout << "Suffix\t\t" << "Example\t\t\t" << "Value\t\t\t" << "Type\t\t\t"
    << "Size" << endl;
  
  cout << "l/L\t\t102401l/102401L\t\t" << 102401l << "/" << 102401L << "\t\t" 
    << type_names[std::type_index(typeid(102401l))] << "\t\t" 
    << sizeof(102401l) << endl;

  cout << "ll/LL\t\t102401ll/102401LL\t" << 102401ll << "/" << 102401LL 
    << "\t\t" << type_names[std::type_index(typeid(102401ll))] << "\t" 
    << sizeof(102401ll) << endl;
    
  cout << "f/F\t\t1.2401f/1.2401F\t\t" << 1.2401f << "/" << 1.2401F 
    << "\t\t" << type_names[std::type_index(typeid(1.2401f))] << "\t" 
    << sizeof(1.2401f) << endl;
  
  cout << "l/L\t\t1.2401l/1.2401L\t\t" << 1.2401l << "/" << 1.2401L 
    << "\t\t" << type_names[std::type_index(typeid(1.2401l))] << "\t\t" 
    << sizeof(1.2401l) << endl << endl;
    
  cout << "Prefix\t\t" << "Type\t\t\t" << "Example\t\t\t" << "Value" << endl;
  cout << "(none)\t\t" << "Decimal\t\t\t" << "10\t\t\t" << 10 << endl;
  cout << "0\t\t" << "Octal\t\t\t" << "077\t\t\t" << 077 << endl;
  cout << "0x\t\t" << "Hexidecimal\t\t" << "0xFF\t\t\t" << 0xFF << endl;
  cout << "0b\t\t" << "Binary\t\t\t" << "0b1110\t\t\t" << 0b1110 << endl;
  cout << endl << endl;
  
  cout << "==================" << endl;
  cout << "String Literals" << endl;
  cout << "==================" << endl;

  cout << "Prefix\t\t" << "Example\t\t\t" << "Value\t\t\t" << "Type\t\t\t" 
    << "Size" << endl;
  
  cout << "u\t\t" << "u\"C++\"\t\t\t" << u"C++" << "\t\t" 
    << typeid(u"C++").name() << "\t\t\t" << sizeof(u"C++") << endl;
  
  cout << "U\t\t" << "U\"C++\"\t\t\t" << U"C++" << "\t\t" 
    << typeid(U"C++").name() << "\t\t\t" << sizeof(U"C++") << endl;
  
  cout << "L\t\t" << "L\"C++\"\t\t\t" << L"C++" << "\t\t" 
    << typeid(L"C++").name() << "\t\t\t" << sizeof(L"C++") << endl;
  
  cout << "u8\t\t" << "u8\"C++\"\t\t\t" << u8"C++" << "\t\t\t" 
    << typeid(u8"C++").name() << "\t\t\t" << sizeof(u8"C++") << endl;
}
