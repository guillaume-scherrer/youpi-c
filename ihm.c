#include <string.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"
#include "lettresXYZ.h"
#include "define.h"

#include <stdio.h> // Test

void ihm(int* e1, int* e2)
{
    int stop = 0;
    SDL_Event event;
    SDL_Rect rect1 = { 16, 16, 0, 48 };
    SDL_Rect rect2 = { 16, 80, 0, 48 };
    SDL_Rect rectV = { 480, 16, 0, 48 };
    SDL_Rect rectD = { 16, 144, 2 * SHEET_SIZE_Z, 2 * SHEET_SIZE_X };
    selection_t button = NONE;
    char msg1[] = "Nombre 1:    ";
    char msg2[] = "Nombre 2:    ";
    gfx_text_t num1;
    gfx_text_t num2;
    gfx_text_t val;
    
    gfx_manager(CREATE);
    gfx_clear(31, 31, 31, 255);
    
    *e1 = 0;
    *e2 = 0;
    num1 = gfx_createText(rect1, BACK_COLOR, FRONT_COLOR, msg1);
    num2 = gfx_createText(rect2, BACK_COLOR, FRONT_COLOR, msg2);
    val = gfx_createText(rectV, BACK_COLOR, FRONT_COLOR, "Valider");
    
    gfx_renderText(val);
    gfx_renderQuad(rectD, BACK_COLOR);
    
    while(!stop)
    {
        SDL_WaitEvent(&event);
        
        switch(event.type)
        {
            case SDL_QUIT:
            {
                stop = 1;
            } break;
            
            case SDL_MOUSEBUTTONUP:
            {
                if(clicked(event, num1.rect))
                {
                    button = NUM1;
                    num1.color = BACK_SELECT_COLOR;
                    num2.color = BACK_COLOR;
                } else if(clicked(event, num2.rect))
                {
                    button = NUM2;
                    num1.color = BACK_COLOR;
                    num2.color = BACK_SELECT_COLOR;
                } else if(clicked(event, val.rect))
                {
                    plotData(rectD, *e1, *e2);
                } else
                {
                    button = NONE;
                    num1.color = BACK_COLOR;
                    num2.color = BACK_COLOR;
                }
            } break;
            
            case SDL_KEYDOWN:
            {
                int* e = NULL;
                char* msg = NULL;
                gfx_text_t* num;
                
                if(button == NUM1)
                {
                    e = e1;
                    msg = msg1;
                    num = &num1;
                } else
                {
                    e = e2;
                    msg = msg2;
                    num = &num2;
                }
                
                if(button != NONE && msg[strlen(msg) - 1] == ' ' && event.key.keysym.sym >= SDLK_KP_1 && event.key.keysym.sym <= SDLK_KP_0)
                {
                    int add = event.key.keysym.sym == SDLK_KP_0 ? 0 : event.key.keysym.sym - SDLK_KP_1 + 1;
                    
                    *e *= 10;
                    *e += add;
                    
                    updateNum(num, msg, add, FRONT_COLOR);
                }
            } break;
        }
        
        gfx_renderText(num1);
        gfx_renderText(num2);
        gfx_render();
    }
    
    gfx_destroyText(num1);
    gfx_destroyText(num2);
    gfx_destroyText(val);
    gfx_manager(DESTROY);
}

void updateNum(gfx_text_t* num, char* msg, int add, SDL_Color frontColor)
{
    int i;
    int canWrite = 0;
    
    for(i = 0; msg[i] != ' ' || !canWrite; ++i)
    {
        if(msg[i] == ':')
        {
            canWrite = 1;
        }
    }
    
    msg[i] = add + '0';
    
    gfx_destroyText(*num);
    *num = gfx_createText(num->rect, num->color, frontColor, msg);
}

int clicked(SDL_Event event, SDL_Rect rect)
{
    return event.button.x >= rect.x && event.button.x < rect.x + rect.w && event.button.y >= rect.y && event.button.y < rect.y + rect.h;
}

void plotData(SDL_Rect sheet, int e1, int e2)
{
    int i;
    int np;
    char* romanNumber = conversion(calcul(e1, e2));
    float tx[MAX_XYZ];
    float ty[MAX_XYZ];
    float tz[MAX_XYZ];
    int ttr[MAX_XYZ];
    
    lettresXYZ(romanNumber, tx, ty, tz, ttr, &np);
    
    if(romanNumber)
    {
        free(romanNumber);
    }
    
    gfx_renderQuad(sheet, BACK_COLOR);
    SDL_SetRenderDrawColor(gfx_manager(GET), 0, 0, 0, 255);
    
    for(i = 0; i < np; ++i)
    {
        SDL_RenderDrawPoint(gfx_manager(GET), tz[i] * 2 + sheet.x + sheet.w / 2, -tx[i] * 2 + sheet.y + sheet.h);
        printf("%d: %f # %f\n", i, tz[i] * 2 + sheet.x + sheet.w / 2, -tx[i] * 2 + sheet.y + sheet.h);
    }
    
    gfx_render();
}

SDL_Renderer* gfx_manager(gfx_action_t action)
{
    static SDL_Window* window = NULL;
    static SDL_Renderer* renderer = NULL;
    SDL_Renderer* result = NULL;
    
    switch(action)
    {
        case CREATE:
        {
            SDL_Init(SDL_INIT_VIDEO);
            TTF_Init();
            
            window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
            renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
        } break;
        
        case DESTROY:
        {
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            
            TTF_Quit();
            SDL_Quit();
        } break;
        
        case GET:
        {
            result = renderer;
        } break;
    }
    
    return result;
}

void gfx_clear(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
    SDL_SetRenderDrawColor(gfx_manager(GET), r, g, b, a);
    SDL_RenderClear(gfx_manager(GET));
}

void gfx_render()
{
    SDL_RenderPresent(gfx_manager(GET));
}

void gfx_renderQuad(SDL_Rect rect, SDL_Color color)
{
    SDL_SetRenderDrawColor(gfx_manager(GET), color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(gfx_manager(GET), &rect);
}

gfx_text_t gfx_createText(SDL_Rect rect, SDL_Color backColor, SDL_Color frontColor, const char* string)
{
    TTF_Font* font = TTF_OpenFont("./SourceCodePro-Regular.otf", 64);
    SDL_Surface* surface = TTF_RenderText_Blended(font, string, frontColor);
    gfx_text_t result;
    
    rect.w = rect.h * strlen(string) / 2;
    result.rect = rect;
    result.color = backColor;
    result.texture = SDL_CreateTextureFromSurface(gfx_manager(GET), surface);
    
    SDL_FreeSurface(surface);
    TTF_CloseFont(font);
    
    return result;
}

void gfx_destroyText(gfx_text_t text)
{
    SDL_DestroyTexture(text.texture);
}

void gfx_renderText(gfx_text_t text)
{
    gfx_renderQuad(text.rect, text.color);
    SDL_RenderCopy(gfx_manager(GET), text.texture, NULL, &text.rect);
}