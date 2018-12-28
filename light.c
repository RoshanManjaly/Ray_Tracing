/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/


#include <math.h>

#include "light.h"
#include "rt.h"
#include "obj.h"
#include "vec.h"
#include "sphere.h"

COLOR_T illuminate (RAY_T ray, LIGHT_T light, OBJ_T *list, COLOR_T surface_col, VEC_T int_pt, VEC_T normal)
{
    COLOR_T color;
    color.R = 0.2 * surface_col.R;
    color.G = 0.2 * surface_col.G;
    color.B = 0.2 * surface_col.B;

    double i;
    double n_power = 1;
    double power = 200;

    VEC_T vector_1;
    VEC_T vector_2;
    VEC_T vector_3;
    VEC_T vector_4;

    vector_1 = normalize(normal);

    vector_2.x = light.loc.x - int_pt.x;
    vector_2.y = light.loc.y - int_pt.y;
    vector_2.z = light.loc.z - int_pt.z;

    vector_3 = normalize(vector_2);

    if(dot(vector_1, vector_3) > 0)
    {
          color.R = color.R + dot(vector_1, vector_3)*surface_col.R;
          color.G = color.G + dot(vector_1, vector_3)*surface_col.G;
          color.B = color.B + dot(vector_1, vector_3)*surface_col.B;
          
          vector_4.x = vector_3.x - (2 * vector_1.x * dot(vector_1, vector_3));
          vector_4.y = vector_3.y - (2 * vector_1.y * dot(vector_1, vector_3));
          vector_4.z = vector_3.z - (2 * vector_1.z * dot(vector_1, vector_3));
          vector_4 = normalize(vector_4);
        
        if( dot(vector_4 ,ray.direction) > 0 )
            {
                for ( i = 1; i <= power; ++i )
                {
                    n_power = n_power * dot(vector_4 ,ray.direction);        
                }

                color.R = color.R + n_power;
                color.B = color.B + n_power;
                color.G = color.G + n_power;
            }
    }


  return color;
}

