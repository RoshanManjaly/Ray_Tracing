/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#ifndef VEC_h
#define VEC_h

typedef struct // with x, y,and z fields
{
  double x;
  double y;
  double z;
}VEC_T;

VEC_T normalize(VEC_T v);
double dot(VEC_T v1, VEC_T v2);

#endif