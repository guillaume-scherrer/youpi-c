#include <stdio.h>
#include <string.h>
#include "ihm.h"
#include "calcul.h"
#include "conversion.h"
#include "define.h"

// void ihm(int* e1, int* e2)
// {
//     static SDL_Window* window = NULL;
//     static SDL_Renderer* renderer = NULL;
//     text_t text;
//     int* numbers[] = {e1, e2};
//
//     text.font = NULL;
//     text.content = NULL;
//     text.texture = NULL;
//     text.rect = (SDL_Rect){0, 0, 0, 64};
//     text.color = (SDL_Color){255, 255, 255, 255};
//
//     SDL_Init(SDL_INIT_VIDEO);
//     TTF_Init();
//
//     window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
//     renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
//
//     text.font = TTF_OpenFont("./SourceCodePro-Regular.otf", 64);
//
//     loop(renderer, &text, numbers, 2);
//
//     SDL_DestroyTexture(text.texture);
//     SDL_FreeSurface(text.content);
//     TTF_CloseFont(text.font);
//
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//
//     TTF_Quit();
//     SDL_Quit();
// }

// void loop(SDL_Renderer* renderer, text_t* text, int** numbers, int numCount)
// {
//     static const char baseMessage[] = "Nombre: ";
//     static const char numMessage[] = "%d";
//     char tmp[MAX_STRING_SIZE];
//     int stop = 0;
//     int numDone = 0;
//     int number = 0;
//     int numSize = 0;
//     SDL_Event event;
//
//     SDL_SetRenderDrawColor(renderer, 31, 31, 31, 255);
//     SDL_RenderClear(renderer);
//
//     newLine(renderer, text, baseMessage);
//
//     changeText(renderer, text, "");
//
//     while(!stop && numDone < 2)
//     {
//         SDL_WaitEvent(&event);
//
//         switch(event.type)
//         {
//             case SDL_QUIT:
//             {
//                 stop = 1;
//             } break;
//
//             case SDL_KEYDOWN:
//             {
//                 if(numSize < 4 && event.key.keysym.sym >= SDLK_KP_1 && event.key.keysym.sym <= SDLK_KP_0)
//                 {
//                     number *= 10;
//                     number += event.key.keysym.sym == SDLK_KP_0 ?
//                         0:
//                         event.key.keysym.sym - SDLK_KP_1 + 1;
//
//                     ++numSize;
//
//                     sprintf(tmp, numMessage, number);
//                     changeText(renderer, text, tmp);
//                 } else if(event.key.keysym.sym == SDLK_RETURN)
//                 {
//                     *(numbers[numDone]) = number;
//                     number = 0;
//                     ++numDone;
//                     numSize = 0;
//                     text->rect.x = 0;
//                     text->rect.y += text->rect.h;
//
//                     if(numDone < 2)
//                     {
//                         newLine(renderer, text, baseMessage);
//                     }
//
//                     changeText(renderer, text, "");
//
//                 } else if(event.key.keysym.sym == SDLK_ESCAPE)
//                 {
//                     stop = 1;
//                 }
//             } break;
//
//             default:
//                 break;
//         }
//
//         SDL_RenderCopy(renderer, text->texture, NULL, &(text->rect));
//         SDL_RenderPresent(renderer);
//     }
//
//     char* result = conversion(calcul(*numbers[0], *numbers[1]));
//
//     changeText(renderer, text, result);
//     SDL_RenderCopy(renderer, text->texture, NULL, &(text->rect));
//     SDL_RenderPresent(renderer);
//     SDL_Delay(1500);
//
//     free(result);
// }

// void changeText(SDL_Renderer* renderer, text_t* text, const char* content)
// {
//     if(text->content)
//     {
//         SDL_FreeSurface(text->content);
//     }
//
//     if(text->texture)
//     {
//         SDL_DestroyTexture(text->texture);
//     }
//
//     text->content = TTF_RenderText_Blended(text->font, content, text->color);
//     text->texture = SDL_CreateTextureFromSurface(renderer, text->content);
//     text->rect.w = text->rect.h / 2 * strlen(content);
// }

// void newLine(SDL_Renderer* renderer, text_t* text, const char* content)
// {
//     changeText(renderer, text, content);
//     SDL_RenderCopy(renderer, text->texture, NULL, &(text->rect));
//     text->rect.x = text->rect.w;
// }

// Test

void ihm(int* e1, int* e2)
{
    int stop = 0;
    SDL_Event event;
    SDL_Rect rect1 = { 16, 16, 0, 48 };
    SDL_Rect rect2 = { 16, 80, 0, 48 };
    SDL_Rect rectV = { 480, 16, 0, 48 };
    selection_t button = NONE;
    char msg1[] = "Nombre 1:    ";
    char msg2[] = "Nombre 2:    ";
    gfx_text_t num1;
    gfx_text_t num2;
    gfx_text_t val;
    
    gfx_manager(CREATE);
    
    *e1 = 0;
    *e2 = 0;
    num1 = gfx_createText(rect1, BACK_COLOR, FRONT_COLOR, msg1);
    num2 = gfx_createText(rect2, BACK_COLOR, FRONT_COLOR, msg2);
    val = gfx_createText(rectV, BACK_COLOR, FRONT_COLOR, "Valider");
    
    gfx_clear(31, 31, 31, 255);
    gfx_renderText(num1);
    gfx_renderText(num2);
    gfx_renderText(val);
    
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
                    stop = 1;
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
                    int add = event.key.keysym.sym == SDLK_KP_0 ?
                        0:
                        event.key.keysym.sym - SDLK_KP_1 + 1;
                    
                    *e *= 10;
                    *e += add;
                    updateNum(num, msg, add, FRONT_COLOR);
                }
            } break;
        }
        
        gfx_renderText(num1);
        gfx_renderText(num2);
        gfx_renderText(val);
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
    // gfx_renderText(*num);
}

int clicked(SDL_Event event, SDL_Rect rect)
{
    return event.button.x >= rect.x && event.button.x < rect.x + rect.w && event.button.y >= rect.y && event.button.y < rect.y + rect.h;
}

static SDL_Renderer* gfx_manager(gfx_action_t action)
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