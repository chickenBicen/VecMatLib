//
// Created by chice on 3/24/2026.
//

#ifndef VECMATLIB_MAT2_H
#define VECMATLIB_MAT2_H
#include <array>

#include "../VecMatLib/Vec2.h"

namespace VecMatLib {
class Mat2 {
 private:
 public:
  std::array<std::array<double, 2>, 2> mat_;

  Mat2(double m00, double m01, double m10, double m11) {
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

  Mat2(double mat[4]) {
    mat_[0][0] = mat[0];
    mat_[0][1] = mat[1];
    mat_[1][0] = mat[2];
    mat_[1][1] = mat[3];
  }

  [[nodiscard]] double det() const;

  [[nodiscard]] Mat2 inversed() const;

  [[nodiscard]] Mat2 transposed() const;

  Mat2 operator+(const Mat2& m) const;
  Mat2 operator-(const Mat2& m) const;
  Mat2 operator*(const Mat2& m) const;
  Vec2 operator*(const Vec2& v) const;
  Mat2 operator*(double s) const;
  bool operator==(const Mat2& m) const;
};
}  // namespace VecMatLib

#endif  // VECMATLIB_MAT2_H
