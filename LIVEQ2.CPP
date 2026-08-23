#include<stdio.h>
#include<conio.h>
void main(){
char ch[1];
clrscr();
printf("Enter the Character:");
gets(ch);
if(ch=="a","i","e","o","u","A","I","E","O","U")
{
printf("It is a vowel");
}
else
{
printf("it is a consonent");
}
getch();
}