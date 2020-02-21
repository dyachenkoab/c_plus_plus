#ifndef LAB8_DEQUE_H
#define LAB8_DEQUE_H
#include <iostream>
//#include "deque.cpp"
using namespace std;

template<class T> class deque
{public:
    class iterator;
    friend class iterator;

private:
    struct _Node;
    friend struct _Node;
    int count = {0};
    _Node *_Beg, *_End;
    struct _Node
    {
        friend class iterator;
        _Node *_Next, *_Prev;
        T _Value;
        _Node(const T& Value){ _Prev=_Next= nullptr; _Value=Value; }
        _Node()= default;
    };
public:
    class iterator
    { _Node *p;
    public:
        iterator()			            { p= nullptr; }
        iterator(const deque<T> &lst)	{ p=lst._Beg; }	    //Если бы не &, то необходим бы был
       ~iterator()		            	{             }     //конструктор копирования
        T&  operator*()                 { return p->_Value; }
        bool operator!=(iterator it)	{ return p!=it.p; }
        iterator operator=(iterator it)	{ p=it.p; return *this; }
        iterator operator++()
        {
            if(p->_Next != nullptr)
                p = p->_Next;
            else p = nullptr;
            return *this;
        }
        iterator operator++(const int)
        {
            iterator tmp=*this;
            if(p->_Next!= nullptr)
                p = p -> _Next;
            else
                p = nullptr;
            return tmp;
        }
   };
///------------------------------------------------------------------------------------
    deque() { _Beg=_End= nullptr; }
   ~deque();
    void push_back(const T &data);
    void push_front(const T &data);
    void erase(const int n);
    void insert(const T &data,const int n);
    void swap(int a, int b);
    void clear();
    size_t size();
    T& get_elem_val(int a);
    T& Front()     { return _Beg->_Value; }
    T& Back()      { _Node *temp=_Beg;  while(temp->_Next!= nullptr)
                                        { temp=temp->_Next; }
                                        return temp->_Value; }
    iterator begin(){ return iterator(*this); }
    iterator end(){ return iterator(); }
};


#endif //LAB8_DEQUE_H
