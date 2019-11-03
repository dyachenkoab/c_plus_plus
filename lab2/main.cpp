#include <iostream>

using namespace std;

int func(char *ptr1, char *ptr2);
int main(int argc, char* argv[])
{
    char string1[100], string2[100];
    char *ptr1 = string1;
    char *ptr2 = string2;

    int n = func(argv[1], argv[2]);
    cout << n << endl;
    for(int i=0; i<argc; i++)
        printf("argv%d=%s\n",i,argv[i]);
    return 0;
}

int func(char *ptr1, char *ptr2)
{
    int n;
    while (*ptr1 != '\0')
    {
        if (*ptr2 == '\0')
            n = 12;

        if (*ptr2 == *ptr1)
            n = 11;

        ptr1++;
        ptr2++;
    }

    if (*ptr2 != '\0')
        n = 21;

    return n;
}