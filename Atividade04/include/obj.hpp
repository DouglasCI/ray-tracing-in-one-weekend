#ifndef OBJ_H
#define OBJ_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <iomanip>

#include "vec2.hpp"
#include "vec3.hpp"

using namespace std;

/// @brief Class for obj files.
class obj {
    public:
        vector<vec3> vVec; ///< Geometric vertices
        vector<vec2> vtVec; ///< Texture coordinates
        vector<vec3> vnVec; ///< Vertex normals
        vector<vector<array<int, 3>>> fVec; ///< Face elements

        // Object metadata
        string groupName = ""; ///< Group name for object
        string materialFileName = ""; ///< File name of materials
        vector<string> materialsNames; ///< List of materials used

        /// @brief Constructor.
        /// @param path Path to obj file.
        obj(string path);

        /// @brief Get geometric vertices of this object in string format.
        /// @return String formatted for obj files.
        string getGeometricVerticesString();

        /// @brief Get texture coordinates of this object in string format.
        /// @return String formatted for obj files.
        string getTextureCoordinatesString();

        /// @brief Get vertex normals of this object in string format.
        /// @return String formatted for obj files.
        string getVertexNormalsString();

        /// @brief Get face elements of this object in string format.
        /// @return String formatted for obj files.
        string getFaceElementsString();

    private:
        /// @brief Parse indices separated by '/' character and convert to int.
        /// @param indList String of indices.
        /// @return Array of indices converted to int.
        array<int, 3> parseFaceVertexIndices(string indList);
};

#endif