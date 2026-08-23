#include<stdio.h>
#include<conio.h>
void main(){
int n1,n2,r=0;
char ch;
clrscr();
printf("Enter the n1:");
scanf("%d",&n1);
printf("Enter the n2:");
scanf("%d",&n2);
printf("Enter the choice:\ns=sum\nu=subtraction\nm=multiplication\n");
ch=getche();
switch(ch){
case's':
r=n1+n2;
printf("The sum is:%d",r);
break;
case'u':
r=n1-n2;
printf("The subtraction is:%d",r);
break;
case'm':
r=n1*n2;
printf("The multiplication is:%d",r);
break;
default:
printf("\nwrong choice");
break;
}
getch();}