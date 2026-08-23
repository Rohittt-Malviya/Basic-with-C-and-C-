#include<stdio.h>
#include<conio.h>
void main(){
int j,t=0,i,n1,n2,r=0,r2=0,f;
char ch;
clrscr();
printf("Enter a n1:");
scanf("%d",&n1);
printf("Enter a n2:");
scanf("%d",&n2);
printf("want to perform opeartion:y/n\t");
ch=getche();
while(ch=='y')
{
printf("\nThe choice is :\ntable=T\nsquare=S\ncube=C\nfactorial=F\naddition=A\nsubtraction=U\nmultiplicatiom=M\ndivision=D");
printf("\nEnter your choice\t");
ch=getche();
switch(ch){
case 'T':
for(i=1;i<=10;i++)
{
r=i*n1;
printf("\tTable of n1:%d",r);
r2=i*n2;
printf("\nTable of n2:%d",r2);
}
break;
case 'S':
r=n1*n1;
printf("The square of n1:%d",r);
r=n2*n2;
printf("\nThe square of n2:%d",r);
break;
case'C':
r=n1*n1*n1;
printf("\nThe cube is:%d",r);
r=n2*n2*n2;
printf("\nThe cube is:%d",r);
break;
case'F':
f=1;
for(i=1;i<=n1;i++){
f=i*f; }
printf("\nThe factorial is:%d",f);
t=1;
for(j=1;j<=n2;j++){
t=j*t;}
printf("\nThe factorial is:%d",t);

 break;
case 'A':
r=n1+n2;
printf("\nThe sum is:%d",r);
 break;
 case 'U':
 r=n1-n2;
 printf("\nThe subtraction is :%d",r);
 break;
 case 'M':

 r=n1*n2;
 printf("\nThe multiplicaton is:%d",r);
 break;
 case 'D':
 r=n1/n2;
 printf("\nThe division is:%d",r);
 break;
 }
 printf("\nWant more:y/n\t");
 ch=getche();
 }
 getch();}