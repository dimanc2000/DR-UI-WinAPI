#pragma once
#include "IRdUi.h"
#include "GUI.h"
#include "Header.h"

class Ui : IRdUi
{
public:
	//Ui();
	~Ui();

	static void Run(GUI Object);
	static void Stop(GUI Object);
	static void Poll(GUI Object);
	static void SetState(GUI Object, unsigned int state);
	static void ShowPassword(GUI Object, const std::string &password);
	static void UpdateTechnicianList(GUI Object, const std::vector<Technician> &technicians);
	static void SetSelectionTechnician(GUI Object, unsigned int tid);
	static void ShowTechnicianMessage(GUI Object, unsigned int tid, const std::string &message);
	static void ShowSessionConfirmMessage(GUI Object);
	static void RemoveSessionConfirmMessage(GUI Object);
	static void ClearChatView(GUI Object);

//private:
	/**
	* Run GUI.
	* Default state = Disconnected
	*/
	//virtual void Run(HINSTANCE hInst, HINSTANCE, LPSTR pStr, int nCmd);

	/**
	* Stop GUI.
	* Close window.
	*/
	//virtual void Stop();

	/**
	* Check the state of the UI.
	* This function is called in an infinite loop from IRdUiListener
	*/
	//void Poll(GUI Object);

	/**
	* Set RdState
	* @param state
	*/
	//void SetState(unsigned int state);

	/**
	* Show password
	* @param password
	*/
	//void ShowPassword(const std::string &password);

	/**
	* Update technician list
	* @param technicians
	*/
	//void UpdateTechnicianList(const std::vector<Technician> &technicians);

	/**
	* Set selection technician (highlight, for example, the blue color)
	* @param tid - technician id
	*/
	//void SetSelectionTechnician(unsigned int tid);

	/**
	* Show technician message.
	* @param tid - technician id
	* @param message
	*/
	//void ShowTechnicianMessage(unsigned int tid, const std::string &message);

	/**
	* Show session confirm message (alert).
	* The alert has two buttons: 'Yes' and 'No'
	*/
	//void ShowSessionConfirmMessage();

	/**
	* Remove session confirm message (alert).
	*/
	//void RemoveSessionConfirmMessage();

	/**
	* Clear chat view.
	* Remove all messages
	*/
	//void ClearChatView();
};

