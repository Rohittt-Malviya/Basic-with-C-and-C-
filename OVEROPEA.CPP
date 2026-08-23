#include<iostream.h>
#include<conio.h>
class example
{
int a,b;
public:
void input()
{
cout<<"enter the number:";
cin>>a>>b;
}
void operator -()
{
a=-a;
b=-b;
}
void display()
{
cout<<"a="<<a<<endl<<"b="<<b<<endl;
}
};
void main()
{
example e;
e.input();
e.display();
-e;
e.display();
getch();
}