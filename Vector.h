#pragma once
#include <string>

class Vector
{
private:
	float m_x = 0.0f; // Vector X Coord - defaults to 0.0f
	float m_y = 0.0f; // Vector Y Coord - defaults to 0.0f
	float m_z = 0.0f; // Vector Z Coord - defaults to 0.0f
	float m_a = 0.0f; // Additional Vector property for 4D Vectors (i.e. RGBA) - defaults to 0.0f

public:
	Vector(); // Constructor
	Vector(float x, float y); // 2D Constructor
	Vector(float x, float y, float z); // 3D Constructor
	Vector(float x, float y, float z, float a); // 4D/Color Constructor

	Vector operator-();

	Vector operator+(Vector const &);
	Vector operator-(Vector const &);

	Vector operator*(float const&);

	Vector operator+=(Vector const &);
	Vector operator-=(Vector const &);

	Vector operator*=(float const&);

	bool operator==(Vector const&);
	bool operator!=(Vector const&);

	// Setters
	void setX(float x);
	void setY(float y);
	void setZ(float z);
	void setA(float a);

	Vector scale(float s); // multiply each value by s, return new values

	// Getters
	float getX();
	float getY();
	float getZ();
	float getA();

	float pythagorean2D(); // Return the result of the applying the Pythagorean Theorem to the X and Y coords
	float pythagorean3D(); // Return the result of the applying the Pythagorean Theorem to the X, Y, and Z coords

	// Normalizers
	void normalize2D();
	void normalize3D();

	// Prints out the Vector's info as a string
	std::string toString();
};

