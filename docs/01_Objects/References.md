# References
References are aliases of another object and do not have an address. The limitations of a reference are as follows: 
- They must be initialized with an object and when they are created which means they cannot reference a `const`.
    ```
    int val = 10;
    int &rval = val;
    int &rval2 = 20; // Error
    ``` 
- Once a reference is initialized to an object, it cannot be changed to refer to another object.
    ```
    int val = 10;
    int val2 = 20;
    int &rval = val;
    rval = val2; // Error
    ```
- The type of the object must match the type of the reference.
    ```
    double val = 1.0;
    int &rval = val; // Error 
    ```
- You cannot reference a reference.
    ```
    int val = 10;
    int &rval = val;
    int &rval2 = rval; // Error
    ```
- Cannot have arrays of references.
- Since references have no address, you cannot point to a reference.
    ```
    int val = 10;
    int &rval = val;
    int *pval = rval; // Error
    ```