
#include "window.hpp"

namespace claw {
  
  Window::Window() : DefaultWidth(640), DefaultHeight(480) {
    HWindow = NULL;
    HSurface = NULL;
  }

  void Window::Init() {
    printf("Trying to initialize window through SDL...\n");
    int initCode = SDL_Init(SDL_INIT_VIDEO);
    if (initCode < 0) {
      printf("Could not initialize window: \n%s\n", SDL_GetError());
      exit(1);
    }
    printf("Initialized window:)\n");
    HWindow = SDL_CreateWindow("Cheeseclaw", 100, 400, DefaultWidth, DefaultHeight, SDL_WINDOW_SHOWN);
    if (HWindow == NULL) {
      printf("Could not show window : %s\n", SDL_GetError());
      exit(1);
    }
    printf("Window created.\n");
    HSurface = SDL_GetWindowSurface(HWindow);
    SDL_FillRect(HSurface, NULL, SDL_MapRGB(HSurface->format, 0x00, 0x00, 0xff));
    SDL_UpdateWindowSurface(HWindow);
    SDL_Delay(5000);
  }
  SDL_Renderer* rend;
}

int main() {
  claw::Window* window = new claw::Window();
  window->Init();
};


