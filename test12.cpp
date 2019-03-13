#include "stdafx.h"  
#include "resource.h"    
  
HINSTANCE hInst;  
  
LRESULT MainDlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam);  
  
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int nCmdShow)  
{  
     MSG msg;  
     HWND hDlg = NULL;  
   
     hInst = hInstance;  
     hDlg = CreateDialog(hInstance, (LPCTSTR)IDD_DIALOG1, 0,(DLGPROC)CallMainDlgProc);  
     ShowWindow(hMainDlg, nCmdShow);  
     while (GetMessage(&msg, NULL, 0, 0))  
     {  
         TranslateMessage(&msg);  
         DispatchMessage(&msg);  
     }  
     return 0;  
}  
LRESULT MainDlgProc(HWND hDlg, UINT Msg, WPARAM wParam, LPARAM lParam)  
{  
     switch (Msg)  
     {  
     case WM_CLOSE:   
         DestroyWindow(hDlg);   
         return TRUE;  
         break;  
     case WM_DESTROY:   
         PostQuitMessage(0);   
         return TRUE;  
     };  
   
     return FALSE;//返回FALSE给缺省对话框函数DefDlgProc(),表示没有处理本消息  
}  