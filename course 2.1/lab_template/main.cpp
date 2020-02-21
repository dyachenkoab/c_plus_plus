#include <iostream>
using namespace std;

template <class T> T func(const T *ptr, int stroka, int stolbec, int zadan)
{
    T summa = 0;

    for (int i = zadan - 1; i < ((stroka * stolbec)); i += stolbec)
    {
        summa += *ptr+i;
    }
    return summa;
}

int main()
{
    const int stroka = 3;
    const int stolbec = 5;
    const int zadan = 3;
    const int array[3][5] = {{1,2,3,4,5},
                             {6,7,8,9,10},
                             {11,12,13,14,15}};
    const int *ptr = &array[0][0];
    int summa = func(ptr, stroka, stolbec, zadan);
    cout << "Сумма элементов " << zadan << "-го столбца = " << summa << endl;
    return 0;
}

