//
// Created by chice on 3/29/2026.
//
#include <cassert>
#include <iostream>

#include "../include/VecMatLib/Core/Mat3.h"
#include "../include/VecMatLib/Core/Vec3.h"

using namespace VecMatLib;

extern double EPS;
extern void runTest(const char* name, void (*testFunc)());
extern bool nearlyEqual(double a, double b);

void testDet() {
  Mat3<double> m(1,4,3,2,5,7,6,9,5);
  assert(nearlyEqual(m.det(), 54));
}

void testMinor() {
  Mat3<double> m(1,4,3,2,5,7,6,9,5);

  double result = m.minor(0,2);
  assert(nearlyEqual(result, -12));

}

void testCofactor() {
  Mat3<double> m(1,2,3,0,4,5,1,0,2);

  double result = m.cofactor(0,1);
  assert(nearlyEqual(result, 5));
}

void testCofactorMatrix() {
  Mat3<double> m(5,9,2,1,8,5,3,6,4);

  Mat3<double> cof = m.cofactorMatrix();
  assert( cof == Mat3<double>(2,11,-18,-24,14,-3,29,-23,31));
}

void testInverse() {
  Mat3<double> m(1,2,3,3,2,1,2,1,3);

  Mat3<double> I = m.inversed();
  Mat3<double> test = Mat3<double>(-5,3,4,7,3,-8,1,-3,4) * (1/12.0);

  assert(I == test);
}

void testMultiplication() {
  Mat3<double> m1(1,2,3,4,5,6,7,8,9);
  Mat3<double> m2(9,8,7,6,5,4,3,2,1);

  Mat3<double> res1 = m1 * m2;
  Mat3<double> res2 = m2 * m1;

  //assures that they shouldn't be equal
  assert(!(res1.row(0) == res2.row(0) && res1.col(0) == res2.col(0)));

  assert(res1 == Mat3<double>(30,24,18,84,69,54,138,114,90));
  assert(res2 == Mat3<double>(90,114,138,54,69,84,18,24,30));
}

void runMat3Tests() {
  runTest("Mat3<double> determinant test", testDet);
  runTest("Mat2 submatrix and minor test", testMinor);
  runTest("Mat3<double> cofactor test", testCofactor);
  runTest("Mat3<double> cofactor matrix test", testCofactorMatrix);
  runTest("Mat3<double> inverse test", testInverse);
  runTest("Mat3<double> multiplication test", testMultiplication);

  std::cout << "Tests passed\n\n";
}