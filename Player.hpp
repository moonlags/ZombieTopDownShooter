#pragma once

#include <SDL2/SDL.h>

#define PI 3.14159

class Player{
public:
    Player(int x,int y,int vx,int vy,int size);
    void Update(int mx,int my,int fx,int fy);
    int GetX();
    int GetY();
    int GetSize();
    int GetDirection();
    SDL_FRect GetGunPos();
private:
    float direction;
    int vx,vy;
    int x,y;
    int size;
};