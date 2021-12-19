#pragma once
#include "Vector.h"
#include "Ray.h"
class Plane
{
protected:
	Vector m_plane = Vector();
	
public:
	Plane();
	Plane(Vector plane);

	void setPlane(Vector plane);
	
	Vector getPlane();

	bool intersectsPlane(Vector& n, Vector& p0, Vector& l0, Vector& l, IntersectInfo& i);
};

