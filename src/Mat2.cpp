//
// Created by chice on 3/24/2026.
//

#include "../include/VecMatLib/Mat2.h"

#include <iostream>

#include "../include/VecMatLib/Vec2.h"

namespace VecMatLib {
double Mat2::det() const {
  return mat_[0][0] * mat_[1][1] - mat_[0][1] * mat_[1][0];
}

Mat2 Mat2::inversed() const {
  const double determinant = det();
  if (determinant == 0) {
    std::cout << "Potentially unintended behavior; Cannot inverse with det = 0";
    throw std::runtime_error("Matrix with det of 0 can NOT be inversed");
  }
  return Mat2(mat_[1][1], -mat_[0][1], -mat_[1][0], mat_[0][0]) *
         (1 / determinant);
}

Mat2 Mat2::transposed() const {
  return {mat_[0][0], mat_[1][0], mat_[0][1], mat_[1][1]};
}

Mat2 Mat2::operator*(double s) const {
  return {mat_[0][0] * s, mat_[0][1] * s, mat_[1][0] * s, mat_[1][1] * s};
}

bool Mat2::operator==(const Mat2& m) const {
  const double eps = 1e-6;
  return std::abs(mat_[0][0] - m.mat_[0][0]) < eps &&
         std::abs(mat_[0][1] - m.mat_[0][1]) < eps &&
         std::abs(mat_[1][0] - m.mat_[1][0]) < eps &&
         std::abs(mat_[1][1] - m.mat_[1][1]) < eps;
}

Mat2 Mat2::operator+(const Mat2& m) const {
  return {mat_[0][0] + m.mat_[0][0], mat_[0][1] + m.mat_[0][1],
          mat_[1][0] + m.mat_[1][0], mat_[1][1] + m.mat_[1][1]};
}

Mat2 Mat2::operator-(const Mat2& m) const {
  return {mat_[0][0] - m.mat_[0][0], mat_[0][1] - m.mat_[0][1],
          mat_[1][0] - m.mat_[1][0], mat_[1][1] - m.mat_[1][1]};
}

Mat2 Mat2::operator*(const Mat2& m) const {
  return {mat_[0][0] * m.mat_[0][0] + mat_[0][1] * m.mat_[1][0],
          mat_[0][0] * m.mat_[0][1] + mat_[0][1] * m.mat_[1][1],
          mat_[1][0] * m.mat_[0][0] + mat_[1][1] * m.mat_[1][0],
          mat_[1][0] * m.mat_[0][1] + mat_[1][1] * m.mat_[1][1]};
}

Vec2 Mat2::operator*(const Vec2& v) const {
  return {mat_[0][0] * v.x + mat_[0][1] * v.y,
          mat_[1][0] * v.x + mat_[1][1] * v.y};
}
}  // namespace VecMatLib
