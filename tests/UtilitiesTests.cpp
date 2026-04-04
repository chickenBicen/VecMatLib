//
// Created by chice on 4/3/2026.
//
#include <../include/VecMatLib/Math/utils.h>

#include <cassert>

#include "../assert.h"

extern bool nearlyEqual(double a, double b);
extern void runTest(const char* name, void (*testFunc)());

using namespace VecMatLib;

void angleTest() {
  Vec2<double> a(1, 2), b(3, 4);
  double angle = VecMatLib::angle(a, b);
  assert(nearlyEqual(angle, 0.1798534998));
}

void clampTest() {
  Vec2<double> a(1, 2), b(3, 4);
  double angle = VecMatLib::angle(a, b);

  VecMatLib::clamp(a, 1);
  assert(nearlyEqual(angle, VecMatLib::angle(a, b)));
}

void runUtilitiesTests() {
  std::cout << "lastly utility tests";
  runTest("angle test", angleTest);
  runTest("clamp test", clampTest);

  std::cout << "tests passed!" << "\n\n";
}