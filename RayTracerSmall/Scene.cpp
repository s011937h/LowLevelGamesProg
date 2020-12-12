#include "Scene.h"


void Scene::BasicRender()
{
	Scene scene;
	// Vector structure for Sphere (position, radius, surface color, reflectivity, transparency, emission color)

	scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
	scene.AddSphere(Vec3f(0.0f, 0, -20), 4, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // The radius paramter is the value we will change
	scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
	scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);

	// This creates a file, titled 1.ppm in the current working directory
	scene.Render(1);

}

void Scene::SimpleShrinking()
{
	Scene scene;
	// Vector structure for Sphere (position, radius, surface color, reflectivity, transparency, emission color)

	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
			scene.AddSphere(Vec3f(0.0f, 0, -20), 4, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // The radius paramter is the value we will change
			scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
			scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);

		}
		else if (i == 1)
		{
			scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
			scene.AddSphere(Vec3f(0.0f, 0, -20), 3, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // Radius--
			scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
			scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);
		}
		else if (i == 2)
		{
			scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
			scene.AddSphere(Vec3f(0.0f, 0, -20), 2, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // Radius--
			scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
			scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);
		}
		else if (i == 3)
		{
			scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
			scene.AddSphere(Vec3f(0.0f, 0, -20), 1, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // Radius--
			scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
			scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);
		}

		scene.Render(i);
		// Dont forget to clear the Vector holding the spheres.
		scene.ClearSpheres();
	}
}

void Scene::SmoothScaling()
{
	Scene scene;
	// Vector structure for Sphere (position, radius, surface color, reflectivity, transparency, emission color)

	for (float r = 0; r <= 100; r++)
	{
		scene.AddSphere(Vec3f(0.0f, -10004, -20), 10000, Vec3f(0.20f, 0.20f, 0.20f), 0, 0.0f);
		scene.AddSphere(Vec3f(0.0f, 0, -20), r / 100, Vec3f(1.00f, 0.32f, 0.36f), 1, 0.5f); // Radius++ change here
		scene.AddSphere(Vec3f(5.0f, -1, -15), 2, Vec3f(0.90f, 0.76f, 0.46f), 1, 0.0f);
		scene.AddSphere(Vec3f(5.0f, 0, -25), 3, Vec3f(0.65f, 0.77f, 0.97f), 1, 0.0f);
		scene.Render(r);
		std::cout << "Rendered and saved spheres" << r << ".ppm" << std::endl;
		// Dont forget to clear the Vector holding the spheres.
		scene.ClearSpheres();

	}
}

/*******************************************************************************************
MARKING SCHEME: Expansion of framework

DESCRIPTION: Animate the spheres on the x, y and z axis continually..., an appropriate interface for setting up animations

*******************************************************************************************/
void Scene::Animate()
{
	Scene scene;
	const float framesPerSecond = 30.0f; //will be in xml later maybe
	const int totalFrames = 60;

	scene.AddSphere(Vec3f(0.0f, 0, -15), 2, Vec3f(1.0f, 0.82f, 0.863f), 1, 0.0f);
	scene.GetSphere(0).SetVelocity(1.0f, 1.0f, 1.0f);
	for (int frame = 0; frame < totalFrames; frame++)
	{
		float currentTime = frame * framesPerSecond;
		float elapsedTimePerFrame = 1.0f / framesPerSecond;

		scene.Update(elapsedTimePerFrame);
		scene.RenderThreaded(frame, 4); //experiment with number of threads
		//scene.Render(frame);
	}

	scene.ClearSpheres();
}

Vec3f Scene::Trace(const Vec3f& rayorig, const Vec3f& raydir, const int depth) const
{
	std::shared_lock<std::shared_mutex> lock(m_Mutex);

	//if (raydir.length() != 1) std::cerr << "Error " << raydir << std::endl;
	float tnear = INFINITY;
	const Sphere* sphere = NULL;
	// find intersection of this ray with the sphere in the scene
	for (unsigned i = 0; i < m_Spheres.size(); ++i) {
		float t0 = INFINITY, t1 = INFINITY;
		if (m_Spheres[i]->intersect(rayorig, raydir, t0, t1)) {
			if (t0 < 0) t0 = t1;
			if (t0 < tnear) {
				tnear = t0;
				sphere = m_Spheres[i].get();
			}
		}
	}
	// if there's no intersection return black or background color
	if (!sphere) return Vec3f(2);
	Vec3f surfaceColor = 0; // color of the ray/surfaceof the object intersected by the ray
	Vec3f phit = rayorig + raydir * tnear; // point of intersection
	Vec3f nhit = phit - sphere->m_center; // normal at the intersection point
	nhit.normalize(); // normalize normal direction
					  // If the normal and the view direction are not opposite to each other
					  // reverse the normal direction. That also means we are inside the sphere so set
					  // the inside bool to true. Finally reverse the sign of IdotN which we want
					  // positive.
	float bias = 1e-4; // add some bias to the point from which we will be tracing
	bool inside = false;
	if (raydir.dot(nhit) > 0) nhit = -nhit, inside = true;
	if ((sphere->m_transparency > 0 || sphere->reflection > 0) && depth < MAX_RAY_DEPTH) {
		float facingratio = -raydir.dot(nhit);
		// change the mix value to tweak the effect
		float fresneleffect = Helpers::mix(pow(1 - facingratio, 3), 1, 0.1f);
		// compute reflection direction (not need to normalize because all vectors
		// are already normalized)
		Vec3f refldir = raydir - nhit * 2 * raydir.dot(nhit);
		refldir.normalize();
		Vec3f reflection = Trace(phit + nhit * bias, refldir, depth + 1);
		Vec3f refraction = 0;
		// if the sphere is also transparent compute refraction ray (transmission)
		if (sphere->m_transparency) {
			float ior = 1.1f, eta = (inside) ? ior : 1 / ior; // are we inside or outside the surface?
			float cosi = -nhit.dot(raydir);
			float k = 1 - eta * eta * (1 - cosi * cosi);
			Vec3f refrdir = raydir * eta + nhit * (eta * cosi - sqrt(k));
			refrdir.normalize();
			refraction = Trace(phit - nhit * bias, refrdir, depth + 1);
		}
		// the result is a mix of reflection and refraction (if the sphere is transparent)
		surfaceColor = (
			reflection * fresneleffect +
			refraction * (1 - fresneleffect) * sphere->m_transparency) * sphere->m_surfaceColor;
	}
	else {
		// it's a diffuse object, no need to raytrace any further
		for (unsigned i = 0; i < m_Spheres.size(); ++i) {
			if (m_Spheres[i]->m_emissionColor.x > 0) {
				// this is a light
				Vec3f transmission = 1;
				Vec3f lightDirection = m_Spheres[i]->m_center - phit;
				lightDirection.normalize();
				for (unsigned j = 0; j < m_Spheres.size(); ++j) {
					if (i != j) {
						float t0, t1;
						if (m_Spheres[j]->intersect(phit + nhit * bias, lightDirection, t0, t1)) {
							transmission = 0;
							break;
						}
					}
				}
				surfaceColor += sphere->m_surfaceColor * transmission *
					std::max(float(0), nhit.dot(lightDirection)) * m_Spheres[i]->m_emissionColor;
			}
		}
	}

	return surfaceColor + sphere->m_emissionColor;
}

//[comment]
// Main rendering function. We compute a camera ray for each pixel of the image
// trace it and return a color. If the ray hits a sphere, we return the color of the
// sphere at the intersection point, else we return the background color.
//[/comment]
void Scene::Render(int iteration) const
{
	std::shared_lock<std::shared_mutex> lock(m_Mutex);

	// quick and dirty
	unsigned width = 640, height = 480;
	// Recommended Testing Resolution
	//unsigned width = 640, height = 480;

	// Recommended Production Resolution
	//unsigned width = 1920, height = 1080;
	Vec3f* image = NEW Vec3f[width * height], * pixel = image;
	float invWidth = 1 / float(width), invHeight = 1 / float(height);
	float fov = 30, aspectratio = width / float(height);
	float angle = tan(M_PI * 0.5f * fov / 180.0f);
	// Trace rays
	for (unsigned y = 0; y < height; ++y, pixel+=width) {
		TraceRow(y, invWidth, invHeight, angle, aspectratio, pixel, width);
	}
	// Save result to a PPM image (keep these flags if you compile under Windows)
	std::stringstream ss;
	ss << "./spheres" << iteration << ".ppm";
	std::string tempString = ss.str();
	char* filename = (char*)tempString.c_str();

	std::ofstream ofs(filename, std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	for (unsigned i = 0; i < width * height; ++i) {
		ofs << (unsigned char)(std::min(float(1), image[i].x) * 255) <<
			(unsigned char)(std::min(float(1), image[i].y) * 255) <<
			(unsigned char)(std::min(float(1), image[i].z) * 255);
	}
	ofs.close();
	delete[] image;
}

/*******************************************************************************************
MARKING SCHEME: Optimisation of the framework

DESCRIPTION: Threading optimisation, FileIO optimisation

*******************************************************************************************/
void Scene::RenderThreaded(int iteration, int numThreads) const
{
	std::shared_lock<std::shared_mutex> lock(m_Mutex);
	
	// quick and dirty
	unsigned width = 640, height = 480;
	// Recommended Testing Resolution
	//unsigned width = 640, height = 480;

	// Recommended Production Resolution
	//unsigned width = 1920, height = 1080;
	Vec3f* image = NEW Vec3f[width * height];
	float invWidth = 1 / float(width), invHeight = 1 / float(height);
	float fov = 30.0f;
	float aspectratio = width / float(height);
	float angle = tan(M_PI * 0.5f * fov / 180.0f);

	int rowsPerThread = height / numThreads;

	// Trace rays
	std::vector<std::thread> workerThreads;
	//dispatch workers
	Vec3f* threadStartRow = image;
	//for (unsigned y = 0; y < height; ++y, threadStartRow += width * rowsPerThread) 
	for (int thread = 0; thread < numThreads; ++thread, threadStartRow += width * rowsPerThread)
	{
		workerThreads.push_back(std::thread([this, thread, invWidth, invHeight, angle, aspectratio, threadStartRow, width, height, rowsPerThread]()
		{
			Vec3f* row = threadStartRow;
			for (int y = thread * rowsPerThread;
				y < height && y < (thread + 1) * rowsPerThread;
				++y, row += width) {
				TraceRow(y, invWidth, invHeight, angle, aspectratio, row, width);
			}
		}));
	}

	// join workers
	for (auto& thread : workerThreads)
	{
		thread.join();
	}

	std::vector<std::thread> ppmWorkerThreads;
	ppmWorkerThreads.push_back(std::thread([this, iteration, width, height, image]()
	{
		SaveToPPM(iteration, width, height, image);
	}));
	for (auto& thread : ppmWorkerThreads)
	{
		thread.join();
	}
}

void Scene::SaveToPPM(int iteration, int width, int height, Vec3f* image) const
{
	// Save result to a PPM image (keep these flags if you compile under Windows)
	std::stringstream ss;
	ss << "./spheres" << iteration << ".ppm";
	std::string tempString = ss.str();
	char* filename = (char*)tempString.c_str();

	std::ofstream ofs(filename, std::ios::out | std::ios::binary);
	ofs << "P6\n" << width << " " << height << "\n255\n";
	for (unsigned i = 0; i < width * height; ++i) {
		ofs << (unsigned char)(std::min(float(1), image[i].x) * 255) <<
			(unsigned char)(std::min(float(1), image[i].y) * 255) <<
			(unsigned char)(std::min(float(1), image[i].z) * 255);
	}
	ofs.close();
	delete[] image;
}

void Scene::TracePixel(int x, int y,float invWidth, float invHeight, float angle, float aspectratio, Vec3f* pixel) const
{
	float xx = (2 * ((x + 0.5f) * invWidth) - 1) * angle * aspectratio;
	float yy = (1 - 2 * ((y + 0.5f) * invHeight)) * angle;
	Vec3f raydir(xx, yy, -1);
	raydir.normalize();
	*pixel = Trace(Vec3f(0), raydir, 0);
}

void Scene::TraceRow(int y, float invWidth, float invHeight, float angle, float aspectratio, Vec3f* row, int width) const
{
	Vec3f* pixel = row;
	for (unsigned x = 0; x < width; ++x, ++pixel) {
		TracePixel(x, y, invWidth, invHeight, angle, aspectratio, pixel);
	}
}

/*******************************************************************************************
MARKING SCHEME: Expansion of framework

DESCRIPTION: An appropriate interface for adding and removing spheres

*******************************************************************************************/
void Scene::AddSphere(const Vec3f& center, const float radius, const Vec3f& surfaceColor, const float reflection, const float transparency, const Vec3f& emissionColor)
{
	// Lock for read-write
	std::unique_lock<std::shared_mutex> lock(m_Mutex);

	SpherePtr newSphere;
	newSphere.reset(NEW Sphere(center, radius, surfaceColor, reflection, transparency, emissionColor));
	m_Spheres.push_back(std::move(newSphere));
}

void Scene::ClearSpheres()
{
	// Lock for read-write
	std::unique_lock<std::shared_mutex> lock(m_Mutex);

	m_Spheres.clear();
}

void Scene::Update(float timeElapsed)
{
	// Lock for read-write
	std::unique_lock<std::shared_mutex> lock(m_Mutex);

	for (SpherePtr& sphere : m_Spheres)
	{
		sphere->Update(timeElapsed);
	}
}

Sphere& Scene::GetSphere(int index) const
{
	// lock for read-only
	std::shared_lock<std::shared_mutex> lock(m_Mutex);

	return *m_Spheres[index];
}

int Scene::GetSphereCount() const
{
	std::shared_lock<std::shared_mutex> lock(m_Mutex);

	return m_Spheres.size();	
}
