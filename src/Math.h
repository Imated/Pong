#pragma once

struct Vector2
{
	float x;
	float y;

	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float x, float y) : x(x), y(y) {}
	Vector2(float val) : x(val), y(val) {}

	Vector2 operator*(float scalar) const {
		return Vector2(x * scalar, y * scalar);
	}
	Vector2 operator/(float scalar) const {
		return Vector2(x / scalar, y / scalar);
	}
	Vector2 operator+(Vector2 adder) const {
		return Vector2(x + adder.x, y + adder.y);
	}
	Vector2 operator-(Vector2 subtractor) const {
		return Vector2(x - subtractor.x, y - subtractor.y);
	}
	friend bool operator!=(const Vector2& a, const Vector2& b) {
		return a.x != b.x || a.y != b.y;
	}
	friend bool operator==(const Vector2& a, const Vector2& b) {
		return a.x == b.x && a.y == b.y;
	}
	void operator*=(const Vector2& a) {
		this->x *= a.x;
		this->y *= a.y;
	}
	void operator/=(const Vector2& a) {
		this->x /= a.x;
		this->y /= a.y;
	}
};