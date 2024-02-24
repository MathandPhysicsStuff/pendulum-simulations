#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include "SDL2/SDL.h"

#define PI 3.1415926535898

typedef struct Pendulum
{
    double length;
    double angle;
    double Fg; //force of gravity
    double bx_pos, by_pos; //base of the pendulum

}Pendulum;

void circle(SDL_Renderer *renderer);
void basic_pendulum(SDL_Renderer *renderer, Pendulum *P);

#endif
