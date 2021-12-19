#include "Utility.h"
#include <math.h>
#include <utility>
#include <iostream>
#include <algorithm>

#define PI 3.14159265358979323846

float Utility::dot2D(Vector v1, Vector v2) {
	return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY());
}

float Utility::dot3D(Vector v1, Vector v2) {
	return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ());
}

float Utility::dot4D(Vector v1, Vector v2) {
	return (v1.getX() * v2.getX()) + (v1.getY() * v2.getY()) + (v1.getZ() * v2.getZ()) + (v1.getA() * v2.getA());
}

Vector Utility::cross3D(Vector v1, Vector v2) {
	float new_x = (v1.getY() * v2.getZ()) - (v1.getZ() * v2.getY());
	float new_y = -1 * ((v1.getX() * v2.getZ()) - (v1.getZ() * v2.getX()));
	float new_z = (v1.getX() * v2.getY()) - (v1.getY() * v2.getX());

	return Vector(new_x, new_y, new_z);
}

float Utility::toDegrees(float rad) {
	return (rad * 180.0f) / PI;
}

float Utility::toRadians(float deg) {
	return (deg * PI) / 180.0f;
}

float Utility::clamp(float value, float min, float max) {
	if (value < min) {
		value = min;
	}
	
	if (value > max) {
		value = max;
	}
	
	return value;

}

bool Utility::solveQuadratic(const float& a, const float& b, const float& c, float& x0, float& x1) {
	float discr = (b * b) - (4 * a * c);

	if (discr < 0) return false;
	else if (discr == 0) x0 = x1 = (-0.5f * b) / a;
	else { // discr > 0
		float q = (b > 0) ?
			-0.5f * (b + sqrtf(discr)) : // if b > 0 
			-0.5f * (b - sqrtf(discr)); // if b <= 0
		x0 = q / a;
		x1 = c / q;
	}
	if (x0 > x1) std::swap(x0, x1);

	return true;
}

Vector Utility::castReflectRay(Ray ray, std::vector<Light*>* lights, std::vector<Object*>* objects, int depth) {
	Vector view_dir = ray.getDirection();
	view_dir.normalize3D();
	Vector final_color = Vector();
	IntersectInfo IsectInfo;
	IsectInfo.t = 0;

	if (depth > ray.getMaxDepth()) return final_color;

	for (int i = 0; i < objects->size(); i++) {
		if (objects->at(i)->intersects(ray, IsectInfo)) {
			switch (objects->at(i)->getShadeType()) {
			case kPhong: {
				IntersectInfo LightIsectInfo;

				for (int l = 0; l < lights->size(); l++) {
					Ray light_ray = Ray(lights->at(l)->getPosition());
					Vector light_dir = IsectInfo.PHit - light_ray.getOrigin();
					light_dir.normalize3D();
					light_ray.setDirection(light_dir);
					Vector temp_color = lights->at(l)->getColor();
					//std::cout << "Light color: " << lights->at(i)->getColor().toString() << std::endl;
					Vector spec = Vector();
					Vector diff = Vector();
					Vector reflect = getReflectionDirection(IsectInfo.NHit, light_dir);
					reflect.normalize3D();

					if (objects->at(i)->intersects(Ray(lights->at(l)->getPosition(), IsectInfo.PHit - lights->at(l)->getPosition()), LightIsectInfo)) {
						diff = diffuse(IsectInfo.NHit, light_ray.getDirection(), lights->at(l)->getColor(), lights->at(l)->getIntensity());
						spec = specular(IsectInfo.NHit, light_ray.getDirection(), reflect,
							lights->at(l)->getIntensity(), objects->at(i)->getShininess(), view_dir);

						temp_color = (diff * objects->at(i)->getDiffuseValue()) + (spec * objects->at(i)->getSpecularValue());
						final_color += temp_color;

						//std::cout << "Light " << l << " Color: " << temp_color.toString() << std::endl;
						//std::cout << "New Color:" << final_color.toString() << std::endl;
					}
				}
				break;
			}
			case kReflect: {
				Vector reflectDir = getReflectionDirection(IsectInfo.NHit, ray.getDirection());
				Ray reflectRay = Ray(IsectInfo.PHit + IsectInfo.NHit, reflectDir);
				reflectRay.setMaxDepth(ray.getMaxDepth()); // make sure the new ray's max depth is the same as the starter!
				final_color += castReflectRay(reflectRay, lights, objects, depth + 1) * 0.8f;
				break;
			}
			default: {
				break;
			}
			}
		}
	}
	
	return final_color;
}

Vector Utility::blendColors(Vector color1, Vector color2, bool useA) {

	Vector temp_c1 = color1;
	//temp_c1.normalize3D();
	Vector temp_c2 = color2;
	//temp_c2.normalize3D();
	//std::cout << "Blending Colors: " << temp_c1.toString() << " and " << temp_c2.toString() << std::endl;
	
	Vector newColor = Vector((temp_c1.getX() + temp_c2.getX()) / 2.0f,
		(temp_c1.getY() + temp_c2.getY()) / 2.0f,
		(temp_c1.getZ() + temp_c2.getZ()) / 2.0f);
	if (useA) {
		float a = color1.getA() + color2.getA() * (1.0f - color1.getA());
		newColor.setA(a);
	}
	//std::cout << "New Color: " << newColor.toString() << std::endl;

	return newColor;
}

Vector Utility::getReflectionDirection(Vector surface_normal_hit, Vector light_direction) {
	Vector R = ((surface_normal_hit * dot3D(surface_normal_hit, light_direction)) * 2.0f) - light_direction;
	//R.normalize3D();
	//std::cout << R.toString() << std::endl;
	return R;
}

Vector Utility::diffuse(Vector surface_normal_hit, Vector light_direction, Vector light_color, float light_intensity) {
	float lambert_cos = dot3D(surface_normal_hit, -light_direction);
	if (lambert_cos < 0.0f) lambert_cos = 0.0f;
	if (lambert_cos > 1.0f) lambert_cos = 1.0f;
	//std::cout << "Lambert Cos: " << lambert_cos << std::endl;
	float diffuse = lambert_cos * light_intensity;
	return Vector(light_color.getX() * diffuse, light_color.getY() * diffuse, light_color.getZ() * diffuse);
}

Vector Utility::specular(Vector surface_normal_hit, Vector light_direction, Vector reflect_direction, float light_intensity, float shininess, Vector view_direction) {
	float specular = dot3D(view_direction, reflect_direction);
	specular = clamp(specular, 0.0f, 1.0f);
	//std::cout << specular << std::endl;
	float spec_with_shiny = std::powf(specular, shininess);
	spec_with_shiny *= light_intensity;
	if(spec_with_shiny < 0.0f) std::cout << spec_with_shiny << std::endl;
	return Vector(spec_with_shiny, spec_with_shiny, spec_with_shiny);
	//return Vector(specular, specular, specular);
}

Vector Utility::getRefractionDirection(Vector incidence_vector, Vector surface_normal_hit, float refract_index) {
	
	float cosi = clamp(dot3D(incidence_vector, surface_normal_hit), -1, 1);
	float etai = 1;
	float etat = refract_index;
	Vector n = surface_normal_hit;
	if (cosi < 0) { // not inside surface
		cosi = -cosi;
	}
	else { // inside surface
		std::swap(etai, etat);
		n = -surface_normal_hit;
	}

	float eta = etai / etat;

	float k = 1 - eta * eta * (1 - cosi * cosi);
	if (k < 0) {
		return Vector();
	}
	else {
		Vector return_val = (incidence_vector * eta) + n * (eta * cosi - sqrtf(k));
		return return_val;
	}
}