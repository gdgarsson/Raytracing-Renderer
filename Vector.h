#pragma once
#include <string>

class Vector
{
private:
	float m_x = 0; // Vector X Coord
	float m_y = 0; // Vector Y Coord
	float m_z = 0; // Vector Z Coord
	float m_a = 0; // Additional Vector property for 4D Vectors (i.e. RGBA)

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

	void normalize2D();
	void normalize3D();

	std::string toString();
};

