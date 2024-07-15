#include <SDL2/SDL.h>
#include <iostream>
#include "SnowFlake.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const int NB_SNOWFLAKES = 25;

void initSnowFlakes(SnowFlake snowFlakes[], int Nb);

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cerr << "SDL could not be initialized : " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("VonKoch SnowFlakes", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window)
    {
        std::cerr << "Window could not be created : " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        std::cerr << "Renderer could not be created : " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    SnowFlake snowFlakes[NB_SNOWFLAKES];

    initSnowFlakes(snowFlakes, NB_SNOWFLAKES);

    bool quit = false;
    SDL_Event e;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 25, 25, 25, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);

        for (int i = 0; i < NB_SNOWFLAKES; ++i)
        {
            SDL_SetRenderDrawColor(renderer, snowFlakes[i].color.r, snowFlakes[i].color.g, snowFlakes[i].color.b, SDL_ALPHA_OPAQUE);
            drawVonKochSnowFlake(renderer, snowFlakes[i]);

            snowFlakes[i].y += snowFlakes[i].speed;

            snowFlakes[i].angle += 1;

            if (snowFlakes[i].y > WINDOW_HEIGHT)
            {
                snowFlakes[i].y = -snowFlakes[i].size;
                snowFlakes[i].complexity = rand() % 3 + 2;
            }
        }

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void initSnowFlakes(SnowFlake snowFlakes[], int Nb)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < Nb; ++i)
    {
        snowFlakes[i].x = rand() % WINDOW_WIDTH;
        snowFlakes[i].y = -(rand() % WINDOW_HEIGHT);
        snowFlakes[i].size = rand() % 100 + 20;
        snowFlakes[i].speed = rand() % 10 + 1;
        snowFlakes[i].angle = rand() % 360;
        snowFlakes[i].color = { static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), static_cast<Uint8>(rand() % 256), SDL_ALPHA_OPAQUE };
        snowFlakes[i].complexity = rand() % 3 + 2;
    }
}