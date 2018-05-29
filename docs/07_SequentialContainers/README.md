# Sequential Containers

Objects that hold a collection of other objects of a specific type are called a **container**. *Sequential containers* 
allow a developer to control the order in which the elements are stored and retrieved. The order in which the objects
are stored within a sequential container is determined by when those objects were put into said container. 

There are several containers and each type provides different performance trade-offs. Each of the containers are 
defined in the header of the same name. To be able to store almost any type of object, they are defined as **class 
templates**. Even though almost any type can be stored within a container, some of these impose requirements of their 
own. These requirements are not the end all and containers can be defined for a type that doesn't support 
operation-specific requirements as long as those operations are not utilized.

|Type|Description|
|:---|:---|
|`vector`|Fexible-size with fast random access. Prepending and appending is fast but insertions are not.|
|`deque`|Double-ended queue supports fast random access with fast inserts and deletes at the front or back.|
|`list`|Doubly linked list that supports only bidirectional sequential access that results in fast inserts and delete at any point in the list.|
|`forward_list`|Singly link list that supports only sequential access in one direction with fast insert and deletes at any point in the list. Intended to be a reusable solution for linked lists. Does not have the size operation because of too much overhead. Added in C++11.|
|`array`|Fixed-size array that support fast random access but cannot add or remove elements as they have a fixed size. This container is easier and safer-to-use alternative to built-in arrays. Added in C++11.|
|`string`|Is a specialized container that is similar to a vector type, but only contains characters. Access to characters is fast and so is insertion and deletion of characters as long as they are at the front or back.|

Of all the types listed in the table above, the only type that is a fixed-size container is `array`. Containers such as 
`string`s and `vector`s store their data contiguously and are quicker to compute the address of an element from its index.
The cost of that calculation speed comes at the price of slower speeds and memory overhead when inserting or removing 
elements in the middle.

`list` and `forward_list` containers are designed to make adding and removing elements anywhere in the container quick 
in exchange for random access. The only way to access an element in a `list` or `forward_list` is to iterate through 
the entire container until the element is found.

## When to use What
- Generally, `vector`s are a safe bet unless you need modifications somewhere in the middle to be fast, for example.
- Don't use `list` or `forward_list` if the program has a lot of small elements and space overhead matters.
- For accessing random elements, use `deque` or `vector`.
- Quick modifications in the middle, use `list` or `forward_list`.
- If you can get away with modifying just the head or tail of a container and need fast random access to elements, use 
`deque`.
- For instances where you need to insert elements somewhere in the body during input and require random access:
    - Use a `vector` by adding it to the end and sorting the elements.
    - If the inserted element must maintain a specific position, use `list` for input and copy it to a `vector`.
    
If the program needs both random access and the ability to modify the body, then determine what the program will do 
more of. If it is going to do more random access, `vector` or `deque` would be the way to go. If there will be more 
modifications somewhere in the body of the container, then `list` or `forward_list` would be the solution.

In the event that you're not sure which container to use, writing the code using iterators and avoiding random access 
to elements will allow the type of container to be easily changed. 
    

## Container Operations
|Type Aliases||
|:---|:---|
|`iterator`|Iterator type for the container|
|`const_iterator`|Read-only iterator|
|`size_type`|Unsigned int type, big enough to hold the largest possible container of the type.|
|`difference_type`|Signed integral type that is big enough to hold the distance between two iterators.|
|`value_type`|Element type|
|`refernce`|Element's lvalue type which is a synonym for `value_type&`|
|`const_reference`|Element's const lvalue type.|

|Construction||
|:---|:---|
|`Container container;`|Default container constructor. Creates an empty container object.|
|`Container container1(container2);`|Creates a new container and copies container2 into container1.|
|`Container container(ia,ib);`|Creates a new container and copies the range of elements denoted by **ia** and **ib**, which are iterators. Note: This is not valid for `array`.|
|`Container container{ca,cb,cc};`|List initialization.|

|Assignment and swap||
|:---|:---|
|`container1 = container2;`|Assign c2 to c1.|
|`container = {ca,cb,cc};`|Assign elements of ca, cb, and cc to c1. This does not work for `array`.|
|`container.assign(ib,ie);`, `container.assign(initializer_list);`, `container.assign(n,v);`|Assigns the values in iterators ib, ie to container. Assigns the values in initializer_list to container. Replaces elements in container with *n* elements with value *v*.|
|`ca.swap(cb);`|Swap the elements in ca with cb.|
|`swap(ca,cb);`|Same as above.|

|Size||
|:---|:---|
|`container.size();`|Retrieves the number of elements in the container. This is not valid for `forward_list`|
|`container.max_size();`|Returns the maximum number of elements the container can hold.|
|`container.empty();`|Whether or not the container is empty.|

|Add/Remove Elements (not valid for `array`)||
|:---|:---|
|`container.insert(args);`|Copies the element(s), **args** into container.|
|`container.emplace(inits);`|Use *inits* to construct an element in container.|
|`container.erase(args);`|Remove the element(s) specified by **args**|
|`container.clear();`|Remove all the elements in the container and return void.|

|Equality and Relational Operators||
|:---|:---|
|`==`, `!=`|Valid for all container types.|
|`<`, `<=`, `>`, `>=`|Relationals, not valid for unordered associative containers.|

|Obtain Iterators||
|:---|:---|
|`container.begin();`, `container.end();`|Returns the iterator to the first element, one past the last element in the container.|
|`container.cbegin();`, `container.cend();`|Same as above, but returns a `const_iterator`.|

**Iterator Ranges** are denoted by a pair of iterators that refers to an element or one past the last. `begin()` and 
`cbegin()` means the first element, up to but not including the last element. This is called **left-inclusive interval**
and it's mathmatical notation is is `[begin, end)`. **left-inclusive ranges** have three convient properties:
1. begin == end, the range is empty.
2. begin != end, there is at least one element in the range and begin refers to the first element in the range.
3. begin can be incremented until begin == end. 

The `end()` and `cend()` don't really refer to an actual element in the container as it returns one-past the last element. 
**end** may be equal to **begin** but never anything before it.

When working with **iterator ranges**, it's important to remember that the compiler cannot enforce that 
1. Iterators refer to elements of, or one past the end of the same container.
2. Iterators can go past the end of the container if it is incremented enough.

|Members of Reversible Containers (not valid for `forward_list`)||
|:---|:---|
|`reverse_iterator`|As the name suggests, iterates in reverse order.|
|`const_reverse_iterator`|The `const` version of `reverse_iterator`.|
|`container.rbegin();`, `container.rend();`|Returns an iterator to the last, and one past the first element in container.|
|`container.crbegin();`, `constiner.crend();`|Same as above, but `const`.|

Calling any of the begin or end members of a container will return an iterator with the same type as the container was
defined with. Any of the "non-c" methods are overloaded, which can be used for types that are `const` or non-`const`. 
Unless the program isn't going to modify the referenced element, it's safer to use the "non-c" version. 

```
vector<string> v = {"one", "two", "three"};
auto it     = v.begin();    // vector<string>::iterator    
auto rit    = v.rbegin();   // vector<string>::reverse_iterator
auto cit    = v.cbegin();   // vector<string>::const_iterator
auto crit   = v.crbegin();  // vector<string>::const_reverse_iterator
```


## Iterators
Iterators have a common interface which have the following standard operations:

|Operation|Description|
|:---|:---|
|`*iter`|References the element denoted by `iter`.|
|`iter->member`|Derefernces `iter` and fetches the member. This can also be accomplished by `(*iter).member`.|
|`++iter`, `--iter`|Moves the reference forward or backward, respectively. The latter is not available for `forward_list`.|
|`iter1 == iter2`, `iter1 != iter2`|Compares two iterators to see if they are equal or not, respectively.|

Arithmetic operations are only for `string`, `vector`, and `array`:

|Operation|Description|
|:---|:---|
|`iter + n`, `iter - n`|Moves the iterator forward or backward *n* elements.|
|`iter += n`, `iter -= n`|Compound assignment of the above.|
|`iter1 - iter2`|Subtracts two iterators, and when added to the right-hand iterator, equals the left-hand iterator.|
|`>`, `>=`, `<`, `<=`|Relational operators determine whether or not an element appears after, after or at the same location, before, before or at the same location as the other.|

All of the operations in the above table must be performed on iterators that denote elements in, or one past the end 
of the same container.

## Container Type Members
In the event that the type of element needs to be known when working with an iterator, this can be done by:
```
vector<string>::iterator iter;
vector<string>::difference_type diff;
```

## Library arrays Have Fixed Size
```
array<int, 42> arr_container1;
array<string, 10> arr_container2;
array<int, 10>::size_type i;
array<int>::size_type j;
```

- `array` is not defaulted to empty, the elements in the container is default initialized.
- `array` works the same as built-in arrays for initiation.
- Can assign or copy `array` unlike the built-in.

