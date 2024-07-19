/**********************************
  
  The reader of this program should not limit
  himself/herself to the comments of this 
  program.

  If one wants to read more about the syntax and 
  the semantics of OpenGL functions used in this
  program, one should read the beginning of the
  paragraph 2.6 "Begin/End Paradigm", the 
  paragraph 2.6.1 "Begin and End Objects" from the 
  file glspec15.pdf at page 25/333 and the index
  from the end of that file. One could also
  read the references to the GLUT functions from
  the file glut-3.spec.pdf.
  


  H O W  T O  R E A D  T H I S  P R O G R A M ?
  
  Start from the function "main" and follow the 
  instruction flow, paying attention to the fact that
  this program belongs to the event-driven programming
  paradigm. So pay attention to what happens when 
  the user presses a key, moves the mouse or presses a
  mouse button. There are also some special events: the
  redrawing of the application window, etc.
  Identify what happens in the program when one of these
  events occurs.

  **********************************/


/**********************************
  With respect to the include-file directives, see the 
  example program from homework 1; in the following it
  was made the assumption that you are using GLUT locally,
  in your project and you didn't install it as an
  Administrator
  **********************************/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "glut.h"

// the size of the window measured in pixels
#define dim 300

const float PI = 3.14159265359f;

unsigned char prevKey;

// the graph of the Conchoid of Nicomedes
void Display1() {
   double xmax, ymax, xmin, ymin;
   double a = 1, b = 2;
   double pi = 4 * atan(1.0);
   double ratia = 0.05;
   double t;

   /**********************************
      Maximum/minimum values of x and y are computed.
      These values will be further used in scaling the
      original graph of the curve. 
      These values are stored in the variables
      xmax, ymax, xmin, ymin: e.g., xmax is initialized
      with a value smaller than any of possible values
      of x; if in doubt or you cannot estimate it, use 
      DBL_MIN instead (or DBL_MAX for minimum values).
      These DBL_* constants are found in <float.h> which
      need to be included.
      E.g., xmax is initialized with a - b - 1 because
      x(t) = a +/- b * cos(t) and for t in (-pi/2, pi/2),
      cos(t) is in (0, 1), so b * cos(t) is in (0, b),
      so +/- b * cos(t) is in (-b, b), so x(t) is in
      (a-b, a+b) and one can safely choose a-b-1 because
      a-b-1 < a-b. 
      For y(t) we see that in its expression appears
      tan(t) which varies in (-inf,+inf) when t
      varies in (-pi/2, pi/2).
     **********************************/
   xmax = a - b - 1; 
   xmin = a + b + 1;
   ymax = ymin = 0;
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = a + b * cos(t);
      xmax = (xmax < x1) ? x1 : xmax;
      xmin = (xmin > x1) ? x1 : xmin;

      x2 = a - b * cos(t);
      xmax = (xmax < x2) ? x2 : xmax;
      xmin = (xmin > x2) ? x2 : xmin;

      y1 = a * tan(t) + b * sin(t);
      ymax = (ymax < y1) ? y1 : ymax;
      ymin = (ymin > y1) ? y1 : ymin;

      y2 = a * tan(t) - b * sin(t);
      ymax = (ymax < y2) ? y2 : ymax;
      ymin = (ymin > y2) ? y2 : ymin;
   }

   /**********************************
      At this line, we have found that the graph of the Conchoid
      is included in the rectangle having the edges x = xmin,
      x = xmax, y = ymin and y = ymax. 
      We would like that the rectangle should be symmetric with
      respect to the Ox and Oy axes.
      We store in xmax and ymax the maximum of absolute values
      max(|xmax|,|xmin|) and max(|ymax|,|ymin|).
      Now we know that the graph of the Conchoid is included in
      the rectangle [-xmax, xmax] x [-ymax, ymax].
     **********************************/

   xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
   ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

   /**********************************
      At this line, we can perform the scaling. All the points
      scaled are visible (i.e., in the rectangle [-1,1]x[-1,1]).
      Because we have -xmax <= x <= xmax we get
      -1 <= x / xmax <= 1. Idem for y.
      In order to correctly display the graph of the Conchoid,
      one should use the exact same points that were used in
      the computation of the scaling factor.
     **********************************/

   glColor3f(1,0.1,0.1); // rosu
   glBegin(GL_LINE_STRIP); 
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = (a + b * cos(t)) / xmax;
      x2 = (a - b * cos(t)) / xmax;
      y1 = (a * tan(t) + b * sin(t)) / ymax;
      y2 = (a * tan(t) - b * sin(t)) / ymax;

      glVertex2f(x1,y1);
   }
   glEnd();

   glBegin(GL_LINE_STRIP); 
   for (t = - pi/2 + ratia; t < pi / 2; t += ratia) {
      double x1, y1, x2, y2;
      x1 = (a + b * cos(t)) / xmax;
      x2 = (a - b * cos(t)) / xmax;
      y1 = (a * tan(t) + b * sin(t)) / ymax;
      y2 = (a * tan(t) - b * sin(t)) / ymax;

      glVertex2f(x2,y2);
   }
   glEnd();
}

// The graph of the function 
// $f(x) = \bar sin(x) \bar \cdot e^{-sin(x)}, x \in \langle 0, 8 \cdot \pi \rangle$, 
void Display2() {
   double pi = 4 * atan(1.0);
   double xmax = 8 * pi;
   double ymax = exp(1.1);
   double ratia = 0.05;


   /**********************************
      For this example, the computation of the scaling factors
      is not needed. Because x is in the interval [0, 8pi]
      the scaling factor for x is 8pi because x/(8pi) is in
      [0,1]. In the case of the exponential function we know
      that if x is [0,8pi] then sin x is in [-1,1] so
      e^(-sin x) is in [1/e, e] and thus it is safe to use 
      e^(1.1) as a scaling factor.
     **********************************/
   glColor3f(1,0.1,0.1); // rosu
   glBegin(GL_LINE_STRIP); 
   for (double x = 0; x < xmax; x += ratia) {
      double x1, y1;
      x1 = x / xmax;
      y1 = (fabs(sin(x)) * exp(-sin(x))) / ymax;

      glVertex2f(x1,y1);
   }
   glEnd();
}

float d(float x) {
    return x == 0 ? 1 : fabs(x - floor(x + 0.5)) / x;
}

void Display3() {
    double xmax = 100;
    double ymax = 1;
    glColor3f(1.0f, 0.0f, 0.0f); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = 0; x <= xmax; x += 0.25f) {
        double y = d(x);
        glVertex2f(x / 100, y);
    }
    glEnd();
}

void Display4() {
    float a = 0.2;
    float xStart = -0.99;
    float yStart = 0.99;
    int index = 0;
    glColor3f(1, 0.1, 0.1);
    glBegin(GL_TRIANGLES);
    glVertex2f(xStart, yStart);
    for (float t = -PI / 2 + 0.002; t < -PI / 6; t += 0.002f, index++) {

        float x = a / (4 * pow(cos(t), 2) - 3);
        float y = a * tan(t) / (4 * pow(cos(t), 2) - 3);
        float new_x = a / (4 * pow(cos(t + 0.002), 2) - 3);
        float new_y = a * tan(t + 0.002) / (4 * pow(cos(t + 0.002), 2) - 3);
        if (index % 4 == 2 && x >= xStart && y <= yStart && y > 0.25) {

            glVertex2f(x, y);
            glVertex2f(new_x, new_y);
            glVertex2d(xStart, yStart);
        }
    }
    glEnd();

    glColor3f(0.1, 0.1, 0.1);
    glBegin(GL_LINE_LOOP);

    glVertex2f(xStart, yStart);
    glVertex2f(a / (4 * cos(-PI / 2) * cos(-PI / 2) - 3), yStart);

    for (float t = -PI / 2 + 0.002; t < -PI / 6; t += 0.002f) {
        float x = a / (4 * pow(cos(t), 2) - 3);
        float y = a * tan(t) / (4 * pow(cos(t), 2) - 3);
        if (x >= xStart && y <= yStart) {
            glVertex2f(x, y);
        }

    }

    glEnd();

    glRasterPos2d(-0.9, -0.4);
    const char* message = "The trisectrix of Longchamps";
    for (const char* c = message; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    char buffer[50];
    sprintf(buffer, "a = %.1f", a);
    glRasterPos2d(-0.9, -0.5);
    for (const char* c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

}

void Display5() {
    double a = 0.1f;
    double b = 0.2f;
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 0.1, 0.1);
    for (float t = -10 * PI; t <= 10 * PI; t += 0.01f) {
        float x = a * t - b * sin(t);
        float y = a - b * cos(t);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.1, 0.1, 0.1);

    glRasterPos2d(-0.9, -0.4);
    const char* message = "The cycloid";
    for (const char* c = message; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    char buffer[50];
    sprintf(buffer, "a = %.1f", a);
    glRasterPos2d(-0.9, -0.5);
    for (const char* c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    sprintf(buffer, "b = %.1f", b);
    glRasterPos2d(-0.9, -0.6);
    for (const char* c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}

void Display6() {
    float a = 0.4f;
    glBegin(GL_LINE_STRIP);
    glColor3f(1, 0.1, 0.1);

    for (float t = -PI / 4; t <= PI / 4; t += 0.01f) {
        float r1 = a * sqrt(2 * cos(2 * t));
        float x1 = r1 * cos(t);
        float y1 = r1 * sin(t);
        glVertex2f(x1, y1);
    }

    for (float t = PI / 4 - 0.002; t > -PI / 4; t -= 0.002) {
        float r2 = -a * sqrt(2 * cos(2 * t));
        float x2 = r2 * cos(t);
        float y2 = r2 * sin(t);
        glVertex2f(x2, y2);
    }
    glEnd();

    glColor3f(0.1, 0.1, 0.1);

    glRasterPos2d(-0.9, -0.4);
    const char* message = "The lemniscate of Bernoulli";
    for (const char* c = message; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    char buffer[50];
    sprintf(buffer, "a = %.1f", a);
    glRasterPos2d(-0.9, -0.5);
    for (const char* c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}

void Display7() {
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    float a = 0.02;
    for (float t = 0; t <= 3 * PI; t += 0.01f) {
        float r = a * exp(1 + t);
        float x = r * cos(t);
        float y = r * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    glColor3f(0.1, 0.1, 0.1);

    glRasterPos2d(-0.9, -0.4);
    const char* message = "The logarithmic spiral";
    for (const char* c = message; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }

    char buffer[50];
    sprintf(buffer, "a = %.2f", a);
    glRasterPos2d(-0.9, -0.5);
    for (const char* c = buffer; *c != '\0'; c++) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *c);
    }
}

void Init(void) {

   glClearColor(1.0,1.0,1.0,1.0);

   glLineWidth(1);

//   glPointSize(4);

   glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
   glClear(GL_COLOR_BUFFER_BIT);

   switch(prevKey) {
   case '1':
      Display1();
      break;
   case '2':
      Display2();
      break;
   case '3':
      Display3();
      break;
   case '4': 
      Display4();
      break;
   case '5':
      Display5();
      break;
   case '6':
      Display6();
      break;
   case '7':
      Display7();
      break;
   default:
      break;
   }

   glFlush();
}

void Reshape(int w, int h) {
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
   prevKey = key;
   if (key == 27) // escape
      exit(0);
   glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   
   glutInitWindowSize(dim, dim);

   glutInitWindowPosition(100, 100);

   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

   glutCreateWindow (argv[0]);

   Init();

   glutReshapeFunc(Reshape);
   
   glutKeyboardFunc(KeyboardFunc);
   
   glutMouseFunc(MouseFunc);

   glutDisplayFunc(Display);
   
   glutMainLoop();

   return 0;
}
