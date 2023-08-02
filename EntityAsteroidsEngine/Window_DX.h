/***************************************************/
// DX code based on http://www.directxtutorial.com //
/***************************************************/

#pragma once
#if BUILD_DIRECTX
#include "Window.h"

// include Windows and Direct3D headers
#include <windows.h>
#include <windowsx.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dx11.lib")
#pragma comment (lib, "d3dx10.lib")
#include "../EntityAsteroidsEngine/imgui/imgui.h"
#include "../EntityAsteroidsEngine/imgui/imgui_impl_dx9.h"
#include "../EntityAsteroidsEngine/imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>

// DirectX window
class Window_DX :
	public Window
{
	// Data
private:

	HWND					_hWnd;

	// Structors
public:
	// Constructor
	Window_DX(Game* game, int width, int height, HINSTANCE hInstance, int nCmdShow);

	// Destructor
	virtual ~Window_DX();


	// Functions
public:

	// Windows Message loop
	static LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);


	// Initialise window
	virtual void Initialise();
};


#endif