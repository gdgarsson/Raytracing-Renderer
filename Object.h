#pragma once
#include "Vector.h"
#include "Ray.h"

enum ShadeType {
	kPhong = 0, // per fragment
	kGouraud = 1, // per vertex
	kReflect = 2 // reflective surface
};

class Object
{
protected:
	Vector m_position = Vector(); // Vector containing position, will replace with 4x4 matrix in the future
					   // Note: this is intended to be located at the CENTER of the objects, at least for now.

	Vector m_color = Vector(); // Object's Default Color Vector (set to black by default)
	float m_shininess = 20.0f; // The "n" shininess value associated with specular highlights. The larger the number, the more focused the highlight. Set to 20.0f by default
	ShadeType m_shade_type = kPhong; // Determines which type of shading this object uses, is Phong by default
	float m_Ks = 0.4f; // Specular material coefficient - set to 0.4f by default
	float m_Kd = 1.0f; // Diffuse material coefficient - set to 1.0f by default

public:
	// Constructors
	Object();
	Object(Vector position);
	Object(Vector position, Vector color);

	// Setters
	void setPosition(Vector new_position);
	void setColor(Vector new_color);
	void setShininess(float new_shininess);
	void setShadeType(ShadeType new_shade_type);
	void setSpecularValue(float new_Ks);
	void setDiffuseValue(float new_Kd);

	// Getters
	Vector getPosition();     // Returns the object's position in 3D space as a Vector.
	Vector getColor();        // Returns the object's RBGA color Vector.
	float getShininess();         // Returns the object's "n" spec value.
	ShadeType getShadeType(); // Returns the object's Shading Type (Phong or Gouraud).
	float getSpecularValue(); // Returns the object's Ks value.
	float getDiffuseValue();  // Returns the object's Kd value.

	// Virtual function for intersection tests
	virtual bool intersects(const Ray& ray, IntersectInfo& IsectInfo) = 0;
};