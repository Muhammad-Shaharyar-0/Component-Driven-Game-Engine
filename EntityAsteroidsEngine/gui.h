#pragma once

#include <vector>
#include <string>
#include <map>
#include "ThreadManager.h"
// Forward declaration of ImGuiContext
struct ImGuiContext;

class GUI
{
private:
    GUI(); // Private constructor to prevent direct instantiation
    GUI(const GUI&) = delete; // Disable copy constructor
    GUI& operator=(const GUI&) = delete; // Disable assignment operator
    std::shared_ptr<ThreadManager> mThreadManager = ThreadManager::Instance();
public:
    ~GUI();

    // Initialize ImGui context
    bool Initialize(HWND _hWnd, ID3D11Device* device, ID3D11DeviceContext* context);

    void Render();

    // Begin new ImGui frame
    void BeginFrame();

    // End ImGui frame
    void EndFrame();

    // Add a float variable to the GUI
    void AddFloatVariable(const std::string& name, float value);

    // Add an integer variable to the GUI
    void AddIntVariable(const std::string& name, int value);

    static GUI& GetInstance()
    {
        static GUI instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }
private:
    // ImGui context
    ImGuiContext* m_imguiContext;
    ID3D11Device* _device;
    ID3D11DeviceContext* _context;
    // Vectors to store variable names and pointers
    std::vector<std::string> m_floatVariableNames;
    std::vector<float> m_floatVariablePointers;
    std::vector<std::string> m_intVariableNames;
    std::vector<int> m_intVariablePointers;


    std::map<std::string, float> m_floatVariables;
    std::map<std::string, float> m_IntVariables;
    bool guiRendered=false;
    bool show_demo_window = true;
    bool show_another_window = false;
    //ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};
