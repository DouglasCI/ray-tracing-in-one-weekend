#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "hittable.hpp"
#include "vertex.hpp"
#include <tuple>

/// @brief Hittable derived class for a hittable triangle.
class triangle : public hittable {
    public:
        vertex A;
        vertex B;
        vertex C;

        /// @brief Default constructor.
        /// @param _A Vertex A.
        /// @param _B Vertex B.
        /// @param _C Vertex C.
        triangle(const vertex& _A, const vertex& _B, const vertex& _C, shared_ptr<material> _mat): 
            A(_A), B(_B), C(_C), mat(_mat) {
            vec3 u = B.coord - A.coord;
            vec3 v = C.coord - A.coord;
            normal = cross(u, v);
        }
        
        /// @brief Constructor with normal setting to avoid normal recalculation.
        /// @param _A Vertex A.
        /// @param _B Vertex B.
        /// @param _C Vertex C.
        /// @param _normal Triangle's normal.
        triangle(const vertex& _A, const vertex& _B, const vertex& _C, 
                const vec3& _normal, shared_ptr<material> _mat):
            A(_A), B(_B), C(_C), normal(_normal), mat(_mat) {}
        
        /// @brief Method for deciding a hit.
        /// @param r Ray.
        /// @param ray_t Valid ray interval.
        /// @param rec Hit record.
        /// @return True if the ray hits the triangle or false if it doesn't.
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            /* Find the point in which the ray intersects with the triangle's plane */
            // But if normal * d = 0, the ray is parallel to the plane
            double nd = dot(normal, r.direction());
            if(fabs(nd) < 1e-8) return false;

            double D = dot(normal, A.coord);
            double t = (D - dot(normal, r.origin())) / nd;
            
            // If t < 0, the plane is behind the ray, which is invalid
            if(t < 0) return false;

            // This guarantees sense of depth between multiple objects.
            if(!ray_t.surrounds(t)) return false;

            // Intersection
            point3 P = r.at(t);

            /* Now, check if the intersection point is inside the triangle */
            double w0, w1, w2; //barycentric coordinates

            // Check edge AB
            vec3 AB = B.coord - A.coord, AP = P - A.coord;
            vec3 ABxAP = cross(AB, AP);
            if(dot(normal, ABxAP) < 0) return false;

            // Check edge BC
            vec3 BC = C.coord - B.coord, BP = P - B.coord;
            vec3 BCxBP = cross(BC, BP);
            w0 = dot(normal, BCxBP); //store this value
            if(w0 < 0) return false;

            // Check edge CA
            vec3 CA = A.coord - C.coord, CP = P - C.coord;
            vec3 CAxCP = cross(CA, CP);
            w1 = dot(normal, CAxCP); //store this value
            if(w1 < 0) return false;

            double denom = normal.length_squared();
            w2 = 1.0 - w0/denom - w1/denom;

            // Record hit
            rec.t = t;
            rec.p = P;
            vec3 color_normal = unit_vector(A.normal*w0 + B.normal*w1 + C.normal*w2);
            // Decide surface's front face with the triangle's normal,
            // but use calculated normal from barycentric coordinates for the color.
            rec.set_face_normal(r, normal, color_normal);
            rec.mat = mat;

            // Intersection is inside the triangle.
            return true;
        }

    private:
        vec3 normal; //triangle's plane normal
        shared_ptr<material> mat;
};

#endif