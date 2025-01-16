#include <graphics.h>
#include <iostream>
#include <math.h>
using namespace std;

int gd = DETECT, gm;
int n, x[100], y[100], i;
float sfx, sfy;

void draw() {
    for (i = 0; i < n; i++) {
        line(x[i], y[i], x[(i + 1) % n], y[(i + 1) % n]);
    }
}

void shear() {
    for (i = 0; i < n; i++) {
        int newX = x[i] + y[i] * sfx;
        int newY = y[i] + x[i] * sfy; 
        x[i] = newX;
        y[i] = newY;
    }
}

int main() {
    cout << "Enter no. of sides in polygon: ";
    cin >> n;
    cout << "Enter coordinates x, y for each vertex: ";
    for (i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    cout << "Enter shear factors: sfx and sfy: ";
    cin >> sfx >> sfy;

    initgraph(&gd, &gm, (char *)"");
    setbkcolor(WHITE);
    cleardevice();

    cout << "Original Polygon:" << endl;
    setcolor(BLACK); 
    draw();

    shear(); 

    cout << "Sheared Polygon:" << endl;
    setcolor(RED); 
    draw();

    getch();
    closegraph();
    return 0;
}