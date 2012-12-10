#include "main.h"

AUX_RGBImageRec *LoadBMP(char *Filename){
	FILE *File=NULL;
	if (!Filename){
        return NULL;
    }
    File=fopen(Filename,"r");
    if (File){
        fclose(File);
        return auxDIBImageLoad(Filename);
    }
    return NULL;
}


void RenderCommandScene(void){

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRasterPos2i(-1,-1);
	glPixelZoom(1,1);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glDrawPixels(cover_hght->sizeX, cover_hght->sizeY, GL_RGB, GL_UNSIGNED_BYTE, cover_hght->data);
	glFinish();
	


	DisplayAim(100, 100); //TODO: ask aim destination
	glutSwapBuffers();
}


void DisplayAim(int xa, int ya){
	glPushMatrix();
	gluOrtho2D(0, width-1, 0, height-1);
	glColor3f(AIM_RED, AIM_GREEN, AIM_BLUE);
	glBegin(GL_POINTS);
		glVertex2f(xa, ya);
	glEnd();
	glPopMatrix();
}

bool AskMode(void){
	switch (MessageBox(NULL, "OK - принимаем команды; Cancel - пишем в лог", "Confirm", MB_OKCANCEL | MB_ICONQUESTION)) {
	case IDOK:{
		return true;
			  }
	case IDCANCEL:{
		return false;
				  }
	default:{
		MessageBox(NULL, "хом€чок сдох :(", NULL, MB_OK);
		exit(1);
			}
	}
}

void RenderLogScene(void){
	//TODO
}

void main(int argc, char**argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Tank");

	//glClearColor(0.5, 0.5, 0.75, 1);
	
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_BLEND);
	glEnable(GL_POINT_SMOOTH);
	glPointSize(10);
	
	
	cover_hght = LoadBMP("./sensors/cover_hght.bmp");
	
	if(AskMode()){ //command mode
		glutDisplayFunc(RenderCommandScene);
	}
	else{ //log mode
		glutDisplayFunc(RenderLogScene);
	}
	
	glutMainLoop();
}