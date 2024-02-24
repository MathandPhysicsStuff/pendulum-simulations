#include <stdio.h>

#include "SDL2/SDL.h"

#include "header.h"

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

int main()
{

    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
        printf("SDL2 video failed to initialize: \n", SDL_GetError());
    else 
        printf("System is ready to go!\n");

    window = SDL_CreateWindow("Hello SDL",
                               SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               SCREEN_WIDTH, SCREEN_HEIGHT,
                               SDL_WINDOW_SHOWN);

    renderer = SDL_CreateRenderer(window,
                                   -1,
                                   SDL_RENDERER_ACCELERATED);


    Pendulum pendulum = 
    {
        .length = 700,
        .angle = PI/2,
        .Fg = 10,
        .bx_pos = SCREEN_WIDTH/2.0, .by_pos = 0, 
    };
    double force, a, v;

    SDL_bool running = SDL_TRUE;
    while (running == SDL_TRUE)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = SDL_FALSE;
                break;
            }

        }

        SDL_SetRenderDrawColor(renderer, 8, 8, 8, 255);
        SDL_RenderClear(renderer);
        
        force = pendulum.Fg * sin(pendulum.angle);
        a = (-1 * force) / pendulum.length; 

        v += a;
        pendulum.angle += v;
        v *= 0.999;
        
        //printf("angle: %lf\n", pendulum.angle);
        
        basic_pendulum(renderer, &pendulum);

        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
