#pragma once
#include <string>
#include "Vector.h"

class PPMImage
{
private:
	int m_res_x = 4; // X Resolution (in pixels), set to 4 by default
	int m_res_y = 4; // Y Resolution (in pixels), set to 4 by default
	std::string m_img_type = "P3"; // Can either be P1, P2, or P3, set to P3 by default
	int m_color_scalar = 255; // Color scale value (set to 255 by default)
	float* m_color_buffer; // Color pointers.

	Vector m_pos = Vector(0, 0, 0);

	int m_res_count = m_res_x * m_res_y * 3;

	float clamp(float val);
public:
	PPMImage(int xres, int yres); // constructor
	~PPMImage(); // Destructor (to free memory)

	// Setters
	void setXRes(int xres);
	void setYRes(int yres);
	void setColorScalar(int new_color_scalar);
	bool setImageType(std::string new_image_type);
	void setPosition(Vector pos);
	
	// Getters
	int getXRes();
	int getYRes();
	int getColorScalar();
	std::string getImageType();
	Vector getPosition();

	bool writeImage(std::string filename); // Write to image file with specified file name
	
	void setPixelColor(int x, int y, float r, float g, float b);
};

