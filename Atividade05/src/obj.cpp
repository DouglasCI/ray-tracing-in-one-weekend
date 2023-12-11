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
        string first_token = line.substr(0, line.find(" "));

        // Geometric vertices
        if(first_token == "v") {
            string values_str = line.substr(2, line.size() - 3);
            stringstream ss(values_str);
            double x, y, z;
            ss >> x >> y >> z;
            v_vec.push_back(vec3(x, y, z));
        }

        // Texture coordinates
        if(first_token == "vt") {
            string values_str = line.substr(3, line.size() - 3);
            stringstream ss(values_str);
            double x, y;
            ss >> x >> y;
            vt_vec.push_back(vec2(x, y));
        }

        // Vertex normals
        if(first_token == "vn") {
            string values_str = line.substr(3, line.size() - 3);
            stringstream ss(values_str);
            double x, y, z;
            ss >> x >> y >> z;
            vn_vec.push_back(vec3(x, y, z));
        }

        // Face elements
        if(first_token == "f") {
            string ind_list, values_str = line.substr(2, line.size() - 2);
            stringstream ss(values_str);
            vector<array<int, 3>> face_vertices;

            // For every list of indices in each vertex...
            while(ss >> ind_list) {
                face_vertices.push_back(parse_face_ind(ind_list));
            }
            // of this face
            f_vec.push_back(face_vertices);
        }

        // Material file name
        if(first_token == "mtllib") {
            mat_file_name = line.substr(7, line.size() - 7);
        }

        // Group name
        if(first_token == "g") {
            group_name = line.substr(2, line.size() - 2);
        }

        // Materials names
        if(first_token == "usemtl") {
            mat_names.push_back(line.substr(7, line.size() - 7));
        }
    }
}

string obj::get_geometric_vertices_string() {
    string str;
    for(vec3 v: v_vec) {
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

string obj::get_texture_coord_string() {
    string str;
    for(vec2 vt: vt_vec) {
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

string obj::get_vertex_normals_string() {
    string str;
    for(vec3 vn: vn_vec) {
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

string obj::get_face_elements_string() {
    string str;
    for(vector<array<int, 3>> face_vertices: f_vec) {
        string formatted_str = "f ";
        for(array<int, 3> ind_list: face_vertices) {
            stringstream ss;
            ss << ind_list[0];
            // Optional indices
            if(ind_list[1] != 0 && ind_list[2] == 0) {
                ss << "/" << ind_list[1];
            } else if(ind_list[1] != 0 && ind_list[2] != 0 ) {
                ss << "/" << ind_list[1] << "/" << ind_list[2];
            } else if(ind_list[1] == 0 && ind_list[2] != 0) {
                ss << "//" << ind_list[2];
            }
            formatted_str.append(ss.str() + " ");
        }
        str.append(formatted_str + "\n");
    }
    return str;
}

vector<triangle> obj::get_triangle_faces() {
    /* Collect all triangles from obj */
    vector<triangle> triangle_list;
    // For each face
    for(vector<array<int, 3>> face : f_vec) {
        // Get indices for geometric vertices of the triangular face
        int index_A = (face[0])[0] - 1;
        int index_B = (face[1])[0] - 1;
        int index_C = (face[2])[0] - 1;

        point3 A = unit_vector(v_vec[index_A]);
        point3 B = unit_vector(v_vec[index_B]);
        point3 C = unit_vector(v_vec[index_C]);

        triangle_list.push_back(triangle(A, B, C));
    }

    return triangle_list;
}

array<int, 3> obj::parse_face_ind(string ind_list) {
    array<int, 3> indices;
    stringstream ss(ind_list);
    string ind, ind_str[3];
    
    int n = 0;
    while(getline(ss, ind, '/')) {
        ind_str[n] = ind;
        n++;
    }

    indices[0] = stoi(ind_str[0]);

    // Check optional indices (0 means no index)
    indices[1] = (ind_str[1].empty()) ? 0 : stoi(ind_str[1]);
    indices[2] = (ind_str[2].empty()) ? 0 : stoi(ind_str[2]);

    return indices;
}