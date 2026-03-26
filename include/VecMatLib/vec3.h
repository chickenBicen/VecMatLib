//
// Created by chice on 3/23/2026.
//

#ifndef VECMATLIB_VEC3_H
#define VECMATLIB_VEC3_H

namespace VecMatLib {
    class vec3 {
    private:


    public:
        const double x, y, z;
        vec3( double x, double y, double z ) : x( x ), y( y ), z( z ) {}
        vec3() : x( 0 ), y( 0 ), z( 0 ) {}

        double magnitude() const;
        double dot( const vec3& v ) const;
        vec3 cross( const vec3& v ) const;

        vec3 normal() const;

        vec3 operator-( const vec3& v ) const;
        vec3 operator+( const vec3& v ) const;
        vec3 operator*( double s ) const;
        vec3 operator/( double s ) const;
    };
} // namespace vecmatlib

#endif //VECMATLIB_VEC3_H