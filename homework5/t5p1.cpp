﻿#include <stdlib.h>
#include <stdio.h>

#define _USE_MATH_DEFINES
#include <math.h>

#include "glut.h"

// the size of the window measured in pixels
#define dim 300

unsigned char prevKey;

enum EObiect {cubw, cubs, sferaw, sferas, tri} ob = cubw;

typedef struct {
    float x, y, z;
} Punct3D;

Punct3D P1 = { 0.0f, 0.0f, 0.0f };


void DisplayAxe() {
  int X, Y, Z;
  X = Y = 200;
  Z = 200;

  glLineWidth(2);

  // Ox axis - green
  glColor3f(0, 1, 0);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(X,0,0);
  glEnd();

  // Oy axis - blue
  glColor3f(0, 0, 1);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(0,Y,0);
  glEnd();

  // Oz axis - red
  glColor3f(1, 0, 0);
  glBegin(GL_LINE_STRIP); 
    glVertex3f(0,0,0);
    glVertex3f(0,0,Z);
  glEnd();

  glLineWidth(1);
}

void drawTriangle() {
    glColor3f(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(P1.x, P1.y, P1.z);
    glVertex3f(P1.x + 1, P1.y, P1.z);
    glVertex3f(P1.x, P1.y + 1, P1.z);
    glEnd();
}

// wireframe cube
void Display1() {
   glColor3f(1,0,0);
   glutWireCube(1);
}

// solid cube
void Display2() {
   glColor3f(1,0,0);
   glutSolidCube(1);
}

// wireframe sphere
void Display3() {
   glColor3f(0,0,1);
   glutWireSphere(1, 10, 10);
}

// solid sphere
void Display4() {
   glColor3f(0,0,1);
   glutSolidSphere(1, 10, 10);
}

void Display5() {
    glColor3f(1,0,0);
    drawTriangle();
}

void DisplayObiect()
{
  switch (ob)
  {
  case cubw:
    Display1();
    break;
  case cubs:
    Display2();
    break;
  case sferaw:
    Display3();
    break;
  case sferas:
    Display4();
    break;
  case tri:
    Display5();
    break;
  default:
    break;
  }
}

// the rotation with 10 degrees about the Ox axis
void DisplayX() {
  glMatrixMode(GL_MODELVIEW);
  glRotated(10,1,0,0);
}

// the rotation with 10 degrees about the Oy axis
void DisplayY() {
  glMatrixMode(GL_MODELVIEW);
  glRotated(10,0,1,0);
}

// the rotation with 10 degrees about the Oz axis
void DisplayZ() {
  glMatrixMode(GL_MODELVIEW);
  glRotated(10,0,0,1);
}

// translation by 0.2, 0.2, 0.2
void DisplayT() {
  glMatrixMode(GL_MODELVIEW);
  glTranslatef(0.2, 0.2, 0.2);
}

// scaling by 1.2, 1.2, 1.2
void DisplayS() {
  glMatrixMode(GL_MODELVIEW);
  glScalef(1.2, 1.2, 1.2);
}

void Init(void) {
  glClearColor(1, 1, 1, 1);
  glLineWidth(2);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-10, 10, -10, 10, 30, -30);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glRotated(20, 1, 0, 0);
  glRotated(-20, 0, 1, 0);
}

void Display(void) {
  switch(prevKey) 
  {
  case 'a':
    DisplayAxe();
    break;
  case '0':
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotated(20, 1, 0, 0);
    glRotated(-20, 0, 1, 0);
    break;
  case '1':
    Display1();
    ob = cubw;
    break;
  case '2':
    Display2();
    ob = cubs;
    break;
  case '3':
    Display3();
    ob = sferaw;
    break;
  case '4':
    Display4();
    ob = sferas;
    break;
  case '5':
    Display5();
    ob = tri;
  case 'x':
    glClear(GL_COLOR_BUFFER_BIT);
    DisplayX();
    DisplayAxe();
    DisplayObiect();
    break;
  case 'y':
    glClear(GL_COLOR_BUFFER_BIT);
    DisplayY();
    DisplayAxe();
    DisplayObiect();
    break;
  case 'z':
    glClear(GL_COLOR_BUFFER_BIT);
    DisplayZ();
    DisplayAxe();
    DisplayObiect();
    break;
  case 't':
    glClear(GL_COLOR_BUFFER_BIT);
    DisplayT();
    DisplayAxe();
    DisplayObiect();
    break;
  case 's':
    glClear(GL_COLOR_BUFFER_BIT);
    DisplayS();
    DisplayAxe();
    DisplayObiect();
    break;
  case 'r':
  {
      glClear(GL_COLOR_BUFFER_BIT);
      // Vectorul diagonalei principale
      float diag[] = { 1, 1, 1 };
      // Unghiul de rotație N
      float N = 45/* valoarea unghiului de rotație dată în enunț */;
      // Normalizarea vectorului diag
      float length = sqrt(diag[0] * diag[0] + diag[1] * diag[1] + diag[2] * diag[2]);
      float axis[] = { diag[0] / length, diag[1] / length, diag[2] / length };
      // Convertirea unghiului în radiani
      float radians = N * M_PI / 180;
      glPushMatrix();
      // Calcularea compoziției de rotații pentru a obține rotația dorită în jurul direcției diagonalei principale
      // Rotirea în jurul axei Ox
      glRotated(-45, 0, 1, 1);
      // Rotirea în jurul axei Oy
      glRotated(atan(sqrt(2)), 0, 1, 0);
      // Rotirea cu unghiul dat în jurul axei definite de direcția diagonalei principale
      glRotated(N, axis[0], axis[1], axis[2]);
      // Rotirea inversă a celei de-a doua rotații în jurul axei Oy
      glRotated(-atan(sqrt(2)), 0, 1, 0);
      // Rotirea inversă a primei rotații în jurul axei Ox
      glRotated(45, 0, 1, 1);
      DisplayObiect();
      glPopMatrix();
      DisplayAxe();
      break;
  }
  default:
    break;
  }
  glutSwapBuffers();
}

void Reshape(int w, int h) {
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
   prevKey = key;
   if (key == 27)
      exit(0);
   glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

   glutInit(&argc, argv);
   
   glutInitWindowSize(dim, dim);

   glutInitWindowPosition(100, 100);

   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

   glutCreateWindow (argv[0]);

   Init();

   glutReshapeFunc(Reshape);
   
   glutKeyboardFunc(KeyboardFunc);
   
   glutMouseFunc(MouseFunc);

   glutDisplayFunc(Display);
   
   glutMainLoop();

   return 0;
}
