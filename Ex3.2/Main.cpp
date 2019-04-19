#include <stdlib.h>
#include "glut.h"//<gl/glut.h>
#include "Main.h"




int main(int argc, char *argv[])
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(600, 400);
	glutCreateWindow("Demo");
	
	glutReshapeFunc(Reshape);
	
	glutDisplayFunc(RenderScene);
	
	glutIdleFunc(myIdle);
	
	Init();
	
	glutMainLoop();
	
	return 0;
	
} 
