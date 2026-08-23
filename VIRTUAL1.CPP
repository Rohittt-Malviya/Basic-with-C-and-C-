#include<iostream.h>
#include<conio.h>
class Shape {
public:

      void draw() {
	cout << "Drawing a shape (base class)" << endl;
    }

     ~Shape() {
	cout << "Shape destroyed (base class)" << endl;
    }
};

class Rectangle : public Shape {
public:

    void draw()  {
	cout << "Drawing a rectangle (derived class)" << endl;
    }
};

int main() {
clrscr();
    Shape* shape;

    Rectangle rectangle;
    shape = &rectangle;
    cout << "With Virtual Function:" << endl;
    shape->draw();  // Calls Rectangle's draw function because of virtual function (dynamic dispatch)
    getch();
    return 0;

}
