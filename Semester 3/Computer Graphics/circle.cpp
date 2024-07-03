#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void setPixel(int , int , int , int );
void directCircle(int, int, int);
void trigonometicCircle(int , int , int);
void midPointCircle(int , int , int );

int main()
{
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");  
    //circle(100,100,50);
	//directCircle(100,100,50);  
	//trigonometicCircle(100,100,50);  
	midPointCircle(100,100,50);
    getch();
    return 0;
}

void midPointCircle(int h, int k, int r)
{
	int x=0, y=r;
	int p=1 - r;
	while (x<=y)
	{
		setPixel(floor(x), floor(y), h,k);  
		if(p<0)
			p=p+2*x+3;
		else
		{
			p=p+2*(x-y)+5;
			y--;
		}
		x++;		
	} 
	
}

void trigonometicCircle(int h, int k, int r)
{
	double x,y,ang=0;  
	x=0,y=r;  
    
    while(ang<=45)  
    {  
        x=r*cos(ang);
        y=r*sin(ang);
        setPixel(floor(x), floor(y), h,k);  
        ang=ang+1;
    }  
	
}

void directCircle(int h, int k, int r)
{
	double x,y,x2;  
	x=0,y=r;  
    x2 = r/sqrt(2);
    while(x<=x2)  
    {  
        y = sqrt(r*r - x*x);  
        setPixel(floor(x), floor(y), h,k);  
        x += 1;  
    }  
	
}
void setPixel(int x, int y, int h, int k)  
{  
    putpixel(x+h, y+k, RED);  
    putpixel(x+h, -y+k, RED);  
    putpixel(-x+h, -y+k, RED);  
    putpixel(-x+h, y+k, RED);  
    putpixel(y+h, x+k, RED);  
    putpixel(y+h, -x+k, RED);  
    putpixel(-y+h, -x+k, RED);  
    putpixel(-y+h, x+k, RED);  
}  