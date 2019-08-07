#pragma once

#define WIN32_LEAN_AND_MEAN             // 从 Windows 头文件中排除极少使用的内容
#define _CRT_SECURE_NO_WARNINGS

// Windows 头文件
#include <windows.h>
#include <stdio.h>


__declspec(selectany) HHOOK g_hHook = NULL;

//安装钩子
extern "C" __declspec(dllexport) BOOL InstallHook();

//卸载钩子
extern "C" __declspec(dllexport) BOOL UninstallHook();

//钩子处理函数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);

