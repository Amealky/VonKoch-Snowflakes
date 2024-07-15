#ifndef SNOWFLAKE_H
#define SNOWFLAKE_H

#include <SDL2/SDL.h>

struct SnowFlake
{
    double x;
    double y;
    double size;
    double speed;
    double angle;
    SDL_Color color;
    int complexity;
};

void drawVonKochSnowFlake(SDL_Renderer* renderer, SnowFlake& snowFlake);

#endif