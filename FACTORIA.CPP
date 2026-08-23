#include<stdio.h>
#include<conio.h>
void main(){
int f,n,i;
clrscr();
printf("Enter the no:");
scanf("%d",&n);
f=1;
for(i=1;i<=n;i++)
{
f=i*f;
}
printf("%d",f);

getch();
}