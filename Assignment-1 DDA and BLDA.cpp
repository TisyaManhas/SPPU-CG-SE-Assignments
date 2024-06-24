/*	
	ASSIGNMENT-1
	Problem Statement : 
		Write C++ program to draw line using DDA and Bresenham‘s 		
		algorithm. Inherit pixel class and use function 	    		
		overloading concepts of OOP.Implement the same using OpenGL.
*/	

#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

class pixel {
	public :
		void plot(int x, int y);
		void plot(float x, float y);
};

void pixel :: plot(float x, float y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
	
}
void pixel :: plot(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
	glFlush();
}

class line : public pixel{
	
	public :
		float X1, X2, Y1, Y2;
		int XX1, XX2, YY1, YY2;
		int choice;
		
		void getPointsBresenham();
		void getPointsDDA();
		
		void drawLine(int X1, int X2, int Y1, int Y2);
		void drawLine(float X1, float X2, float Y1, float Y2);
};
void line :: getPointsBresenham(){
	cout << "Enter the Coordinates : \n";
	cout << "x1, y1 : "; cin >>  this->XX1 >>  this->YY1;
	cout << "x2, y2 : "; cin >>  this->XX2 >>  this->YY2;
	cout << "-------------------------------\n";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	drawLine(this->XX1,this->XX2, this->YY1, this->YY2);
	glFlush();
}

void line :: getPointsDDA(){
	cout << "Enter the Coordinates : \n";
	cout << "x1, y1 : "; cin >>  this->X1 >>  this->Y1;
	cout << "x2, y2 : "; cin >>  this->X2 >>  this->Y2;
	cout << "-------------------------------\n";
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1,1,1);
	drawLine(this->X1,this->X2, this->Y1, this->Y2);
	glFlush();
}

void line :: drawLine(int X1, int X2, int Y1, int Y2){
	pixel p;
	float dx, dy, step, xInc, yInc, x = X1, y = Y1;

	dx = X2 - X1;
	dy = Y2 - Y1;
	
	(abs(dx) > abs(dy))? step = abs(dx) : step = abs(dy);
	xInc = dx/step;
	yInc = dy/step;

	for (int i = 1; i <= step+1 ; i++){
		p.plot(x,y);
		x += xInc;
		y += yInc;
	}
}

void line :: drawLine(float X1, float X2, float Y1, float Y2){
	pixel p;
	int dx, dy, xInc, yInc, d, i1, i2, x, y;
		
	x = X1;
	y = Y1;

	dx = abs(X2 - X1);
	dy = abs(Y2 - Y1);

	(X1 > X2) ? xInc = -1 : xInc = 1;
	(Y1 > Y2) ? yInc = -1 : yInc = 1;

	if (dx > dy){
		i1 = 2 * dy;
		i2 = 2 * (dy - dx);
		d = i1 - dx;
		for (int i = 0; i <= dx; i++){
			p.plot(x,y);
			x += xInc;
			if (d < 0)
				d += i1;
			else{
				y += yInc;
				d += i2;
			}
		}
	}
	else {
		i1 = 2 * dx;
		i2 = 2 * (dx - dy);
		d = i1 - dy;
		for (int i = 0; i < dy; i++){
			p.plot(x,y);
			y += yInc;
			if (d < 0)
				d += i1;
			else{
				x += xInc;
				d += i2;
			}
		}
	}
}


void myInit(){
	glClearColor(0,0,0,0);
	glColor3f(1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}


int main(int argc, char** argv){
	line l;
	cout << "---MENU---\n";
	cout << "1. Bresenham line algorithm \n";
	cout << "2. DDA linr algorthm \n";
	cout << "Enter your choice : "; cin >> l.choice;
	cout << "\n";
	
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Line Drawing Algoritm");
	myInit();
	if (l.choice == 1)
		l.getPointsBresenham();
	else 
		l.getPointsDDA();
	
	glutMainLoop();

	return 0;
}





























