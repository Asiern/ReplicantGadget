#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include "ReplicantHook/Source/ReplicantHook/ReplicantHook.hpp"
#include <map>
class GraphicsPanel :public wxPanel
{
public:
	//Timer
	wxTimer* m_Timer = nullptr;

	GraphicsPanel(wxNotebook* parent, ReplicantHook* hook);
	~GraphicsPanel();

protected:
	//TIMER
	void OnTimer(wxTimerEvent&);
	//POSITION EVT
	void loadModel(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();

private:
	ReplicantHook* hook = nullptr;
	std::map<wxString, wxString> models;
	wxListBox* m_models = nullptr;
	wxStaticText* modelsLabel = nullptr;
	wxButton* m_setModel = nullptr;
	wxArrayString getItems();
	wxString getItemID(wxString name);
	wxStaticText* m_feedbacklbl = nullptr;
};


