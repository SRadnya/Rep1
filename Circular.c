#include<stdio.h>
#include<stdlib.h>
#define Queuesize 5
void insert(int *r,int *c,int q[])
{
    int item;
    if(*r==Queuesize-1)
    {
    printf("queue Overflow\n");
    return;
    }
    printf("Enter the item\n");
    scanf("%d",&item);
    *r=(*r+1)%Queuesize;
    q[*r+1]=item;
    *c++;
}
long int delete(int *f,int *r,int *c,int q[])
{
    long int itemd;
    if(*c==0)
    {
        printf("Queue is empty");
        return 99999999;
    }
    *f=(*f+1)%Queuesize;
    itemd=q[*f++];
    *c--;
return itemd;
}
void display(int *c,int *f,int q[])
{
    if(*c==0)
    {
        printf("Queue Under flow\n");
        return;
    }
    for(int i=*f;i<*c;i++)
    {
        printf("%d",&q[i]);
        i=(i+1)%Queuesize;
    }
}
int main()
{
   int f=0,c=0,r=-1,ch,q[Queuesize],item;
for(;;){
   printf("1.Insert;\n 2.Delete;\n 3.Display;\n Enter your Choice\n");
   scanf("%d",&ch);
   switch (ch)
   {
   case 1:insert( &r ,&c,  q);
       break;
   case 2:item=delete( &f, &r,  &c, q); 
   if(item!=99999999) 
   printf("item deleted is %d",item);
   else
   printf("  Deletion not possible\n"); 
   break;
   case 3:display( &c,&f, q);
   default:exit(0);
       break;
   }
}
    return 0;
}