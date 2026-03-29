//
// Created by chice on 3/29/2026.
//

#include "../include/VecMatLib/Mat3.h"

#include "VecMatLib/Mat2.h"

using namespace VecMatLib;

double Mat3::det() const {
  double term1 =
      (Mat2(mat_[1][1], mat_[1][2], mat_[2][1], mat_[2][2]).det()) * mat_[0][0];
  double term2 =
      (Mat2(mat_[1][0], mat_[1][2], mat_[2][0], mat_[2][2]).det()) * mat_[0][1];
  double term3 =
      (Mat2(mat_[1][0], mat_[1][1], mat_[2][0], mat_[2][1]).det()) * mat_[0][2];

  return term1 - term2 + term3;
}

Mat2 Mat3::subMatrix(int row, int col) const {
  int i = 0;
  double arr[4];
  for (int r = 0; r < 3; r++) {
    if (r == row) {
      continue;
    }
    for (int c = 0; c < 3; c++) {
      if (c == col) {
        continue;
      }
      arr[i++] = mat_[r][c];
    }
  }

  return Mat2(arr);
}

double Mat3::minor(int row, int col) const { return subMatrix(row, col).det(); }

double Mat3::cofactor(int row, int col) const {
  return std::pow(-1, row + col) * minor(row, col);
}

Mat3 Mat3::cofactorMatrix() const {
  std::array<std::array<double, 3>, 3> arr;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      arr[r][c] = cofactor(r, c);
    }
  }

  return Mat3(arr);
}

Mat3 Mat3::transposed() const {
  return {
      mat_[0][0], mat_[1][0], mat_[2][0], mat_[0][1], mat_[1][1],
      mat_[2][1], mat_[0][2], mat_[1][2], mat_[2][2],
  };
}

Mat3 Mat3::adjoint() const { return cofactorMatrix().transposed(); }

Mat3 Mat3::inversed() const { return adjoint() * (1 / det()); }

Vec3 Mat3::row(int i) const { return {mat_[i][0], mat_[i][1], mat_[i][2]}; }
Vec3 Mat3::col(int i) const { return {mat_[0][i], mat_[1][i], mat_[2][i]}; }

Mat3 Mat3::operator*(const Mat3& other) const {
  Mat3 C{};

  for (int i = 0; i < 3; ++i) {
    C.mat_[i][0] = mat_[i][0] * other.mat_[0][0] +
                   mat_[i][1] * other.mat_[1][0] +
                   mat_[i][2] * other.mat_[2][0];

    C.mat_[i][1] = mat_[i][0] * other.mat_[0][1] +
                   mat_[i][1] * other.mat_[1][1] +
                   mat_[i][2] * other.mat_[2][1];

    C.mat_[i][2] = mat_[i][0] * other.mat_[0][2] +
                   mat_[i][1] * other.mat_[1][2] +
                   mat_[i][2] * other.mat_[2][2];
  }

  return C;
}

Vec3 Mat3::operator*(const Vec3& v) const {
  return {mat_[0][0] * v.x + mat_[0][1] * v.y + mat_[0][2] * v.z,
          mat_[1][0] * v.x + mat_[1][1] * v.y + mat_[1][2] * v.z,
          mat_[2][0] * v.x + mat_[2][1] * v.y + mat_[2][2] * v.z};
}

Mat3 Mat3::operator*(const double scalar) const {
  return Mat3{mat_[0][0] * scalar, mat_[0][1] * scalar, mat_[0][2] * scalar,
              mat_[1][0] * scalar, mat_[1][1] * scalar, mat_[1][2] * scalar,
              mat_[2][0] * scalar, mat_[2][1] * scalar, mat_[2][2] * scalar};
}

Mat3 Mat3::operator/(double scalar) const {
  return Mat3{
      mat_[0][0] / scalar, mat_[0][1] / scalar, mat_[0][2] / scalar,
      mat_[1][0] / scalar, mat_[1][1] / scalar, mat_[1][2] / scalar,
      mat_[2][0] / scalar, mat_[2][1] / scalar, mat_[2][2] / scalar,
  };
}

bool Mat3::operator==(const Mat3& other) const { return (mat_ == other.mat_); }