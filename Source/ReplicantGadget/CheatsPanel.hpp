#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include "ReplicantHook/Source/ReplicantHook/ReplicantHook.hpp"
class CheatsPanel :public wxPanel
{
public:
	//wxStaticBox* m_CheatsBox = nullptr;
	wxCheckBox* m_InfiniteHealth = nullptr;
	wxCheckBox* m_InfiniteMagic = nullptr;

	CheatsPanel(wxNotebook* parent, ReplicantHook* hook);
	~CheatsPanel();
private:
	ReplicantHook* hook = nullptr;
	void InfiniteHealth(wxCommandEvent& evt);
	void InfiniteMagic(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

