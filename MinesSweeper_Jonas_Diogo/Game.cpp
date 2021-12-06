#include "pch.h"
#include "Game.h"
#include <iostream>

//Basic game functions
#pragma region gameFunctions											
void Start()
{
	g_tTiles = new Texture[g_ArrayTextureSize];
	bool success{};

	success = TextureFromFile("Resources/0_TileZero.png", g_tTiles[0]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/1_TileOne.png", g_tTiles[1]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/2_TileTwo.png", g_tTiles[2]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/3_TileThree.png", g_tTiles[3]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/4_TileBacteria.png", g_tTiles[4]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/5_TileBacteriaPressed.png", g_tTiles[5]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/6_TileVaccine.png", g_tTiles[6]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	success = TextureFromFile("Resources/7_TileClear.png", g_tTiles[7]);
	if (!success) std::cout << "0_TileZero.png failed." << std::endl;

	
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
	for (int i{ 0 }; i < int(g_ArrayTextureSize - 1); ++i)
	{
		DeleteTexture(g_tTiles[i]);
	}
	
	/*delete[] g_tTiles;
	g_tTiles = nullptr;*/

	delete g_tTiles;
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
			
			//DrawTexture(g_tTiles[0])
			FillRect(g_GridRect);
			g_GridRect.left += g_RectSize + g_Border;
			//g_pGrid[j];
			if (IsPointInRectangle(g_GridRect, g_Mouse))
			{
				std::cout << "overlapping" << std::endl;
				SetColor(0, 1, 0);
			}
		}
		g_GridRect.left = g_Border;
		g_GridRect.bottom += g_RectSize + g_Border;
		//g_pGrid[i];
		if (IsPointInRectangle(g_GridRect, g_Mouse))
		{
			std::cout << "overlapping" << std::endl;
		}
	}
	g_GridRect.bottom = g_Border;

}


#pragma endregion ownDefinitions