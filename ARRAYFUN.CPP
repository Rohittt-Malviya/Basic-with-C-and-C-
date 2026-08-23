#include<stdio.h>
#include<conio.h>
void displaystudent(char name[][50],int age[],int size)
{
int i;
printf("\nDetails of student :\n");
for(i=0;i<size;i++)
{
printf("students%d:name=%s,age=%d\n",i+1,name[i],age[i]);
}
}
void main(){
char name[5][50];
int age[5],i;
clrscr();
printf("Enter the details of 5 students:\n");
for(i=0;i<5;i++)
{
printf("enter the name of students%d:",i+1);
scanf("%s",name[i]);
printf("Enter the age of students:%d",i+1);
scanf("%d",&age[i]);
while(getchar()!='\n');
}
displaystudent(name,age,5);
getch();
}