

#ifndef MAPH_H
#define MAPH_H

// Can uncomment USE_<LIB> defines to disable library dependencies and support for 3PLs.
#define MAPH_USE_SDL2
#if defined(MAPH_USE_SDL2)
#include <SDL2/SDL.h>
#endif

namespace claw {

  ////////////////////////// VEC
  template <typename T>
  class vec {
  public:
    T x;
    T y;
    T z;
    T w;
  public:
    inline vec() {
      this->x = 0;
      this->y = 0;
      this->z = 0;
      this->w = 0;
    }
    inline vec(const T &x, const T &y) {
      this->x = x;
      this->y = y;
      this->z = 0;
      this->w = 0;
    }
    inline vec(const T &x, const T &y, const T &z) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = 1;
    }
    inline vec(const T &x, const T &y, const T &z, const T &w) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w;
    }
  public:
    inline vec<T> operator+(const vec<T> &v) {
      return vec<T>(x+v.x, y+v.y, z+v.z, w+v.w);
    }
    inline vec<T> operator-(const vec<T> &v) {
      return vec<T>(x-v.x, y-v.y, z-v.z, w-v.w);
    }
    inline T operator*(const vec<T> &v) {
      return x*v.x + y*v.y + z*v.z + w*v.w;
    }
    inline vec<T> operator*(const T &t) {
      return vec<T>(x*t, y*t, z*t, w*t);
    }
    inline vec<T>& operator^(const vec<T> &v) {
      return v;
    }
    inline T& operator[](int i) {
      if (i == 0) {
        return x;
      } else if (i == 1) {
        return y;
      } else if (i == 2) {
        return z;
      } else if (i == 3) {
        return w;
      }
    }
  };
  
  ////////////////////////// MAT
  template <typename T>
  class mat {
  public:
    vec<T> r1;
    vec<T> r2;
    vec<T> r3;
    vec<T> r4;
  public:
    inline mat() {
      r1.x = 1;
      r2.y = 1;
      r3.z = 1;
      r4.w = 1;      
    }
  public:
    inline vec<T>& operator[](int i) {
      if (i == 0) {
        return r1;
      } else if (i == 1) {
        return r2;
      } else if (i == 2) {
        return r3;
      } else if (i == 3) {
        return r4;
      }
    }
  };
  
  ////////////////////////// RECT
  template <typename T>
  class rect {
  public:
    T x;
    T y;
    T w;
    T h;
  public:
    inline rect() {
      this->x = 0;
      this->y = 0;
      this->w = 0;
      this->h = 0;
    }
    inline rect(const rect &r) {
      this->x = r.x;
      this->y = r.y;
      this->w = r.w;
      this->h = r.h;
    }
    inline rect(const T &x, const T &y, const T &w, const T &h) {
      this->x = x;
      this->y = y;
      this->w = w;
      this->h = h;
    }
    #if defined(MAPH_USE_SDL2)
    inline rect(SDL_Rect &r) {
      this->x = r.x;
      this->y = r.y;
      this->w = r.w;
      this->h = r.h;
    }
    #endif
  public:
    #if defined(MAPH_USE_SDL2)
    inline operator SDL_Rect() {
      SDL_Rect r;
      r.x = x;
      r.y = y;
      r.w = w;
      r.h = h;
      return r;
    }
    #endif
  };
  
}

#endif
