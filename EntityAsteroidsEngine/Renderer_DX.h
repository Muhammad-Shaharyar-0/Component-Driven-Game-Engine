#pragma once
#if BUILD_DIRECTX
#include <windows.h>
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dx10.h>
#include <DirectXMath.h>
#include <array>
#include <chrono>
#include "Renderer.h"
#include "CameraComponent.h"
#include "FrequencyValues.h"
#include "ThreadManager.h"
#include "ResourceManager.h"
#include "gui.h"

typedef struct ConstantBuffer
{
	DirectX::XMFLOAT4X4 MVM;
	DirectX::XMFLOAT4X4 mWorld;
	DirectX::XMFLOAT4X4 mView;
	DirectX::XMFLOAT4X4 mProj;
	DirectX::XMFLOAT4 mCameraPosition;
	DirectX::XMFLOAT4 mColour;
	DirectX::XMFLOAT4 Colour;
}ConstantBuffer;

// DirectX Device & Context
class Renderer_DX :
	public Renderer
{
	// Data
protected:
	IDXGISwapChain*			_swapchain;             // the pointer to the swap chain interface
	ID3D11Device*			_device;                // the pointer to our Direct3D device interface
	ID3D11DeviceContext*	_context;				// the pointer to our Direct3D device context
	ID3D11RenderTargetView* _backbuffer;			// the pointer to our back buffer
	ID3D11InputLayout*		_layout;				// the pointer to the input layout
	ID3D11VertexShader*		_vertexShader;			// the pointer to the vertex shader
	ID3D11PixelShader*		_pixelShader;			// the pointer to the pixel shader
	ID3D11Buffer*			_ConstantBuffer;			// Stores the MVM and colour
	HWND					_hWnd;					// Window handle
	ConstantBuffer mCB{};
	Mesh* currentMesh=nullptr;
	std::shared_ptr<ThreadManager> mThreadManager = ThreadManager::Instance();
	std::shared_ptr<ResourceManager> mResourceManager = ResourceManager::Instance();
	
	std::chrono::nanoseconds mDeltaTime{};
	std::chrono::high_resolution_clock::time_point mStartTime;
	std::chrono::high_resolution_clock::time_point mCurrentTime;
	std::chrono::high_resolution_clock::time_point mPreviousTime;

	int mActualFrequency{};
	double mAverageDeltaTime = 0;
	double mTargetDeltaTime = 0;
	std::array<double, 50> mLast50Frames;
	double sleepTime;
	std::mutex mx;

	GUI* g = &GUI::GetInstance();


	// Structors
public:
	Renderer_DX(HWND hWnd);
	virtual ~Renderer_DX();

	// Gets/Sets
public:
	ID3D11Device* GetDevice()					const	{ return _device; }
	void SetDevice(ID3D11Device* v)						{ _device = v; }

	ID3D11DeviceContext* GetContext()			const	{ return _context; }
	void SetContext(ID3D11DeviceContext* v)				{ _context = v; }

	// Functions
public:

	virtual void ClearScreen();
	virtual void Destroy();
	virtual void Draw(Mesh* mesh, glm::mat4 MVM, const Colour& colour);
	void CalculateFreq();
	void RenderLoop();
	void SetViewProj(CameraComponent* camera);
	virtual void Initialise(int width, int height);
	virtual void SwapBuffers();

	// Initialise the shaders
	void InitialiseShaders();

};

#endif