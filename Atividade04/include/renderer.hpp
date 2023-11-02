#ifndef TRACER_H
#define TRACER_H

#include <iostream>
#include "../include/CImg.h"
#include "../include/vec3.hpp"
#include "../include/obj.hpp"
#include "../include/ray.hpp"
#include "../include/sphere.hpp"
#include "../include/triangle.hpp"

using namespace std;
using namespace cimg_library;

/// @brief Class for tracing and drawing objects.
class renderer {
    public:
        renderer() {};

        /// @brief Draw a gradient.
        /// @param img_width Image width.
        /// @param img_height Image height.
        /// @param camera_center Camera position.
        /// @param origin_pixel Origin pixel position.
        /// @param pixel_delta_h Horizontal delta between pixels.
        /// @param pixel_delta_v Vertical delta between pixels.
        void draw_gradient(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                        const vec3& pixel_delta_h, const vec3& pixel_delta_v);
        
        /// @brief Draw a sphere.
        /// @param img_width Image width.
        /// @param img_height Image height.
        /// @param camera_center Camera position.
        /// @param origin_pixel Origin pixel position.
        /// @param pixel_delta_h Horizontal delta between pixels.
        /// @param pixel_delta_v Vertical delta between pixels.
        /// @param s Sphere that will be drawn.
        void draw_sphere(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                        const vec3& pixel_delta_h, const vec3& pixel_delta_v, const sphere& s);
        
        /// @brief Draw a triangle.
        /// @param img_width Image width.
        /// @param img_height Image height.
        /// @param camera_center Camera position.
        /// @param origin_pixel Origin pixel position.
        /// @param pixel_delta_h Horizontal delta between pixels.
        /// @param pixel_delta_v Vertical delta between pixels.
        /// @param s Triangle that will be drawn.
        void draw_triangle(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                        const vec3& pixel_delta_h, const vec3& pixel_delta_v, const triangle& t);
        
        /// @brief Draw an object.
        /// @param img_width Image width.
        /// @param img_height Image height.
        /// @param camera_center Camera position.
        /// @param origin_pixel Origin pixel position.
        /// @param pixel_delta_h Horizontal delta between pixels.
        /// @param pixel_delta_v Vertical delta between pixels.
        /// @param s Object that will be drawn.
        void draw_obj(int img_width, int img_height, const point3& camera_center, const vec3& origin_pixel, 
                    const vec3& pixel_delta_h, const vec3& pixel_delta_v, const obj& o, string name);

    private:
        /// @brief Decide the color of a pixel for drawing a gradient.
        /// @param r Ray that points to the pixel.
        /// @return Color of the pixel.
        color ray_color(const ray& r);

        /// @brief Decide the color of a pixel for drawing a sphere.
        /// @param r Ray that points to the pixel.
        /// @param s Sphere to be drawn.
        /// @return Color of the pixel.
        color ray_color(const ray& r, const sphere& s);

        /// @brief Decide the color of a pixel for drawing a triangle.
        /// @param r Ray that points to the pixel.
        /// @param t Triangle to be drawn.
        /// @return Color of the pixel.
        color ray_color(const ray& r, const triangle& t);

        /// @brief Decide the color of a pixel for drawing an object.
        /// @param r Ray that points to the pixel.
        /// @param t_list Group of triangles that compose an object.
        /// @return Color of the pixel.
        color ray_color(const ray& r, const vector<triangle>& t_list);
};

#endif