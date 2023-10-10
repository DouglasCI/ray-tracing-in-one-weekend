#include "Generator.h"

int main() {
    unsigned int width = 256;
    unsigned int height = 256;
    unsigned int depth = 1;
    unsigned int num_channels = 3;

    generate_gradient(width, height, depth, num_channels);
    generate_square(width, height, depth, num_channels, 200);
    generate_circle(width, height, depth, num_channels, 70);
}