// GUI_App.cpp: Определяет точку входа для приложения.
//

#include "stdafx.h"
#include <windows.h> 
#include "GUI_App.h"
#include "Ui.h"

#include "Header.h"

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR pStr, int nCmd)
{
	LoadStringW(hInst, IDI_GUIAPP, szWindowClass, MAX_LOADSTRING);

	MyRegisterClass(hInst);
	hInstance = hInst;				// Сохранить дескриптор экземпляра в глобальной переменной

	Gui = GUI(nCmd);

	int desktopwidth = GetSystemMetrics(SM_CXSCREEN);
	int desktopheight = GetSystemMetrics(SM_CYSCREEN);
	HWND hwnd = CreateWindowEx(0,                        // extended styles
		classname.c_str(),         // name: wnd 'class'
		_T("App"), // wnd title
		WS_OVERLAPPEDWINDOW,       // wnd style
		desktopwidth / 4,          // position:left
		desktopheight / 4,         // position: top
		420,          // width (250)
		400,         // height (310)
		0,                         // parent wnd handle
		0,                         // menu handle/wnd id
		hInst,                     // app instance
		0);                        // user defined info

	Gui.hwnd = hwnd;

	if (!hwnd)
	{
		ErrMsg(_T("Failed to create wnd"));
		return -1;
	}

	Ui::Run(Gui);

	MSG msg;

	Ui::Stop(Gui);
	Ui::Poll(Gui);

	int state = 0;
	Ui::SetState(Gui, state);
	
	std::string password = "time";
	Ui::ShowPassword(Gui, password);
	
	std::vector<Technician> technicians;
	Ui::UpdateTechnicianList(Gui, technicians);

	int tid = 0;
	Ui::SetSelectionTechnician(Gui, tid);
	std::string message;
	Ui::ShowTechnicianMessage(Gui, tid, message);

	Ui::ShowSessionConfirmMessage(Gui);
	Ui::RemoveSessionConfirmMessage(Gui);
	Ui::ClearChatView(Gui);

	while (GetMessage(&msg, 0, 0, 0)>0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcx = { 0 };

	wcx.cbSize = sizeof(WNDCLASSEX);

	wcx.style = CS_HREDRAW | CS_VREDRAW;
	wcx.lpfnWndProc = WndProc;
	wcx.cbClsExtra = 0;
	wcx.cbWndExtra = 0;
	wcx.hInstance = hInstance;
	wcx.hIcon = reinterpret_cast<HICON>(LoadImage(0, IDI_APPLICATION, IMAGE_ICON, 0, 0, LR_SHARED));
	wcx.hCursor = reinterpret_cast<HCURSOR>(LoadImage(0, IDC_ARROW, IMAGE_CURSOR, 0, 0, LR_SHARED));
	wcx.hbrBackground = reinterpret_cast<HBRUSH>(COLOR_BTNFACE + 1);
	wcx.lpszClassName = classname.c_str();

	return RegisterClassEx(&wcx);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CTLCOLOREDIT:
	{
		SetTextColor((HDC)wParam, RGB(0, 210, 0));
		return 0;
	}
	case WM_CREATE:
	{
		return Gui.OnCreate(hwnd, reinterpret_cast<CREATESTRUCT*>(lParam));
	}

	case IDM_STOP:
		Gui.AddText(_T("Ui::Stop() - Completed\r\n"));
		break;
	case IDM_POLL:
		Gui.AddText(_T("Ui::Poll() - Completed\r\n"));
		break;
	case IDM_SS:
		Gui.AddText(_T("Ui::SetState() - Completed\r\n"));
		break;
	case IDM_SP:
		Gui.AddText(_T("Ui::ShowPassword() - Completed\r\n"));
		break;
	case IDM_UTL:
		Gui.AddText(_T("Ui::UpdateTechnicianList() - Completed\r\n"));
		break;
	case IDM_SST:
		Gui.AddText(_T("Ui::SetSelectionTechnician() - Completed\r\n"));
		break;
	case IDM_STM:
		Gui.AddText(_T("Ui::ShowTechnicianMessage() - Completed\r\n"));
		break;
	case IDM_SSCM:
		Gui.AddText(_T("Ui::ShowSessionConfirmMessage() - Completed\r\n"));
		break;
	case IDM_RSCM:
		Gui.AddText(_T("Ui::RemoveSessionConfirmMessage() - Completed\r\n"));
		break;
	case IDM_CCV:
		Gui.AddText(_T("Ui::ClearChatView() - Completed\r\n"));
		break;

	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDC_BUTTON:
			DialogBox(0, MAKEINTRESOURCE(IDD_ABOUTBOX), hwnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hwnd);
			break;
		default:
			return DefWindowProc(hwnd, uMsg, wParam, lParam);
		}
	}
	break;
	case WM_DESTROY:
	{
		Gui.OnDestroy(hwnd);
		return 0;
	}
	case WM_SIZE:
	{
		Gui.OnSize(hwnd, LOWORD(lParam), HIWORD(lParam), static_cast<UINT>(wParam));
		return 0;
	}
	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}
}

INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}