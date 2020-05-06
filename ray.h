#pragma once

#include "vec.h"

class Ray {
public:
	Point3d origin;
	Vector3 direction;

public:
	Ray() :
	origin(),
	direction()
		{}

	Ray(const Point3d& o, const Vector3& d) :
	origin(o[0], o[1], o[2]),
	direction(d[0], d[1], d[2])
		{}

	Point3d getOrigin() const { return origin; }
	Vector3 getDirection() const { return direction; }

	Point3d at(double t) const {
		return origin + t * direction;
	}
};