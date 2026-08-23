#include<stdio.h>
#include<conio.h>
void square(int n)
{
int sq=n*n;
printf("The square is:%d",sq);
}
void main(){
int n;
clrscr();
printf("Enter a number:");
scanf("%d",&n);
square(n);
getch();
}