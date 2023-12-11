#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.hpp"

/// @brief Hittable derived class for a hittable sphere.
class sphere : public hittable {
    public:
        /// @brief Constructor.
        /// @param center Sphere's center coordinates.
        /// @param radius Sphere's radius.
        sphere(const point3& center, double radius): center(center), radius(radius) {}

        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @param ray_t Valid ray interval.
        /// @param rec Hit record.
        /// @return True if the ray hits the sphere or false if it doesn't.
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            vec3 oc = r.origin() - center;
            auto a = r.direction().length_squared();
            auto half_b = dot(oc, r.direction());
            auto c = oc.length_squared() - radius*radius;

            auto discriminant = half_b*half_b - a*c;
            if(discriminant < 0) return false;
            auto sqrtd = sqrt(discriminant);

            // Find the nearest root that lies in the acceptable range.
            auto root = (-half_b - sqrtd) / a;
            if(!ray_t.surrounds(root)) {
                root = (-half_b + sqrtd) / a;
                if (!ray_t.surrounds(root))
                    return false;
            }

            // Record hit
            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - center) / radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

    private:
        point3 center;
        double radius;
};

#endif