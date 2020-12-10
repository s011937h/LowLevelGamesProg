#pragma once
#include "Vector3.h"
#include "Spheres.h"

typedef Vec3<float> Vec3f;
typedef std::unique_ptr<Sphere> SpherePtr;
class Scene
{
public:
	static void BasicRender();
	static void SimpleShrinking();
	static void SmoothScaling();
	static void Animate();
	
	Vec3f Trace(const Vec3f& rayorig, const Vec3f& raydir, const int depth);
	void Render(int iteration);
	void AddSphere(const Vec3f& center, const float radius, const Vec3f& surfaceColor, const float reflection = 0, const float transparency = 0, const Vec3f& emissionColor = 0);
	void ClearSpheres();

	void Update(float timeElapsed);
	Sphere& GetSphere(int index);
	int GetSphereCount();

private:
	std::vector<SpherePtr> m_Spheres;

};

