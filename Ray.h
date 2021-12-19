#pragma once
#include "Vector.h"
class Ray
{
private:
	Vector m_origin; // Origin point of the ray
	Vector m_direction; // Direction of the ray

	Vector m_direction_inverse; // Inverse direction of the ray

	int m_max_depth = 5; // max # of times a ray can reflect

	int m_signx, m_signy, m_signz;
	
	void setInverse(); // Helper function: call ONLY inside setDirection

public:
	Ray(); // Constructor (both Vectors at (0,0,0))
	Ray(Vector origin); // Constructor (Heading at (0,0,0) from origin)
	Ray(Vector origin, Vector dir);

	void setOrigin(float x, float y, float z);
	void setOrigin(Vector new_origin);
	void setDirection(float x, float y, float z);
	void setDirection(Vector new_direction);
	void setMaxDepth(int new_max_depth);
	
	Vector getOrigin() const;
	Vector getDirection() const;
	Vector getInverseDirection() const;
	
	int getSignX();
	int getSignY();
	int getSignZ();

	int getMaxDepth();
};

struct IntersectInfo {
	float t = 0;
	Vector PHit = Vector();
	Vector NHit = Vector();
};