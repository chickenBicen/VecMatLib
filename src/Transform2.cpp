//
// Created by chice on 3/26/2026.
//

#include "../include/VecMatLib/Transform2.h"
using namespace VecMatLib;

Transform2 Transform2::identity() { return Transform2(); }

Transform2 Transform2::translation(const VecMatLib::Vec2& t) {
  return {t.x, t.y};
}
Transform2 Transform2::rotation(double radians) {
  return {cos(radians), -sin(radians), sin(radians), cos(radians), 0, 0};
}

Transform2 Transform2::scaling(double sx, double sy) {
  return {sx, 0, 0, sy, 0, 0};
}

Transform2 Transform2::inverse() {
  Mat2 mat = this->matrix_.inversed();
  Vec2 t = mat * this->translation_;
  t.x *= -1;
  t.y *= -1;

  return {mat, t};
}

Transform2& Transform2::combine(const Transform2& other) {
  matrix_ = matrix_ * other.matrix_;
  translation_ = matrix_ * other.translation_ + translation_;
  return *this;
}

Transform2 Transform2::operator*(const Transform2& other) const {
  return {matrix_ * other.matrix_, matrix_ * other.translation_ + translation_};
}
Vec2 Transform2::operator*(const Vec2& v) const {
  return {matrix_.mat_[0][0] * v.x + matrix_.mat_[0][1] * v.y + translation_.x,
          matrix_.mat_[1][0] * v.x + matrix_.mat_[1][1] * v.y + translation_.y};
}

Transform2& Transform2::rotate(double angle) {
  return combine(Transform2::rotation(angle));
}

Transform2& Transform2::translate(const Vec2& translation) {
  return combine(Transform2::translation(translation));
}

Transform2& Transform2::scale(double sx, double sy) {
  return combine(Transform2::scaling(sx, sy));
}