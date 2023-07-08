//
// Created by Konstantin on 17/06/2023.
//

#include "Game.h"
#include <iostream>
#include <cmath>

Game::Game(int w,int h):running(true),mouseDown(false) {
    window.Init("Zombie",w,h);

    player_texture=window.LoadTexture("res/player.png");
    weapon_texture=window.LoadTexture("res/pistol.png");
    road_texture=window.LoadTexture("res/road.png");
    player=new Player(w/2,h/2,5,5,60);
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
            mouseDown=true;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseDown=false;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym==SDLK_ESCAPE){
                running=false;
            }else if(event.key.keysym.sym==SDLK_w){
                vy=-1;
            }else if(event.key.keysym.sym==SDLK_s){
                vy=1;
            }else if(event.key.keysym.sym==SDLK_a){
                vx=-1;
            }else if(event.key.keysym.sym==SDLK_d){
                vx=1;
            }
            break;
        case SDL_KEYUP:
            if(event.key.keysym.sym==SDLK_w){
                vy=0;
            }else if(event.key.keysym.sym==SDLK_s){
                vy=0;
            }else if(event.key.keysym.sym==SDLK_a){
                vx=0;
            }else if(event.key.keysym.sym==SDLK_d){
                vx=0;
            }
            break;
    }

    player->Update(mx,my,vx,vy);
}

void Game::Render() {
    window.Clear();

    roadRect.x-=0.5;
    if(roadRect.x<=-1280){
        roadRect.x=0;
    }
    window.DrawTexture(road_texture,nullptr,&roadRect,0);
    SDL_Rect road2={roadRect.x+1280,0,1280,720};
    window.DrawTexture(road_texture,nullptr,&road2);

    SDL_Rect dst={player->GetX(),player->GetY(),player->GetSize(),player->GetSize()};
    window.DrawTexture(player_texture,nullptr,&dst,player->GetDirection());

    SDL_FRect gunpos=player->GetGunPos();
    window.DrawTexture(weapon_texture,nullptr,&gunpos,player->GetDirection());

    window.Present();
}