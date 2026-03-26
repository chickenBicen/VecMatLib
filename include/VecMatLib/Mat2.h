//
// Created by chice on 3/24/2026.
//

#ifndef VECMATLIB_MAT2_H
#define VECMATLIB_MAT2_H
#include "../VecMatLib/vec2.h"

namespace VecMatLib {
    class Mat2 {
    private:

    public:
        const double a, b, c, d;

        Mat2( double a, double b, double c, double d ) : a(a), b(b), c(c), d(d) {
        }

        Mat2() : a(1), b(0), c(0), d(1) {
        }

        double det() const;

        Mat2 inversed() const;

        Mat2 transposed() const;

        Mat2 operator+( const Mat2& m ) const;
        Mat2 operator-( const Mat2& m ) const;
        Mat2 operator*( const Mat2& m ) const;
        vec2 operator*( const vec2& v ) const;
        Mat2 operator*( double s ) const;
        bool operator==( const Mat2& m ) const;
    };
} // VecMatLib

#endif //VECMATLIB_MAT2_H
