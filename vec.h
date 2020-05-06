#pragma once

#include <stdexcept>
#include <math.h>

class Vector3 {
public:
	double e[3];

public:
	Vector3() : e{0, 0, 0} {}

	Vector3(double e1, double e2, double e3)
		: e{e1, e2, e3} {}

	Vector3& operator+=(Vector3 &other) {
		e[0] += other[0];
		e[1] += other[1];
		e[2] += other[2];
		return *this;
	}

	Vector3& operator-=(Vector3 &other) {
		e[0] -= other[0];
		e[1] -= other[1];
		e[2] -= other[2];
		return *this;
	}

	Vector3& operator*=(double t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	Vector3 operator-() const {
		return Vector3(-e[0], -e[1], -e[2]);
	}

	double operator[](int i) const {
		if (i < 0 || i > 2)
			throw std::invalid_argument("index out of bounds.");
		return e[i];
	}

	double length() const {
		return std::sqrt(length_squared());
	}

	double length_squared() const {
		return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
	}
};

inline std::ostream& operator<<(std::ostream& out, const Vector3& v) {
	return out << '[' << v[0] << ", " << v[1] << ", " << v[2] << ']'; 
}

inline Vector3 operator+(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline Vector3 operator-(const Vector3& v1, const Vector3& v2) {
	return Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline Vector3 operator*(double t, const Vector3& v) {
	return Vector3(t * v[0], t * v[1], t * v[2]);
}

inline Vector3 operator/(const Vector3& v, double t) {
	return (1 / t) * v;
}

inline double dot(const Vector3& v1, const Vector3& v2) {
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline Vector3 cross(const Vector3& v1, const Vector3& v2) {
	return Vector3(
			v1[1] * v2[2] - v2[1] * v1[2],
			-(v1[0] * v2[2] - v2[0] * v1[2]),
			v1[0] * v2[1] - v2[0] * v1[1]
		);
}

inline Vector3 unit_vector(Vector3& v) {
	return v / v.length();
}

using Point3d = Vector3;
using Color = Vector3;