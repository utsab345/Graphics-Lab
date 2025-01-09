#include <iostream>
#include <graphics.h>
using namespace std;

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;
const int xMin = 50;
const int xMax = 200;
const int yMin = 50;
const int yMax = 300;

int computeCode(int x, int y) {
    int code = INSIDE;
    if (x < xMin) code |= LEFT;
    else if (x > xMax) code |= RIGHT;
    if (y < yMin) code |= BOTTOM;
    else if (y > yMax) code |= TOP;
    return code;
}

void lineClipping(int x1, int y1, int x2, int y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    bool accept = false;

    while (true) {
        if ((code1 == 0) && (code2 == 0)) {
            accept = true;
            break;
        } else if (code1 & code2) {
            break;
        } else {
            int x, y;
            int codeOut = (code1 != 0) ? code1 : code2;

            if (codeOut & TOP) {
                x = x1 + (x2 - x1) * (yMax - y1) / (y2 - y1);
                y = yMax;
            } else if (codeOut & BOTTOM) {
                x = x1 + (x2 - x1) * (yMin - y1) / (y2 - y1);
                y = yMin;
            } else if (codeOut & RIGHT) {
                y = y1 + (y2 - y1) * (xMax - x1) / (x2 - x1);
                x = xMax;
            } else if (codeOut & LEFT) {
                y = y1 + (y2 - y1) * (xMin - x1) / (x2 - x1);
                x = xMin;
            }

            if (codeOut == code1) {
                x1 = x;
                y1 = y;
                code1 = computeCode(x1, y1);
            } else {
                x2 = x;
                y2 = y;
                code2 = computeCode(x2, y2);
            }
        }
    }

    if (accept) {
        cout << "Line segment after clipping: (" << x1 << ", " << y1 << ") to (" << x2 << ", " << y2 << ")\n";
        line(x1, y1, x2, y2);
    } else {
        cout << "Line segment not inside view port!\n";
    }
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter the coordinates (x1, y1) of the line: ";
    cin >> x1 >> y1;
    cout << "Enter the coordinates (x2, y2) of the line: ";
    cin >> x2 >> y2;

    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");

    rectangle(xMin, yMin, xMax, yMax);
    lineClipping(x1, y1, x2, y2);

    getch();
    closegraph();
    return 0;
}
