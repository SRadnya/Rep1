#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void parser(char *string)
{
    int i, in = 0; //variable tracking
    int index = 0;
    for (i = 0; i < strlen(string); i++)
    {
        if (string[i] == '<')
        {
            in = 1;
            continue;
        }
        else if (string[i] == '>')
        {
            in = 0;
            continue;
        }
        if (in == 0)
        {
            string[index] = string[i];
            index++;
        }
    }
    string[index] = '\0';
    //removal of tralling spaces
    while (string[0] == ' ')
    {
        for (int i = 0; i < strlen(string); i++)
        {
            string[i] = string[i + 1];
        }
    }
    //removal of tab space from end
    while (string[strlen(string) - 1] == ' ')
    {
        string[strlen(string) - 1] = '\0';
    }
}
int main()
{
    char string[]="<h1>harry pooter</h1>";
    parser(string);
    printf("the parsed string is ~~%s~~",string);
    return 0;
}