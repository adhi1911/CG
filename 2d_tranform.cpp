#include <stdlib.h>
#include <iostream>
#include <graphics.h>
#include <math.h>

using namespace std;
class Tdimen
{
    int x1, y1, x2, y2, x3, y3;
    
public:
    void translate();
    void scale();
    void rotate();
    void draw();
    
    // Overload the assignment operator
    Tdimen& operator=(const Tdimen& other)
    {
        if (this != &other)
        {
            x1 = other.x1;
            y1 = other.y1;
            x2 = other.x2;
            y2 = other.y2;
            x3 = other.x3;
            y3 = other.y3;
        }
        return *this;
    }
};

void Tdimen::translate()
{
    float tx, ty;
    cout << "Enter tx & ty: ";
    cin >> tx >> ty;
    x1 += tx; x2 += tx; x3 += tx;
    y1 += ty; y2 += ty; y3 += ty;
}

void Tdimen::scale()
{
    float sx, sy;
    cout << "Enter sx & sy: ";
    cin >> sx >> sy;
    x1 *= sx; x2 *= sx; x3 *= sx;
    y1 *= sy; y2 *= sy; y3 *= sy;
}

void Tdimen::rotate()
{
    float deg;
    cout << "Enter angle: ";
    cin >> deg;
    deg = deg * 3.14 / 180;
    int x, y;
    x = x1; y = y1;
    x1 = x * cos(deg) - y * sin(deg);
    y1 = x * sin(deg) + y * cos(deg);
    x = x2; y = y2;
    x2 = x * cos(deg) - y * sin(deg);
    y2 = x * sin(deg) + y * cos(deg);
    x = x3; y = y3;
    x3 = x * cos(deg) - y * sin(deg);
    y3 = x * sin(deg) + y * cos(deg);
}

void Tdimen::draw()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);
    cleardevice();
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main()
{
    int option;
    Tdimen T;
    
    do
    {
        cout << "\n1.Translation 2.Scaling 3.Rotation 4.Exit: ";
        cin >> option;
        
        switch (option)
        {
            case 1:
                cout << "Enter coordinates (x1, y1, x2, y2, x3, y3): ";
                cin >> T.x1 >> T.y1 >> T.x2 >> T.y2 >> T.x3 >> T.y3;
                T.draw();
                T.translate();
                T.draw(); // Draw the triangle after translation
                break;
                
            case 2:
                cout << "Enter coordinates (x1, y1, x2, y2, x3, y3): ";
                cin >> T.x1 >> T.y1 >> T.x2 >> T.y2 >> T.x3 >> T.y3;
                T.draw();
                T.scale();
                T.draw(); // Draw the triangle after scaling
                break;

            case 3:
                cout << "Enter coordinates (x1, y1, x2, y2, x3, y3): ";
                cin >> T.x1 >> T.y1 >> T.x2 >> T.y2 >> T.x3 >> T.y3;
                T.draw();
                T.rotate();
                T.draw(); // Draw the triangle after rotation
                break;

            case 4:
                break;

            default:
                cout << "Invalid choice";
        }
        
    } while (option != 4);

    closegraph();
}

//example coordinates for equilateral traingle
// 100 100 200 100 150 150
