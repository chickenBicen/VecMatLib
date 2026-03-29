#include "../include/VecMatLib/utils.h"

#include <algorithm>
#include <cmath>

double VecMatLib::magnitude(const Vec2& other) {
  return std::sqrt(other.x * other.x + other.y * other.y);
}

VecMatLib::Mat2 VecMatLib::rotationMat2(const double angle) {
  const double PI = 3.14159265358979323846;
  return {std::cos(angle), std::sin(angle), -std::sin(angle), std::cos(angle)};
}
