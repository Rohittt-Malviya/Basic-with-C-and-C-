#include<stdio.h>
#include<conio.h>
void main(){
int n,i,t=0;
clrscr();
i=1;
while(i<=5)
{
printf("Enter a number:");
scanf("%d",&n);
i++;
}
t=n*n;
printf("Square is:%d",t);
getch();
}