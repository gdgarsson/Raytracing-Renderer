#pragma once
#include "Light.h"

class PointLight :
    public Light
{
private:
    //
public:
    PointLight();
    PointLight(Vector position);
    PointLight(Vector position, Vector color);
};

