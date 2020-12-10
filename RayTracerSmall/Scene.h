#pragma once
#include "Vector3.h"
#include "Spheres.h"
#include <shared_mutex>

typedef Vec3<float> Vec3f;
typedef std::unique_ptr<Sphere> SpherePtr;
class Scene
{
public:
	static void BasicRender();
	static void SimpleShrinking();
	static void SmoothScaling();
	static void Animate();
	
	Vec3f Trace(const Vec3f& rayorig, const Vec3f& raydir, const int depth) const;
	void Render(int iteration) const;
	void RenderThreaded(int iteration, int numThreads) const;
	void AddSphere(const Vec3f& center, const float radius, const Vec3f& surfaceColor, const float reflection = 0, const float transparency = 0, const Vec3f& emissionColor = 0);
	void ClearSpheres();

	void Update(float timeElapsed);
	Sphere& GetSphere(int index) const;
	int GetSphereCount() const;

private:
	std::vector<SpherePtr> m_Spheres;

	void TracePixel(int x, int y, float invWidth, float invHeight, float angle, float aspectratio, Vec3f* pixel) const;
	void TraceRow(int y, float invWidth, float invHeight, float angle, float aspectratio, Vec3f* row, int width) const;

	// Read-write lock to protect m_Spheres
	mutable std::shared_mutex m_Mutex;
};

