#include<iostream>
#include<graphics.h>
using namespace std;

void move(int direction, int h, int &x, int &y)   
{
    if(direction == 1)       //UP
         y -= h;
    else if(direction == 2)  //RIGHT
         x += h;   
    else if(direction == 3)  //DOWN
         y += h;
    else if(direction == 4)   //LEFT
         x -= h;
    
    lineto(x, y);
}

void hilbert(int up, int right, int down, int left, int i, int h, int &x, int &y)
{              
    if(i > 0)   
    {
        i--;  
        
        hilbert(right, up, left, down, i, h, x, y);   
        move(up, h, x, y);    //  |
        delay(1000);
        
        hilbert(up, right, down, left, i, h, x, y);
        move(right, h, x, y);    // __
        delay(1000);
        
        hilbert(up, right, down, left, i, h, x, y);
        move(down, h, x, y);   // |
        delay(1000);

        hilbert(left, down, right, up, i, h, x, y);
        delay(1000);
    }
}

int main()
{
    int n, x = 100, y = 350, h = 30, right = 2, down = 3, left = 4, up = 1;
    int driver = DETECT, mode = 0;
    initgraph(&driver, &mode, NULL);

    cout << "Give the value of n: ";
    cin >> n;

    moveto(x, y);   //move to xpos and ypos
    hilbert(up, right, down, left, n, h, x, y);            

    delay(1000);
    closegraph();

    return 0;
}
