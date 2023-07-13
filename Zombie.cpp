#include "Zombie.hpp"
#include <cmath>

#define PI 3.14159

Zombie::Zombie(int x,int y,int size,int speed):speed(speed){
    pos={x,y,size,size};
}

SDL_Rect * Zombie::GetPos(){
    return &pos;
}

void Zombie::Update(int px,int py){
    direction=atan2(py-(pos.y+pos.w/2),px-(pos.x+pos.w/2));
    if (direction<0)
        direction+=2*PI;

    pos.x+=speed*cos(direction);
    pos.y+=speed*sin(direction);
}


int Zombie::GetDirection(){
    return direction*(180/PI);
}