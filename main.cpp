#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include<windows.h>
#include<mmsystem.h>
#include <stdio.h>


GLfloat position = 0.0f;
GLfloat speed = 0.1f;

GLfloat position1 = 0.0f;
GLfloat speed1 = 0.01f;

GLfloat position2 = 0.0f;
GLfloat speed2 = 0.1f;

GLfloat position3 = 0.0f;
GLfloat speed3 = 0.006f;

GLfloat position4 = 0.0f;
GLfloat speed4 = 0.1f;


bool rainday = false;
GLfloat positionRain = 0.0f;
GLfloat speedRain = 0.03f;

float sr=1.0, sg=1.0, sb=0.0;
float skyr=0.0, skyg=0.5, skyb=1.0;
float skyr1=0.0, skyg1=0.5, skyb1=1.0;

char text[] = "School";

//==============================Update=====================================


void update(int value) {

    if(position > 1.3)
        position = -1.2f;

    position += speed;

	glutPostRedisplay();


	glutTimerFunc(100, update, 0);
}

void update1(int value) {

    if(position1 > 1.3)
        position1 = -1.0f;

    position1 += speed1;

	glutPostRedisplay();


	glutTimerFunc(100, update1, 0);
}
void update2(int value) {

    if(position2 > 1.6)
        position2 = -1.0f;

    position2 += speed2;

	glutPostRedisplay();


	glutTimerFunc(100, update2, 0);
}

void update3(int value) {

    if(position3 > 1.7)
        position3 = -1.1f;

    position3 += speed3;

	glutPostRedisplay();


	glutTimerFunc(100, update3, 0);
}

void update4(int value) {

    if(position4 > 1.6)
        position4 = -1.0f;

    position4 += speed4;

	glutPostRedisplay();


	glutTimerFunc(100, update4, 0);
}
//=================================================================================


//====================================School Name==================================


void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(0.0f,0.0f,0.0f);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]);

    }
}

//====================================================================================


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);

}


//==================================Rain============================================
void Rain(){

  glPushMatrix();
  glTranslatef(0.0f, -positionRain, 0.0f);
    if(rainday){
  glPushMatrix();
  glTranslatef(0.0, 0.5f, 0.0f);

    GLfloat xR= -1.0f;
    GLfloat yR = 1.0f;

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f,1.0f);
    for(int i=0;i<=100;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-0.02f,yR-0.07f);

    xR += .03f;
    }
    glEnd();

    for(int j=0;j<=100;j++)
    {
    xR = -1.0f;
    yR= yR-0.10f;
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    for(int i=0;i<=250;i++){

    glVertex2f(xR,yR);
    glVertex2f(xR-.02f,yR-.07f);

    xR += .03f;
    }
    glEnd();
    }
  glPopMatrix();
    }
  glPopMatrix();
}
void updateRain(int value) {
    if(positionRain >.14)
        {positionRain = 0.0f;}

    positionRain += speedRain;

	glutPostRedisplay();

	glutTimerFunc(100, updateRain, 0);
}

//========================================================================================


//================================Handel Mouse============================================


void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed += 0.1f;
			speed1 += 0.01f;
            speed3 += 0.006f;
            speed4 += 0.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}

//======================================================================


//==================================Morning, Night Sound============================
void morningSound()
{
    sndPlaySound("morning.wav",SND_ASYNC|SND_LOOP);
}
void nightSound()
{
    sndPlaySound("night.wav",SND_ASYNC|SND_LOOP);
}

//=============================================================================


//===========================Handle KeyPress=====================================


void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'a':
    speed = 0.0f;
    speed1= 0.0f;
    speed2= 0.0f;
    speed3= 0.0f;
    speed4= 0.0f;
    break;
case 'w':
    speed = 0.1f;
    speed1= 0.01f;
    speed2= 0.1f;
    speed3= 0.006f;
    speed4= 0.1f;
    break;
glutPostRedisplay();

case 'n':
    skyr=0.0;
    skyg=0.0;
    skyb=0.2;

    skyr1=1.0;
    skyg1=1.0;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=1.0;
    break;
glutPostRedisplay();

case 'N':
    skyr=0.0;
    skyg=0.0;
    skyb=0.2;

    skyr1=1.0;
    skyg1=1.0;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=1.0;
    break;
glutPostRedisplay();

case 'd':
    skyr=0.0;
    skyg=0.5;
    skyb=1.0;

    skyr1=0.0;
    skyg1=0.5;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=0.0;
    break;
glutPostRedisplay();

case 'D':
    skyr=0.0;
    skyg=0.5;
    skyb=1.0;

    skyr1=0.0;
    skyg1=0.5;
    skyb1=1.0;

    sr=1.0;
    sg=1.0;
    sb=0.0;
    break;
glutPostRedisplay();

case '1':
    morningSound();
    break;
glutPostRedisplay();

case '2':
    nightSound();
    break;
glutPostRedisplay();

case '3':
    sndPlaySound(NULL,SND_ASYNC);
    break;
glutPostRedisplay();



case 'r':
        rainday = true;
        sndPlaySound("rain.wav",SND_ASYNC|SND_LOOP);
        //sndPlaySound("rain.wav",SND_MEMORY|SND_ASYNC);
        break;
    case 't':
        rainday = false;
        sndPlaySound(NULL,SND_ASYNC);
        break;
glutPostRedisplay();

	}
}
//======================================================================================

//==========================================Plane=========================================

void plane()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.4f, 0.0f);
        glVertex2f(0.65f, 0.9f);
        glVertex2f(0.87f, 0.9f);
        glVertex2f(0.9f, 0.85f);
        glVertex2f(0.6f, 0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.87f, 0.9f);
        glVertex2f(0.93f, 0.94f);
        glVertex2f(0.95f, 0.96f);
        glVertex2f(0.9f, 0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.74f, 0.9f);
        glVertex2f(0.76f, 0.96f);
        glVertex2f(0.79f, 0.98f);
        glVertex2f(0.78f, 0.9f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.74f, 0.85f);
        glVertex2f(0.76f, 0.78f);
        glVertex2f(0.79f, 0.76f);
        glVertex2f(0.78f, 0.85f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.65f, 0.885f);
        glVertex2f(0.68f, 0.885f);
        glVertex2f(0.68f, 0.868f);
        glVertex2f(0.65f, 0.868f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.7f, 0.885f);
        glVertex2f(0.73f, 0.885f);
        glVertex2f(0.73f, 0.868f);
        glVertex2f(0.7f, 0.868f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.75f, 0.885f);
        glVertex2f(0.78f, 0.885f);
        glVertex2f(0.78f, 0.868f);
        glVertex2f(0.75f, 0.868f);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2f(0.8f, 0.885f);
        glVertex2f(0.83f, 0.885f);
        glVertex2f(0.83f, 0.868f);
        glVertex2f(0.8f, 0.868f);
    glEnd();
}

//===========================================Car & Bus==================================


void car(){

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.f);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.22f, -0.44f);
    glVertex2f(-0.22f, -0.5f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, -0.44f);
    glVertex2f(-0.45f, -0.39f);
    glVertex2f(-0.3f, -0.39f);
    glVertex2f(-0.25f, -0.44f);
    glEnd();

}

void bus()
{
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(0.63f, -0.15f);
    glVertex2f(0.8f, -0.15f);
    glVertex2f(0.8f, -0.29f);
    glVertex2f(0.6f, -0.29f);
    glVertex2f(0.6f, -0.22f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.6f, -0.22f);
    glVertex2f(0.63f, -0.15);
    glVertex2f(0.63f, -0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.64f, -0.17f);
    glVertex2f(0.67f, -0.17);
    glVertex2f(0.67f, -0.235f);
    glVertex2f(0.64f, -0.235f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.66f, -0.17f);
    glVertex2f(0.68f, -0.17);
    glVertex2f(0.68f, -0.255f);
    glVertex2f(0.66f, -0.255f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.685f, -0.17f);
    glVertex2f(0.715f, -0.17);
    glVertex2f(0.715f, -0.22f);
    glVertex2f(0.685f, -0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.718f, -0.17f);
    glVertex2f(0.75f, -0.17);
    glVertex2f(0.75f, -0.22f);
    glVertex2f(0.718f, -0.22f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2f(0.752f, -0.17f);
    glVertex2f(0.795f, -0.17);
    glVertex2f(0.795f, -0.22f);
    glVertex2f(0.752f, -0.22f);
    glEnd();
}
//================================================================


//=================================Circle==========================


void circle()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.02;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void circle1()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.003;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void circle2()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.03;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

void circle3()
{
    glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
        {

            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=0.01;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x,y );
        }
	glEnd();
}

//=================================================================


//=========================Bus & Car Wheel==================================


void wheel()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.45f, -0.5f, 0.0f);
    circle();
	glPopMatrix();

	glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(-0.29f, -0.5f, 0.0f);
    circle();
	glPopMatrix();
}

void busWheel()
{
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.65f, -0.29f, 0.0f);
    circle();
	glPopMatrix();


	glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glTranslatef(0.75f, -0.29f, 0.0f);
    circle();
	glPopMatrix();
}

//===============================================================================


//===================================Flag Circle====================================
void flag()
{
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);
    glTranslatef(0.73f, 0.235f, 0.0f);
    circle2();
	glPopMatrix();
}

//===============================================================================


//=================================Cloud=========================================


void cloud()
{
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.9f, 0.89f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.82f, 0.87f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.88f, 0.81f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

    glPushMatrix();
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(-0.8f, 0.79f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();
}

//====================================================================


//=========================Tree Code===================================


void tree()
{
//Tree Code
//Left Side Tree
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.0, 0.4, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.6, -0.4, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();

glTranslatef(0.0, 0.45, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();


glTranslatef(1.2, -0.23, 0.0);
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.6f);
    glVertex2f(-0.9f, 0.05f);
    glVertex2f(-0.89f, 0.05f);
    glVertex2f(-0.89f, -0.08f);
    glVertex2f(-0.9f, -0.08f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.1f);
    glVertex2f(-0.82f, 0.0f);
    glVertex2f(-0.97f, 0.0f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(-0.895f, 0.17f);
    glVertex2f(-0.8f, 0.05f);
    glVertex2f(-0.99f, 0.05f);
glEnd();
}

//==============================================================


//==============================Display=========================
void display() {
    glClearColor(0.0f, 0.7f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

//===================Sky Code=============================

glBegin(GL_QUADS);
    glColor3f(skyr, skyg, skyb);
    glVertex2f(-1.0f, 1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(1.0f, 0.6f);
    glVertex2f(-1.0f, 0.6f);
glEnd();

//==================================================

//=====================SUN CODE===============================

glPushMatrix();
    glColor3f(sr, sg, sb);
    glTranslatef(-0.25f, 0.9f, 0.0f);
    glBegin(GL_POLYGON);
        for(int i=0;i<200;i++)
            {

                float pi=3.1416;
                float A=(i*2*pi)/200;
                float r=0.07;
                float x = r * cos(A);
                float y = r * sin(A);
                glVertex2f(x,y );
            }
	glEnd();
glPopMatrix();

//===========================Star Code=================================

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.8f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.9f, 0.84f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.97f, 0.74f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.6f, 0.93f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.69f, 0.86f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.73f, 0.98f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.66f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.55f, 0.71f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.4f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.45f, 0.85f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.3f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.2f, 0.77f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.17f, 0.668f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(-0.1f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.0f, 0.64f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.8f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.9f, 0.84f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.97f, 0.74f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.6f, 0.93f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.69f, 0.86f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.73f, 0.98f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.66f, 0.8f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.55f, 0.71f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.4f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.45f, 0.85f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.3f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.2f, 0.63f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.2f, 0.75f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.1f, 0.9f, 0.0f);
    circle1();
glPopMatrix();

glPushMatrix();
    glColor3f(skyr1, skyg1, skyb1);
    glTranslatef(0.8f, 0.629f, 0.0f);
    circle1();
glPopMatrix();

//=========================================================

//================================Hill Code================
//Left side
//HILL CODE 1
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.8f, 0.75f);
    glVertex2f(-0.7f, 0.6f);
    glVertex2f(-0.9f, 0.6f);
glEnd();

//HILL CODE 2
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.7f, 0.75f);
    glVertex2f(-0.6f, 0.6f);
    glVertex2f(-0.8f, 0.6f);
glEnd();

//HILL CODE 3
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(-0.6f, 0.75f);
    glVertex2f(-0.5f, 0.6f);
    glVertex2f(-0.7f, 0.6f);
glEnd();


//Right side
//HILL CODE 4
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.8f, 0.75f);
    glVertex2f(0.7f, 0.6f);
    glVertex2f(0.9f, 0.6f);
glEnd();

//HILL CODE 5
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.7f, 0.75f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.8f, 0.6f);
glEnd();

//HILL CODE 6
glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.0f);
    glVertex2f(0.6f, 0.75f);
    glVertex2f(0.5f, 0.6f);
    glVertex2f(0.7f, 0.6f);
glEnd();
//=============================================

//=====================ROAD CODE========================

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(-1.0f, -0.6f);
glEnd();

//********************
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.1f);
    glVertex2f(-0.9f, -0.1f);
    glVertex2f(-0.9f, -0.12f);
    glVertex2f(-1.0f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.9f, -0.1f);
    glVertex2f(-0.7f, -0.1f);
    glVertex2f(-0.7f, -0.12f);
    glVertex2f(-0.9f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.7f, -0.1f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.5f, -0.12f);
    glVertex2f(-0.7f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.5f, -0.1f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(-0.2f, -0.12f);
    glVertex2f(-0.5f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.1f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.0f, -0.12f);
    glVertex2f(-0.2f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, -0.1f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.2f, -0.12f);
    glVertex2f(0.0f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.1f);
    glVertex2f(0.45f, -0.1f);
    glVertex2f(0.45f, -0.12f);
    glVertex2f(0.2f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.45f, -0.1f);
    glVertex2f(0.7f, -0.1f);
    glVertex2f(0.7f, -0.12f);
    glVertex2f(0.45f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.7f, -0.1f);
    glVertex2f(0.88f, -0.1f);
    glVertex2f(0.88f, -0.12f);
    glVertex2f(0.7f, -0.12f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.88f, -0.1f);
    glVertex2f(1.0f, -0.1f);
    glVertex2f(1.0f, -0.12f);
    glVertex2f(0.88f, -0.12f);
glEnd();
//********************************

//********************
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.9f, -0.58f);
    glVertex2f(-1.0f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.9f, -0.6f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.7f, -0.58f);
    glVertex2f(-0.9f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.5f, -0.58f);
    glVertex2f(-0.7f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(-0.5f, -0.6f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(-0.2f, -0.58f);
    glVertex2f(-0.5f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.2f, -0.6f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.0f, -0.58f);
    glVertex2f(-0.2f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.0f, -0.6f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.2f, -0.58f);
    glVertex2f(0.0f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.2f, -0.6f);
    glVertex2f(0.45f, -0.6f);
    glVertex2f(0.45f, -0.58f);
    glVertex2f(0.2f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.45f, -0.6f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.7f, -0.58f);
    glVertex2f(0.45f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.7f, -0.6f);
    glVertex2f(0.88f, -0.6f);
    glVertex2f(0.88f, -0.58f);
    glVertex2f(0.7f, -0.58f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.4f, 0.4f, 0.4f);
    glVertex2f(0.88f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -0.58f);
    glVertex2f(0.88f, -0.58f);
glEnd();
//********************************

//Road white color right side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.3f, -0.35f);
    glVertex2f(0.6f, -0.35f);
    glVertex2f(0.6f, -0.36f);
    glVertex2f(0.3f, -0.36f);
glEnd();


//Road white color middle side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.3f, -0.35f);
    glVertex2f(0.0f, -0.35f);
    glVertex2f(0.0f, -0.36f);
    glVertex2f(-0.3f, -0.36f);
glEnd();


//Road white color left side
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.9f, -0.35f);
    glVertex2f(-0.6f, -0.35f);
    glVertex2f(-0.6f, -0.36f);
    glVertex2f(-0.9f, -0.36f);
glEnd();
//================================================

//===================RIVER CODE=============================

glBegin(GL_QUADS);
    glColor3f(0.6f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -0.6f);
    glVertex2f(1.0f, -0.6f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
glEnd();
//================================================

//=====================SCHOOL CODE===========================
//School Roof
glBegin(GL_QUADS);
    glColor3f(0.9f, 1.0f, 0.0f);
    glVertex2f(-0.18f, 0.55f);
    glVertex2f(0.6f, 0.55f);
    glVertex2f(0.55f, 0.4);
    glVertex2f(-0.2f, 0.4f);
glEnd();

//School Text
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.1f, 0.49f);
    glVertex2f(0.3f, 0.49f);
    glVertex2f(0.3f, 0.4f);
    glVertex2f(0.1f, 0.4f);
glEnd();

glPushMatrix();
glTranslatef(0.27f, 0.42f, 0.0f);
Sprint(-0.12f, 0.0f, text);
glPopMatrix();
//End of Text


//School Right Side
glBegin(GL_QUADS);
    glColor3f(0.8f, 1.0f, 0.5f);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.6f, 0.55f);
    glVertex2f(0.6f, 0.05f);
    glVertex2f(0.55f, 0.0f);
glEnd();

//School Left Side
glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 0.5f);
    glVertex2f(-0.2f, 0.4f);
    glVertex2f(0.55f, 0.4f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(-0.2f, 0.0f);
glEnd();

//School Door
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.1f, 0.125f);
    glVertex2f(0.25f, 0.125f);
    glVertex2f(0.25f, 0.0f);
    glVertex2f(0.1f, 0.0f);
glEnd();


//School Window 1 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.15f, 0.35f);
    glVertex2f(-0.1f, 0.35f);
    glVertex2f(-0.1f, 0.28f);
    glVertex2f(-0.15f, 0.28f);
glEnd();

//School Window 2 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.05f, 0.35f);
    glVertex2f(0.0f, 0.35f);
    glVertex2f(0.0f, 0.28f);
    glVertex2f(-0.05f, 0.28f);
glEnd();


//School Window 3 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.05f, 0.35f);
    glVertex2f(0.1f, 0.35f);
    glVertex2f(0.1f, 0.28f);
    glVertex2f(0.05f, 0.28f);
glEnd();

//School Window 4 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.15f, 0.35f);
    glVertex2f(0.2f, 0.35f);
    glVertex2f(0.2f, 0.28f);
    glVertex2f(0.15f, 0.28f);
glEnd();

//School Window 5 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, 0.35f);
    glVertex2f(0.3f, 0.35f);
    glVertex2f(0.3f, 0.28f);
    glVertex2f(0.25f, 0.28f);
glEnd();


//School Window 6 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.35f, 0.35f);
    glVertex2f(0.4f, 0.35f);
    glVertex2f(0.4f, 0.28f);
    glVertex2f(0.35f, 0.28f);
glEnd();

//School Window 7 Top Floor
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f, 0.35f);
    glVertex2f(0.5f, 0.35f);
    glVertex2f(0.5f, 0.28f);
    glVertex2f(0.45f, 0.28f);
glEnd();

//School Window 1
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.15f, 0.25f);
    glVertex2f(-0.1f, 0.25f);
    glVertex2f(-0.1f, 0.18f);
    glVertex2f(-0.15f, 0.18f);
glEnd();

//School Window 2
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.05f, 0.25f);
    glVertex2f(0.0f, 0.25f);
    glVertex2f(0.0f, 0.18f);
    glVertex2f(-0.05f, 0.18f);
glEnd();


//School Window 3
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.05f, 0.25f);
    glVertex2f(0.1f, 0.25f);
    glVertex2f(0.1f, 0.18f);
    glVertex2f(0.05f, 0.18f);
glEnd();

//School Window 4
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.15f, 0.25f);
    glVertex2f(0.2f, 0.25f);
    glVertex2f(0.2f, 0.18f);
    glVertex2f(0.15f, 0.18f);
glEnd();

//School Window 5
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.3f, 0.25f);
    glVertex2f(0.3f, 0.18f);
    glVertex2f(0.25f, 0.18f);
glEnd();


//School Window 6
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.35f, 0.25f);
    glVertex2f(0.4f, 0.25f);
    glVertex2f(0.4f, 0.18f);
    glVertex2f(0.35f, 0.18f);
glEnd();

//School Window 7
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.45f, 0.25f);
    glVertex2f(0.5f, 0.25f);
    glVertex2f(0.5f, 0.18f);
    glVertex2f(0.45f, 0.18f);
glEnd();
//=======================================================

//Flag Code
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.66f, 0.31f);
    glVertex2f(0.67f, 0.31f);
    glVertex2f(0.67f, 0.0f);
    glVertex2f(0.66f, 0.0f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.0f, 0.2f, 0.0f);
    glVertex2f(0.67f, 0.3f);
    glVertex2f(0.8f, 0.3f);
    glVertex2f(0.8f, 0.17f);
    glVertex2f(0.67f, 0.17f);
glEnd();

//=======================================================

//==========================HOUSE CODE====================

glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.6f, 0.2f);
    glVertex2f(-0.7f, 0.2f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.6f, 0.0f, 0.9f);
    glVertex2f(-0.7f, 0.4f);
    glVertex2f(-0.65f, 0.52f);
    glVertex2f(-0.6f, 0.4f);
glEnd();

//Door Code

glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.4f);
    glVertex2f(-0.67f, 0.33f);
    glVertex2f(-0.63f, 0.33f);
    glVertex2f(-0.63f, 0.2f);
    glVertex2f(-0.67f, 0.2f);
glEnd();


glBegin(GL_QUADS);
    glColor3f(0.3f, 0.4f, 0.5f);
    glVertex2f(-0.65f, 0.52f);
    glVertex2f(-0.47f, 0.52f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.6f, 0.4f);
glEnd();

glBegin(GL_QUADS);
    glColor3f(0.1f, 0.3f, 0.3f);
    glVertex2f(-0.6f, 0.4f);
    glVertex2f(-0.4f, 0.4f);
    glVertex2f(-0.4f, 0.2f);
    glVertex2f(-0.6f, 0.2f);
glEnd();


//Window
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.58f, 0.37f);
    glVertex2f(-0.53f, 0.37f);
    glVertex2f(-0.53f, 0.3f);
    glVertex2f(-0.58f, 0.3f);
glEnd();

//Window L
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.49f, 0.37f);
    glVertex2f(-0.44f, 0.37f);
    glVertex2f(-0.44f, 0.3f);
    glVertex2f(-0.49f, 0.3f);
glEnd();
//=========================================


//=====================B0AT CODE================================
glPushMatrix();
glTranslatef(position1,0.0f, 0.0f);

glBegin(GL_QUADS);
    glColor3f(0.9f, 0.8f, 0.5f);
    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.4f, -0.8f);
    glVertex2f(-0.5f, -0.95f);
    glVertex2f(-0.7f, -0.95f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.6f, -0.625f);
    glVertex2f(-0.5f, -0.8f);
    glVertex2f(-0.6f, -0.8f);
glEnd();

glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-0.6f, -0.7f);
    glVertex2f(-0.6f, -0.8f);
    glVertex2f(-0.7f, -0.8f);
glEnd();

    glPopMatrix();

//============================================

    glPushMatrix();
        glTranslatef(position,0.0f, 0.0f);
        car();
        wheel();
    glPopMatrix();

    Rain();

    glPushMatrix();
        glTranslatef(position3,0.0f, 0.0f);
        cloud();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-position4,0.0f, 0.0f);
        bus();
        busWheel();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-position2,0.0f, 0.0f);
        plane();
    glPopMatrix();

    flag();
    tree();

    glutSwapBuffers();
    glFlush();
}
//=================================================================


int main(int argc, char** argv) {

   printf("\n\n******************Country Scene by a Highway****************\n\n");
   printf("Press N/n: For Night\n\n");
   printf("Press D/d: For Day\n\n");
   printf("Press r: For Rain\n\n");
   printf("Press t: For Rain Stop\n\n");
   printf("Press 1: For Morning Sound\n\n");
   printf("Press 2: For Night Sound\n\n");
   printf("Press 3: For Sound Stop\n\n");
   glutInit(&argc, argv);
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
   glutInitWindowSize(1000, 600);
   glutInitWindowPosition(50, 50);
   glutCreateWindow("Country Scene by a Highway");
   glutDisplayFunc(display);
   init();
   glutKeyboardFunc(handleKeypress);
   glutMouseFunc(handleMouse);
   glutTimerFunc(100, update, 0);
   glutTimerFunc(100, update1, 0);
   glutTimerFunc(100, update2, 0);
   glutTimerFunc(100, update3, 0);
   glutTimerFunc(100, update4, 0);
   glutTimerFunc(100, updateRain, 0);
   glutMainLoop();
   return 0;
}
