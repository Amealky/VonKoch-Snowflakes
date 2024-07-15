#ifndef TURTLE_H
#define TURTLE_H

#include <SDL2/SDL.h>


void up();
void down();
void forward(SDL_Renderer* renderer, double L, double angle);
void left(int B);
void right(int B);
void grgoto(int x, int y);
void setangle(double B);
void drawVonKochLine(SDL_Renderer* renderer, double L, int N);

#endif