#pragma once
#include "Light.h"

class PointLight :
    public Light
{
private:
    //
public:
    // Constructors
    PointLight();
    PointLight(Vector position);
    PointLight(Vector position, Vector color);
};

