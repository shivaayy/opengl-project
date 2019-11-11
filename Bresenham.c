#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;



void draw_line() {


    glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    //glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 1200, 0, 700);
	int dx, dy, i, e;

	int incx, incy, inc1, inc2;
	int x,y;

	dx = x2-x1;
	dy = y2-y1;

	if (dx < 0) dx = -dx;
	if (dy < 0) dy = -dy;
	incx = 1;
	if (x2 < x1) incx = -1;
	incy = 1;
	if (y2 < y1) incy = -1;
	x = x1; y = y1;
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POINTS);

	if (dx > dy) {
		glVertex2i(x, y);
		e = 2 * dy-dx;
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i=0; i<dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else
				e += inc2;
			x += incx;
			glVertex2i(x, y);
		}

	} else {
	glVertex2i(x, y);
		e = 2*dx-dy;
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i=0; i<dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else
				e += inc2;
			y += incy;
			glVertex2i(x, y);
		}
	}  
    glEnd();
    glFlush();
}


void shape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
     
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}

void main(int argc, char **argv) {

	printf( "Enter (x1, y1)  , (x2, y2)\n");
	scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1200, 700);
	glutInitWindowPosition(100, 80);
	glutCreateWindow("Bresenham's Line Drawing");
	
	glutDisplayFunc(draw_line);
    
   
    
	glutMainLoop();
}