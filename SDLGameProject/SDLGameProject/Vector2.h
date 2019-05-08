#ifndef VECTOR2_H_
#define VECTOR2_H_

class Vector2
{
public:
	float x;
	float y;

	Vector2();
	Vector2(float x, float y);

	//adds two vectors
	Vector2 operator+ (const Vector2& anotherVector);
	Vector2 operator+=(const Vector2& anotherVector);

	//subtracts two vectors
	Vector2 operator- (const Vector2& anotherVector);
	Vector2 operator-=(const Vector2& anotherVector);

	//multiplying a scalar with a vector
	Vector2 operator*(const float& scalarValue);

	//assigns another operator
	void operator = (const Vector2& anotherVector);

	//calculates length of vector
	float Magnitude();

	//normalize
	float Normalize();

	~Vector2();
};

#endif 