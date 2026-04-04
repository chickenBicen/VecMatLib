//
// Created by chice on 3/23/2026.
//
#include "../include/VecMatLib/Vec3.h"

#include <cmath>

namespace VecMatLib {

template <typename T>
T Vec3<T>::magnitude() const {
  return std::sqrt(x * x + y * y + z * z);
}

template <typename T>
T Vec3<T>::dot(const Vec3& v) const {
  return x * v.x + y * v.y + z * v.z;
}

template <typename T>
Vec3<T> Vec3<T>::cross(const Vec3& v) const {
  return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x};
}

template <typename T>
Vec3<T> Vec3<T>::normal() const {
  if (x == T(0) && y == T(0) && z == T(0)) {
    return *this;
  }
  return {x / magnitude(), y / magnitude(), z / magnitude()};
}

template <typename T>
Vec3<T> Vec3<T>::operator+(const Vec3& other) const {
  return {x + other.x, y + other.y, z + other.z};
}

template <typename T>
Vec3<T> Vec3<T>::operator-(const Vec3& other) const {
  return {x - other.x, y - other.y, z - other.z};
}
template <typename T>
Vec3<T> Vec3<T>::operator*(T s) const {
  return {x * s, y * s, z * s};
}

template <typename T>
Vec3<T> Vec3<T>::operator/(T s) const {
  return {x / s, y / s, z / s};
}

template <typename T>
bool Vec3<T>::operator==(const Vec3& other) const {
  T eps = Epsilon<T>::value;
  return (std::abs(x - other.x) < eps && std::abs(y - other.y) < eps &&
          std::abs(z - other.z) < eps);
}

template class Vec3<float>;
template class Vec3<double>;
}  // namespace VecMatLib
