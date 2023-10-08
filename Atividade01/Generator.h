#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

/// @brief Generate gradient image with <width> and <depth>. 
/// @param width Width of image.
/// @param height Height of image.
/// @param depth Depth of image
/// @param num_channels Number of color channels of image.
/// @return This function has no return.
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

/// @brief Generate a square at the center of image with <width> and <depth>. 
/// @param width Width of image.
/// @param height Height of image.
/// @param depth Depth of image
/// @param num_channels Number of color channels of image.
/// @param side_length Length of the square's side.
/// @return This function has no return.
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

/// @brief Generate a circle at the center of image with <width> and <depth>. 
/// @param width Width of image.
/// @param height Height of image.
/// @param depth Depth of image
/// @param num_channels Number of color channels of image.
/// @param radius Circle's radius.
/// @return This function has no return.
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