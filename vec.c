/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include <math.h>
#include "vec.h"

VEC_T normalize (VEC_T vec);
double dot(VEC_T vec1, VEC_T vec2);

VEC_T normalize (VEC_T vec) //computes and returns normalized vector v 
{

  double scalar;
  double s_x = vec.x * vec.x;
  double s_y = vec.y * vec.y;
  double s_z = vec.z * vec.z;
  scalar = sqrt(s_x + s_y + s_z);


  vec.x = vec.x / scalar;
  vec.y = vec.y / scalar;
  vec.z = vec.z / scalar;

  return vec;
}

double dot(VEC_T vec1, VEC_T vec2)
{
	double d_out;
  double d_x = vec1.x * vec2.x;
 	double d_y = vec1.y * vec2.y;
 	double d_z = vec1.z * vec2.z;
 	d_out = d_x + d_y + d_z;

    return d_out;
}