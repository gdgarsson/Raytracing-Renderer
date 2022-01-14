#pragma once
#include <vector>
#include "Object.h"
#include "Vector.h"
#include "PPMImage.h"
#include "Ray.h"
#include "Light.h"
class Camera
{
private:
	Vector m_position = Vector(); // Position of the camera
	Vector m_forward = Vector(); // Forward direction of the camera
	float m_fov = 70; // Field of view

	int m_x_res; // X-resolution of the camera
	int m_y_res; // Y-resolution of the camera

	float t_near = 0.0f; // minimum distance needed to draw.
	float t_far = 1000.0f; // Maxmimum draw distance.

	PPMImage* m_img; // Image buffer pointer

public:
	// Constructors
	Camera();
	Camera(Vector position);
	Camera(Vector position, Vector forward);
	Camera(Vector position, float fov);
	Camera(Vector position, Vector forward, float fov);
	
	// Destructor
	~Camera();

	// Setters
	bool assignImage(int xres, int yres);
	bool assignImage(PPMImage* img);

	void setPosition(Vector position);
	void setForward(Vector forward);
	void setFOV(float new_fov);
	void setResolution(int xres, int yres);
	void setXResolution(int xres);
	void setYResolution(int yres);

	// Getters
	Vector getPosition();
	Vector getForward();
	float getFOV();
	int getXResolution();
	int getYResoltion();

	PPMImage* getImage();

	// Raycast function
	void castRays(std::vector<Object*> *objects, std::vector<Light*>* lights);
};

