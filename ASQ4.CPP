#include<stdio.h>
#include<conio.h>
void main(){
char Pname[20];
int qty,rate;
clrscr();
printf("Enter the Product name:");
scanf("%s",Pname);
printf("Enter the Qty:");
scanf("%d",&qty);
printf("Enter the Rates:");
scanf("%d",&rate);
clrscr();
printf("Product Name \t Qty \t Rates\n");
printf("      %s\t%d\t%d\t",Pname,qty,rate);
getch();}