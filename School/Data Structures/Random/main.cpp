//
//  Skeleton-01.cpp
//  COMP2611 - Project #1
//
//  Created by Dr. John Charlery on 02/15/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

// ==============================================================================
/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/

#include <wx/wxprec.h>
#include <wx/wx.h>

#include <iostream>
#include <fstream>
#include <string>


using namespace std;


// Other miscellaneous functions' prototypes, if required

// Include the ADTs header files
//#include "Queue.h"
//#include "Deque.h"
//#include "PQueue.h"
//#include "Stack.h"
// Global pointers for the ADT containers

/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it withthe function to execute the program
*************************************************************************************
*************************************************************************************/
class ProjectApp : public wxApp
{
	virtual bool OnInit();
};

/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
class ProjectFrame : public wxFrame
{
private:
	DECLARE_EVENT_TABLE() // To declare events items

public:
	ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	// Functions for File Menu Items
	void OnOpenFile(wxCommandEvent &event);
	void OnDisplay(wxCommandEvent &event);
	void OnSave(wxCommandEvent &event);
	void OnSaveAs(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event); // handle for Quit function

	// Functions for the Queue Menu Items
	void OnCreateQ(wxCommandEvent &event);
	void OnDisplayQ(wxCommandEvent &event);
	void OnShowHeadQ(wxCommandEvent &event);
	void OnShowTailQ(wxCommandEvent &event);
	void OnDequeueQ(wxCommandEvent &event);

	// Functions for the Deque Items
	void OnCreateDQ(wxCommandEvent &event);
	void OnnDisplayDQ(wxCommandEvent &event);
	void OnShowDQ(wxCommandEvent &event);
	void OnShowTailDQ(wxCommandEvent &event);
	void OnDequeueHeadDQ(wxCommandEvent &event);
	void OnDequeueTailDQ(wxCommandEvent &event);

	// Function for the Priority Queue
	void OnCreatePQ(wxCommandEvent &event);
	void OnDisplayPQ(wxCommandEvent &event);
	void OnShowPQ(wxCommandEvent &event);
	void OnShowHeadPQ(wxCommandEvent &event);
	void OnShowTailPQ(wxCommandEvent &event);
	void DequeuePQ(wxCommandEvent &event);

	// Function for the Stack
	void OnCreateStack(wxCommandEvent &event);
	void OnPopStack(wxCommandEvent &event);
	void OnDisplayStack(wxCommandEvent &event);
	void OnShowHeadStack(wxCommandEvent &event);
	void OnShowTailStack(wxCommandEvent &event);

	// Public attributes
	wxTextCtrl *MainEditBox;
	wxTextCtrl *filenameTextBox;
	wxString CurrentDocPath; // The Path to the file we have open
};

/************************************************************************************
*************************************************************************************
					Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(ProjectApp)	  // Declare Application class
IMPLEMENT_APP(ProjectApp) // Create Application class object

enum
{
	// File menu items
	ID_OpenFile = wxID_HIGHEST + 1, // File menu item
	ID_Display,
	ID_Save,
	ID_SaveAs,
	ID_Exit,

	// create ID //todo

	// Idea: Queue IDs
	ID_CreateQ,
	ID_DisplayQ,
	ID_ShowHeadQ,
	ID_ShowTailQ,
	ID_DequeQ,

	// Idea: Dequeue IDs
	ID_CreateDQ,
	ID_DisplayDQ,
	ID_ShowDQ,
	ID_ShowHeadDQ,
	ID_ShowTailDQ,
	ID_DequeueHeadDQ,
	ID_DequeueTailDQ,

	// Idea: Priority Queue
	ID_CreatePQ,
	ID_DisplayPQ,
	ID_ShowPQ,
	ID_ShowHeadPQ,
	ID_ShowTailPQ,
	ID_DequeuePQ,

	// Idea: Stacks
	ID_CreateStack,
	ID_PopStack,
	ID_DisplayStack,
	ID_ShowHeadStack,
	ID_ShowTailStack,

};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

END_EVENT_TABLE()

/************************************************************************************
*************************************************************************************
	Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool ProjectApp::OnInit()
{
	// Create the main application window
	ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"), wxPoint(50, 50), wxSize(840, 600));

	// Display the window
	frame->Show(TRUE);

	SetTopWindow(frame);

	return TRUE;
}

/************************************************************************************
*************************************************************************************
			Step 6:   Define the Constructor functions for the Frame class
*************************************************************************************
*************************************************************************************/
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
	: wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	// Set the frame icon - optional
	SetIcon(wxIcon(wxT("Icon.xpm")));

	// Create the main-menu items
	wxMenu *menuFile = new wxMenu;
	wxMenu *menuQueue = new wxMenu;
	wxMenu *menuPriorityQueue = new wxMenu;
	wxMenu *menuDeque = new wxMenu;
	wxMenu *menuStack = new wxMenu;
	wxMenu *menuHelp = new wxMenu;

	// Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;

	// Append the main menu items to the Menu Bar
	menuBar->Append(menuFile, wxT("File"));
	menuBar->Append(menuQueue, wxT("Queue"));
	menuBar->Append(menuPriorityQueue, wxT("Priority Queue"));
	menuBar->Append(menuDeque, wxT("Deque"));
	menuBar->Append(menuStack, wxT("Stack"));
	menuBar->Append(menuHelp, wxT("Help"));

	// Append the sub-menu items to the File Main Menu item
	menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file"));
	menuFile->Append(ID_Display, wxT("&Display File..."), wxT("Display contents of opened file"));
	menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
	menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));
	menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

	// append the sub menu items to the queue main menu item
	menuQueue->Append(ID_CreateQ, wxT("Create Queue"), wxT("Create Queue"));
	menuQueue->Append(ID_DisplayQ, wxT("Display All"), wxT("Show contents of Queue"));
	menuQueue->Append(ID_ShowHeadQ, wxT("Show Head"), wxT("Display Top of Queue"));
	menuQueue->Append(ID_ShowTailQ, wxT("Show Tail"), wxT("Display Bottom of Queue"));
	menuQueue->Append(ID_DequeQ, wxT("Dequeue"), wxT("Remove an Element from Queue"));

	// append the sub menu items to the deque main menu item
	menuDeque->Append(ID_CreateDQ, wxT("Create Deque"), wxT("Create Deque"));
	menuDeque->Append(ID_DisplayDQ, wxT("Display All"), wxT("Display Deque"));
	menuDeque->Append(ID_ShowHeadDQ, wxT("Show Head"), wxT("Display Top of Deque"));
	menuDeque->Append(ID_ShowTailDQ, wxT("Show Tail"), wxT("Display Bottom of Deque"));
	menuDeque->Append(ID_DequeueHeadDQ, wxT("Dequeue Head"), wxT("Remove an Element from Top of Deque"));
	menuDeque->Append(ID_DequeueTailDQ, wxT("Dequeue Tail"), wxT("Remove an Element from Bottom of Deque"));

	// append the sub menu items to the priority queue main menu item
	menuPriorityQueue->Append(ID_CreatePQ, wxT("Create Priority Queue"), wxT("Create Priority Queue"));
	menuPriorityQueue->Append(ID_DisplayPQ, wxT("Display All"), wxT("Display Priority Queue"));
	menuPriorityQueue->Append(ID_ShowHeadPQ, wxT("Show Head"), wxT("Display Top of Priority Queue"));
	menuPriorityQueue->Append(ID_ShowTailPQ, wxT("Show Tail"), wxT("Display Bottom of Priority Queue"));
	menuPriorityQueue->Append(ID_DequeuePQ, wxT("Dequeue"), wxT("Remove an Element from Priority Queue"));

	// append the sub menu items to the stack main menu item
	menuStack->Append(ID_CreateStack, wxT("Create Stack"), wxT("Create Stack"));
	menuStack->Append(ID_PopStack, wxT("Pop Stack"), wxT("Remove the Top Element from Stack"));
	menuStack->Append(ID_DisplayStack, wxT("Display All"), wxT("Show Contents of Stack"));
	menuStack->Append(ID_ShowHeadStack, wxT("Show Head"), wxT("Show Head of Stack"));
	menuStack->Append(ID_ShowTailStack, wxT("Show Tail"), wxT("Show Tail of Stack"));

	// Add the queue submenu to the main menu
	wxMenu *menuMain = new wxMenu;
	menuMain->AppendSubMenu(menuQueue, wxT("&Queue"));

	// ... and now... attach this main menu bar to the frame
	SetMenuBar(menuBar);

	// Create a status bar just for fun
	CreateStatusBar(3);

	// Put something in the first section of the status bar
	SetStatusText(wxT("Ready..."));

	// Put something in the Second section of the status bar
	SetStatusText(wxT("    Ean Bynoe"), 1);

	// Put something in the Third section of the status bar
	SetStatusText(wxT("    400005520"), 2);

	// Set up the panel for data display
	//=========================================================================================
	//=========================== DO NOT CHANGE THE CODE IN THIS SECTION ======================
	//=========================================================================================

	wxPanel *panel = new wxPanel(this, -1);
	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);	  // Vertical sizer for main window
	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for main window

	// Add two textboxes to the panel for data display
	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for filename window
	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for display window

	wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
	wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

	// Initialize the filename textbox window
	filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

	// Initialize the display window
	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
								 wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);

	// Position the labels and textboxes in the panel
	hbox1->Add(fileLabel, 0, wxRIGHT, 8);
	hbox1->Add(filenameTextBox, 1);
	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

	vbox->Add(-1, 10);
	hbox2->Add(displayLabel, 0);
	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
	vbox->Add(-1, 10);

	hbox3->Add(MainEditBox, 1, wxEXPAND);
	vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

	vbox->Add(-1, 25);
	panel->SetSizer(vbox);

	Centre();
}

/************************************************************************************
*************************************************************************************
  Step 7:  Define member functions for the Frame class
*************************************************************************************
*************************************************************************************/

//===================================================================================
//=========== Definition for the File Functions =====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
	// Creates a "open file" dialog with 3 file types
	wxFileDialog *OpenDialog = new wxFileDialog(this,
												(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
												(wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
												wxFD_OPEN, wxDefaultPosition);

	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
	{
		// Sets our current document to the file the user selected
		CurrentDocPath = OpenDialog->GetPath();

		// Clean up filename textbox and Display file name in filename textbox
		filenameTextBox->Clear();
		filenameTextBox->AppendText(CurrentDocPath);

		MainEditBox->LoadFile(CurrentDocPath); // Opens that file in the MainEditBox

		// Set the Title
		SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
	}
}

void ProjectFrame::OnSave(wxCommandEvent &event)
{
	// Save to the already-set path for the document
	MainEditBox->SaveFile(CurrentDocPath);
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
	wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
												wxEmptyString, wxEmptyString,
												(wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
												wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 4 file types
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
		CurrentDocPath = SaveDialog->GetPath();

		// set the path of our current document to the file the user chose to save under
		MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

		// Set the Title to reflect the file open
		SetTitle(wxString(wxT("COMP2611 - Data Structures : 40005520")));
	}
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
	// Creates a "open file" dialog with 4 file types
	wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")),
												wxEmptyString, wxEmptyString,
												(wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
												wxFD_OPEN, wxDefaultPosition);

	MainEditBox->Clear();

	MainEditBox->LoadFile(CurrentDocPath);
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
	wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE); // Close the window
}

/*void ProjectFrame::OnAbout(wxCommandEvent &event)
{
	wxMessageBox(wxT("Ean Bynoe\nTop #1 Billboard Songs from 1990s\nLinux OpenSuse Leap 15.4"), wxT("About"), wxOK | wxICON_INFORMATION, this); // Close the window
}*/

void ProjectFrame::OnCreateQ(wxCommand &event)
{
	ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
	string month, artists, title, label, heading;
	int year, weeks;
	char ch;
	MainEditBox->Clear();

	queue->purge();
	if (!FileOpen)
	{
		MainEditBox->AppendText(wxT("Invalid File!"));
		return;
	}
	getline(FileOpen, heading, '\n');
	while (!FileOpen.eof())
	{
		getline(!FileOpen, month, '*');
		FileOpen >> year >> ch;
		getline(FileOpen, artists, '*');
		getline(FileOpen, title, '*');
		getline(FileOpen, label, '*');
		FileOpen >> weeks;

		if (FileOpen.eof())
		{
			break;
		}

		queue->enqueue(month, year, artists, title, label, weeks);
	}

	FileOpen.close();
	MainEditBox->AppendText(wxT("Queue was created!"));
}
void ProjectFrame::OnDisplayQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = queue -> showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowHeadQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = queue -> showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowTailQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = queue -> showTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);

}

void ProjectFrame::OnDequeQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = queue -> dequeue();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnCreateDQ(wxCommandEvent& event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, title, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    deque -> purge();

    if ( !FileOpen )
    {
            MainEditBox->AppendText (wxT("Invalid File!") );
            return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, title, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        if (year > 1994)
        {
            deque->enqueueHead(month, year, artists, title, label, weeks);
        }
        else
        {
            deque->enqueueTail(month, year, artists, title, label, weeks);
        }
    }

    FileOpen.close();
    MainEditBox->AppendText (wxT("Deque was created!") );
}

void ProjectFrame::OnDisplayDQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = deque -> showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowHeadDQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = deque -> showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowTailDQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = deque -> showTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnDequeueHeadDQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = deque -> dequeueHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnDequeueTailDQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = deque -> dequeueTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnCreatePQ(wxCommandEvent& event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, title, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    priorityqueue -> purge();
    if ( !FileOpen )
    {
            MainEditBox->AppendText (wxT("Invalid File!") );
            return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, title, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        priorityqueue->insert(month, year, artists, title, label, weeks);
    }

    FileOpen.close();
    MainEditBox->AppendText (wxT("Priority Queue was created!") );
}

void ProjectFrame::OnDisplayPQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = priorityqueue -> getAllRecords();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowHeadPQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = priorityqueue -> getFront();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnShowTailPQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = priorityqueue -> getLast();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnDequeuePQ(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = priorityqueue -> dequeue();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnCreateStack(wxCommandEvent& event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, title, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    stack -> purge();
    if ( !FileOpen )
    {
            MainEditBox->AppendText (wxT("Invalid File!") );
            return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, title, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        stack->push(month, year, artists, title, label, weeks);
    }

    FileOpen.close();
    MainEditBox->AppendText (wxT("Stack was created!") );
}

void ProjectFrame::OnPopStack(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = stack -> pop();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnDisplayStack(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = stack -> showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnHeadStack(wxCommandEvent& event)
{

    MainEditBox->Clear();
    string records = stack -> showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}

void ProjectFrame::OnTailStack(wxCommandEvent& event)
{
    MainEditBox->Clear();
    string records = stack -> getLast();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText (wxrecords);
}
