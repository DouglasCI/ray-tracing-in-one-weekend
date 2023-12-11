#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.hpp"

/// @brief Hittable derived class for a hittable triangle.
class triangle : public hittable {
    public:
        vec3 normal; //triangle's plane normal vector

        /// @brief Constructor.
        /// @param A Vertex A.
        /// @param B Vertex B.
        /// @param C Vertex C.
        triangle(const point3& _A, const point3& _B, const point3& _C) {
            A = _A;
            B = _B;
            C = _C;
            vec3 u = B - A;
            vec3 v = C - A;
            normal = unit_vector(cross(u, v));
        }
        
        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @param ray_t Valid ray interval.
        /// @param rec Hit record.
        /// @return True if the ray hits the triangle or false if it doesn't.
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            /* Find the point in which the ray intersects with the triangle's plane */
            // But if normal * d = 0, the ray is parallel to the plane
            double nd = dot(normal, r.direction());
            if(fabs(nd) < 1e-8) { return false; }

            double D = dot(normal, A);
            double t = (D - dot(normal, r.origin())) / nd;
            
            // If t < 0, the plane is behind the ray, which is invalid
            if(t < 0) { return false; }

            // Intersection
            point3 P = r.at(t);

            /* Now, check if the intersection point is inside the triangle */
            // Check edge AB
            vec3 AB = B - A, AP = P - A;
            vec3 ABxAP = cross(AB, AP);
            if(dot(normal, ABxAP) < 0) { return false; }

            // Check edge BC
            vec3 BC = C - B, BP = P - B;
            vec3 BCxBP = cross(BC, BP);
            if(dot(normal, BCxBP) < 0) { return false; }

            // Check edge CA
            vec3 CA = A - C, CP = P - C;
            vec3 CAxCP = cross(CA, CP);
            if(dot(normal, CAxCP) < 0) { return false; }

            // Record hit
            rec.t = t;
            rec.p = P;
            vec3 outward_normal = normal;
            rec.set_face_normal(r, outward_normal);

            // Intersection is inside the triangle
            return true;
        }

    private:
        point3 A;
        point3 B;
        point3 C;
};

#endif