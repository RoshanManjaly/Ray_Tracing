/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include "vec.h"
#include "rt.h"
#include "obj.h"

#ifndef LIGHT_h
#define LIGHT_h

typedef struct
{
  VEC_T loc;
}LIGHT_T;

COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_col, VEC_T int_pt, VEC_T normal);

#endif