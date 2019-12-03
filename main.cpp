/*
 * main.cpp: Art
 *
 * Artists:
 * Jose Javier Rodríguez Mota     - A01372812
 * Luis Fernando Cedeño Medrano   - A01373540
 *
 */
 #include <stdlib.h>
 #include <stdio.h>
 #include <OpenGL/gl.h>
 #include <string.h>
 #include <OpenGl/glu.h>
 #include <GLUT/glut.h>

 // Letters
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

 // Screen variables
 static int width;
 static int height;
 GLuint fontOffset;

 // 3D tour variables
 float xv = 0.0, yv = 0.0, zv = 10.0; // Viewing-coordinate origin.
 float xref = 0.0, yref = 0.0, zref = 0.0; // Look-at point.
 GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // View-up vector.

 // Animation variables
 float xrefa = 0.0, yrefa = 0.0, zrefa = 0.0; // Look-at point.
 float xa = 0.0, ya = 0.0, za = -10.0; // Viewing-coordinate origin.
 GLfloat Vxa = 0.0, Vya = 1.0, Vza = 0.0; // View-up vector.

 float movement = 0.1;
 int isNegativeZ = 0;
 int isNegativeX = 0;

 GLfloat mat_specular[] = { 0.0, 0.0, 0.0, 1.0 };

 GLfloat mat_specular_e[] = { 1.0, 1.0, 1.0, 1.0 };

 GLfloat mat_diffuse_white[] = { 1.0, 1.0, 1.0, 0.5 };
 GLfloat mat_diffuse_orange[] = { 206.0f/255,48.0f/255,64.0f/255, 1.0 };
 GLfloat mat_diffuse_red[] = { 203.0f/255,46.0f/255,36.0f/255, 0.5 };
 GLfloat mat_black_ambient[] = {0.0, 0.0, 0.0, 1.0};
 GLfloat mat_shininess[] = { 100.0 };

 GLfloat material_color_orange[] = {206.0f/255,48.0f/255,64.0f/255, 0.5};
 GLfloat material_color_black[] = {0,0,0, 1.0};
 GLfloat material_color_red[] = { 203.0f/255,46.0f/255,36.0f/255, 1.0 };

  GLfloat materialSpecular[] = {0,0,1,1};
  GLfloat material_emission_white[] = {1.0f,1.0f,1.0f, 1.0f};

  GLfloat material_emission_black[] = {0,0,0, 1.0f};

  GLfloat shininess = 20;




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

 void drawArt() {
   glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_black);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular_e);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_black);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 10);
     setColor(COLOR_BLACK,1);
     glBegin(GL_QUADS);
       glVertex3f(4, -1, 0.0);
       glVertex3f(4, -3, 0.0);
       glVertex3f(-5.5, -3, 0.0);
       glVertex3f(-5.5, -1, 0.0);

       glVertex3f(4, -1, -5.0);
       glVertex3f(4, -3, -5.0);
       glVertex3f(-5.5, -3, -5.0);
       glVertex3f(-5.5, -1, -5.0);

       glVertex3f(4, -1, 0.0);
       glVertex3f(4, -3, 0.0);
       glVertex3f(4, -3, -5.0);
       glVertex3f(4, -1, -5.0);

       glVertex3f(-5.5, -1, 0.0);
       glVertex3f(-5.5, -3, 0.0);
       glVertex3f(-5.5, -3, -5.0);
       glVertex3f(-5.5, -1, -5.0);

       glVertex3f(4, -1, -5.0);
       glVertex3f(4, -1, 0.0);
       glVertex3f(-5.5, -1, 0.0);
       glVertex3f(-5.5, -1, -5.0);


     glEnd();
   glPopMatrix();
   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_black);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_black);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
     glRotatef(180,1,0,0);
     glPushMatrix();
      glTranslatef(3,-3,2);
      glScalef(0.7,3.5,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(2,-3,1.7);
      glScalef(0.7,3,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(1.1,-3,2);
      glScalef(0.5,2.7,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(0.5,-3,1);
      glScalef(0.5,2.7,1);
      setColor(COLOR_BLACK, 1.7);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-0.1,-3,2);
      glScalef(0.5,3.7,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-0.8,-3,1.7);
      glScalef(0.5,3.5,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-1.5,-3,2);
      glScalef(0.5,3.8,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-2.5,-3,1);
      glScalef(0.5,2.5,1);
      setColor(COLOR_BLACK, 1.7);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-3.1,-3,2);
      glScalef(0.7,3.5,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
     glPushMatrix();
      glTranslatef(-4.5,-3,1.7);
      glScalef(0.7,3.2,1);
      setColor(COLOR_BLACK, 1);
      triangularPrism();
     glPopMatrix();
   glPopMatrix();
   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_red);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular_e);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_red);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    glTranslatef(0.0,0.0,0.0);
    setColor(COLOR_RED, 0.2);
    triangularPrism();
    glTranslatef(-3.0, 1.0, 0.0);
    glRotatef(90.0, 0.0, 0.0, 0.0);
    setColor(COLOR_RED, 0.6);
    triangularPrism();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_orange);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_orange);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 100);
    glRotatef(90.0, 0.0, 90.0, 0.0);
    glTranslatef(-2.0, 1.0, 0.5);
    setColor(COLOR_ORANGE, 0.4);
    triangularPrism();
    glRotatef(90.0, 90.0, 0.0, 0.0);
    glTranslatef(0.5, 4.0, 1.0);
    glScalef(0.8, 0.8, 0.8);
    setColor(COLOR_ORANGE, 0.65);
    triangularPrism();
   glPopMatrix();

   glPushMatrix();
   glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_red);
   glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_red);
   glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 50);
    glRotatef(90.0, 0.0, 90.0, 0.0);
    glTranslatef(1.1, -0.5, 0.7);
    glScalef(0.9, 0.9, 0.9);
    setColor(COLOR_RED, 0.85);
    triangularPrism();
   glPopMatrix();
   glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_orange);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular_e);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_orange);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 80);
    glRotatef(-90.0, 0.0, 90.0, 0.0);
    glTranslatef(-1.1, -0.7, 3.2);
    glScalef(0.9, 0.9, 0.9);
    setColor(COLOR_ORANGE, 0.5);
    triangularPrism();
   glPopMatrix();
   glPushMatrix();
    glRotatef(-45.0, 0.0, 90.0, 0.0);
    glTranslatef(-1.3, 0.8, 1.0);
    glScalef(0.7, 0.7, 0.9);
    setColor(COLOR_ORANGE, 0.9);
    triangularPrism();
   glPopMatrix();
   glPushMatrix();
    glRotatef(90.0, 0.0, -45.0, 0.0);
    glTranslatef(-2.0, 0.5, -1.9);
    glScalef(0.7, 0.7, 0.9);
    setColor(COLOR_ORANGE, 0.35);
    triangularPrism();
   glPopMatrix();
   glPushMatrix();
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, material_color_red);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mat_specular_e);
    glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, material_color_red);
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 90);
    glTranslatef(-1.5, -1.0, -0.5);
    glScalef(0.7, 1.7, 0.9);
    setColor(COLOR_RED, 0.3);
    triangularPrism();
   glPopMatrix();
   glPushMatrix();
    glTranslatef(1.3, 0.7, 1.5);
    glScalef(0.8, 1.6, 1.2);
    setColor(COLOR_RED, 0.65);
    triangularPrism();
   glPopMatrix();
 }

 void drawInstructions() {
   glPushMatrix();
     glBegin (GL_QUADS);
       glColor3f(0.0f,0.0f,0.3f);
       glVertex3f(10.0, 10.0, 0.0);
       glVertex3f(10.0, -10.0, 0.0);
       glVertex3f(0.0, -10.0, 0.0);
       glVertex3f(0.0, 10.0, 0.0);
     glEnd ();

     glColor3f(1.0f,1.0f,1.0f);
     glRasterPos3f(6.3, 3.5, 0.0);
     printString("INSTRUCTIONS");

     glRasterPos3f(6.3, 3.0, 0.0);
     printString("CAMERA POSITION");
     glColor3f(0.0f,0.8f,0.0f);
     glRasterPos3f(6.3, 2.6, 0.0);
     printString("PRESS Q TO MOVE POSITIVE IN X AXIS");
     glRasterPos3f(6.3, 2.4, 0.0);
     printString("PRESS A TO MOVE NEGATIVE IN X AXIS");

     glRasterPos3f(6.3, 2.0, 0.0);
     printString("PRESS W TO MOVE POSITIVE IN Y AXIS");
     glRasterPos3f(6.3, 1.8, 0.0);
     printString("PRESS S TO MOVE NEGATIVE IN Y AXIS");

     glRasterPos3f(6.3, 1.4, 0.0);
     printString("PRESS E TO MOVE POSITIVE IN Z AXIS");
     glRasterPos3f(6.3, 1.2, 0.0);
     printString("PRESS D TO MOVE NEGATIVE IN Z AXIS");

     glColor3f(1.0f,1.0f,1.0f);
     glRasterPos3f(6.3, 0.7, 0.0);
     printString("CAMERA VIEW");

     glColor3f(0.9f,0.5f,0.1f);
     glRasterPos3f(6.3, 0.3, 0.0);
     printString("PRESS U TO MOVE VIEW POSITIVE IN X AXIS");
     glRasterPos3f(6.3, 0.1, 0.0);
     printString("PRESS J TO MOVE VIEW NEGATIVE IN X AXIS");

     glRasterPos3f(6.3, -0.3, 0.0);
     printString("PRESS I TO MOVE VIEW POSITIVE IN Y AXIS");
     glRasterPos3f(6.3, -0.5, 0.0);
     printString("PRESS K TO MOVE VIEW NEGATIVE IN Y AXIS");

     glRasterPos3f(6.3, -0.9, 0.0);
     printString("PRESS O TO MOVE VIEW POSITIVE IN Z AXIS");
     glRasterPos3f(6.3, -1.1, 0.0);
     printString("PRESS L TO MOVE VIEW NEGATIVE IN Z AXIS");
    
     glColor3f(1.0f,1.0f,1.0f);
     glRasterPos3f(6.3, -1.6, 0.0);
     printString("ILUMINATION");

     glColor3f(0.8f,0.0f,0.4f);
     glRasterPos3f(6.3, -2.0, 0.0);
     printString("PRESS X TO ENABLE LIGHT ZERO");
     glRasterPos3f(6.3, -2.2, 0.0);
     printString("PRESS C TO ENABLE LIGHT ONE");
     glRasterPos3f(6.3, -2.4, 0.0);
     printString("PRESS V TO ENABLE LIGHT TWO");

     glRasterPos3f(6.3, -2.8, 0.0);
     printString("PRESS M TO DISABLE LIGHT ZERO");
     glRasterPos3f(6.3, -3.0, 0.0);
     printString("PRESS N TO DISABLE LIGHT ONE");
     glRasterPos3f(6.3, -3.2, 0.0);
     printString("PRESS B TO DISABLE LIGHT TWO");

     glRasterPos3f(6.3, -3.7, 0.0);
     printString("PRESS G TO ENTER VALUES FOR CAMERA");
     glRasterPos3f(6.3, -3.9, 0.0);
     printString("PRESS T TO ENTER VALUES FOR VIEW");
   glPopMatrix();
 }

 static void display(void) {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glColor3f(1.0f, 0.0f, 0.0f);

     // bottom viewport
     glViewport(0, 0, 1000, 500);
     glLoadIdentity();
     gluLookAt(xa, ya, za, xrefa, yrefa, zrefa, Vxa, Vya, Vza);
     drawArt();

     // Upper left viewport
     glViewport(100, 500, 800, 1000);
     glLoadIdentity();
     gluLookAt(xv, yv, zv, xref, yref, zref, Vx, Vy, Vz);
     drawArt();

     // Upper right viewport
     glViewport(1000, 0, 1000, 1000);
     glLoadIdentity();
     glDisable(GL_LIGHTING);
     glDisable(GL_DEPTH_TEST);
     gluLookAt(0.0, 0.0, -10, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
     drawInstructions();
     glEnable(GL_LIGHTING);
     glEnable(GL_DEPTH_TEST);


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

 void keyboard(unsigned char key, int w, int v) {
   GLfloat pos[] = {xv,yv,zv,1};
   GLfloat x, y, z;

    switch (key) {
       case 'w':
         yv+=movement;
         printf("Movido a:%f %f %f\n", xv, yv, zv );
         break;
       case 's':
         yv-=movement;
         printf("Movido a: %f %f %f\n", xv, yv, zv );
         break;
       case 'q':
         xv+=movement;
         printf("Movido a: %f %f %f\n", xv, yv, zv );
         break;
       case 'a':
         xv-=movement;
         printf("Movido a: %f %f %f\n", xv, yv, zv );
         break;
       case 'e':
         zv+=movement;
         printf("Movido a: %f %f %f\n", xv, yv, zv );
         break;
       case 'd':
         zv-=movement;
         printf("Movido a: %f %f %f\n", xv, yv, zv );
         break;
       case 'u':
         xref+=movement;
         printf("Viendo a: %f %f %f\n", xref, yref, zref );
         break;
       case 'j':
         xref-=movement;
         printf("Viendo a: %f %f %f\n", xref, yref, zref );
         break;
       case 'i':
         yref+=movement;
         printf("Viendo a: %f %f %f\n", xref, yref, zref );
         break;
       case 'k':
        yref-=movement;
        printf("Viendo a: %f %f %f\n", xref, yref, zref );
        break;
       case 'o':
         zref+=movement;
         printf("Viendo a: %f %f %f\n", xref, yref, zref );
         break;
       case 'l':
         zref-=movement;
         printf("Viendo a: %f %f %f\n", xref, yref, zref );
         break;
       case 'v':
          glLightfv(GL_LIGHT2, GL_POSITION, pos);
          glLightfv(GL_LIGHT2, GL_SPECULAR, mat_specular_e);
          glEnable(GL_LIGHT2);
          printf("Luz 2 en: %f %f %f Viendo a:  %f %f %f\n", xv, yv, zv, xref, yref,zref );
          break;
        case 'b':
          glDisable(GL_LIGHT2);
          printf("Luz 2 desactivada\n" );
          break;
        case 'n':
          glDisable(GL_LIGHT1);
          printf("Luz 1 desactivada\n" );
          break;
        case 'm':
          glDisable(GL_LIGHT0);
          printf("Luz 0 desactivada\n" );
          break;
        case 'c':
          glEnable(GL_LIGHT1);
          printf("Luz 1 activada\n" );
          break;
        case 'x':
          glEnable(GL_LIGHT0);
          printf("Luz 0 activada\n" );
          break;
        case 'g':
          printf("Obtener coordenadas para mover la camara x y z\n");
          scanf("%f %f %f",&x,&y,&z);
          xv =x;
          yv =y;
          zv = z;
          printf("Movido a: %f %f %f\n", xv, yv, zv );
          break;
        case 't':
            printf("Obtener coordenadas para mover la vista x y z\n");
            scanf("%f %f %f",&x,&y,&z);
            xref =x;
            yref =y;
            zref = z;
            printf("Vista en: %f %f %f\n", xv, yv, zv );
            break;
       default: break;
    }
    glutPostRedisplay();
 }

 void timer (int val) {
   if (isNegativeX == 0) {
     xa += movement;
   } else {
     xa -= movement;
   }
   if (xa >= 5) {
     isNegativeX = 1;
   }
   if (xa <= -5) {
     isNegativeX = 0;
   }
   if (isNegativeZ == 1) {
     za -= movement;
   } else {
     za += movement;
   }
   if (za >= 10) {
     isNegativeZ = 1;
   }
   if (za <= -10) {
     isNegativeZ = 0;
   }
   glutPostRedisplay();
   glutTimerFunc(16,timer,1);

 }
 void init() {
   GLfloat light_position[] = { 3.0, 1, -2.0, 1.0 };
   GLfloat light_position_2[] = { -3.0, 2, -2.0, 1.0 };

   glClearColor(250.0f/255, 232.0f/255, 217.0f/255, 1.0f);
   glShadeModel(GL_FLAT);
   glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   glEnable( GL_BLEND );
   glLightfv(GL_LIGHT0, GL_POSITION, light_position);
   glLightfv(GL_LIGHT1, GL_POSITION, light_position_2);
   glLightfv(GL_LIGHT0, GL_SPECULAR, mat_specular_e);
   glLightfv(GL_LIGHT1, GL_SPECULAR, mat_specular_e);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_LIGHT1);
   glEnable(GL_DEPTH_TEST);
   glDisable(GL_COLOR_MATERIAL);

   glEnable(GL_NORMALIZE);
   glShadeModel(GL_SMOOTH);
   glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_TRUE);

 }

 int main(int argc, char** argv) {
     glutInit(&argc, argv);
     glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
     glutInitWindowSize(2000, 2000);
     glutInitWindowPosition(100, 100);
     glutCreateWindow(argv[0]);
     init();
     makeRasterFont();
     glutDisplayFunc(display);
     glutReshapeFunc(reshape);
     glutKeyboardFunc(keyboard);
     glutTimerFunc(0,timer,1);
     glutMainLoop();
     return EXIT_SUCCESS;
 }
