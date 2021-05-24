#include "GraphicsPanel.hpp"

wxBEGIN_EVENT_TABLE(GraphicsPanel, wxPanel)
wxEND_EVENT_TABLE()

GraphicsPanel::GraphicsPanel(wxNotebook* parent, ReplicantHook* hook) : wxPanel(parent, wxID_ANY)
{
	this->hook = hook;
	//Const sizes
	const int margin = 10;
	const int width = 365;

	//Load Models
	models.insert(std::pair<wxString, wxString>(wxString("Kaine"), wxString("kaineE")));
	models.insert(std::pair<wxString, wxString>(wxString("Nier young"), wxString("nierB")));
	models.insert(std::pair<wxString, wxString>(wxString("Nier old"), wxString("nierY")));
	models.insert(std::pair<wxString, wxString>(wxString("Nier Father"), wxString("nierF")));
	models.insert(std::pair<wxString, wxString>(wxString("Nier shadowlord"), wxString("nierT")));

	modelsLabel = new wxStaticText(this, wxID_ANY, "Models", wxPoint(20, 30), wxDefaultSize, 0, wxStaticTextNameStr);

	wxArrayString choices = getItems();
	m_models = new wxListBox(this, wxID_ANY, wxPoint(20, 60), wxSize(315, 100), choices, 0, wxDefaultValidator, wxListBoxNameStr);

	m_setModel = new wxButton(this, wxID_ANY, "Set Model", wxPoint(20, 180), wxDefaultSize, 0, wxDefaultValidator, wxButtonNameStr);
	m_setModel->Bind(wxEVT_BUTTON, &GraphicsPanel::loadModel, this);

	//Timer
	m_Timer = new wxTimer();
	m_Timer->Bind(wxEVT_TIMER, &GraphicsPanel::OnTimer, this);

	this->SetBackgroundColour(wxColor(255, 255, 255));
	m_Timer->Start(1000, wxTIMER_CONTINUOUS);
}

GraphicsPanel::~GraphicsPanel()
{
	m_Timer->Stop();
	delete m_Timer;
}

void GraphicsPanel::OnTimer(wxTimerEvent&)
{
	if (hook->isHooked()) {

	}
	else {
	}
}

void GraphicsPanel::loadModel(wxCommandEvent& evt)
{
	if (wxNOT_FOUND == m_models->GetSelection()) {
		wxMessageBox("Please select a model");
		return;
	}
	wxString ID = getItemID(m_models->GetString(m_models->GetSelection()));
	if (ID == "") {
		wxMessageBox("Could not change the model");
		return;
	}
	hook->setActorModel(std::string(ID));
}

wxArrayString GraphicsPanel::getItems()
{
	std::map<wxString, wxString>::iterator it = models.begin();
	std::map<wxString, wxString>::iterator end = models.end();
	wxArrayString choices;

	for (;it != end;it++) {
		choices.Add(it->first);
	}
	return choices;
}

wxString GraphicsPanel::getItemID(wxString name)
{
	std::map<wxString, wxString>::iterator it = models.begin();
	std::map<wxString, wxString>::iterator end = models.end();

	for (;it != end;it++) {
		if (it->first == name) {
			return it->second;
		}
	}
	return "";
}