#include<stdio.h>
#include<conio.h>
void main(){
clrscr();
int n,i,j,t=0;
printf("Enter a No:");
scanf("%d",&n);
for(j=1;j<=5;j++)
{
for(i=1;i<=10;i++)
{
t=n*i;
printf("\t%d",t);
}
}
getch();
}