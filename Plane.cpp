#include "Plane.h"
#include "Vector.h"
#include "Ray.h"
#include "Utility.h"

Plane::Plane() {

}

Plane::Plane(Vector plane) {
	m_plane = plane;
}

void Plane::setPlane(Vector plane) {
	m_plane = plane;
}

Vector Plane::getPlane() {
	return m_plane;
}

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