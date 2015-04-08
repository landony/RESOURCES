// 
//Modified by: LEWEN YAO
//lewen.yao at gmail.com
//Date: 04/07/2015

//
// Michael Shafae
// mshafae at fullerton.edu
// 
// Procedural module that implements transformations used in
// the homework assignment.
//
// $Id: transformations.cpp 5554 2015-02-19 06:59:50Z mshafae $
//
// STUDENTS _MUST_ ADD THEIR CODE INTO THIS FILE
//

#include "transformations.h"

#ifndef __SOLUTION__


#ifndef SQR
#define SQR( x ) ((x) * (x))
#endif

void rotateCameraLeft(float degrees, Vec3& eyePosition, Vec3& centerPosition, Vec3& upVector){
  // Please implement this function.
  
  Mat4 m;	  //Rotation matrix
  
  //Calculate the rotation matrix
  m = rotate(degrees, Vec3(0.0f, -1.0f, 0.0f));
  
  //Apply the rotation to the eyePosition and upVector vectors
  Mat3 r;
  r[0][0] = m[0][0];
  r[0][1] = m[0][1];
  r[0][2] = m[0][2];
  
  r[1][0] = m[1][0];
  r[1][1] = m[1][1];
  r[1][2] = m[1][2];
  
  r[2][0] = m[2][0];
  r[2][1] = m[2][1];
  r[2][2] = m[2][2];
  
  eyePosition = r*eyePosition;
  upVector = r*upVector;

}

void rotateCameraUp(float degrees, Vec3& eyePosition, Vec3& centerPosition, Vec3& upVector){
  // Please implement this function.

   Mat4 m;	  //Rotation matrix
  
  //Calculate the rotation matrix
  m = rotate(degrees, Vec3(-1.0f,0.0f,0.0f));
  
  //Apply the rotation to the eyePosition and upVector vectors
  Mat3 r;
  r[0][0] = m[0][0];
  r[0][1] = m[0][1];
  r[0][2] = m[0][2];
  
  r[1][0] = m[1][0];
  r[1][1] = m[1][1];
  r[1][2] = m[1][2];
  
  r[2][0] = m[2][0];
  r[2][1] = m[2][1];
  r[2][2] = m[2][2];
  
  eyePosition = r*eyePosition;
  upVector = r*upVector;
}

#else
#include "transformations_solution.cpp"
#endif
