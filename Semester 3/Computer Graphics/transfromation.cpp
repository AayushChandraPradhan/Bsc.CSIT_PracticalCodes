#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void translation(int , int , int , int, int, int );
void rotation(int , int , int , int, int );
void rotationArbitrary(int , int , int , int, int, int, int );
void scaling(int , int , int , int, int, int );
void reflection();
void shear_x(int);
void shear_y(int);

int main()
{
	int gd=DETECT,gm;  
    initgraph(&gd,&gm,"c:\\tc\\bgi");  
    
    int ch;
    printf("\n\n 1. Translation \n 2. Rotation \n 3. Rotation about arbitrary point \n 4. Scaling \n 5. Reflection \n 6. X-shear \n 7. Y-shear");
    printf("Enter your Choice (1,2,3,4,5,6,7): ");
    scanf("%d", &ch);
  	
  	if (ch ==1)    
   		translation(100, 300, 200, 500, 50, 25);
   	else if (ch==2)
   		rotation(10, 100, 10, 200, -45);
   	else if (ch==3)
   		rotationArbitrary(50, 50, 50, 200, 10, 20,  -45);
   	else if (ch==4)
    	scaling(10, 100, 25, 200, 5, 2);  
	else if (ch==5)  
    	reflection();
    else if (ch==6)
    	shear_x(2);
    else if (ch==7)
		shear_y(2); 
	else
		printf("\n\nInvalid Entry");  
    getch();
    return 0;
}

void shear_x(int shear_f)
{
	int x1 = 50, x2 = 100, x3 = 200;
	int y1 = 50, y2 = 150, y3 = 75;
	
	setcolor(14);
    outtextxy(x1-20, y1-20, "Original triangle");
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    getch();
	
	setcolor(4);
	x1 = x1 + y1*shear_f;
	x2 = x2 + y2*shear_f;
	x3 = x3 + y3*shear_f;
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x3+20, y3+20, "after x-shear");
}

void shear_y(int shear_f)
{
	int x1 = 50, x2 = 100, x3 = 200;
	int y1 = 50, y2 = 150, y3 = 75;
	
	setcolor(14);
    outtextxy(x1-20, y1-20, "Original triangle");
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    getch();
	
	setcolor(2);
	y1 = y1 + x1*shear_f;
	y2 = y2 + x2*shear_f;
	y3 = y3 + x3*shear_f;
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    outtextxy(x3+20, y2+20, "after y-shear");
}

void reflection()
{
	line(getmaxx() / 2, 0, getmaxx() / 2, getmaxy());
    line(0, getmaxy() / 2, getmaxx(), getmaxy() / 2);
        
	int x1 = 100, x2 = 100, x3 = 200;
	int y1 = 100, y2 = 200, y3 = 100;
	
	setcolor(14);
    outtextxy(x1-20, y1-20, "Original triangle");
	line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
    getch();
    
	//reflection about orgin
	setcolor(4);    
	line(getmaxx() - x1, getmaxy() - y1, getmaxx() - x2, getmaxy() - y2);  
    line(getmaxx() - x2, getmaxy() - y2, getmaxx() - x3, getmaxy() - y3);  
    line(getmaxx() - x3, getmaxy() - y3, getmaxx() - x1, getmaxy() - y1);
    outtextxy(getmaxx() - x3, getmaxy() - y3 + 20, "reflection about origin");
    getch();
    
    //reflection about x-axis
    setcolor(3);
    line(getmaxx() - x1, y1, getmaxx() - x2, y2);
    line(getmaxx() - x2, y2, getmaxx() - x3, y3);
    line(getmaxx() - x3, y3, getmaxx() - x1, y1);
    outtextxy(getmaxx() - x3 , y1 - 20, "reflection about x-axis");
    getch();
    
     //reflection about y-axis
    setcolor(2);
    line(x1, getmaxy() - y1, x2, getmaxy() - y2);
    line(x2, getmaxy() - y2, x3, getmaxy() - y3);
    line(x3, getmaxy() - y3, x1, getmaxy() - y1);
    outtextxy(x1 , getmaxy() - y1 +20, "reflection about y-axis");
    getch();	
}

void translation(int x1, int y1, int x2, int y2, int tx, int ty)
{
	outtextxy(x1-2, y1-2, "Origninal Line");	
	line(x1,y1,x2,y2);
	int x3=x1+tx, y3=y1+ty;
	int x4=x2+tx, y4=y2+ty;
	outtextxy(x4+2, y4+2, "translated Line");
	line(x3,y3,x4,y4);	
}

void rotation(int x1, int y1, int x2, int y2, int ang)
{
	outtextxy(x1-2, y1-2, "Origninal Line");	
	
	line(x1,y1,x2,y2);
	
	int x3 = x1*cos(ang)-y1*sin(ang);
	int y3 = x1*sin(ang)+y1*cos(ang);
	
	int x4 = x2*cos(ang)-y2*sin(ang);
	int y4 = x2*sin(ang)+y2*cos(ang);	
	
	outtextxy(x4+2, y4+2, "rotated Line");
	line(x3,y3,x4,y4);	
}

void rotationArbitrary(int x1, int y1, int x2, int y2, int xr, int yr, int ang)
{
	outtextxy(x1-2, y1-2, "Origninal Line");	
	
	line(x1,y1,x2,y2);
	
	int x3 = xr + (x1-xr)*cos(ang)-(y1-yr)*sin(ang);
	int y3 = yr + (x1-xr)*sin(ang)+(y1-yr)*cos(ang);
	
	int x4 = xr + (x2-xr)*cos(ang)-(y2-yr)*sin(ang);
	int y4 = yr + (x2-xr)*sin(ang)+(y2-yr)*cos(ang);	
	
	outtextxy(x4+2, y4+2, "rotated Line about arbitrary point");
	line(x3,y3,x4,y4);	
}

void scaling(int x1, int y1, int x2, int y2, int sx, int sy)
{
	outtextxy(x1-2, y1-2, "Origninal Line");	
	line(x1,y1,x2,y2);
	int x3=x1*sx, y3=y1*sy;
	int x4=x2*sx, y4=y2*sy;
	outtextxy(x4+2, y4+2, "translated Line");
	line(x3,y3,x4,y4);	
}