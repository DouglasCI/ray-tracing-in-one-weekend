#ifndef CAMERA_H
#define CAMERA_H

#include "CImg.h"
#include "hittable.hpp"

using namespace cimg_library;

/// @brief Class to render a world.
class camera {
  public:
    double aspect_ratio = 16.0 / 9.0; //!< Ratio of image width over height.
    int img_width = 400; //!< Rendered image width in pixels.
    int samples_per_pixel = 10; //!< Number of random samples for each pixel.
    int max_depth = 10; //!< Maximum number of ray bounces.
    double gamma = 0.5; //!< Level of reflectance.
    double vfov = 90; //!< Vertical field of view.
    point3 look_from = point3(0, 0, -1); //!< Where camera is looking from.
    point3 look_at = point3(0, 0, 0); //!< Where camera is looking at.
    vec3 v_up = vec3(0, 1, 0); //!< Camera-relative up direction.
    string path = "../images/output.png"; //!< Path to save image.

    /// @brief Render world.
    /// @param world World.
    void render(const hittable& world) {
        initialize();

        CImg<unsigned char> img(img_width, img_height, 1, 3, 255);

        for(int y = 0; y < img_height; ++y) {
            for(int x = 0; x < img_width; ++x) {
                color pixel_color(0, 0, 0);

                for(int sample = 0; sample < samples_per_pixel; ++sample) {
                    ray r = get_ray(x, y);
                    // Sum colors of all samples.
                    pixel_color += ray_color(r, max_depth, world); 
                }

                // Get mean of color samples.
                double r = pixel_color.x() / samples_per_pixel;
                double g = pixel_color.y() / samples_per_pixel;
                double b = pixel_color.z() / samples_per_pixel;

                // Tranform data from linear to gamma 2 space.
                r = sqrt(r);
                g = sqrt(g);
                b = sqrt(b);

                // Ensure color values don't go beyond RGB bounds.
                static const interval intensity(0.000, 0.999);
                img(x, y, 0) = static_cast<int>(256 * intensity.clamp(r));
                img(x, y, 1) = static_cast<int>(256 * intensity.clamp(g));
                img(x, y, 2) = static_cast<int>(256 * intensity.clamp(b));
            }
        }

        img.save(path.c_str());
        clog << "\rGenerated image saved at " << path << endl;
    }

  private:
    int img_height; // Rendered image height.
    point3 camera_center; // Camera center coordinate.
    point3 origin_pixel; // Location of pixel 0, 0.
    vec3 pixel_delta_u; // Offset to pixel to the right.
    vec3 pixel_delta_v; // Offset to pixel below.
    vec3 u, v, w; // Camera positioning vectors.

    /// @brief Initialize camera parameters.
    void initialize() {
        img_height = static_cast<int>(img_width / aspect_ratio);
        img_height = (img_height < 1) ? 1 : img_height;

        camera_center = look_from;

        // Determine viewport dimensions.
        double focal_length = (look_from - look_at).length();
        double h = tan(degrees_to_radians(vfov) / 2);
        double view_height = 2.0 * h * focal_length;
        double view_width = view_height * (static_cast<double>(img_width) / img_height);

        // Calculate vectors for the camera coordinate frame.
        w = unit_vector(look_from - look_at);
        u = unit_vector(cross(v_up, w));
        v = cross(w, u);

        // Calculate the vectors across the horizontal and down the vertical viewport edges.
        vec3 view_u = view_width * u;
        vec3 view_v = view_height * -v;

        // Delta vectors ("distance") from pixel to pixel.
        pixel_delta_u = view_u / img_width;
        pixel_delta_v = view_v / img_height;

        // Calculate the location of the upper left pixel.
        point3 view_upper_left = camera_center - (focal_length * w) - view_u/2 - view_v/2;
        origin_pixel = view_upper_left + 0.5*(pixel_delta_u + pixel_delta_v);
    }

    /// @brief Get a randomly sampled camera ray for the pixel at (x, y).
    /// @param x X pixel coodinate.
    /// @param y Y pixel coordinate.
    /// @return Sampled ray.
    ray get_ray(int x, int y) const {
        point3 pixel_center = origin_pixel + (x * pixel_delta_u) + (y * pixel_delta_v);
        vec3 pixel_sampled = pixel_center + pixel_random_nudge();

        vec3 ray_origin = camera_center;
        vec3 ray_direction = pixel_sampled - ray_origin;

        return ray(ray_origin, ray_direction);
    }

    /// @brief Move a pixel to a random point around him.
    /// @return Random pixel movement.
    vec3 pixel_random_nudge() const {
        auto px = -0.5 + random_double();
        auto py = -0.5 + random_double();
        return (px * pixel_delta_u) + (py * pixel_delta_v);
    }

    /// @brief Draw color of pixel hit by ray.
    /// @param r Ray.
    /// @param world World.
    /// @return Pixel color.
    color ray_color(const ray& r, int depth, const hittable& world) const {
        hit_record rec;

        // If we've exceeded the ray bounce limit, no more light is gathered.
        if(depth <= 0) return color(0,0,0);

        if(world.hit(r, interval(0.001, infinity), rec)) {
            // return 0.5 * (rec.normal + color(1, 1, 1));
            vec3 direction = rec.normal + random_unit_vector();
            return gamma * ray_color(ray(rec.p, direction), depth - 1, world);
        }

        vec3 unit_direction = unit_vector(r.direction());
        double a = 0.5 * (unit_direction.y() + 1.0);
        return (1.0 - a)*color(1.0, 1.0, 1.0) + a*color(0.5, 0.7, 1.0);
    }
};

#endif