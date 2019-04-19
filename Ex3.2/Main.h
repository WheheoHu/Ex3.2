#pragma once
#include<iostream>
#include<cmath>

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

	glClearColor(1.f, 1.f, 1.f, 0.8f); //背景为黑色
}



void RenderATriangle()
{
	glLoadIdentity();
	glTranslatef(-1.5f, 1.3f, -6.0f);
	glRotatef(fRotateTri, 0.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, 0.0f);
	glEnd();
}
void RenderAQuadrilateral() {
	glLoadIdentity();
	glTranslatef(1.5, 1.3, -6);
	glRotatef(fRotateQuad, 1, 0, 0);
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
void RenderARegularTetrahedron() {
	glLoadIdentity();
	glTranslatef(-1.5, -1.3, -6);
	glRotatef(fRotateTri, 0, 1, 0);
	float RegularTetrahedronPoints[4][3] = {
		{0,0,std::sqrt(3) / 3},

		{1. / 2,0,-std::sqrt(3) / 2 + std::sqrt(3) / 3},
		{-1. / 2,0,-std::sqrt(3) / 2 + std::sqrt(3) / 3},
		{0,std::sqrt(6) / 3,0}
	};
	glBegin(GL_TRIANGLES);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3fv(RegularTetrahedronPoints[0]);
	glVertex3fv(RegularTetrahedronPoints[1]);
	glVertex3fv(RegularTetrahedronPoints[2]);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3fv(RegularTetrahedronPoints[0]);
	glVertex3fv(RegularTetrahedronPoints[1]);
	glVertex3fv(RegularTetrahedronPoints[3]);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3fv(RegularTetrahedronPoints[0]);
	glVertex3fv(RegularTetrahedronPoints[2]);
	glVertex3fv(RegularTetrahedronPoints[3]);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3fv(RegularTetrahedronPoints[1]);
	glVertex3fv(RegularTetrahedronPoints[2]);
	glVertex3fv(RegularTetrahedronPoints[3]);
	glEnd();
}
void RenderACube() {
	glLoadIdentity();
	glTranslatef(1.5, -1.3, -6);
	glRotatef(fRotateQuad,1, 0, 0);
	float CubePoints[8][3] = {
		{0.5,-0.5,0.5},
		{-0.5,-0.5,0.5},
		{-0.5,-0.5,-0.5},
		{0.5,-0.5,-0.5},
		{0.5,0.5,0.5},
		{-0.5,0.5,0.5},
		{-0.5,0.5,-0.5},
		{0.5,0.5,-0.5}
	};
	int facevec[6][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{1,5,8,4},
		{2,3,7,6},
		{1,2,6,5},
		{3,4,7,8},
	};
	glBegin(GL_QUADS);
	for (int i = 0; i < 6; i++)
	{
		for (int pointvec = 0; pointvec < 4; pointvec++)
		{
			glVertex3fv(CubePoints[facevec[i][pointvec]-1]);
		}
	}
	glEnd();
}
void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	RenderAQuadrilateral();
	RenderATriangle();

	RenderARegularTetrahedron();
	RenderACube();
	glutSwapBuffers();

}

void myIdle(void) //在空闲时调用，达到动画效果
{
	fRotateTri += 0.05f;
	if (fRotateTri > 360)
	{
		fRotateTri = 0;
	}
	fRotateQuad += 0.05f;
	if (fRotateQuad > 360)
	{
		fRotateQuad = 0;
	}
	/*std::cout << fRotateTri <<std:: endl;
	std::cout << fRotateQuad << std::endl;*/
	RenderScene();
}
