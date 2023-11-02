#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"

/// @brief Base class for hittable objects.
class hittable {
    public:
        virtual ~hittable() = default;

        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @return True if the ray hits the object or false if it doesn't.
        virtual bool hit(const ray& r) const = 0;
};

#endif