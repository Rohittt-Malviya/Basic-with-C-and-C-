#include<stdio.h>
#include<conio.h>
void main(){
int n;
clrscr();
printf("Enter the no");
scanf("%d",&n);
if(n%3==0){
if (n%5==0)
{
printf("It is divisible by both");
}
}
else
{
printf("it is not divisible by 3 and 5");
}
getch();
}