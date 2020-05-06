#include <iostream>
#include <cstdlib>

#include "vec.h"
#include "color.h"
#include "ray.h"

double rand_double() {
	return ((double) rand() / (RAND_MAX));
}

void write_header(int width, int height) {
	std::cerr << "Printing header...\n" << std::flush;

	std::cout << "P3\n";
	std::cout << width << ' ' << height << '\n';
	std::cout << 255 << '\n';
}

Color ray_color(const Ray& r) {
	Vector3 u = unit_vector(r.getDirection());
	double grad = 0.5 * (u[1] + 1);
	return (1 - grad) * Color(1, 1, 1) + grad * Color(0.4, 0.6, 1);
}

int main() {
	const double aspect_ratio = 16.0 / 9.0;

	const int image_width = 256;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

	write_header(image_width, image_height);

	Point3d origin(0, 0, 0);
	Vector3 x_max(4, 0, 0);
	Vector3 y_max(0, 2.25, 0);
	Point3d bottom_left(origin - x_max / 2 - y_max / 2 - Point3d(0, 0, 1));


	for (int y = 0; y < image_height; y++) {
		std::cerr << "Printing scanline: " << y << '\n' << std::flush;
		for (int x = 0; x < image_width; x++) {
			double xf = double(x) / (image_width - 1);
			double yf = double(y) / (image_height - 1);

			Ray r(origin, bottom_left + xf * x_max + yf * y_max);
			write_color(std::cout, ray_color(r));
		}
	}
}