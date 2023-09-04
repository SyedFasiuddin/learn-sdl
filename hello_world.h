#ifndef HELLO_WORLD_H_
#define HELLO_WORLD_H_

#include <SDL2/SDL.h>
#include <iostream>

void hello_world(void);

#endif // HELLO_WORLD_H_

#ifdef HELLO_WORLD_IMPL

#define WIDTH 500
#define HEIGHT 500

void hello_world(void) {
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    SDL_Event event;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "Could not initialize SDL2: " << SDL_GetError() << std::endl;
        return;
    }

    window = SDL_CreateWindow( "Hello World: SDL2", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT,
                              SDL_WINDOW_SHOWN);

    if (window == NULL) {
        std::cerr << "Could not create window: " << SDL_GetError() << std::endl;
        return;
    }

    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL,
                 SDL_MapRGB(screenSurface->format, 0x18, 0x18, 0x18));
    SDL_UpdateWindowSurface(window);

    while (SDL_WaitEvent(&event)) {
        if (event.type == SDL_QUIT) break;
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}

#endif // HELLO_WORLD_IMPL
