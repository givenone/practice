#include <windows.h>
#include <tchar.h> //T매크로사용을 위한 헤더파일

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//함수원형 
HINSTANCE hInst; //윈헨들의 전역변수 만들기
				
LPCTSTR lpclassname = TEXT("class");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WNDCLASS WndClass;  //윈 클레스 
	HWND hWnd;			//창핸들 
	MSG Message;		//메세지루프
	hInst = hInstance;  //윈헨들 내보내기

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //배경 
	WndClass.style = CS_HREDRAW | CS_VREDRAW;    //창 조절가능 
	WndClass.hInstance = hInstance;				//메인의 핸들 
	WndClass.lpfnWndProc = (WNDPROC)WndProc;		//메세지처리함수 
	WndClass.lpszClassName = lpclassname;			//창생성에 사용될이름 
	WndClass.lpszMenuName = NULL;		//메뉴 
	WndClass.cbClsExtra = 0;			//보조영역 
	WndClass.cbWndExtra = 0;			//보조영역 
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   //커서 
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //아이콘 

	RegisterClass(&WndClass);  //메모리 올리기 
							   //창생성 
	hWnd = CreateWindow(lpclassname, TEXT("title_bar_name_test"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	//창보이기 
	ShowWindow(hWnd, nCmdShow);  //창의 핸들 ,표시방법 
								 //시스템메세지 큐에서 메세지을 읽어 메세지구조체에저장한다.
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message); //키보드메세지을 가공한다. 
		DispatchMessage(&Message);  //메세지을 메세지처리함수에게로 보낸다. 
	}
	return Message.wParam;
}
//윈프락시라 부르며 윈도우메세지의 처리 함수이다.
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	
	static BOOL ELLIPSE = FALSE;
	static HWND b2,c1;
	static BOOL MYSELLECT = FALSE;
	PAINTSTRUCT ps;

	switch (iMessage) {
	case WM_CREATE:
		CreateWindow(TEXT("button"),TEXT("Click Me"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 20, 100, 25, hWnd, (HMENU)0, hInst, NULL);
		b2=CreateWindow(TEXT("button"),TEXT("TextOut"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			20, 50, 100, 25, hWnd, (HMENU)1, hInst, NULL);
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case 0:
			MessageBox(hWnd,TEXT("First Button Clicked"),TEXT("Button"), MB_OK);
			break;
		case 1:
			SendMessage(hWnd, WM_PAINT, 1, 0);
			MYSELLECT =TRUE; 
			InvalidateRect(hWnd, NULL, TRUE);
			break;
		}
		return 0;

		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			if(MYSELLECT == TRUE)			
				TextOut(hdc, 100,80, TEXT("hello world textout"), 19);
					else	
					TextOut(hdc, 150, 80,TEXT("hello"), 5);
			EndPaint(hWnd, &ps);
			break;
				
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam));
}
