#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv) {
    
    int ival = 0;
    
    /**************************
     * Simple statements
     **************************/
    ival = 5;
    cout << "Simple Statement demonstration: " << ival << endl;
    
    /**************************
     * Null Statement
     **************************/
    ;
    
    /*
     * Null statements are useful when the language requires a
     * statement but the logic does not. When utilizing null 
     * statements it may be obvious to you that nothing should be 
     * done. To someone else it may not be obvious.
     */
    
    string input;
    while(cin >> input)
        ; // Do nothing.
    
    /**************************
     * Compound / Block Statements
     **************************/
    
    /*
     * A block is also a scope created by using '{' and '}'
     * any names introduced within the scope are only accessible to 
     * that block and any nested blocks inside. 
     * 
     * For and while loops are two control statements take a single 
     * statement but we get around that by using compound statements.
     */
    
    // This will print 0-4 on a single line followed by a new line.
    for(ival = 0; ival < 5; ival++)
        cout << ival; // This is the only statement that will be looped.
        cout << endl;
    
    // This will print one number per line.
    for(ival = 0; ival < 5; ival++) {
        cout << ival;
        cout << endl;
    }

    /* 
     * It's not a requirement that compound statements be bound to control 
     * statements such as if, for, while, etc.
     */
    
    {
        cout << "Random compound statement." << endl;
    }
    
    /***********************
     * Statement scope
     ***********************/
    
    /*
     * Variables define within the control structure are only visible
     * within that scope. 
     */
    
    for(int i = 0; i < 5; i++) {
        cout << i << endl;
    }
    
    // cout << "'i' is: " << i << endl; // error: i does not exist in this scope. 
 
 
    /****************
     * Control statements
     ****************/
    
    for(int i = 0; i < 5; i++)
        cout << i << endl;
    
    ival = 0;
    while(ival < 5)
    {
        cout << ival << endl;
    return 0;
}
