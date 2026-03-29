//
// Created by chice on 3/29/2026.
//

#ifndef VECMATLIB_TRANSFORM3_H
#define VECMATLIB_TRANSFORM3_H
#include "Mat3.h"

namespace VecMatLib {

class Transform3 {
private:
  Mat3 mat3_;
  Vec3 translation_;
public:
  Transform3() {
    mat3_ = Mat3();
    translation_ = Vec3(0,0,0);
  }
  Transform3(const Mat3& mat3, const Vec3& translation) {
    mat3_ = mat3;
    translation_ = translation;
  }

  static Transform3 identity();
  static Transform3 translation(const Vec3& translation);
  static Transform3 scaling(const Vec3& scale);
  static Transform3 rotation(const Vec3& axis, const double angle);

  Transform3& translate(const Vec3& translation);
  Transform3& scale(const Vec3& scale);
  Transform3& rotate(const Vec3& axis, const double angle);

  void orthonormalize();

  double rotationInX()const;
  double rotationInY()const;
  double rotationInZ()const;

};

}  // namespace VecMatLib

#endif  // VECMATLIB_TRANSFORM3_H
