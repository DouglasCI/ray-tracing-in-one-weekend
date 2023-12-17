#ifndef OBJ_H
#define OBJ_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <iomanip>

#include "triangle.hpp"
#include "vec2.hpp"

using namespace std;

/// @brief Class for obj files.
class obj {
    public:
        vector<vec3> v_vec; ///< Geometric vertices
        vector<vec2> vt_vec; ///< Texture coordinates
        vector<vec3> vn_vec; ///< Vertex normals
        vector<vector<array<int, 3>>> f_vec; ///< Face elements

        // Object metadata
        string group_name = ""; ///< Group name for object

        /// @brief Constructor.
        /// @param path Path to obj file.
        obj(string path, shared_ptr<material> _mat);

        /// @brief Get geometric vertices of this object in string format.
        /// @return String formatted for obj files.
        string get_geometric_vertices_string();

        /// @brief Get texture coordinates of this object in string format.
        /// @return String formatted for obj files.
        string get_texture_coord_string();

        /// @brief Get vertex normals of this object in string format.
        /// @return String formatted for obj files.
        string get_vertex_normals_string();

        /// @brief Get face elements of this object in string format.
        /// @return String formatted for obj files.
        string get_face_elements_string();

        /// @brief Get face elements as a list of triangle class' objects.
        /// @return List of triangle objects.
        vector<triangle> get_triangle_faces();

    private:
        shared_ptr<material> mat;

        /// @brief Parse indices separated by the '/' character and convert to int.
        /// @param ind_list String of indices.
        /// @return Array of indices converted to int.
        array<int, 3> parse_face_ind(string ind_list);
};

#endif