#include <windows.h>

LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);
#define _WIN32_WINNT 0x0A00
#define IDBUTTON 102

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "mingw.thread.h"

using namespace std;
clock_t timenow;
void do_something(float t, ofstream &out)
{
    POINT p;
    int cnt = 1;
    char temp[1000];
    //ofstream out = ofstream(argv[1]);
    timenow = clock();
    while(1)
    {
        clock_t tt = clock();
        printf("%d\n", timenow - tt);
        timenow = tt;
        if (GetCursorPos(&p))
        {
            sprintf(temp, "%d, %d, %d", cnt++, p.x, p.y);
            out << temp << endl;
        }
        //cout << temp;        
        Sleep(t * 1000);
    }
    std::cout << "I am doing something" << std::endl;
}

void doit()
{

    float time = atof("0.01");
    string path = string("test");
    path = path + ".csv";
    ofstream out(path);
    
    do_something(time, out);
}


/* 클래스 이름을 전역 변수로 생성 */
TCHAR szClassName[] = TEXT("MyFirstProgram");
HINSTANCE g_hInst;

int WINAPI WinMain (HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpCmdLine,
                    int nCmdShow)
{
  HWND hWnd;                    /* 윈도우를 위한 처리기 */
  MSG msg;                      /* 프로그램에 전송된 메시지가 저장 */
  WNDCLASSEX wcex;              /* windowclass를 위한 자료 구조체 */

  /* 윈도우 구조체 */
  g_hInst = hInstance;
  wcex.hInstance = hInstance;
  wcex.lpszClassName = szClassName;
  wcex.lpfnWndProc = WndProc;   /* 이 함수는 윈도우에 의해 호출됩니다 */
  wcex.style = CS_DBLCLKS;      /* 더블 클릭을 잡아냄 */
  wcex.cbSize = sizeof (WNDCLASSEX); 

  /* 기본 아이콘과 포인터 사용 */
  wcex.hIcon = LoadIcon (NULL, IDI_APPLICATION); 
  wcex.hIconSm = LoadIcon (NULL, IDI_APPLICATION); 
  wcex.hCursor = LoadCursor (NULL, IDC_ARROW); 
  wcex.lpszMenuName = NULL;     /* 메뉴 사용안함 */
  wcex.cbClsExtra = 0;          /* 윈도우 클래스 뒤에 여우 바이트 없음 */
  wcex.cbWndExtra = 0;          /* 윈도우 인스턴스 또는 구조체 */
  /* 창의 배경으로 윈도우의 기본 색상 사용 */
  wcex.hbrBackground = (HBRUSH)(COLOR_BTNFACE+1);

  /* 윈도우 클래스 등록. 실패 시 프로그램 종료 */
  if (!RegisterClassEx (&wcex))
    return 0;

  /* 클래스는 등록되었다. 이제 프로그램을 만들자 */
  hWnd = CreateWindowEx (0,     /* 변화를 위한 확장 가능성 */
    szClassName,                /* 클래스 이름 */
    TEXT("MyFirstProgram v1.0.0.0"),  /* 제목 */
    WS_OVERLAPPEDWINDOW,        /* 기본 창 */
    CW_USEDEFAULT,              /* 프로그램이 화면에 표시 될 때의 */
    CW_USEDEFAULT,              /* 윈도우 위치 선언 */
    500,                        /* 프로그램 너비와 */
    200,                         /* 높이 (pixel 단위) */
    HWND_DESKTOP,               /* 이 창은 바탕화면의 자식 창이다 */
    NULL,                       /* 메뉴 없음 */
    hInstance,                  /* 프로그램 인스턴스 처리 */
    NULL);                      /* 윈도우 생성 자료 없음 */

  /* 윈도우를 화면에 보이게 */
  ShowWindow (hWnd, SW_SHOW);
  UpdateWindow(hWnd);

  /* 메시지 순환 실행. GetMessage()가 0을 반환 할 때 까지 작동 */
  while (GetMessage (&msg, NULL, 0, 0))
  {
    /* 가상의 키 메시지를 문자 메시지로 해석 */
    TranslateMessage(&msg);
    /* 메시지를 WndProc으로 전송 */
    DispatchMessage(&msg);
  }
  /* 프로그램 반환 값은 0 입니다. (PostQuicMessage()에서 받은 값) */
  return msg.wParam;
}

LRESULT CALLBACK WndProc (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
  HWND hWndButton, tmp; 
  switch (message) {        /* 모든 윈도우 메시지를 처리 */
    case WM_COMMAND: {
      if (((HWND)lParam) && (HIWORD(wParam) == BN_CLICKED)) {
        int iMID; 
        iMID = LOWORD(wParam); 
        thread t1;
        switch(iMID) {
          case IDBUTTON: {
            t1 = thread(doit);
            MessageBox(hWnd, TEXT("Hi"), TEXT("Hello"), MB_OK|MB_ICONEXCLAMATION); 
            break; 
            }
          case 103 : 
            {
                //t1.interrupt();
                PostQuitMessage (0);  /* 메시지 처리기에 프로그램을 종료하라는 WM_QUIT를 보냄 */
                break; 
            } 
          default: 
            break; 
        }
      }
      break; 
    } 
    case WM_DESTROY: {
      PostQuitMessage (0);  /* 메시지 처리기에 프로그램을 종료하라는 WM_QUIT를 보냄 */
      break; 
      }

    case WM_CREATE: {
      hWndButton = CreateWindowEx(0,  /* 더 또는  '확장된' 모양 */
        TEXT("BUTTON"),             /* 만들고픈 GUI '클래스' */
        TEXT("Click to Start"),          /* GUI 자막(Caption) */
        WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON, /* 컨트롤 모양은 |로 분할 */
        10,                         /* 좌측 위치 (좌측으로부터의 위치) */
        10,                         /* 상단 위치 (상단으로부터의 위치) */
        200,                        /* 컨트롤의 너비 */
        30,                         /* 컨트롤의 높이 */
        hWnd,                       /* 부모 창 처리 */
        (HMENU)IDBUTTON,            /* WM_COMMAND를 위한 컨트롤의 ID */
        g_hInst,                    /* 응용프로그램 인스턴스 */
        NULL);
        
        tmp = CreateWindowEx(0,  /* 더 또는  '확장된' 모양 */
    TEXT("BUTTON"),             /* 만들고픈 GUI '클래스' */
    TEXT("Click to Stop"),          /* GUI 자막(Caption) */
    WS_CHILD|WS_VISIBLE|BS_DEFPUSHBUTTON, /* 컨트롤 모양은 |로 분할 */
    10,                         /* 좌측 위치 (좌측으로부터의 위치) */
    50,                         /* 상단 위치 (상단으로부터의 위치) */
    200,                        /* 컨트롤의 너비 */
    30,                         /* 컨트롤의 높이 */
    hWnd,                       /* 부모 창 처리 */
    (HMENU)103,            /* WM_COMMAND를 위한 컨트롤의 ID */
    g_hInst,                    /* 응용프로그램 인스턴스 */
    NULL);    
      break; 
      }
    default:             /* 작동하지 않았을 때의 메시지 */
      return DefWindowProc (hWnd, message, wParam, lParam); 
  }

  return 0;
}