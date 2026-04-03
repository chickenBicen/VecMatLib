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
class Mat3 {
 public:
  std::array<std::array<double, 3>, 3> mat_;

  Mat3(double m00, double m01, double m02, double m10, double m11, double m12,
       double m20, double m21, double m22) {
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

  Mat3(const std::array<std::array<double, 3>, 3>& mat) { mat_ = mat; }

  Mat3(const double mat[9]) {
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
    Mat3 mat(1,0,0,0,1,0,0,0,1);
    return mat;
  }

  Mat3() = default;

  double det() const;
  Mat3 inversed() const;
  Mat3 transposed() const;

  double cofactor(int row, int col) const;
  Mat3 cofactorMatrix() const;
  Mat3 adjoint() const;
  Mat2 subMatrix(int row, int col) const;
  double minor(int row, int col) const;

  Vec3 row(int i) const;
  Vec3 col(int i) const;

  Mat3 operator*(const Mat3& other) const;
  Vec3 operator*(const Vec3& v) const;
  Mat3 operator*(const double scalar) const;
  Mat3 operator/(double scalar) const;

  Mat3 operator+(const Mat3& other) const;
  Mat3 operator-(const Mat3& other) const;
  bool operator==(const Mat3& other) const;
};
}  // namespace VecMatLib
#endif  // VECMATLIB_MAT3_H
