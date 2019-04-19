#pragma once
#include<iostream>

constexpr double PI = 3.141592653;

float	fRotateTri = 0;
//float	fRotateTri;


float	fRotateQuad = 0;
void Reshape(int w, int h)
{
	if (0 == h)
		h = 1;

	glViewport(0, 0, w, h); //设置视区尺寸

	glMatrixMode(GL_PROJECTION); //指定当前操作投影矩阵堆栈
	glLoadIdentity(); //重置投影矩阵
	gluPerspective(45.0f, (float)w / (float)h, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void Init()
{
	glEnable(GL_DEPTH_TEST); //启用深度测试

	glClearColor(0.0f, 0.0f, 0.0f, 0.8f); //背景为黑色
}

void RenderAQuadrilateral() {
	glLoadIdentity();
	glTranslatef(1.5, 0, -6);
	glRotatef(fRotateTri, 1, 0, 0);
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-1.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();
	
}

void RenderATriangle()
{
	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(fRotateQuad, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderAQuadrilateral();
	RenderATriangle();
	

	glutSwapBuffers();

}

void myIdle(void) //在空闲时调用，达到动画效果
{
	fRotateTri += 0.005f;
	if (fRotateTri>2*PI)
	{
		fRotateTri = 0;
	}
	fRotateQuad += 0.05f;
//	std::cout << fRotateTri <<std:: endl;
	RenderScene();
}
