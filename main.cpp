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

    HMODULE hDLL = LoadLibrary("sayHello.dll"); //����dll�ļ�
    if(hDLL != NULL){
        pAdd fp1 = pAdd(GetProcAddress(hDLL, MAKEINTRESOURCE(1))); //�õ�dll�еĵ�һ������
        cout<<fp1(2.5, 5.5)<<endl;

    }
    /**
    * ��ȡϵͳĿ¼
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
//    printf(" �½��̵Ľ���ID�ţ�%d \n", pi.dwProcessId);
//    printf(" �½��̵����߳�ID�ţ�%d \n", pi.dwThreadId);

    HINSTANCE hNewExe = ShellExecute(NULL, "open", "d:\\test.txt", NULL, NULL, SW_SHOW);
//    char newExeChar[ARRLEN] = {0};
//    GetWindowText(hNewExe,newExeChar,MSIZE);

    /**
     * ͨ����������ȡ����
     */

    printf("�ַ�����%d\n", sizeof("������"));
    HWND window;
    int i;
    window = ::FindWindow(_T("Notepad"),NULL);  //���ұ���Ϊ"������"�Ĵ���
    HMENU hMenu = GetMenu(window);
    int menuCount = GetMenuItemCount(hMenu);
    printf("�˵�����:%d\n",menuCount);
    //SendMessage(window,WM_CLOSE,0,0);              //�򴰿ڷ��͹ر�ָ��
    HWND childWindow = FindWindowEx(window,NULL,"Edit",0);
    Sleep(100);
    SendMessage(childWindow,WM_CHAR,WPARAM('a'),0);
    //SendMessage(childWindow,WM_CLOSE,0,0);
    /**
     * ͨ�����λ�û�ȡ��ǰ����
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
                /*SendMessage(���ھ��,��Ϣ����,��Ϣ��������,��Ϣ��������)
                ����������ѡ������Ϣ������WM_CHAR
                ��Ϣ��������ΪWPARAM('a')
                ������Ϣ�������ݾ���ģ������򴰿�����a*/
                GetWindowText(window, WindowTitle, MSIZE);
                GetClassName(window,ClassName,MSIZE);
                printf("%s-%s\n", WindowTitle,ClassName);
                pHwnd = window;
            }
        Sleep(100);
    }



    return 0;
}