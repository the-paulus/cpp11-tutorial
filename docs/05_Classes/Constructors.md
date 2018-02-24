# Constructors
The job of a constructor is to initialize the newly created object with data rather than having to call or set data 
members. A constructor is a function that doesn't have a return type nor can it be declared as const. It doesn't need 
to have any parameters just like a normal one. By default, when a class is defined without explicitly naming a 
constructor, the compiler will add a **default constructor** that takes no arguments. The compiler-generated constructor 
is called a **synthesized default constructor**. The following class definition has a synthesized default constructor 
assigned to it.

```
struct Sale {
    Sale() = default;
    Sale(istream &is);
    double total() const;
    void addProduct(Product *p);
    void removeProduct(Product *p);
    string printDate() const;
    string customer = string();
    time_t date = time(0);
    Product *products = nullptr;
};
```

It's important to know that if there are any constructors defined, then the compiler will not define a synthesized 
default constructor.

When dealing with objects of built-in or compound types are undefined and must either be default initialized or asigned 
a value right off the bat.

Classes that have members of a class type may not have a default constructor. Therefore the compiler cannot initialize 
that member. In that instance, a constructor must be defined.  

## Default Constructor
When creating constructors and the default constructor does the same thing as a synthesized default constructor then it 
can be defined as `Sale() = default`. In order to use the `= default` all data members with a built-in type must be 
initialized.

The default constructor is used whenever an object is default or value initialized. Default initialization happens when

- objects are defined as non`static` at block scope without initializers. 
- a class itself has data members of class type using the sythesized default constructor.
- members of a class type are not explicitly initialized in a constructor initializer list.

Value initialization happens when

- arrays are initialized with fewer elements than the size of the array.
- local static objects are defined without an initializer.
- value initialization is explicitly requested by writing an expression in the form of `T()` -- where *T* is the type, 
e.g., `Vector();`

Class types defined using the `class` keyword at least has a synthesized constructor or one explicit constructor. 
`struct` classes must have a constructor explicitly defined because one cannot be synthesized for them.

```
class Product {
public:
    Product(string &identifier, string &name, string &description, double price);
    // ...
};

struct LineItem {
    Product product; // Default synthesized constructor is used.
    // ...
};

LineItem item; // Error: No constructor was synthesized or explicitly defined.

struct Customer {
    Customer() {}; // Error: no initializer for first and last names.
    string first_name;
    string last_name;
};
```

## Constructor Initializer Lists
Creating constructors that's only job is to initialize data members can be done using in-class initializers. That is
providing that the compiler being used supports it. 

```
Product(const string &pn) : name(pn) {}
Product(const string &pn, const string &d) : name(pn), description(d) {}
Product(const string &pn, const string &d, const string &i) : name(pn), description(d), identifier(i) {}
Product(const string &pn, const string &d, const string &i, unsigned int q) : name(pn), description(d), identifier(i), qty(q) {}
Product(const string &pn, const string &d, const string &i, unsigned int q, double p) : name(pn), description(d), identifier(i), qty(q), price(p) {}
``` 

The list of initializers sits between the semicolon and opening curly bracket. Each data member is is assigned the 
value of the object within its corresponding parenthesies. For example, the `Product(const string &pn) : name(pn) {}` 
constructor assigns the value of `pn` to the `name` data member. This equivolent to:

```
struct Product {
    Product(const string &pn);
    // ...
}

Product::Product(const string &pn) {
    name = pn;
}
```  

In the first constructor declaration, you will notice that there is no initializer list. It isn't that there is not one, 
but that the initializer list is empty. Members that do not appear in the constructor initializer list are initialized 
by the corresponding in-class initializer, providing there is one, or default initialized. 

## When Initialization is Required
Most of the time initialization is not required but it is required when there are data members that are `const` or
references. Example:

```
Class Screen {
public: 
    // This will not work
    Screen(video_card_t video_card, WindowManager &window_manager) { this->video_card = video_card; this->window_manager = window_manager; };
    // This will
    Screen(video_card_t video_card, WindowManager &window_manager) : video_card(video_card), window_manager(window_manager) {};
private: 
    WindowManager &window_manager;
    const video_card_t video_card;
}
``` 

Since `const`s and references need to be initialized, the first `Screen` constructor will not work because by the time the 
body of the function begins executing, the initialization phase is complete.

## Member Initialization Order
When initializing data members, the order in which those objects are initialized are not the order they appear in the 
initialization list. For the most part, the order in which data members are initialized doesn't matter but if one 
depends on another then the definition order of the class data members becomes critical.

```
Class Screen {
public: 
    Screen(video_card_t video_card, WindowManager &window_manager) : video_card(video_card), window_manager(window_manager) {};
private: 
    WindowManager &window_manager;
    position_t position;
    const video_card_t video_card;
    dimensions_t dimensions;
}
```
Although the order of the data members in the initialization list is video_card followed by window_manager, window_manager 
gets initialized first because of the order in they are defined within the class.

## Default Arguments
Constructors can have some or all of its parameters be assigned default values.

```
class Window {
public:
    // ...
    Window(position_t position, string content = "") : position(position), content(content) {};
    // ...
};
``` 

## Delegating Constructors
In C++11, the ability to use **delegating constructors** is available. When using **delegating constructors** the 
initialization list is reduced to a single entry.

```
class Window {
public:
    // Nondelegating constructor -- one that initializes all data members.
    Window(position_t position, dimensions_t dimensions, string content) : position(position), dimensions(dimensions), content(content) {};
    // Delegating constructors
    Window(position_t position) : Window(position, WindowManager::default_dimensions, "") {};
    Window(position_t position, dimensions_t dimensions) : Window(position, dimensions, "") {};
```