//
// Created by chice on 3/29/2026.
//

#include "../include/VecMatLib/Mat3.h"

#include "VecMatLib/Mat2.h"

namespace VecMatLib {
template <typename T>
T Mat3<T>::det() const {
  T term1 =
      (Mat2(mat_[1][1], mat_[1][2], mat_[2][1], mat_[2][2]).det()) * mat_[0][0];
  T term2 =
      (Mat2(mat_[1][0], mat_[1][2], mat_[2][0], mat_[2][2]).det()) * mat_[0][1];
  T term3 =
      (Mat2(mat_[1][0], mat_[1][1], mat_[2][0], mat_[2][1]).det()) * mat_[0][2];

  return term1 - term2 + term3;
}

template <typename T>
Mat2<T> Mat3<T>::subMatrix(int row, int col) const {
  int i = 0;
  T arr[4];
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

template <typename T>
T Mat3<T>::minor(int row, int col) const {
  return subMatrix(row, col).det();
}

template <typename T>
T Mat3<T>::cofactor(int row, int col) const {
  return ((row + col) % 2 == 0 ? T(1) : T(-1)) * minor(row, col);
}

template <typename T>
Mat3<T> Mat3<T>::cofactorMatrix() const {
  std::array<std::array<T, 3>, 3> arr;
  for (int r = 0; r < 3; r++) {
    for (int c = 0; c < 3; c++) {
      arr[r][c] = cofactor(r, c);
    }
  }

  return Mat3(arr);
}

template <typename T>
Mat3<T> Mat3<T>::transposed() const {
  return {
      mat_[0][0], mat_[1][0], mat_[2][0], mat_[0][1], mat_[1][1],
      mat_[2][1], mat_[0][2], mat_[1][2], mat_[2][2],
  };
}

template <typename T>
Mat3<T> Mat3<T>::adjoint() const {
  return cofactorMatrix().transposed();
}

template <typename T>
Mat3<T> Mat3<T>::inversed() const {
  return adjoint() * (1 / det());
}

template <typename T>
Vec3<T> Mat3<T>::row(int i) const {
  return {mat_[i][0], mat_[i][1], mat_[i][2]};
}

template <typename T>
Vec3<T> Mat3<T>::col(int i) const {
  return {mat_[0][i], mat_[1][i], mat_[2][i]};
}

template <typename T>
Mat3<T> Mat3<T>::operator*(const Mat3& other) const {
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

template <typename T>
Vec3<T> Mat3<T>::operator*(const Vec3<T>& v) const {
  return {mat_[0][0] * v.x + mat_[0][1] * v.y + mat_[0][2] * v.z,
          mat_[1][0] * v.x + mat_[1][1] * v.y + mat_[1][2] * v.z,
          mat_[2][0] * v.x + mat_[2][1] * v.y + mat_[2][2] * v.z};
}

template <typename T>
Mat3<T> Mat3<T>::operator*(const T scalar) const {
  return Mat3{mat_[0][0] * scalar, mat_[0][1] * scalar, mat_[0][2] * scalar,
              mat_[1][0] * scalar, mat_[1][1] * scalar, mat_[1][2] * scalar,
              mat_[2][0] * scalar, mat_[2][1] * scalar, mat_[2][2] * scalar};
}

template <typename T>
Mat3<T> Mat3<T>::operator/(T scalar) const {
  return Mat3{
      mat_[0][0] / scalar, mat_[0][1] / scalar, mat_[0][2] / scalar,
      mat_[1][0] / scalar, mat_[1][1] / scalar, mat_[1][2] / scalar,
      mat_[2][0] / scalar, mat_[2][1] / scalar, mat_[2][2] / scalar,
  };
}

template <typename T>
bool Mat3<T>::operator==(const Mat3& other) const {
  constexpr T eps = std::is_same_v<T, float> ? 1e-6f : 1e-12;
  for (int r = 0; r < 3; ++r)
    for (int c = 0; c < 3; ++c)
      if (std::abs(mat_[r][c] - other.mat_[r][c]) > eps) return false;
  return true;
}

template class Mat3<double>;
template class Mat3<float>;

}  // namespace VecMatLib