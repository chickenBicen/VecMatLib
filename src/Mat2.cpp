//
// Created by chice on 3/24/2026.
//

#include "../include/VecMatLib/Mat2.h"
#include "../include/VecMatLib/vec2.h"

#include <iostream>

namespace VecMatLib {
    double Mat2::det() const {
        return a * d - b * c;
    }

    Mat2 Mat2::inversed() const {
        const double determinant = det();
        if (determinant == 0) {
            std::cout << "Potentially unintended behavior; Cannot inverse with det = 0";
            throw std::runtime_error("Matrix with det of 0 can NOT be inversed");
        }
        return Mat2(d, -b, -c, a) * (1 / determinant);
    }

    Mat2 Mat2::transposed() const {
        return {a, c, b, d};
    }

    Mat2 Mat2::operator*( double s ) const {
        return {a * s, b * s, c * s, d * s};
    }

    bool Mat2::operator==( const Mat2& m ) const {
        const double eps = 1e-6;
        return std::abs(a - m.a) < eps && std::abs(b - m.b) < eps && std::abs(c - m.c) < eps && std::abs(d - m.d) < eps;
    }

    Mat2 Mat2::operator+( const Mat2& m ) const {
        return {a + m.a, b + m.b, c + m.c, d + m.d};
    }

    Mat2 Mat2::operator-( const Mat2& m ) const {
        return {a - m.a, b - m.b, c - m.c, d - m.d};
    }

    Mat2 Mat2::operator*( const Mat2& m ) const {
        return {
            a * m.a + b * m.c,
            a * m.b + b * m.d,
            c * m.a + d * m.c,
            c * m.b + d * m.d
        };
    }

    vec2 Mat2::operator*( const vec2& v ) const {
        return {a * v.x + b * v.y, c * v.x + d * v.y};
    }
} // VecMatLib
