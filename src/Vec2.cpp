#include "../include/VecMatLib/Core/Vec2.h"

#include <cmath>

namespace VecMatLib {

template <typename T>
T Vec2<T>::magnitude() const {
  return std::sqrt(x * x + y * y);
}

template <typename T>
T Vec2<T>::distance(const Vec2& v) const {
  return (*this - v).magnitude();
}

template <typename T>
Vec2<T> Vec2<T>::normal() const {
  if (x == T(0) && y == T(0)) return {T(0), T(0)};
  T mag = magnitude();
  return {x / mag, y / mag};
}

template <typename T>
T Vec2<T>::dot(const Vec2& v) const {
  return x * v.x + y * v.y;
}

template <typename T>
T Vec2<T>::cross(const Vec2& v) const {
  return x * v.y - y * v.x;
}

template <typename T>
Vec2<T> Vec2<T>::operator+(const Vec2& other) const {
  return {x + other.x, y + other.y};
}

template <typename T>
Vec2<T> Vec2<T>::operator-(const Vec2& other) const {
  return {x - other.x, y - other.y};
}

template <typename T>
Vec2<T> Vec2<T>::operator*(T s) const {
  return {x * s, y * s};
}

template <typename T>
Vec2<T> Vec2<T>::operator/(T s) const {
  return {x / s, y / s};
}

template class Vec2<float>;
template class Vec2<double>;

}  // namespace VecMatLib