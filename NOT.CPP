#include<stdio.h>
#include<conio.h>
void main(){
char name;
int age;
char address;
clrscr();
printf("Enter your name:");
scanf("%s",name);
printf("\nEnter your Age:");
scanf("%d",&age);
printf("Enter your Adddress:");
scanf("%s",address);
clrscr();
gotoxy(20,10);
printf("__________________________________");
gotoxy(20,12);
printf("name:%s",name);
gotoxy(20,14);
printf("Age:%d",age);
gotoxy(20,16);
printf("Address:%s",address);
getch();
}