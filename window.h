#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Window{
public:
	void Init(const char* title,int w,int h);
	virtual ~Window();
	void Clear();
	static SDL_Event GetEvent();
    void Present();
	SDL_Texture* LoadTexture(const char* filename);
	void DrawTexture(SDL_Texture* texture,SDL_Rect* src,SDL_Rect *dst);
	void DrawTexture(SDL_Texture* texture,SDL_Rect*src ,SDL_Rect *dst,int angle);
	void DrawTexture(SDL_Texture* texture,SDL_Rect*src ,SDL_FRect *dst,int angle);
	void FillFloor();
	void DrawLine(int x,int y,int x1,int y2);
private:
	SDL_Window* window=nullptr;
	SDL_Renderer* renderer=nullptr;
};