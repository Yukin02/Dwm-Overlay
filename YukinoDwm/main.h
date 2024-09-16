#pragma once
#include <Windows.h>
#include <d3d11.h>
#include <dxgi.h>
#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_dx11.h"
#include "ImGui/imgui_impl_win32.h"

#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3d11.lib")

static ID3D11Device* g_pd3dDevice = 0;

static ID3D11DeviceContext* g_pd3dDeviceContext = 0;

static ID3D11RenderTargetView* g_mainRenderTargetView = 0;

extern "C" UINT64 PresentCall;