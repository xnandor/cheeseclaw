
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

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
