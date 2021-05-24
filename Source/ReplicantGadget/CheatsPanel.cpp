#include "CheatsPanel.hpp"


wxBEGIN_EVENT_TABLE(CheatsPanel, wxPanel)
wxEND_EVENT_TABLE()

CheatsPanel::CheatsPanel(wxNotebook* parent, ReplicantHook* hook) : wxPanel(parent, wxID_ANY)
{
	this->hook = hook;
	//Const sizes
	const int margin = 10;
	const int width = 365;

	//Cheats
	//m_CheatsBox = new wxStaticBox(this, wxID_ANY, "Cheats", wxPoint(margin, 110), wxSize(width - 30, 130), 1, wxStaticBoxNameStr);
	m_InfiniteHealth = new wxCheckBox(this, wxID_ANY, "Infinite Health", wxPoint(margin, margin), wxDefaultSize, 0, wxDefaultValidator, wxCheckBoxNameStr);
	m_InfiniteHealth->Bind(wxEVT_CHECKBOX, &CheatsPanel::InfiniteHealth, this);
	m_InfiniteMagic = new wxCheckBox(this, wxID_ANY, "Infinite Magic", wxPoint(margin, 40), wxDefaultSize, 0, wxDefaultValidator, wxCheckBoxNameStr);
	m_InfiniteMagic->Bind(wxEVT_CHECKBOX, &CheatsPanel::InfiniteMagic, this);

	this->SetBackgroundColour(wxColor(255, 255, 255));
}

CheatsPanel::~CheatsPanel()
{
}

void CheatsPanel::InfiniteMagic(wxCommandEvent& evt)
{
	hook->InfiniteMagic(m_InfiniteMagic->IsChecked());
}

void CheatsPanel::InfiniteHealth(wxCommandEvent& evt)
{
	hook->InfiniteHealth(m_InfiniteHealth->IsChecked());
}