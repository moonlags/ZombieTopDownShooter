#include "Bullet.hpp"
#include <cmath>

#define PI 3.14159

Bullet::Bullet(int x1,int y1,float direction):direction(direction){
    int x2 = x1+30*cos(direction);
    int y2 = y1+30*sin(direction);
    pos={x1,y1,x2,y2};
}

SDL_Rect* Bullet::GetPos(){
    return &pos;
}

int Bullet::GetDirection(){
    return direction*(180/PI);
}

void Bullet::Update(){
    pos.x+=(30)*cos(direction);
    pos.y+=(30)*sin(direction);
    pos.w+=(30)*cos(direction);
    pos.h+=(30)*sin(direction);
}