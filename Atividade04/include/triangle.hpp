#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.hpp"
#include "vec3.hpp"

/// @brief Hittable derived class for a hittable triangle.
class triangle : public hittable {
    public:
        /// @brief Constructor.
        /// @param A Vertex A.
        /// @param B Vertex B.
        /// @param C Vertex C.
        triangle(const point3& A, const point3& B, const point3& C): 
            A(A), B(B), C(C) {}
        
        /// @brief Abstract method for deciding a hit.
        /// @param r Ray.
        /// @return True if the ray hits the triangle or false if it doesn't.
        bool hit(const ray& r) const override {
            /* Find the normal vector of the triangle's plane */
            vec3 u = B - A;
            vec3 v = C - A;
            vec3 n = unit_vector(cross(u, v));

            /* Find the point in which the ray intersects with the triangle's plane */
            // But if n * d = 0, the ray is parallel to the plane
            double nd = dot(n, r.direction());
            if(fabs(nd) < 1e-8) { return false; }

            double D = dot(n, A);
            double t = (D - dot(n, r.origin())) / nd;
            
            // If t < 0, the plane is behind the ray, which is invalid
            if(t < 0) { return false; }

            // Intersection
            point3 P = r.at(t);

            /* Now, check if the intersection point is inside the triangle */
            // Check edge AB
            vec3 AB = B - A, AP = P - A;
            vec3 ABxAP = cross(AB, AP);
            if(dot(n, ABxAP) < 0) { return false; }

            // Check edge BC
            vec3 BC = C - B, BP = P - B;
            vec3 BCxBP = cross(BC, BP);
            if(dot(n, BCxBP) < 0) { return false; }

            // Check edge CA
            vec3 CA = A - C, CP = P - C;
            vec3 CAxCP = cross(CA, CP);
            if(dot(n, CAxCP) < 0) { return false; }

            // Intersection is inside the triangle
            return true;
        }

    private:
        point3 A;
        point3 B;
        point3 C;
};

#endif