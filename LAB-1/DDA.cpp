#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int gd = DETECT, gm;
    
    
    initgraph(&gd, &gm, const_cast<char*>("C:\\TURBOC3\\BGI"));

    float x_inc, y_inc, x1=10, y1=20, x2=170, y2=240, dx, dy, step;

    // cout << "Enter the value of x1 and y1: ";
    // cin >> x1 >> y1;
    // cout << "Enter the value of x2 and y2: ";
    // cin >> x2 >> y2;

    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);
    step = (dx >= dy) ? dx : dy;
    dx = (x2 - x1) / step;
    dy = (y2 - y1) / step;

    x_inc = x1;
    y_inc = y1;
    for (int i = 0; i <= step; i++) {
        putpixel(round(x_inc), round(y_inc), WHITE); 
        x_inc += dx;
        y_inc += dy;
        delay(50); 
    }

    getch();
    
    closegraph();
    
    return 0;
}