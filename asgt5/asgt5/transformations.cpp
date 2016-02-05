//Modified by: LW.Y
//
//Date: 04/07/2015
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



void rotateCameraLeft(float degrees, Vec3& eyePosition, Vec3& centerPosition, Vec3& upVector){
  // Please implement this function.
  

  //lookat(eyePosition, centerPosition,upVector);
 
  //Vec3 g=(centerPosition-eyePosition);
  //Vec3 leftVector=Vec3(-1.0,0.0,0.0);
  //Vec3 r=cross(g,upVector);
  //Vec3 u=normalize(r);
  Mat4 rm=rotate(degrees,upVector);
  Vec4 k(eyePosition,0.0);
  Vec4 w= rm*k;
  for(int i=0;i<=2;i++){
      eyePosition[i]=w[i];
  
  }
  
  
  
  

/*Mat4 rm=rotate(degrees,0,6,0);
 Vec4 rt=rm[0]+rm[1]+rm[2];
  for(int i=0;i<=2;i++){
      eyePosition[i]=rt[i];
  
  }*/
  //perspective(degrees,1,1,25);
  //lookat(eyePosition, centerPosition,upVector);
  //rotate(degrees,0,1,0);
  //perspective(degrees,1,1,25);
  
  
}

void rotateCameraUp(float degrees, Vec3& eyePosition, Vec3& centerPosition, Vec3& upVector){
  // Please implement this function.
  
  Vec3 g=(centerPosition-eyePosition);
  Vec3 r=cross(g,upVector);
  Vec3 u=normalize(r);
  Mat4 rm=rotate(degrees,u);
  Vec4 k(eyePosition,0.0);
  //eyePosi
  //Mat4 rm=rotate(degrees,6,0,0);
  Vec4 w= rm*k;
  //eyePosition=
 //Vec4 rt=rm[0]+rm[1]+rm[2];
  for(int i=0;i<=2;i++){
      eyePosition[i]=w[i];
  
  }

  Vec3 g1=centerPosition-eyePosition;
  //Vec3 rightVector=Vec(1.0,0.0,0.0);
  upVector=cross(r,g1);
  upVector=normalize(upVector);
  
  //perspective(degrees,1,1,25);
   //lookat(eyePosition, centerPosition,upVector);
  //rotate(degrees,eyePosition);
}

#else
#include "transformations_solution.cpp"
#endif
