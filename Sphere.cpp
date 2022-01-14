#include "Sphere.h"
#include <math.h>
#include <utility>
#include <iostream>
#include "Utility.h"

// Default constructor - creates a Black sphere with radius 1.0f at the origin
Sphere::Sphere() {
	setPosition(Vector());
	setColor(Vector());
}

// Create a Black sphere with radius 1.0f at a specified point in space
Sphere::Sphere(Vector position) {
	setPosition(position);
	setColor(Vector());
}

// Create a sphere of a specified color with radius 1.0f at a specified point in space
Sphere::Sphere(Vector position, Vector color) {
	setPosition(position);
	setColor(color);
}

// Create a Black sphere with a given radius at a specified point in space
Sphere::Sphere(float radius, Vector position) {
	setPosition(position);
	m_radius = radius;
	setColor(Vector());
}

// Create a colored sphere with a given radius at a specific point in space
Sphere::Sphere(float radius, Vector position, Vector color) {
	setPosition(position);
	m_radius = radius;
	setColor(color);
}

// Create a colored sphere with a given radius at a specific point in space, facing in a particular direction
Sphere::Sphere(float radius, Vector position, Vector color, Vector forward) {
	setPosition(position);
	m_radius = radius;
	m_forward = forward;
	setColor(color);
}

// Setter: set the radius of the sphere
void Sphere::setRadius(float new_radius) {
	m_radius = new_radius;
}

// Setter: set the forward direction of the sphere
void Sphere::setForward(Vector new_forward) {
	m_forward = new_forward;
}

// Setter: multiplies the sphere's radius by a given amount
void Sphere::scale(float scalar) {
	m_radius *= scalar;
}

// Getter: get's the sphere's radius
float Sphere::getRadius() {
	return m_radius;
}

// Getter: get's the sphere's forward direction
Vector Sphere::getForward() {
	return m_forward;
}

// Sphere intersection test - returns true if a given ray intersects the sphere
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
	// Algebraic solution
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