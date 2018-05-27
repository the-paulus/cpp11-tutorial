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
|`Container container{ca,cb,cc};`, `Container container = { ca, cb, cc };`|List initialization.|
|`Container container(ia,ib);`|Creates a new container and copies the range of elements denoted by **ia** and **ib**, which are iterators. Note: This is not valid for `array`.|
|`Container container(n);`|Creates a new sequential container with *n* elements. **Not valid for `array`**|
|`Container container(n,v);`|Creates a new sequential container with *n* elements with *v* as their value. **Not valid for `array`**|

Containers being created from a copy of another, the element type can differ as long as they can be converted.

```
vector<string> first_names = { "Bob", "Ed", "Jo" };
list<const char*> last_names = { "Johnson", "Richards", "Kelly" };
vector<string> first_names2(first_names);
vector<string> names(first_names); // Containers don't match.
vector<string> names(last_names); // Element type doesn't match.
forward_list<string> names(first_names.begin(), last_names.begin()); // Converts const char* to string.
```