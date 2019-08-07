/**************************
 * C++实现Windows关机，注销，重启
 * 开发工具 Visual Studio
 * 开发者：summer
 * 开发时间：2019.05.18
 * **************************/
#include <iostream>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include <ctype.h>

using namespace std;

//提升进程权限
bool improvePv()
{
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    //打开当前进程的权限令牌
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ALL_ACCESS, &hToken)) 
        return false;

    //获得某一特定权限的权限标识LUID，保存在tkp中
    //查看里面的权限
    //第一个参数：NULL表示要查看的是当前本地系统
    //第二个参数：指定特权名称
    //第三个参数：用来接收返回的特权名称信息
    if (!LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid)) 
        return false;

    //设置特权数组的个数
    tkp.PrivilegeCount = 1;
    //SE_PRIVILEGE_ENABLE_BY_DEFAULT    特权默认启动
    //SE_PRIVILEGE_ENABLED              特权启动
    //SE_PRIVILEGE_USER_FOR_ACCESS      用来访问一个对象或者服务
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;    //特权启动
    
    //调用AdjustTokenPrivileges来提升我们需要的系统权限
    //修改令牌的权限
    //第一个参数：调整特权的句柄
    //第二个参数：禁止所有权限表示
    if (!AdjustTokenPrivileges(hToken, FALSE, &tkp, NULL, NULL, NULL)) 
        return false;

    return true;
}

//关机
bool powerOffProc()
{
    if (!improvePv() || !ExitWindowsEx(EWX_POWEROFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) 
        return false;
    return true;
}

//注销
bool logOffProc()
{
    if (!improvePv() || !ExitWindowsEx(EWX_LOGOFF | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) 
        return false;
    return true;
}

//重启
bool reBootProc()
{
    if (!improvePv() || !ExitWindowsEx(EWX_REBOOT | EWX_FORCE, SHTDN_REASON_MAJOR_APPLICATION)) 
        return false;
    return true;
}

int main(void)
{
    char ch;
    printf("******************************************\n*\n");
    printf("* 1. Power_Off\n*\n");
    printf("* 2. Log_Off\n*\n");
    printf("* 3. ReBoot\n*\n");
    printf("******************************************\n");
    ch = getch();
    while (1){
        switch (ch){
            case '1':
                if (!powerOffProc()){
                    printf("Process Error!\n");
                    continue;
                }
                return 0;
            case '2':
                if (!logOffProc()){
                    printf("Process Error!\n");
                    continue;
                }
                return 0;
            case '3':
                if (!reBootProc()){
                    printf("Process Error!\n");
                    continue;
                }
                return 0;
            default:
                printf("Error!\n");
            }
    }
    system("pause");
    return 0;
}