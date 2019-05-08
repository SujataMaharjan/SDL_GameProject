#ifndef AABB_H_
#define _AABB_H_
#include "Vector2.h"

class Circle;

class AABB
{
public:
	AABB();
	AABB(Vector2 position, int width, int height);
	~AABB();

	//@brief returns position of bounding box
	const Vector2 GetPosition() const;

	//@brief returns width of bounding box
	const int GetWidth() const;

	//@brief returns height of bounding box
	const int GetHeight() const;

	//@brief check if a point collides with rectangle
	bool PointCollision(Vector2 point);

	//@brief check if rectangle collides with another rectangle
	bool RectangleCollision(const AABB& rect);

	//@brief check if a circle collides with rectangle
	bool CircleCollision(const Circle& c);

private:
	Vector2 m_position;
	int m_width;
	int m_height;

};

#endif