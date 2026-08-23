#include<stdio.h>
#include<conio.h>
void main(){
int a[10],i,low;
clrscr();
for(i=0;i<=9;i++)
{
printf("Enter the 10 element:" );
scanf("%d",&a[i]);
}
low=a[0];
for(i=0;i<=9;i++)
{if (a[i]<=low)
low=a[i];}
printf("the small element is:%d",low);
getch();}
