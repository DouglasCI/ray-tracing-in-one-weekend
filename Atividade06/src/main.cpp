#include "../include/obj.hpp"
#include "../include/sphere.hpp"
#include "../include/triangle.hpp"
#include "../include/hittable_list.hpp"
#include "../include/camera.hpp"
#include "../include/material.hpp"

int main() {
    // World
    hittable_list world;

    auto material_ground = make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_sphere = make_shared<dielectric>(1.5);
    auto material_ico = make_shared<metal>(color(0.8, 0.6, 0.2), 0.0);

    world.add(make_shared<sphere>(point3(0.0, -101, -1.0), 100.0, material_ground));
    world.add(make_shared<sphere>(point3(2, 0.0, 0), 1, material_sphere));

    obj ico = obj("../input/icosahedron.obj", material_ico);
    for(triangle t : ico.get_triangle_faces()) {
        world.add(make_shared<triangle>(t));
    }

    // Camera
    camera cam1;
    cam1.path = "../images/output_cam1.png";
    cam1.aspect_ratio = 16.0 / 9.0;
    cam1.img_width = 400;
    cam1.samples_per_pixel = 40;
    cam1.max_depth = 50;
    cam1.vfov = 90;
    cam1.look_from = point3(1, 0, 2);
    cam1.look_at = point3(1, 0, 0);
    cam1.v_up = vec3(0, 1, 0);
    cam1.render(world);

    camera cam2;
    cam2.path = "../images/output_cam2.png";
    cam2.aspect_ratio = 16.0 / 9.0;
    cam2.img_width = 400;
    cam2.samples_per_pixel = 40;
    cam2.max_depth = 50;
    cam2.vfov = 90;
    cam2.look_from = point3(1.6, 1, -2);
    cam2.look_at = point3(1, 0, 0);
    cam2.v_up = vec3(0, 1, 0);
    cam2.render(world);
}
