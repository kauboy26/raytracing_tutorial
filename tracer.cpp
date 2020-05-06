#include <iostream>
#include <cstdlib>

#include "vec.h"
#include "color.h"


int main() {
	const int image_width = 256;
	const int image_height = 256;

	std::cerr << "Printing header...\n" << std::flush;

	// Add header.
	std::cout << "P3\n";
	std::cout << image_width << ' ' << image_height << '\n';
	std::cout << 255 << '\n';

	Color c;

	// color each pixel randomly
	for (int y = 0; y < image_height; y++) {
		for (int x = 0; x < image_width; x++) {
			c = Color(1, 1, 1);
			write_color(c);
		}
	}
}