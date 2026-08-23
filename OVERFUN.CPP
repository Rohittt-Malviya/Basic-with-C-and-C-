#include<iostream.h>
#include<conio.h>
int add(int,int);
float add(float,int);
void main()
{
int a,b,c;
float cf;
cout<<"Enter the 2 number";
cin>>a>>b;
cout<<"Enter the f number";
cin>>cf>>c;
cout<<add(a,b)<<endl;
cout<<add(cf,c)<<endl;
getch();
}
int add(int x, int y)
{
return x+y;
}
float add(float a, int b)
{
return a+b;
}