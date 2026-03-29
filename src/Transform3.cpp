//
// Created by chice on 3/29/2026.
//

#include "../include/VecMatLib/Transform3.h"

namespace VecMatLib {
Transform3 Transform3::rotation(const Vec3& axis, const double angle) {
  Vec3 v = axis.normal();
  double x = v.x;
  double y = v.y;
  double z = v.z;

  double c = cos(angle);
  double s = sin(angle);
  double t = 1 - c;

  Mat3 rotation(
    c + x*x*t, x*y*t - z*s, x*z*t + y*s,
    y*x*t - z*s, c + y*y*t, y*z*t - x*s,
    z*x*t - y*s, z*y*t + x*s, c + z*z*t
  );

  return Transform3(rotation, {0,0,0});
}
}  // namespace VecMatLib