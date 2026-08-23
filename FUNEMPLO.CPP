#include<stdio.h>
#include<conio.h>
long int sal,pf=0,tax=0,net=0;
char name[20],dpt[10],ch;
void input(){
printf("Enter Employe name:");
gets(name);
printf("Enter the dept:");
gets(dpt);
printf("Enter the salary amount:");
scanf("%ld",&sal);
}
void cal()
{
pf=sal*5/100;
tax=sal*10/100;
net=sal+pf-tax;
}
void output()
{
printf("Employee Name:%s",name);
printf("\nDepartment:%s",dpt);
printf("\nincome tax:%ld",tax);
printf("\npf is :%ld",pf);
printf("\nnet salary:%ld",net);
}
void main()
{
clrscr();
input();
cal();
output();
getch();
}