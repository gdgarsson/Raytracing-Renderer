#include "Camera.h"
#include <iostream>
#include <Windows.h>
#include <math.h>
#include "Utility.h"
#include "Sphere.h"
#include "Light.h"
#include "PointLight.h"

Camera::Camera() {
	m_position = Vector(0, 0, 4);
	m_forward = Vector();
	m_fov = 90;
}

Camera::Camera(Vector position) {
	m_position = position;
	m_forward = Vector();
	m_fov = 90;
}

Camera::Camera(Vector position, Vector forward) {
	m_position = position;
	m_forward = forward;
	m_fov = 90;
}

Camera::Camera(Vector position, float fov) {
	m_position = position;
	m_forward = Vector();
	m_fov = fov;
}


Camera::Camera(Vector position, Vector forward, float fov) {
	m_position = position;
	m_forward = forward;
	m_fov = fov;
}

Camera::~Camera() {
	if(m_img) delete m_img;
}

bool Camera::assignImage(int xres, int yres) {
	if (m_img) return false;

	m_img = new PPMImage(xres, yres);
	m_x_res = m_img->getXRes();
	m_y_res = m_img->getYRes();
	return true;
}

bool Camera::assignImage(PPMImage* img) {
	m_img = img;

	m_x_res = m_img->getXRes();
	m_y_res = m_img->getYRes();
	return true;
}

void Camera::setPosition(Vector new_position) {
	m_position = new_position;
}

void Camera::setForward(Vector new_forward) {
	m_forward = new_forward;
}

void Camera::setFOV(float new_fov) {
	m_fov = new_fov;
}

void Camera::setResolution(int xres, int yres) {
	m_x_res = xres;
	m_y_res = yres;
}

void Camera::setXResolution(int xres) {
	m_x_res = xres;
}

void Camera::setYResolution(int yres) {
	m_y_res = yres;
}
Vector Camera::getPosition() {
	return m_position;
}

Vector Camera::getForward() {
	return m_forward;
}

float Camera::getFOV() {
	return m_fov;
}

PPMImage* Camera::getImage() {
	return m_img;
}

int Camera::getXResolution() {
	return m_x_res;
}

int Camera::getYResoltion() {
	return m_y_res;
}

void Camera::castRays(std::vector<Object*>* objects, std::vector<Light*>* lights) {
	float angleStep = m_fov / static_cast<float>(m_x_res); // Determine # steps across x-axis. Is XFOV / XRes

	float yFov = (static_cast<float>(m_y_res) / static_cast<float>(m_x_res)) * static_cast<float>(m_fov); // the y-angle FOV of the camera
	float yAngleStep = yFov / static_cast<float>(m_y_res); // Determine # steps across y-axis. Is YFOV / YRes

	Ray ray = Ray(m_position); // Create new ray
	Vector rayDir = Vector(); // create temporary directional vector
	
	rayDir.setZ(-1.0f); // Set Z direction to look down -1.0

	for (int yPixel = 0; yPixel <= m_y_res; yPixel++) {
		Utility util;

		float yTan = tan(util.toRadians((-yFov / 2.0f) + (yPixel * yAngleStep)));
		rayDir.setY(yTan);

		for (int xPixel = 0; xPixel <= m_x_res; xPixel++) {
			float xTan = tan(util.toRadians((-m_fov / 2.0f) + (xPixel * angleStep)));
			rayDir.setX(xTan);

			ray.setDirection(rayDir);
			Vector view_dir = rayDir; // making a copy so I don't mess anything major up just in case
			view_dir.normalize3D();

			float draw_t = t_far;

			IntersectInfo IsectInfo;
			IsectInfo.t = 0.0f;

			for (int i = 0; i < objects->size(); i++) {
				if (objects->at(i)->intersects(ray, IsectInfo)) {
					IntersectInfo LightIsectInfo;
					Vector final_color = Vector();

					switch (objects->at(i)->getShadeType()) {
					case kPhong: {
						for (int l = 0; l < lights->size(); l++) {
							Ray light_ray = Ray(lights->at(l)->getPosition());
							Vector light_dir = IsectInfo.PHit - light_ray.getOrigin();
							light_dir.normalize3D();
							light_ray.setDirection(light_dir);
							Vector temp_color = lights->at(l)->getColor();
							//std::cout << "Light color: " << lights->at(i)->getColor().toString() << std::endl;
							Vector specular = Vector();
							Vector diffuse = Vector();
							Vector reflect = util.getReflectionDirection(IsectInfo.NHit, light_dir);
							reflect.normalize3D();


							if (objects->at(i)->intersects(Ray(lights->at(l)->getPosition(), IsectInfo.PHit - lights->at(l)->getPosition()), LightIsectInfo)) {
								diffuse = util.diffuse(IsectInfo.NHit, light_ray.getDirection(), lights->at(l)->getColor(), lights->at(l)->getIntensity());
								specular = util.specular(IsectInfo.NHit, light_ray.getDirection(), reflect,
									lights->at(l)->getIntensity(), objects->at(i)->getShininess(), view_dir);

								temp_color = (diffuse * objects->at(i)->getDiffuseValue()) + (specular * objects->at(i)->getSpecularValue());
								final_color = final_color + temp_color;

								//std::cout << "Light " << l << " Color: " << temp_color.toString() << std::endl;
								//std::cout << "New Color:" << final_color.toString() << std::endl;
							}
						}

						break;
					}
					case kReflect: {
						Vector reflectDir = util.getReflectionDirection(IsectInfo.NHit, rayDir);
						Ray reflectRay = Ray(IsectInfo.PHit + IsectInfo.NHit, reflectDir);
						final_color += util.castReflectRay(reflectRay, lights, objects, 0) * 0.8f;

						break;
					}
						
					default: {
						break;

					}
					}

					//std::cout << "Final Color:" << final_color.toString() << std::endl;
					if (IsectInfo.t < draw_t) {
						m_img->setPixelColor(xPixel, m_y_res - yPixel, final_color.getX(), final_color.getY(), final_color.getZ());
						draw_t = IsectInfo.t;
					}
					

				}
			}

			//std::cout << "Ray sent from camera in heading (" << ray.getDirection().getX() << ", " << ray.getDirection().getY() << ", " << ray.getDirection().getZ() << ")" << std::endl;

		}
	}

	/*while (!lights->empty()) {
		Light* temp = lights->back();
		lights->pop_back();
		delete temp;
	}
	delete lights;*/
}