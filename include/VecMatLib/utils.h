#pragma once
#include "vec2.h"
#include "vec3.h"
#include "mat2.h"
#include <cmath>
#include <algorithm>

namespace VecMatLib {
    vec2 lerp( const vec2& a, const vec2& b, double t );
    vec3 lerp( const vec3& a, const vec3& b, double t );

    double magnitude( const vec2& v );

    Mat2 rotationMat2( double angle );

    template<typename Vec>
        requires requires( Vec v )
        {
            v.dot(v);
            v.magnitude();
        }
    double angle( const Vec& a, const Vec& b ) {
        double dot = a.dot(b);
        double mag = b.magnitude() * a.magnitude();

        double val = dot / mag;
        val = std::clamp(val, -1.0, 1.0);
        return std::acos(val);
    }

    template<typename Vec>
        requires requires( Vec v )
        {
            v.magnitude();
        }
    double distance( const Vec& a, const Vec& b ) {
        Vec ab = a - b;
        return ab.magnitude();
    }
} // namespace vecmatlib
