#include<iostream>
#include<graphics.h>
using namespace std;

int main()
{
 
 int gd=DETECT, gm;
 initgraph(&gd,&gm,NULL);

 int  cnt,temp,i,j,n, ymax, ymin, yscan;
 float inter_x[10], m[10],dx,dy; 
 int x[10],y[10];
 
 cout<<"Enter number of vertices of polygon: ";
 cin>>n;
 
 for(i=0;i<n;i++)
{
  cout<<" Enter " << i+1 << " vertex of polygon (as x and y): ";
  cin>>x[i]>>y[i];
}
x[n]=x[0];
y[n]=y[0];

for(i=0;i<n;i++)          //draw a polygon
{
  line(x[i],y[i],x[i+1],y[i+1]);
}

ymax=0;
ymin=480;

 for(i=0;i<n;i++)      //find ymax and ymin
 {
   if(y[i]>ymax)
    ymax=y[i];
    if(y[i]<ymin)
    ymin=y[i];
	
 }

 for(i=0;i<n;i++)       //cal slope of each side
 {
  dx=x[i+1]-x[i];
  dy=y[i+1]-y[i];
   
   if(dx==0)
   m[i]=0;
   
   else if(dy==0)
   m[i]=0;
   
   else
   m[i]=(float)dy/dx;
 }
 //scanline filling
for(yscan=ymax;yscan>ymin;yscan--)
 {
    cnt=0;
    for(i=0;i<n;i++)
    {
     	if(y[i]>yscan && y[i+1]<=yscan || y[i]<=yscan && y[i+1]>yscan)
     	{
                  if(m[i]==0)
         	         inter_x[cnt]=x[i];  //inactive edge
       	      else
           	        inter_x[cnt]= x[i] + (yscan-y[i])/m[i];  //active edge
       	        cnt++;
    	}
   }
      
    
      for(j=0;j<cnt-1;j++)  //find intersection points
      {
    	if(inter_x[j]<=inter_x[j+1])
    	{
     		temp=inter_x[j];
    		inter_x[j]=inter_x[j+1];
     		inter_x[j+1]=temp;
            }
      }
   
     
    for(j=0;j<cnt-1;j=j+2)            //fill the polygon using line
    {
        line(inter_x[j],yscan,inter_x[j+1],yscan);
        delay(100);
    }
 }  //end of for loop

getch();
return 0;
}  
