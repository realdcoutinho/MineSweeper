#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "Project name - Name, firstname - 1DAExx" };




const float g_Border{ 10.f };
const float g_MineSize{ 32 };
const int g_Rows{ 10 };
const int g_Colums{ 10 };
const int g_ArraySize{ g_Rows * g_Colums };
const float g_PlaySizeWidth{ (g_Colums * g_MineSize) + g_Border * 2 };
const float g_PlaySizeHeight{ (g_Rows * g_MineSize) + g_Border * 2 };
const float g_HeaderHeight{ g_Border + 60 };
// Change the window dimensions here
float g_WindowWidth{ g_PlaySizeWidth };
float g_WindowHeight{ g_PlaySizeHeight + g_HeaderHeight};
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
Texture* g_tTiles{};
unsigned int g_ArrayTextureSize{8};

//Colors
Color4f g_White(1, 1, 1, 1);
Color4f g_Grey(0.5f, 0.5f, 0.5f, 1);
Color4f g_Red(1, 0, 0, 1);
Color4f g_Green(0, 1, 0, 1);
Color4f g_Blue(0, 0, 1, 1);


Point2f g_Mouse{};



Rectf g_PlayRect{ g_Border, g_Border, g_WindowWidth - g_Border * 2, g_WindowHeight - g_WindowHeight / 5 };
Rectf g_BorderRect{ g_Border, g_Border, g_WindowWidth - g_Border * 2, g_WindowHeight - g_Border * 2 };






Point2f g_RectPos{g_Border, g_Border};
Rectf g_GridRect{ g_RectPos.x, g_RectPos.y, g_MineSize, g_MineSize };

int g_pGrid[g_ArraySize]{};
// Declare your own functions here
void ToggleCell(Point2f MousePoint);
void DrawGrid();
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);
//void DrawGrid(const float rows, const float cols, int* pArray);
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
