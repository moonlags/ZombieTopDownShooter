#include "Player.hpp"
#include <cmath>
#include <iostream>

Player::Player(int x,int y,int vx,int vy):x(x),y(y),vx(vx),vy(vy),direction(0){}

void Player::Update(int mx,int my){
    direction=atan2(my-y,mx-x);
    if (direction<0)
        direction+=2*PI;
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
    SDL_FRect dst={(x-50)+75*cos(direction),(y-50)+75*sin(direction),100,100};
    return dst;
}