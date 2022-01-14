#include "Ray.h"
#include <math.h>

// Default constructor - creates a ray at the origin heading (0,0,0)
Ray::Ray() {
	m_origin = Vector();
	m_direction = Vector();
	setInverse();
}

// Create a ray at a specified point heading towards (0,0,0)
Ray::Ray(Vector ray_origin) {
	m_origin = ray_origin;
	m_direction = Vector();
	setInverse();
}


// Create a ray at a specified point heading in a given direction
Ray::Ray(Vector ray_origin, Vector direction) {
	m_origin = ray_origin;
	m_direction = direction;
	setInverse();
}

// Setter: set the origin point of the ray with given X, Y, and Z values
void Ray::setOrigin(float x, float y, float z) {
	m_origin = Vector(x, y, z);
}

// Setter: set the origin point of the ray with a given Vector
void Ray::setOrigin(Vector new_origin) {
	m_origin = new_origin;
}

// Setter: set the direction of the ray with given X, Y, and Z values
void Ray::setDirection(float x, float y, float z) {
	m_direction = Vector(x, y, z);
	setInverse();
}

// Setter: set the direction of the ray with a given Vector
void Ray::setDirection(Vector new_direction) {
	m_direction = new_direction;
	setInverse();
}

// Private Setter: set the inverse direction of the given direction
void Ray::setInverse() {
	m_direction_inverse = Vector(powf(m_direction.getX(), -1.0f), powf(m_direction.getY(), -1.0f),
		powf(m_direction.getZ(), -1.0f));

	m_signx = ((int)m_direction_inverse.getX() < 0);
	m_signy = ((int)m_direction_inverse.getY() < 0);
	m_signz = ((int)m_direction_inverse.getZ() < 0);
}

// Setter: set the maximum depth of the ray
void Ray::setMaxDepth(int new_max_depth) {
	m_max_depth = new_max_depth;
}

// Getter: get the origin point of the ray
Vector Ray::getOrigin() const {
	return m_origin;
}

// Getter: get the direction of the ray
Vector Ray::getDirection() const {
	return m_direction;
}

// Getter: get the inverse direction of the ray
Vector Ray::getInverseDirection() const {
	return m_direction_inverse;
}

int Ray::getSignX() {
	return m_signx;
}

int Ray::getSignY() {
	return m_signy;
}

int Ray::getSignZ() {
	return m_signz;
}

// Getter: get the maximum depth of the ray
int Ray::getMaxDepth() {
	return m_max_depth;
}