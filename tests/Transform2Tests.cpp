#include <cassert>
#include <iostream>
#include <ostream>

#include "VecMatLib/Transform2.h"
//
// Created by chice on 3/28/2026.
//
extern bool nearlyEqual(double a, double b);
extern void runTest(const char* name, void (*testFunc)());
extern double EPS;

void testIdentity() {
  VecMatLib::Transform2 t;

  VecMatLib::Vec2 v(3, 2);
  VecMatLib::Vec2 result = t * v;

  assert(nearlyEqual(v.x, result.x) && nearlyEqual(v.y, result.y));
}

void testTranslation() {
  VecMatLib::Transform2 t = VecMatLib::Transform2::translation({2, 3});

  VecMatLib::Vec2 v(1, 1);
  VecMatLib::Vec2 result = t * v;

  assert(nearlyEqual(result.x, 3) && nearlyEqual(result.y, 4));
}

void testScale() {
  VecMatLib::Transform2 t = VecMatLib::Transform2::scaling(2, 3);
  VecMatLib::Vec2 v(1, 2);

  VecMatLib::Vec2 result = t * v;

  assert(nearlyEqual(result.x, 2) && nearlyEqual(result.y, 6));
}

void testRotation() {
  VecMatLib::Transform2 r =
      VecMatLib::Transform2::rotation(std::numbers::pi / 2);
  VecMatLib::Vec2 v(1, 0);
  VecMatLib::Vec2 result = r * v;

  assert(nearlyEqual(result.x, 0) && nearlyEqual(result.y, 1));
}

void testOrder() {
  VecMatLib::Transform2 translate;
  translate.translate({1, 0});

  VecMatLib::Transform2 rotate;
  rotate.rotate(std::numbers::pi / 2);

  VecMatLib::Vec2 v(1, 0);

  VecMatLib::Vec2 result1 = (rotate * translate) * v;
  VecMatLib::Vec2 result2 = (translate * rotate) * v;

  // Should NOT be equal
  assert(!(std::abs(result1.x - result2.x) < 1e-5 &&
           std::abs(result1.y - result2.y) < 1e-5));
}

void runTransform2Tests() {
  runTest("Transform Identity and multiplication test", testIdentity);
  runTest("Transform Translation test", testTranslation);
  runTest("Transform Scale test", testScale);
  runTest("Transform Rotation test", testRotation);
  runTest("Combination order", testOrder);
  std::cout << "Tests passed" << "\n\n";
}