#pragma once
#include <cmath>
#include <numbers>

template <typename T>
struct Epsilon {
  static constexpr T value = T(0);  // fallback
};

template <>
struct Epsilon<float> {
  static constexpr float value = 1e-6f;
};

template <>
struct Epsilon<double> {
  static constexpr double value = 1e-12;
};

namespace VecMatLib {

template <typename T>
class Vec2 {
 public:
  T x, y;

  Vec2(T x_, T y_) : x(x_), y(y_) {}
  Vec2() : x(0), y(0) {}

  [[nodiscard]] T magnitude() const;
  [[nodiscard]] T distance(const Vec2 &v) const;

  [[nodiscard]] Vec2 normal() const;

  [[nodiscard]] T dot(const Vec2 &v) const;
  [[nodiscard]] T cross(const Vec2 &v) const;

  Vec2 operator+(const Vec2 &other) const;
  Vec2 operator-(const Vec2 &other) const;
  Vec2 operator*(T s) const;
  Vec2 operator/(T s) const;
  bool operator==(const Vec2<T> &v) const {
    // Just access the static member of the type trait
    constexpr T eps = Epsilon<T>::value;
    return std::abs(x - v.x) < eps && std::abs(y - v.y) < eps;
  }
};
}  // namespace VecMatLib
