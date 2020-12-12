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
#include "MemoryManager.h"
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
#include <Windows.h>
#include <chrono>
using namespace std;

#include "Spheres.h"
#include "Vector3.h"
#include "Scene.h"

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
int main(int argc, char** argv)
{
	/*******************************************************************************************
	MARKING SCHEME: Optimisation of the framework

	DESCRIPTION: Add C++ Chrono

	*******************************************************************************************/

	{ //add extra scope to make sure memory isn't used
	auto start = chrono::steady_clock::now();

	//do operations
	// This sample only allows one choice per program execution. Feel free to improve upon this
	srand(13);

	Scene::Animate();
	//Sphere::BasicRender();
	//SimpleShrinking();
	//SmoothScaling();

	auto end = chrono::steady_clock::now();

	// Store the time difference between start and end
	chrono::duration<double> diff = end - start;
	string duration = to_string(diff.count());

	//print result and elapsed time
	cout << "Elapsed time: " << duration << endl;
	}

	MemoryManager::Get().DumpHeap();

	return 0;
}

