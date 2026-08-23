#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
void main(){
char *str;
clrscr();
str=(char*)malloc(15);
strcpy(str,"Ambition Academy Bhopal");
printf("string=%s\nAddress=%u,\n",str,str);
str=(char*)realloc(str,50);
strcat(str,".com");
printf("string=%s\nAddress=%u",str,str);
free(str);
getch();}