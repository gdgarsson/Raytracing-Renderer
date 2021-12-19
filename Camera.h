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
	float m_fov = 90; // Field of view

	int m_x_res;
	int m_y_res;

	float t_near = 0.0f;
	float t_far = 1000.0f;

	PPMImage* m_img;

public:
	Camera();
	Camera(Vector position);
	Camera(Vector position, Vector forward);
	Camera(Vector position, float fov);
	Camera(Vector position, Vector forward, float fov);
	
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

	Vector getPosition();
	Vector getForward();
	float getFOV();
	int getXResolution();
	int getYResoltion();

	PPMImage* getImage();
	void castRays(std::vector<Object*> *objects, std::vector<Light*>* lights);
};

