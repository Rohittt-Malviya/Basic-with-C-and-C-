#include<stdio.h>
#include<conio.h>
void main(){
char nm[20];
int i;
clrscr();
i=1;
while(i<=5)
{
printf("Enter a Name:");
scanf("%s",nm);
i++;
}
printf("Name id :%s",nm);
getch();}