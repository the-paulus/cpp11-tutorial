#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) 
{

  /*
   * Type		Meaning			Guaranteed Size in bits
   * ==========================================================
   * bool		boolean			1
   * char		character		8
   * wchar_t		wide character		16
   * char16_t		unicode character	16
   * char32_t		unicode character	32
   * short		short integer		16
   * integer		integer			16
   * long		long integer		32
   * long long		long integer		64
   * float		single-precesion	6 significant digits.
   * double		double-precision	10
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
  
  cout << "Type\t\tMeaning\t\t\t\tGuaranteed Size in bytes" << endl;
  cout << "bool\t\tboolean\t\t\t\t" << sizeof(bool) << endl;
  cout << "char\t\tcharacter\t\t\t" << sizeof(char) << endl;
  cout << "wchar_t\t\twide character\t\t\t" << sizeof(wchar_t) << endl;
  cout << "char16_t\tunicode character\t\t" << sizeof(char16_t) << endl;
  cout << "char32_t\tunicode character\t\t" << sizeof(char32_t) << endl;
  cout << "short\t\tshort\t\t\t\t" << sizeof(short) << endl;
  cout << "int\t\tinteger\t\t\t\t" << sizeof(int) << endl;
  cout << "long\t\tLong integer\t\t\t" << sizeof(long) << endl;
  cout << "long long\tLong integer\t\t\t" << sizeof(long long) << endl;
  cout << "float\t\tsingle-precision\t\t" << sizeof(float) << endl;
  cout << "double\t\tdouble-precision\t\t" << sizeof(double) << endl;
  cout << "long double\tLong double\t\t\t" << sizeof(long double) << endl;
  
  /*
   * Variable Type Guidelines
   * ========================
   * - Always use the unsigned type modifier if the value cannot be negative.
   * - Use the same type when doing arthmetic.
   * - Depending on the archeticure, int and long are the same length.
   * - When dealing with large numbers use long long.
   * - Don't use char or bool in arithmetic expressions.
   * - Char can be either signed or unsigned depending on the archeticure.
   * - The decision to use a float or double depends on the application. Only use
   *   as much precision as you need as well as the right algorithm.
   */
  
}