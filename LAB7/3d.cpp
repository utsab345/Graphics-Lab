#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

class Cube {
public:
    int x1, y1, x2, y2, x1b, y1b, x2b, y2b, d, tpfl;

    Cube() {
        x1 = 0; y1 = 0; x2 = 150; y2 = 150;
        x1b = 150; y1b = 150; x2b = 100; y2b = 100;
        d = 30; tpfl = 30;
    }

    // Function to draw 2D line
    void drawLine(int midx, int midy) {
        line(x1 + midx, -y1 + midy, x2 + midx, -y2 + midy);
    }

    // Function to draw 3D bar
    void drawBar3D(int midx, int midy) {
        bar3d(-x1b + midx, -y1b + midy, -x2b + midx, -y2b + midy, d, tpfl);
    }

    // Function to perform translation
    void translate(int tx, int ty, int tz, int midx, int midy) {
        x1 += tx;
        y1 += ty;
        x2 += tx;
        y2 += ty;

        x1b += tx;
        y1b += ty;
        x2b += tx;
        y2b += ty;

        drawLine(midx, midy);
        drawBar3D(midx, midy);
    }

    // Function to perform scaling
    void scale(int sx, int sy, int sz, int midx, int midy) {
        x1 *= sx;
        x2 *= sx;
        y1 *= sy;
        y2 *= sy;

        x1b *= sx;
        y1b *= sy;
        x2b *= sx;
        y2b *= sy;

        drawLine(midx, midy);
        drawBar3D(midx, midy);
    }

    // Function to perform rotation about Z-Axis
    void rotate(float angle, int midx, int midy) {
        float t = (M_PI * angle) / 180;
        
        // Rotate 2D line points
        int tempX1 = x1 * cos(t) - y1 * sin(t);
        int tempY1 = x1 * sin(t) + y1 * cos(t);
        int tempX2 = x2 * cos(t) - y2 * sin(t);
        int tempY2 = x2 * sin(t) + y2 * cos(t);
        
        x1 = tempX1;
        y1 = tempY1;
        x2 = tempX2;
        y2 = tempY2;

        // Rotate 3D bar points
        int tempX1b = x1b * cos(t) - y1b * sin(t);
        int tempY1b = x1b * sin(t) + y1b * cos(t);
        int tempX2b = x2b * cos(t) - y2b * sin(t);
        int tempY2b = x2b * sin(t) + y2b * cos(t);

        x1b = tempX1b;
        y1b = tempY1b;
        x2b = tempX2b;
        y2b = tempY2b;

        drawLine(midx, midy);
        drawBar3D(midx, midy);
    }

    // Function to perform shearing
    void shear(float shX, float shY, float shZ, int midx, int midy) {
        // Shearing transformation for the 2D line
        int tempX1 = x1 + shX * y1;
        int tempY1 = y1 + shY * x1;
        int tempX2 = x2 + shX * y2;
        int tempY2 = y2 + shY * x2;

        x1 = tempX1;
        y1 = tempY1;
        x2 = tempX2;
        y2 = tempY2;

        // Shearing transformation for the 3D bar
        int tempX1b = x1b + shX * y1b;
        int tempY1b = y1b + shY * x1b;
        int tempX2b = x2b + shX * y2b;
        int tempY2b = y2b + shY * x2b;

        x1b = tempX1b;
        y1b = tempY1b;
        x2b = tempX2b;
        y2b = tempY2b;

        drawLine(midx, midy);
        drawBar3D(midx, midy);
    }

    // Function to perform projection (Orthogonal projection)
    void project(float fx, float fy, int midx, int midy) {
        // Perform orthogonal projection (simplified to drop the z-component)
        int tempX1 = x1 * fx;
        int tempY1 = y1 * fy;
        int tempX2 = x2 * fx;
        int tempY2 = y2 * fy;

        x1 = tempX1;
        y1 = tempY1;
        x2 = tempX2;
        y2 = tempY2;

        int tempX1b = x1b * fx;
        int tempY1b = y1b * fy;
        int tempX2b = x2b * fx;
        int tempY2b = y2b * fy;

        x1b = tempX1b;
        y1b = tempY1b;
        x2b = tempX2b;
        y2b = tempY2b;

        drawLine(midx, midy);
        drawBar3D(midx, midy);
    }
};

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int maxx = getmaxx();
    int maxy = getmaxy();
    int midx = maxx / 2;
    int midy = maxy / 2;
    
    Cube cube;

    // Initial Cube Drawing
    setcolor(WHITE);
    line(midx, 0, midx, maxy);
    line(0, midy, maxx, midy);

    // Initial line and bar3d
    cube.drawLine(midx, midy);
    cube.drawBar3D(midx, midy);

    int ch;
    cout << "1. Translation  2. Scaling  3. Rotation  4. Shearing  5. Projection\n";
    cout << "Enter your choice: ";
    cin >> ch;

    switch (ch) {
        case 1: {
            int tx, ty, tz;
            cout << "Enter tx, ty, tz: ";
            cin >> tx >> ty >> tz;
            cube.translate(tx, ty, tz, midx, midy);
            break;
        }

        case 2: {
            int sx, sy, sz;
            cout << "Enter the scaling factors (sx, sy, sz): ";
            cin >> sx >> sy >> sz;
            cube.scale(sx, sy, sz, midx, midy);
            break;
        }

        case 3: {
            float angle;
            cout << "Enter the rotation angle: ";
            cin >> angle;
            cube.rotate(angle, midx, midy);
            break;
        }

        case 4: {
            float shX, shY, shZ;
            cout << "Enter the shear factors (shX, shY, shZ): ";
            cin >> shX >> shY >> shZ;
            cube.shear(shX, shY, shZ, midx, midy);
            break;
        }

        case 5: {
            float fx, fy;
            cout << "Enter the projection factors (fx, fy): ";
            cin >> fx >> fy;
            cube.project(fx, fy, midx, midy);
            break;
        }
    }

    getch();
    closegraph();
    return 0;
}
