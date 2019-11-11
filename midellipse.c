#include "GL/freeglut.h"
#include "GL/gl.h"
#include<math.h>
#include<stdio.h>
int rx ,ry,xc=0 ,yc=0;

void draw()
{
    glClearColor(0.0, 0.0, 0.0, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    
    glOrtho(-600.0,600.0,-350.0,350.0,0.0,100.0);
    glColor3f(255,0,0);

   float dx, dy, d1, d2, x, y; 
    x = 0; 
    y = ry; 
  
    // Initial decision parameter of region 1 
    d1 = (ry * ry) 
         - (rx * rx * ry) 
         + (0.25 * rx * rx); 
    dx = 2 * ry * ry * x; 
    dy = 2 * rx * rx * y; 
  
    // For region 1 
    while (dx < dy) { 
  
        // Print points based on 4-way symmetry 
        printf("(%f, %f)\n", x + xc, y + yc); 
        printf("(%f, %f)\n", -x + xc, y + yc); 
        printf("(%f, %f)\n", x + xc, -y + yc); 
        printf("(%f, %f)\n", -x + xc, -y + yc); 
        glColor3f(255,0,0);
        glBegin(GL_POINTS);
        glVertex2f(x + xc, y + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);
        glEnd();
        
  
        // Checking and updating value of 
        // decision parameter based on algorithm 
        if (d1 < 0) { 
            x++; 
            dx = dx + (2 * ry * ry); 
            d1 = d1 + dx + (ry * ry); 
        } 
        else { 
            x++; 
            y--; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d1 = d1 + dx - dy + (ry * ry); 
        } 
    } 
  
    // Decision parameter of region 2 
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) 
         + ((rx * rx) * ((y - 1) * (y - 1))) 
         - (rx * rx * ry * ry); 
  
    // Plotting points of region 2 
    while (y >= 0) { 
  
        // printing points based on 4-way symmetry 
        printf("(%f, %f)\n", x + xc, y + yc); 
        printf("(%f, %f)\n", -x + xc, y + yc); 
        printf("(%f, %f)\n", x + xc, -y + yc); 
        printf("(%f, %f)\n", -x + xc, -y + yc); 
        glColor3f(255,0,0);
         glBegin(GL_POINTS);
        glVertex2f(x + xc, y + yc);
        glVertex2f(-x + xc, y + yc);
        glVertex2f(x + xc, -y + yc);
        glVertex2f(-x + xc, -y + yc);
        glEnd();
  
        // Checking and updating parameter 
        // value based on algorithm 
        if (d2 > 0) { 
            y--; 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + (rx * rx) - dy; 
        } 
        else { 
            y--; 
            x++; 
            dx = dx + (2 * ry * ry); 
            dy = dy - (2 * rx * rx); 
            d2 = d2 + dx - dy + (rx * rx); 
        } 
    } 
    glFlush();
}

/*
void reshape(int w,int h)
{
        glViewport(0,0,w,h);
        glMatrixMode(GL_PROJECTION);
        
        //glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}*/


int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    printf("Enter rx and ry values-------------\n");
    scanf("%d%d",&rx,&ry);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1200,700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("OpenGL - Creating a ellipse ");
    glutDisplayFunc(draw);
    //glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;



}