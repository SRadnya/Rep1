#include <stdio.h>
#include <stdlib.h>
#define sts 10
void insert(int s[], int *r)
{
    int item;
    if (*r == sts - 1)
    {
        printf("Over flow\n");
    }
    else
    {
        printf("enter the element to be inserted\n");
        scanf("%d", &item);
        s[*++r] = item;
    }
}
void delete (int s[], int *r)
{
    int item;
    if (*r == -1)
        printf("underflow\n");
    else
        item = s[*r--];
    printf("item deleted=%d");
}
void display(int s[], int *r)
{
    int i = 0;
    if (*r == -1)
        printf("underflow\n");
    else
    {
        printf("the stackelements are\n");
        for (i = *r; i > 0; i++)
            printf("%d\t", s[i]);
    }
}
int main()
{
    int a, s[sts], r = -1;
    for (;;)
    {
        printf("Enter your choice to do below oparation \n1.insert\n2.delete\n3.display\nany key to exit");
        scanf("T%d", &a);
        switch (a)
        {
        case 1:
            insert(s[], &r);
            break;
        case 2:
            delete (s[], &r);
            break;
        case 3:
            display(s[], &r);
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
