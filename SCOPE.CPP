#include<iostream.h>
#include<conio.h>
class student
{
private:
int rollno;
char sname[30],add[20];
public:
void input() ;
void output();
};
void student::input()
{
cout<<"Enter the Rollno:";
cin>>rollno;
cout<<"Enter the student name:";
cin>>sname;
cout<<"Enter the address:";
cin>>add;
}
void student::output()
{
cout<<"Rollno is:"<<rollno<<endl;
cout<<"Name is:"<<sname<<endl;
cout<<"Address is:"<<add<<endl;
}
class employee
{
char dpt[10],ename[20];
int no;
public:
void input();
void output();
};
void employee::input(){
cout<<"Enter the Employee name:";
cin>>ename;
cout<<"Enter the dpt:";
cin>>dpt;
cout<<"Enter the mobile no:";
cin>>no;
}
void employee::output(){
cout<<"Employee Name:"<<ename<<endl;
cout<<"Department:"<<dpt<<endl;
cout<<"Mobile no :"<<no<<endl;
}

class account
{
long int sal;
char nm[20],dpt[10];
public:
void input();
void output();
} ;
void account::input(){
cout<<"Enter the Name:";
cin>>nm;
cout<<"Enter the department:";
cin>>dpt;
cout<<"Enter the salary amount:";
cin>>sal;
}
void account::output()
{
cout<<"Name is :"<<nm<<endl;
cout<<"Department is :"<<dpt<<endl;
cout<<"amount:" <<sal<<endl;
}
void main(){
char ch1,ch2;
clrscr();
student s1;
employee e1;
account a1;
do{
cout<<"Enter your choice:\nstudent=s\nemployee=e\naccount=a\t";
cin>>ch1;
switch(ch1)
{
case 's':
s1.input();
clrscr();
s1.output();
break;
case 'e':
e1.input();
clrscr();
e1.output();
break;
case 'a':
a1.input();
clrscr();
a1.output();
break;
default:
cout<<"Wrong choice";
break;
}
cout<<"Want more:y/n";
cin>>ch2;
}
while(ch2=='y');
getch();
}
