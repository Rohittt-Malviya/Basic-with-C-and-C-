#include<graphics.h>
#include<conio.h>
void main(){
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
setbkcolor(1);
circle(100,100,100);
setcolor(RED);
outtextxy(100,200i,"hello");
getch();
}