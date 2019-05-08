#pragma once
#include "Vector2.h"
class Circle
{
public:
	Circle();
	Circle(Vector2 position, int radius);
	~Circle();

	//returns position of circle
	const Vector2 GetPosition() const;
	//returns radius of circle
	const int GetRadius() const;

	//@brief checks collision with a point
	bool PointCollision(Vector2 point);

	//@brief circle-circle collision
	bool CircleCollision(const Circle& c);

private:
	int m_radius;
	Vector2 m_position;
};

