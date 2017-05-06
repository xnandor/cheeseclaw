
#include "window.hpp"

namespace claw {
  
  Window::Window() : DefaultWidth(640), DefaultHeight(480) {
    HWindow = NULL;
    HSurface = NULL;
  }

  void Window::Init() {
    printf("Trying to Init SDL...\n");
    int initCode = SDL_Init(SDL_INIT_VIDEO);
    if (initCode < 0) {
      printf("Could not init SDL: \n%s\n", SDL_GetError());
      exit(1);
    }
    printf("Initialized SDL:)\n");
    HWindow = SDL_CreateWindow("SDL Tutorial", 100, 400, DefaultWidth, DefaultHeight, SDL_WINDOW_SHOWN);
    if (HWindow == NULL) {
      printf("COULD NOT SHOW WINDOW:(  : %s\n", SDL_GetError());
      exit(1);
    }
    printf("TADA...\n");
    HSurface = SDL_GetWindowSurface(HWindow);
    SDL_FillRect(HSurface, NULL, SDL_MapRGB(HSurface->format, 0x00, 0x00, 0xff));
    SDL_UpdateWindowSurface(HWindow);
    SDL_Delay(5000);
  }

}

int main() {
  claw::Window* window = new claw::Window();
  window->Init();
};


