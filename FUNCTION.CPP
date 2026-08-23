#include<stdio.h>
#include<conio.h>
int h,e,c,t=0,p=0;
char Sname[20],ch;
void input()
{
printf("Enter Student Name:");
scanf("%s",Sname);
printf("Enter marks:\nHindi:");
scanf("%d",&h);
printf("English:");
scanf("%d",&e);
printf("Computer:");
scanf("%d",&c);
}
void cal()
{
t=h+e+c;
p=t/3;
}
void output()
{
printf("Student Name:%s",Sname);
printf("\nMarks:\nHindi:%d",h);
printf("\nEnglish:%d",e);
printf("\nComputer:%d",c);
printf("\nTotal marks:%d",t);
printf("\nPercentage:%d",p);
}
void main()
{clrscr();
input();
cal();
output();
getch();
}