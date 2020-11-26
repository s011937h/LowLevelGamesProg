// [header]
// A very basic raytracer example.
// [/header]
// [compile]
// c++ -o raytracer -O3 -Wall raytracer.cpp
// [/compile]
// [ignore]
// Copyright (C) 2012  www.scratchapixel.com
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// [/ignore]
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
#include <memory>

#include "Spheres.h"

#if defined __linux__ || defined __APPLE__
// "Compiled for Linux
#else
// Windows doesn't define these values by default, Linux does
#define M_PI 3.141592653589793
#define INFINITY 1e8
#endif

//[comment]
// In the main function, we will create the scene which is composed of 5 spheres
// and 1 light (which is also a sphere). Then, once the scene description is complete
// we render that scene, by calling the render() function.
//[/comment]
int main(int argc, char **argv)
{
	//std::vector<std::unique_ptr<Sphere>> sphereList;

	//sphereList.push_back(std::make_unique<Sphere>(Vec3f(1,2,3), 32, Vec3f(2,65,2), 0.5, 0.7, Vec3f(0,0,0));

	//Sphere* spheres = new Sphere(const Vec3f & c, const float r, const Vec3f & sc, const float refl = 0, const float transp = 0, const Vec3f & ec = 0);
	// This sample only allows one choice per program execution. Feel free to improve upon this
	srand(13);
	//BasicRender();
	//SimpleShrinking();
	//spheres.SmoothScaling();

	return 0;
}

