#include<stdio.h>
#include<conio.h>
void main(){
char pname[50];
int qty,pri,i,j,t=0;
clrscr();
for(i=1;i<=5;i++)
{
printf("Enter Product Name:");
scanf("%s",pname);
printf("Enter the qty:");
scanf("%d",&qty);
printf("Enter the price:");
scanf("%d",&pri);
t=qty*pri; }


for(j=1;j<=5;j++) {
printf("Product name:%s",pname);
printf("\nQty:%d",qty);
printf("\nPri:%d",pri);
printf("\nTotal Price:%d",t);

}
getch();
}