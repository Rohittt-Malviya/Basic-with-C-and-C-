#include<iostream.h>
#include<conio.h>
class Area
{
public:
clrscr();
int calculateArea(int r)
{
return r*r;}


public:
int calculateArea(int l, int b)
{return l*b;}

};
void main()
{
Area a1;
cout<<a1.calculateArea(12)<<endl;
getch();
}