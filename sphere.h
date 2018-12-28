/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include "vec.h"
#include "rt.h"

#ifndef SPHERE_h
#define SPHERE_h

typedef struct //SPHERE_T with center and radius 
{
  VEC_T center;
  double radius;
}SPHERE_T;

int intersect_sphere (RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal);

#endif