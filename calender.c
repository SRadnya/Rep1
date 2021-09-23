#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
struct DATE
{
    /* data */
    int dd;
    int mm;
    int yy;
};
struct DATE date;
//xy coordinates
COORD xy = {0, 0};
// Toset coursur
void gotoxy(int, int);
// to check leap year
int leapyear(int);
//increment month
void countmonth(int *, int *);
//decrement of month
void reducemonth(int *, int *);
//count number of days
int numberofdays(int, int);
// name of days based on numbers
char *getname(int);
//print name of month and year
void print_date(int, int);
//get day number
int getdaynumber(int, int, int);
//get day name
char *getday(int, int, int);
//to print the month
void printmonth(int, int, int, int);
//execution of program starts here
int main()
{
    system("title wowza");
    system("color 6c"); //color help
    int choice;
    char ch;
    while (1)
    {
        system("color 6c");
        ch = 'a';
        system("cls");
        printf("1.To find out the day\n ");
        printf("2.Show the calender  of the month\n");
        printf("3.Exit\n");
        printf("Enter your choice\n ");
        scanf("%d", &choice);
        system("cls");
        switch (choice)
        {
        case 1:
            system("color 5f");
            printf("Enter the date(DD MM YYYY):");
            scanf("%d%d%d", &date.dd, &date.mm, &date.yy);
            system("cls");
            printf("Day is:%s\n", getday(date.dd, date.mm, date.yy));
            printf("press any key to continue......");
            getch();
            break;
        case 2:
            system("color 9f");
            printf("enter month and year(MM YYYY):\n ");
            scanf("%d%d", &date.mm, &date.yy);
            system("cls");
            while (ch != 'q')
            {
                printmonth(date.mm, date.yy, 20, 5);
                ch = getch();
                if (ch == 'n')
                {
                    countmonth(&date.mm, &date.yy);
                    system("cls");
                    printmonth(date.mm, date.yy, 20, 5);
                }
                else if (ch == 'p')
                {
                    reducemonth(&date.mm, &date.yy);
                    system("cls");
                    printmonth(date.mm, date.yy, 20, 5);
                }
            }

        case 3:
            system("color 07");
            exit(0);
        }
    }
    return 0;
}
//setting cursor
void gotoxy(int x, int y)
{
    xy.X = x;
    xy.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

//cheking leap year
int leapyear(int year)
{
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    return 0;
}
//increasing month count
void countmonth(int *mm, int *yy)
{
    ++*mm;
    if (*mm > 12)
    {
        ++*yy;
        *mm = *mm - 12;
    }
}
//reduce month count
void reducemonth(int *mm, int *yy)
{
    --*mm;
    if (*mm < 1)
    {
        --*yy;
        *mm = *mm + 12;
    }
}
//number of days in month
int numberofdays(int month, int year)
{
    switch (month)
    {
    case 1:
        return (31);
    case 2:
        if (leapyear(year) == 0)
            return (28);
        else
            return (29);
    case 3:
        return (31);
    case 4:
        return (30);
    case 5:
        return (31);
    case 6:
        return (30);
    case 7:
        return (31);
    case 8:
        return (31);
    case 9:
        return (30);
    case 10:
        return (31);
    case 11:
        return (30);
    case 12:
        return (31);
    default:
        return (-1);
    }
}
//name of the day based on number
char *getname(int day)
{
    switch (day)
    {
    case 7:
        return ("MONDAY\t");
    case 2:
        return ("TUESDAY\t");
    case 3:
        return ("WEDENESDAY\t");
    case 4:
        return ("THRUSDAY\t");
    case 5:
        return ("FRIDAY\t");
    case 6:
        return ("SATURDAY\t");
    case 1:
        return ("SUNDAY\t");
    default:
        return ("Error in collecting day name\n");
    }
}
//print name of month and year
void print_date(int mm, int yy)
{
    printf("++++++++++++++++++\n");
    gotoxy(25, 6);
    switch (mm)
    {
    case 1:
        printf("JAN\n");
        break;
    case 2:
        printf("FEB\n");
        break;

    case 3:
        printf("MAR\n");
        break;

    case 4:
        printf("APR\n");
        break;
    case 5:
        printf("MAY\n");
        break;
    case 6:
        printf("JUN\n");
        break;
    case 7:
        printf("JUL\n");
        break;
    case 8:
        printf("AUG\n");
        break;
    case 9:
        printf("SEP\n");
        break;
    case 10:
        printf("OCT\n");
        break;
    case 11:
        printf("NEV\n");
        break;
    case 12:
        printf("DEC\n");
        break;
    default:
        printf("ERROR IN GETTING NAME OF MONTH\n");
        break;
    }
    printf("%d", yy);
    gotoxy(20, 7);
    printf("-------------------\n");
}
//get Day number
int getdaynumber(int day, int mon, int year)
{
    int res = 0, t1, t2, y = year;
    year = year - 1600;
    while (year >= 100)
    {
        res = res + 5;
        year = year - 100;
    }
    res = (res % 7);
    t1 = ((year - 1) / 4);
    t2 = ((year - 1) - t1);
    t1 = (t1 * 2) + t2;
    t1 = t1 % 7;
    res = res + t1;
    res = res % 7;
    t2 = 0;
    for (t1 = 1; t1 < mon; t1++)
    {
        t2 += numberofdays(t1, y);
    }
    t2 = t2 + day;
    t2 = t2 % 7;
    res = res + t2;
    res = res % 7;
    if (y > 2000)
        res += 1;
    res = res % 7;
    return res;
}
//getting day function
char *getday(int dd, int mm, int yy)
{
    int day;
    if (!(mm >= 1 && mm <= 12))
    {
        return ("invalid month value\n");
    }
    if (!(dd >= 1 && dd <= numberofdays(mm, yy)))
    {
        return ("invalid date\n");
    }
    if (yy >= 1600)
    {
        day = getdaynumber(dd, mm, yy);
        day = day % 7;
        return (getname(day));
    }
}
//to print the month
void printmonth(int mon, int year, int x, int y)
{
    system("color 9f");
    int nod, day, cnt, d = 1, x1 = x, y1 = y;
    if (!(mon >= 1 && mon <= 12))
    {
        printf("invalid month\n");
        getchar();
        return;
    }
    if (!(year >= 1600))
    {
        printf("invalid year\n");
        getchar();
        return;
    }
    gotoxy(20, y);
    print_date(mon, year);
    y += 3;
    gotoxy(x, y);
    printf("S   M   T   W   T   F   S \n");
    y++;
    nod = numberofdays(mon, year);
    day = getdaynumber(d, mon, year);
    switch (day) //locates the sarting day of calender
    {
    case 0:
        x = x;
        cnt = 1;
        break;
    case 1:
        x = x + 4;
        cnt = 2;
        break;
    case 2:
        x = x + 8;
        cnt = 3;
        break;
    case 3:
        x = x + 12;
        cnt = 4;
        break;
    case 4:
        x = x + 16;
        cnt = 5;
        break;
    case 5:
        x = x + 20;
        cnt = 6;
        break;
    case 6:
        x = x + 24;
        cnt = 7;
        break;

    default:
        printf("invalid data from the get odd number()module ");
        return;
    }
    gotoxy(x, y);
    printf("%02d", d);
    for (d = 2; d <= nod; d++)
    {
        if (cnt % 7 == 0)
        {
            y++;
            cnt = 0;
            x = x1 - 4;
        }
        x = x + 4;
        cnt++;
        gotoxy(x, y);
        printf("%02d", d);
    }
    gotoxy(8, y + 2);
    printf("\npress 'n' to next,\n press 'p'to previous,\n press 'q'to quit,\n ");
}
