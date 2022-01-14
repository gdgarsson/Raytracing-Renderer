#include "Object.h"

// Default constructor
Object::Object() {

}

// Create an object at a given position
Object::Object(Vector position) {
	m_position = position;
}

// Create an object at a given position with a specified position
Object::Object(Vector position, Vector color) {
	m_position = position;
	m_color = color;
}

// Setter: set the object's position in space
void Object::setPosition(Vector new_position) {
	m_position = new_position;
}

// Setter: set the object's RGB color value
void Object::setColor(Vector new_color) {
	m_color = new_color;
}

// Setter: set the object's shininess value
void Object::setShininess(float new_shininess) {
	m_shininess = new_shininess;
}

// Setter: set which method is used to shade the object.
// Currently supported: kReflect (reflections), kPhong (default)
void Object::setShadeType(ShadeType new_shade_type) {
	m_shade_type = new_shade_type;
}

// Setter: set the object's specular value (used for specular lighting)
void Object::setSpecularValue(float new_Ks) {
	m_Ks = new_Ks;
}

// Setter: set the object's diffuse value (used for diffuse lighting)
void Object::setDiffuseValue(float new_Kd) {
	m_Kd = new_Kd;
}

// Getter: returns the object's position in space
Vector Object::getPosition() {
	return m_position;
}

// Getter: returns the RGB color value of the object
Vector Object::getColor() {
	return m_color;
}

// Getter: returns the shininess value of the object
float Object::getShininess() {
	return m_shininess;
}

// Getter: returns the enum which determines how the object is shaded
ShadeType Object::getShadeType() {
	return m_shade_type;
}

// Getter: returns the specular value (used for specular lighting)
float Object::getSpecularValue() {
	return m_Ks;
}

// Getter: returns the diffuse value (used for diffuse lighting)
float Object::getDiffuseValue() {
	return m_Kd;
}