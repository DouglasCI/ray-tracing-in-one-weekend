#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

void generate_gradient(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels);

void generate_square(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels, unsigned int side_length);

void generate_circle(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels, unsigned int radius);

int main() {
    unsigned int width = 256;
    unsigned int height = 256;
    unsigned int depth = 1;
    unsigned int num_channels = 3;

    generate_gradient(width, height, depth, num_channels);
    generate_square(width, height, depth, num_channels, 200);
    generate_circle(width, height, depth, num_channels, 70);
}

void generate_gradient(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels) {
    
    clog << "\rGenerating gradient...\n";

    CImg<unsigned char> img_gradient(width, height, depth, num_channels, 255);

    // Draw gradient
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            auto r = double(width - x) / (width - 1);
            auto g = double(height - y) / (height - 1);
            auto b = double(y / 2) / (height - 1);

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            img_gradient(x, y, 0) = ir;
            img_gradient(x, y, 1) = ig;
            img_gradient(x, y, 2) = ib;
        }
    }

    clog << "\rGradient done.\n";

    img_gradient.save("../images/gradient.png");
}

void generate_square(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels, unsigned int side_length) {
    
    clog << "\rGenerating square...\n";

    CImg<unsigned char> img_square(width, height, depth, num_channels, 255);

    // Get center point of image
    unsigned int xc = width / 2;
    unsigned int yc = height / 2;

    // Get bounds of square
    int x1 = xc - side_length / 2; //bottom
    int x2 = xc + side_length / 2; //top
    int y1 = yc - side_length / 2; //left
    int y2 = yc + side_length / 2; //right

    // Draw square
    for(int y = y1; y < y2; y++) {
        for(int x = x1; x < x2; x++) {
            img_square(x, y, 0) = 0;
            img_square(x, y, 1) = 150;
            img_square(x, y, 2) = 66;
        }
    }

    clog << "\rSquare done.\n";

    img_square.save("../images/square.png");
}

void generate_circle(unsigned int width, unsigned int height, unsigned int depth,
                        unsigned int num_channels, unsigned int radius) {
    
    clog << "\rGenerating circle...\n";

    CImg<unsigned char> img_circle(width, height, depth, num_channels, 255);

    // Get center point of image
    unsigned int xc = width / 2;
    unsigned int yc = height / 2;

    // Draw circle
    for(int y = 0; y < height; y++) {
        for(int x = 0; x < width; x++) {
            // Use formula to check if the point is inside the circle
            int dx = xc - x;
            int dy = yc - y;

            if((dx * dx + dy * dy) <= (radius * radius)) {
                img_circle(x, y, 0) = 188;
                img_circle(x, y, 1) = 0;
                img_circle(x, y, 2) = 45;
            }
        }
    }

    clog << "\rCircle done.\n";

    img_circle.save("../images/circle.png");
}