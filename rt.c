/*
Roshan Manjaly
Assignment 8: Ray Caster Project 
Computer Organization
04/27/2018
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "rt.h"
#include "obj.h"
#include "vec.h"
#include "sphere.h"
#include "light.h"

COLOR_T trace (RAY_T ray, OBJ_T *list, LIGHT_T light);
void read_objs (OBJ_T **list);


void read_objs (OBJ_T **list) 
{ 
    double center_x;
    double center_y;
    double center_z;
    
    double radius;

    double R;
    double G;
    double B;
    OBJ_T *new;
    
    while (scanf("%lf %lf %lf %lf %lf %lf %lf", &center_x, &center_y, &center_z, &radius, &R, &G, &B) == 7) 
    {
      new = (OBJ_T *)malloc(sizeof(OBJ_T));
      new -> sphere.radius = radius;
      new -> sphere.center.x = center_x;
      new -> sphere.center.y = center_y;
      new -> sphere.center.z = center_z;
      new -> color.R = R;
      new -> color.G = G;
      new -> color.B = B;
      new -> next = *list;
      *list = new;
    }
} 
     
 
//iterates through linked list; finds closest intersection using intersect_sphere; returns color of closest sphere
COLOR_T trace (RAY_T ray, OBJ_T *list, LIGHT_T light)
{
    OBJ_T *current;
    double dimension = 1000;
    double t;
    COLOR_T color;
    color.R = 0.0;
    color.G = 0.0;
    color.B = 0.0;

    OBJ_T *o_ject;

    VEC_T vector_a;
    VEC_T vector_b;
    VEC_T vector_c;
    VEC_T vector_d;

    for (current = list; current != NULL; current = current->next)
    {
        if (intersect_sphere(ray, current->sphere, &t, &vector_a, &vector_d))
        {
            if (t < dimension) 
            {
                color = current->color;
                dimension = t;
                vector_c = vector_a;
                vector_b = vector_d;
                o_ject = current;
            }
        }
    }

    if(o_ject != NULL)
    {
        color = illuminate(ray, light, list, color, vector_c, vector_b);
    }

    return color;
}

//calls read_objs; initializes image file; loops through pixels: sets ray, calls cast, prints color; frees linked list
int main() {
  OBJ_T *list = NULL;
  OBJ_T *current;
  read_objs(&list);
  COLOR_T color;
  RAY_T rray;
  double x;
  double y;
  SPHERE_T sphere;
  LIGHT_T light;
  light.loc.x = 5;
  light.loc.y = 10;
  light.loc.z = 0;
  double dimensions = 1000.0;
  
  printf("P6\n1000 1000\n255\n");

  for (y = 0; y < dimensions; y++) 
  {
      for (x = 0; x < dimensions; x++) 
      {
          rray.origin.x = 0;
          rray.origin.y = 0;
          rray.origin.z = 0;

          rray.direction.x = -0.5 + (x / dimensions);
          rray.direction.y = 0.5 - (y / dimensions);
          rray.direction.z = 1.0;
          rray.direction = normalize(rray.direction);

          color = trace(rray, list, light);
          
          if(color.R > 1.0)
              color.R = 1.0;
          if(color.G > 1.0)        
              color.G = 1.0;
          if(color.B > 1.0)
              color.B = 1.0;

          printf("%c%c%c", ((unsigned char)(color.R*255)), ((unsigned char)(color.G*255)), ((unsigned char)(color.B*255)));
      }
  }
  while (list != NULL) 
  {
      current = list;
      list = list->next;
      free(current);
  }
  
  return 0;
}