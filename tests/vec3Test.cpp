//
// Created by chice on 3/24/2026.
//
#include<cmath>
#include<cassert>
#include <iostream>

#include "../include/VecMatLib/vec3.h"
#include "VecMatLib/Mat2.h"
#include "VecMatLib/utils.h"
using namespace VecMatLib;

extern double EPS;
vec3 a(1, 2, 3), b(4, 5, 6);

extern bool nearlyEqual( double a, double b );

void testVec3Addition() {
    vec3 a(1, 2, 3), b(4, 5, 6);
    vec3 result = a + b;

    assert(result.x == 5 && result.y == 7 && result.z == 9);
}

void testVec3Subtraction() {
    vec3 result = a - b;

    assert(result.x == -3 && result.y == -3 && result.z == -3);
}

void testVec3Dot() {
    double res = a.dot(b);
    assert(res == 32);
}

void testVec3Cross() {
    vec3 result = a.cross(b);
    assert(result.x == -3 && result.y == 6 && result.z == -3);
}

void testVec3Dist() {
    double dist = VecMatLib::distance(a, b);
    assert(nearlyEqual(dist, std::sqrt(27)));
}

void runTest( const char* name, void (*testFunc)() ) {
    std::cout << "Running " << name << "...";
    testFunc();
    std::cout << "OK\n";
}

void runVec3Tests() {
    runTest("vec 3 addition test", testVec3Addition);
    runTest("vec 3 subtraction test", testVec3Subtraction);
    runTest("vec 3 dot test", testVec3Dot);
    runTest("vec 3 cross test", testVec3Cross);
    runTest("vec3 distance function test", testVec3Dist);

    const vec3 big(1e9, 1e9, 1e9);

    assert(nearlyEqual(a.dot(b), b.dot(a)));
    assert(big.magnitude() > 0);
    assert(nearlyEqual(big.normal().magnitude(), 1));
}
