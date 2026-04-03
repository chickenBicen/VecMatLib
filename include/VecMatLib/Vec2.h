#pragma once
#include <cmath>
#include <numbers>

namespace VecMatLib {
class Vec2 {
 public:
  double x, y;

  Vec2(double x_, double y_) : x(x_), y(y_) {}

  [[nodiscard]] double magnitude() const;

  [[nodiscard]] double distance(const Vec2& v) const;

  [[nodiscard]] Vec2 normal() const;

  [[nodiscard]] double dot(const Vec2& v) const;
  [[nodiscard]] double cross(const Vec2& v) const;

  Vec2 operator+(const Vec2& other) const;
  Vec2 operator-(const Vec2& other) const;
  Vec2 operator*(double s) const;
  Vec2 operator/(double s) const;
  bool operator==(const Vec2& v) const;
};
}  // namespace VecMatLib
