#include "GL/freeglut.h"
#include "GL/gl.h"
#include<math.h>

void draw()
{
    glClearColor(0.4, 0.4, 0.4, 0.4);
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    
    glOrtho(0.0,1000.0,0.0,700.0,0.0,100.0);
glColor3f(0.909,0.941,0.9568);   //SKY COLOR
        glBegin(GL_POLYGON);   
                glVertex2f(0.0,700.0);glVertex2f(0.0,400.0);glVertex2f(1000.0,400.0);glVertex2f(1000.0,700.0);
        glEnd();
    
glColor3f(0.3411,0.847,0.2705);// GROUND COLOR
        glBegin(GL_POLYGON);   
                glVertex2f(0.0,0.0);glVertex2f(0.0,400.0);glVertex2f(1000.0,400.0);glVertex2f(1000.0,0.0);
        glEnd();

glColor3f(0.384, 0.250, 0.415);
        glBegin(GL_POLYGON);   //     FRONT WALL
                glVertex2f(200.0,200.0);glVertex2f(350.0,200.0);glVertex2f(350.0,400.0);glVertex2f(200.0,400.0);
        glEnd();
glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);   //     FRONT WALL OUTLINE
                glVertex2f(200.0,200.0);glVertex2f(348.0,200.0);glVertex2f(348.0,400.0);glVertex2f(200.0,400.0);
        glEnd();


glColor3f(0.384, 0.250, 0.415);


        glBegin(GL_POLYGON);            // right wall
                glVertex2f(350.0,200.0);glVertex2f(350.0,400.0);glVertex2f(600.0,471.42);glVertex2f(600.0,271.42);
        glEnd();

glColor3f(0.3372, 0.0, 0.0);    //ceiling

        glBegin(GL_POLYGON);      
                glVertex2f(275.0,550.0);glVertex2f(380.0,340.0);glVertex2f(655.0,418.57);glVertex2f(550.0,608.56);
        glEnd();

        glBegin(GL_POLYGON);      
                glVertex2f(170.0,340.0);glVertex2f(200.0,400.0);glVertex2f(200.0,348.57);
        glEnd();

        glBegin(GL_POLYGON);      
                glVertex2f(200.0,400.0);glVertex2f(275.0,550.0);glVertex2f(350.0,400.0);
        glEnd();

glColor3f(0.4,0.4,0.4);

        glBegin(GL_POLYGON);      //middle triangle
                glVertex2f(200.0+5.0,404.0);glVertex2f(275.0,545.0);glVertex2f(350.0-5.0,404.0);
        glEnd();
glColor3f(0.4,0.4,0.4);
        glBegin(GL_POLYGON);   // FRONT DOOR          
                glVertex2f(230,202.0);glVertex2f(320.0,202.0);glVertex2f(320.0,330.0);glVertex2f(230.0,330.0);
        glEnd();
glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);    // FRONT DOOR OUTLINE
                glVertex2f(230,202.0);glVertex2f(320.0,202.0);glVertex2f(320.0,330.0);glVertex2f(230.0,330.0);
        glEnd();

        glBegin(GL_LINES);        //FRONT DOOR PARTITION
                glVertex2f(275.0,202.0);glVertex2f(275.0,330.0);

        glEnd();
glColor3f(0.949,0.8823,0.0509);

glBegin(GL_POLYGON); //           SUN 
    float x, y, i; 
      float pi=3.14287;
    
    for ( i = 0; i < (2 * pi); i += 0.01) 
    { 
       
        x = 800+50* cos(i); 
        y = 600+50 * sin(i); 
          
        glVertex2i(x, y); 
    } 
    glEnd(); 


glColor3f(0.4,0.4,0.4);


        glBegin(GL_POLYGON);            // window
                glVertex2f(435.0,270.0);glVertex2f(435.0,330.0);glVertex2f(515.0,352.86);glVertex2f(515.0,292.86);
        glEnd();
glColor3f(0.0,0.0,0.0);
        glBegin(GL_LINE_LOOP);   // WINDOW OUTLINE
                glVertex2f(435.0,270.0);glVertex2f(435.0,330.0);glVertex2f(515.0,352.86);glVertex2f(515.0,292.86);
                
        glEnd();

        glBegin(GL_LINES);   // WINDOW PARTITION  -1
                glVertex2f(435.0,300.0);glVertex2f(515.0,322.86);
        glEnd();

        glBegin(GL_LINES);   // WINDOW PARTITION  -2
                glVertex2f(475.0,281.86);glVertex2f(475.0,341.86);
        glEnd();

        //   SUN RAY 
glColor3f(0.9725,0.5019,0.0901);
     
//------------------------------------------------------ 
int j=0;
for(j=0;j<12;j++)
{       glBegin(GL_LINES);
                glVertex2f(800.0+55*cos((pi/6)*j),600.0+55*sin((pi/6)*j));
        if(j%2==0)
                glVertex2f(800.0+75*cos((pi/6)*j),600.0+75*sin((pi/6)*j));
        else
                glVertex2f(800.0+65*cos((pi/6)*j),600.0+65*sin((pi/6)*j));
        
        glEnd();
         
}

//-------------------------------------------------



    glFlush();
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(1000,700);
    glutInitWindowPosition(200, 0);
    glutCreateWindow("OpenGL - Creating a triangle");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;



}