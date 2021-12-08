#include "pch.h"
#include "Game.h"
#include <iostream>
#include <iomanip>


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	AddingTextures();
	/*
		bool tileClear = TextureFromFile("Resources/00_TileClear.png", g_00TileClear);
	if (!tileClear)
	{
		std::cout << "Loading failed";
	}
	
	*/
	/*
	
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
	*/
	BombPosition();
}

void Draw()
{
	ClearBackground(0.5f, 0.5f, 0.5f);
	//SetColor(1, 0, 0);
	//DrawGrid(g_Border,g_Border, g_pGrid);
	DrawGrid();
	AddingTimeTexture();
}

void Update(float elapsedSec)
{
	g_TimeSeconds += elapsedSec;
}

void End()
{
	for (int j{}; j < 12 - 1; j++) {
		DeleteTexture(g_TileTextures[j]);
	}
	for (int k{}; k < 10 - 1; k++) {
		DeleteTexture(g_TextTexture[k]);

	}

	for (int i{ 0 }; i < int(g_ArrayTextureSize - 1); ++i)
	{
		DeleteTexture(g_tTiles[i]);
	}
	
	delete[] g_tTiles;
	g_tTiles = nullptr;

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
	g_Mouse = mousePos; // Set Mouse Position

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	ClickTile(g_Mouse, g_Grid); // adds mouse position
	//Its not working in the switche bellow

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		break;
	}
	case SDL_BUTTON_RIGHT:
	{
		std::cout << "  [" << e.x << ", " << e.y << "]\n";
		break;
	}
	case SDL_BUTTON_MIDDLE:

		break;
	}
}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{
	
	////switch (e.button)
	////{
	////case SDL_BUTTON_LEFT:
	////{
	////	//std::cout << "Left mouse button released\n";
	////	//Point2f mousePos{ float( e.x ), float( g_WindowHeight - e.y ) };
	////	break;
	////}
	////case SDL_BUTTON_RIGHT:
	////	//std::cout << "Right mouse button released\n";
	////	break;
	////case SDL_BUTTON_MIDDLE:
	////	//std::cout << "Middle mouse button released\n";
	////	break;
	////}
}
#pragma endregion inputHandling




#pragma region ownDefinitions
// Define your own functions here

//adds the time texture and call the draw function
void AddingTimeTexture()
{
	const std::string time{ std::to_string(g_TimeSeconds) }; // transforms the float variable into a string and passes it into another const string
	Point2f positionTime{ g_GridWidth - g_Border - 120, g_GridHeight + 15 }; // Position of the Time
	bool tile = TextureFromString(time, "Resources/Hospital.ttf", 55, Color4f{ g_Red }, g_TextTexture[0]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	
	//std::cout << time << '\n';
	DrawTimeTexture(g_TextTexture, positionTime, 0);
}

//Draws Time on the visuals
void DrawTimeTexture(Texture *pArray, Point2f point, int idx)
{
	DrawTexture(pArray[idx], point);
}

//adds all the visual textures
void AddingTextures() // adds all the visual textures
{
	bool tile = TextureFromFile("Resources/0_Tile.png", g_TileTextures[0]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/1_ClearTile.png", g_TileTextures[1]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/2_ClearTileOne.png", g_TileTextures[2]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/3_ClearTileTwo.png", g_TileTextures[3]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/4_ClearTileThree.png", g_TileTextures[4]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/5_FlagTile.png", g_TileTextures[5]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/6_MineTilePressed.png", g_TileTextures[6]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/7_LostTile.png", g_TileTextures[7]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/8_RestartTile.png", g_TileTextures[8]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
	tile = TextureFromFile("Resources/9_RestartTilePressed.png", g_TileTextures[9]);
	if (!tile)
	{
		std::cout << "Loading failed";
	}
} // adds all the visual textures

/*
void CheckPosition(int row, int column, int* pArray, Point2f mouse)
{
	for (int rows{ 0 }; rows < g_Rows; rows++)
	{
		for (int columns{ 0 }; columns < g_Colums; columns++)
		{
			float width{ columns * g_TileSize }; // Distance of the next tile horizontally from the intial grid position
			float height{ rows * g_TileSize }; // Distance of the next tile vertically from the intial grid position
			float textureLenght{ g_TileTextures[0].width / g_Scale }; // lenght of each tile
			Point2f tileXY{ g_GridPos.x + width, g_GridPos.y + height }; //bottomleft Point of each individual tile
			Rectf tileRect{ tileXY.x, tileXY.y, textureLenght , textureLenght }; //Rect of each individual tile
			int index{ GetIndex(rows, columns, g_Colums) };

			if (IsPointInRectangle(tileRect, mouse))
			{
				g_Grid[index] = !g_Grid[index];
			}
			std::cout << index << " Value: " << g_Grid[index] << '\n';

			return;
		}
	}
}
*/

void ClickTile(Point2f MousePoint, int* pArray)
{
	for (int row{ 0 }; row < g_Rows; row++)
	{
		for (int column{ 0 }; column < g_Colums; column++)
		{
			float width{ column * g_TileSize }; // Distance of the next tile horizontally from the intial grid position
			float height{ row * g_TileSize }; // Distance of the next tile vertically from the intial grid position
			float textureLenght{ g_TileTextures[0].width / g_Scale }; // lenght of each tile
			Point2f tileXY{ g_GridPos.x + width, g_GridPos.y + height }; //bottomleft Point of each individual tile
			Rectf zeroMine{ tileXY.x, tileXY.y, textureLenght , textureLenght }; //Rect of each individual tile
			int index{ GetIndex(row, column, g_Colums) };

			if (IsPointInRectangle(zeroMine, MousePoint))
			{
				pArray[index] = !pArray[index];
				/*
								if (!pArray[index]) { // Does allow the same tile to be selected again
					pArray[index] = !pArray[index];
				}
				*/
				std::cout << "Value " << index << '\n';
			}
		}
	}
}

void DrawGrid()
{
	for (int row{ 0 }; row < g_Rows; row++)
	{
		for (int column{ 0 }; column < g_Colums; column++)
		{
			float width{ column * g_TileSize }; // Distance of the next tile horizontally from the intial grid position
			float height{ row * g_TileSize }; // Distance of the next tile vertically from the intial grid position
			float textureLenght{ g_TileTextures[0].width / g_Scale }; // lenght of each tile
			Point2f tileXY{ g_GridPos.x + width, g_GridPos.y + height }; //bottomleft Point of each individual tile
			Rectf zeroMine{ tileXY.x, tileXY.y, textureLenght , textureLenght }; //Rect of each individual tile
			int index{ GetIndex(row, column, g_Colums) }; // gets the tile index
			if (!g_Grid[index]){
				DrawTexture(g_TileTextures[0], zeroMine); // if its not clicked, stays as original, Tile 0
			}
			/*
						else if (g_Grid[index]) {
					if (g_Grid[index] != g_BombPositionArray[index]) {
						DrawTexture(g_TileTextures[1], zeroMine);
					}
					else if(g_Grid[index] == g_BombPositionArray[index]){
						DrawTexture(g_TileTextures[6], zeroMine); // if it is clicked Draws this texture. Here we have to implemente a function to check if the tile pressed was a bom or otherwise to change texture based on it
					}
			}
			*/
		}
	}
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}


void DrawBom() 
{


}

void BombPosition() {

	for (int i{}; i < g_nrBombs - 1; ++i) {
		g_BombPositionArray[i] = rand() % (g_ArraySize - 1);
	}
	PrintArray(g_BombPositionArray, g_nrBombs);
}

void PrintArray(int* pArray, int size) {

	for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] << ' ';
	std::cout << '\n';
}


//void DrawGrid(const float rows, const float cols, int* pArray)
//{
	//const Color4f toggleOn{ g_Orange };
	//const Color4f toggleOff{ g_Grey };

	/*
		for (int i{0}; i < rows; ++i)
	{
		for (int j{ 0 }; j < cols; ++j)
		{
			
			//DrawTexture(g_tTiles[0]);
			DrawRect(g_GridRect);
			SetColor(g_Red);
			FillRect(g_GridRect);
			SetColor(g_Blue);
			
			g_GridRect.left += g_RectSize;
			//g_pGrid[j];
			if (IsPointInRectangle(g_GridRect, g_Mouse))
			{
				std::cout << "overlapping" << std::endl;
			}
		}
		g_GridRect.left = g_Border;
		g_GridRect.bottom += g_RectSize;
		//g_pGrid[i];
		if (IsPointInRectangle(g_GridRect, g_Mouse))
		{
			std::cout << "overlapping" << std::endl;
		}
	}
	g_GridRect.bottom = g_Border;
	*/	
//

#pragma endregion ownDefinitions