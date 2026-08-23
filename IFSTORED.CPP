#include<stdio.h>
#include<conio.h>
void main(){
int n,t=0;
clrscr();
printf("Enter a amount:");
scanf("%d",&n);
if(n>1000)
{
t=n-n*10/100;
printf("Discount is applied After disciunt:%d",t);
}
if(n>500)
{
if(n<1000)
{
t=n-n*5/100;
printf("Discount is applied After Discount:%d",t);
}
}
if(n<500){
printf("\nNo Discount us applied ");
}
getch();
}
