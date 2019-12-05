#include <iostream>
using namespace std;

template <class T> class Array
{
    T *a;                 // указатель на массив элементов
    int ind,size;
public:
    Array();
    Array(int Size);
    Array(const Array &Arr);
    ~Array();
    T& operator[](int n);
    void Add(const T &Value);
    void Erase(int n);
    void Clear();
    int Empty();
    Array& operator=(const Array<T> &Arr);
    int Size();
    void ReSize(int NewSize);
};
//----------------------------------
template<class T> Array<T>::Array()
{
    size=10;
    ind=0;
    a=new T[size];
}
//----------------------------------
template<class T> Array<T>::Array(int Size)
{
    size=Size;
    ind=0;
    if(Size==0)
        a=NULL;
    else
        a=new T[size];
}
//----------------------------------
template<class T> Array<T>::Array(const Array<T> &Arr)
{
    ind=Arr.ind;
    a=new T[size=Arr.size];
    for(int i=0; i<ind; i++)
        a[i] = Arr.a[i];
}
//----------------------------------
template<class T> Array<T>::~Array()
{
    delete[] a;
}
//----------------------------------
template<class T> int Array<T>::Size()
{
    return ind;
}
//----------------------------------
template<class T> T & Array<T>::operator [] (int n)
{
    if(n>=ind||n<0)
    {
        printf("Bad value of index!");
        exit(0);
    }
    return a[n];
}
//----------------------------------
template<class T> Array<T> & Array<T>::operator = (const Array<T>& Arr)
{
    delete[] a;
    a=new T[size=Arr.size];
    ind=Arr.ind;
    for(int i=0; i<ind; i++)
        a[i]=Arr.a[i];
    return *this;

}
//----------------------------------
template<class T> void Array<T>::ReSize(int NewSize)
{
    T *tmp;
    tmp=new T[NewSize];
    for(int i=0; i<NewSize && i<ind; i++)
        tmp[i]=a[i];
    delete[] a;
    a=tmp;
    size=NewSize;
    if(ind>=NewSize)
        ind=NewSize;
}
//----------------------------------
template<class T> void Array<T>::Add(const T &Value)
{
    if(ind>=size)
        ReSize(size+1);
    a[ind++] = Value;
}
//----------------------------------
template<class T> void Array<T>::Erase(int n)
{
    if(n<0||n>=ind)
        return;
    for(int i=n;i<ind-1;i++)
        a[i]=a[i+1];
    ind--;
}
//----------------------------------
template<class T> void Array<T>::Clear()
{
    ind=0;
}
//----------------------------------
template<class T> int Array<T>::Empty()
{
    return !ind;
}
//----------------------------------
int IsRazd(char sym, const char *razd)
{
    for(int i=0;razd[i];i++)
        if(razd[i]==sym)
            return 1;
    return 0;
}

//Аналог стандартной функции strtok, выделяет и возвращает фрагменты str,
// ограниченные символами из razd, но при этом не портит строку str.

char* StrTok(const char *str, const char *razd)
{
    static char *p=nullptr, *p1, *p2;
    char *p3;
    int state=1;
    int len;

    if(str)
    {
        for(len=0;str[len];len++);
        p=new char[len+1];
        for(int k=0; (p[k]=str[k]); k++);
        p1=p2=p;
    }

    while(true)
    {
        if(p==nullptr) return nullptr;
        switch(state)
        {
            case 1:
                if(*p2=='\0')
                { delete[] p; p=nullptr; return nullptr;}
                if(IsRazd(*p2,razd))
                {p1=++p2; break;}
                state=2;
            case 2:
                if(*p2=='\0' || IsRazd(*p2,razd))
                {
                    p3=p1;
                    if(*p2=='\0') return p3;
                    *p2='\0'; p1=++p2; return p3;
                }
                p2++;
        }
    }
}