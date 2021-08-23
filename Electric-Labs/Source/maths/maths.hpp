#pragma once

#define MATH_PI 3.1415926535897932384626433832795
#define ToRadians(x) (float)(((x) * MATH_PI / 180.0f))
#define ToDegrees(x) (float)(((x) * 180.0f / MATH_PI))

namespace EL::Maths{
	static float Cos(int deg);
	static float Sin(int deg);
	static float Tan(int deg);
	static float Sqrt(float num);
	static float Q_rsqrt(float num);
	static float power(float base, int exp);
	static int fact(int n);
	static float abs(float num);
	static float abs(int num);
	static float Lerp(float start, float stop, float step);
}