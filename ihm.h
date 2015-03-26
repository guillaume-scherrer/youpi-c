#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct
{
    TTF_Font* font;
    SDL_Surface* content;
    SDL_Texture* texture;
    SDL_Rect rect;
    SDL_Color color;
} text_t;

typedef enum
{
    NONE,
    NUM1,
    NUM2
} selection_t;

typedef enum
{
    CREATE,
    DESTROY,
    GET
} gfx_action_t;

typedef struct
{
    SDL_Rect rect;
    SDL_Color color;
    SDL_Texture* texture;
} gfx_text_t;

void ihm(int* e1, int* e2);

void updateNum(gfx_text_t* num, char* msg, int add, SDL_Color frontColor);

int clicked(SDL_Event event, SDL_Rect rect);

static SDL_Renderer* gfx_manager(gfx_action_t action);

void gfx_clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

void gfx_render();

void gfx_renderQuad(SDL_Rect rect, SDL_Color color);

gfx_text_t gfx_createText(SDL_Rect rect, SDL_Color backColor, SDL_Color frontColor, const char* string);

void gfx_destroyText(gfx_text_t text);

void gfx_renderText(gfx_text_t text);