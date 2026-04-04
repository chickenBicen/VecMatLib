//
// Created by chice on 3/26/2026.
//

#ifndef VECMATLIB_TRANSFORM2_H
#define VECMATLIB_TRANSFORM2_H
#include <numbers>

#include "../Core/Mat2.h"

namespace VecMatLib {
template<typename T>
class Transform2 {
 private:
  Mat2<T> matrix_;
  Vec2<T> translation_;

 public:
  Transform2(T m00, T m01, T m10, T m11, T tx,
             T ty)
      : matrix_(m00, m01, m10, m11), translation_(tx, ty) {}

  Transform2(const T tx, const T ty)
      : matrix_(), translation_(tx, ty) {}
  Transform2(const Mat2<T> matrix, const Vec2<T> translation)
      : matrix_(matrix), translation_(translation) {}

  Transform2() : matrix_(), translation_(0, 0) {}

  Transform2& rotate(T angle);
  Transform2& translate(const Vec2<T>& translation);
  Transform2& scale(T sx, T sy);
  Transform2& combine(const Transform2& other);

  [[nodiscard]] static Transform2 identity();
  [[nodiscard]] static Transform2 translation(const Vec2<T>& t);
  [[nodiscard]] static Transform2 rotation(T radians);
  [[nodiscard]] static Transform2 scaling(T sx, T sy);

  [[nodiscard]] Transform2 inverse();

  Transform2 operator*(const Transform2& other) const;
  Vec2<T> operator*(const Vec2<T>& v) const;
};
}  // namespace VecMatLib
#endif  // VECMATLIB_TRANSFORM2_H
