#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, const_cast<char *>("C:\\TURBOC3\\BGI"));

    float p0, p_next, x2, y2, dx, dy, i_x, i_y, x1, y1, x_next, y_next;

    cout << "Enter the value of x1 and y1: ";
    cin >> x1 >> y1;
    cout << "Enter the value of x2 and y2: ";
    cin >> x2 >> y2;

    dx = fabs(x2 - x1);
    dy = fabs(y2 - y1);
    if (x2 > x1)
        i_x = 1;
    else
        i_x = -1;
    if (y2 > y1)
        i_y = 1;
    else
        i_y = -1;

    if (dx > dy)
    {
        p0 = 2 * dy - dx;
        while (x1 != x2)
        {
            putpixel(x1, y1, WHITE);
            if (p0 < 0)
            {
                x1 += i_x;
                p0 += 2 * dy;
            }
            else
            {
                x1 += i_x;
                y1 += i_y;
                p0 += 2 * (dy - dx);
            }
            delay(50);
        }
    }
    else
    {
        p0 = 2 * dx - dy;
        while (y1 != y2)
        {
            putpixel(x1, y1, WHITE);
            if (p0 < 0)
            {
                y1 += i_y;
                p0 += 2 * dx;
            }
            else
            {
                x1 += i_x;
                y1 += i_y;
                p0 += 2 * (dx - dy);
            }
            delay(50);
        }
    }

    putpixel(x1, y1, WHITE);

    getch();

    closegraph();

    return 0;
}
