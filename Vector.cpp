#include "Vector.h"
#include <iostream>
#include <string>
#include <cmath>

Vector::Vector() {
	m_x = 0.0f; // Vector X Coord
	m_y = 0.0f; // Vector Y Coord
	m_z = 0.0f; // Vector Z Coord
	m_a = 0.0f; // Additional Vector property for 4D Vectors (i.e. RGBA)
}

Vector::Vector(float x, float y) {
	m_x = x; // Vector X Coord
	m_y = y; // Vector Y Coord
	m_z = 0.0f; // Vector Z Coord
	m_a = 0.0f; // Additional Vector property for 4D Vectors (i.e. RGBA)
}

Vector::Vector(float x, float y, float z) {
	m_x = x; // Vector X Coord
	m_y = y; // Vector Y Coord
	m_z = z; // Vector Z Coord
	m_a = 0.0f; // Additional Vector property for 4D Vectors (i.e. RGBA)
}

Vector::Vector(float x, float y, float z, float a) {
	m_x = x; // Vector X Coord
	m_y = y; // Vector Y Coord
	m_z = z; // Vector Z Coord
	m_a = a; // Additional Vector property for 4D Vectors (i.e. RGBA)
}

Vector Vector::operator-() {
	return Vector(-this->m_x, -this->m_y, -this->m_z, -this->m_a);
}

Vector Vector::operator+(const Vector &v1) {
	return Vector(this->m_x + v1.m_x, this->m_y + v1.m_y, this->m_z + v1.m_z, this->m_a + v1.m_a);
}

Vector Vector::operator-(const Vector& v1) {
	return Vector(this->m_x - v1.m_x, this->m_y - v1.m_y, this->m_z - v1.m_z, this->m_a - v1.m_a);
}

Vector Vector::operator*(const float& f) {
	return Vector(this->m_x * f, this->m_y * f, this->m_z * f, this->m_a * f);
}

Vector Vector::operator+=(const Vector& v1) {
	m_x += v1.m_x;
	m_y += v1.m_y;
	m_z += v1.m_z;
	m_a += v1.m_a;
	return Vector(this->m_x, this->m_y, this->m_z, this->m_a);
}

Vector Vector::operator-=(const Vector& v1) {
	m_x -= v1.m_x;
	m_y -= v1.m_y;
	m_z -= v1.m_z;
	m_a -= v1.m_a;
	return Vector(this->m_x, this->m_y, this->m_z, this->m_a);
}

Vector Vector::operator*=(const float& f) {
	scale(f);
	return Vector(this->m_x, this->m_y, this->m_z, this->m_a);
}

bool Vector::operator==(const Vector& v1) {
	if (m_x == v1.m_x && m_y == v1.m_y && m_z == v1.m_z && m_a == v1.m_a) {
		return true;
	}
	else return false;
}

bool Vector::operator!=(const Vector& v1) {
	if (m_x != v1.m_x || m_y != v1.m_y || m_z != v1.m_z || m_a != v1.m_a) {
		return true;
	}
	else return false;
}

void Vector::setX(float x) {
	m_x = x;
}

void Vector::setY(float y) {
	m_y = y;
}

void Vector::setZ(float z) {
	m_z = z;
}

void Vector::setA(float a) {
	m_a = a;
}

Vector Vector::scale(float s) {
	m_x *= s;
	m_y *= s;
	m_z *= s;
	m_a *= s;
	return Vector(m_x, m_y, m_z, m_a);
}

float Vector::getX() {
	return m_x;
}

float Vector::getY() {
	return m_y;
}

float Vector::getZ() {
	return m_z;
}

float Vector::getA() {
	return m_a;
}

float Vector::pythagorean2D() {
	return sqrtf(powf(m_x, 2.0f) + powf(m_y, 2.0f));
}

float Vector::pythagorean3D() {
	return sqrtf(powf(m_x, 2.0f) + powf(m_y, 2.0f) + powf(m_z, 2.0f));
}

void Vector::normalize2D() {
	float length = pythagorean2D();
	if (length != 0.0f) { // If the length is 0, its already normalized. No need to change things.
		m_x = m_x / length;
		m_y = m_y / length;
	}
}

void Vector::normalize3D() {
	//std::cout << "X: " << m_x << std::endl;
	//std::cout << "Y: " << m_y << std::endl;
	//std::cout << "Z: " << m_z << std::endl;
	float length = pythagorean3D();
	if (length != 0.0f) { // If the length is 0, its already normalized. No need to change things.
		m_x = m_x / length;
		m_y = m_y / length;
		m_z = m_z / length;
	}
	
}

std::string Vector::toString() {
	std::string a = "(X: " + std::to_string(m_x) + ", Y: " + std::to_string(m_y) + ", Z: " + std::to_string(m_z) + ", A: " + std::to_string(m_a) + ")";
	return a;
}