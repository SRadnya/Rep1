#include <stdio.h>
struct employee
{
    char name[10];
    int salary;
    int dis;
    char role[10];
};

int main()
{
    struct employee e[20];
    int n, i, id;
    printf("enter the value of n\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the Employee detials as per the below instuctions\n A.Enter your Employee ID\n");
        printf(" B.Employee Name\n C. Employee Salary \n D.Employee coverd distance \n E.Employee role\n");
        printf("%d  enter the emp data\n", i + 1);
        scanf("%d",&id);
        scanf("%s%d%d%s", e[i].name, &e[i].salary, &e[i].dis, e[i].role);
    }
    printf("The Detials of Employee are\n");
    for (i = 0; i < n; i++)
    {
        printf(" %d EMPLOYEE ID is %d\n", i+1,id);
        printf(" employee was %s\n their salary is %d\n their distance was %d\n their role was %s\n",  e[i].name, e[i].salary, e[i].dis, e[i].role);
    }
    return 0;
}