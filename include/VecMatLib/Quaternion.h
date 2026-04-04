//
// Created by chice on 3/29/2026.
//

#ifndef VECMATLIB_QUATERNION_H
#define VECMATLIB_QUATERNION_H
#include <complex>
#include <numbers>

#include "Vec3.h"

namespace VecMatLib {

template<typename T>
class Quaternion {
 public:
  T w, x, y, z;

  Quaternion() : w(1.0), x(0.0), y(0.0), z(0.0) {}
  Quaternion(double w, double x, double y, double z)
      : w(w), x(x), y(y), z(z) {}
  Quaternion(double w, const Vec3<T>& v) : w(w), x(v.x), y(v.y), z(v.z) {}

  T magnitude() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
  }
  Quaternion normalized() const {
    double m = magnitude();
    return {w / m, x / m, y / m, z / m};
  }
  Quaternion conjugate() const { return {w, -x, -y, -z}; }

  Quaternion operator*(const Quaternion& q) const {
    return {
      w*q.w - x*q.x - y*q.y - z*q.z,
      w*q.x + x*q.w + y*q.z - z*q.y,
      w*q.y - x*q.z + y*q.w + z*q.x,
      w*q.z + x*q.y - y*q.x + z*q.w
  };
  }

  Vec3<T> operator*(const Vec3<T>& v) const {
    Quaternion qv(0, v);                // treat vector as quaternion
    Quaternion rotated = (*this) * qv * this->conjugate();
    return {rotated.x, rotated.y, rotated.z};
  }
};

}  // namespace VecMatLib

#endif  // VECMATLIB_QUATERNION_H
