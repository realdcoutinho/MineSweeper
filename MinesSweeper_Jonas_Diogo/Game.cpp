#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
}

void Draw()
{
	ClearBackground(0.5f, 0.5f, 0.5f);
	SetColor(1, 0, 0);
	DrawGrid(g_Border,g_Border, g_pGrid);
	

}

void Update(float elapsedSec)
{
	// process input, do physics 

	// e.g. Check keyboard state
	//const Uint8 *pStates = SDL_GetKeyboardState( nullptr );
	//if ( pStates[SDL_SCANCODE_RIGHT] )
	//{
	//	std::cout << "Right arrow key is down\n";
	//}
	//if ( pStates[SDL_SCANCODE_LEFT] && pStates[SDL_SCANCODE_UP])
	//{
	//	std::cout << "Left and up arrow keys are down\n";
	//}
}

void End()
{
	// free game resources here
}
#pragma endregion gameFunctions

//Keyboard and mouse input handling
#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key)
{

}

void OnKeyUpEvent(SDL_Keycode key)
{
	//switch (key)
	//{
	//case SDLK_LEFT:
	//	//std::cout << "Left arrow key released\n";
	//	break;
	//case SDLK_RIGHT:
	//	//std::cout << "Right arrow key released\n";
	//	break;
	//case SDLK_1:
	//case SDLK_KP_1:
	//	//std::cout << "Key 1 released\n";
	//	break;
	//}
}

void OnMouseMotionEvent(const SDL_MouseMotionEvent& e)
{
	//std::cout << "  [" << e.x << ", " << e.y << "]\n";
	Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	g_Mouse.x = float(e.x);
	g_Mouse.y = g_WindowHeight - float(e.y);

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		if (IsPointInRectangle(g_GridRect, g_Mouse))
		{
	
			SetColor(0, 1, 0);
		}
	}
		break;
	default:
		break;	
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	////std::cout << "  [" << e.x << ", " << e.y << "]\n";
	//switch (e.button)
	//{
	//case SDL_BUTTON_LEFT:
	//{
	//	//std::cout << "Left mouse button released\n";
	//	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	//	break;
	//}
	//case SDL_BUTTON_RIGHT:
	//	//std::cout << "Right mouse button released\n";
	//	break;
	//case SDL_BUTTON_MIDDLE:
	//	//std::cout << "Middle mouse button released\n";
	//	break;
	//}
}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void DrawGrid(const float rows, const float cols, int* pArray)
{
	for (int i{ 0 }; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
		{
			FillRect(g_GridRect);
			g_GridRect.left += g_RectSize + g_Border;
			g_pGrid[j];
			if (IsPointInRectangle(g_GridRect, g_Mouse))
			{
				std::cout << "overlapping" << std::endl;
				SetColor(0, 1, 0);
			}
		}
		g_GridRect.left = g_Border;
		g_GridRect.bottom += g_RectSize + g_Border;
		g_pGrid[i];
		if (IsPointInRectangle(g_GridRect, g_Mouse))
		{
			std::cout << "overlapping" << std::endl;
		}
	}
	g_GridRect.bottom = g_Border;

}


#pragma endregion ownDefinitions