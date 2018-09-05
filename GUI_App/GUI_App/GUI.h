#pragma once

#include <windows.h> 
#include <string>
#include <tchar.h>
#include <vector>

#include "Header.h"

class GUI
{
public:
	GUI();
	GUI(int nCmdShow);
	~GUI();

	void AddText(const TCHAR * text);//HWND eWnd, const TCHAR * text);

	int OnCreate(const HWND hwnd, CREATESTRUCT * cs);
	void OnSize(const HWND hwnd, int cx, int cy, UINT flags);
	void OnDestroy(const HWND hwnd);
	//void SetText(const TCHAR* text);

	HWND hwnd; 
	int nCmd;

	HWND hEdit;

	const TCHAR* text;

private:

};

