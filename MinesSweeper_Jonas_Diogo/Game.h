#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };

// Change the window dimensions here
float g_WindowWidth{ 500 };
float g_WindowHeight{ 500 };
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture* g_tTiles{};
unsigned int g_ArrayTextureSize{8};

Point2f g_Mouse{};
const float g_Border{10.f};
const float g_RectSize{32};
Point2f g_RectPos{g_Border, g_Border};
Rectf g_GridRect{ g_RectPos.x, g_RectPos.y, g_RectSize, g_RectSize };

int g_pGrid[100]{};
// Declare your own functions here
void DrawGrid(const float rows, const float cols, int* pArray);
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
