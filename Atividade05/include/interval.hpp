#ifndef INTERVAL_H
#define INTERVAL_H

/// @brief Class for managing real-valued intervals.
class interval {
  public:
    double min, max;

    /// @brief Default constructor.
    interval() : min(+infinity), max(-infinity) {}

    /// @brief Constructor with set minimum and maximum.
    /// @param _min Minimum value.
    /// @param _max Maximum value.
    interval(double _min, double _max) : min(_min), max(_max) {}

    /// @brief Check if value is inside interval, including bounds (like [min, max]).
    /// @param x Value to check.
    bool contains(double x) const {
        return min <= x && x <= max;
    }

    /// @brief Check if value is inside interval, excluding bounds (like (min, max)).
    /// @param x Value to check.
    bool surrounds(double x) const {
        return min < x && x < max;
    }

    /// @brief Ensures that a given value stays within the interval.
    /// @param x Value.
    /// @return Value clamped between interval bounds.
    double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);

#endif