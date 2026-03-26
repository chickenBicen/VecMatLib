#include "../include/VecMatLib/vec2.h"

#include "../include/VecMatLib/utils.h"

namespace VecMatLib {
	double vec2::magnitude() const { return std::sqrt( x * x + y * y ); }

	double vec2::distance( const vec2& v ) const { return VecMatLib::magnitude( v - *this ); }

	vec2 vec2::normal() const {
		if (x == 0 && y == 0) return { 0.0, 0.0 };
		return { x / magnitude(), y / magnitude() };
	}

	double vec2::dot( const vec2& v ) const{ return x * v.x + y * v.y; }
	double vec2::cross( const vec2& v ) const { return x * v.y - y * v.x; }

	vec2 vec2::operator+( const vec2& other ) const { return { x + other.x, y + other.y }; }
	vec2 vec2::operator-( const vec2& other ) const { return { x - other.x, y - other.y }; }
	vec2 vec2::operator*( double s ) const { return { x * s, y * s }; }

	vec2 vec2::operator/( double s ) const { return { x / s, y / s }; }

	bool vec2::operator==( const vec2& v ) const {
		const double eps = 1e-6;
		return std::abs(x - v.x) < eps && std::abs(y - v.y) < eps;
	}
} // namespace vecmatlib