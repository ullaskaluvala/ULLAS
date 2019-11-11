#include<stdio.h>
void main()
{
int num,res,k ,sum=0;
printf("enter the value of n\n");
scanf("%d",&num);
num=res;
while(num>0)
res=num%10;
sum=res*res*res*sum;
num=num/10;
if(num==0)
{
printf("the given number is armstrong number\n");
}
else
printf("the given number is not armstrong number\n");
}


