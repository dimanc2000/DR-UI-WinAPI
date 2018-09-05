#pragma once

#ifndef GUI_TEST_IRDUI_H
#define GUI_TEST_IRDUI_H

#include <string>
#include <vector>

/**
* Rd GUI states
*/
namespace RdState {
	enum T {
		Disconnected = 0,
		ConnectingToMango, //Connecting to the server
		ConnectionInformation, //Connecting to the server
		DownloadingUpdate,
		ConnectingToPineapple, //Connecting to the server
		Authorizing,
		ReceivingPassword,
		WaitingTechnician, //Ready
		SessionStarted, //In session
		ResumingSession, //Show message: "Resuming session"
		Denied //The same as Disconnected
	};
}

namespace ConfirmReturnCode {
	enum T {
		Idle = 0,
		DisagreeStartSession,
		AgreeStartSession
	};
}

/**
* Technician info
*/
struct Technician {
	unsigned int id;
	std::string title;
	std::string nick;
};

class IRdUiListener;

/**
* Client-RD graphical user interface.
* Contains callbacks for changing GUI state.
* From dispatcher to GUI
*/
class IRdUi {
public:
	explicit IRdUi(IRdUiListener *listener) :
		listener_(listener) {
	}

	/**
	* Run GUI.
	* Default state = Disconnected
	*/
	virtual void Run() = 0;

	/**
	* Check the state of the UI.
	* This function is called in an infinite loop from IRdUiListener
	*/
	virtual void Poll() = 0;

	/**
	* Stop GUI.
	* Close window.
	*/
	virtual void Stop() = 0;

	/**
	* Set RdState
	* @param state
	*/
	virtual void SetState(unsigned int state) = 0;

	/**
	* Show password
	* @param password
	*/
	virtual void ShowPassword(const std::string &password) = 0;

	/**
	* Update technician list
	* @param technicians
	*/
	virtual void UpdateTechnicianList(const std::vector<Technician> &technicians) = 0;

	/**
	* Set selection technician (highlight, for example, the blue color)
	* @param tid - technician id
	*/
	virtual void SetSelectionTechnician(unsigned int tid) = 0;

	/**
	* Show technician message.
	* @param tid - technician id
	* @param message
	*/
	virtual void ShowTechnicianMessage(unsigned int tid, const std::string &message) = 0;

	/**
	* Show session confirm message (alert).
	* The alert has two buttons: 'Yes' and 'No'
	*/
	virtual void ShowSessionConfirmMessage() = 0;

	/**
	* Remove session confirm message (alert).
	*/
	virtual void RemoveSessionConfirmMessage() = 0;

	/**
	* Clear chat view.
	* Remove all messages
	*/
	virtual void ClearChatView() = 0;

protected:
	IRdUiListener * listener_;
};


#endif //GUI_TEST_IRDUI_H