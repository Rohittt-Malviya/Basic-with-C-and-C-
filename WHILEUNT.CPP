#include<stdio.h>
#include<conio.h>
void main(){
char nm[10],ch;
clrscr();
printf("want to enter name:y/n") ;
ch=getche();
while(ch=='y')
{
printf("\nEnter the Name:");
scanf("%s",nm);
printf("\nName:%s",nm);
printf("\nwant more name:y/n");
ch=getche();
}
getch();
}