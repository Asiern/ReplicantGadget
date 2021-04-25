#include "PlayerPanel.hpp"

wxBEGIN_EVENT_TABLE(PlayerPanel, wxPanel)
wxEND_EVENT_TABLE()

PlayerPanel::PlayerPanel(wxNotebook* parent, ReplicantHook* hook) : wxPanel(parent, wxID_ANY)
{
	this->hook = hook;
	//Const sizes
	const int margin = 10;
	const int width = 365;

	//Timer
	m_Timer = new wxTimer();
	m_Timer->Bind(wxEVT_TIMER, &PlayerPanel::OnTimer, this);

	//Status
	m_StatsBox = new wxStaticBox(this, wxID_ANY, "Status", wxPoint(margin, margin), wxSize(width - 30, 90), 1, wxStaticBoxNameStr);
	m_Health = new wxStaticText(this, wxID_ANY, "Health: 0/0", wxPoint(margin * 3, margin + 30), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Level = new wxStaticText(this, wxID_ANY, "Level: 0", wxPoint(margin + (width - 2 * margin) / 2, margin + 30), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Funds = new wxStaticText(this, wxID_ANY, "Funds(G): 0", wxPoint(margin + (width - 2 * margin) / 2, margin + 60), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Zone = new wxStaticText(this, wxID_ANY, "Zone: ", wxPoint(margin * 3, margin + 60), wxDefaultSize, 0, wxStaticTextNameStr);

	//Cheats
	m_CheatsBox = new wxStaticBox(this, wxID_ANY, "Cheats", wxPoint(margin, 110), wxSize(width - 30, 130), 1, wxStaticBoxNameStr);
	m_InfiniteHealth = new wxCheckBox(this, wxID_ANY, "Infinite Health", wxPoint(3 * margin, 140), wxDefaultSize, 0, wxDefaultValidator, wxCheckBoxNameStr);
	m_InfiniteHealth->Bind(wxEVT_CHECKBOX, &PlayerPanel::InfiniteHealth, this);
	m_InfiniteMagic = new wxCheckBox(this, wxID_ANY, "Infinite Magic", wxPoint(3 * margin, 170), wxDefaultSize, 0, wxDefaultValidator, wxCheckBoxNameStr);
	m_InfiniteMagic->Bind(wxEVT_CHECKBOX, &PlayerPanel::InfiniteMagic, this);

	//Position
	wxSize TextCtrlSize = wxSize(80, 20);
	m_PositionBox = new wxStaticBox(this, wxID_ANY, "Position", wxPoint(margin, 250), wxSize(width - 30, 200), 1, wxStaticBoxNameStr);
	m_XText = new wxStaticText(this, wxID_ANY, "X", wxPoint(20, 303), wxDefaultSize, 0, wxStaticTextNameStr);
	m_YText = new wxStaticText(this, wxID_ANY, "Y", wxPoint(20, 338), wxDefaultSize, 0, wxStaticTextNameStr);
	m_ZText = new wxStaticText(this, wxID_ANY, "Z", wxPoint(20, 373), wxDefaultSize, 0, wxStaticTextNameStr);
	m_XposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 300), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_YposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 335), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_ZposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 370), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_XposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 300), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_YposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 335), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_ZposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 370), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_CurrentPosText = new wxStaticText(this, wxID_ANY, "Current", wxPoint(4 * margin, 280), wxDefaultSize, 0, wxStaticTextNameStr);
	m_StoredPosText = new wxStaticText(this, wxID_ANY, "Stored", wxPoint(width / 2 - 4 * margin, 280), wxDefaultSize, 0, wxStaticTextNameStr);
	m_StorePosition = new wxButton(this, wxID_ANY, "Store", wxPoint(240, 300), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_StorePosition->Bind(wxEVT_BUTTON, &PlayerPanel::StorePosition, this);
	m_RestorePosition = new wxButton(this, wxID_ANY, "Restore", wxPoint(240, 335), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_RestorePosition->Bind(wxEVT_BUTTON, &PlayerPanel::RestorePosition, this);
	m_WarpButton = new wxButton(this, wxID_ANY, "Warp", wxPoint(240, 410), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_WarpButton->Bind(wxEVT_BUTTON, &PlayerPanel::onWarpCLicked, this);
	wxArrayString* Locations = new wxArrayString();
	Locations->Add("Amusement (Beauvoir)", 1);
	m_WarpComboBox = new wxComboBox(this, wxID_ANY, "", wxPoint(2 * margin, 410), wxSize((width - (6 * margin)) * 2 / 3, 20), *Locations, 0, wxDefaultValidator, wxComboBoxNameStr);

	delete Locations;

	this->SetBackgroundColour(wxColor(255, 255, 255));
	m_Timer->Start(1000, wxTIMER_CONTINUOUS);
}

PlayerPanel::~PlayerPanel()
{
	m_Timer->Stop();
	delete m_Timer;
}

void PlayerPanel::OnTimer(wxTimerEvent&)
{
	if (hook->isHooked()) {
		//Player
		m_Level->SetLabel("Level: " + wxString::Format(wxT("%i"), hook->getLevel()));
		m_Health->SetLabel("Health: " + wxString::Format(wxT("%i"), hook->getHealth()));
		m_Funds->SetLabel("Funds(G): " + wxString::Format(wxT("%i"), hook->getGold()));
		m_Zone->SetLabel("Zone: " + wxString::Format(wxT("%i"), hook->getLevel()));
		//Position
		m_XposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getX()));
		m_YposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getY()));
		m_ZposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getZ()));
	}
	else {
	}
}

void PlayerPanel::InfiniteMagic(wxCommandEvent& evt)
{
	hook->InfiniteMagic(m_InfiniteMagic->IsChecked());
}

void PlayerPanel::InfiniteHealth(wxCommandEvent& evt)
{
	hook->InfiniteHealth(m_InfiniteHealth->IsChecked());
}


void PlayerPanel::StorePosition(wxCommandEvent& evt)
{
	m_XposStoredTextCtrl->SetValue(wxString::Format(wxT("%f"), hook->getX()));
	m_YposStoredTextCtrl->SetValue(wxString::Format(wxT("%f"), hook->getY()));
	m_ZposStoredTextCtrl->SetValue(wxString::Format(wxT("%f"), hook->getZ()));
	this->setStoredPosition(hook->getX(), hook->getY(), hook->getZ());
}

void PlayerPanel::setStoredPosition(float X, float Y, float Z)
{
	this->StoredX = X;
	this->StoredY = Y;
	this->StoredZ = Z;
}

void PlayerPanel::RestorePosition(wxCommandEvent& evt)
{
	hook->setPosition(this->StoredX, this->StoredY, this->StoredZ);
}

constexpr unsigned int str2int(const char* str, int h = 0)
{
	return !str[h] ? 5381 : (str2int(str, h + 1) * 33) ^ str[h];
}

void PlayerPanel::onWarpCLicked(wxCommandEvent& evt)
{
	switch (str2int(m_WarpComboBox->GetValue()))
	{
	case str2int("Amusement (Beauvoir)"):
		hook->setPosition(796.61, 21.72, 295.11);
		break;
	default:
		wxMessageBox("Could not find location", wxMessageBoxCaptionStr, 0, this, -1, -1);
		break;
	}
}
