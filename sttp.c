#include <stdio.h>
#include <stdlib.h>
//#include <process.h>
#define STACK_SIZE 5

void push(int item, int *top, int s[]);
int pop(int *top, int s[]);
void display(int top, int s[]);

int main()
{

    int s[STACK_SIZE], ch, top = -1, item, item_deleted;

    for (;;)
    {
        printf("enter your choice\n 1.PUSH\n2.POP\n3.DISPLAY\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            push(item, &top, s);
            break;
        case 2:
            item_deleted = pop(&top, s);
            printf("the element deleted %d\n", item_deleted);
            if (item_deleted == 0)
            {
                printf("empty stack\n");
                return 999999;
            }
            break;
        case 3:
            display(top, s);
            break;
        case 4:
            printf("invalid option\n");
            return 0;
            break;
        }
    }

    return 0;
}
void push(int item, int *top, int s[])
{
    if (*top == STACK_SIZE - 1)
    {
        printf("stack is full\n");
        return;
    }
    else
    {
        printf("enter the element to be inserted\n");
        scanf("%d",& item);
        *top = *top + 1;
        s[*top] = item;
    }
    return;
}

int pop(int *top, int s[])
{
    int item;
    if (*top == -1)
    {
        printf("stack is not found\n");
        return 99999;
    }
    item = s[*top];
    *top = *top - 1;
    return item;
}

void display(int top, int s[])
{
    int i;
    if (top == -1)
    {
        printf("stack is empty\n");
        return;
    }
    for (i = top; i >= 0; i--)
    {
        printf("%d\n", s[i]);
    }
    printf("content of stack\n");
}
