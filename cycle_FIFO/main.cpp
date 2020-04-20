#include <iostream>
#include "myclass.h"

using namespace std;
bool
even(int i)
{
    return (i & 1) != 0;
}


int main() {

    mylist<int> a(5);

    a.push(5);
    a.push(6);
    a.push(7);
    a.push(8);
    a.push(9);

    for (int i = 0; i < a.size_(); ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';

    a.push(1);
    a.push(2);
    a.push(3);
//    a.push(4);
    a.push(5);

    for (int i = 0; i < a.size_(); ++i) {
        cout << a[i] << " ";
    }
    cout << '\n';

    auto b = even(4);
    cout << b;
/*    a.clear();

    for (int i = 0; i < a.size_(); ++i) {
        cout << a[i] << " ";
    }

    cout << '\n';*/


    return 0;
}