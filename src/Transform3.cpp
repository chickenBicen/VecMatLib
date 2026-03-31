//
// Created by chice on 3/29/2026.
//

#include "../include/VecMatLib/Transform3.h"

namespace VecMatLib {

Quaternion Transform3::rotation(const Vec3& axis, const double angle) {
  Vec3 norm = axis.normal();

  double half = angle * 0.5;
  double s = std::sin(half);

  return {std::cos(half), norm.x * s, norm.y * s, norm.z * s};
}

Transform3& Transform3::scale(const Vec3& scale) {
  scale_.x *= scale.x;
  scale_.y *= scale.y;
  scale_.z *= scale.z;
  return *this;
}

Transform3 Transform3::operator*(const Transform3& other) const {
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

Transform3& Transform3::translate(const Vec3& translation) {
  this->translation_ = translation_ + translation;
  return *this;
}

Transform3& Transform3::rotate(const Vec3& axis, const double angle) {
  rotation_ = (rotation(axis, angle) * rotation_).normalized();
  return *this;
}

Transform3& Transform3::combine(const Transform3& other) {
  (*this) = (*this) * other;
  return *this;
}

Vec3 Transform3::operator*(const Vec3& v) const {
  Vec3 scaled(scale_.x * v.x, scale_.y * v.y, scale_.z * v.z);

  // 2. Rotate (using quaternion)
  Vec3 rotated = rotation_ * scaled; // using the Vec3 * Quaternion overload

  // 3. Translate
  return {rotated.x + translation_.x, rotated.y + translation_.y,
          rotated.z + translation_.z};
}
}  // namespace VecMatLib