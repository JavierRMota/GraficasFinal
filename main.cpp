/*
 * main.cpp: Art
 */
 #include <stdlib.h>
 #include <OpenGL/gl.h>

 #include <OpenGl/glu.h>

 #include <GLUT/glut.h>

 static int width;
 static int height;
 float xv = 0.0, yv = 0.0, zv = -4.0; // Viewing-coordinate origin.
 float xref = 0.0, yref = 0.0, zref = 0.0; // Look-at point.
 GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
 float movement = 0.1;

 int COLOR_BACKGROUND = 0, COLOR_BLACK = 1, COLOR_RED = 2, COLOR_ORANGE = 3;
 void setColor(int value, float alpha) {
   switch(value) {
     case 1:
      glColor4f(0.0,0.0,0.0, alpha);
      break;
    case 2:
      glColor4f(203.0f/255,46.0f/255,36.0f/255, alpha);
      break;
    case 3:
      glColor4f(206.0f/255,48.0f/255,64.0f/255, alpha);
      break;
    default:
      glColor4f(250.0f/255, 232.0f/255, 217.0f/255, alpha);
   }
 }
 void triangularPrism()
{
    glBegin(GL_QUADS);
        glVertex3f(0.5, 0, 0.5);
        glVertex3f(0.5, 0, -0.5);
        glVertex3f(-0.5, 0, -0.5);
        glVertex3f(-0.5, 0, 0.5);

        glVertex3f(0.5,0,-0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);

        glVertex3f(0.5,1,-0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,0.5);
        glVertex3f(0.5,0,0.5);
    glEnd();
    glBegin(GL_TRIANGLES);
        glVertex3f(0.5,0,0.5);
        glVertex3f(0.5,1,-0.5);
        glVertex3f(0.5,0,-0.5);

        glVertex3f(-0.5,0,0.5);
        glVertex3f(-0.5,1,-0.5);
        glVertex3f(-0.5,0,-0.5);
    glEnd();
}

 static void display(void) {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);

     glViewport(0, 0, width, height/2);
     glLoadIdentity();
     gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     glutWireTeapot(2);

     glViewport(0, height/2, width/2, height);
     glLoadIdentity();
     gluLookAt(xv, yv, zv, xref, yref, zref, Vx, Vy, Vz);
     glPushMatrix();
     setColor(COLOR_BLACK, 0.2);
     triangularPrism();
     glTranslatef(0.5,0.5,0.0);
     setColor(COLOR_RED, 0.2);
     triangularPrism();
     glTranslatef(-0.5,-0.5,1.0);
     setColor(COLOR_ORANGE, 0.2);
     triangularPrism();
     glPopMatrix();
     glViewport(width/2, height/2, width, height);
     glLoadIdentity();
     gluLookAt(0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
     glBegin (GL_QUADS);
       glColor3f(0.0f,0.0f,0.0f);
       glVertex3f(-1.0, -1.0, 1.0);
       glVertex3f(1.0, -1.0, 1.0);
       glVertex3f(1.0,-1.0, -1.0);
       glVertex3f(-1.0, -1.0, -1.0);
     glEnd ();

     glFlush();
 }

 static void reshape(int w, int h) {
     width = w;
     height = h;
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
     glMatrixMode(GL_MODELVIEW);
 }

 void keyboard(unsigned char key, int x, int y) {
    switch (key) {
       case 'w':
         yv+=movement;
         break;
       case 's':
         yv-=movement;
         break;
       case 'q':
         xv+=movement;
         break;
       case 'a':
         xv-=movement;
         break;
       case 'e':
         zv+=movement;
         break;
       case 'd':
         zv-=movement;
         break;
       case 'u':
         xref+=movement;
         break;
       case 'j':
         xref-=movement;
         break;
       case 'i':
         yref+=movement;
         break;
       case 'k':
        yref-=movement;
        break;
       case 'o':
         zref+=movement;
         break;
       case 'l':
         zref-=movement;
         break;
       default: break;
    }
    glutPostRedisplay();
 }

 int main(int argc, char** argv) {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize(500, 500);
     glutInitWindowPosition(100, 100);
     glutCreateWindow(argv[0]);
     glClearColor(250.0f/255, 232.0f/255, 217.0f/255, 1.0f);
     glShadeModel(GL_FLAT);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     glEnable( GL_BLEND );
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     glutMainLoop();
     return EXIT_SUCCESS;
 }
