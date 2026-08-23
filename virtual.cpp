#include<iostream>
using namespace std;
class shape
{
public:
    virtual void draw(){
    cout<<"drawing a shape base class";
    }
    ~shape(){
    cout<<"shape destroy by base class";
    }
};
class rect:public shape
{

public:
    void draw()
    {

        cout<<"drawing a rect by derived class:";

    }
};
int main()
{
    shape *shape;
    rect *rect;
    shape=&rect;
    cout<<"without virtual function :";
    shape->draw();
    return 0;

}
