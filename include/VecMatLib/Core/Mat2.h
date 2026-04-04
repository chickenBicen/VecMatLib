//
// Created by chice on 3/24/2026.
//

#ifndef VECMATLIB_MAT2_H
#define VECMATLIB_MAT2_H
#include <array>
#include <numbers>

#include "Vec2.h"

namespace VecMatLib {

template <typename T>
class Mat2 {
 public:
  std::array<std::array<T, 2>, 2> mat_;

  Mat2(T m00, T m01, T m10, T m11) {
    mat_[0][0] = m00;
    mat_[0][1] = m01;
    mat_[1][0] = m10;
    mat_[1][1] = m11;
  }

  Mat2() {
    mat_[0][0] = 1;
    mat_[0][1] = 0;
    mat_[1][0] = 0;
    mat_[1][1] = 1;
  }

  Mat2(T mat[4]) {
    mat_[0][0] = mat[0];
    mat_[0][1] = mat[1];
    mat_[1][0] = mat[2];
    mat_[1][1] = mat[3];
  }

  static Mat2 identity() {
    Mat2 m;
    return m;
  }

  [[nodiscard]] T det() const;

  [[nodiscard]] Mat2 inversed() const;

  [[nodiscard]] Mat2 transposed() const;

  Mat2 operator+(const Mat2& m) const;
  Mat2 operator-(const Mat2& m) const;
  Mat2 operator*(const Mat2& m) const;
  Vec2<T> operator*(const Vec2<T>& v) const;
  Mat2 operator*(T s) const;
  bool operator==(const Mat2& m) const;
};
}  // namespace VecMatLib

#endif  // VECMATLIB_MAT2_H
