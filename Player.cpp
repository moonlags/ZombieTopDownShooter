#include "Player.hpp"
#include <cmath>
#include <iostream>

Player::Player(int x,int y,int size):size(size),x(x),y(y),direction(0),shootcd(0){}

void Player::Update(int mx,int my,int fx,int fy){
    direction=atan2(my-(y+size/2),mx-(x+size/2));
    if (direction<0)
        direction+=2*PI;
    
    x+=fx;
    y+=fy;
    shootcd--;

    if(x<0){
        x=0;
    }else if(y<0){
        y=0;
    }else if(y>720-size){
        y=720-size;
    }else if(x>960){
        if(fx!=0){
            x=961;
        }else{
            x=960;
        }
    }
}

int Player::GetSize(){
    return size;
}

bool Player::CanShoot(){
    return shootcd<=0;
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
    SDL_FRect dst={x+(size/4*3)*cos(direction),y+(size/4*3)*sin(direction),size,size};
    return dst;
}

Bullet Player::Shoot(){
    Bullet bullet(x+size/2,y+size/2,direction);
    x=x-(size/4*3)*cos(direction);
    y=y-(size/4*3)*sin(direction);
    shootcd=60;
    return bullet;   
}