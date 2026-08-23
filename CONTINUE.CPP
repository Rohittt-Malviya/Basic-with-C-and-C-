#include<stdio.h>
#include<conio.h>
void main(){
int n,i,s=0;
clrscr();
for(i=1;i<=5;i++){
printf("Enter a No:");
scanf("%d",&n);
if(n%2==0)
continue;
s=n*n*n;
printf("\nThe cube is:%d",s);
}
getch();
}