#include "PointLight.h"

// Default constructor
// Create a White point light at the origin
PointLight::PointLight() {
	setPosition(Vector());
	setColor(Vector(1.0f, 1.0f, 1.0f));
}

// Create a White point light at a given point in space
PointLight::PointLight(Vector position) {
	setPosition(position);
	setColor(Vector(1.0f, 1.0f, 1.0f));
}

// Create a point light of a specified color at a given point in space
PointLight::PointLight(Vector position, Vector color) {
	setPosition(position);
	setColor(color);
}