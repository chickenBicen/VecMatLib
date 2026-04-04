//
// Created by chice on 3/24/2026.
//

#include <cassert>
#include <cmath>
#include <iostream>

#include "VecMatLib/Mat2.h"
extern double EPS;
extern void runTest(const char* name, void (*testFunc)());
extern bool nearlyEqual(const double a, const double b);

using namespace VecMatLib;

void testMat2Addition() {
  Mat2<double> b(0, 0, 0, 0), c(1, 2, 3, 4), d(5, 6, 7, 8);
  assert(c + d == Mat2<double>(6, 8, 10, 12));
}

void testMat2Multiplication() {
  Mat2<double> b(0, 0, 0, 0), c(1, 2, 3, 4), d(5, 6, 7, 8);
  assert(c * d == Mat2<double>(19, 22, 43, 50));
}

void testMat2xVec2() {
  Mat2<double> b(0, 0, 0, 0), c(1, 2, 3, 4), d(5, 6, 7, 8);
  Vec2<double> v(1, 1);
  assert(c * v == Vec2<double>(3, 7));
}

void testMat2Inverse() {
  Mat2<double> c(1, 2, 3, 4);
  Mat2<double> I = c * c.inversed();

  assert(nearlyEqual(I.mat_[0][0], 1));
  assert(nearlyEqual(I.mat_[0][1], 0));
  assert(nearlyEqual(I.mat_[1][0], 0));
  assert(nearlyEqual(I.mat_[1][1], 1));
}

void testMat2Transpose() {
  Mat2<double> b(0, 0, 0, 0), c(1, 2, 3, 4), d(5, 6, 7, 8);
  Mat2<double> I = c.transposed();

  assert(I == Mat2<double>(1, 3, 2, 4));
}

void runMat2Tests() {
  runTest("Mat2 addition test", testMat2Addition);
  runTest("mat2 multiplication test", testMat2Multiplication);
  runTest("mat2 - vec2 multiplication test", testMat2xVec2);
  runTest("mat2 inverse test", testMat2Inverse);
  runTest("Mat2 transpose test", testMat2Transpose);

  std::cout << "Tests passed" << "\n\n";
}
