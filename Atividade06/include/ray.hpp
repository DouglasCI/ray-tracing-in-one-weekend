#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

// Alias
using color = vec3;

/// @brief Class for rays.
class ray {
    public:
        /// @brief Empty constructor.
        ray() {}

        /// @brief Default constructor.
        /// @param origin Origin of the ray.
        /// @param direction Direction of the ray.
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

        /// @brief Get ray origin.
        /// @return Ray origin.
        point3 origin() const { return orig; }

        /// @brief Get ray direction.
        /// @return Ray direction.
        vec3 direction() const { return dir; }

        /// @brief Get a point in the ray given an offset.
        /// @param t Offset.
        /// @return Resultant point.
        point3 at(double t) const {
            return orig + t * dir;
        }

    private:
        point3 orig;
        vec3 dir;
};

#endif