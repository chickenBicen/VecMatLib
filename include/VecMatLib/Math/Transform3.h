//
// Created by chice on 3/29/2026.
//

#ifndef VECMATLIB_TRANSFORM3_H
#define VECMATLIB_TRANSFORM3_H
#include <numbers>

#include "../Core/Mat3.h"
#include "../Core/Quaternion.h"

namespace VecMatLib {

template<typename T>
class Transform3 {
 private:
  Vec3<T> scale_;
  Vec3<T> translation_;
  Quaternion<T> rotation_;

 public:
  Transform3() {
    scale_ = Vec3<T>(1, 1, 1);
    translation_ = Vec3<T>(0, 0, 0);
    rotation_ = Quaternion<T>();
  }
  Transform3(const Quaternion<T>, const Vec3<T>& translation) {
    scale_ = Vec3<T>(1, 1, 1);
    translation_ = translation;
    rotation_ = Quaternion<T>();
  }

  static Quaternion<T> rotation(const Vec3<T>& axis, const T angle);

  Transform3& translate(const Vec3<T>& translation);
  Transform3& scale(const Vec3<T>& scale);
  Transform3& rotate(const Vec3<T>& axis, const T angle);

  Transform3& combine(const Transform3& other);

  Vec3<T> getTranslation() { return translation_; }

  Vec3<T> getScale() { return scale_; }

  Quaternion<T> getRotation() { return rotation_; }

  Transform3 operator*(const Transform3& other) const;
  Vec3<T> operator*(const Vec3<T>& v) const;

  Transform3& operator=(const Transform3& other) {
    translation_ = other.translation_;
    scale_ = other.scale_;
    rotation_ = other.rotation_;
    return *this;
  }
};

}  // namespace VecMatLib

#endif  // VECMATLIB_TRANSFORM3_H
