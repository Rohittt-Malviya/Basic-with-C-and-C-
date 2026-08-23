#include<stdio.h>
#include<conio.h>
void main(){
int t=0,m1[3][3],m2[3][3],i,j;
clrscr();
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("Enter 3*3 matrix:%d%d:",j,i);
scanf("%d",&m1[i][j]);
}
}
for(i=0;i<3;i++){
for(j=0;j<3;j++){
printf("Enter 3*3 matrix:%d%d:",j,i);
scanf("%d",&m2[i][j]);
}
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++){
t=m1[i][j]+m2[i][j];
printf("The sum is :%d",t);
}
printf("\n");
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++){
printf("%d",m1[i][j]);
}
printf("\n");
}
for(i=0;i<3;i++)
{
for(j=0;j<3;j++){
printf("%d",m2[i][j]);
}
printf("\n");
}
getch();
}