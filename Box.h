#pragma once
#include "Object.h"
#include "Vector.h"
class Box : public Object
{
private:
	// Note: the Box will be drawn with half of the width and length sprouting from the sides of the position point. Height is undecided.
	//       This is done to simplify rotational purposes.

	Vector m_forward = Vector(); // 3D "forward" vector - currently unused.

	float m_width = 1.0f; // Width of box (along its x-axis) - defaults to 1.0f
	float m_length = 1.0f; // Length of box (along its y-axis) - defaults to 1.0f
	float m_height = 1.0f; // Height of box (along its z-axis) - defaults to 1.0f
	
	Vector m_bound_min; // mininum boundary field - currently unused
	Vector m_bound_max; // maximum boundary field - currently unused

public:
	Box();

	Box(float width, float length, Vector position); 	
	Box(float width, float length, Vector position, Vector forward);
	
	Box(float width, float length, float height, Vector position);
	Box(float width, float length, float height, Vector position, Vector forward);
	
	// Unused constructors
	Box(Vector min_bound, Vector max_bound); 
	Box(Vector min_bound, Vector max_bound, Vector position); 

	// Setters
	void setWidth(float new_width);
	void setLength(float new_length);
	void setHeight(float new_height);

	void scaleWidth(float scalar);
	void scaleLength(float scalar);
	void scaleHeight(float scalar);

	void scale(float scalar);

	void setBounds(Vector min, Vector max);

	void setForward(Vector new_forward);

	//Getters
	float getWidth();
	float getLength();
	float getHeight();
	Vector getForward();

	Vector getMinBound();
	Vector getMaxBound();

	// Intersection test
	bool intersects(const Ray& ray, IntersectInfo &t);
};

