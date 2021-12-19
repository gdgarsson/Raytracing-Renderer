#pragma once
#include "Object.h"
#include "Vector.h"
class Sphere : public Object
{
private:
	float m_radius; // Radius of the Sphere
	Vector m_forward; // 3D "forward" vector of the sphere

	// going to need a rotation matrix at some point... I THINK.

public:
	Sphere();
	Sphere(Vector position);
	Sphere(Vector position, Vector color);
	Sphere(float radius, Vector position);
	Sphere(float radius, Vector position, Vector color);
	Sphere(float radius, Vector position, Vector color, Vector forward);

	void setRadius(float new_radius); // Set radius of sphere
	void setForward(Vector new_forward); // Set 3D "forward" vector fo the sphere (used for rotation)
	void scale(float scalar); // Scale the sphere by multiplying current radius by given value.

	float getRadius();
	Vector getForward();
	
	bool intersects(const Ray& ray, IntersectInfo& IsectInfo);
};

