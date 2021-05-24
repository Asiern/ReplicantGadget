#include "Main.hpp"
#include "PlayerPanel.hpp"
#include "GraphicsPanel.hpp"
#include "CheatsPanel.hpp"

wxBEGIN_EVENT_TABLE(Main, wxFrame)
EVT_CLOSE(Main::OnClose)
wxEND_EVENT_TABLE()

Main::Main() : wxFrame(nullptr, wxID_ANY, "NieR Replicant Gadget", wxPoint(30, 30), wxSize(400, 600))
{
	//Hook Thread bind
	Bind(wxEVT_THREAD, &Main::OnThreadUpdate, this);

	//Frame style
	this->SetIcon(wxICON(IDI_ICON1));
	this->SetMaxSize(wxSize(400, 600));
	this->SetMinSize(wxSize(400, 600));
	this->SetBackgroundColour(wxColor(242, 242, 242));
	wxFont font = wxFont(8, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false);

	//Const sizes
	const int margin = 10;
	const int width = 365;

	//Initialize hook
	hook = new ReplicantHook();

	//Create Notebook
	notebook = new wxNotebook(this, wxID_ANY, wxPoint(margin, margin * 6), wxSize(width, 485), 0, wxNotebookNameStr);
	Player = new PlayerPanel(notebook, hook);
	Graphics = new GraphicsPanel(notebook, hook);
	Cheats = new CheatsPanel(notebook, hook);

	notebook->AddPage(Player, wxT("Player"), false, 0);
	notebook->AddPage(Graphics, wxT("Graphics"), false, 1);
	notebook->AddPage(Cheats, wxT("Cheats"), false, 2);

	Player->Enable(false);
	Graphics->Enable(false);
	Cheats->Enable(false);

	//Timer
	m_Timer = new wxTimer();
	m_Timer->Bind(wxEVT_TIMER, &Main::OnTimer, this);

	//Hook status text
	m_hooked = new wxStaticText(this, wxID_ANY, "Hooked: No", wxPoint(margin, margin), wxDefaultSize, 0, wxStaticTextNameStr);
	m_hooked->SetForegroundColour(wxColor(244, 67, 54));
	m_hooked->SetFont(font);
	m_status = new wxStaticText(this, wxID_ANY, "Process: None", wxPoint(margin, margin * 3), wxDefaultSize, 0, wxStaticTextNameStr);
	m_status->SetFont(font);
	m_version = new wxStaticText(this, wxID_ANY, "Version: 1.0.0", wxPoint(width - margin * 6, margin), wxDefaultSize, 0, wxStaticTextNameStr);
	m_version->SetFont(font);

	StartHook();//start hook thread
	startTimer();//start ui thread
}

Main::~Main()
{
}

void Main::updateComponents(void)
{
	if (hook->isHooked()) {
		m_hooked->SetForegroundColour(wxColor(76, 175, 80));
		m_hooked->SetLabelText("Hooked: Yes");
		m_status->SetLabel("Process: " + wxString::Format(wxT("%i"), hook->getProcessID()));
		Player->Enable(true);
		Graphics->Enable(true);
		Cheats->Enable(true);

	}
	else {
		m_hooked->SetForegroundColour(wxColor(244, 67, 54));
		m_hooked->SetLabelText("Hooked: No");
		m_status->SetLabel("Process: None");
		Player->Enable(false);
		Graphics->Enable(false);
		Cheats->Enable(false);
	}
}

void Main::startTimer(void)
{
	if (!m_Timer->IsRunning()) {
		m_Timer->Start(1000, wxTIMER_CONTINUOUS);
	}
	else {
		wxLogError("Timer already running");
		return;
	}
}

void Main::stopTimer(void)
{
	if (m_Timer->IsRunning()) {
		m_Timer->Stop();
	}
	else {
		wxLogError("Timer not running");
		return;
	}
}

void Main::OnTimer(wxTimerEvent&)
{
	updateComponents();
}

void Main::OnThreadUpdate(wxThreadEvent& evt)
{
}

void Main::OnClose(wxCloseEvent&)
{
	m_Timer->Stop();
	if (hook->isHooked()) {
		hook->stop();
		GetThread()->TestDestroy();
		GetThread()->Delete();
	}
	delete m_Timer;
	delete hook;
	Destroy();
}

wxThread::ExitCode Main::Entry()
{
	while (!GetThread()->TestDestroy())
	{
		hook->hookStatus(); //Update status
		if (!hook->isHooked()) {
			hook->start();//Start hook
		}
		else {
			hook->update(); //Update hook
		}
	}
	return (wxThread::ExitCode)0;
}

void Main::StartHook(void)
{
	//Start Hook thread
	if (CreateThread(wxTHREAD_JOINABLE) != wxTHREAD_NO_ERROR)
	{
		wxLogError("Could not create the Hook thread");
		return;
	}
	if (GetThread()->Run() != wxTHREAD_NO_ERROR)
	{
		wxLogError("Could not run the Hook thread");
		return;
	}
}
