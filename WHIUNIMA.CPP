#include<stdio.h>
#include<conio.h>
void main(){
char ch,sname[20];
int h,e,c,t=0,i,p=0;
clrscr();
printf("Want to enter a Student name:y/n");
ch=getche();
while(ch=='y')
{
printf("\nEnter student name:");
scanf("%s",sname);
printf("\nEnter marks:\nHindi:");
scanf("%d",&h);
printf("\nEnglish:");
scanf("%d",&e);
printf("\ncomputer:");
scanf("%d",&c);
t=h+e+c;
p=t/3;
printf("\nStudent name:%s",sname);
printf("\nmarks:\nHindi:\nEnglish:\ncomputer:%d",&h,&c,&e);
printf("\nTotal:%d",t);
printf("\nper:%d",p);
printf("\nwant more entry:y/n");
ch=getche();
}
getch();
}