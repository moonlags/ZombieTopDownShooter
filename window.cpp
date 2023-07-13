#include "window.h"

Window::~Window(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void Window::DrawLine(int x,int y,int x1,int y1){
    SDL_SetRenderDrawColor(renderer,255,255,0,255);
    SDL_RenderDrawLine(renderer,x,y,x1,y1);
    SDL_SetRenderDrawColor(renderer,220,220,220,255);
}

void Window::Present() {
    SDL_RenderPresent(renderer);
}

void Window::Clear() {
    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);
}

SDL_Event Window::GetEvent(){
	SDL_Event event;
    SDL_PollEvent(&event);
    return event;
}

void Window::Init(const char* title,int w,int h) {
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);
    Mix_Init(MIX_INIT_MP3);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
    Mix_Volume(-1,MIX_MAX_VOLUME);

    window= SDL_CreateWindow(title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,w,h,SDL_WINDOW_SHOWN);
    renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
}

void Window::PlaySound(Mix_Chunk* sound,int loops){
    Mix_PlayChannel(-1,sound,loops);
}

void Window::DrawTexture(SDL_Texture* texture,SDL_Rect* src,SDL_Rect* dst){
    SDL_RenderCopy(renderer,texture,src,dst);
}

void Window::DrawTexture(SDL_Texture* texture,SDL_Rect* src,SDL_Rect*dst,int angle){
    SDL_RenderCopyEx(renderer,texture,src,dst,angle,nullptr,SDL_FLIP_NONE);
}

void Window::DrawTexture(SDL_Texture* texture,SDL_Rect*src ,SDL_FRect *dst,int angle){
    SDL_RenderCopyExF(renderer,texture,src,dst,angle,nullptr,SDL_FLIP_NONE);
}

SDL_Texture* Window::LoadTexture(const char*filename){
    return IMG_LoadTexture(renderer,filename);
}