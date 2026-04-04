//
// Created by chice on 3/23/2026.
//

#ifndef VECMATLIB_VEC3_H
#define VECMATLIB_VEC3_H

#include <numbers>

#include "Vec2.h"

namespace VecMatLib {

template <typename T>
class Vec3 {
 public:
  T x, y, z;
  Vec3(T x, T y, T z) : x(x), y(y), z(z) {}
  Vec3() : x(0), y(0), z(0) {}

  T magnitude() const;
  T dot(const Vec3& v) const;
  Vec3 cross(const Vec3& v) const;

  Vec3 normal() const;

  Vec3 operator-(const Vec3& v) const;
  Vec3 operator+(const Vec3& v) const;
  Vec3 operator*(T s) const;
  Vec3 operator/(T s) const;

  bool operator==(const Vec3& v) const;
};
}  // namespace VecMatLib

#endif  // VECMATLIB_VEC3_H