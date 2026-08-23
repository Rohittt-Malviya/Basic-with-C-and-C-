#include<iostream.h>

int main(){
int a,b;
cout<<"Enter the Number A:";
cin>>a;
cout<<"Enter the Number B:";
cin>>b;
cout<<"Number Before swaping :";
cout <<"\nA:"<<a<<"\nB:"<<b;
a=a+b;
b=a-b;
a=a-b;
cout<<"\nnumber After swaping :"<<"\nA:"<<a<<"\nB:"<<b;
return 0;}

