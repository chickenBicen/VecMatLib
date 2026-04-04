//
// Created by chice on 3/29/2026.
//

#ifndef VECMATLIB_MAT3_H
#define VECMATLIB_MAT3_H
#include <array>
#include <numbers>

#include "Mat2.h"
#include "Vec3.h"

namespace VecMatLib {

template <typename T>
class Mat3 {
 public:
  std::array<std::array<T, 3>, 3> mat_;

  Mat3(T m00, T m01, T m02, T m10, T m11, T m12, T m20, T m21, T m22) {
    mat_[0][0] = m00;
    mat_[0][1] = m01;
    mat_[0][2] = m02;
    mat_[1][0] = m10;
    mat_[1][1] = m11;
    mat_[1][2] = m12;
    mat_[2][0] = m20;
    mat_[2][1] = m21;
    mat_[2][2] = m22;
  }

  Mat3(const std::array<std::array<T, 3>, 3>& mat) { mat_ = mat; }

  Mat3(const T mat[9]) {
    mat_[0][0] = mat[0];
    mat_[0][1] = mat[1];
    mat_[0][2] = mat[2];
    mat_[1][0] = mat[3];
    mat_[1][1] = mat[4];
    mat_[1][2] = mat[5];
    mat_[2][0] = mat[6];
    mat_[2][1] = mat[7];
    mat_[2][2] = mat[8];
  }

  static Mat3 identity() {
    Mat3 mat(1, 0, 0, 0, 1, 0, 0, 0, 1);
    return mat;
  }

  Mat3() = default;

  T det() const;
  Mat3 inversed() const;
  Mat3 transposed() const;

  T cofactor(int row, int col) const;
  Mat3 cofactorMatrix() const;
  Mat3 adjoint() const;
  Mat2<T> subMatrix(int row, int col) const;
  T minor(int row, int col) const;

  Vec3<T> row(int i) const;
  Vec3<T> col(int i) const;

  Mat3 operator*(const Mat3& other) const;
  Vec3<T> operator*(const Vec3<T>& v) const;
  Mat3 operator*(const T scalar) const;
  Mat3 operator/(T scalar) const;

  Mat3 operator+(const Mat3& other) const;
  Mat3 operator-(const Mat3& other) const;
  bool operator==(const Mat3& other) const;
};
}  // namespace VecMatLib
#endif  // VECMATLIB_MAT3_H
