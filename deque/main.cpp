#include <iostream>
#include "deque.h"
#include "deque.cpp"
using namespace std;

int main() {
      deque<int> d1;
      deque<int>::iterator it1;

      for(int i=1;i<6;i++)
      {
        d1.push_front(i);
      }
//    for(int i=1;i<6;i++)
//    {
//        d1.push_front(i);
//    }
//    d1.push_back(5);
//    d1.push_back(7);
//    d1.push_front(4);
//   d1.push_front(3);
//    d1.push_back(9);
//    d1.erase(1);
//    d1.erase(1);
//    d1.erase(3);
//    d1.erase(4);
//    d1.erase(5);

//    d1.push_front("wassup");
//    d1.insert(55, 2);
//     d1.swap(9, 2);



//    cout << d1.get_elem_val(0) << "\n";
//    cout << d1.size() << "\n";

    for(it1=d1.begin();it1 != d1.end();it1++)
       cout  << *it1;// <<endl;

//d1.clear();

//    for(it1=d1.begin();it1 != d1.end();it1++)
//        cout  << *it1;// <<endl;
    return 0;
}