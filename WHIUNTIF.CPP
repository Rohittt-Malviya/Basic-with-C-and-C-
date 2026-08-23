#include<stdio.h>
#include<conio.h>
void main(){
int k,n,i;
char ch;
clrscr();
printf("Want to enter A no:y/n");
ch=getche();
while(ch=='y')
{
printf("\nEnter a no:");
scanf("%d",&n);
k=1;
i=1;
while(i<=n)
{ k=i*k;
printf("\nfactorial is:%d",k);
i++;
}
printf("\nwant more values:y/n");
ch=getche();
}
getch();
}
