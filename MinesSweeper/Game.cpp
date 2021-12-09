#include "pch.h"
#include "Game.h"
#include <iostream>
#include <math.h>
#include <iomanip>      // std::setprecision
#include <iomanip>      // std::setw


//Basic game functions
#pragma region gameFunctions											
void Start()
{
	// initialize game resources here
	TwoDArrays(g_Rows, g_Colums, tiles);
	InitializeBombLocation(g_NrBombs);
	SetBomb();
	SetNumbers();
}

void Draw()
{
	ClearBackground();
	SetColor(1, 0, 0, 1);
	DrawRect(g_GridRect);
	DrawTile(g_Rows, g_Colums, g_TileArray, g_Grey, g_White);

	// Put your own draw statements here

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
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };
	//ToggleTile(mousePos, g_Rows, g_Colums, g_TileArray);

}

void OnMouseDownEvent(const SDL_MouseButtonEvent& e)
{
	
	Point2f mousePos{ float(e.x), float(g_WindowHeight - e.y) };

	switch (e.button)
	{
	case SDL_BUTTON_LEFT:
	{
		ClickTile(mousePos, g_Rows, g_Colums, g_TileArray);

		break;
	}
	case SDL_BUTTON_RIGHT:
		ToggleTile(mousePos, g_Rows, g_Colums, tiles);
		break;
	case SDL_BUTTON_MIDDLE:
		//std::cout << "Middle mouse button released\n";
		break;
	}

}

void OnMouseUpEvent(const SDL_MouseButtonEvent& e)
{

}
#pragma endregion inputHandling

#pragma region ownDefinitions
// Define your own functions here
void ToggleTile(Point2f MousePoint, const int rows, const int columns, MSTile* pArray)
{
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			Rectf gridCell{ g_GridXY.x + (g_TileLeght * column),
							g_GridXY.y + (g_TileLeght * row), g_TileLeght, g_TileLeght };
			while (IsPointInRectangle(gridCell, MousePoint))
			{
				pArray[index].HasFlag = !pArray[index].HasFlag;
				std::cout << pArray[index].HasFlag << '\n';
				return;
			}
		}
	}
}

void ClickTile(Point2f MousePoint,const int rows,const int columns, bool* pArray)
{
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			Rectf gridCell{ g_GridXY.x + (g_TileLeght * column),
							g_GridXY.y + (g_TileLeght * row), g_TileLeght, g_TileLeght };
			if (IsPointInRectangle(gridCell, MousePoint))
			{
				pArray[index] = !pArray[index];
				if (!pArray[index]) { // Does allow the same tile to be selected again
					pArray[index] = !pArray[index];
				}
				std::cout << index << " " << pArray[index] << '\n';
				return;
			}
		}
	}
}

void DrawTile(int rows, int columns, bool* pArray, Color4f off, Color4f on)
{
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			Point2f bottomLeft{ g_GridXY.x + (column * g_TileLeght), g_GridXY.y + (row * g_TileLeght) };
			int index{ GetIndex(row, column, columns) };
			SetColor(off);
			if (tiles[index].HasFlag) {
				SetColor(g_Green);
			}
			if (pArray[index] && !tiles[index].HasBomb) {
				
				if (tiles[index].Number == 0) {
					SetColor(on);
				}
				if (tiles[index].Number == 1) {
					SetColor(g_Blue);
				}
				if (tiles[index].Number == 2) {
					SetColor(g_Pink);
				}
				if (tiles[index].Number == 3) {
					SetColor(g_Yellow);
				}
				if (tiles[index].Number == 4) {
					SetColor(g_Black);
				}
				if (tiles[index].Number == 5) {
					SetColor(g_What);
				}

			}
			if (pArray[index] && tiles[index].HasBomb) {
				SetColor(g_Red);
			}
			FillRect(bottomLeft, g_TileLeght, g_TileLeght);
			SetColor(g_Black);
			DrawRect(bottomLeft, g_TileLeght, g_TileLeght);
		}
	}
}


void InitializeBombLocation(int nrOfBombs)
{

	for (int i{}; i < nrOfBombs - 1; ++i) 
	{
		int randoom = rand() % (g_GridSize - 1);
		tiles[randoom].HasBomb = true;
	}

	//PrintArray(pArray, size);
}

void SetBomb()
{
	for (int i{}; i < g_GridSize; ++i) {
		for (int j{}; j < g_NrBombs; ++j) {

			for (int row{ 0 }; row < g_Rows; row++)
			{
				for (int column{ 0 }; column < g_Colums; column++)
				{
					int index{ GetIndex(row, column, g_Colums) };

					if (g_BombLocation[j] == index) {
						tiles[index].HasBomb = true;
					}

				}
			}

		}
	}
	PrintArrayHasBomb(tiles, 100);
}

void SetNumbers()
{
	for (int row{ 0 }; row < g_Rows; row++)
	{
		for (int column{ 0 }; column < g_Colums; column++)
		{
			int index{ GetIndex(row, column, g_Colums) };

			if (tiles[index].HasBomb) {

				int indexOffSets[]={ -11, -10, -9, -1, 1, 9, 10, 11 };
				int size = sizeof(indexOffSets) / sizeof(int);
				std::cout << '\n' <<"Size: " << size << '\n';
				for (int i{}; i < size; ++i) {
					int j{ indexOffSets[i] };

					//bool IsValid{ (row >= 0) && (row < g_Rows) && (column >= 0) && (column < g_Colums) };

					if (index + j >= 0 && index + j <= 99) {
						tiles[index + j].Number += 1;
					}
				}
			}

		}
	}
	//PrintArray(g_NrArrayTile, g_GridSize);
}








void PrintArrayHasBomb(MSTile* pArray, int size) {

	for (int i{ 0 }; i < size; ++i) {
		std::cout << i << ": " << pArray[i].HasBomb << '\n';
	}
	std::cout << '\n';
}


void PrintArrayBool(bool* pArray, int size) {

	for (int i{ 0 }; i < size; ++i) {
		std::cout << i << ": " << pArray[i] << '\n';
	}
	std::cout << '\n';
}

void PrintArray(int* pArray, int size) {

	for (int i{ 0 }; i < size; ++i) std::cout << i << ": " << pArray[i] << '\n';
	std::cout << '\n';
}

void TwoDArrays(const int rows, const int columns, MSTile* pArray)
{
	std::cout << "-- 2D arrays --" << std::endl;
	for (int row{ 0 }; row < rows; row++)
	{
		for (int column{ 0 }; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			//linearGridArray[index] = (row + 1) * 10 + column + 1;
			pArray[index].GridArray = (row + 1) * columns + column + 1;
		}
	}
	Print2DElements(pArray, rows, columns);
}

void Print2DElements(MSTile* pArray, int rows, int columns)
{
	for (int row = 0; row < rows; row++)
	{
		for (int column = 0; column < columns; column++)
		{
			int index{ GetIndex(row, column, columns) };
			std::cout << std::setw(5) << pArray[index].GridArray;
		}
		std::cout << std::endl;
	}
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
	return rowIndex * nrOfColumns + columnIndex;
}

int GetRowIndex(int Index, int columns)
{
	return Index / columns;
}

int GetColumnIndex(int Index, int columns)
{
	return Index % columns;
}
#pragma endregion ownDefinitions