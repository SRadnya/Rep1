#include <stdio.h>  // header file for Standard Input Output
#include <stdlib.h> // header file for Standard Library

int main()
{

    //Your code herehah
    long int a[5], temp;
    printf("enter your numbers \n ");
    for (int i = 0; i < 3; i++)
    {
        scanf("%ld", &a[i]);
        if (a[i] > a[i + 1])
        {
            a[i] = temp;
            a[i] = a[i + 1];
            a[i + 1] = temp;
        }
    }
    printf("%ld", a[1]);
    return 0;
}