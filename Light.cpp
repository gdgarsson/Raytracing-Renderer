#include "Light.h"

Light::Light() {
	m_position = Vector();
	m_color = Vector(1.0f, 1.0f, 1.0f);
}

Light::Light(Vector position) {
	m_position = position;
	m_color = Vector(1.0f, 1.0f, 1.0f);
}

Light::Light(Vector position, Vector color) {
	m_position = position;
	m_color = color;
}

void Light::setPosition(Vector position) {
	m_position = position;
}

void Light::setColor(Vector color) {
	m_color = color;
}

void Light::setIntensity(float intensity) {
	if (intensity > 1.0f) {
		intensity = 1.0f;
	}
	else if(intensity < 0.0f) {
		intensity = 0.0f;
	}
	m_light_intensity = intensity;
}

Vector Light::getPosition() {
	return m_position;
}

Vector Light::getColor() {
	return m_color;
}

float Light::getIntensity() {
	return m_light_intensity;
}