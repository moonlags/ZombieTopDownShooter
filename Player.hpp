#pragma once

#include <SDL2/SDL.h>

#define PI 3.14159

class Player{
public:
    Player(int x,int y,int vx,int vy);
    void Update(int mx,int my);
    int GetX();
    int GetY();
    int GetDirection();
    SDL_FRect GetGunPos();
private:
    float direction;
    int vx,vy;
    int x,y;
};