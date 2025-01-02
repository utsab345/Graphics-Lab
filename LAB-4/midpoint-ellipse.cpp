#include <graphics.h>
#include <iostream>
#include <cmath>

#define ROUND(a) ((int)(a + 0.5))

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, const_cast<char *>("C:\\TURBOC3\\BGI"));

    setbkcolor(15);
    cleardevice();
    setcolor(0);

    int xCenter, yCenter, Rx, Ry, x, y, Rx2, Ry2, twoRx2, twoRy2, p, px, py;

    xCenter = getmaxx() / 2;
    yCenter = getmaxy() / 2;

    std::cout << "Enter the semi-major axis (Rx): ";
    std::cin >> Rx;
    std::cout << "Enter the semi-minor axis (Ry): ";
    std::cin >> Ry;

    Rx2 = Rx * Rx;
    Ry2 = Ry * Ry;
    twoRx2 = 2 * Rx2;
    twoRy2 = 2 * Ry2;

    x = 0;
    y = Ry;
    px = 0;
    py = twoRx2 * y;

    putpixel(xCenter + x, yCenter + y, BLACK);
    putpixel(xCenter - x, yCenter + y, BLACK);
    putpixel(xCenter + x, yCenter - y, BLACK);
    putpixel(xCenter - x, yCenter - y, BLACK);

    p = ROUND(Ry2 - (Rx2 * Ry) + (0.25 * Rx2));
    while (px < py) {
        x++;
        px += twoRy2;

        if (p < 0)
            p += Ry2 + px;
        else {
            y--;
            py -= twoRx2;
            p += Ry2 + px - py;
        }

        putpixel(xCenter + x, yCenter + y, BLACK);
        putpixel(xCenter - x, yCenter + y, BLACK);
        putpixel(xCenter + x, yCenter - y, BLACK);
        putpixel(xCenter - x, yCenter - y, BLACK);

        delay(50);
    }

    p = ROUND(Ry2 * (x + 0.5) * (x + 0.5) + Rx2 * (y - 1) * (y - 1) - Rx2 * Ry2);
    while (y > 0) {
        y--;
        py -= twoRx2;

        if (p > 0)
            p += Rx2 - py;
        else {
            x++;
            px += twoRy2;
            p += Rx2 - py + px;
        }

        putpixel(xCenter + x, yCenter + y, BLACK);
        putpixel(xCenter - x, yCenter + y, BLACK);
        putpixel(xCenter + x, yCenter - y, BLACK);
        putpixel(xCenter - x, yCenter - y, BLACK);

        delay(50);
    }

    getch();
    closegraph();

    return 0;
}
