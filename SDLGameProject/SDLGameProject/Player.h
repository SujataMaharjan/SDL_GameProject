#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"
#include "Input.h"
#include "AABB.h"

class Player :
	public GameObject {
public:
	Player();
	Player(Texture* texture,Vector2 pos);

	void Update(float deltaTime)override;
	void Draw(SDL_Renderer* renderer) override;
	void HandleInput() override;
	void SetForce(Vector2 force);
	Vector2 GetVelocity();

	AABB* GetCollider();

	~Player();

private:
	Input* m_input;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	AABB* m_collider;
	float m_maxVelocity;
};

#endif