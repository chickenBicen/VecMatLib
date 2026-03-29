#include "../include/VecMatLib/Vec2.h"

#include "../include/VecMatLib/utils.h"

namespace VecMatLib {
double Vec2::magnitude() const { return std::sqrt(x * x + y * y); }

double Vec2::distance(const Vec2& v) const {
  return VecMatLib::magnitude(v - *this);
}

Vec2 Vec2::normal() const {
  if (x == 0 && y == 0) return {0.0, 0.0};
  return {x / magnitude(), y / magnitude()};
}

double Vec2::dot(const Vec2& v) const { return x * v.x + y * v.y; }
double Vec2::cross(const Vec2& v) const { return x * v.y - y * v.x; }

Vec2 Vec2::operator+(const Vec2& other) const {
  return {x + other.x, y + other.y};
}
Vec2 Vec2::operator-(const Vec2& other) const {
  return {x - other.x, y - other.y};
}
Vec2 Vec2::operator*(double s) const { return {x * s, y * s}; }

Vec2 Vec2::operator/(double s) const { return {x / s, y / s}; }

bool Vec2::operator==(const Vec2& v) const {
  const double eps = 1e-6;
  return std::abs(x - v.x) < eps && std::abs(y - v.y) < eps;
}
}  // namespace VecMatLib