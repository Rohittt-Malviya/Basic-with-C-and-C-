#include<stdio.h>
#include<conio.h>
void main(){
char Pname[25];
int qty,pri,t=0;
clrscr();
printf("Enter the Product name:");
scanf("%s",Pname);
printf("Enter the Qty:");
scanf("%d",&qty);
printf("Enter the Sales price:");
scanf("%d",pri);
t=qty*pri;
printf("Total Price:%d",t);
getch();}
