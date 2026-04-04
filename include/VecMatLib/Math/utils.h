#pragma once
#include <algorithm>
#include <cmath>
#include <numbers>

#include "../Core/Mat2.h"
#include "../Core/Vec2.h"
#include "../Core/Vec3.h"

namespace VecMatLib {

template <typename Vec>
  requires requires(Vec v) {
    v.dot(v);
    v.magnitude();
  }
double angle(const Vec& a, const Vec& b) {
  double dot = a.dot(b);
  double mag = b.magnitude() * a.magnitude();

  double cosTheta = dot / mag;
  cosTheta = std::clamp(cosTheta, -1.0, 1.0);
  return std::acos(cosTheta);
}

template <typename Vec>
  requires requires(Vec v) { v.magnitude(); }
double distance(const Vec& a, const Vec& b) {
  Vec ab = a - b;
  return ab.magnitude();
}

template <typename Vec>
  requires requires(Vec a, Vec b, double s) {
    { a.dot(b) } -> std::convertible_to<double>;
    { b * s } -> std::same_as<Vec>;
  }
Vec project(const Vec& a, const Vec& b) {
  double ab = a.dot(b);
  double bb = b.dot(b);

  if (bb == 0) {
    return Vec{0, 0};
  }

  return b * (ab / bb);
}

template <typename Vec>
  requires requires(Vec v) { v.magnitude(); }
void clamp(Vec& a, double max) {
  if (a.magnitude() > max) {
    a = a * (max / a.magnitude());
  }
}

template<typename Vec>
requires requires(Vec a, Vec b, double s) {
  { a.dot(b) } -> std::convertible_to<double>;
  { b * s } -> std::same_as<Vec>;
}
Vec lerp(Vec& a, Vec& b, double t ) {
  return a + ((b - a) * t);
}


}  // namespace VecMatLib
