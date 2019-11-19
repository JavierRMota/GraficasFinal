/*
 * main.cpp: Art
 */
 #include <OpenGL/gl.h>

 #include <OpenGl/glu.h>

 #include <GLUT/glut.h>
//bg: 250.0f/255, 232.0f/255, 217.0f/255, 1.0f
/* Global variables */


GLint winWidth = 600, winHeight = 600; // Initial display-window size.

GLfloat x = 0.0, y = 40.0, z = -100.0; // Viewing-coordinate origin.
GLfloat xref = 0.0, yref = -50.0, zref = 0.0; // Look-at point.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.

/* Set coordinate limits for the clipping window: */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;

/* Set positions for near and far clipping planes: */
GLfloat dnear = 25.0, dfar = 200.0;

void init (void)
{
   glClearColor (250.0f/255, 232.0f/255, 217.0f/255, 1.0f);
   glMatrixMode(GL_MODELVIEW);
   gluLookAt(x, y, z, xref, yref, zref, Vx, Vy, Vz);
   glMatrixMode(GL_PROJECTION);
   glOrtho(-200.0,200.0,-200.0,200.0, -200,200);
   //glFrustum(xwMin, xwMax, ywMin, ywMax, dnear, dfar);
   glEnable(GL_DEPTH_TEST);
}

void displayFcn (void)
{
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  /* Set parameters for a square fill area. */
  glMatrixMode(GL_MODELVIEW);

  // glPolygonMode (GL_FRONT, GL_LINE);
  // glPolygonMode(GL_FRONT, GL_FILL);
  glBegin (GL_QUADS);
    glColor3f(0.0f,0.0f,0.0f);
    glVertex3f(-200.0, -200.0, 200.0);
    glVertex3f(200.0, -200.0, 200.0);
    glVertex3f(200.0,-200.0, -200.0);
    glVertex3f(-200.0, -200.0, -200.0);

    glVertex3f(-200.0, 200.0, 200.0);
    glVertex3f(200.0, 200.0, 200.0);
    glVertex3f(200.0,200.0, -200.0);
    glVertex3f(-200.0, 200.0, -200.0);
  glEnd ();
  glTranslatef(0.0,0.0,0.0);
  glutWireCube (30.0);
 glFlush();

}

void reshapeFcn (GLint newWidth, GLint newHeight)
{
  if (newHeight == 0) newHeight = 1;                // To prevent divide by 0
  GLfloat aspect = (GLfloat)newWidth / (GLfloat)newHeight;

  glViewport(0, 0, newWidth, newHeight);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, aspect, dnear, dfar);
}

int main (int argc, char** argv)
{
   glutInit (&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
   glutInitWindowPosition (50, 50);
   glutInitWindowSize (winWidth, winHeight);
   glutCreateWindow ("Art");
   init ( );
   glutDisplayFunc (displayFcn);
   //glutReshapeFunc (reshapeFcn);
   glutMainLoop ( );
}
