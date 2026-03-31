//
// Created by chice on 3/29/2026.
//
#include <cassert>
#include <iostream>

#include "../include/VecMatLib/Mat3.h"
#include "../include/VecMatLib/Vec3.h"

using namespace VecMatLib;

extern double EPS;
extern void runTest(const char* name, void (*testFunc)());
extern bool nearlyEqual(double a, double b);

void testDet() {
  Mat3 m(1,4,3,2,5,7,6,9,5);
  assert(nearlyEqual(m.det(), 54));
}

void testMinor() {
  Mat3 m(1,4,3,2,5,7,6,9,5);

  double result = m.minor(0,2);
  assert(nearlyEqual(result, -12));

}

void testCofactor() {
  Mat3 m(1,2,3,0,4,5,1,0,2);

  double result = m.cofactor(0,1);
  assert(nearlyEqual(result, 5));
}

void testCofactorMatrix() {
  Mat3 m(5,9,2,1,8,5,3,6,4);

  Mat3 cof = m.cofactorMatrix();
  assert( cof == Mat3(2,11,-18,-24,14,-3,29,-23,31));
}

void testInverse() {
  Mat3 m(1,2,3,3,2,1,2,1,3);

  Mat3 I = m.inversed();
  Mat3 test = Mat3(-5,3,4,7,3,-8,1,-3,4) * (1/12.0);

  assert(I == test);
}

void testMultiplication() {
  Mat3 m1(1,2,3,4,5,6,7,8,9);
  Mat3 m2(9,8,7,6,5,4,3,2,1);

  Mat3 res1 = m1 * m2;
  Mat3 res2 = m2 * m1;

  //assures that they shouldn't be equal
  assert(!(res1.row(0) == res2.row(0) && res1.col(0) == res2.col(0)));

  assert(res1 == Mat3(30,24,18,84,69,54,138,114,90));
  assert(res2 == Mat3(90,114,138,54,69,84,18,24,30));
}

void runMat3Tests() {
  runTest("Mat3 determinant test", testDet);
  runTest("Mat2 submatrix and minor test", testMinor);
  runTest("Mat3 cofactor test", testCofactor);
  runTest("Mat3 cofactor matrix test", testCofactorMatrix);
  runTest("Mat3 inverse test", testInverse);
  runTest("Mat3 multiplication test", testMultiplication);

  std::cout << "Tests passed\n\n";
}