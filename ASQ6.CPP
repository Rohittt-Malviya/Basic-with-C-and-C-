#include<stdio.h>
#include<conio.h>
void main(){
char Bname[25];
int qty,pri;
clrscr();
printf("Enter Book Name:");
scanf("%s",Bname);
printf("Enter Qty:");
scanf("%d",&qty);
printf("Enter Price:");
scanf("%d",&pri);
clrscr();
printf("Book Name:%s",Bname);
printf("\nQty:%d",qty);
printf("\nPrice:%d",pri);
getch();}