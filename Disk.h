#pragma once
#include "Plane.h"
#include "Vector.h"
#include "Ray.h"

class Disk :
    public Plane
{
private:
    float m_radius = 1; // radius of the disk - set to 1.0f by default

public:
    // Constructors
    Disk();
    Disk(float radius);
    Disk(float radius, Vector plane);

    // Setters
    void setRadius(float m_radius);

    // Getters
    float getRadius();

    // Intersection test
    bool intersectsDisk(Vector& n, Vector& p0, Vector& l0, Vector l, IntersectInfo& i);
};

