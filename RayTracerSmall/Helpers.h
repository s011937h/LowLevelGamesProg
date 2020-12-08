#pragma once

//[comment]
// This variable controls the maximum recursion depth
//[/comment]
#define MAX_RAY_DEPTH 5

class Helpers
{

public:
	static float mix(const float a, const float b, const float mix)
	{
		return b * mix + a * (1 - mix);
	}
};
