#pragma once
#include <algorithm>
#include <cmath>
#include <numbers>

#include "Vec2.h"
#include "Vec3.h"
#include "mat2.h"

namespace VecMatLib {
Vec2 lerp(const Vec2& a, const Vec2& b, double t);
Vec3 lerp(const Vec3& a, const Vec3& b, double t);

double magnitude(const Vec2& v);

Mat2 rotationMat2(double angle);

template <typename Vec>
  requires requires(Vec v) {
    v.dot(v);
    v.magnitude();
  }
double angle(const Vec& a, const Vec& b) {
  double dot = a.dot(b);
  double mag = b.magnitude() * a.magnitude();

  double val = dot / mag;
  val = std::clamp(val, -1.0, 1.0);
  return std::acos(val);
}

template <typename Vec>
  requires requires(Vec v) { v.magnitude(); }
double distance(const Vec& a, const Vec& b) {
  Vec ab = a - b;
  return ab.magnitude();
}

template <typename Vec>
requires requires(Vec a, Vec b, double s)
{
  { a.dot(b)} -> std::convertible_to<double>;
  { b * s} -> std::same_as<Vec>;
}
Vec project(const Vec& a, const Vec& b) {
  double ab = a.dot(b);
  double bb = b.dot(b);

  if (bb == 0) {
    return Vec{0,0};
  }

  return b * (ab/bb);
}
}  // namespace VecMatLib
