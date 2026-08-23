#include<stdio.h>
#include<conio.h>
void main(){
int n1,n2,r=0;
clrscr();
printf("Enter the n1:");
scanf("%d",&n1);
printf("Enter the n2:");
scanf("%d",&n2);
r=n1+n2;
printf("Addition is:%d",r);
r=n1-n2;
printf("\nSubtraction is :%d",r);
r=n1*n2;
printf("\nMulplication is :%d",r);
r=n1/n2;
printf("\nDivision id :%d",r);
getch();}