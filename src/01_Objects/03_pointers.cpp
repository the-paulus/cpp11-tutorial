#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;

int main(int argc, char **argv) {
    
    /* 
     * First and foremost, initialize all pointers. Although initializing 
     * a pointer to 0 is acceptable the nullptr initialization method
     * is preferred and safest to use between architectures.
     * 
     * When 0 is used to initialize a pointer, you are initializing it to a null. 
     * Anything else that's not an address will result in a compiler error. 
     */
    
    int *ptr_null = nullptr; 
    int ival = 10;
    int tmp_val = 31;
    
    /* 
     * 'int *' is a compound type, which can only contain addresses of objects 
     * that are of type 'int'. Assigning objects of any other type will result
     * in an error. The '&' has multiple uses in C++ and the context
     * in which they are used will determine what will happen. In this case, 
     * prefixing an object with the '&' will return that object's memory address.
     */
    int *ptr_ival = &ival;
    
    cout << endl;
    cout << "Demonstrating pointers, addresses, and dereferencing." << endl;
    cout << "The current value of ival:            " << ival << endl;
    cout << "The address that is held in ptr_ival: " << ptr_ival << endl;
    cout << "The address of ival (&ival):          " << &ival << endl;
    
    /*
     * Using an astrix (*) before a variable, or lvalue will return the data
     * stored at the address assigned to the pointer. This is called dereferencing.
     */
    cout << "ptr_ival is dereferenced:             " << *ptr_ival << endl;
    cout << endl << endl;
    
    cout << "Demonstrating indirect object manipulation." << endl;
    cout << "Current value of ival:                " << ival << endl;
    
    /* 
     * Indirectly assigning ival a new value -- this can also be acheived by 
     * using references (see refernces.cpp). Before assigning a new value to the object at the
     * address held within the pointer, it must first be dereferenced. Since
     * pointers are objects just like ints, doubles, floats, etc., they 
     * cannot be used as an "alias". The assignment illistrated below will 
     * fail because 20 isn't an address. 
     * 
     * ptr_ival = 20; 
     * 
     * Dereferencing a pointer is telling the computer "Please fetch me this object 
     * held at this address because I want to assign it a new value." In other cases
     * you may just want the value held at the address within the pointer.
     */
    
    *ptr_ival = 20;     
    
    cout << "ival after *ptr_ival = 20:            " << ival << endl; 
    cout << "dereferencing ptr_ival:               " << *ptr_ival << endl;
    
    /*
     * We are creating a reference to the variable "ival". This is just another
     * way of writing *ptr_ival = &ival, which has the same effect as 
     * 
     * int &ref_ival = ival;
     *
     * In the statement below, we are dereferncing ptr_ival to retrieve the object
     * that we want to reference.
     */
    int &ref_ival = *ptr_ival;
    
    cout << "Value referenced by 'ref_ival':       " << ref_ival << endl;
    cout << "Address referenced by 'ref_ival':     " << &ref_ival << endl;
    
    /*
     * Changing the value of the object referenced with ref_ival to 31
     */
    ref_ival = 31;
    
    cout << "Value of ival after ref_ival = 31:    " << ival << endl;
    cout << endl << endl;
    
    /*
     * In the statement below we are creating a pointer to a pointer. Since 
     * the pointer is to another pointer, in order to retrieve the object 
     * that is ultimately being pointed to we must dereference twice (**).
     */
    int **ptr_ptr_ival = &ptr_ival;
    
    cout << "Demonstrating indirect access." << endl;
    cout << "**ptr_ptr_ival                         " << ptr_ptr_ival << endl;
    cout << "*ptr_ptr_ival:                         " << *ptr_ptr_ival << endl;
    cout << "&ptr_ival                              " << &ptr_ival << endl;
    cout << "Direct value of ival:                  " << ival << endl;
    cout << "Indirect value *ptr_ival:              " << *ptr_ival << endl;
    cout << "Indirect, indirect value **ptr_ptr_ival:" << **ptr_ptr_ival << endl;
    
    cout << endl << endl;
    
    /*
     * There is a special kind of pointer that holds only addresses. In the
     * statement below, we are assigning the address of the object ival to
     * the void pointer. Void pointers do not have a type and therefore cannot
     * be dereferenced. However, they can be cast to retrieve the value stored
     * at that address.
     */
    void *vptr_ival = &ival;
    int *ptr_vptr_ival = static_cast<int*>(vptr_ival);
    
    cout << "&ival:                                   " << &ival << endl;
    cout << "vptr_ival:                               " << vptr_ival << endl;
    cout << "static_cast<int>(vptr_ival):             " << *ptr_vptr_ival << endl;
    return 0;
}
