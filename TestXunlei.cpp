//
// Created by  on 2019/1/23.
//
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<Imagehlp.h>
#include <tchar.h>
using namespace std;
int main(int argc, char *argv[]) {
     HMENU hMenu ;
     LPRECT rect;
     HWND mainHwnd = FindWindow(_T("Chrome_WidgetWin_0"),_T("Ѹ��"));
     if(mainHwnd != NULL){
//         HWND warpHwnd = FindWindowEx(mainHwnd,0,"Chrome_RenderWidgetHostHWND",0);
//         SendMessage(warpHwnd,WM_RBUTTONDBLCLK,0,0);
         SwitchToThisWindow(mainHwnd, true);
         GetWindowRect(mainHwnd,rect);
         printf("����λ��left:%d,top:%d,right:%d,bottom:%d\n",rect->left,rect->top,rect->right,rect->bottom);
         hMenu = GetMenu(mainHwnd);
         int hMenuCount = GetMenuItemCount(hMenu);
         printf("���ڲ˵��ĸ����ǣ�%d\n",hMenuCount);
     }
     return 0;
}