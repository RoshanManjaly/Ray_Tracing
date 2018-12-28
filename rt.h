/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include "vec.h"

#ifndef RT_h
#define RT_h

	typedef struct // RAY_T with origin and direction fields
		{
		    VEC_T origin;
		    VEC_T direction;
		} RAY_T;

	typedef struct // COLOR_T with R, G, B fields
		{
		    double R;
		    double G;
		    double B;
		} COLOR_T;
		
#endif
