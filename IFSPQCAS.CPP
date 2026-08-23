#include<stdio.h>
#include<conio.h>
void main(){
char ch;
clrscr();
printf("Enter a Alphabat:");
scanf("%c",&ch);
if(ch>='A' && ch<='Z')
{
printf("Capital letter");
}
if(ch>='a' && ch<='z')
{
printf("Small letter");
}
getch();
}