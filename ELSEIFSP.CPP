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
else if(ch>='a' && ch<='z')
{
printf("Small letter");
}
else if(ch>=0 && ch<=9)
{
printf("digit");
}
else
{
printf("special character");
}
getch();
}