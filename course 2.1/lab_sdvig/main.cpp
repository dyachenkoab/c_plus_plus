#include <iostream>

using namespace std;
unsigned long func(unsigned long a, int n1);
int main()
{
    int n1;
    unsigned long a, res;

    cout << "Введите число" << endl;
    cin >> a;
    cout << "Введите величину сдвига" << endl;
    cin >> n1;

    res = func(a, n1);
    cout << showbase << hex << "Получившиеся число - " << res << endl;

    return 0;
}
    unsigned long func(unsigned long a, int n1)
    {
        int k;
        int n2;
        k = sizeof(unsigned long) * 8 - 1;

        n2 = k - n1;                                //вычисляем интервал
        a = a >> n1;

        unsigned long r1 = (1 << (k - n2)) - 1;    //получаем маску

        r1 = r1 << n2;

        unsigned long r2 = a | r1;    //применяем маску

        return r2;
    }