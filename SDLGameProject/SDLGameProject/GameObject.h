#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Texture.h"
#include"Vector2.h"

class GameObject {
public:
	GameObject();
	~GameObject();

	virtual void Draw(SDL_Renderer* renderer) = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void HandleInput() = 0;

protected:
	/*int m_positionX;
	int m_positionY;*/
	Vector2 m_position;
	//Vector2 m_velocity;
	Texture* m_texture;
};
#endif
