#include "Ray.h"
#include <math.h>
Ray::Ray() {
	m_origin = Vector();
	m_direction = Vector();
	setInverse();
}

Ray::Ray(Vector origin) {
	m_origin = origin;
	m_direction = Vector();
	setInverse();
}

Ray::Ray(Vector origin, Vector direction) {
	m_origin = origin;
	m_direction = direction;
	setInverse();
}

void Ray::setOrigin(float x, float y, float z) {
	m_origin = Vector(x, y, z);
}

void Ray::setOrigin(Vector new_origin) {
	m_origin = new_origin;
}

void Ray::setDirection(float x, float y, float z) {
	m_direction = Vector(x, y, z);
	setInverse();
}

void Ray::setDirection(Vector new_direction) {
	m_direction = new_direction;
	setInverse();
}

void Ray::setInverse() {
	m_direction_inverse = Vector(powf(m_direction.getX(), -1.0f), powf(m_direction.getY(), -1.0f),
		powf(m_direction.getZ(), -1.0f));

	m_signx = ((int)m_direction_inverse.getX() < 0);
	m_signy = ((int)m_direction_inverse.getY() < 0);
	m_signz = ((int)m_direction_inverse.getZ() < 0);
}

void Ray::setMaxDepth(int new_max_depth) {
	m_max_depth = new_max_depth;
}

Vector Ray::getOrigin() const {
	return m_origin;
}

Vector Ray::getDirection() const {
	return m_direction;
}

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

int Ray::getMaxDepth() {
	return m_max_depth;
}