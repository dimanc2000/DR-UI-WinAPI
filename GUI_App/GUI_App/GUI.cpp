#include "stdafx.h"
#include <windows.h> 
//#include <commctrl.h>
#include "GUI.h"
#include "resource.h"

GUI::GUI()
{
}

GUI::GUI(int nCmd)
{
	this->nCmd = nCmd;
}

GUI::~GUI()
{
}

void GUI::AddText(const TCHAR * text) //HWND eWnd, const TCHAR* text)
{
	int ndx = GetWindowTextLength(hEdit);
#ifdef WIN32
	SendMessage(hEdit, EM_SETSEL, (WPARAM)ndx, (LPARAM)ndx);
#else
	SendMessage(hEdit, EM_SETSEL, 0, MAKELONG(ndx, ndx));
#endif
	SendMessage(hEdit, EM_REPLACESEL, 0, reinterpret_cast<LPARAM>(text));
	
	//SendMessage(eWnd, WM_SETTEXT, NULL, reinterpret_cast<LPARAM>(text));

	/*SendMessage(eWnd, EM_SETSEL, -1, -1);
	SendMessage(eWnd, EM_REPLACESEL, FALSE, reinterpret_cast<LPARAM>(text));*/

	/*SendMessage(hEdit, EM_SETSEL, -1, -1);
	SendMessage(hEdit, EM_REPLACESEL, FALSE, reinterpret_cast<LPARAM>(text));*/
}

/*
void GUI::SetText(const TCHAR* text)
{
	this->text = text;
}
*/

int GUI::OnCreate(const HWND hwnd, CREATESTRUCT *cs)
{
	//Кнопка с иконкой, которая ведёт в пункт меню "О программе"
	RECT rc_bit = { 0,0,405,75 }; // { 0,0,235,75 }
	HBITMAP hBitmap = (HBITMAP)LoadImage(cs->hInstance, MAKEINTRESOURCE(IDB_BITMAP),
		IMAGE_BITMAP, 0, 0, 0);
	HWND hBtn1 = CreateControl(L"button", L"Пуск", hwnd, 0, cs->hInstance, WS_VISIBLE | WS_CHILD | BS_BITMAP,
		rc_bit, IDC_BUTTON);
	SendMessage(hBtn1, BM_SETIMAGE, IMAGE_BITMAP, LPARAM(hBitmap));

	//Стили
	HFONT hFont1 = CreateFont(18, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Bodoni MT"));
	HFONT hFont2 = CreateFont(18, 0, 0, 0, 0, 1, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Tahoma"));

	//Text
	RECT rc_text = { 80,100,100,40 };
	HWND hBtn2 = CreateStatics(hwnd, cs->hInstance, SS_EDITCONTROL, rc_text, IDC_TEXT, _T("just a field \n with results"));

	//Edit
	RECT rc3 = { 53,145,300,170 };// { 53,145,122,40 };
	HWND hEdit = CreateEdit(hwnd, cs->hInstance, ES_MULTILINE | WS_VSCROLL, rc3, IDC_EDIT,_T(""));

	SendMessage(hEdit, WM_SETFONT, (LPARAM)hFont1, TRUE);
	this->hEdit = hEdit;

	SendMessage(hBtn2, WM_SETFONT, (LPARAM)hFont2, TRUE);

	return 0;
}

void GUI::OnSize(const HWND hwnd, int cx, int cy, UINT flags)
{
	HWND hTabCntrl = reinterpret_cast<HWND>(static_cast<LONG_PTR>
		(GetWindowLongPtr(hwnd, GWLP_USERDATA)));

	MoveWindow(hTabCntrl, 2, 2, cx - 4, cy - 4, TRUE);
}

void GUI::OnDestroy(const HWND hwnd)
{
	HWND hTabCntrl = reinterpret_cast<HWND>(static_cast<LONG_PTR>
		(GetWindowLongPtr(hwnd, GWLP_USERDATA)));

	PostQuitMessage(0);
}