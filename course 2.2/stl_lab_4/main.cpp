#include <iostream>
#include <vector>
#include <list>
#include "fact.cpp"
using namespace std;

int main() {
    mylist<int> list;

    std::vector<int> vec{0, 0, 0, 0, 0};
    std::vector<int>::iterator it_v;
    it_v = vec.begin();

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    mylist<int>::iterator it = list.begin();
    mylist<int>::iterator it2 = list.end();

    list.factorial(it, it2);

    std::copy(it, it2, it_v);

    for (int x : vec) {
        cout << x << " ";
    }
    return 0;
}