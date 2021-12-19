#include "Sphere.h"
#include <math.h>
#include <utility>
#include <iostream>
#include "Utility.h"

Sphere::Sphere() {
	//BaseObject();
	setPosition(Vector());
	m_radius = 1;
	m_forward = Vector();
	setColor(Vector());
}

Sphere::Sphere(Vector position) {
	//Object(position)
	setPosition(position);
	m_radius = 1;
	m_forward = Vector();
	setColor(Vector());
}

Sphere::Sphere(Vector position, Vector color) {
	setPosition(position);
	m_radius = 1;
	m_forward = Vector();
	setColor(color);
}

Sphere::Sphere(float radius, Vector position) {
	//BaseObject(position);
	setPosition(position);
	m_radius = radius;
	m_forward = Vector();
	setColor(Vector());
}

Sphere::Sphere(float radius, Vector position, Vector color) {
	//BaseObject(position);
	setPosition(position);
	m_radius = radius;
	m_forward = Vector();
	setColor(color);
}

Sphere::Sphere(float radius, Vector position, Vector color, Vector forward) {
	setPosition(position);
	m_radius = radius;
	m_forward = forward;
	setColor(color);
}


void Sphere::setRadius(float new_radius) {
	m_radius = new_radius;
}

void Sphere::setForward(Vector new_forward) {
	m_forward = new_forward;
}

void Sphere::scale(float scalar) {
	m_radius *= scalar;
}

float Sphere::getRadius() {
	return m_radius;
}

Vector Sphere::getForward() {
	return m_forward;
}

// This version is able to modify the t value
bool Sphere::intersects(const Ray& ray, IntersectInfo& IsectInfo) {
	Utility util;
	float t0, t1;
#if 0
	// Geometric solution
	Vector L = getPosition() - ray.getOrigin();
	float tca = util.dot3D(L, ray.getDirection());
	if (tca < 0) return false;

	float d = sqrtf(util.dot3D(L, L) - powf(tca, tca));
	if (powf(d, 2) > powf(getRadius(), 2)) return false; // Overshoots the radius of the sphere

	float thc = sqrtf(powf(getRadius(), 2) - powf(d, 2));

	t0 = tca - thc;
	t1 = tca + thc;
	
#else
	// Analytic solution
	Vector L = ray.getOrigin() - getPosition();
	float a = util.dot3D(ray.getDirection(), ray.getDirection());
	float b = 2 * util.dot3D(ray.getDirection(), L);
	float c = util.dot3D(L, L) - powf(getRadius(), 2);
	if (!util.solveQuadratic(a, b, c, t0, t1)) return false; // If unable to solve the quadratic involving a, b, and c, return false
#endif
	if (t0 > t1) std::swap(t0, t1);

	if (t0 < 0) {
		t0 = t1; // If t0 is negative, use t1 instead
		if (t0 < 0) return false; // If both t0 and t1 negative, return false
	}

	IsectInfo.t = t0;
	IsectInfo.PHit = ray.getOrigin() + ray.getDirection().scale(IsectInfo.t);
	IsectInfo.NHit = IsectInfo.PHit - getPosition();
	IsectInfo.NHit.normalize3D();


	return true;
}