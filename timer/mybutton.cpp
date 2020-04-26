#include <windows.h>
#include <tchar.h> //T��ũ�λ���� ���� �������

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);//�Լ����� 
HINSTANCE hInst; //������� �������� �����
				
LPCTSTR lpclassname = TEXT("class");

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WNDCLASS WndClass;  //�� Ŭ���� 
	HWND hWnd;			//â�ڵ� 
	MSG Message;		//�޼�������
	hInst = hInstance;  //����� ��������

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); //��� 
	WndClass.style = CS_HREDRAW | CS_VREDRAW;    //â �������� 
	WndClass.hInstance = hInstance;				//������ �ڵ� 
	WndClass.lpfnWndProc = (WNDPROC)WndProc;		//�޼���ó���Լ� 
	WndClass.lpszClassName = lpclassname;			//â������ �����̸� 
	WndClass.lpszMenuName = NULL;		//�޴� 
	WndClass.cbClsExtra = 0;			//�������� 
	WndClass.cbWndExtra = 0;			//�������� 
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);   //Ŀ�� 
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION); //������ 

	RegisterClass(&WndClass);  //�޸� �ø��� 
							   //â���� 
	hWnd = CreateWindow(lpclassname, TEXT("title_bar_name_test"), WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);
	//â���̱� 
	ShowWindow(hWnd, nCmdShow);  //â�� �ڵ� ,ǥ�ù�� 
								 //�ý��۸޼��� ť���� �޼����� �о� �޼�������ü�������Ѵ�.
	while (GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message); //Ű����޼����� �����Ѵ�. 
		DispatchMessage(&Message);  //�޼����� �޼���ó���Լ����Է� ������. 
	}
	return Message.wParam;
}
//�������ö� �θ��� ������޼����� ó�� �Լ��̴�.
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
