#include <iostream>
#include "../include/vec3.hpp"
#include "../include/obj.hpp"
#include "../include/renderer.hpp"
#include "../include/sphere.hpp"
#include "../include/triangle.hpp"

int main() {
    // Image
    double aspect_ratio = 16.0 / 9.0;
    int img_width = 400;
    int img_height = static_cast<int>(img_width / aspect_ratio);
    img_height = (img_height < 1)? 1 : img_height; //img_height must be at least 1

    // Camera
    auto focal_length = 1.0;
    auto view_height = 2.0;
    auto view_width = view_height * (static_cast<double>(img_width) / img_height);
    point3 camera_center = point3(0, 0, 1.5);

    // Viewport vectors
    vec3 view_h = vec3(view_width, 0, 0); //horizontal
    vec3 view_v = vec3(0, -view_height, 0); //vertical

    // Delta vectors from pixel to pixel.
    vec3 pixel_delta_h = view_h / img_width;
    vec3 pixel_delta_v = view_v / img_height;

    // Calculate the location of the upper left pixel
    vec3 view_upper_left = camera_center - vec3(0, 0, focal_length) - view_h/2 - view_v/2;
    vec3 origin_pixel = view_upper_left + 0.5 * (pixel_delta_h + pixel_delta_v);

    /* Rendering */
    renderer R = renderer();
    // Gradient
    R.draw_gradient(img_width, img_height, camera_center, 
                    origin_pixel, pixel_delta_h, pixel_delta_v);
    // Sphere
    sphere s = sphere(point3(0, 0, 0), 0.5);
    R.draw_sphere(img_width, img_height, camera_center, 
                origin_pixel, pixel_delta_h, pixel_delta_v, s);
    // Triangle
    triangle t = triangle(point3(-0.5, -0.5, 0), point3(0.5, 0.5, 0), point3(0.7, -0.5, 0));
    R.draw_triangle(img_width, img_height, camera_center, 
                    origin_pixel, pixel_delta_h, pixel_delta_v, t);
    // Real objects
    obj ico = obj("../input/icosahedron.obj");
    R.draw_obj(img_width, img_height, camera_center, 
            origin_pixel, pixel_delta_h, pixel_delta_v, ico, "icosahedron");

    obj cat = obj("../input/cat.obj");
    R.draw_obj(img_width, img_height, camera_center, 
            origin_pixel, pixel_delta_h, pixel_delta_v, cat, "cat");
}
