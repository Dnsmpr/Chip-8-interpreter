#ifndef DISPLAY
#define DISPLAY
#define WIDTH         64
#define HEIGHT        32
#define WINDOW_HEIGHT 512
#define WINDOW_WIDTH  (2 * WINDOW_HEIGHT)
#define GAME_TITLE    "Chip8"
#include <stdint.h>
#include <SDL2/SDL.h>

typedef enum PixelState {
    OFF = 0,
    ON = 1
} PixelState;

typedef struct Pixel {
    SDL_Rect bounds;
    PixelState currentState;
} Pixel;

typedef struct Display {
    Pixel        display[WIDTH][HEIGHT];
    SDL_Window   *win;
    SDL_Renderer *renderer;
} Display;

void ClearScreen(Display *display);
Display* DisplayInit(void);
void drawFrame(const Display *display);
void drawSprite(Display *display, const uint8_t x, const uint8_t y, const uint8_t sprite);
#endif