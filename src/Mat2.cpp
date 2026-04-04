//
// Created by chice on 3/24/2026.
//

#include "../include/VecMatLib/Mat2.h"

#include <iostream>

#include "../include/VecMatLib/Vec2.h"

namespace VecMatLib {
template <typename T>
T Mat2<T>::det() const {
  return mat_[0][0] * mat_[1][1] - mat_[0][1] * mat_[1][0];
}

template <typename T>
Mat2<T> Mat2<T>::inversed() const {
  const double determinant = det();
  if (determinant == 0) {
    std::cout << "Potentially unintended behavior; Cannot inverse with det = 0";
    throw std::runtime_error("Matrix with det of 0 can NOT be inversed");
  }
  return Mat2(mat_[1][1], -mat_[0][1], -mat_[1][0], mat_[0][0]) *
         (1 / determinant);
}

template <typename T>
Mat2<T> Mat2<T>::transposed() const {
  return {mat_[0][0], mat_[1][0], mat_[0][1], mat_[1][1]};
}

template <typename T>
Mat2<T> Mat2<T>::operator*(T s) const {
  return {mat_[0][0] * s, mat_[0][1] * s, mat_[1][0] * s, mat_[1][1] * s};
}

template <typename T>
bool Mat2<T>::operator==(const Mat2& m) const {
  const T eps = Epsilon<T>::value;
  return std::abs(mat_[0][0] - m.mat_[0][0]) < eps &&
         std::abs(mat_[0][1] - m.mat_[0][1]) < eps &&
         std::abs(mat_[1][0] - m.mat_[1][0]) < eps &&
         std::abs(mat_[1][1] - m.mat_[1][1]) < eps;
}

template <typename T>
Mat2<T> Mat2<T>::operator+(const Mat2& m) const {
  return {mat_[0][0] + m.mat_[0][0], mat_[0][1] + m.mat_[0][1],
          mat_[1][0] + m.mat_[1][0], mat_[1][1] + m.mat_[1][1]};
}

template <typename T>
Mat2<T> Mat2<T>::operator-(const Mat2& m) const {
  return {mat_[0][0] - m.mat_[0][0], mat_[0][1] - m.mat_[0][1],
          mat_[1][0] - m.mat_[1][0], mat_[1][1] - m.mat_[1][1]};
}

template <typename T>
Mat2<T> Mat2<T>::operator*(const Mat2& m) const {
  return {mat_[0][0] * m.mat_[0][0] + mat_[0][1] * m.mat_[1][0],
          mat_[0][0] * m.mat_[0][1] + mat_[0][1] * m.mat_[1][1],
          mat_[1][0] * m.mat_[0][0] + mat_[1][1] * m.mat_[1][0],
          mat_[1][0] * m.mat_[0][1] + mat_[1][1] * m.mat_[1][1]};
}

template <typename T>
Vec2<T> Mat2<T>::operator*(const Vec2<T>& v) const {
  return {mat_[0][0] * v.x + mat_[0][1] * v.y,
          mat_[1][0] * v.x + mat_[1][1] * v.y};
}

template class Mat2<double>;
template class Mat2<float>;
}  // namespace VecMatLib
