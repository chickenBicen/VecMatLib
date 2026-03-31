//
// Created by chice on 3/29/2026.
//
#include <cassert>
#include <iostream>

#include "../include/VecMatLib/Transform3.h"

using namespace VecMatLib;

extern bool nearlyEqual(double a, double b);
extern void runTest(const char* name, void (*testFunc)());

bool matEqual(const Mat3& a, const Mat3& b, double eps = 1e-9) {
  for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
      if(!nearlyEqual(a.mat_[i][j], b.mat_[i][j]))
        return false;
  return true;
}

void testTransform3Rotation() {
  Transform3 t;
  t.rotate({0,0,1}, std::numbers::pi / 2);

  Vec3 v = {1,0,0};
  Vec3 result = t * v;
  // (1,0,0) rotated 90° around Z → (0,1,0)
  assert(std::abs(result.x) < 1e-6);
  assert(std::abs(result.y - 1) < 1e-6);
  assert(std::abs(result.z) < 1e-6);
}

void testQuaternionDrift() {
  Transform3 t;

  // Small rotation around Z-axis
  Vec3 axis{0, 0, 1};
  double angle = 0.01; // radians (~0.57°)

  // Apply the small rotation 10,000 times
  for (int i = 0; i < 10000; ++i) {
    t.rotate(axis, angle);
  }

  // Check that the quaternion is still normalized
  double mag = t.getRotation().magnitude();
  assert(std::abs(mag - 1.0) < 1e-6 && "Quaternion drift exceeded tolerance!");

  // Optional: check a vector rotates approximately correctly
  Vec3 v{1, 0, 0};
  Vec3 rotated = t * v;
  double len = rotated.magnitude();
  assert(std::abs(len - 1.0) < 1e-6 && "Rotated vector lost length due to drift!");
}

void runTransform3Tests() {
  runTest("Transform3 rotation test", testTransform3Rotation);
  runTest("Quaternion floating point drift test", testQuaternionDrift);

  std::cout << "Tests passed! (these are the worst)";
}