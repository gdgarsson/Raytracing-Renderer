#pragma once
#include "Vector.h"
class Light
{
protected:
	Vector m_position; // The current location in 3D space of the light
	Vector m_color; // The color that the lights emits
	float m_light_intensity; // Value between 0 and 1 determining how intense the light is.

public:
	Light();
	Light(Vector position);
	Light(Vector position, Vector color);

	void setPosition(Vector position);
	void setColor(Vector color);
	void setIntensity(float intensity);
	
	Vector getPosition();
	Vector getColor();
	float getIntensity();
};

