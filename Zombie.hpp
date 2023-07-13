#pragma once

#include <SDL2/SDL.h>

class Zombie{
public:
    Zombie(int x,int y,int size,int speed);
    SDL_Rect* GetPos();
    void Update(int px,int py);
    int GetDirection();
private:
    int speed;
    float direction;
    SDL_Rect pos;
};