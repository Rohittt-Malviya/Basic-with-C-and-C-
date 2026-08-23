#include<stdio.h>
#include<conio.h>
void main(){
char Sname[25];
int Class;
int marks;
clrscr();
printf("Enter Student Name:");
scanf("%s",Sname);
printf("Enter Class:");
scanf("%d",&Class);
printf("Enter the marks:\n");
printf("Computer:");
scanf("%d",marks);
printf("English:");
scanf("%d",&marks);
printf("Hindi:");
scanf("%d",&marks);
clrscr();
gotoxy(25,10);
printf("Student Name:%s",Sname);
gotoxy(25,12);
printf("Class:%d",Class);
gotoxy(25,13);
printf("Marks:");
gotoxy(24,14);
printf("Computer:%d",marks);
gotoxy(24,15);
printf("English:%d",marks);
gotoxy(24,16);
printf("Hindi:%d",marks);
getch();}
