#include "Player.hpp"
#include <cmath>
#include <iostream>

Player::Player(int x,int y,int vx,int vy,int size):size(size),x(x),y(y),vx(vx),vy(vy),direction(0){}

void Player::Update(int mx,int my,int fx,int fy){
    direction=atan2(my-y,mx-x);
    if (direction<0)
        direction+=2*PI;

    x+=fx*vx;
    y+=fy*vy;
}

int Player::GetSize(){
    return size;
}

int Player::GetX(){
    return x;
}

int Player::GetY(){
    return y;
}

int Player::GetDirection(){
    return direction*(180/PI);
}

SDL_FRect Player::GetGunPos(){
    SDL_FRect dst={(x-size/2)+(size/4*3)*cos(direction),(y-size/2)+(size/4*3)*sin(direction),size,size};
    return dst;
}