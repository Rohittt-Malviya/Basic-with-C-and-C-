#include<stdio.h>
#include<conio.h>
void main(){
char sname[25];
int h,m,c,i,j,t=0;
clrscr();
for(i=1;i<=4;i++)
{
printf("Enter the Student name:");
scanf("%s",sname);
printf("Enter marks:\nHINDI:");
scanf("%d",&h);
printf("MATHS:");
scanf("%d",&m);
printf("COMPUTER:");
scanf("%d",&c);
t=h+m+c/3;
}
if(t>=60)
{
if(t<=100)
{
printf("First division");
}
}
for(j=1;j<=10;j++)
{
printf("Student Name:%s",sname);
printf("marks:%d\n",h,c,m);
printf("per:%d",t);
}
getch();
}
