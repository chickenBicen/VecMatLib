#include "../include/VecMatLib/vec2.h"

#include <cassert>
#include <cmath>

using namespace vecmatlib;

const double EPS = 1e-6;

bool nearlyEqual( double a, double b ) { return std::abs( a - b ) < EPS; }

void testVec2Addition() {
	vec2 a( 1, 2 ), b( 3, 4 );
	vec2 c = a + b;

	assert( c.getX() == 4 );
	assert( c.getY() == 6 );
}

void testVec2Subtraction() {
	vec2 a( 5, 7 ), b( 2, 3 );
	vec2 c = a - b;

	assert(c.getX() == 3);
	assert(c.getY() == 4);
}

void testVec2Length(){
	vec2 v(3,4);
	assert(nearlyEqual(v.magnitude(), 5.0));
}

void testVec2Normalization(){
	vec2 v(3,4);
	vec2 n = v.normal();

	assert(nearlyEqual(n.magnitude(), 1.0));
	assert(nearlyEqual(n.getX(), 0.6));
	assert(nearlyEqual(n.getY(), 0.8));
}

void testVec2Dot(){
	vec2 a(1,2), b(3,4);

	double d = a.dot(b);
	
	assert(d == 11);
}

void runVec2Tests(){
	testVec2Addition();
	testVec2Subtraction();
	testVec2Length();
	testVec2Normalization();
	testVec2Dot();
}