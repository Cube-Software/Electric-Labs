#pragma once

#define PI 3.1415926535897932384626433832795
#define Radians(x) (float)(((x) * MATH_PI / 180.0f))
#define Degrees(x) (float)(((x) * 180.0f / MATH_PI))

// Basic stuff
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

// Vectors

namespace EL::Maths{
    class Vector2 {

    public:

        float x;
        float y;

        inline Vector2() {
            x = 0;
            y = 0;
        }

        inline Vector2(float p_x, float p_y) {
            x = p_x;
            y = p_y;
        }

        inline float Length() const {
            return Sqrt(x * x + y * y);
        }

        inline Vector2 Middle(Vector2 p_vector) const {
            return Vector2(abs(p_vector.x - x), abs(p_vector.y - y));
        }

        Vector2 Normalized() const {
			return *this * Q_rsqrt(Length());
		}

        Vector2 operator+(Vector2 p_vector) const;
        Vector2 operator+(float p_val) const;

        Vector2 operator-(Vector2 p_vector) const;
        Vector2 operator-(float p_val) const;

        Vector2 operator*(Vector2 p_vector) const;
        Vector2 operator*(float p_val) const;

        Vector2 operator/(Vector2 p_vector) const;
        Vector2 operator/(float p_val) const;

        bool operator==(Vector2 p_vector) const;
        bool operator!=(Vector2 p_vector) const;

        void operator+=(Vector2 p_vector);
        void operator+=(float p_val);

        void operator-=(Vector2 p_vector);
        void operator-=(float p_val);

        void operator*=(Vector2 p_vector);
        void operator*=(float p_val);

        void operator/=(Vector2 p_vector);
        void operator/=(float p_val);

    };
}