#include "../include/VecMatLib/vec2.h"

#include "../include/VecMatLib/utils.h"

namespace vecmatlib {
	double vec2::magnitude() const { return std::sqrt( x * x + y * y ); }

	double vec2::distance( const vec2& v ) const { return vecmatlib::magnitude( v - *this ); }

	vec2 vec2::normal() const { return { x / magnitude(), y / magnitude() }; }
	vec2& vec2::normalize() {
		x /= magnitude();
		y /= magnitude();
		return *this;
	}

	double vec2::dot( const vec2& v ) { return x * v.x + y * v.y; }
	double vec2::cross( const vec2& v ) { return x * v.x - y * v.y; }

	vec2 vec2::operator+( const vec2& other ) const { return { x + other.x, y + other.y }; }
	vec2 vec2::operator-( const vec2& other ) const { return { x - other.x, y - other.y }; }
	vec2 vec2::operator*( double s ) const { return { x * s, y * s }; }
	vec2 vec2::operator/( double s ) const { return { x / s, y / s }; }

	vec2& vec2::operator+=( const vec2& other ) {
		x += other.x;
		y += other.y;
		return *this;
	}
	vec2& vec2::operator-=( const vec2& other ) {
		x -= other.x;
		y -= other.y;
		return *this;
	}
	vec2& vec2::operator*=( const double s ) {
		x *= s;
		y *= s;
		return *this;
	}
	vec2& vec2::operator/=( const double s ) {
		x /= s;
		y /= s;
		return *this;
	}
} // namespace vecmatlib