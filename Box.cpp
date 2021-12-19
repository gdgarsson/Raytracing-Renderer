#include "Box.h"
#include <utility>

Box::Box() {
	//BaseObject();

	setPosition(Vector());
	
	m_width = 1;
	m_length = 1;
	m_height = 1;

	m_forward = Vector();

}

Box::Box(Vector min_bound, Vector max_bound) {
	setPosition(Vector());
	m_bound_min = min_bound;
	m_bound_max = max_bound;
}

Box::Box(Vector min_bound, Vector max_bound, Vector position) {
	setPosition(position);
	m_bound_min = min_bound;
	m_bound_max = max_bound;
}



Box::Box(float width, float length, Vector position) {
	//BaseObject(position);
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = 1;
	m_forward = Vector();
}

Box::Box(float width, float length, Vector position, Vector forward) {
	//BaseObject(position);
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = 1;
	m_forward = forward;
}

Box::Box(float width, float length, float height, Vector position) {
	//BaseObject(position);
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = height;
	m_forward = Vector();
}

Box::Box(float width, float length, float height, Vector position, Vector forward) {
	//BaseObject(position);
	setPosition(position);
	m_width = width;
	m_length = length;
	m_height = height;
	m_forward = forward;
}

void Box::setWidth(float new_width) {
	m_width = new_width;
}

void Box::setLength(float new_length) {
	m_width = new_length;
}

void Box::setHeight(float new_height) {
	m_width = new_height;
}

void Box::scaleX(float scalar) {
	m_width *= scalar;
}

void Box::scaleY(float scalar) {
	m_length *= scalar;
}

void Box::scaleZ(float scalar) {
	m_height *= scalar;
}

void Box::scaleXY(float scalar) {
	m_width *= scalar;
	m_length *= scalar;
}

void Box::scaleXZ(float scalar) {
	m_width *= scalar;
	m_height *= scalar;
}

void Box::scaleYZ(float scalar) {
	m_length *= scalar;
	m_height *= scalar;
}

void Box::scale(float scalar) {
	m_width *= scalar;
	m_length *= scalar;
	m_height *= scalar;
}

void Box::setForward(Vector new_forward) {
	new_forward = new_forward;
}

void Box::setBounds(Vector min, Vector max) {
	m_bound_min = min;
	m_bound_max = max;
}

float Box::getWidth() {
	return m_width;
}

float Box::getLength() {
	return m_length;
}

float Box::getHeight() {
	return m_height;
}

Vector Box::getForward() {
	return m_forward;
}

Vector Box::getMinBound() {
	return m_bound_min;
}

Vector Box::getMaxBound() {
	return m_bound_max;
}

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