#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SHAPE_SIZE = 200;
const int FRAME_DELAY = 30; // Delay in milliseconds between frames

void drawTriangle(SDL_Renderer *renderer, int centerX, int centerY, float factor) {
    SDL_Point points[4];
    int halfSize = static_cast<int>(SHAPE_SIZE / 2 * factor);

    points[0].x = centerX;
    points[0].y = centerY - halfSize;

    points[1].x = centerX - halfSize;
    points[1].y = centerY + halfSize;

    points[2].x = centerX + halfSize;
    points[2].y = centerY + halfSize;

    points[3] = points[0]; // Close the triangle

    SDL_RenderDrawLines(renderer, points, 4);
}

void drawSquare(SDL_Renderer *renderer, int centerX, int centerY, float factor) {
    SDL_Rect rect;
    int halfSize = static_cast<int>(SHAPE_SIZE / 2 * factor);

    rect.x = centerX - halfSize;
    rect.y = centerY - halfSize;
    rect.w = 2 * halfSize;
    rect.h = 2 * halfSize;

    SDL_RenderDrawRect(renderer, &rect);
}

void drawCircle(SDL_Renderer *renderer, int centerX, int centerY, float factor) {
    int radius = static_cast<int>(SHAPE_SIZE / 2 * factor);
    int offsetX, offsetY, d;

    offsetX = radius;
    offsetY = 0;
    d = 1 - radius;

    SDL_Point points[2 * 4 * radius]; // Array to hold the circle points
    int idx = 0;

    while (offsetX >= offsetY) {
        points[idx++] = SDL_Point{ centerX + offsetX, centerY + offsetY };
        points[idx++] = SDL_Point{ centerX + offsetY, centerY + offsetX };
        points[idx++] = SDL_Point{ centerX - offsetY, centerY + offsetX };
        points[idx++] = SDL_Point{ centerX - offsetX, centerY + offsetY };
        points[idx++] = SDL_Point{ centerX - offsetX, centerY - offsetY };
        points[idx++] = SDL_Point{ centerX - offsetY, centerY - offsetX };
        points[idx++] = SDL_Point{ centerX + offsetY, centerY - offsetX };
        points[idx++] = SDL_Point{ centerX + offsetX, centerY - offsetY };

        if (d < 0) {
            d += 2 * offsetY + 1;
        } else {
            d += 2 * (offsetY - offsetX) + 1;
            offsetX--;
        }
        offsetY++;
    }

    SDL_RenderDrawPoints(renderer, points, idx);
}

int main(int argc, char* args[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    bool quit = false;
    SDL_Event e;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Shape Transformation",
                              SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    int centerX = SCREEN_WIDTH / 2;
    int centerY = SCREEN_HEIGHT / 2;
    float factor = 0.0f;
    bool transformingToSquare = true;
    bool transformingToCircle = false;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        if (transformingToSquare) {
            drawTriangle(renderer, centerX, centerY, 1.0f - factor);
            drawSquare(renderer, centerX, centerY, factor);
        } else if (transformingToCircle) {
            drawSquare(renderer, centerX, centerY, 1.0f - factor);
            drawCircle(renderer, centerX, centerY, factor);
        }

        SDL_RenderPresent(renderer);

        if (transformingToSquare) {
            factor += 0.01f;
            if (factor >= 1.0f) {
                factor = 0.0f;
                transformingToSquare = false;
                transformingToCircle = true;
            }
        } else if (transformingToCircle) {
            factor += 0.01f;
            if (factor >= 1.0f) {
                factor = 0.0f;
                transformingToCircle = false;
            }
        }

        SDL_Delay(FRAME_DELAY);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
