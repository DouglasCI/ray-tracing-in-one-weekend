#ifndef VERTEX_H
#define VERTEX_H

#include "vec3.hpp"

/// @brief Class for a vertex.
class vertex {
    public:
        point3 coord;
        vec3 normal = vec3(0, 0, 0); //starts without a normal

        /// @brief Constructor.
        /// @param _coord Coordinates of the vertex.
        vertex(const point3& _coord): 
            coord(_coord) {}
};

#endif