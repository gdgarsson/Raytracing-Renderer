#pragma once
#include "Vector.h"
class Light
{
protected:
	Vector m_position = Vector(); // The current location in 3D space of the light - defaults to the origin
	Vector m_color = Vector(1.0f, 1.0f, 1.0f); // The color that the lights emits - defaults to White (1.0f, 1.0f, 1.0f)
	float m_light_intensity = 0.5f; // Value between 0 and 1 determining how intense the light is - defaults to 0.5f;
public:
	//Constructors
	Light();
	Light(Vector position);
	Light(Vector position, Vector color);

	// Setters
	void setPosition(Vector position);
	void setColor(Vector color);
	void setIntensity(float intensity);
	
	// Getters
	Vector getPosition();
	Vector getColor();
	float getIntensity();
};

