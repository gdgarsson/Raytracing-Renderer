#pragma once
#include "Object.h"
#include "Vector.h"
class Sphere : public Object
{
private:
	float m_radius = 1.0f; // Radius of the Sphere - defaults to 1.0f
	Vector m_forward = Vector(); // 3D "forward" vector of the sphere - defaults to (0,0,0)

	// going to need a rotation matrix at some point... I THINK.

public:
	// Constructors
	Sphere();
	Sphere(Vector position);
	Sphere(Vector position, Vector color);
	Sphere(float radius, Vector position);
	Sphere(float radius, Vector position, Vector color);
	Sphere(float radius, Vector position, Vector color, Vector forward);

	// Setters
	void setRadius(float new_radius); // Set radius of sphere
	void setForward(Vector new_forward); // Set 3D "forward" vector fo the sphere (used for rotation)
	void scale(float scalar); // Scale the sphere by multiplying current radius by given value.

	// Getters
	float getRadius();
	Vector getForward();
	
	// Sphere intersection test
	bool intersects(const Ray& ray, IntersectInfo& IsectInfo);
};

