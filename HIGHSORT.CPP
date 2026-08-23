#include<stdio.h>
#include<conio.h>
void main(){
int a[10],i,high;
clrscr();
for(i=0;i<=9;i++)
{
printf("Enter the 10 element:" );
scanf("%d",&a[i]);
}
high=a[0];
for(i=0;i<=9;i++)
{if (a[i]>=high)
high=a[i];}
printf("the grater element is:%d",low);
getch();}
