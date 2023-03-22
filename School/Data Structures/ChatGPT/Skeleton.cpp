#include <wx/wx.h>
#include <wx/filedlg.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Queue.h"
#include "PQueue.h"
#include "Deque.h"
#include "Stack.h"

wxTextCtrl *displayTextCtrl; // pointer to the textbox used for displaying output
// other global variables...

class ProjectApp : public wxApp
{
public:
	virtual bool OnInit();
};

class ProjectFrame : public wxFrame
{
private:
	wxDECLARE_EVENT_TABLE();

public:
	ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	void OnOpen(wxCommandEvent &event);
	void OnDisplayAll(wxCommandEvent &event);
	void OnDisplayFile(wxCommandEvent &event);
	void OnSave(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);
	void OnCreateQueue(wxCommandEvent &event);
	void OnCreatePQ(wxCommandEvent &event);
	void OnCreateDeque(wxCommandEvent &event);
	void OnCreateStack(wxCommandEvent &event);
	void OnDequeue(wxCommandEvent &event);
	void OnDequeueHead(wxCommandEvent &event);
	void OnDequeueTail(wxCommandEvent &event);
	void OnShowHead(wxCommandEvent &event);
	void OnShowTail(wxCommandEvent &event);

	// Public attributes
		wxTextCtrl *MainEditBox;
		wxTectCtrl *filenameTextBox;
		wxSring CurrenDocPatch;

};



enum
{
	ID_Open = 1,
	ID_DisplayAll,
	ID_DisplayFile,
	ID_Save,
	ID_Exit,
	ID_CreateQueue,
	ID_CreatePQ,
	ID_CreateDeque,
	ID_CreateStack,
	ID_Dequeue,
	ID_DequeueHead,
	ID_DequeueTail,
	ID_ShowHead,
	ID_ShowTail,
	ID_TextBox
};

DECLARE_APP(ProjectApp)
IMPLEMENT_APP(ProjectApp)

wxBEGIN_EVENT_TABLE(ProejctFrame, wxFrame)
EVT_MENU(ID_Open, ProejctFrame::OnOpen)
EVT_MENU(ID_DisplayAll, ProejctFrame::OnDisplayAll)
EVT_MENU(ID_DisplayFile, ProejctFrame::OnDisplayFile)
EVT_MENU(ID_Save, ProejctFrame::OnSave)
EVT_MENU(ID_Exit, ProejctFrame::OnExit)
EVT_MENU(ID_CreateQueue, ProejctFrame::OnCreateQueue)
EVT_MENU(ID_CreatePQ, ProejctFrame::OnCreatePQ)
EVT_MENU(ID_CreateDeque, ProejctFrame::OnCreateDeque)
EVT_MENU(ID_CreateStack, ProejctFrame::OnCreateStack)
EVT_MENU(ID_Dequeue, ProejctFrame::OnDequeue)
EVT_MENU(ID_DequeueHead, ProejctFrame::OnDequeueHead)
EVT_MENU(ID_DequeueTail, ProejctFrame::OnDequeueTail)
EVT_MENU(ID_ShowHead, ProejctFrame::OnShowHead)
EVT_MENU(ID_ShowTail, ProejctFrame::OnShowTail)
wxEND_EVENT_TABLE()

bool ProjectApp::OnInit()
{
	ProejctFrame *frame = new ProejctFrame("COMP2611 - Data Structures Project #1", wxDefaultPosition, wxSize(800, 600));
	frame->Show(true);
	return true;
}

// Define the main frame

ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
	: wxFrame(NULL, wxID_ANY, title, pos, size)
{
	// Set the frame icon
	SetIcon(wxICON(sample));

	// Create the menu bar
	wxMenu *fileMenu = new wxMenu;
	fileMenu->Append(ID_Open, "&Open\tCtrl-O", "Open a file with song data");
	fileMenu->AppendSeparator();
	fileMenu->Append(ID_DisplayAll, "&Display All", "Display all songs in the data structure");
	fileMenu->Append(ID_DisplayFile, "&Display File", "Display songs from file in the data structure");
	fileMenu->Append(ID_Save, "&Save\tCtrl-S", "Save song data to a file");
	fileMenu->AppendSeparator();
	fileMenu->Append(ID_Exit, "&Exit\tCtrl-Q", "Exit the program");

	wxMenu *createMenu = new wxMenu;
	createMenu->Append(ID_CreateQueue, "&Create Queue", "Create a new Queue");
	createMenu->Append(ID_CreatePQ, "&Create Priority Queue", "Create a new Priority Queue");
	createMenu->Append(ID_CreateDeque, "&Create Deque", "Create a new Deque");
	createMenu->Append(ID_CreateStack, "&Create Stack", "Create a new Stack");

	wxMenu *operationsMenu = new wxMenu;
	operationsMenu->Append(ID_Dequeue, "&Dequeue", "Remove the first element from the Queue");
	operationsMenu->Append(ID_DequeueHead, "Remove &Head", "Remove the first element from the Deque");
	operationsMenu->Append(ID_DequeueTail, "Remove &Tail", "Remove the last element from the Deque");
	operationsMenu->AppendSeparator();
	operationsMenu->Append(ID_ShowHead, "Show &Head", "Show the first element from the Deque");
	operationsMenu->Append(ID_ShowTail, "Show &Tail", "Show the last element from the Deque");

	// Attach the menus to the frame
	wxMenuBar *menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, "&File");
	menuBar->Append(createMenu, "&Create");
	menuBar->Append(operationsMenu, "&Operations");
	SetMenuBar(menuBar);

	// Create the status bar
	InitStatusBar();

	// Create the text display control
	m_displayText = new wxTextCtrl(this, ID_TextBox, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE);
	m_displayText->SetFont(wxFont(10, wxFONTFAMILY_TELETYPE, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false));
	displayTextCtrl = m_displayText;

	// Position the text display control and set its size
	wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(m_displayText, 1, wxEXPAND, 0);
	SetSizer(sizer);
	SetAutoLayout(true);
	sizer->Fit(this);
	sizer->SetSizeHints(this);

	// Set the minimum size of the frame
	SetMinSize(wxSize(400, 300));

	// Initialize other member variables
	m_filePath = wxEmptyString;
}
