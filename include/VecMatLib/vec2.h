#pragma once
#include <cmath>

namespace VecMatLib {
    class vec2 {
    private:

    public:
        const double x, y;

        vec2( double x_, double y_ ) : x(x_), y(y_) {
        }

        [[nodiscard]] double magnitude() const;

        [[nodiscard]] double distance( const vec2& v ) const;

        [[nodiscard]] vec2 normal() const;

        [[nodiscard]] double dot( const vec2& v ) const;
        [[nodiscard]] double cross( const vec2& v ) const;

        vec2 operator+( const vec2& other ) const;
        vec2 operator-( const vec2& other ) const;
        vec2 operator*( double s ) const;
        vec2 operator/( double s ) const;
        bool operator==( const vec2& v ) const;
    };
} // namespace vecmatlib
