//
// Created by chice on 3/29/2026.
//

#ifndef VECMATLIB_TRANSFORM3_H
#define VECMATLIB_TRANSFORM3_H
#include "Mat3.h"
#include "Quaternion.h"

namespace VecMatLib {

class Transform3 {
 private:
  Vec3 scale_;
  Vec3 translation_;
  Quaternion rotation_;

 public:
  Transform3() {
    scale_ = Vec3(1, 1, 1);
    translation_ = Vec3(0, 0, 0);
    rotation_ = Quaternion();
  }
  Transform3(const Mat3& mat3, const Vec3& translation) {
    scale_ = Vec3(1, 1, 1);
    translation_ = translation;
    rotation_ = Quaternion();
  }

  static Quaternion rotation(const Vec3& axis, const double angle);

  Transform3& translate(const Vec3& translation);
  Transform3& scale(const Vec3& scale);
  Transform3& rotate(const Vec3& axis, const double angle);

  Transform3& combine(const Transform3& other);

  Vec3 getTranslation() { return translation_; }

  Vec3 getScale() { return scale_; }

  Quaternion getRotation() { return rotation_; }

  Transform3 operator*(const Transform3& other) const;
  Vec3 operator*(const Vec3& v) const;
};

}  // namespace VecMatLib

#endif  // VECMATLIB_TRANSFORM3_H
