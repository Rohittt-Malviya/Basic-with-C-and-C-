#include<stdio.h>
#include<conio.h>
void main(){
int n,i,t=0;
char ch;
clrscr();
printf("Want to input a no:y/n");
ch=getche();
while(ch=='y')
{
printf("\nEnter a no:");
scanf("%d",&n);
for(i=1;i<=10;i++)
{
t=i*n;
printf("\nTable :%d",t);
}
printf("\nWant more value:y/n");
ch=getche();
}
getch();
}