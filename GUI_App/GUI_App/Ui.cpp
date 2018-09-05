#include "stdafx.h"
#include "Ui.h"

/*Ui::Ui()
{
}*/

Ui::~Ui()
{
}

void Ui::Run(GUI Object)
{
	ShowWindow(Object.hwnd, Object.nCmd);
}

void Ui::Stop(GUI Object)
{
	SendMessage(Object.hwnd, IDM_STOP, 0, 0);  //синхронно (postmessage - асинхронно)
}

void Ui::Poll(GUI Object)
{
	SendMessage(Object.hwnd, IDM_POLL, 0, 0);
}

void Ui::SetState(GUI Object, unsigned int state)
{
	SendMessage(Object.hwnd, IDM_SS, 0, 0);
}

void Ui::ShowPassword(GUI Object, const std::string & password)
{
	SendMessage(Object.hwnd, IDM_SP, 0, 0);
}

void Ui::UpdateTechnicianList(GUI Object, const std::vector<Technician>& technicians)
{
	SendMessage(Object.hwnd, IDM_UTL, 0, 0);
}

void Ui::SetSelectionTechnician(GUI Object, unsigned int tid)
{
	SendMessage(Object.hwnd, IDM_SST, 0, 0);
}

void Ui::ShowTechnicianMessage(GUI Object, unsigned int tid, const std::string & message)
{
	SendMessage(Object.hwnd, IDM_STM, 0, 0);
}

void Ui::ShowSessionConfirmMessage(GUI Object)
{
	SendMessage(Object.hwnd, IDM_SSCM, 0, 0);
}

void Ui::RemoveSessionConfirmMessage(GUI Object)
{
	SendMessage(Object.hwnd, IDM_RSCM, 0, 0);
}

void Ui::ClearChatView(GUI Object)
{
	SendMessage(Object.hwnd, IDM_CCV, 0, 0);
}
