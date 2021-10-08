#pragma once
#include <wx/wx.h>
#include <wx/notebook.h>
#include "./ReplicantHook/Source/ReplicantHook/ReplicantHook.hpp"
#include <map>

class InventoryPanel : public wxPanel
{
private:
	ReplicantHook* hook;
	wxComboBox* m_ItemCategoryComboBox = nullptr;
	wxListBox* m_Items = nullptr;
	wxButton* m_AddItems = nullptr;
	wxButton* m_RemoveItems = nullptr;
	wxTextCtrl* m_Quantity = nullptr;
	wxStaticText* m_feedbacklbl = nullptr;
	wxArrayString* _Recovery;
	wxArrayString* _Cultivation;
	wxArrayString* _Fishing;
	wxArrayString* _Materials;
	wxArrayString* _Key;

public:
	InventoryPanel(wxNotebook* parent, ReplicantHook* hook);
	~InventoryPanel();
protected:
	void onAddItemPress(wxCommandEvent& evt);
	void onRemoveItemPress(wxCommandEvent& evt);
	void onChangeItemCategory(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

