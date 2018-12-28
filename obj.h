/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include "sphere.h"
#include "rt.h"
#include "vec.h"

#ifndef OBJ_h
#define OBJ_h


typedef struct OBJ //OBJ_T with sphere,color,and nextfields
{
  SPHERE_T sphere;
  COLOR_T color;
  struct OBJ *next;
} OBJ_T;

#endif