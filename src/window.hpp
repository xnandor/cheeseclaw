
#include <SDL.h>

#ifndef WINDOW_H
#define WINDOW_H

namespace claw {
  

  class Window {
  public:
    SDL_Window* HWindow;
    SDL_Surface* HSurface;
    const int DefaultWidth;
    const int DefaultHeight;
  public:
    Window();
    void Init();
      

  };

}
#endif
