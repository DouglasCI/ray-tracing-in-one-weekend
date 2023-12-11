#include "../include/obj.hpp"
#include "../include/sphere.hpp"
#include "../include/triangle.hpp"
#include "../include/hittable_list.hpp"
#include "../include/camera.hpp"

int main() {
    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // world.add(make_shared<triangle>(point3(-0.5, -0.5, 0), point3(0.5, -0.5, 0), point3(0, 1, 0)));
    // world.add(make_shared<triangle>(point3(-0.5, -0.5, 0), point3(-1, 0.25, -1), point3(0, 1, 0)));
    // world.add(make_shared<triangle>(point3(1, 0.25, -1), point3(0.5, -0.5, 0), point3(0, 1, 0)));
    
    // obj ico = obj("../input/icosahedron.obj");
    // for(triangle t : ico.get_triangle_faces()) {
    //     world.add(make_shared<triangle>(t));
    // }

    // Camera
    camera cam1;
    cam1.path = "../images/output_cam1.png";
    cam1.aspect_ratio = 16.0 / 9.0;
    cam1.img_width = 400;
    cam1.samples_per_pixel = 1;
    cam1.look_from = point3(0, 0, 3);
    cam1.look_at = point3(0, 0, 0);
    cam1.v_up = vec3(0, 1, 0);
    cam1.render(world);

    camera cam2;
    cam2.path = "../images/output_cam2.png";
    cam2.aspect_ratio = 16.0 / 9.0;
    cam2.img_width = 400;
    cam2.samples_per_pixel = 40;
    cam2.look_from = point3(1, 1.25, 3);
    cam2.look_at = point3(0, 0, 0);
    cam2.v_up = vec3(0, 1, 0);
    cam2.render(world);
}
