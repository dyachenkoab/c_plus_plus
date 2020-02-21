#include <iostream>
#include "deque.h"

//#include "deque.h"

template<class T>
deque<T>::~deque()
{
    _Node *cur, *next;				//деструктор
    if(_Beg!= nullptr)
    {
        cur=_Beg;
        while(cur!= nullptr)
        { next=cur->_Next;  delete cur; cur=next; }
    }
}

template<class T>
void deque<T>::push_back(const T &data)
{
    _Node *nd=new _Node(data);
    if(nd== nullptr)
        return;
    if(_Beg== nullptr)
    { _Beg=_End=nd; }
    else
    { nd->_Prev=_End; _End->_Next=nd; _End=nd;}
    count++;
}

template<class T>
void deque<T>::push_front(const T &data)
{
    _Node *nd = new _Node(data);
    if (nd == nullptr)
        return;
    else
    { nd->_Next = _Beg; nd->_Prev = 0; _Beg = nd; }
    count++;
}


template<class T>
void deque<T>::erase(const int n)
{
    _Node *temp = _Beg;
    if (n  > count) { cout << "неверные параметры" << endl; }
        else if (!n) { cout << "неверные параметры" << endl; }
            else if (n==1)
              {  _Beg = _Beg->_Next;
                  if (_Beg != NULL)
                  {
                  _Beg->_Prev = NULL;
                  }
              }
             else
             {
             for (int i = 1; i < n-1; i++) { temp = temp->_Next; }
             if (temp == _Beg) { _Beg = temp->_Next; }
             temp->_Next=temp->_Next->_Next;
             count--;
             }
 }


template<class T>
void deque<T>::insert(const T &data,const int n)
{   if (n == 1 || _End == nullptr) { push_front(data); }
    else
    {
    _Node *hlp = _Beg;
    for (int i = 1;i!=n-1;i++)
    { hlp = hlp->_Next; }

    _Node *tmp = new _Node(data);
    tmp->_Next=hlp->_Next;
    hlp->_Next=tmp;
    count++;
    }
}

template<class T>
void deque<T>::swap(int a, int b)
{
     if (a==b) {cout << "значения равны" << endl;}
        else if ((a  > count) || (b > count)) { cout << "неверные параметры" << endl; }
            else if (!a || !b) {cout << "неверные параметры" << endl;}
                else
                {
                _Node *tmp = new _Node;
                tmp->_Value = get_elem_val(a);
                get_elem_val(a) = get_elem_val(b);
                get_elem_val(b) = tmp->_Value;
                delete tmp;
                }
}

template<class T>
T& deque<T>::get_elem_val(int a)

    { _Node *p = _Beg;
    if ((a > count) || (a <= 0)) { return p->_Value; }
       else
       {
        for (int i = 0;i!=a-1;i++)
        {  p = p->_Next;  }
        return p->_Value;
       }
    }

template<class T> void deque<T>::clear()
    {
        for (int i = count; i != 0; --i)
        {
           erase(i);
        }

    }

template<class T>
size_t deque<T>::size() {
   return count;
}
