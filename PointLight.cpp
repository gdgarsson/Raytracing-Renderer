#include "PointLight.h"

PointLight::PointLight() {
	setPosition(Vector());
	setColor(Vector(1.0f, 1.0f, 1.0f));
}

PointLight::PointLight(Vector position) {
	setPosition(position);
	setColor(Vector(1.0f, 1.0f, 1.0f));
}

PointLight::PointLight(Vector position, Vector color) {
	setPosition(position);
	setColor(color);
}