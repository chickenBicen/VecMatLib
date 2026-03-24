#pragma once
#include <cmath>
namespace vecmatlib {
	class vec2 {
	  private:
		double x, y;

	  public:
		vec2( double x_, double y_ ) : x( x_ ), y( y_ ) {}

		double magnitude() const;

		double distance( const vec2& v ) const;

		vec2 normal() const;
		vec2& normalize();

		double dot( const vec2& v );
		double cross(const vec2& v);

		double getX() const { return x; }
		double getY() const { return y; }

		vec2 operator+( const vec2& other ) const;
		vec2 operator-( const vec2& other ) const;
		vec2 operator*( double s ) const;
		vec2 operator/( double s ) const;

		vec2& operator+=( const vec2& other );
		vec2& operator-=( const vec2& other );
		vec2& operator*=( const double s );
		vec2& operator/=( const double s );
	};
} // namespace vecmatlib