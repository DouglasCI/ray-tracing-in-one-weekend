#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"
#include "vec3.hpp"

/// @brief Hittable derived class for a hittable sphere.
class sphere : public hittable {
    public:
        /// @brief Constructor.
        /// @param center Sphere's center coordinates.
        /// @param radius Sphere's radius.
        sphere(const point3& center, double radius): center(center), radius(radius) {}

        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @return True if the ray hits the sphere or false if it doesn't.
        bool hit(const ray& r) const override {
            vec3 oc = r.origin() - center;
            auto a = dot(r.direction(), r.direction());
            auto b = 2.0 * dot(oc, r.direction());
            auto c = dot(oc, oc) - radius * radius;
            auto discriminant = b * b - 4 * a * c;
            return discriminant >= 0;
        }

    private:
        point3 center;
        double radius;
};

#endif