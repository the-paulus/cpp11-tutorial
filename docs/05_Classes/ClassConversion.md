# Class Conversion

## Implicit Class-Type Conversion
C++ defines several automatic conversion for built-in types. When a constructor that has a single argument defined is 
called, an implicit conversion to that class takes place. 

```
class Window {
public:
    Window(string content) : content(content) {};
    // ...
private:
    string content;
    // ...
};

// Converts a string into a Window class object type.
Window w = Window("New window.");
``` 

In the event that implicit conversion should not happen, the constructor can be declared as `explicit` for 
direct initialization.

```
class Window {
public:
    // The explicit keyword is only used once, during declaration.
    explicit Window(string &content);
    // ...
private:
    string content;
    // ...
};

Window::Window(string content) {
    this->content = &content;
}

Window new_window("New window."); // Direct intialization
Window new_window2 = "Another new window!"; // No longer possible after declaring Window(string &content) explicit.
```

Although `explicit` constructors cannot be used for implicit conversion, it is still possible to use them to 
explicitly perform a conversion. This can be done by either direct initialization or by using `static_cast<T>()`. 