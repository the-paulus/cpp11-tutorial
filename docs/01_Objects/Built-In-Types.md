# Built In Types

Any of the built-in data types may have a type modifier of either signed
or unsigned. Objects defined as signed are allowed to have a negative or
positive value that is half the maximum value that can be assigned. For
example, an unsigned char is 8 bits which can hold a value of 0-255.
If the signed modifier is used a char can only have a value between -127
and 127 or -127 and 128 depending on whether ones' compliment or twos'
complement is used, respectively. Depending on the compiler and
architecture, omitting the signed or unsigned type modifier will define 
the object as is allowed or specified by default. In the instance of char
the default modifier is unsigned.
 
In ones' complement, given an 8 bit char, the left most bit,
128, is used to invert all other bits before it to achieve a negative
number:

``` 
signed char c = -127; // is '1000 0000' in binary form
signed char c = 0; //is '1111 1111' in binary form 
signed char c = 127; //is '0111 1111' in binary form 
``` 

Since the 8th bit (128) is used for inverting all other bits, it is not
possible to have +/-128.
 
With twos complement, the left most bit is still used but instead of
inverting the bits before it, the value of the left most bit is subtracted
from the sum of all previous bits.

``` 
signed char c = -128; //is '1000 0000' in binary form 
signed char c = 0; //is '0000 0000' in binary form
signed char c = 127; //is '0111 1111' in binary form 
```
 
To get the value -2, which is represented as '1111 1110' in binary
we add the values of the bits turned on. In this case they are 2, 4, 8, 
16, 32, and 64 but exclude 128 because this is the value that we're 
subtracting:

```
(2 + 4 + 8 + 16 + 32 + 64) - 128 = -2
``` 

Because the left most bit is no longer reserved exclusively for reversal of
previous bits, the value of that location is now available but only for 
negative values. Twos' complement is widely implemented because arithmetic
operations are identical for both signed and unsigned values.

|Type|Meaning|Guaranteed Size in bits|
|:---:|:---:|:---:|
|bool|boolean|1|
|char|character|8|
|wchar_t|wide character|16|
|char16_t|unicode character|16|
|char32_t|unicode character|32|
|short|short integer|16|
|integer|integer|16|
|long|long integer|32|
|long long|long integer|64|
|float|single-precesion|6 significant digits|
|double|double-precision|10|
|long double|extended precision|10|

## Variable Type Guidelines
- Always use the unsigned type modifier if the value cannot be negative.
- Use the same type when doing arthmetic.
- Depending on the architecture, int and long are the same length.
- When dealing with large numbers use long long.
- Don't use char or bool in arithmetic expressions.
- Char can be either signed or unsigned depending on the archeticure.
- The decision to use a float or double depends on the application. Only use as much precision as you need as well as 
the right algorithm.

## Literals
Literals are values that are hard-coded into the program and can be
any of the built-in types: `int`, `long`, `short`, `double`, `float`, `char`, `wchar_t`, 
`char16_t`, or `char32_t`. Using a numeric literal and string literal differ
slightly in that numeric literals use a suffix to represent their type 
while string literals use a prefix to represent their type.

### Numeric Literals
Numeric literal types are expressed using an upper or lower `l`, `ll`, or 
`f`. Since object names cannot begin with a number, using a specified 
prefix allows us to specify the literal type using the mentioned 
characters. 

|Suffix          |Example|                 Value|                   Type|                    Size|
|:---:|:---:|:---:|:---:|:---:|
|l/L|             102401l/102401L|         102401/102401|           Long Integer|            8
|ll/LL|           102401ll/102401LL|       102401/102401|           Long Long Integer|       8
|f/F|             1.2401f/1.2401F|         1.2401/1.2401|           Single-percision|        4
|l/L|             1.2401l/1.2401L|         1.2401/1.2401|           Long Double|             16

0 may be used as a prefix on a decimal value to tell the compiler how it should be interpreted.

|Prefix|          Type|                    Example|                 Value|
|:---:|:---:|:---:|:---:|
|(none)|          Decimal|                 10|                      10|
|0|               Octal|                   077|                     63|
|0x|              Hexidecimal|             0xFF|                    255|
|0b|              Binary|                  0b1110|                  14|

### String Literals
String literal types are prefixed with either an upper or lower case `u`, `L`,
or `u8`. String literal type ids vary depending on the value of the string.
The type ID is prefixed with an `A{n}_`, where n is the size of the string 
that includes the null terminator character.

|Prefix|          Example|                 Value|                   Type|                    Size|
|:---:|:---:|:---:|:---:|:---:|
|u|               u"C++"|                  0x40cd8a|                A4_Ds|                   8|
|U|               U"C++"|                  0x40cda4|                A4_Di|                   16|
|L|               L"C++"|                  0x40cda4|                A4_w|                    16|
|u8|              u8"C++"|                 C++|                     A4_c|                    4|