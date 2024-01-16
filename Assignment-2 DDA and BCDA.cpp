/*
	Name : Anand Prakash Dwivedi
	Roll No : 7211
	
	ASSIGNMENT-2
	Problem Statement : 
		Write C++ program to draw circle using DDA and Bresenham’s algorithm. 
		Inherit pixel classand use function overloading concepts of OOP.
		Implement the same using OpenGL.
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

class circle : public pixel{
	
	public :
		int X1, Y1, r;
		void getPoints();
		void drawCircle();
};

class bresenhamCircle : public circle{
	public:
		void drawCircle();
};
class ddaCircle : public circle{
	public :
	void drawCircle();
};

class midpoint : public circle{
	public :
	void drawCircle();
};

void circle :: getPoints(){
	cout << "Enter the coordinates of the center:\n";
	cout << "X-coordinate   : "; cin >> X1;
	cout << "Y-coordinate : "; cin >> Y1;
	cout << "Enter radius : "; cin >> r;
	cout << "-------------------------------\n";
}

void bresenhamCircle :: drawCircle(){
	int x = 0, y = r;
	float d = 3 - 2r;

	while (y >= x){
		plot(x+X1,y+Y1);
		plot(x+X1,-y+Y1);
		plot(-x+X1,y+Y1);
		plot(-x+X1,-y+Y1);
		plot(y+X1,x+Y1);
		plot(y+X1,-x+Y1);
		plot(-y+X1,x+Y1);
		plot(-y+X1,-x+Y1);
		if (d < 0)
			d += 4*x + 6;
		else {
			d += 4*(x-y) + 10;
			y--;
		}
		x++;
	}
}

void midpoint :: drawCircle(){
	int x = 0, y = r;
	float d = 1 - r;

	while (y >= x){
		plot(x+X1,y+Y1);
		plot(x+X1,-y+Y1);
		plot(-x+X1,y+Y1);
		plot(-x+X1,-y+Y1);
		plot(y+X1,x+Y1);
		plot(y+X1,-x+Y1);
		plot(-y+X1,x+Y1);
		plot(-y+X1,-x+Y1);
		if (d < 0)
			d += 2*x + 1;
		else {
			d += 2*(x-y) + 1;
			y--;
		}
		x++;
	}
}

void ddaCircle :: drawCircle(){
	float x1,x2,y1,y2,eps,sx,sy;
	int val,i;
	x1=r;
	y1=0;
	sx=x1;
	sy=y1;
	i=0;
	
	do {
		val = pow(2,i);
		i++;
	}while(val < r);
	eps = 1/pow(2,i-1);
	
	do {
		x2 = x1 + y1*eps;
		y2 = y1 - eps*x2;
		plot(X1+x2,Y1-y2);
		x1=x2;
		y1=y2;
	}while((y1-sy)<eps || (sx-x1)>eps);
}
void myInit(){
	glClearColor(0,0,0,0);
	glColor3f(1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
}


int main(int argc, char** argv){
	
	int choice;
	cout << "---MENU---\n";
	cout << "1. Bresenham circle algorithm \n";
	cout << "2. DDA circle algorthm \n";
	cout << "Enter your choice : "; cin >> choice;
	cout << "\n";
	
		
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Circle Drawing Algoritm");
	myInit();
	if (choice == 1){
		bresenhamCircle bc;
		bc.getPoints();
		bc.drawCircle();
	}
	else {
		ddaCircle dda;
		dda.getPoints();
		dda.drawCircle();
	}
	
	glutMainLoop();

	return 0;
}