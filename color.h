#pragma once

#include <iostream>
#include "vec.h"

void write_color(std::ostream& out, const Color& c) {
	out << (int) (255 * c[0])
		<< ' ' << (int) (255 * c[1])
		<< ' ' << (int) (255 * c[2])
		<< '\n';
}