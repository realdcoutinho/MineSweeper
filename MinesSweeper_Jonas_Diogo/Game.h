#pragma once
using namespace utils;
#pragma region gameInformation
// Set your name and group in the title here
std::string g_WindowTitle{ "MineSweeper - Name, firstname - 1DAExx" };


//important measures before seating the window size
const float g_Border{ 10.f }; // border measure around the window
const float g_TileSize{ 32 }; // size of each tile
const int g_Rows{ 15 }; // Nr of rows
const int g_Colums{ 15 }; // Nr of Colums
const int g_ArraySize{ g_Rows * g_Colums }; //Size of the Grid
const float g_GridWidth{ (g_Colums * g_TileSize) + g_Border * 2 }; //width of the play area
const float g_GridHeight{ (g_Rows * g_TileSize) + g_Border * 2 }; // height of the play area
const float g_HeaderHeight{ g_Border + g_TileSize * 3 }; // Height for the header

// Change the window dimensions here
float g_WindowWidth{ g_GridWidth };
float g_WindowHeight{ g_GridHeight + g_HeaderHeight};
#pragma endregion gameInformation



#pragma region ownDeclarations
// Declare your own global variables here
bool g_IsVaccine{};

const int g_nrBombs{ 10 };

//Texture
const float g_PNGTextureSize{ 256 }; // size of the textures 256 x 256 pixels
const float g_Scale{ g_PNGTextureSize / g_TileSize }; // the scale by which the textures will have to be reduced
Texture* g_tTiles{};
float g_TimeSeconds{}; //times in seconds, failed to implement as of this moment. However I changed my mind and prefer to have the time with 2 floating points

//std::strings
std::string g_Time{}; // string time to be printed

//
unsigned int g_ArrayTextureSize{8};

//Colors
Color4f g_White(1, 1, 1, 1);
Color4f g_Grey(0.5f, 0.5f, 0.5f, 1);
Color4f g_Red(1, 0, 0, 1);
Color4f g_Green(0, 1, 0, 1);
Color4f g_Blue(0, 0, 1, 1);

//Mouse Point
Point2f g_Mouse{};

//Rects
Point2f g_GridPos{g_Border, g_Border};
Rectf g_GridRect{ g_GridPos.x, g_GridPos.y, g_TileSize, g_TileSize };

//Arrays
int g_pGrid[g_ArraySize]{};
Texture g_TileTextures[12]{}; // the size of this array is a random one. 12 doesnt mean anything, just trying to test
Texture g_TextTexture[10]{}; //Arrau for the text textures. the size was completily random. just a test
int g_BombPositionArray[g_nrBombs]{};

// Declare your own functions here
void AddingTimeTexture();// Creates the time texture
void DrawTimeTexture(Texture* pArray, Point2f point, int idx); // Draws the Time texture

void AddingTextures();// Creates the visual textures

void BombPosition();
void DrawBom();

void PrintArray(int* pArray, int size);



void ClickTile(Point2f MousePoint); // checks which Tile was pressed
void DrawGrid(); //Draws the Tiles Including the pressed ones
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns); // gets the index for the tile position
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
