#include "Player.h"
#include <iostream>


Player::Player() {
	
	m_position = Vector2 (0, 0);
	m_texture = nullptr;
	std::cout << "player constructor" << std::endl;
	m_collider = nullptr;
	m_maxVelocity = 0.0f;
}

Player::Player(Texture * texture, Vector2 pos) {
	m_texture = texture;
	this->m_position = pos;
	m_acceleration = Vector2(0, 0);
	//set up collider
	m_collider = new AABB(m_position, m_texture->GetImageWidth(), m_texture->GetImageHeight());
	m_maxVelocity = 100.0f;
}

void Player::Update(float deltaTime) {
	SetForce(m_velocity * -2.0f);
	m_velocity = m_velocity + m_acceleration * deltaTime;
	m_position = m_position + m_velocity * deltaTime;
	m_acceleration = Vector2(0, 0);
	//m_position = m_position + m_velocity*deltaTime;

	if (m_velocity.x > 100.0f)
	{
		m_velocity.x = m_maxVelocity;
	}
	if (m_velocity.y > 100.0f)
	{
		m_velocity.y = m_maxVelocity;
	}
	if (m_velocity.x < -100.0f)
	{
		m_velocity.x = m_maxVelocity;
	}
	if (m_velocity.y > -100.0f)
	{
		m_velocity.y = m_maxVelocity;
	}

}

void Player::Draw(SDL_Renderer* renderer) {
	m_texture->Draw(renderer,m_position.x, m_position.y);
}

void Player::HandleInput() {
	m_input = Input::GetInstance();
	/*if (m_input->isKeyDown(SDL_SCANCODE_W))
	{
	Vector2 v = Vector2(0,-100);
	v.Normalize();
	SetForce(v*100.0f);
		SetForce(Vector2(0, -1000));
	}
	if (m_input->isKeyDown(SDL_SCANCODE_S))
	{
		SetForce(Vector2(0, 1000));
	}
	if (m_input->isKeyDown(SDL_SCANCODE_A))
	{
		SetForce(Vector2(-1000, 0));
	}
	if (m_input->isKeyDown(SDL_SCANCODE_D))
	{
		SetForce(Vector2(1000, 0));
	}*/

	int x = 0;
	int y = 0;
	m_input->GetMousePos(&x, &y);

	if (m_input->IsMouseDown(MOUSE_BUTTON_LEFT))
	{
		SetForce(Vector2(x - m_position.x, y - m_position.y));
	}
	std::cout << x << "" << y << std::endl;
	//std::cout << y << std::endl;

}

void Player::SetForce(Vector2 force)
{
	m_acceleration = m_acceleration + force;
}

Vector2 Player::GetVelocity()
{
	return m_velocity;
}

AABB * Player::GetCollider()
{
	return m_collider;
}

Player::~Player() {
	std::cout << "player destructor" << std::endl;
	//deletes AABB
	if (m_collider != nullptr)
	{
		delete m_collider;
		m_collider = nullptr;
	}
}
