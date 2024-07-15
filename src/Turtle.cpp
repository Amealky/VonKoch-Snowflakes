#include "Turtle.h"
#include <cmath>

static double X = 0;
static double Y = 0;
static double A = 0;
static double Pen = 1;

void up()
{
    Pen = 0;
}

void down()
{
    Pen = 1;
}

void forward(SDL_Renderer* renderer, double L, double angle)
{
    double pi = 3.1415926535;

    double dX = (L * cos(((double)angle * pi) / 180));
    double dY = (L * sin(((double)angle * pi) / 180));

    if (Pen == 1)
    {
        SDL_RenderDrawLine(renderer, static_cast<int>(X), static_cast<int>(Y), static_cast<int>(X + dX), static_cast<int>(Y + dY));
    }

    X += dX;
    Y += dY;
}

void left(int B)
{
    A += B;
}

void right(int B)
{
    A -= B;
}

void grgoto(int x, int y)
{
    X = x;
    Y = y;
}

void setangle(double B)
{
    A = B;
}


void drawVonKochLine(SDL_Renderer* renderer, double L, int N)
{
    if (N == 0)
    {
        forward(renderer, L, A);
    }
    else
    {
        L /= 3;
        drawVonKochLine(renderer, L, N - 1);
        left(60);
        drawVonKochLine(renderer, L, N - 1);
        right(120);
        drawVonKochLine(renderer, L, N - 1);
        left(60);
        drawVonKochLine(renderer, L, N - 1);
    }
}