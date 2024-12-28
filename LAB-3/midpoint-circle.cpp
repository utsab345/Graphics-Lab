#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, const_cast<char *>("C:\\TURBOC3\\BGI"));

    float p, x_c, y_c, r, x, y;

    x_c = getmaxx() / 2;
    y_c = getmaxy() / 2;

    cout << "Enter the radius (r): ";
    cin >> r;

    x = 0;
    y = r;
    p = 1 - r;

    while (x <= y)
    {
        for (int i = -1; i <= 1; i += 2)
            for (int j = -1; j <= 1; j += 2)
                putpixel(i * x + x_c, j * y + y_c, WHITE),
                    putpixel(i * y + x_c, j * x + y_c, WHITE);

        x++;

        if (p < 0)
            p += 2 * x + 1;
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }

        delay(50);
    }

    getch();
    closegraph();

    return 0;
}
