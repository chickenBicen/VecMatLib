//
// Created by chice on 3/26/2026.
//

#ifndef VECMATLIB_TRANSFORM2_H
#define VECMATLIB_TRANSFORM2_H
#include "Mat2.h"
#include <numbers>

namespace VecMatLib {
class Transform2 {
 private:
  Mat2 matrix_;
  Vec2 translation_;

 public:
  Transform2(double m00, double m01, double m10, double m11, double tx,
             double ty)
      : matrix_(m00, m01, m10, m11), translation_(tx, ty) {}

  Transform2(const double tx, const double ty)
      : matrix_(), translation_(tx, ty) {}
  Transform2(const Mat2 matrix, const Vec2 translation)
      : matrix_(matrix), translation_(translation) {}

  Transform2() : matrix_(), translation_(0, 0) {}

  Transform2& rotate(double angle);
  Transform2& translate(const Vec2& translation);
  Transform2& scale(double sx, double sy);
  Transform2& combine(const Transform2& other);

  [[nodiscard]] static Transform2 identity();
  [[nodiscard]] static Transform2 translation(const Vec2& t);
  [[nodiscard]] static Transform2 rotation(double radians);
  [[nodiscard]] static Transform2 scaling(double sx, double sy);

  [[nodiscard]] Transform2 inverse();

  Transform2 operator*(const Transform2& other) const;
  Vec2 operator*(const Vec2& v) const;
};
}  // namespace VecMatLib
#endif  // VECMATLIB_TRANSFORM2_H
