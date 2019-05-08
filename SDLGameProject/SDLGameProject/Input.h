#ifndef INPUT_H_
#define INPUT_H_

#include<SDL.h>
#include<vector>

enum MouseInput
{
	MOUSE_BUTTON_LEFT = 0,
	MOUSE_BUTTON_RIGHT = 1,
	MOUSE_BUTTON_MIDDLE = 2,
	MOUSE_BUTTON_4 = 3,
	MOUSE_BUTTON_5 = 4

};
class Input
{
public:
	static Input* GetInstance();
	static void Create();
	static void Destroy();

	~Input();

	void UpdateInput();
	//keyboard handling events
	bool isKeyDown(SDL_Scancode key);
	bool IsKeyUp(SDL_Scancode key);

	//mouse handling events
	bool IsMouseDown(MouseInput button);
	bool IsMouseUp(MouseInput button);

	//Returns X position of mouse
	int GetMouseX();
	//Returns Y position of mouse
	int GetMouseY();
	//Returns both position of mouse
	void GetMousePos(int* x, int* y);

private:
	Input();
	//keyboard events
	void OnKeyDown();
	void OnKeyUp();
	const Uint8* m_keyboardState;
	static Input* m_instance;

	//mouse spec
	int m_mouseX;
	int m_mouseY;
	std::vector<bool>m_mouseButtonStates;

	//mouse events;
	void onMouseDown(SDL_Event& e);
	void onMouseUp(SDL_Event&);
	void onMouseMove(SDL_Event& e);
};


#endif 
