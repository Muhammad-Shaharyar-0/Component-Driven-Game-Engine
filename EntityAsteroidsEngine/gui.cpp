#include "../EntityAsteroidsEngine/imgui/imgui.h"
#include "../EntityAsteroidsEngine/imgui/imgui_impl_dx9.h"
#include "../EntityAsteroidsEngine/imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"
#include <d3d11.h>
#include <tchar.h>
#include "GUI.h"

GUI::GUI()
    : m_imguiContext(nullptr)
{
}

GUI::~GUI()
{

    ImGui_ImplWin32_Shutdown();
    ImGui::DestroyContext();
 //   ImGui_ImplDX11_Shutdown();
}

bool GUI::Initialize(HWND _hWnd, ID3D11Device* device, ID3D11DeviceContext* context)
{
    // Create ImGui context
    m_imguiContext = ImGui::CreateContext();
    if (!m_imguiContext)
    {
        return false;
    }

    // Initialize ImGui
   // ImGui_ImplWin32_Init(NULL);

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    
    io.IniFilename = NULL;
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init(_hWnd);
    ImGui_ImplDX11_Init(device, context);


    return true;
}
void GUI::Render()
{
    while (true)
    {
        BeginFrame();

        EndFrame();

        Sleep(10);
    }

}

void GUI::BeginFrame()
{
   
    ImGui_ImplDX11_NewFrame();
    ImGui_ImplWin32_NewFrame();
    ImGui::NewFrame();
    ImGui::SetNextWindowPos({ 0, 0 });
    ImGui::Begin("Game Data");                        // Create a window called "Hello, world!" and append into it.

    // Display and update float variables
    for (const auto& [name, value] : m_floatVariables)
    {
        // Convert name to C-style string for ImGui Text
        const char* nameCStr = name.c_str();
        ImGui::Text("%s", nameCStr);

        // Use name as a unique identifier for the input box
        ImGui::InputFloat(nameCStr, &m_floatVariables[name]);
    }
    // Display and update float variables
    for (const auto& [name, value] : m_IntVariables)
    {
        // Convert name to C-style string for ImGui Text
        const char* nameCStr = name.c_str();
        ImGui::Text("%s", nameCStr);

        // Use name as a unique identifier for the input box
        ImGui::InputFloat(nameCStr, &m_IntVariables[name]);
    }
    ImGui::End();
   
}

void GUI::EndFrame()
{
    ImGui::Render();
    ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}


void GUI::AddFloatVariable(const std::string& name, float initialValue)
{
    m_floatVariables[name] = initialValue;
}

void GUI::AddIntVariable(const std::string& name, int initialValue)
{
    m_IntVariables[name] = initialValue;
}
