#include<stdio.h>
#include<conio.h>
void main(){
int n,j,i,t=0;
clrscr();
i=1;
while(i<=5)
{
printf("Enter a number:");
scanf("%d",&n);
i++;
}
j=1;
while(j<=10)
{
t=n*n;
printf("square is :%d\n",t);
j++;
}
getch();
}