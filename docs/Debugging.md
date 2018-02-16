# Debugging

## assert Preprocessor Macro
Defined in the *cassert* header, the assert preprocessor macro acts similar to an inline function and is used to check 
for conditions that *"cannot happen"* f

```c
#include <cassert>
#include <iostream>

#define 

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    const int MAX_SIZE = 12;
    string my_string;
    
    cout << "Enter a string: ";
    cin >> my_string;
    
    assert( my_string.size() > MAX_SIZE);
    
    cout << endl; << "Your string: " << my_string << endl;
    
    return 0;
}
```

The `assert` macro depends on whether or not the `NDEBUG` preprocessor variable is defined, which it is not by default.