#include "SnowFlake.h"
#include "Turtle.h"

void drawVonKochSnowFlake(SDL_Renderer* renderer, SnowFlake& snowFlake)
{
    grgoto(static_cast<int>(snowFlake.x), static_cast<int>(snowFlake.y));
    setangle(snowFlake.angle);
    for (int i = 0; i < 3; ++i)
    {
        drawVonKochLine(renderer, snowFlake.size, snowFlake.complexity);
        right(120);
    }
}