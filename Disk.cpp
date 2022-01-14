#include "Disk.h"
#include "Utility.h"

// Default constructor
Disk::Disk() {
	
}

// Create a disk with a given radius
Disk::Disk(float radius) {
	m_radius = radius;
}

// Create a disk along a specified plane with a given radius
Disk::Disk(float radius, Vector plane) {
	m_radius = radius;
	m_plane = plane;
}

// Setter: sets the radius of the disk
void Disk::setRadius(float radius) {
	m_radius = radius;
}

// Getter: gets the radius of the disk
float Disk::getRadius() {
	return m_radius;
}

// Intersection test for the plane
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