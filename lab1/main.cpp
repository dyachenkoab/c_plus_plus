#include <iostream>
using namespace std;
int func(char *ptr1, char *ptr2);
int main()
{
    char string1[100], string2[100];
    char *ptr1 = string1;
    char *ptr2 = string2;

    cin >> string1 >> string2;
    int n = func(ptr1, ptr2);
    cout << n << endl;
    return 0;
}

int func(char *ptr1, char *ptr2)
{
    int n;
    while (*ptr1)
    {
        if (*ptr1 != *ptr2)
        {
            if  (*ptr1 < *ptr2) return 21;
            else return 12;
        }

        if (*ptr2 == '\0')
            return 11;
     (*ptr1)++;
     (*ptr2)++;
    }

    return n;
}