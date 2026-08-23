#include<stdio.h>
#include<conio.h>
void main(){
FILE *fptr;
char name[20];
int age;
float salary;
fptr=fopen("emp.txt","w");
if(fptr==NULL){
printf("File does not exist:\n");
return;}
printf("Enter the name:");
scanf("%s",name);
fprintf(fptr,"Name is:%s\n",name);
printf("Enter the age:");
scanf("%d",age);
fprintf(fptr,"AGE is :%d\n",age);
printf("Enter the salary:");
scanf("%f",&salary);
fprintf(fptr,"salary:%2f\n",salary);
fclose(fptr);
getch();
}