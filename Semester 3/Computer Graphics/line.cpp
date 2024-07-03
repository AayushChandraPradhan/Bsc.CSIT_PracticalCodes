#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void lineDDA(int, int, int, int);
void lineBresenham(int, int, int, int);

int main()
{
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");  
    lineDDA(100,100,200,300);  
    getch();
    return 0;
}
void lineDDA (int x1, int y1, int x2, int y2) 
{ 
	int steps, k; 
	float incrx, incry, x, y, dx, dy; 
	
	dx=abs(x2-x1); 
	dy=abs(y2-y1); 
	
	if (dx > dy) 
		steps=dx; 
	else 
		steps=dy; 
		
	incrx=dx/steps; 
	incry=dy/steps; 
	
	printf("%f, %f", incrx, incry);
	
	x=x1; /* first point to plot */ 
	y=y1; 
	putpixel(round(x), round(y),1); //1 is used for color 
	for (k=1;k<=steps;k++) 
	{ 
		//delay(100);
		x = x + incrx; 
		y = y + incry; 
		putpixel(round(x),round(y),1); \]
	}
 }
 void lineBresenham (int x1, int y1, int x2, int y2) 
{ 
	int x, y, dx, dy, pk, xEnd;
	dx=abs(x2-x1); 
	dy=abs(y2-y1); 
	if(x1>x2) 
	{ 
		x = x2;   y = y2;  xEnd = x1; 
	} 
	else 
	{ 
		x = x1;  y = y1;   xEnd = x2; 
	} 
	pk=2*dy-dx; 
	while (x<=xEnd) 
	{ 
		putpixel(x,y,1);
		x=x+1;
		if(pk<0)
			pk=pk+2*dy; 
		else {
			pk= pk+2*dy-2*dx;
			y=y+1;
		 }
	}
}
