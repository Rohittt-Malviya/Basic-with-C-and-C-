#include<stdio.h>
#include<conio.h>
void main(){
int n,i,t=0;
clrscr();
printf("Enter a number:");
scanf("%d",&n);
i=1;
while(i<=10)
{
t=i*n;
printf("Table is:%d\n",t);
i++;
}
getch();
}