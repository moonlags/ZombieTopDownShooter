//
// Created by Konstantin on 17/06/2023.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#pragma once

#include "window.h"
#include <vector>
#include "Player.hpp"
#include "Zombie.hpp"

class Game {
public:
    Game(int w,int h,int speed);
    bool isRunning() const;
    virtual ~Game();
    void Update();
    void Render();
private:
    SDL_Texture* player_texture;
    SDL_Texture* weapon_texture;
    SDL_Texture* road_texture;
    SDL_Texture* zombie_texture;
    Mix_Chunk* shoot_sound;
    bool running;
    Window window;
    Player* player;
    std::vector<Zombie> zombies;
    Bullet bullet{-100,-100,0};
    int vx,vy;
    int speed;
    SDL_FRect roadRect;
    bool keys[4];
    int score;
};


#endif //SNAKE_GAME_H
