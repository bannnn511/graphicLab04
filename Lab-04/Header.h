//
//  Header.h
//  Lab-04
//
//  Created by An on 5/25/20.
//  Copyright © 2020 An Binh Ha. All rights reserved.
//

#ifndef Header_h
#define Header_h

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <GLUT/GLUT.h>
#include "Texture.hpp"
#include "SOIL2/SOIL2.h"
using namespace std;

// MARK: GLOBAL VARIABLES

inline GLfloat anglePyramid = 0.0f;
inline GLfloat angleCube = 0.0f;
inline int refreshMills = 15;
inline GLuint texture[1];
inline GLfloat xrot = 0;
inline GLfloat yrot = 0;
inline GLfloat zrot = 0;

void initGL();
void display();
void reshape(GLsizei width, GLsizei height);
void timer(int value);

#endif /* Header_h */
