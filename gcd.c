//data stucture
//recurssion
#include <stdio.h>
#include<math.h>
int gcd(int a, int b)
{
    if(a==0)
    return b;
    if(b==0)
    return a;
    if(a<b)
    return gcd(b,a);
    if(a==b)
    return a;
    return gcd(b,a%b);

}
int main()
{
    int m,n;
    
    printf("enter the m and n value\n");
    scanf("%d %d",&m,&n);
    printf("the gcd of %d ,%d is %d\n",m,n,gcd(m,n));
    return 0;
}