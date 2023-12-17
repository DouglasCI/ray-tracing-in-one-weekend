#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.hpp"

class hit_record;

/// @brief Class for a generic material.
class material {
  public:
    virtual ~material() = default;
    
    /// @brief Virtual method for scattering rays.
    /// @param r_in Incoming ray.
    /// @param rec Hit record.
    /// @param attenuation Color attenuation.
    /// @param scattered Scattered ray.
    /// @return True if the scattered ray is valid.
    virtual bool scatter(const ray& r_in, const hit_record& rec, 
                        color& attenuation, ray& scattered) const = 0;
};

/// @brief Class for a Lambertian (diffuse) material.
class lambertian : public material {
    public:
        /// @brief Constructor.
        /// @param a Levels of light reflection.
        lambertian(const color& a) : albedo(a) {}

        /// @brief Method for scattering rays.
        /// @param r_in Incoming ray.
        /// @param rec Hit record.
        /// @param attenuation Color attenuation.
        /// @param scattered Scattered ray.
        /// @return True if the scattered ray is valid.
        bool scatter(const ray& r_in, const hit_record& rec, 
                    color& attenuation, ray& scattered) const override {
            vec3 scatter_direction = rec.normal + random_unit_vector();

            // Prevent a zero scatter direction vector.
            if (scatter_direction.near_zero())
                scatter_direction = rec.normal;

            scattered = ray(rec.p, scatter_direction);
            attenuation = albedo;

            return true;
        }

    private:
        color albedo;
};

/// @brief Class for a metalic material.
class metal : public material {
    public:
        /// @brief Constructor.
        /// @param a Levels of light reflection.
        /// @param f Fuzziness (blurring of the reflection).
        metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

        /// @brief Method for scattering rays.
        /// @param r_in Incoming ray.
        /// @param rec Hit record.
        /// @param attenuation Color attenuation.
        /// @param scattered Scattered ray.
        /// @return True if the scattered ray is valid.
        bool scatter(const ray& r_in, const hit_record& rec, 
                    color& attenuation, ray& scattered) const override {
            vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
            scattered = ray(rec.p, reflected + fuzz*random_unit_vector());
            attenuation = albedo;

            // Absorb rays that scattered below the surface.
            return(dot(scattered.direction(), rec.normal) > 0);
        }

    private:
        color albedo;
        double fuzz;
};

/// @brief Class for a dielectric material.
class dielectric : public material {
  public:
    /// @brief Constructor.
    /// @param index_of_refraction Refractive index.
    dielectric(double index_of_refraction) : ir(index_of_refraction) {}
    
    /// @brief Method for scattering rays.
    /// @param r_in Incoming ray.
    /// @param rec Hit record.
    /// @param attenuation Color attenuation.
    /// @param scattered Scattered ray.
    /// @return True if the scattered ray is valid.
    bool scatter(const ray& r_in, const hit_record& rec, color& attenuation, ray& scattered)
    const override {
        attenuation = color(1.0, 1.0, 1.0);
        double refraction_ratio = rec.front_face ? (1.0 / ir) : ir;

        vec3 unit_direction = unit_vector(r_in.direction());
        double cos_theta = fmin(dot(-unit_direction, rec.normal), 1.0);
        double sin_theta = sqrt(1.0 - cos_theta*cos_theta);

        bool cannot_refract = refraction_ratio * sin_theta > 1.0;
        vec3 direction;

        // If the ray cannot be refracted, it must reflect.
        if(cannot_refract || reflectance(cos_theta, refraction_ratio) > random_double())
            direction = reflect(unit_direction, rec.normal);
        else
            direction = refract(unit_direction, rec.normal, refraction_ratio);

        scattered = ray(rec.p, direction);

        return true;
    }

  private:
    double ir;

    // Use Schlick's approximation for reflectance.
    static double reflectance(double cosine, double ref_idx) {
        double r0 = (1 - ref_idx) / (1 + ref_idx);
        r0 = r0 * r0;
        return r0 + (1 - r0)*pow((1 - cosine), 5);
    }
};

#endif