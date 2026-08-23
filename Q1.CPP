#include<stdio.h>
#include<conio.h>
void main(){
char Ename[10],dpt[10];
double sal;
clrscr();
printf("Enter the Employee Name:");
scanf("%s",Ename);
printf("Enter the Department:");
scanf("%s",dpt);
printf("Enter the Salary Amount:");
scanf("%lf",&sal);
clrscr();
gotoxy(25,10);
printf("Employee Name:%s",Ename);
gotoxy(25,12);
printf("Department:%s",dpt);
gotoxy(25,14);
printf("Salary:%lf",sal);
getch();}