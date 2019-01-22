#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<Imagehlp.h>
#include <tchar.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define ARRLEN 100
#define MSIZE 99
int main(int argc, char *argv[]) {
    typedef void (*FUNT)(int);
    HINSTANCE Hint = LoadLibrary("sayHello.dll");
    FUNT sayHello = (FUNT) GetProcAddress(Hint,"sayHello");
    FUNT helloWorld = (FUNT) GetProcAddress(Hint,"HelloWorld");
//	cout<<123<<endl;

    sayHello(1);
    cout<<endl;
//	helloWorld();

    typedef double (*pAdd)(int a, double b);
    typedef double (*pSubtract)(double a, double b);

    HMODULE hDLL = LoadLibrary("sayHello.dll"); //加载dll文件
    if(hDLL != NULL){
        pAdd fp1 = pAdd(GetProcAddress(hDLL, MAKEINTRESOURCE(1))); //得到dll中的第一个函数
        cout<<fp1(2.5, 5.5)<<endl;

    }
    /**
    * 获取系统目录
    */
//    char systemDirectory[ARRLEN] ={0};
//    GetSystemDirectory(systemDirectory,MSIZE);
//    cout<<systemDirectory<<endl;
//    STARTUPINFO si;
//    PROCESS_INFORMATION pi;
//    BOOL bRet;
//    ZeroMemory(&si, sizeof(si));
//    si.cb = sizeof(si);
//    ZeroMemory(&pi, sizeof(pi));
//    bRet = CreateProcess(NULL,"calc.exe",0,0,true,CREATE_SUSPENDED,NULL,NULL,&si,&pi);
//    cout<<(int)bRet<<endl;
//    printf(" 新进程的进程ID号：%d \n", pi.dwProcessId);
//    printf(" 新进程的主线程ID号：%d \n", pi.dwThreadId);

    HINSTANCE hNewExe = ShellExecute(NULL, "open", "d:\\test.txt", NULL, NULL, SW_SHOW);
//    char newExeChar[ARRLEN] = {0};
//    GetWindowText(hNewExe,newExeChar,MSIZE);

    /**
     * 通过窗口名获取窗口
     */

    printf("字符长度%d\n", sizeof("计算器"));
    HWND window;
    int i;
    window = ::FindWindow(_T("Notepad"),NULL);  //查找标题为"计算器"的窗口
    HMENU hMenu = GetMenu(window);
    int menuCount = GetMenuItemCount(hMenu);
    printf("菜单个数:%d\n",menuCount);
    //SendMessage(window,WM_CLOSE,0,0);              //向窗口发送关闭指令
    HWND childWindow = FindWindowEx(window,NULL,"Edit",0);
    Sleep(100);
    SendMessage(childWindow,WM_CHAR,WPARAM('a'),0);
    //SendMessage(childWindow,WM_CLOSE,0,0);
    /**
     * 通过鼠标位置获取当前窗口
     */
    POINT mouse;
    HWND pHwnd;
    char WindowTitle[ARRLEN]={0};
    char ClassName[ARRLEN] = {};
    while (1) {
            GetCursorPos(&mouse);
            HWND window;
            window = WindowFromPoint(mouse);
            if (pHwnd != window) {
                /*SendMessage(窗口句柄,消息类型,消息附带内容,消息附带内容)
                比如我这里选定的消息类型是WM_CHAR
                消息附带内容为WPARAM('a')
                所以消息附带内容就是模拟键盘向窗口输入a*/
                GetWindowText(window, WindowTitle, MSIZE);
                GetClassName(window,ClassName,MSIZE);
                printf("%s-%s\n", WindowTitle,ClassName);
                pHwnd = window;
            }
        Sleep(100);
    }



    return 0;
}