#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#if defined(__APPLE__) && defined(__MACH__)
#include <OpenGL/gl.h>
#else
#include <GL/gl.h>
#endif

#include <set>
#include "maph.hpp"

#ifndef CC_COMPONENT_H
#define CC_COMPONENT_H

namespace claw {

  // ENUMS
  enum Align { alLeft, alTop, alRight, alBottom, alCenter, alCustom};
  
  class Component;
  
  typedef std::set<Component*> CSet;
  
  class Component {
  private:
    Component* owner;
    CSet slaves;
    Component* parent;
    CSet children;
    SDL_Surface* surface;
    claw::rect<int> clip;
    Align align;
  public:
    Component(Component* Owner);
    ~Component();
    void SetParent(Component* p);
    void SetOwner(Component* p);
    void SetAlign(Align a);
  };

}
#endif
