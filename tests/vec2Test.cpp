#include <cassert>
#include <cmath>
#include <iostream>

#include "../include/VecMatLib/Vec2.h"

using namespace VecMatLib;

constexpr double EPS = 1e-9;

void runTest(const char* name, void (*testFunc)()) {
  std::cout << "Running " << name << "...";
  testFunc();
  std::cout << "OK\n";
}

bool nearlyEqual(const double a, const double b) {
  return std::abs(a - b) < EPS;
}

void testVec2Addition() {
  Vec2 a(1, 2), b(3, 4);
  Vec2 c = a + b;

  assert(c.x == 4);
  assert(c.y == 6);
}

void testVec2Subtraction() {
  Vec2 a(5, 7), b(2, 3);
  Vec2 c = a - b;

  assert(c.x == 3.0);
  assert(c.y == 4.0);
}

void testVec2Length() {
  Vec2 v(3, 4);
  assert(nearlyEqual(v.magnitude(), 5.0));
}

void testVec2Normalization() {
  Vec2 v(3, 4);
  Vec2 n = v.normal();

  assert(nearlyEqual(n.magnitude(), 1.0));
  assert(nearlyEqual(n.x, 0.6));
  assert(nearlyEqual(n.y, 0.8));
}

void testVec2Dot() {
  Vec2 a(1, 2), b(3, 4);
  Vec2 c(1, 0), d(0, 1);

  double res = a.dot(b);
  double res2 = c.dot(b);

  assert(res == 11.0);
  assert(nearlyEqual(c.dot(d), 0));
}

void testVec2Cross() {
  Vec2 a(1, 2), b(3, 4);
  double c = a.cross(b);

  assert(c == -2.0);
}

void runVec2Tests() {
  runTest("vec2 addition test", testVec2Addition);
  runTest("vec2 subtraction test", testVec2Subtraction);
  runTest("vec2 length test", testVec2Length);
  runTest("vec2 normalization test", testVec2Normalization);
  runTest("vec2 dot test", testVec2Dot);
  runTest("vec2 cross test", testVec2Cross);

  assert(Vec2(1, 1) - Vec2(1, 1) == Vec2(0, 0));
  std::cout  << "Tests passed" << "\n\n";
}