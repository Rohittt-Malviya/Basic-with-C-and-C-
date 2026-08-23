#include<stdio.h>
#include<conio.h>
void main(){
int no1,no2;
clrscr();
printf("Enter the No1:");
scanf("%d",&no1);
printf("Enter the No2:");
scanf("%d",&no2);
if(no1/no2)
{
printf("N1 is divisible by N2");
}
else
{
printf("N1 is not divisible  by N2");
}
getch();
}