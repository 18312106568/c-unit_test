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
    Sleep(100);
    HWND window;
    int i;
    window = ::FindWindow(_T("Notepad"),NULL);  //���ұ���Ϊ"������"�Ĵ���
    HMENU hMenu = GetMenu(window);
    HMENU subMenu = GetSubMenu(hMenu,1);
    int menuCount = GetMenuItemCount(hMenu);
    int subMenuCount = GetMenuItemCount(subMenu);
    printf("�˵�����:%d\n",menuCount);
    TCHAR szTile[32] = {0};
    long lMenuCount=GetMenuItemCount(hMenu);
    for (i=0;i<lMenuCount;++i){
        GetMenuString(hMenu,i,szTile,sizeof(szTile)/sizeof(TCHAR),MF_BYPOSITION);
        printf("%s-%d",szTile,sizeof(szTile));
    }
    printf("\n�Ӳ˵�����%d\n",subMenuCount);
    for(i=0;i<subMenuCount;i++){
        GetMenuString(subMenu,i,szTile,sizeof(szTile)/sizeof(TCHAR),MF_BYPOSITION);
        printf("%s-%d\n",szTile,sizeof(szTile));
    }
    Sleep(100);
    printf("\n%d �Ƿ�ɹ���%d\n",LOWORD(GetMenuItemID(subMenu,0)),SendMessage(window,WM_COMMAND,GetMenuItemID(subMenu,4),NULL));

    //SendMessage(window,WM_CLOSE,0,0);              //�򴰿ڷ��͹ر�ָ��
    HWND childWindow = FindWindowEx(window,NULL,"Edit",0);
    Sleep(100);
  //  SendMessage(childWindow,WM_CHAR,WPARAM('a'),0);

//    HWND selfHwnd;
//    selfHwnd = CreateWindow(_T("Notepad"),_T("�ޱ���"),WS_OVERLAPPEDWINDOW,0,0,600,400,NULL,NULL,GetModuleHandle (0),NULL);
//    ShowWindow(selfHwnd,SW_SHOWMINNOACTIVE);
    HWND button;
    button = FindWindow(_T("Button"),_T("��ʼ"));
    //SendMessage(button,WM_RBUTTONDBLCLK,0,0);
    //SendMessage(button,WM_LBUTTONDBLCLK,0,0);
    //SendMessage(button,WM_KEYDOWN,'\x0d',0);
    //SendMessage(childWindow,WM_CLOSE,0,0);
    //printf("�Ƿ�ɹ���%d\n",SendMessage(button,WM_KEYDOWN,'\x0d',0));
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
                printf("���λ��x:%d,y:%d ���ڱ�������%s�����ڵ�����%s\n",mouse.x,mouse.y, WindowTitle,ClassName);
//                mouse_event(MOUSEEVENTF_LEFTDOWN,mouse.x,mouse.y,NULL,NULL);
//                mouse_event(MOUSEEVENTF_LEFTUP,mouse.x,mouse.y,NULL,NULL);
                pHwnd = window;
            }
        Sleep(100);
    }



    return 0;
}