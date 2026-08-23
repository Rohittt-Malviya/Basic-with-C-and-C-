#include<stdio.h>
#include<conio.h>
void main(){
int f,n[5],i,j;
clrscr();
for(i=0;i<5;i++){
printf("Enter the no:");
scanf("%d",&n[i]); }
f=1;
for(i=1;i<=n[i];i++)
{
f=i*f;
}
for(j=0;j<=4;j++)
{
printf("\n%d",f);
 }
getch();
}