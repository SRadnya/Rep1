# include<stdio.h>
#include<stdlib.h>
#define queuesize 5

 void insert_rear(int item,int q[],int* r)
{
    if(*r==queuesize-1)
    printf("Queue empty\n");
    else
    q[*(++r)]=item;
}
void delete_front(int *f,int *r,int q[])
{
    int itemdeleted;
    if(f>r)
    printf(" Not in bound\n ");
    else
    {
    itemdeleted=q[*f--];
    printf("item deleted is %d",&itemdeleted);
    }
}
void display(int *r,int *f,int q[])
{
     if(f<r)
    printf(" Not in bound\n ");
    else{
    printf("the queue content is\n");
    for(int i=*f;i<=*r;i++){
    printf("%d",&q[i]);
    }
    }
}
int main()
{
    int ch,item,f=0,r=-1,q[queuesize];
    for(;;)
    {
    printf("1. insertion \n2. deletion\n3. display\n");
    printf("Enter Your Choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
      case 1:printf("Enter the item to be inserted\n");
             scanf("%d",&item);
             insert_rear( item, q, &r);
             break;
      case 2: delete_front( &f, &r, q);
              break ;
      case 3: display( &r, &f, q);  
              break ; 
      default :exit(0);
    }
    }
    return 0;
       
}