#include "Object.h"

Object::Object() {

}

Object::Object(Vector position) {
	m_position = position;
}

Object::Object(Vector position, Vector color) {
	m_position = position;
	m_color = color;
}

void Object::setPosition(Vector new_position) {
	m_position = new_position;
}

void Object::setColor(Vector new_color) {
	m_color = new_color;
}

void Object::setShininess(float new_shininess) {
	m_shininess = new_shininess;
}

void Object::setShadeType(ShadeType new_shade_type) {
	m_shade_type = new_shade_type;
}

void Object::setSpecularValue(float new_Ks) {
	m_Ks = new_Ks;
}

void Object::setDiffuseValue(float new_Kd) {
	m_Kd = new_Kd;
}

Vector Object::getPosition() {
	return m_position;
}

Vector Object::getColor() {
	return m_color;
}

float Object::getShininess() {
	return m_shininess;
}

ShadeType Object::getShadeType() {
	return m_shade_type;
}

float Object::getSpecularValue() {
	return m_Ks;
}

float Object::getDiffuseValue() {
	return m_Kd;
}

// not yet implemented
/*bool Object::intersects(const Ray& ray, float& t) {
	return false;
}*/