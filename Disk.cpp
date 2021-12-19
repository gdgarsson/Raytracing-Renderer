#include "Disk.h"
#include "Utility.h"

Disk::Disk() {
	
}

Disk::Disk(float radius) {
	m_radius = radius;
}

Disk::Disk(float radius, Vector plane) {
	m_radius = radius;
	m_plane = plane;
}

void Disk::setRadius(float radius) {
	m_radius = radius;
}

float Disk::getRadius() {
	return m_radius;
}

bool Disk::intersectsDisk(Vector& n, Vector& p0, Vector& l0, Vector l, IntersectInfo& i) {
	i.t = 0;
	Utility util;
	if (intersectsPlane(n, p0, l0, l, i)) {
		Vector p = l0 + l * i.t;
		Vector v = p - p0;
		float d2 = util.dot3D(v, v);
		return (sqrtf(d2) <= m_radius);
	}

	return false;
}