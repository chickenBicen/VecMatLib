//
// Created by chice on 3/23/2026.
//
#include "../include/VecMatLib/vec3.h"

#include <cmath>

namespace VecMatLib {
    double vec3::magnitude() const { return std::sqrt(x * x + y * y + z * z); }
    double vec3::dot( const vec3& v ) const { return x * v.x + y * v.y + z * v.z; }

    vec3 vec3::cross( const vec3& v ) const { return {y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x}; }

    vec3 vec3::normal() const {
        if (x == 0 && y == 0 && z == 0) {
            return *this;
        }
        return {x / magnitude(), y / magnitude(), z / magnitude()};
    }

    vec3 vec3::operator+( const vec3& other ) const { return {x + other.x, y + other.y, z + other.z}; }
    vec3 vec3::operator-( const vec3& other ) const { return {x - other.x, y - other.y, z - other.z}; }
    vec3 vec3::operator*( double s ) const { return {x * s, y * s, z * s}; }
    vec3 vec3::operator/( double s ) const { return {x / s, y / s, y / s}; }
} // namespace vecmatlib
