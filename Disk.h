#pragma once
#include "Plane.h"
#include "Vector.h"
#include "Ray.h"

class Disk :
    public Plane
{
private:
    float m_radius = 1;

public:
    Disk();
    Disk(float radius);
    Disk(float radius, Vector plane);

    void setRadius(float m_radius);

    float getRadius();

    bool intersectsDisk(Vector& n, Vector& p0, Vector& l0, Vector l, IntersectInfo& i);
};

