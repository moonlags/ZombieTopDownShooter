#pragma once

#include <SDL2/SDL.h>

class Bullet{
public:
    Bullet(int x1,int y1,float direction);
    void Update();
    int GetDirection();
    SDL_Rect* GetPos();
private:
    SDL_Rect pos;
    float direction;
};