#include<stdio.h>
#include<conio.h>
struct stu
{
char ch,Sname[20];
int h,e,c;
};
struct stu s1;
void main(){
char ch;
int t=0,p=0;
clrscr();
do{
printf("Enter the Student name:");
scanf("%s",s1.Sname);
printf("Enter marks:\nHindi:");
scanf("%d",&s1.h);
printf("\nEnglish:");
scanf("%d",&s1.e);
printf("\nComputer:");
scanf("%d",&s1.c);
t=s1.h+s1.e+s1.c;
p=t/3;
printf("Student Name:%s\t",s1.Sname);
printf("Hindi:%d",s1.h);
printf("\tEnglish:%d",s1.e);
printf("\tComputer:%d",s1.c);
printf("\tTotal:%d",t);
printf("\tper:%d",p);
printf("\nWant more:y/n\t");
ch=getche();
}
while(ch=='y');
getch();
}

