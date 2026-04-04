//
// Created by chice on 4/4/2026.
//

#ifndef VECMATLIB_GEOMETRY_H
#define VECMATLIB_GEOMETRY_H
#include "Core/Vec3.h"

namespace VecMatLib::Geometry {
template <typename T>
struct Ray3 {
  Vec3<T> origin = Vec3<T>();
  Vec3<T> direction = Vec3<T>();
};

template<typename T>
struct Sphere {
  Vec3<T> center = Vec3<T>(0,0,0);
  T radius = 1;
};

template <typename T>
struct BoundingBox3 {
  Vec3<T> min = Vec3<T>();
  Vec3<T> max = Vec3<T>();


};

template <typename T>
struct Plane {
  Vec3<T> normal = Vec3<T>();  ///< normal vector off the plane, shows the direction the
  ///< plane is facing in space

  T distance = 0;  ///< the distance in the direction of the normal vector from the
  ///< origin in 3d space.
};

template<typename T>
struct LineSegment3 {
  Vec3<T> origin = Vec3<T>();
  Vec3<T> end = Vec3<T>();
};

template<typename T>
struct Triangle3 {
  Vec3<T> v1 = Vec3<T>();
  Vec3<T> v2 = Vec3<T>();
  Vec3<T> v3 = Vec3<T>();
};
}

#endif  // VECMATLIB_GEOMETRY_H
