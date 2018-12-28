/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include <math.h>
#include "sphere.h"
#include "vec.h"
#include "rt.h"

int intersect_sphere (RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal);

int intersect_sphere (RAY_T ray, SPHERE_T sphere, double *t, VEC_T *int_pt, VEC_T *normal)
{
    double A = 1;

    double B_x = (ray.direction.x * (ray.origin.x - sphere.center.x));
    double B_y = (ray.direction.y * (ray.origin.y - sphere.center.y));
    double B_z = (ray.direction.z * (ray.origin.z - sphere.center.z));
    double B = 2 * (B_x + B_y +B_z);


    double C_x = (ray.origin.x - sphere.center.x) * (ray.origin.x - sphere.center.x);
    double C_y = (ray.origin.y - sphere.center.y) * (ray.origin.y - sphere.center.y);
    double C_z = (ray.origin.z - sphere.center.z) * (ray.origin.z - sphere.center.z);
    double C_sphere = sphere.radius * sphere.radius;
    double C = C_x + C_y + C_z - C_sphere;

    double d = (B * B) - (A * C * 4);
    double temp = (B * B) - (A * C * 4);

    
    if (d <= 0) 
    {
        return 0;
    }

    double val_1 = ( sqrt(temp) - B )  /  (2 * A);
    double val_2 = ( (-1) * (B + sqrt(temp)) )  / (2 * A);
    
    if (val_1 < 0 && val_2 < 0)
    {
        return 0;
    }
    else if(val_1 > val_2)
    {
        *t = val_2;

        int_pt -> x = ray.origin.x + ray.direction.x * (*t);
        int_pt -> y = ray.origin.y + ray.direction.y * (*t);
        int_pt -> z = ray.origin.z + ray.direction.z * (*t);
        
        normal -> x = (int_pt -> x - sphere.center.x) / sphere.radius;
        normal -> y = (int_pt -> y - sphere.center.y) / sphere.radius;
        normal -> z = (int_pt -> z - sphere.center.z) / sphere.radius;
        
        return 1;
    }
    else if(val_1 < val_2)
    {
        *t = val_1;
        
        int_pt -> x = ray.origin.x + ray.direction.x * (*t);
        int_pt -> y = ray.origin.y + ray.direction.y * (*t);
        int_pt -> z = ray.origin.z + ray.direction.z * (*t);
        
        normal -> x = (int_pt -> x - sphere.center.x) / sphere.radius;
        normal -> y = (int_pt -> y - sphere.center.y) / sphere.radius;
        normal -> z = (int_pt -> z - sphere.center.z) / sphere.radius;
        
        return 1;
    }


    return 0;
}


