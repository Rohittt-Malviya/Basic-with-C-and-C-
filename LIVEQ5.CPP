#include<stdio.h>
#include<conio.h>
void main(){
int age;
clrscr();
printf("Enter the Age:");
scanf("%d",&age);
if(age>=18)
{if(age<65)
{printf("this person is avaliable for drive a car");
}
}
else
{
printf("not eligible for drive a car");
}
getch();
}