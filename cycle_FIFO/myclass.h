#ifndef TEST2_MYCLASS_H
#define TEST2_MYCLASS_H

#include <iostream>
using namespace std;

template<typename T>
class mylist;

//---------------mylist_node------------------------------
template<typename T>
class mylist_node
{
    friend class mylist<T>;

    T elem;
    mylist_node<T> *next;

    mylist_node(const T &t, mylist_node<T> *next) : elem(t), next(next)
    {
    }
    ~mylist_node() = default;
};

//-------------mylist----------------------------------------------
template<typename T>
class mylist
{
    mylist_node<T> *head, *tail;
    int count = 0;
    int buff_size = 0;

public:

    mylist(int b_size) : buff_size(b_size), head(nullptr), tail(nullptr)
    {
    }

    ~mylist()
    {
        delete head;
    }

    void push(const T &elem);

    void pop();

    int size_();

    void clear();

    typedef std::ptrdiff_t difference_type;

    T &operator[](difference_type n)
    {
        auto tmp = head;
        for (int i = 0; i != n; ++i) {
            tmp = tmp->next;
        }
        return tmp->elem;
    }
};

//---------------------push----------------------------
template<typename T>
void
mylist<T>::push(const T &elem)
{
    auto *node = new mylist_node<T>(elem, nullptr);

    if (head == nullptr) {
        head = tail = node;
        count++;
    } else if (count < buff_size) {
        node->next = head;
        tail->next = node;
        tail = node;
        count++;
    } else {
        mylist_node<T> *head_temp = head->next;

        node->next = head->next;
        tail->next = node;
        tail = node;
        head = head_temp;
    }
}

//--------------------pop--------------------------------
template<typename T>
void
mylist<T>::pop()
{
    if (head != nullptr) {
        cout << head->elem << '\n';

        head = head->next;
        count--;

    } else {
        head = nullptr;
    }
}

//------------------size---------------------------------
template<typename T>
int
mylist<T>::size_()
{
    return count;
}

//----------------clear----------------------------------
template<typename T>
void
mylist<T>::clear()
{
    mylist_node<T> *cur, *next;

    if (head != nullptr) {
        cur = head;
        while (--count) {
            next = cur->next;
            delete cur;
            cur = next;
            head = nullptr;
        }
    } else {
        head = nullptr;
    }
};

#endif //TEST2_MYCLASS_H
