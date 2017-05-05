

#ifndef MAPH_H
#define MAPH_H

namespace claw {

  template <typename T>
  class vec {
  public:
    T x;
    T y;
    T z;
    T w;
  public:
    inline vec(T x, T y, T z, T w) {
      this->x = x;
      this->y = y;
      this->z = z;
      this->w = w;
    }
  public:
    vec<T> operator+(vec<T> v) {
      return vec<T>(x+v.x, y+v.y, z+v.z, w+v.w);
    }
  
    vec<T> operator-(vec<T> v) {
      return vec<T>(x-v.x, y-v.y, z-v.z, w-v.w);
    }
  
    T operator*(vec<T> v) {
      return x*v.x + y*v.y + z*v.z + w*v.w;
    }
  
    vec<T> operator^(vec<T> v) {
      return v;
    }
  };

}

#endif
