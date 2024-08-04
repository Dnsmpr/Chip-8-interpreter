#ifndef DISPLAY
#define DISPLAY
#define WIDTH  64
#define HEIGHT 32
#define WINDOW_HEIGHT 256
#define WINDOW_WIDTH  (2 * WINDOW_HEIGHT)
#include <stdint.h>
#include <SDL2/SDL.h>

typedef struct Display {
    SDL_Rect     display[WIDTH][HEIGHT];
    SDL_Window   *win;
    SDL_Renderer *renderer;
} Display;

void ClearScreen(Display *display);
Display* DisplayInit(void);
void drawFrame(Display *display);
#endif