/*!
 * \file Implementation of methods from obj class.
 */

#include "../include/obj.hpp"

obj::obj(string path) {
    if(path.substr(path.size() - 4, 4) != ".obj") {
        clog << "> File from this path is not in .obj format!\n";
        exit(1);
    }

    ifstream file(path);
    if(!file.is_open()) {
        clog << "> Error opening file!\n";
        exit(1);
    }

    string line;
    while(getline(file, line)) {
        string firstToken = line.substr(0, line.find(" "));

        // Geometric vertices
        if(firstToken == "v") {
            string valuesStr = line.substr(3, line.size() - 3);
            stringstream ss(valuesStr);
            double x, y, z;
            ss >> x >> y >> z;
            vVec.push_back(vec3(x, y, z));
        }

        // Texture coordinates
        if(firstToken == "vt") {
            string valuesStr = line.substr(3, line.size() - 3);
            stringstream ss(valuesStr);
            double x, y;
            ss >> x >> y;
            vtVec.push_back(vec2(x, y));
        }

        // Vertex normals
        if(firstToken == "vn") {
            string valuesStr = line.substr(3, line.size() - 3);
            stringstream ss(valuesStr);
            double x, y, z;
            ss >> x >> y >> z;
            vnVec.push_back(vec3(x, y, z));
        }

        // Face elements
        if(firstToken == "f") {
            string indList, valuesStr = line.substr(2, line.size() - 2);
            stringstream ss(valuesStr);
            vector<array<int, 3>> faceVertices;

            // For every list of indices in each vertex...
            while(ss >> indList) {
                faceVertices.push_back(parseFaceVertexIndices(indList));
            }
            // of this face
            fVec.push_back(faceVertices);
        }

        // Material file name
        if(firstToken == "mtllib") {
            materialFileName = line.substr(7, line.size() - 7);
        }

        // Group name
        if(firstToken == "g") {
            groupName = line.substr(2, line.size() - 2);
        }

        // Materials names
        if(firstToken == "usemtl") {
            materialsNames.push_back(line.substr(7, line.size() - 7));
        }
    }
}

string obj::getGeometricVerticesString() {
    string str;
    for(vec3 v: vVec) {
        string formatted_str = "v ";
        for(int n = 0; n < 3; n++) {
            // Convert coordinates to string with 4 decimals precision
            stringstream ss;
            ss << std::fixed << std::setprecision(4) << v[n];
            formatted_str.append(" " + ss.str());
        }
        str.append(formatted_str + "\n");
    }
    return str;
}

string obj::getTextureCoordinatesString() {
    string str;
    for(vec2 vt: vtVec) {
        string formatted_str = "vt";
        for(int n = 0; n < 2; n++) {
            // Convert coordinates to string with 4 decimals precision
            stringstream ss;
            ss << std::fixed << std::setprecision(4) << vt[n];
            formatted_str.append(" " + ss.str());
        }
        formatted_str.append(" 0.0000");
        str.append(formatted_str + "\n");
    }
    return str;
}

string obj::getVertexNormalsString() {
    string str;
    for(vec3 vn: vnVec) {
        string formatted_str = "vn";
        for(int n = 0; n < 3; n++) {
            // Convert coordinates to string with 4 decimals precision
            stringstream ss;
            ss << std::fixed << std::setprecision(4) << vn[n];
            formatted_str.append(" " + ss.str());
        }
        str.append(formatted_str + "\n");
    }
    return str;
}

string obj::getFaceElementsString() {
    string str;
    for(vector<array<int, 3>> faceVertices: fVec) {
        string formatted_str = "f ";
        for(array<int, 3> indList: faceVertices) {
            stringstream ss;
            ss << indList[0];
            // Optional indices
            if(indList[1] != 0 && indList[2] == 0) {
                ss << "/" << indList[1];
            } else if(indList[1] != 0 && indList[2] != 0 ) {
                ss << "/" << indList[1] << "/" << indList[2];
            } else if(indList[1] == 0 && indList[2] != 0) {
                ss << "//" << indList[2];
            }
            formatted_str.append(ss.str() + " ");
        }
        str.append(formatted_str + "\n");
    }
    return str;
}

array<int, 3> obj::parseFaceVertexIndices(string indList) {
    array<int, 3> indices;
    stringstream ss(indList);
    string ind, indicesStr[3];
    
    int n = 0;
    while(getline(ss, ind, '/')) {
        indicesStr[n] = ind;
        n++;
    }

    indices[0] = stoi(indicesStr[0]);

    // Check optional indices (0 means no index)
    indices[1] = (indicesStr[1].empty()) ? 0 : stoi(indicesStr[1]);
    indices[2] = (indicesStr[2].empty()) ? 0 : stoi(indicesStr[2]);

    return indices;
}