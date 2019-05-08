#include "Input.h"
#include "Game.h"

Input* Input::m_instance = nullptr;

Input::Input()
{
	m_keyboardState = 0;
	//setting button state to false by default
	for (int i = 0; i < 5; ++i)
	{
		m_mouseButtonStates.push_back(false);
	}
}


Input * Input::GetInstance()
{
	//returns instance of input
	return m_instance;
}

void Input::Create()
{
	//check if there is no input
	if (m_instance == nullptr)
	{
		//create an input
		m_instance = new Input();
	}
}

void Input::Destroy()
{
	if (m_instance != nullptr)
	{
		//removes instance of input from memory
		delete m_instance;
		//set pointer to nullptr
		m_instance = nullptr;
	}
}

Input::~Input()
{
	//check if the size is greater than 0
	if (m_mouseButtonStates.size() > 0)
	{
		//remove all items in array
		m_mouseButtonStates.clear();
	}
}

void Input::UpdateInput()
{
	SDL_Event e;
	if (SDL_PollEvent(&e))
	{
		switch (e.type) {
		case SDL_QUIT:
			Game::GetInstance()->Quit();
			break;
		case SDL_KEYDOWN:
			OnKeyDown();
			break;
		case SDL_KEYUP:
			OnKeyUp();
			break;
		case SDL_MOUSEBUTTONDOWN:
			onMouseDown(e);
			break;
		case SDL_MOUSEBUTTONUP:
			onMouseUp(e);
			break;
		case SDL_MOUSEMOTION:
			onMouseMove(e);
			break;
		default:
			break;
		}
	}
}

bool Input::isKeyDown(SDL_Scancode key)
{
	if (m_keyboardState != nullptr)
	{
		//check if any key is being pressed
		if (m_keyboardState[key] == 1)
		{
			return true;
		}
	}
	return false;
}

bool Input::IsKeyUp(SDL_Scancode key)
{
	if (m_keyboardState != nullptr)
	{
		if (m_keyboardState[key] == 0)
		{
			return true;
		}
	}
	return false;
}

bool Input::IsMouseDown(MouseInput button)
{
	if (m_mouseButtonStates.size() > 0)
	{
		if (m_mouseButtonStates[button])
		{
			return true;
		}
	}
	return false;
}

bool Input::IsMouseUp(MouseInput button)
{
	if (m_mouseButtonStates.size() > 0)
	{
		if (!m_mouseButtonStates[button])
		{
			return true;
		}
	}
	return false;
}

int Input::GetMouseX()
{
	return m_mouseX;
}

int Input::GetMouseY()
{
	return m_mouseY;
}

void Input::GetMousePos(int * x, int * y)
{
	*x = m_mouseX;
	*y = m_mouseY;
}

void Input::OnKeyDown()
{
	m_keyboardState = SDL_GetKeyboardState(0);
}

void Input::OnKeyUp()
{
	m_keyboardState = SDL_GetKeyboardState(0);
}

void Input::onMouseDown(SDL_Event & e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT) { 
			m_mouseButtonStates[MOUSE_BUTTON_LEFT] = true;
		}  if (e.button.button == SDL_BUTTON_MIDDLE) { 
			m_mouseButtonStates[MOUSE_BUTTON_MIDDLE] = true; 
		}  if (e.button.button == SDL_BUTTON_RIGHT) { 
			m_mouseButtonStates[MOUSE_BUTTON_RIGHT] = true; 
		}
		m_mouseX = e.button.x;
		m_mouseY = e.button.y;
	}
}

void Input::onMouseUp(SDL_Event & e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		//left mouse button released?
		if (e.button.button == SDL_BUTTON_LEFT) {
			m_mouseButtonStates[MOUSE_BUTTON_LEFT] = false;
		}  
		//middle mouse button released?
		if (e.button.button == SDL_BUTTON_MIDDLE) {
			m_mouseButtonStates[MOUSE_BUTTON_MIDDLE] = false;
		} 
		//right mouse button released?
		if (e.button.button == SDL_BUTTON_RIGHT) {
			m_mouseButtonStates[MOUSE_BUTTON_RIGHT] = false;
		}
	}
}

void Input::onMouseMove(SDL_Event & e)
{
	//if its of type mouse motion
	if (e.type == SDL_MOUSEMOTION)
	{
			//Get position of X-coordinate of mouse cursor
			m_mouseX = e.button.x;
			//Get position of Y-coordinate of mouse cursor
			m_mouseY = e.button.y;
		
	}
}
