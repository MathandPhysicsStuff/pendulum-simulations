#include "header.h"

void circle(SDL_Renderer *renderer)
{
    double t = 0;
    double r = 300;
    double x, y;

    while (t < 2*PI)
    {
        x = 320 + 300*cos(t);
        y = 320 + 300*sin(t);
                
        SDL_SetRenderDrawColor(renderer, 255, 8, 255, 255); 
        SDL_RenderDrawPoint(renderer, x, y);

        t += (2*PI)/1000.0;
    }
}


void basic_pendulum(SDL_Renderer *renderer, Pendulum *P)
{
    double x = P->bx_pos + P->length * sin(P->angle); 
    double y = P->by_pos + P->length * cos(P->angle); 

    SDL_SetRenderDrawColor(renderer, 8, 8, 255, 255); 
    SDL_RenderDrawLine(renderer, P->bx_pos, P->by_pos, x, y);
}



























