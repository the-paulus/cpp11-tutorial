#include <iostream>

#define num_elements(arr) ((char*)(&arr+1) - (char*)(&arr))

using std::cout;
using std::endl;

int main(int argc, char **argv) {

    const int size = 5;

    /*
     * Simple single dimension integer array containing 5 elements.
     * When using a value to specify the size, the object must be
     * a constant.
     */
    int iarr[size] = { 1, 2, 3, 4, 5 };

    /*
     * When initializing the array, the number used to specify how many
     * elements are in the array can be omitted. iarr2 is a an integer
     * array containing three elements.
     */
    int iarr2[] = {1, 2, 3 };

    /*
     * When defining the size of the array and not initializing all elements
     * the remaining elements will be default initialized. In this case, the
     * other three array elements will be set to 0.
     */
    int iarr3[5] = { 1, 3 };

    /*
     * Character arrays are a special case. String literals end with a null character
     * which is automatically copied when using a list initializer or string literal.
     *
     * carr1 is initialized using list initialization and automatically has a null
     * character added as the last element in the array.
     *
     * carr2 is defined the same as carr1 but with an explicit null character.
     *
     * carr3 is initialized using a string literal and like the previous two objects
     * have a null character appended.
     *
     * Assigning a string literal to an array with a predefined number of elements will
     * produce an error.
     */
    char carr1[] = { 'C', '+', '+' };
    char carr2[] = { 'C', '+', '+', '\0' };
    char carr3[] = "C++";
    //char carr4[3] = "C++";

    /*
     * Arrays can not be initialized or assigned by another array.
     */
    // char carr5[] = carr1
    // carr6 = carr1

    /*
     * Multidimensional integer array containing a total of 15 elements (3*15)
     */
    int imarr[3][5] = {
            { 1, 2, 3, 4, 5 },
            { 6, 7, 8, 9, 10 },
            { 11, 12, 13, 14, 15 }
    };

    cout << "Getting the size of an array:" << endl;
    cout << "sizeof(iarr) = " << sizeof(iarr) << " = 5 * " << sizeof(int) << endl;
    cout << "sizeof(iarr) / sizeof(int) = " << sizeof(iarr) / sizeof(int) << " = " << sizeof(iarr) << " / " << sizeof(int) << endl;

    /*
     * Another way of getting the number of elements in an array is using pointers.
     */
    cout << "*(&iarr2 + 1) - iarr2 " << *(&iarr2 + 1) - iarr2 << endl;

    cout << "MACRO: " << num_elements(iarr) << endl;

    cout << "Printing the array variable as a whole will print the object's address." << endl;
    cout << iarr << endl;

    cout << "To access array elements: iarr[2] = " << iarr[2] << endl;

    cout << "Printing all elements of a multidimensional array: " << endl;
    for(int i = 0; i < 3; i++) {
        cout << "Element (" << i << "): ";
        for(int j = 0; j < 5; j++) {
            cout << " " << imarr[i][j] << " ";
        }
        cout << endl;
    }

    /*
     * Arrays can hold objects of almost any type, including pointers and references.
     *
     * Array of 5 pointers to integers.
     */
    int *ptr_arr1[size];

    /*
     * Since references don't have addresses, it is not possible to create an array of
     * references:
     *
     * int &ref_arr1[10] = ... No arrays of references.
     */

    /*
     * Points to an array of 5 integers.
     */
    int (*ptr_arr2)[size] = &iarr;

    /*
     * Refers to an array of 5 integers.
     */
    int (&ref_arr1)[size] = iarr;

    /*
     * ptr_arr3 is a reference to an array of five pointers that point to an integer.
     */
    int *(&ptr_arr3)[size] = ptr_arr1;

    /*
     * Pointers and arrays are closely intertwined where operations on an array
     * are operations on a pointer.
     *
     * pc1 points to the first element of carr2.
     */
    char *pc1 = &carr2[0];
    cout << "*pc1 = &carr2[0]: " << *pc1 << " = " << &carr2[0] << endl;

    /*
     * When arrays are used, the compiler automatically substitutes a pointer to the
     * first element.
     */
    char *pc2 = carr2;
    cout << "*pc2 = carr2: " << *pc2 << " = " << carr2 << endl;

    /*
     * iarr4 points to the first element in iarr Which is the equivalent of:
     * auto iarr4(iarr[0])
     */
     auto iarr4(iarr);
}