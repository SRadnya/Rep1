#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int genraterandomnum(int n)
{
  srand(time(NULL));
  return rand() % n;
}
int greater(char c1,char c2)
{
  if((c1=='r')&&(c2=='s'))
  {
    return 1;
  }
  if((c1=='p')&&(c2=='r'))
  {
    return 1;
  }
  if((c1=='s')&&(c2=='p'))
  {
    return 1;
  }
  if((c1=='s')&&(c2=='r'))
  {
    return 0;
  }
  if((c1=='r')&&(c2=='p'))
  {
    return 0;
  }
  if((c1=='p')&&(c2=='s'))
  {
    return 0;
  }
  if((c1=='p')&&(c2=='p'))
  {
    return -1;
  }
   if((c1=='s')&&(c2=='s'))
  {
    return -1;
  }
   if((c1=='r')&&(c2=='r'))
  {
    return -1;
  }
}
int main()
{
  int n, i, temp=0, compscore=0, plyscore=0,ram=0;
  char plychar, compchar;
  char dic[]={'r','p','s'};
  system("color 8d");
  printf("select how many times you have to play \n");
  scanf("%d", &n);
  for (i = 0; i < n; i++)
  {
    //player's turn
    printf("CHOOSE ONE AMONG\n 1.ROCK\n 2.PAPER\n 3.SISSORS\n");
    printf("Player's Turn :\n");
    scanf("%d", &temp);
    plychar = dic[temp - 1];
    printf("YOUR chioce is %c\n\n",plychar);

    //computer's turn
    printf("COMP'S Turn :\n");
    ram = genraterandomnum(3);
    compchar = dic[ram];
    printf("COMP chioce is %c \n\n",compchar);

    //comparision of score
    if (greater(compchar, plychar) == 1)
    {
      compscore += 1;
      printf("COMP WON\n");
    }
    else if(greater(compchar, plychar) == -1)
    {
      compscore += 1;
      plyscore += 1;
      printf("MATCH WAS DRAW\n");
    }
    else
    {
      plyscore += 1;
      printf("YOU WON\n\n\n");
    }
  }
  return 0;
}