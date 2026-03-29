//
// Created by chice on 3/23/2026.
//
#include "../include/VecMatLib/Vec3.h"

#include <cmath>

namespace VecMatLib {
double Vec3::magnitude() const { return std::sqrt(x * x + y * y + z * z); }
double Vec3::dot(const Vec3& v) const { return x * v.x + y * v.y + z * v.z; }

Vec3 Vec3::cross(const Vec3& v) const {
  return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
}

Vec3 Vec3::normal() const {
  if (x == 0 && y == 0 && z == 0) {
    return *this;
  }
  return {x / magnitude(), y / magnitude(), z / magnitude()};
}

Vec3 Vec3::operator+(const Vec3& other) const {
  return {x + other.x, y + other.y, z + other.z};
}
Vec3 Vec3::operator-(const Vec3& other) const {
  return {x - other.x, y - other.y, z - other.z};
}
Vec3 Vec3::operator*(double s) const { return {x * s, y * s, z * s}; }
Vec3 Vec3::operator/(double s) const { return {x / s, y / s, y / s}; }

bool Vec3::operator==(const Vec3& other) const {
  return (std::abs(x - other.x) < 1e-6 && std::abs(y - other.x) < 1e-6 &&
          std::abs(z - other.z) < 1e-6);
}
}  // namespace VecMatLib
