#ifndef COMMONS_H
#define COMMONS_H

#include <cmath>
#include <limits>
#include <memory>
#include <random>

// Usings
using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants
const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

/// @brief Converts degress to radians.
/// @param degrees Degrees.
/// @return Radians.
inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

/// @brief Get a random real number in [0, 1).
/// @return Random real number.
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

/// @brief Get a random real number in [min, max).
/// @param min Minimum value.
/// @param max Maximum value.
/// @return Random real number.
inline double random_double(double min, double max) {
    // Returns a random real in [min, max).
    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

// Common Headers
#include "ray.hpp"
#include "vec3.hpp"
#include "interval.hpp"

#endif