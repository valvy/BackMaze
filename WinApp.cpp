//
//  WinApp
//  BackMaze
//
//  Created by Heiko van der Heijden on 06-03-15.
//  Copyright (c) 2015 Heiko van der Heijden. All rights reserved.
//
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include "Application.hpp"
#include <windows.h>



WNDCLASSEX wc;
HWND hwnd;
MSG Msg;
const char g_szClassName[] = "myWindowClass";
HDC g_HDC;
HINSTANCE hInstance;
int nCmdShow = 1;
Application* app;

void SetupPixelFormat(HDC hDC)
{
    int nPixelFormat;
    
    static PIXELFORMATDESCRIPTOR pfd = {
        sizeof(PIXELFORMATDESCRIPTOR),
        1,
        PFD_DRAW_TO_WINDOW |
        PFD_SUPPORT_OPENGL |
        PFD_DOUBLEBUFFER,
        PFD_TYPE_RGBA,
        32,
        0, 0, 0, 0, 0, 0,
        0,
        0,
        0,
        0, 0, 0, 0,
        16,
        0,
        0,
        PFD_MAIN_PLANE,
        0,
        0, 0, 0 };
    
    nPixelFormat = ChoosePixelFormat(hDC, &pfd);

    SetPixelFormat(hDC, nPixelFormat, &pfd);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    static HGLRC	hRC;
    static HDC	hDC;
    switch(msg)
    {
        case WM_KEYDOWN:
            switch (wParam) {
                case VK_SPACE:
                    app->OnKeyDown(SPACE_BAR);
                    break;
                case VK_ESCAPE:
                    app->OnKeyDown(ESCAPE_KEY);
                    break;
                case VK_EXECUTE:
                    app->OnKeyDown(ENTER_KEY);
                    break;
                case 0x053:
                    app->OnKeyDown(S_KEY);
                    break;
                default:
                    break;
            }
            ;
            break;
        case WM_CREATE:
            
            hDC = GetDC(hwnd);
            g_HDC = hDC;
            SetupPixelFormat(hDC);
            hRC = wglCreateContext(hDC);
            wglMakeCurrent(hDC,hRC);
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            wglMakeCurrent(hDC, nullptr);
            wglDeleteContext(hRC);
            break;
        case WM_DESTROY:
            wglMakeCurrent(hDC,nullptr);
            wglDeleteContext(hRC);
            PostQuitMessage(0);
            break;
            
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}


Application::Application(){
    app = this;
    wc.cbSize        = sizeof(WNDCLASSEX);
    wc.style         = 0;
    wc.lpfnWndProc   = WndProc;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.hInstance     = GetModuleHandle(nullptr);
    wc.hIcon         = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(nullptr, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName  = nullptr;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm       = LoadIcon(nullptr, IDI_APPLICATION);
    
    if(!RegisterClassEx(&wc))
        return;
    
    hwnd = CreateWindowEx(
                          WS_EX_CLIENTEDGE,
                          g_szClassName,
                          "Back Maze",
                          WS_OVERLAPPED | WS_CAPTION | WS_DLGFRAME | WS_MINIMIZEBOX | WS_SYSMENU,
                          CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
                          nullptr, nullptr, hInstance, nullptr);
    
    if(hwnd == nullptr)
        return;
    
}

void Application::StartApp(){
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);
    
    // Step 3: The Message Loop
    while(true)
    {
        //GetMessage(&Msg, nullptr,0,0);
        PeekMessage(&Msg, nullptr,0,0,PM_REMOVE);
        
        if(WM_QUIT == Msg.message){
            return;
        }
        
        if((GetKeyState(VK_LBUTTON) & 0x100) != 0){
            POINT p;
            if(GetCursorPos(&p)){
                if(ScreenToClient(hwnd, &p)){
                    const unsigned short Y_OFFSET = 20;
                    app->OnMouseDown(p.x,-(p.y - WINDOW_HEIGHT + Y_OFFSET));
                }
            }
        }
        
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);
        this->Update();
        glFlush();
        SwapBuffers(g_HDC);
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
        
    }
}

void Application::OnMouseDown(float x, float y){
    //virtual
}

void Application::OnKeyDown(unsigned short keycode){
    //virtual
}

void Application::Update(){
    //virtual
}

void Application::ExitApp(){
    
}

Application::~Application(){
    
}

#endif
