//
// Created by chice on 3/23/2026.
//

#ifndef VECMATLIB_VEC3_H
#define VECMATLIB_VEC3_H

namespace VecMatLib {
class Vec3 {
 public:
  double x, y, z;
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
  Vec3() : x(0), y(0), z(0) {}

  double magnitude() const;
  double dot(const Vec3& v) const;
  Vec3 cross(const Vec3& v) const;

  Vec3 normal() const;

  Vec3 operator-(const Vec3& v) const;
  Vec3 operator+(const Vec3& v) const;
  Vec3 operator*(double s) const;
  Vec3 operator/(double s) const;

  bool operator==(const Vec3& v) const;
};
}  // namespace VecMatLib

#endif  // VECMATLIB_VEC3_H