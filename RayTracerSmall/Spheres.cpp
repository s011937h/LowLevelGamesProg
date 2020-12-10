#include "Spheres.h"

void* Sphere::operator new(size_t size)
{
	return GetMemoryManager().Allocate(size);
}

void Sphere::operator delete(void* p, size_t size)
{
	GetMemoryManager().Delete(p);
}

MemoryManager& Sphere::GetMemoryManager()
{
	static MemoryManager instance;
	return instance;
}

Sphere::Sphere(const Vec3f& center, const float radius, const Vec3f& surfaceColor, const float reflection, const float transparency, const Vec3f& emissionColor)
	: m_center(center), m_radius(radius), m_radius2(radius* radius), m_surfaceColor(surfaceColor), m_emissionColor(emissionColor),	m_transparency(transparency), reflection(reflection)
{
	m_velocity = Vec3f(0.0, 0.0, 0.0);
}

bool Sphere::intersect(const Vec3f& rayorig, const Vec3f& raydir, float& t0, float& t1) const
{
	Vec3f l = m_center - rayorig;
	float tca = l.dot(raydir);
	if (tca < 0) return false;
	float d2 = l.dot(l) - tca * tca;
	if (d2 > m_radius2) return false;
	float thc = sqrt(m_radius2 - d2);
	t0 = tca - thc;
	t1 = tca + thc;

	return true;
}


void Sphere::Update(float deltaTime)
{
	m_center += m_velocity * deltaTime;
}

void Sphere::SetVelocity(float x, float y, float z)
{
	SetVelocity(Vec3f(x, y, z));
}

void Sphere::SetVelocity(Vec3f velocity)
{
	m_velocity = velocity;
}