#ifndef UNICODE
    #define  UNICODE
#endif
#ifndef _UNICODE
    #define  _UNICODE
#endif
#include <windows.h>
#define IDC_BUTTONS  1500


LRESULT CALLBACK fnWndProc(HWND hwnd, unsigned int msg, WPARAM wParam, LPARAM lParam)
{
 switch(msg)
 {
   case WM_CREATE:
    {
       HINSTANCE hIns=((LPCREATESTRUCT)lParam)->hInstance;
       wchar_t szBuffer[64], szTmp[16];
       for(size_t i=0; i<10; i++)
       {
           wcscpy(szBuffer,L"Program Activity #");
           wsprintf(szTmp,L"%u",i+1),  wcscat(szBuffer,szTmp);
           CreateWindowEx(0,L"button",L"",WS_CHILD|WS_VISIBLE,25,15+30*i,40,25,hwnd,(HMENU)(IDC_BUTTONS+i),hIns,0);
           CreateWindowEx(0,L"static",szBuffer,WS_CHILD|WS_VISIBLE,75,20+30*i,200,25,hwnd,(HMENU)-1,hIns,0);
           memset(szBuffer,0,64);
       }
       return 0;
    }
   case WM_COMMAND:
    {
        if(LOWORD(wParam)>=IDC_BUTTONS && LOWORD(wParam)<IDC_BUTTONS+10)
        {
           if(HIWORD(wParam)==BN_CLICKED)
           {
              int iCtrlId=LOWORD(wParam);
              iCtrlId=iCtrlId-IDC_BUTTONS+1;
              wchar_t szBuffer[64], szTmp[16];
              wcscpy(szBuffer,L"You Want Program Activity #");
              wsprintf(szTmp,L"%d",iCtrlId);
              wcscat(szBuffer,szTmp);
              MessageBox(hwnd,szBuffer,L"Button Click Report",MB_OK);
           }
        }
        return 0;
    }
   case WM_DESTROY:
    {
       PostQuitMessage(0);
       return 0;
    }
 }

 return (DefWindowProc(hwnd, msg, wParam, lParam));
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevIns, LPSTR lpszArgument, int iShow)
{
 TCHAR szClassName[]=L"Form1";
 WNDCLASSEX wc={};
 MSG messages;
 HWND hWnd;

 wc.lpszClassName = szClassName;
 wc.lpfnWndProc   = fnWndProc;
 wc.cbSize        = sizeof(WNDCLASSEX);
 wc.hbrBackground = (HBRUSH)COLOR_BTNSHADOW;
 wc.hInstance     = hInstance;
 RegisterClassEx(&wc);
 hWnd=CreateWindowEx(0,szClassName,L"Only Three CreateWindowqEx() Calls",WS_OVERLAPPEDWINDOW,150,150,350,360,HWND_DESKTOP,0,hInstance,0);
 ShowWindow(hWnd,iShow);
 while(GetMessage(&messages,NULL,0,0))
 {
    TranslateMessage(&messages);
    DispatchMessage(&messages);
 }

 return messages.wParam;
}