#pragma once
#include<stdio.h>
#include<graphics.h>   //图形界面库头文件
#include<math.h>       //计算圆形的轨迹坐标
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<mmsystem.h>
#pragma comment(lib,"winmm.lib")
//#include 包含头文件
//#pragma comment（lib."文件名称"）  包含库文件

#define WND_WIDTH  1000
#define WND_HEIGHT 600
#define PI         3.1415926548
#define NUM        13

/***********结构****************/
struct JET  //烟花弹
{
	int x, y;      //发射点坐标
	int hx, hy;    //最高点坐标  爆炸坐标
	int height;    //高度  最高点y 发射点y的差值
	bool isshoot;  //是否发射状态

	DWORD t1, t2, dt;   //保存时间  时间可以用来描述发射速度
	IMAGE img[2];       //保存烟花一明一暗的图片
	byte n : 1;         //保存烟花弹的明暗状态  位段
	//字节为单位 int 4 char 1 n一个位 0-1
}jet[NUM];    //结构体数组13  img这个数组

struct FIRE
{
	int r;
	int max_r;
	int x, y;
	int cen_x, cen_y;
	int width, height;
	int xy[240][240];

	bool show;
	bool draw;
	DWORD t1, t2, dt;
}fire[NUM];

void welcome();
void init(int i);
void loadimages();
void choice(DWORD& t1);
void shoot();
void Show(DWORD* pMem);
