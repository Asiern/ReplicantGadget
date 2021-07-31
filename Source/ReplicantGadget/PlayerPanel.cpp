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
	m_StatsBox = new wxStaticBox(this, wxID_ANY, "Status", wxPoint(margin, margin), wxSize(width - 30, 150), 1, wxStaticBoxNameStr);

	m_Health = new wxStaticText(this, wxID_ANY, "Health: 0/0", wxPoint(margin * 3, margin + 30), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Level = new wxStaticText(this, wxID_ANY, "Level: 0", wxPoint(margin + (width - 2 * margin) / 2, margin + 30), wxDefaultSize, 0, wxStaticTextNameStr);

	m_Funds = new wxStaticText(this, wxID_ANY, "Gold(G): 0", wxPoint(margin * 3, margin + 60), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Magic = new wxStaticText(this, wxID_ANY, "Magic: ", wxPoint(margin + (width - 2 * margin) / 2, margin + 60), wxDefaultSize, 0, wxStaticTextNameStr);

	m_Name = new wxStaticText(this, wxID_ANY, "Name: ", wxPoint(margin * 3, margin + 90), wxDefaultSize, 0, wxStaticTextNameStr);
	m_Playtime = new wxStaticText(this, wxID_ANY, "Playtime: ", wxPoint(margin + (width - 2 * margin) / 2, margin + 90), wxDefaultSize, 0, wxStaticTextNameStr);

	m_Zone = new wxStaticText(this, wxID_ANY, "Zone: ", wxPoint(margin * 3, margin + 120), wxDefaultSize, 0, wxStaticTextNameStr);

	//Attributes
	m_AttributesBox = new wxStaticBox(this, wxID_ANY, "Attributes", wxPoint(margin, 180), wxSize(width - 30, 80), 1, wxStaticBoxNameStr);
	m_SetLevel = new wxStaticText(this, wxID_ANY, "Level", wxPoint(margin * 3, 210), wxDefaultSize, 0, wxStaticTextNameStr);
	m_LevelTextCtrl = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxPoint(margin * 2 + 100, 210), wxDefaultSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_setLevelBtn = new wxButton(this, wxID_ANY, "Set Level", wxPoint(240, 210), wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr);
	m_setLevelBtn->Bind(wxEVT_BUTTON, &PlayerPanel::setLevel, this);

	//Position
	wxSize TextCtrlSize = wxSize(80, 20);
	m_PositionBox = new wxStaticBox(this, wxID_ANY, "Position", wxPoint(margin, 290), wxSize(width - 30, 150), 1, wxStaticBoxNameStr);
	m_XText = new wxStaticText(this, wxID_ANY, "X", wxPoint(20, 333), wxDefaultSize, 0, wxStaticTextNameStr);
	m_YText = new wxStaticText(this, wxID_ANY, "Y", wxPoint(20, 368), wxDefaultSize, 0, wxStaticTextNameStr);
	m_ZText = new wxStaticText(this, wxID_ANY, "Z", wxPoint(20, 403), wxDefaultSize, 0, wxStaticTextNameStr);
	m_XposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 330), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_YposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 365), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_ZposTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(4 * margin, 400), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_XposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 330), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_YposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 365), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_ZposStoredTextCtrl = new wxTextCtrl(this, wxID_ANY, "0.000000", wxPoint(width / 2 - 4 * margin, 400), TextCtrlSize, 0, wxDefaultValidator, wxTextCtrlNameStr);
	m_CurrentPosText = new wxStaticText(this, wxID_ANY, "Current", wxPoint(4 * margin, 310), wxDefaultSize, 0, wxStaticTextNameStr);
	m_StoredPosText = new wxStaticText(this, wxID_ANY, "Stored", wxPoint(width / 2 - 4 * margin, 310), wxDefaultSize, 0, wxStaticTextNameStr);
	m_StorePosition = new wxButton(this, wxID_ANY, "Store", wxPoint(240, 330), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_StorePosition->Bind(wxEVT_BUTTON, &PlayerPanel::StorePosition, this);
	m_RestorePosition = new wxButton(this, wxID_ANY, "Restore", wxPoint(240, 365), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_RestorePosition->Bind(wxEVT_BUTTON, &PlayerPanel::RestorePosition, this);
	/*m_WarpButton = new wxButton(this, wxID_ANY, "Warp", wxPoint(240, 410), wxSize(90, 25), 1, wxDefaultValidator, wxStaticBoxNameStr);
	m_WarpButton->Bind(wxEVT_BUTTON, &PlayerPanel::onWarpCLicked, this);
	wxArrayString* Locations = new wxArrayString();
	Locations->Add("Amusement (Beauvoir)", 1);
	m_WarpComboBox = new wxComboBox(this, wxID_ANY, "", wxPoint(2 * margin, 410), wxSize((width - (6 * margin)) * 2 / 3, 20), *Locations, 0, wxDefaultValidator, wxComboBoxNameStr);

	delete Locations;*/

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
		m_Level->SetLabel("Level: " + wxString::Format(wxT("%i"), hook->getLevel() + 1));
		m_Health->SetLabel("Health: " + wxString::Format(wxT("%i"), hook->getHealth()));
		m_Funds->SetLabel("Gold(G): " + wxString::Format(wxT("%i"), hook->getGold()));
		m_Magic->SetLabel("Magic: " + wxString::Format(wxT("%f"), (float)hook->getMagic()));
		m_Name->SetLabel("Name: " + hook->getName());
		m_Playtime->SetLabel("Playtime: " + wxString::Format(wxT("%f"), hook->getPlaytime()));
		m_Zone->SetLabel("Zone: " + hook->getZone());
		//Position
		m_XposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getX()));
		m_YposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getY()));
		m_ZposTextCtrl->SetLabel(wxString::Format(wxT("%f"), hook->getZ()));
	}
	else {
	}
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

void PlayerPanel::setLevel(wxCommandEvent& evt)
{
	long level;
	if (!m_LevelTextCtrl->GetValue().ToLong(&level)) {
		wxMessageBox("Could not set the level");
		return;
	}
	hook->setLevel(level - 1);
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
