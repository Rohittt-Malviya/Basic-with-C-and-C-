#include<stdio.h>
#include<conio.h>
void main(){
char nm[10],ad [20],*nptr,*adptr;
int age,*aptr;
clrscr();
nptr=nm;
adptr=ad;
aptr=&age;
printf("Enter the name age address:");
scanf("%s%d%s",nm,&age,ad);
printf("\n___________________\n");
printf("Name is :%s",nm);
printf("Address is :%u",&nptr);
printf("\nAge:%d",age);
printf("\nAddress is:%u",&aptr);
printf("\nthe address is :%s",ad);
printf("Address is :%u",&adptr);
getch();
}