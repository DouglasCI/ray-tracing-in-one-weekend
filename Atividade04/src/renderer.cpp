/*!
 * \file Implementation of methods from renderer class.
 */

#include "../include/renderer.hpp"

void renderer::draw_gradient(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                            const vec3& pixel_delta_h, const vec3& pixel_delta_v) {

    CImg<unsigned char> img(img_width, img_height, 1, 3, 255);

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            point3 pixel_center = origin_pixel + (x * pixel_delta_h) + (y * pixel_delta_v);
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r);

            img(x, y, 0) = static_cast<int>(255.999 * pixel_color.x());
            img(x, y, 1) = static_cast<int>(255.999 * pixel_color.y());
            img(x, y, 2) = static_cast<int>(255.999 * pixel_color.z());
        }
    }

    string path = "../images/gradient.png";
    img.save(path.c_str());
    clog << "\rGenerated image saved at " << path << endl;
}

void renderer::draw_sphere(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                            const vec3& pixel_delta_h, const vec3& pixel_delta_v, const sphere& s) {

    CImg<unsigned char> img(img_width, img_height, 1, 3, 255);

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            point3 pixel_center = origin_pixel + (x * pixel_delta_h) + (y * pixel_delta_v);
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, s);

            img(x, y, 0) = static_cast<int>(255.999 * pixel_color.x());
            img(x, y, 1) = static_cast<int>(255.999 * pixel_color.y());
            img(x, y, 2) = static_cast<int>(255.999 * pixel_color.z());
        }
    }

    string path = "../images/sphere.png";
    img.save(path.c_str());
    clog << "\rGenerated image saved at " << path << endl;
}

void renderer::draw_triangle(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                            const vec3& pixel_delta_h, const vec3& pixel_delta_v, const triangle& t) {

    CImg<unsigned char> img(img_width, img_height, 1, 3, 255);

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            point3 pixel_center = origin_pixel + (x * pixel_delta_h) + (y * pixel_delta_v);
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, t);

            img(x, y, 0) = static_cast<int>(255.999 * pixel_color.x());
            img(x, y, 1) = static_cast<int>(255.999 * pixel_color.y());
            img(x, y, 2) = static_cast<int>(255.999 * pixel_color.z());
        }
    }

    string path = "../images/triangle.png";
    img.save(path.c_str());
    clog << "\rGenerated image saved at " << path << endl;
}

void renderer::draw_obj(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                        const vec3& pixel_delta_h, const vec3& pixel_delta_v, const obj& o, string name) {
    
    /* Collect all triangles from obj */
    vector<triangle> triangle_list;
    // For each face
    for(vector<array<int, 3>> face : o.fVec) {
        // Get indices for geometric vertices of the triangular face
        int index_A = (face[0])[0] - 1;
        int index_B = (face[1])[0] - 1;
        int index_C = (face[2])[0] - 1;

        point3 A = unit_vector(o.vVec[index_A]);
        point3 B = unit_vector(o.vVec[index_B]);
        point3 C = unit_vector(o.vVec[index_C]);

        triangle t = triangle(A, B, C);
        triangle_list.push_back(t);
    }

    CImg<unsigned char> img(img_width, img_height, 1, 3, 255);

    for (int y = 0; y < img_height; ++y) {
        for (int x = 0; x < img_width; ++x) {
            point3 pixel_center = origin_pixel + (x * pixel_delta_h) + (y * pixel_delta_v);
            vec3 ray_direction = pixel_center - camera_center;
            ray r(camera_center, ray_direction);

            color pixel_color = ray_color(r, triangle_list);

            img(x, y, 0) = static_cast<int>(255.999 * pixel_color.x());
            img(x, y, 1) = static_cast<int>(255.999 * pixel_color.y());
            img(x, y, 2) = static_cast<int>(255.999 * pixel_color.z());
        }
    }

    string path = "../images/" + name + ".png";
    img.save(path.c_str());
    clog << "\rGenerated image saved at " << path << endl;
}

color renderer::ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto a = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - a) * color(1.0, 1.0, 1.0) + a * color(0.5, 0.7, 1.0);
}

color renderer::ray_color(const ray& r, const sphere& s) {
    if(s.hit(r))
        return color(1, 0, 0);

    return color(1, 1, 1);
}

color renderer::ray_color(const ray& r, const triangle& t) {
    if(t.hit(r))
        return color(0, 1, 0.5);

    return color(1, 1, 1);
}

color renderer::ray_color(const ray& r, const vector<triangle>& t_list) {
    for(triangle t : t_list) {
        if(t.hit(r))
            return color(0.1, 0.4, 0.2);
    }

    return color(1, 1, 1);
}