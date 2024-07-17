#include <SDL2/SDL.h>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;

    SDL_Surface* screenSurface = nullptr;

    SDL_Surface* bmpSurface = nullptr;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("BMP Viewer",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    screenSurface = SDL_GetWindowSurface(window);

    bmpSurface = SDL_LoadBMP("image.bmp");
    if (bmpSurface == nullptr) {
        std::cerr << "Unable to load image! SDL Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_BlitSurface(bmpSurface, nullptr, screenSurface, nullptr);

    SDL_UpdateWindowSurface(window);

    SDL_Delay(5000);

    SDL_FreeSurface(bmpSurface);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
