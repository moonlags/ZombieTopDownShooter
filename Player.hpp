#pragma once

#include <SDL2/SDL.h>
#include "Bullet.hpp"

#define PI 3.14159
class Player{
public:
    Player(int x,int y,int size);
    void Update(int mx,int my,int fx,int fy);
    int GetX();
    int GetY();
    int GetSize();
    int GetDirection();
    SDL_FRect GetGunPos();
    bool CanShoot();
    Bullet Shoot();
private:
    float direction;
    int x,y;
    int size;
    int shootcd;
};