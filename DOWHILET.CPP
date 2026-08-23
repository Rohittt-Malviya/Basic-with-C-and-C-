#include<stdio.h>
#include<conio.h>
void main(){
int i,n,t=0;
char ch;
clrscr();
do{
printf("Enter a No:");
scanf("%d",&n);
for(i=1;i<=10;i++){
t=i*n;
printf("\nThe table is :%d",t);
}
printf("\nWant more :y/n\t");
ch=getche();
}
while(ch=='y');
getch();}