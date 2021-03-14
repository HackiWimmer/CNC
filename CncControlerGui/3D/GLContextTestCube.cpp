#include <iostream>
#include "3D/GLInclude.h"
#include "3D/GLContextTestCube.h"

/////////////////////////////////////////////////////////////////
GLContextTestCube::GLContextTestCube(wxGLCanvas* canvas) 
: GLContextCncPathBase(canvas, "GLContextTestCube")
{
/////////////////////////////////////////////////////////////////
	// do something here on demand
}
/////////////////////////////////////////////////////////////////
GLContextTestCube::~GLContextTestCube() {
/////////////////////////////////////////////////////////////////
	// do something here on demand
}
/////////////////////////////////////////////////////////////////
GLViewPort* GLContextTestCube::createViewPort() {
/////////////////////////////////////////////////////////////////
	// determine the destort type
	return new GLViewPort(GLViewPort::VPT_Distorted);
}
/////////////////////////////////////////////////////////////////
void GLContextTestCube::initContext() {
/////////////////////////////////////////////////////////////////
	// do context specific initalization here
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
	
	glEnable(GL_LINE_SMOOTH);

	if ( options.blending ) {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA); 
		glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
	}
	
	setViewMode(GLContextBase::V3D_ISO1);
}
/////////////////////////////////////////////////////////////////
void GLContextTestCube::determineProjection(int w, int h) {
	GLContextBase::determineProjection(w, h);
}
/////////////////////////////////////////////////////////////////
void GLContextTestCube::determineModel() {
/////////////////////////////////////////////////////////////////
	glMatrixMode(GL_MODELVIEW);

	// draw the scene
	glColor3f (1.0, 1.0, 1.0);
	glutWireCube (1.0);
	
	glPushMatrix();
		glColor3f (1.0, 0.0, 0.0);
		glTranslatef(0.3f, 0.3f, 0.3f);
		glutWireCube (0.3);
	glPopMatrix();
	
}
