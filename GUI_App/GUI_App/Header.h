#pragma once

#include <windows.h> 
#include <vector>
#include "GUI.h"

enum {
	IDC_BUTTON = 200,
	IDC_EDIT,
	IDC_TEXT,
	IDM_STOP,
	IDM_POLL,
	IDM_SS,
	IDM_SP,
	IDM_UTL,
	IDM_SST,
	IDM_STM,
	IDM_SSCM,
	IDM_RSCM,
	IDM_CCV
};

typedef std::basic_string<TCHAR> ustring;

int ErrMsg(const ustring& s);

HWND CreateEdit(const HWND hParent, const HINSTANCE hInst, DWORD dwStyle,
	const RECT & rc, const int id, const ustring & caption);
HWND CreateControl(const ustring&, const ustring&, const HWND, DWORD,
	const HINSTANCE, DWORD, const RECT&, const int);
HWND CreateStatics(const HWND hParent, const HINSTANCE hInst, DWORD dwStyle,
	const RECT & rc, const int id, const ustring & caption);