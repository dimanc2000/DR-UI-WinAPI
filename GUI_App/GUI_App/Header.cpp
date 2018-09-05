#include "stdafx.h"

#include "Header.h"

int ErrMsg(const ustring& s)
{
	return MessageBox(0, s.c_str(), _T("ERROR"), MB_OK | MB_ICONEXCLAMATION);
}

HWND CreateControl(const ustring& classname, const ustring& caption,
	const HWND hParent, DWORD extstyle, const HINSTANCE hInst,
	DWORD dwStyle, const RECT& rc, const int id)
{
	return CreateWindowEx(0,                  //extended styles
		classname.c_str(),  //control 'class' name
		caption.c_str(),    //control caption
		dwStyle,            //wnd style
		rc.left,            //position: left
		rc.top,             //position: top
		rc.right,           //width
		rc.bottom,          //height
		hParent,            //parent window handle
							//control's ID
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)),
		hInst,              //instance
		0);                 //user defined info
}

HWND CreateStatics(const HWND hParent, const HINSTANCE hInst, DWORD dwStyle,
	const RECT& rc, const int id, const ustring& caption)
{
	dwStyle |= WS_CHILD | WS_VISIBLE;
	return CreateWindowEx(0,                            //extended styles
		_T("static"),                 //control 'class' name
		caption.c_str(),              //control caption
		dwStyle,                      //control style 
		rc.left,                      //position: left
		rc.top,                       //position: top
		rc.right,                     //width
		rc.bottom,                    //height
		hParent,                      //parent window handle
									  //control's ID
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)),
		hInst,                        //application instance
		0);                           //user defined info
}

HWND CreateEdit(const HWND hParent, const HINSTANCE hInst, DWORD dwStyle,
	const RECT& rc, const int id, const ustring& caption)
{
	dwStyle |= WS_CHILD | WS_VISIBLE;
	return CreateWindowEx(WS_EX_CLIENTEDGE,             //extended styles
		_T("edit"),                   //control 'class' name
		caption.c_str(),              //control caption
		dwStyle,                      //control style 
		rc.left,                      //position: left
		rc.top,                       //position: top
		rc.right,                     //width
		rc.bottom,                    //height
		hParent,                      //parent window handle
									  //control's ID
		reinterpret_cast<HMENU>(static_cast<INT_PTR>(id)),
		hInst,                        //application instance
		0);                           //user defined info
}