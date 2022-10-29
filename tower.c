#include<stdio.h>
int count=0;
void tower(int n,int source,int temp,int destination)
{
   if(n==1)
   {
     printf("Move disc 1 from %c to %c\n",source,destination);
     count++;
     return;
   }
   tower(n-1,source,destination,temp);
   printf("Move disc %d from %c to %c\n",n,source,destination);
   count++;
   tower(n-1,temp,source,destination);
}
void main()
{
  int  n;
  printf("Enter the number of disc\n");
  scanf("%d",&n);
  tower(n,'A','B','C');
  printf("Total number of disc moves=%d",count);
}
