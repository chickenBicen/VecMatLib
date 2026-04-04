//
// Created by chice on 3/29/2026.
//

#include "../include/VecMatLib/Transform3.h"

namespace VecMatLib {

template <typename T>
Quaternion<T> Transform3<T>::rotation(const Vec3<T>& axis, const T angle) {
  Vec3 norm = axis.normal();

  T half = angle * T(0.5);
  T s = T(std::sin(half));

  return {T(std::cos(half)), norm.x * s, norm.y * s, norm.z * s};
}

template <typename T>
Transform3<T>& Transform3<T>::scale(const Vec3<T>& scale) {
  scale_.x *= scale.x;
  scale_.y *= scale.y;
  scale_.z *= scale.z;
  return *this;
}

template <typename T>
Transform3<T> Transform3<T>::operator*(const Transform3& other) const {
  Transform3 result;

  // Apply this, then other
  result.scale_ = {scale_.x * other.scale_.x, scale_.y * other.scale_.y,
                   scale_.z * other.scale_.z};

  result.rotation_ = (other.rotation_ * rotation_).normalized();

  result.translation_ =
      other.rotation_ * Vec3{translation_.x * other.scale_.x,
                             translation_.y * other.scale_.y,
                             translation_.z * other.scale_.z} +
      other.translation_;

  return result;
}

template <typename T>
Transform3<T>& Transform3<T>::translate(const Vec3<T>& translation) {
  this->translation_ = translation_ + translation;
  return *this;
}

template <typename T>
Transform3<T>& Transform3<T>::rotate(const Vec3<T>& axis, const T angle) {
  rotation_ = (rotation_ * rotation(axis, angle)).normalized();
  return *this;
}

template <typename T>
Transform3<T>& Transform3<T>::combine(const Transform3& other) {
  (*this) = (*this) * other;
  return *this;
}

template <typename T>
Vec3<T> Transform3<T>::operator*(const Vec3<T>& v) const {
  Vec3 scaled(scale_.x * v.x, scale_.y * v.y, scale_.z * v.z);

  // 2. Rotate (using quaternion)
  Vec3 rotated = rotation_ * scaled; // using the Vec3 * Quaternion overload

  // 3. Translate
  return {rotated.x + translation_.x, rotated.y + translation_.y,
          rotated.z + translation_.z};
}

template class Transform3<double>;
template class Transform3<float>;
}  // namespace VecMatLib