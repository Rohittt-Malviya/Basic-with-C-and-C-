#include<stdio.h>
#include<conio.h>
void main(){
int i,j,n,t=0;
clrscr();
i=1;
do
{
printf("Enter a number:");
scanf("%d",&n);
for(j=1;j<=10;j++){
t=j*n;
printf("\nTable is:%d",t);}
i++;
}
while(i<=5);
getch();}