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
  
  /*
   * Type		    Meaning			    Guaranteed Size in bits
   * ==========================================================
   * bool		    boolean			    1
   * char		    character		    8
   * wchar_t		wide character		16
   * char16_t		unicode character	16
   * char32_t		unicode character	32
   * short		    short integer		16
   * integer		integer			    16
   * long		    long integer		32
   * long long		long integer		64
   * float		    single-precesion	6 significant digits.
   * double		    double-precision	10
   * long double	extended precision	10
   * 
   * Any of the built-in data types may have a type modifier of either signed
   * or unsigned. Objects defined as signed are allowed to have a negative or
   * positive value that is half the maximum value that can be assigned. For
   * example, an unsigned char is 8 bits which can hold a value of 0-255.
   * If the signed modifier is used a char can only have a value between -127
   * and 127 or -127 and 128 depending on whether ones' compliment or twos'
   * complement is used, respectively. Depending on the compiler and
   * architecture, omitting the signed or unsigned type modifier will define 
   * the object as is allowed or specified by default. In the instance of char
   * the default modifier is unsigned.
   * 
   * In ones' complement, given an 8 bit char, the left most bit,
   * 128, is used to invert all other bits before it to achieve a negative
   * number:
   * 
   * signed char c = -127 in binary form is '1000 0000'
   * signed char c = 0 in binary form is '1111 1111'
   * signed char c = 127 in binary form is '0111 1111'
   * 
   * Since the 8th bit (128) is used for inverting all other bits, it is not
   * possible to have +/-128.
   * 
   * With twos complement, the left most bit is still used but instead of
   * inverting the bits before it, the value of the left most bit is subtracted
   * from the sum of all previous bits.
   * 
   * signed char c = -128 in binary form is '1000 0000'
   * signed char c = 0 in binary form is '0000 0000'
   * signed char c = 127 in binary form is '0111 1111'
   * 
   * To get the value -2, which is represented as '1111 1110' in binary
   * we add the values of the bits turned on. In this case they are 2, 4, 8, 
   * 16, 32, and 64 but exclude 128 because this is the value that we're 
   * subtracting:
   *
   * (2 + 4 + 8 + 16 + 32 + 64) - 128 = -2
   * 
   * Because the left most bit is no longer reserved exclusively for reversal of
   * previous bits, the value of that location is now available but only for 
   * negative values. Twos' complement is widely implemented because arithmetic
   * operations are identical for both signed and unsigned values.
   */
  
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
  
  /*
   * Variable Type Guidelines
   * ========================
   * - Always use the unsigned type modifier if the value cannot be negative.
   * - Use the same type when doing arthmetic.
   * - Depending on the architecture, int and long are the same length.
   * - When dealing with large numbers use long long.
   * - Don't use char or bool in arithmetic expressions.
   * - Char can be either signed or unsigned depending on the archeticure.
   * - The decision to use a float or double depends on the application. Only use
   *   as much precision as you need as well as the right algorithm.
   */
  
  /*
   * Literals are values that are hard-coded into the program and can be
   * any of the built-in types: int, long, short, double, float, char, wchar_t, 
   * char16_t, or char32_t. Using a numeric literal and string literal differ
   * slightly in that numeric literals use a suffix to represent their type 
   * while string literals use a prefix to represent their type.
   */
  
  cout << "==================" << endl;
  cout << "Numeric Literals" << endl;
  cout << "==================" << endl;
  
  /*
   * Numeric literal types are expressed using an upper or lower 'l', 'll', or 
   * 'f'. Since object names cannot begin with a number, using a specified 
   * prefix allows us to specify the literal type using the mentioned 
   * characters. 
   */
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
    
  /*
   * 0 may be used as a prefix on a decimal value to tell the compiler 
   * how it should be interpreted. 
   */
  cout << "Prefix\t\t" << "Type\t\t\t" << "Example\t\t\t" << "Value" << endl;
  cout << "(none)\t\t" << "Decimal\t\t\t" << "10\t\t\t" << 10 << endl;
  cout << "0\t\t" << "Octal\t\t\t" << "077\t\t\t" << 077 << endl;
  cout << "0x\t\t" << "Hexidecimal\t\t" << "0xFF\t\t\t" << 0xFF << endl;
  cout << "0b\t\t" << "Binary\t\t\t" << "0b1110\t\t\t" << 0b1110 << endl;
  cout << endl << endl;
  
  cout << "==================" << endl;
  cout << "String Literals" << endl;
  cout << "==================" << endl;
  
  /*
   * String literal types are prefixed with either an upper or lower case u, L,
   * or 'u8'. String literal type ids vary depending on the value of the string.
   * The type ID is prefixed with an 'A{n}_', where n is the size of the string 
   * that includes the null terminator character.
   */
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
