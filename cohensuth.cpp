//Cohen Sutherland line clipping algorithm
// Path: cohensuth.cpp
#include<iostream>
#include<graphics.h>
using namespace std;

static int x_max=0,x_min=0,y_max=0,y_min=0;

//define region codes
static int INSIDE=0; //0000
static int LEFT=1;   //0001
static int RIGHT=2;  //0010
static int BOTTOM=4; //0100
static int TOP=8;    //1000

//compute region code for a point(x,y)
int RCode(double x , double y){
    int code = INSIDE;
    if(x<x_min)
        code |= LEFT; //bitwise OR
    else if(x>x_max)
        code |= RIGHT;

    if(y<y_min)
        code |= BOTTOM; //example 0001 | 0100 = 0101
    else if(y>y_max)
        code |= TOP;

        return code;
}

int clip(double x1 , double y1 , double x2, double y2){
    int code1 = RCode(x1,y1);
    int code2 = RCode(x2,y2);

    bool accept = false;
    while(true){
        //both inside
        if(!(code1 | code2)){
            accept = true;
            break;
        }
        //both outside
        else if(code1 & code2){
            break;
        }

        //one of them is outside
        else{
            int code_out;
            double x , y;

            //decide which one is outside
            if(code1 !=0) code_out = code1;
            else code_out = code2;

            //find intersection point
            // y = y1 + (x-x1)*(y2-y1)/(x2-x1)
            // x = x1 + (y-y1)*(x2-x1)/(y2-y1)

            if (code_out & TOP){
                x = x1 + (x2-x1)*(y_max-y1)/(y2-y1);
                y = y_max;
            }
            else if(code_out & BOTTOM){
                x = x1 + (x2-x1)*(y_min-y1)/(y2-y1);
                y = y_min;
            }
            else if(code_out & RIGHT){
                y = y1 + (y2-y1)*(x_max-x1)/(x2-x1);
                x = x_max;
            }
            else if(code_out & LEFT){
                y = y1 + (y2-y1)*(x_min-x1)/(x2-x1);
                x = x_min;
            }
        }

        //replace outside point with intersection point
        if (code_out == code1){
            x1 = x;
            y1 = y;
            code1 = RCode(x1,y1);
        }
        else{
            x2 = x;
            y2 = y;
            code2 = RCode(x2,y2);
        }

    }

    if(accept){
        delay(2000);
        rectangle(x_min,y_min,x_max,y_max);
        line(x1,y1,x2,y2);
    }
}

//driver code 
int main(){
    int gd = DETECT , gm = VGAMAX;
    initgraph(&gd,&gm,NULL);
    cout<<"Enter the coordinates of clipping window"<<endl;
    cout<<"Enter x_min and y_min"<<endl;
    cin>>x_min>>y_min;
    cout<<"Enter x_max and y_max"<<endl;
    cin>>x_max>>y_max;
    rectangle(x_min,y_min,x_max,y_max);
    cout<<"Enter the coordinates of line"<<endl;
    cout<<"Enter x1 and y1"<<endl;
    int x1,y1,x2,y2;
    cin>>x1>>y1;
    cout<<"Enter x2 and y2"<<endl;
    cin>>x2>>y2;
    line(x1,y1,x2,y2);
    delay(2000);
    cleardevice();
    clip(x1,y1,x2,y2);
    getch();
    closegraph();
    return 0;
}

//example input for all variables
// xmax = 100
// xmin = 50
// ymax = 100
// ymin = 50
//line completely outside
// x1 = 10
// y1 = 10
// x2 = 200
// y2 = 200

//line completely inside
// x1 = 60
// y1 = 60
// x2 = 80
// y2 = 80

//line partially inside
// x1 = 60
// y1 = 60
// x2 = 200
// y2 = 200

