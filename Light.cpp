#include "Light.h"

// Default Light constructor
Light::Light() {
	
}

// Create a White light at a given postion
Light::Light(Vector position) {
	m_position = position;
}

// Create a light of a specified color at a given position
Light::Light(Vector position, Vector color) {
	m_position = position;
	m_color = color;
}

// Setter: set the light's position in space
void Light::setPosition(Vector position) {
	m_position = position;
}

// Setter: set the light's RGB color
void Light::setColor(Vector color) {
	m_color = color;
}

// Setter: set how intense the light is - clamped between 0.0f and 1.0f
void Light::setIntensity(float intensity) {
	if (intensity > 1.0f) {
		intensity = 1.0f;
	}
	else if(intensity < 0.0f) {
		intensity = 0.0f;
	}
	m_light_intensity = intensity;
}

// Getters: get the light's position in space
Vector Light::getPosition() {
	return m_position;
}

// Getter: get the light's RGB color
Vector Light::getColor() {
	return m_color;
}

// Getter: get the light's intensity value
float Light::getIntensity() {
	return m_light_intensity;
}