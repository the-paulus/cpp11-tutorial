#include <iostream>
#include <forward_list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{

    /* When adding or removing elements in a forward_list, two iterators needs to be kept an eye on.
     *
     */

    forward_list<int> flist = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto prev = flist.before_begin();
    auto current = flist.begin();

    while( current != flist.end() )
    {
        if( *current % 2 )
        {
            current = flist.erase_after(prev);
        } else {
            prev = current;
            current++;
        }
    }
}