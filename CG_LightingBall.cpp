#include <stdlib.h>
#include <GL/glut.h>

/*  Initialize z-buffer, projection matrix, light source,
 *  and lighting model.  Do not specify a material property here.
 */
 float _angle = 0;
 float _angle_tri = 0;

void init(void)
{
   GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
   GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat local_view[] = { 0.0 };

   glClearColor(0.1, 0.1, 0.1, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, position);

   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
}

/*  Draw twelve spheres in 3 rows with 4 columns.
 *  The spheres in the first row have materials with no ambient reflection.
 *  The second row has materials with significant ambient reflection.
 *  The third row has materials with colored ambient reflection.
 *
 *  The first column has materials with blue, diffuse reflection only.
 *  The second column has blue diffuse reflection, as well as specular
 *  reflection with a low shininess exponent.
 *  The third column has blue diffuse reflection, as well as specular
 *  reflection with a high shininess exponent (a more concentrated highlight).
 *  The fourth column has materials which also include an emissive component.
 *
 *  glTranslatef() is used to move spheres to their appropriate locations.
 */

void display(void)
{
   GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };
   GLfloat low_shininess[] = { 1.0 };
   GLfloat high_shininess[] = { 100.0 };
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

/*  draw sphere in first row, first column
 *  diffuse reflection only; no ambient or specular
 */
     glPushMatrix();
      glTranslatef (-3.75, 3.0, 0.0);
      glRotatef(_angle,1.0,0.0,0.0);
      GLfloat light_position1[] = {1.0, -1.30, 1.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
      GLfloat white_light1[] = { 1.0, 0.60, 0.0, 0.0 };

      glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light1);
      glLightfv(GL_LIGHT0, GL_SPECULAR, white_light1);
   /*glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);*/
   glutSolidSphere(1.0, 16, 16);
   glPopMatrix();




/*  draw sphere in first row, fourth column
 *  diffuse reflection; emission; no ambient or specular reflection
 */
   glPushMatrix();
     glTranslatef (3.75, 3.0, 0.0);
     glRotatef(_angle,1.0,0.0,1.0);
    GLfloat light_position2[] = {-1.0, -1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
   GLfloat white_light2[] = { 0.0, 1.0, 0.0, 0.0 };

      glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light2);
      glLightfv(GL_LIGHT0, GL_SPECULAR, white_light2);
   /*glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);*/
   glutSolidSphere(1.0, 16, 16);
   glPopMatrix();




/*  draw sphere in third row, first column
 *  colored ambient and diffuse reflection; no specular
 */
   glPushMatrix();
      glTranslatef (-3.75, -3.0, 0.0);
      glRotatef(_angle,0.0,0.0,1.0);
     GLfloat light_position3[] = {1.0, 1.0, 1.0, 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, light_position3);
     GLfloat white_light3[] = { 1.0, 0.0, 0.0, 0.0 };

      glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light3);
   glLightfv(GL_LIGHT0, GL_SPECULAR, white_light3);
   /*glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);*/
   glutSolidSphere(1.0, 16, 16);
   glPopMatrix();



/*  draw sphere in third row, fourth column
 *  colored ambient and diffuse reflection; emission; no specular
 */
      glPushMatrix();
      glTranslatef (3.75, -3.0, 0.0);
      glRotatef(_angle,0.0,1.0,0.0);
      GLfloat light_position4[] = {-1.0, 1.0, 1.0, 0.0 };
      glLightfv(GL_LIGHT0, GL_POSITION, light_position4);
      GLfloat white_light4[] = { 1.5, 1.0, 2.0, 0.0 };

      glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light4);
      glLightfv(GL_LIGHT0, GL_SPECULAR, white_light4);
   /*glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);*/
   glutSolidSphere(1.0, 16, 16);
   glPopMatrix();

   glFlush();
}

void reshape(int w, int h)
{
   glViewport(0, 0, w, h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   if (w <= (h * 2))
      glOrtho (-6.0, 6.0, -3.0*((GLfloat)h*2)/(GLfloat)w,
         3.0*((GLfloat)h*2)/(GLfloat)w, -10.0, 10.0);
   else
      glOrtho (-6.0*(GLfloat)w/((GLfloat)h*2),
         6.0*(GLfloat)w/((GLfloat)h*2), -3.0, 3.0, -10.0, 10.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)
{
   switch (key) {
      case 27:
         exit(0);
         break;
   }
}

void update(int value){
_angle += 2.0f;
if(_angle > 360){
    _angle -= 360;
}
_angle_tri += 2.0f;
if(_angle_tri > 360){
        _angle_tri -= 360;

}
glutPostRedisplay();
glutTimerFunc(25, update ,0);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (600, 450);
   glutCreateWindow(argv[0]);
   init();
   glutTimerFunc(25, update ,0);
   glutReshapeFunc(reshape);
   glutDisplayFunc(display);
   glutKeyboardFunc (keyboard);
   glutMainLoop();
   return 0;
}
