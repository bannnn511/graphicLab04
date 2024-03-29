//
//  main.cpp
//  Lab-04
//
//  Created by An on 5/25/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#include "Header.h"

// MARK:- MAIN

int main(int argc, char * argv[]) {
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GL_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab-04");
    
    glLoadGLTextures();
    
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    
    initGL();
    glutTimerFunc(0, timer, 0);
    
    glutMainLoop();
    return 0;
}

void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape(GLsizei width, GLsizei height) {
    if (height == 0) {
        height = 1;
    }
    
    GLfloat aspect = (GLfloat) width / (GLfloat) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

//MARK:- DISPLAY
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    
    drawCube();
    drawPyramid();
    drawCylinder();
    drawConeShape();
    drawRingShape();
    
    drawGLScene();
    
    glutSwapBuffers();
}

// TIMER
void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(refreshMills, timer, 0);
}

// MARK: Draw RingShape
void drawRingShape() {
    GLdouble innerRaidus=0.5;
    GLdouble outterRaidus=1;
    GLint sides =50;
    GLint rings =50;
    
    glLoadIdentity();
    glTranslatef(2.0,1.9,-7.0);
    
    glColor3f(0.5, 0.2, 0.9);
    
    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glRotatef(zrot,0.0,0.0,1.0);
    
    xrot -= 1.0f;
    yrot += 1.0f;
    zrot += 1.0f;
    
    glutSolidTorus(innerRaidus, outterRaidus, sides, rings);
}

// MARK: Draw ConeShape
void drawConeShape() {
    
    GLdouble base=1;
    GLdouble height=1.5;
    GLint slices =50;
    GLint stacks =50;
    glLoadIdentity();
    glTranslatef(0.0,0.0,-7.0);
 
    glColor3f(0.8, 0.2, 0.1);

    glRotatef(xrot,1.0,0.0,0.0);
    glRotatef(yrot,0.0,1.0,0.0);
    glRotatef(zrot,0.0,0.0,1.0);
    
    xrot += 1.0f;
    yrot += 1.0f;
    zrot += 1.0f;
    
    glutSolidCone(base,height,slices,stacks);
    
}

//MARK: Draw Cylinder
void drawCylinder() {
    double r = 1.0;
    double height = 2.0;
    int faces = 360;
    glColor3f(1.0f, 0.5f, 0.0f);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    
    glBegin(GL_QUAD_STRIP);
    double x, y, z;
    y = height;
    for (int i = 0; i<= faces; i++) {
        double u = (double)i/ (double) faces;
        x = r*cos(2*3.14*u);
        z = r*sin(2*3.13*u);
        // Bottom vertex
        glTexCoord2d(u, 1.0);
        glVertex3d(x, 0, z);
        // Top vertex
        glTexCoord2d(u, 0.0);
        glVertex3d(x, y, z);
    }
    glEnd();
}

// MARK: Draw Cube
void drawCube() {
    glLoadIdentity();
    glTranslatef(1.5f, 0.0f, -7.0f);
    glRotatef(angleCube, 1.0f, 1.0f, 1.0f);
    
    // MARK: CUBE
    // Top face y =1.0f
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f,  -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    
    // Bottom face 7=-1.0f
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // Front face z= 1.0f
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // Back face z = -1.0f
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    
    // Left face  x= -1.0f
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f,- 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    
    // Right face x =1.0f
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    
    angleCube -= 0.15f;
}

// MARK: Draw Pyramid
void drawPyramid() {
    // Render a pyramid consists of 4 triangles
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f);
    glRotatef(anglePyramid, 1.0f, 1.0f, 0.0f);
    
    // MARK: TRIANGLE
    glBegin(GL_TRIANGLES);
    // Front
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
    // Right
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    
    // Back
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    
    // Left
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    
    anglePyramid += 0.2f;
}
