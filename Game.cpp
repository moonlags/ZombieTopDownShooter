//
// Created by Konstantin on 17/06/2023.
//

#include "Game.h"
#include <iostream>
#include <cmath>

enum {w,a,s,d};

Game::Game(int w,int h,int speed):speed(speed),running(true) {
    window.Init("Zombie",w,h);

    player_texture=window.LoadTexture("res/player.png");
    weapon_texture=window.LoadTexture("res/pistol.png");
    road_texture=window.LoadTexture("res/road.png");
    player=new Player(w/2,h/2,60);
    vx=0;
    vy=0;

    roadRect={0,0,1280,720};
}

Game::~Game() {}

bool Game::isRunning() const {
    return running;
}

void Game::Update() {
    int mx,my;
    SDL_GetMouseState(&mx,&my);

    auto event = Window::GetEvent();
    
    switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_MOUSEBUTTONDOWN:
            if(player->CanShoot())
                bullets.push_back(player->Shoot());
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym==SDLK_ESCAPE){
                running=false;
            }else if(event.key.keysym.sym==SDLK_w){
                vy=-speed;
                keys[w]=true;
            }else if(event.key.keysym.sym==SDLK_s){
                vy=speed;
                keys[s]=true;
            }else if(event.key.keysym.sym==SDLK_a){
                vx=-speed;
                keys[a]=true;
            }else if(event.key.keysym.sym==SDLK_d){
                vx=speed;
                keys[d]=true;
            }
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_w){
                keys[w]=false;
            }else if(event.key.keysym.sym==SDLK_s){
                keys[s]=false;
            }else if(event.key.keysym.sym==SDLK_a){
                keys[a]=false;
            }else if(event.key.keysym.sym==SDLK_d){
                keys[d]=false;
            }
            break;
    }

    if(player->GetX()>960){
        roadRect.x-=speed;
        if(roadRect.x<=-1280){
            roadRect.x=0;
        }
    }

    if(!keys[w]&&!keys[s])
        vy=0;
    if(!keys[a]&&!keys[d])
        vx=0;

    player->Update(mx,my,vx,vy);

    for(auto& b:bullets){
        b.Update();
    }
}

void Game::Render() {
    window.Clear();

    window.DrawTexture(road_texture,nullptr,&roadRect,0);
    SDL_Rect road2={roadRect.x+1280,0,1280,720};
    window.DrawTexture(road_texture,nullptr,&road2);

    int p_size=player->GetSize();
    SDL_Rect dst={player->GetX(),player->GetY(),p_size,p_size};
    window.DrawTexture(player_texture,nullptr,&dst,player->GetDirection());

    SDL_FRect gunpos=player->GetGunPos();
    window.DrawTexture(weapon_texture,nullptr,&gunpos,player->GetDirection());

    for(auto& b:bullets){
        SDL_Rect* pos=b.GetPos();
        window.DrawLine(pos->x,pos->y,pos->w,pos->h);
    }

    window.Present();
}