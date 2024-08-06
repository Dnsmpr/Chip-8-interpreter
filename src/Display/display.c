#include "display.h"
#include <stdlib.h>
#include <stdio.h>

void ClearScreen(Display *display) {
    SDL_SetRenderDrawColor(
        display->renderer,
         0, 0, 0, 0
    );
    SDL_RenderClear(display->renderer);
    SDL_RenderPresent(display->renderer);
    

}
Display* DisplayInit() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow(
        GAME_TITLE, 
        SDL_WINDOWPOS_UNDEFINED, 
        SDL_WINDOWPOS_UNDEFINED, 
        WINDOW_WIDTH, WINDOW_HEIGHT, 
        SDL_WINDOW_ALLOW_HIGHDPI
    );
    SDL_Renderer *render = SDL_CreateRenderer(
        win, 
        -1, 
        SDL_RENDERER_ACCELERATED
    );
    Display *display = malloc(sizeof(Display));
    display->renderer = render;
    display->win = win;
    const int widthScalarFactor   = WINDOW_WIDTH / WIDTH;
    const int heightScalarFactor  = WINDOW_HEIGHT / HEIGHT;

    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {

            display->display[i][j].bounds = (SDL_Rect) {
                .x = i * widthScalarFactor,
                .y = j * heightScalarFactor,
                .h = heightScalarFactor,
                .w = widthScalarFactor
            };
            display->display[i][j].currentState = OFF;
        }
    }
    return display;
}

void drawFrame(const Display *display) {

    SDL_SetRenderDrawColor(
        display->renderer, 
        250, 165, 0, 255
    );

    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            if(display->display[i][j].currentState == ON) {
                SDL_RenderFillRect(
                    display->renderer, 
                    &display->display[i][j].bounds
                );
            }
        }
    }
    SDL_RenderPresent(display->renderer);
}

void drawSprite(Display *display, const uint8_t x, const uint8_t y, const uint8_t sprite) {

    uint8_t yNew = y % HEIGHT;
    for(int i = 0; i < 8; i++) {
        uint8_t xNew = (x + i) % WIDTH;
        display->display[xNew][yNew].currentState ^= (sprite >> i) & 0x1;
    }

}

