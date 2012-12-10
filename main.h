#ifndef __main_h__
#define __main_h__

#include<stdlib.h>
#include<gl/glut.h>
#include<gl/gl.h>
#include<gl/glu.h>
#include<windows.h>
#include <GL/glaux.h>
#include<stdio.h>
#include<iostream>

#pragma comment (lib,"opengl32.lib")
#pragma comment (lib,"glu32.lib")
#pragma comment (lib, "glaux.lib")

#define AIM_RED 0
#define AIM_GREEN 1
#define AIM_BLUE 0

using namespace std;

AUX_RGBImageRec *cover_hght;
GLuint texture[1];
int width = 800, height = 480;

void DisplayAim(int xa, int ya);
void RenderCommandScene(void);
void RenderLogScene(void);
AUX_RGBImageRec *LoadBMP(char *Filename);

bool AskMode(void); // true => command mode; false => log mode

#endif