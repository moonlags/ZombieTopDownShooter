#pragma once

#include <SDL2/SDL.h>

class Zombie{
public:
    Zombie(int x,int y,int size,int speed);
    SDL_Rect* GetPos();
    void Update();
private:
    int speed;
    float direction;
    SDL_Rect pos;
}