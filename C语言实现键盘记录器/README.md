## C语言实现键盘记录器
开发语言：C

开发工具：Visual Studio 2019

开发时间：2019.8.7

开发者：Summer

参考课程：[C/C++黑客技术：键盘记录器……](https://www.bilibili.com/video/av56195928?from=search&seid=8623392146810887085)

项目源码参考：[C语言实现键盘记录器-源码](https://github.com/zz2summer/C-CPP-Programs/tree/master/C%E8%AF%AD%E8%A8%80%E5%AE%9E%E7%8E%B0%E9%94%AE%E7%9B%98%E8%AE%B0%E5%BD%95%E5%99%A8)

***

一、编写Crack.dll钩子，记录键盘操作

&emsp;&emsp;源码参考：[Crack](https://github.com/zz2summer/C-CPP-Programs/tree/master/C%E8%AF%AD%E8%A8%80%E5%AE%9E%E7%8E%B0%E9%94%AE%E7%9B%98%E8%AE%B0%E5%BD%95%E5%99%A8/Crack)

二、编写使用程序 CrackPassword

&emsp;&emsp;源码参考：[CrackPassword](https://github.com/zz2summer/C-CPP-Programs/tree/master/C%E8%AF%AD%E8%A8%80%E5%AE%9E%E7%8E%B0%E9%94%AE%E7%9B%98%E8%AE%B0%E5%BD%95%E5%99%A8/CrackPassword)

三、使用说明

&emsp;&emsp;双击运行**CrackPassword\Release\CrackPassword.exe**，会弹出运行窗口，之后即会记录所有键盘操作，生成文件**CrackPassword.dat**,保存在**C盘根目录下**，保存内容包含键盘操作的**窗口的标题**和**键盘输入**。

![Alt](runWidget.png#pic_center)

![Alt](saveFile.png#pic_center)

&emsp;&emsp;文件保存目录可在Crack\Crack.cpp中39行进行自定义修改。
```c
FILE* pFile = fopen("C:\\CrackPassword.dat", "a+");
```

&emsp;&emsp;程序运行的显示窗口可在CrackPassword\CrackPassword.cpp中56行进行设置显示或者隐藏。
```c
//ShowWindow(hWnd, SW_HIDE);	//隐藏程序运行窗口
ShowWindow(hWnd, SW_SHOW);		//显示程序运行窗口
```