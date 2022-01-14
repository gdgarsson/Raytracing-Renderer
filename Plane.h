#pragma once
#include "Vector.h"
#include "Ray.h"
class Plane
{
protected:
	Vector m_plane = Vector(); // defaults to (0,0,0)
	
public:
	// Constructors
	Plane();
	Plane(Vector plane);

	// Setters
	void setPlane(Vector plane);
	
	// Getters
	Vector getPlane();

	// Intersection test
	bool intersectsPlane(Vector& n, Vector& p0, Vector& l0, Vector& l, IntersectInfo& i);
};

