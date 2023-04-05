#define GLUT_DISABLE_ATEXIT_HACK
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

void myinit();
void myReshape(GLsizei w, GLsizei h);
void display(void);

GLfloat ctrlpoints[7][3]={
{-4.0,-4.0,0.0},{-2.0,4.0,0.0},{-2.0,4.0,0.0},{-2.0,4.0,0.0},{-2.0,4.0,0.0},
{2.0,-4.0,0.0},{4.0,4.0,0.0}};

void myinit(void)
{
glClearColor(0.0, 0.0, 0.0, 1.0);
glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 7, &ctrlpoints[0][0]);
glEnable(GL_MAP1_VERTEX_3);
glShadeModel(GL_FLAT);
}

void display(void)
{
int i;
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0, 1.0, 1.0);
glBegin(GL_LINE_STRIP);
for (i = 0; i <= 30; i++)
glEvalCoord1f((GLfloat) i/30.0);
glEnd();
/* ÏÔÊ¾¿ØÖÆµã */
glPointSize(5.0);
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_POINTS);
for (i = 0; i < 7; i++)
glVertex3fv(&ctrlpoints[i][0]);
glEnd();
glFlush();
}

void  myReshape(GLsizei w, GLsizei h)
{
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if (w <= h)
glOrtho(-5.0, 5.0, -5.0*(GLfloat)h/(GLfloat)w, 5.0*(GLfloat)h/(GLfloat)w, -5.0, 5.0);
else
glOrtho(-5.0*(GLfloat)w/(GLfloat)h, 5.0*(GLfloat)w/(GLfloat)h, -5.0, 5.0, -5.0, 5.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}

int main(int argc, char * * argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
glutInitWindowPosition(0,0);
glutInitWindowSize(300,300);
glutCreateWindow(argv[0]);
myinit();
glutReshapeFunc(myReshape);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

