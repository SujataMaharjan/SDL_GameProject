#include "AABB.h"
#include "Circle.h"


AABB::AABB()
{
	m_position = Vector2(0, 0);
	m_width = 0;
	m_height = 0;

}

AABB::AABB(Vector2 position, int width, int height)
{
	m_position =position;
	m_width = width;
	m_height = height;
}


AABB::~AABB()
{
}

const Vector2 AABB::GetPosition() const
{
	return m_position;
}

const int AABB::GetWidth() const
{
	return m_width;
}

const int AABB::GetHeight() const
{
	return m_height;
}

bool AABB::PointCollision(Vector2 point)
{
	if (point.x > m_position.x && point.x < m_position.x + m_width && 
		point.y < m_position.y && point.y<m_position.y + m_height)
	{
		return true;
	}
	return false;
}

bool AABB::RectangleCollision(const AABB & rect)
{
	//check if another rectangle is not colliding with this rectangle
	if (rect.GetPosition().x + rect.GetWidth() < m_position.x || 
		rect.GetPosition().x > m_width  + m_position.x||
		rect.GetPosition().y + rect.GetHeight() < m_position.y || 
		rect.GetPosition().y > m_height + m_position.y)
	{
		return false;
	}
	return true;
}

bool AABB::CircleCollision(const Circle & c)
{
	int testX = 0;
	int testY = 0;
	//Check if circle is at right side of rectangle 
	if (c.GetPosition().x > m_width + m_position.x)
	{
		//Check against width of that rectangle
		testX = m_position.x + m_width;
	}
	//Check if circle is at left side of rectangle
	else if (c.GetPosition().x < m_position.x)
	{
		//Check against left edge
		testX = m_position.x;
	}
	//if circle is above square
	if (c.GetPosition().y < m_position.y)
	{
		//Check against top edge
		testY = m_position.y;
	}
	//if circle is below square
	if (c.GetPosition().y > m_position.y + m_height)
	{
		//Check against bottom edge
		testY = m_position.y + m_height;
	}

	Vector2 distance;
	distance.x = c.GetPosition().x - testX;
	distance.y = c.GetPosition().y - testY;
	float length = distance.Magnitude();

	if (length <= c.GetRadius())
	{
		return true;
	}

	return false;
}
