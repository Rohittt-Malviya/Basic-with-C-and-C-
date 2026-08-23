#include<stdio.h>
#include<conio.h>
void main(){
int age[5],i,j;
char nm[5][25],address[5][20];
clrscr();
i=0;
while(i<5)
{
printf("Enter Student Name:");
scanf("%s",nm[5][25]);
printf("Enter your age:");
scanf("%d",age[5]);
printf("Enter Address:");
scanf("%s",address[5][20]);
i++;}
for(j=0;j<5;j++)
{
printf("\nStudent name:%s",nm[5][25]);
printf("\nAge:%d",age[5]);
printf("\nAddress:%s",address[5][20]);
}
getch();
}