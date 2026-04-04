//
// Created by chice on 3/26/2026.
//

#include "../include/VecMatLib/Math/Transform2.h"
namespace VecMatLib {

template <typename T>
Transform2<T> Transform2<T>::identity() { return Transform2(); }

template <typename T>
Transform2<T> Transform2<T>::translation(const Vec2<T>& t) {
  return {t.x, t.y};
}

template <typename T>
Transform2<T> Transform2<T>::rotation(T radians) {
  return {T(cos(radians)), T(-sin(radians)), T(sin(radians)), T(cos(radians)), T(0), T(0)};
}

template <typename T>
Transform2<T> Transform2<T>::scaling(T sx, T sy) {
  return {sx, T(0), T(0), sy, T(0), T(0)};
}

template <typename T>
Transform2<T> Transform2<T>::inverse() {
  Mat2 mat = this->matrix_.inversed();
  Vec2 t = mat * this->translation_;
  t.x *= T(-1);
  t.y *= T(-1);

  return {mat, t};
}

template <typename T>
Transform2<T>& Transform2<T>::combine(const Transform2& other) {
  matrix_ = matrix_ * other.matrix_;
  translation_ = matrix_ * other.translation_ + translation_;
  return *this;
}

template <typename T>
Transform2<T> Transform2<T>::operator*(const Transform2& other) const {
  return {matrix_ * other.matrix_, matrix_ * other.translation_ + translation_};
}

template <typename T>
Vec2<T> Transform2<T>::operator*(const Vec2<T>& v) const {
  return {matrix_.mat_[0][0] * v.x + matrix_.mat_[0][1] * v.y + translation_.x,
          matrix_.mat_[1][0] * v.x + matrix_.mat_[1][1] * v.y + translation_.y};
}

template <typename T>
Transform2<T>& Transform2<T>::rotate(T angle) {
  return combine(Transform2::rotation(angle));
}

template <typename T>
Transform2<T>& Transform2<T>::translate(const Vec2<T>& translation) {
  return combine(Transform2::translation(translation));
}

template <typename T>
Transform2<T>& Transform2<T>::scale(T sx, T sy) {
  return combine(Transform2::scaling(sx, sy));
}

template class Transform2<float>;
template class Transform2<double>;
}