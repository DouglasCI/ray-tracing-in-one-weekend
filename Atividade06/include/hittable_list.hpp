#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.hpp"

#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

/// @brief Class for a list of hittable objects, can represent a world.
class hittable_list : public hittable {
    public:
        std::vector<shared_ptr<hittable>> objects;

        /// @brief Empty constructor.
        hittable_list() {}

        /// @brief Constructor with an initial object.
        /// @param object Initial object.
        hittable_list(shared_ptr<hittable> object) { add(object); }

        /// @brief Remove all objects from world.
        void clear() { objects.clear(); }

        /// @brief Add an object to the world.
        /// @param object Object to be added.
        void add(shared_ptr<hittable> object) {
            objects.push_back(object);
        }

        /// @brief Decides if a ray hits any object from the world.
        /// @param r Ray.
        /// @param ray_t Valid ray interval.
        /// @param rec Hit record.
        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            auto closest_so_far = ray_t.max;

            for (const auto& object : objects) {
                if (object->hit(r, interval(ray_t.min, closest_so_far), temp_rec)) {
                    hit_anything = true;
                    closest_so_far = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
};

#endif