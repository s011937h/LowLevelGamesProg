#pragma once
#include "MemoryManager.h"
#include "Vector3.h"
#include "Helpers.h"
#include <stdlib.h>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>
// Windows only
#include <algorithm>
#include <sstream>
#include <string.h>
#include <chrono>

#if defined __linux__ || defined __APPLE__
// "Compiled for Linux
#else
// Windows doesn't define these values by default, Linux does
#define M_PI 3.141592653589793
#define INFINITY 1e8
#endif

class Sphere
{
typedef Vec3<float> Vec3f;
public:
	static void* operator new(size_t size);
	static void* operator new(size_t size, const char* file, int line);
	static void operator delete(void* p, size_t size);
	static MemoryManager& GetMemoryManager();

	//TODO: Make all these private & add getters and setters for them and make code use getters and setters (all getters const)
	Vec3f m_center;                           /// position of the sphere
	float m_radius, m_radius2;                  /// sphere radius and radius^2
	Vec3f m_surfaceColor, m_emissionColor;      /// surface color and emission (light)
	float m_transparency, reflection;         /// surface transparency and reflectivity
	Vec3f m_velocity;

	Sphere(const Vec3f& center, const float radius, const Vec3f& surfaceColor, const float reflection = 0, const float transparency = 0, const Vec3f& emissionColor = 0);

	bool intersect(const Vec3f& rayorig, const Vec3f& raydir, float& t0, float& t1) const;

	void Update(float deltaTime);
	void SetVelocity(Vec3f velocity);
	void SetVelocity(float x, float y, float z);
	void SetColour();
};

