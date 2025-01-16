#include <iostream>
#include <graphics.h>
#include <math.h>
using namespace std;

void translate(int x1, int y1, int x2, int y2, int tx, int ty) {
    line(x1 + tx, y1 + ty, x2 + tx, y2 + ty);
}

void rotateLine(int x1, int y1, int x2, int y2, float theta) {
    float rad = theta * M_PI / 180.0;
    float c = cos(rad);
    float s = sin(rad);
    int rx1 = round(x1 * c - y1 * s);
    int ry1 = round(x1 * s + y1 * c);
    int rx2 = round(x2 * c - y2 * s);
    int ry2 = round(x2 * s + y2 * c);
    line(rx1, ry1, rx2, ry2);
}

void scaleLine(int x1, int y1, int x2, int y2, float sx, float sy) {
    int sx1 = round(x1 * sx);
    int sy1 = round(y1 * sy);
    int sx2 = round(x2 * sx);
    int sy2 = round(y2 * sy);
    line(sx1, sy1, sx2, sy2);
}

int main() {
    int x1, y1, x2, y2, tx, ty;
    float sx, sy, theta;

    cout << "Enter the coordinate x1, y1: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinate x2, y2: ";
    cin >> x2 >> y2;
    cout << "Enter the translation vector tx, ty: ";
    cin >> tx >> ty;
    cout << "Enter the scaling factor sx, sy: ";
    cin >> sx >> sy;
    cout << "Enter the rotation angle theta (in degrees): ";
    cin >> theta;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    setbkcolor(WHITE);
    cleardevice();

    setcolor(BLACK);
    line(x1, y1, x2, y2);

    setcolor(RED);
    translate(x1, y1, x2, y2, tx, ty);

    setcolor(GREEN);
    scaleLine(x1, y1, x2, y2, sx, sy);

    setcolor(BLUE);
    rotateLine(x1, y1, x2, y2, theta);

    getch();
    closegraph();
    return 0;
}