#pragma once
#include "Object.h"
#include "Vector.h"
class Box : public Object
{
private:
	// Note: the Box will be drawn with half of the width and length sprouting from the sides of the position point. Height is undecided.
	//       This is done to simplify rotational purposes.

	Vector m_forward; // 3D "forward" vector

	float m_width = 1; // Width of box (along its x-axis)
	float m_length = 1; // Length of box (along its y-axis)
	float m_height = 1; // Height of box (along its z-axis)

	Vector m_bound_min;
	Vector m_bound_max;

public:
	Box();

	Box(float width, float length, Vector position);
	Box(float width, float length, Vector position, Vector forward);
	
	Box(float width, float length, float height, Vector position);
	Box(float width, float length, float height, Vector position, Vector forward);

	Box(Vector min_bound, Vector max_bound);
	Box(Vector min_bound, Vector max_bound, Vector position);

	// Setters
	void setWidth(float new_width);
	void setLength(float new_length);
	void setHeight(float new_height);

	void scaleX(float scalar);
	void scaleY(float scalar);
	void scaleZ(float scalar);

	void scaleXY(float scalar);
	void scaleXZ(float scalar);
	void scaleYZ(float scalar);

	void setBounds(Vector min, Vector max);

	void scale(float scalar);

	void setForward(Vector new_position);

	//Getters
	float getWidth();
	float getLength();
	float getHeight();
	Vector getForward();

	Vector getMinBound();
	Vector getMaxBound();

	bool intersects(const Ray& ray, IntersectInfo &t);
};

