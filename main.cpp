/*
 * main.cpp: Art
 */
 #include <stdlib.h>
 #include <OpenGL/gl.h>
 #include <string.h>
 #include <OpenGl/glu.h>
 #include <GLUT/glut.h>

 GLubyte space[] =
 {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

 GLubyte letters[][13] = {
 {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x18},
 {0x00, 0x00, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
 {0x00, 0x00, 0x7e, 0xe7, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
 {0x00, 0x00, 0xfc, 0xce, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc7, 0xce, 0xfc},
 {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xc0, 0xff},
 {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfc, 0xc0, 0xc0, 0xc0, 0xff},
 {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xcf, 0xc0, 0xc0, 0xc0, 0xc0, 0xe7, 0x7e},
 {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
 {0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x7e},
 {0x00, 0x00, 0x7c, 0xee, 0xc6, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06, 0x06},
 {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xe0, 0xf0, 0xd8, 0xcc, 0xc6, 0xc3},
 {0x00, 0x00, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0},
 {0x00, 0x00, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xdb, 0xff, 0xff, 0xe7, 0xc3},
 {0x00, 0x00, 0xc7, 0xc7, 0xcf, 0xcf, 0xdf, 0xdb, 0xfb, 0xf3, 0xf3, 0xe3, 0xe3},
 {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7, 0x7e},
 {0x00, 0x00, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
 {0x00, 0x00, 0x3f, 0x6e, 0xdf, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c},
 {0x00, 0x00, 0xc3, 0xc6, 0xcc, 0xd8, 0xf0, 0xfe, 0xc7, 0xc3, 0xc3, 0xc7, 0xfe},
 {0x00, 0x00, 0x7e, 0xe7, 0x03, 0x03, 0x07, 0x7e, 0xe0, 0xc0, 0xc0, 0xe7, 0x7e},
 {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff},
 {0x00, 0x00, 0x7e, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
 {0x00, 0x00, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
 {0x00, 0x00, 0xc3, 0xe7, 0xff, 0xff, 0xdb, 0xdb, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3},
 {0x00, 0x00, 0xc3, 0x66, 0x66, 0x3c, 0x3c, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
 {0x00, 0x00, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x3c, 0x66, 0x66, 0xc3},
 {0x00, 0x00, 0xff, 0xc0, 0xc0, 0x60, 0x30, 0x7e, 0x0c, 0x06, 0x03, 0x03, 0xff}
 };

 static int width;
 static int height;
 GLuint fontOffset;
 float xv = 0.0, yv = 0.0, zv = -10.0; // Viewing-coordinate origin.
 float xref = 0.0, yref = 0.0, zref = 0.0; // Look-at point.
 GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.
 float movement = 0.1;

 void makeRasterFont(void) {
   GLuint i, j;
   glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

   fontOffset = glGenLists (128);
   for (i = 0,j = 'A'; i < 26; i++,j++) {
     glNewList(fontOffset + j, GL_COMPILE);
     glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, letters[i]);
     glEndList();
   }
   glNewList(fontOffset + ' ', GL_COMPILE);
   glBitmap(8, 13, 0.0, 2.0, 10.0, 0.0, space);
   glEndList();
 }

 void printString(char *s) {
   glPushAttrib (GL_LIST_BIT);
   glListBase(fontOffset);
   glCallLists((GLsizei) strlen(s), GL_UNSIGNED_BYTE, (GLubyte *) s);
   glPopAttrib ();
 }

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

     // bottom viewport
     glViewport(0, 0, width, height/2);
     glLoadIdentity();
     gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     glutWireTeapot(2);

     // Upper left viewport
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

     // Upper right viewport
     glViewport(width/2, height/2, width, height);
     glLoadIdentity();
     gluLookAt(0.0, 0.0, -10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

     glBegin (GL_QUADS);
       glColor3f(0.0f,0.0f,0.3f);
       glVertex3f(10.0, 0.0, 0.0);
       glVertex3f(10.0, -10.0, 0.0);
       glVertex3f(0.0, -10.0, 0.0);
       glVertex3f(0.0, 0.0, 0.0);
     glEnd ();

     glColor3f(0.0f,0.8f,0.0f);
     glRasterPos3f(5.9, -0.5, 0.0);
     printString("PRESS Q TO MOVE POSITIVE IN X AXIS");
     glRasterPos3f(5.9, -0.8, 0.0);
     printString("PRESS A TO MOVE NEGATIVE IN X AXIS");

     glRasterPos3f(5.9, -1.3, 0.0);
     printString("PRESS W TO MOVE POSITIVE IN Y AXIS");
     glRasterPos3f(5.9, -1.6, 0.0);
     printString("PRESS S TO MOVE NEGATIVE IN Y AXIS");

     glRasterPos3f(5.9, -2.1, 0.0);
     printString("PRESS E TO MOVE POSITIVE IN Z AXIS");
     glRasterPos3f(5.9, -2.4, 0.0);
     printString("PRESS D TO MOVE NEGATIVE IN Z AXIS");

     glColor3f(0.9f,0.5f,0.1f);
     glRasterPos3f(5.9, -3.0, 0.0);
     printString("PRESS U TO MOVE VIEW POSITIVE IN X AXIS");
     glRasterPos3f(5.9, -3.3, 0.0);
     printString("PRESS J TO MOVE VIEW NEGATIVE IN X AXIS");

     glRasterPos3f(5.9, -3.8, 0.0);
     printString("PRESS I TO MOVE VIEW POSITIVE IN Y AXIS");
     glRasterPos3f(5.9, -4.1, 0.0);
     printString("PRESS K TO MOVE VIEW NEGATIVE IN Y AXIS");

     glRasterPos3f(5.9, -4.6, 0.0);
     printString("PRESS O TO MOVE VIEW POSITIVE IN Z AXIS");
     glRasterPos3f(5.9, -4.9, 0.0);
     printString("PRESS L TO MOVE VIEW NEGATIVE IN Z AXIS");

     glColor3f(0.8f,0.0f,0.4f);
     glRasterPos3f(5.9, -5.5, 0.0);
     printString("PRESS ALGO TO ADD LIGHT");

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
     glutInitWindowSize(1000, 1000);
     glutInitWindowPosition(100, 100);
     glutCreateWindow(argv[0]);
     glClearColor(250.0f/255, 232.0f/255, 217.0f/255, 1.0f);
     glShadeModel(GL_FLAT);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
     glEnable( GL_BLEND );
     makeRasterFont();
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     glutMainLoop();
     return EXIT_SUCCESS;
 }
