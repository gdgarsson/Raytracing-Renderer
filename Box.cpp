#include "Box.h"
#include <utility>

// Default Box Constructor
Box::Box() {
	setPosition(Vector());
}

// Create a box with specifed width and length at the given position
Box::Box(float width, float length, Vector position) {
	setPosition(position);
	m_width = width;
	m_length = length;
}

// Create a box with specifed width and length at the given position, with a given forward direction
Box::Box(float width, float length, Vector position, Vector forward) {
	setPosition(position);
	m_width = width;
	m_length = length;
	m_forward = forward;
}

// Create a box with specifed width, length, and height at the given position
Box::Box(float width, float length, float height, Vector position) {
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = height;
}

// Create a box with specifed width, length, and height at the given position, with a given forward direction
Box::Box(float width, float length, float height, Vector position, Vector forward) {
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = height;
	m_forward = forward;
}

// Create boxes with specified boundaries - currently unused.
Box::Box(Vector min_bound, Vector max_bound) {
	setPosition(Vector());
	m_bound_min = min_bound;
	m_bound_max = max_bound;
}

// Create boxes with specified boundaries at a given position - currently unused.
Box::Box(Vector min_bound, Vector max_bound, Vector position) {
	setPosition(position);
	m_bound_min = min_bound;
	m_bound_max = max_bound;
}

// Setter: changes the value of the box's width
void Box::setWidth(float new_width) {
	m_width = new_width;
}

// Setter: changes the value of the box's length
void Box::setLength(float new_length) {
	m_length = new_length;
}

// Setter: changes the value of the box's height
void Box::setHeight(float new_height) {
	m_height = new_height;
}

// Setter: multiplies the box's width by a given value
void Box::scaleWidth(float scalar) {
	m_width *= scalar;
}

// Setter: multiplies the box's length by a given value
void Box::scaleLength(float scalar) {
	m_length *= scalar;
}

// Setter: multiplies the box's height by a given value
void Box::scaleHeight(float scalar) {
	m_height *= scalar;
}

// Setter: multiplies the size of the entire box by a given value
void Box::scale(float scalar) {
	m_width *= scalar;
	m_length *= scalar;
	m_height *= scalar;
}

// Setter: sets the forward direction to a new direction. Currently unused.
void Box::setForward(Vector new_forward) {
	m_forward = new_forward;
}

// Setter: sets the minimum and maximum boundaries for the box. Currently unused.
void Box::setBounds(Vector min, Vector max) {
	m_bound_min = min;
	m_bound_max = max;
}

// Getter: returns the box's width
float Box::getWidth() {
	return m_width;
}

// Getter: returns the box's length
float Box::getLength() {
	return m_length;
}

// Getter: returns the box's height
float Box::getHeight() {
	return m_height;
}

// Getter: returns the box's forward direction. Currently unused.
Vector Box::getForward() {
	return m_forward;
}

// Getter: returns the box's minimum boundary. Currently unused.
Vector Box::getMinBound() {
	return m_bound_min;
}

// Getter: returns the box's maximum boundary. Currently unused.
Vector Box::getMaxBound() {
	return m_bound_max;
}


// Box intersect test - returns true if a given ray intersects the box. Currently uses boundaries, which are unused.
//   Modifies distance value to be from the ray origin to intersect point on IsectInfo if the test returns true
bool Box::intersects(const Ray& ray, IntersectInfo& IsectInfo) {
	float tmin, tmax, tymin, tymax, tzmin, tzmax;

	tmin = (m_bound_min.getX() - ray.getOrigin().getX()) * ray.getInverseDirection().getX();
	tmax = (m_bound_max.getX() - ray.getOrigin().getX()) * ray.getInverseDirection().getX();
	tymin = (m_bound_min.getY() - ray.getOrigin().getY()) * ray.getInverseDirection().getY();
	tymax = (m_bound_max.getY() - ray.getOrigin().getY()) * ray.getInverseDirection().getY();

	if ((tmin > tymax) || (tymin > tmax)) return false;
	
	if (tymin > tmin) tmin = tymin;
	if (tymax > tmax) tmax = tymax;

	tzmin = (m_bound_min.getZ() - ray.getOrigin().getZ()) * ray.getInverseDirection().getZ();
	tzmax = (m_bound_max.getZ() - ray.getOrigin().getZ()) * ray.getInverseDirection().getZ();

	if ((tmin > tzmax) || (tzmin > tmax)) return false;

	if (tzmin > tmin) tmin = tzmin;
	if (tzmax > tmax) tmax = tzmax;

	IsectInfo.t = (tmin < tmax) ? tmin : tmax;

	return true;
}