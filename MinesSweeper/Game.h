#pragma once
using namespace utils;
#include "structs.h"
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

//Game Settings
const int g_Rows{ 10 };
const int g_Colums{ g_Rows };
const int g_GridSize{ g_Rows * g_Colums };
 
// Change the window dimensions here

float g_Border{ 10.0f };


//------------------------------//

float g_WindowWidth{ g_GridSize * 3.2f + g_Border *2};
float g_WindowHeight{ g_GridSize * 3.2f + g_Border * 2 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here

//Colors
Color4f g_Red{ 1, 0, 0, 1 };
Color4f g_Green{ 0, 1, 0, 1 };
Color4f g_Blue{ 0, 0, 1, 1 };
Color4f g_Pink{ 1, 0, 1, 1 };
Color4f g_Yellow { 1, 1, 0, 1 };
Color4f g_What{ 0, 1, 1,1 };


Color4f g_White{ 1, 1, 1, 1 };
Color4f g_Black{ 0, 0, 0,1 };
Color4f g_Grey{ 0.5f, 0.5f, 0.5f, 1 };

//Sizes int
const int g_NrBombs{ 10 };
//Sizes float
float g_TileLeght{ 32 };

//Point2f
Point2f g_GridXY{ g_Border, g_Border };

//Rect
Rectf g_GridRect{ g_GridXY.x , g_GridXY.y, g_TileLeght * g_Rows, g_TileLeght * g_Colums };

//Arrays
//int g_GridArray[g_GridSize]{}; //only used to print 2D

bool g_TileArray[g_GridSize]{};
//bool g_TileArrayOverlay[g_GridSize]{};

MSTile tiles[g_GridSize]{};



int g_BombLocation[g_NrBombs];

//bools
bool IsClicked{ false };


// Declare your own functions here
void ClickTile(Point2f MousePoint, const int rows, const int columns, bool* pArray);
void ToggleTile(Point2f MousePoint, const int rows, const int columns, MSTile* pArray);
void DrawTile(int rows, int columns, bool* pArray, Color4f off, Color4f on);

void SetNumbers();

void InitializeBombLocation(int nrOfBombs);
void SetBomb();

void PrintArrayHasBomb(MSTile* pArray, int size);
void PrintArrayBool(bool* pArray, int size);
void PrintArray(int* pArray, int size);


void TwoDArrays(const int rows, const int columns, MSTile* pArray);
void Print2DElements(MSTile* pArray, int rows, int columns);
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);
int GetRowIndex(int Index, int columns);
int GetColumnIndex(int Index, int columns);
#pragma endregion ownDeclarations

#pragma region gameFunctions											
void Start();
void Draw();
void Update(float elapsedSec);
void End();
#pragma endregion gameFunctions

#pragma region inputHandling											
void OnKeyDownEvent(SDL_Keycode key);
void OnKeyUpEvent(SDL_Keycode key);
void OnMouseMotionEvent(const SDL_MouseMotionEvent& e);
void OnMouseDownEvent(const SDL_MouseButtonEvent& e);
void OnMouseUpEvent(const SDL_MouseButtonEvent& e);
#pragma endregion inputHandling
