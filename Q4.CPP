#include<stdio.h>
#include<conio.h>
void main(){
int age,Class,Rollno;
char Sname,Address;

clrscr();
printf("Enter the Student Name:\n");
scanf("%s",Sname);
printf("Enter the Age:\n");
scanf("%d",&age);
printf("Enter your class:\n");
scanf("%d",&Class);
printf("Enter Your Rollno:\n");
scanf("%d",&Rollno);
printf("Enter your Address:\n");
scanf("%s",Address);
clrscr();
gotoxy(20,10);
printf("____________________________________");
gotoxy(20,12);
printf("Student Name:%s",Sname);
gotoxy(20,14);
printf("Age:%d ",age);
gotoxy(20,16);
printf("Class:%d",Class);
gotoxy(20,18);
printf("Rollno:%d",Rollno);
gotoxy(20,20);
printf("Address:%s",Address);
getch();
}
