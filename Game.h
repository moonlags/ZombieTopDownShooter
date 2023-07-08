//
// Created by Konstantin on 17/06/2023.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#pragma once

#include "window.h"
#include <vector>
#include "Player.hpp"

class Game {
public:
    Game(int w,int h);
    bool isRunning() const;
    virtual ~Game();
    void Update();
    void Render();
private:
    SDL_Texture* player_texture;
    SDL_Texture* weapon_texture;
    SDL_Texture* floor_texture;
    SDL_Texture* zombie_texture;
    bool running;
    Window window;
    //Camera camera;
    Player* player;
    //std::vector<Zombie> zombies;
    //std::vector<Bullet> bullets;
    bool mouseDown;
    int vx,vy;
};


#endif //SNAKE_GAME_H
