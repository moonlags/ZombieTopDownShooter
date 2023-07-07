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
    player=new Player(w/2,h/2,0,0);
}

Game::~Game() {}

bool Game::isRunning() const {
    return running;
}

void Game::Update() {
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
            if(event.key.keysym.sym==SDLK_ESCAPE)
                running=false;
    }


    int mx,my;
    SDL_GetMouseState(&mx,&my);

    player->Update(mx,my);
}

void Game::Render() {
    window.Clear();

    window.FillFloor();

    SDL_Rect dst={player->GetX()-50,player->GetY()-50,100,100};
    window.DrawTexture(player_texture,nullptr,&dst,player->GetDirection());

    SDL_FRect gunpos=player->GetGunPos();
    window.DrawTexture(weapon_texture,nullptr,&gunpos,player->GetDirection());

    int mx,my;
    SDL_GetMouseState(&mx,&my);

    window.DrawLine(player->GetX(),player->GetY(),mx,my);

    window.Present();
}