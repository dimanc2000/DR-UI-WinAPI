#pragma once

#include "resource.h"
#include "GUI.h"

#define MAX_LOADSTRING 100

//Переменные:
GUI Gui;
ustring classname = _T("SIMPLEWND");
HINSTANCE hInstance;                            //текущий экземпляр
WCHAR szWindowClass[MAX_LOADSTRING];            //имя класса главного окна

//Функции:
ATOM                MyRegisterClass(HINSTANCE hInstance);

LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
