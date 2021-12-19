#include "PPMImage.h"
#include <iostream>
#include <fstream>
#pragma once

PPMImage::PPMImage(int xres, int yres) {
	setXRes(xres);
	setYRes(yres);
	m_res_count = m_res_x * m_res_y * 3;
	m_color_buffer = new float[m_res_count];
	m_pos = Vector(0, 0, 0);
}

PPMImage::~PPMImage() {
	
	delete m_color_buffer;
}

void PPMImage::setXRes(int xres) {
	m_res_x = xres;
}

void PPMImage::setYRes(int yres) {
	m_res_y = yres;
}

void PPMImage::setColorScalar(int new_color_scalar) {
	m_color_scalar = new_color_scalar;
}

bool PPMImage::setImageType(std::string new_image_type) {
	if (new_image_type != "P1" && new_image_type != "P2" && new_image_type != "P3") {
		std::cout << "Image type must be one of: P1, P2, P3" << std::endl;
		return false;
	}
	else {
		m_img_type = new_image_type;
		return true;
	}
}

void PPMImage::setPosition(Vector pos) {
	m_pos = pos;
}

int PPMImage::getXRes() {
	return m_res_x;
}

int PPMImage::getYRes() {
	return m_res_y;
}

int PPMImage::getColorScalar() {
	return m_color_scalar;
}

float PPMImage::clamp(float val) {
	float temp = val;
	if (val < 0) temp = 0;
	else if (val > 1.0f) temp = 1.0f;
	return temp;
}

std::string PPMImage::getImageType() {
	return m_img_type;
}

Vector PPMImage::getPosition() {
	return m_pos;
}

void PPMImage::setPixelColor(int x, int y, float r, float g, float b) {
	// confine r,g,b to between 0,color scalar
	float temp_r = clamp(r) * getColorScalar();
	float temp_g = clamp(g) * getColorScalar();
	float temp_b = clamp(b) * getColorScalar();
	//std::cout << Vector(temp_r, temp_g, temp_b).toString() << std::endl;

	if (x < 0 || x > m_res_x || y < 0 || y > m_res_y) {
		std::cout << "Target pixel out of bounds." << std::endl;
		std::cout << "X Range: 0-" << m_res_x - 1 << std::endl;
		std::cout << "Y Range: 0-" << m_res_y - 1 << std::endl;
		std::cout << "Target pixel was: X: " << x << "   Y: " << y << std::endl;
		return; // out of range
	}

	int index = (x + (y * m_res_x)) * 3;
	m_color_buffer[index] = temp_r;
	m_color_buffer[index+1] = temp_g;
	m_color_buffer[index+2] = temp_b;

}

bool PPMImage::writeImage(std::string filename) {
	std::ofstream img;
	img.open(filename);

	if (!img.is_open()) {
		return false;
	}

	// place header info
	img << getImageType() << std::endl; // place file type
	img << getXRes() << " " << getYRes() << std::endl; // place width and height
	img << getColorScalar() << std::endl;

	// place pixels
	for (int i = 0; i < m_res_count; i++) {
		img << m_color_buffer[i] << " ";
		if (i % (m_res_x * 3) == 0) {
			img << std::endl;
		}
	}

	img.close();
}