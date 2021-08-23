#include "maths.hpp"

namespace EL::maths {
    float Sqrt(float num) { float p = 0.000001; float s = num; while ((s - num / s) > p) { s = (s + num / s) / 2; } return s; }

	float Q_rsqrt(float num) { 
        long i;
        float x2, y;
        const float threehalfs = 1.5F;

        x2 = num * 0.5F;
        y  = num;
        i  = * ( long * ) &y;                       
        i  = 0x5f3759df - ( i >> 1 );               
        y  = * ( float * ) &i;
        y  = y * ( threehalfs - ( x2 * y * y ) );  

        return y; 
    }

	float Sin(int deg) {
		deg %= 360;
		float rad = deg * PI / 180;
		float sin = 0;
		for (int i = 0; i < 7; i++) {
			sin += power(-1, i) * power(rad, 2 * i + 1) / fact(2 * i + 1);
		}
		return sin;
	}

	float Cos(int deg) {
		deg %= 360;
		float rad = deg * PI / 180;
		float cos = 0;

		int i;
		for (i = 0; i < 7; i++) {
			cos += power(-1, i) * power(rad, 2 * i) / fact(2 * i);
		}
		return cos;
	}

	float Tan(int deg) { return Sin(deg) / Cos(deg); }

	float power(float base, int exp) {
		if (exp < 0) {
			if (base == 0)
				return -0;
			return 1 / (base * power(base, (-exp) - 1));
		}
		if (exp == 0)
			return 1;
		if (exp == 1)
			return base;
		return base * power(base, exp - 1);
	}

	int fact(int n) {
		return n <= 0 ? 1 : n * fact(n - 1);
	}

	float abs(float num) {
		return (num < 0.0f) ? -num : num;
	}

	float abs(int num) {
		return (num < 0) ? (float)(-num) : (float)(num);
	}
}