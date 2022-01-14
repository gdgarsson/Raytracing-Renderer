#include "Plane.h"
#include "Vector.h"
#include "Ray.h"
#include "Utility.h"

// Default Constructor
Plane::Plane() {

}

// Create a set of "plane data" along a specified 3D plane
Plane::Plane(Vector plane) {
	m_plane = plane;
}

// Setter: change the plane the "plane data" runs along
void Plane::setPlane(Vector plane) {
	m_plane = plane;
}

// Getter: get the the plane the "plane data" runs along
Vector Plane::getPlane() {
	return m_plane;
}

// Plane intersect test
bool Plane::intersectsPlane(Vector& n, Vector& p0, Vector& l0, Vector& l, IntersectInfo& i) {
	// assuming all vectors are normalized
	Utility util;
	float denominator = util.dot3D(n, l);
	if (denominator > 0.0f) {
		Vector p0l0 = p0 - l0;
		i.t = util.dot3D(p0l0, n) / denominator;
		return (i.t >= 0);
	}
	
	return false;
}