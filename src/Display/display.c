#include "display.h"
#include <stdlib.h>
#include <stdio.h>

void ClearScreen(Display *display) {
    SDL_SetRenderDrawColor(display->renderer, 0, 0, 0, 0);
    SDL_RenderClear(display->renderer);
    SDL_RenderPresent(display->renderer);
    

}
Display* DisplayInit() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *win = SDL_CreateWindow("CHIP-8", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Renderer *render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
    Display *display = malloc(sizeof(Display));
    display->renderer = render;
    display->win = win;
    const int widthScalarFactor   = 2 * (WINDOW_WIDTH / WIDTH);
    const int heightScalarFactor  = 2 * (WINDOW_HEIGHT / HEIGHT);

    for(int i = 0; i < WIDTH; i++) {
        for(int j = 0; j < HEIGHT; j++) {
            SDL_Rect rect = {
                .x = i * widthScalarFactor,
                .y = j * heightScalarFactor,
                .h = heightScalarFactor,
                .w = widthScalarFactor
            };
            display->display[i][j] = rect;
        }
    }
    return display;
}

void drawFrame(Display *display) {

    SDL_SetRenderDrawColor(display->renderer, 255, 255, 255, 255);

    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
            SDL_RenderDrawRect(display->renderer, &display->display[i][j]);
        }
    }
    SDL_RenderPresent(display->renderer);
}

