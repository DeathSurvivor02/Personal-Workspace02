#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "Queue.h"
#include "Deque.h"
#include "PQueue.h"
#include "Stack.h"

Deque *deque = new Deque();
Queue *queue = new Queue();
PriorityQueue *priorityqueue = new PriorityQueue();
Stack *stack = new Stack();

class ProjectApp : public wxApp
{
    virtual bool OnInit();
};

class ProjectFrame : public wxFrame
{
private:
    DECLARE_EVENT_TABLE() // to declare event items
public:
    ProjectFrame(const wxString &song, const wxPoint &pos, const wxSize &size);

    // functions for file menu items
    void OnOpenFile(wxCommandEvent &event);
    void OnDisplay(wxCommandEvent &event);
    void OnSave(wxCommandEvent &event);
    void OnSaveAs(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event); // handle for quit function

    // functions for queue menu items
    void OnCreateQ(wxCommandEvent &event);
    void OnDisplayQ(wxCommandEvent &event);
    void OnShowHeadQ(wxCommandEvent &event);
    void OnShowTailQ(wxCommandEvent &event);
    void OnDequeQ(wxCommandEvent &event);

    // functions for deque menu items
    void OnCreateDQ(wxCommandEvent &event);
    void OnDisplayDQ(wxCommandEvent &event);
    void OnShowHeadDQ(wxCommandEvent &event);
    void OnShowTailDQ(wxCommandEvent &event);
    void OnDequeueHeadDQ(wxCommandEvent &event);
    void OnDequeueTailDQ(wxCommandEvent &event);

    // functions for priority queue menu items
    void OnCreatePQ(wxCommandEvent &event);
    void OnDisplayPQ(wxCommandEvent &event);
    void OnShowHeadPQ(wxCommandEvent &event);
    void OnShowTailPQ(wxCommandEvent &event);
    void OnDequeuePQ(wxCommandEvent &event);

    // functions for stack menu items
    void OnCreateStack(wxCommandEvent &event);
    void OnPopStack(wxCommandEvent &event);
    void OnDisplayStack(wxCommandEvent &event);
    void OnHeadStack(wxCommandEvent &event);
    void OnTailStack(wxCommandEvent &event);

    // function for help menu item
    void OnAbout(wxCommandEvent &event);

    // public attributes
    wxTextCtrl *MainEditBox;
    wxTextCtrl *filenameTextBox;
    wxString CurrentDocPath; // the path to the file we have open.
};

// declare compiler directives

DECLARE_APP(ProjectApp)   // Declare Application class
IMPLEMENT_APP(ProjectApp) // Create Application class object

enum
{
    // file menu items
    ID_OpenFile = wxID_HIGHEST + 1, // file menu item
    ID_Display,
    ID_Save,
    ID_SaveAs,
    ID_Exit,

    // queue menu items
    ID_CreateQ,
    ID_DisplayQ,
    ID_ShowHeadQ,
    ID_ShowTailQ,
    ID_DequeQ,

    // deque menu items
    ID_CreateDQ,
    ID_DisplayDQ,
    ID_ShowHeadDQ,
    ID_ShowTailDQ,
    ID_DequeueHeadDQ,
    ID_DequeueTailDQ,

    // priority queue menu items
    ID_CreatePQ,
    ID_DisplayPQ,
    ID_ShowHeadPQ,
    ID_ShowTailPQ,
    ID_DequeuePQ,

    // stack menu items
    ID_CreateStack,
    ID_PopStack,
    ID_DisplayStack,
    ID_HeadStack,
    ID_TailStack,

    // help menu item
    ID_About,
};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile)
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// Events for the "Queue" menu items
EVT_MENU(ID_CreateQ, ProjectFrame::OnCreateQ)
EVT_MENU(ID_DisplayQ, ProjectFrame::OnDisplayQ)
EVT_MENU(ID_ShowHeadQ, ProjectFrame::OnShowHeadQ)
EVT_MENU(ID_ShowTailQ, ProjectFrame::OnShowTailQ)
EVT_MENU(ID_DequeQ, ProjectFrame::OnDequeQ)

// Events for the "Deque" menu items
EVT_MENU(ID_CreateDQ, ProjectFrame::OnCreateDQ)
EVT_MENU(ID_DisplayDQ, ProjectFrame::OnDisplayDQ)
EVT_MENU(ID_ShowHeadDQ, ProjectFrame::OnShowHeadDQ)
EVT_MENU(ID_ShowTailDQ, ProjectFrame::OnShowTailDQ)
EVT_MENU(ID_DequeueHeadDQ, ProjectFrame::OnDequeueHeadDQ)
EVT_MENU(ID_DequeueTailDQ, ProjectFrame::OnDequeueTailDQ)

// Events for the "Priority Queue" menu items
EVT_MENU(ID_CreatePQ, ProjectFrame::OnCreatePQ)
EVT_MENU(ID_DisplayPQ, ProjectFrame::OnDisplayPQ)
EVT_MENU(ID_ShowHeadPQ, ProjectFrame::OnShowHeadPQ)
EVT_MENU(ID_ShowTailPQ, ProjectFrame::OnShowTailPQ)
EVT_MENU(ID_DequeuePQ, ProjectFrame::OnDequeuePQ)

// Events for the "Stack" menu items
EVT_MENU(ID_CreateStack, ProjectFrame::OnCreateStack)
EVT_MENU(ID_PopStack, ProjectFrame::OnPopStack)
EVT_MENU(ID_DisplayStack, ProjectFrame::OnDisplayStack)
EVT_MENU(ID_HeadStack, ProjectFrame::OnHeadStack)
EVT_MENU(ID_TailStack, ProjectFrame::OnTailStack)

// Event for the "Help" menu item
EVT_MENU(ID_About, ProjectFrame::OnAbout)

END_EVENT_TABLE()

// define the application class function to initialize the application

bool ProjectApp::OnInit()
{
    // create the main application window
    ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures Project #1"), wxPoint(50, 50), wxSize(840, 600));

    // display the window
    frame->Show(TRUE);
    SetTopWindow(frame);
    return TRUE;
}

// define the constructor functions from the frame class

ProjectFrame::ProjectFrame(const wxString &song, const wxPoint &pos, const wxSize &size) : wxFrame((wxFrame *)NULL, -1, song, pos, size)
{

    // create the main-menu items
    wxMenu *menuFile = new wxMenu;
    wxMenu *menuQueue = new wxMenu;
    wxMenu *menuDeque = new wxMenu;
    wxMenu *menuPriorityQueue = new wxMenu;
    wxMenu *menuStack = new wxMenu;
    wxMenu *menuHelp = new wxMenu;

    // create a main menu bar
    wxMenuBar *menuBar = new wxMenuBar;

    // append the main menu items to the menu menu bar
    menuBar->Append(menuFile, wxT("File"));
    menuBar->Append(menuQueue, wxT("Queue"));
    menuBar->Append(menuDeque, wxT("Deque"));
    menuBar->Append(menuPriorityQueue, wxT("Priority Queue"));
    menuBar->Append(menuStack, wxT("Stack"));
    menuBar->Append(menuHelp, wxT("Help"));

    // apprend the sub menu items to the file main menu item
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

    // apppend the sub menu items to the stack main menu item
    menuStack->Append(ID_CreateStack, wxT("Create Stack"), wxT("Create Stack"));
    menuStack->Append(ID_PopStack, wxT("Pop Stack"), wxT("Remove the Top Element from Stack"));
    menuStack->Append(ID_DisplayStack, wxT("Display All"), wxT("Show Contents of Stack"));
    menuStack->Append(ID_HeadStack, wxT("Show Head"), wxT("Show Head of Stack"));
    menuStack->Append(ID_TailStack, wxT("Show Tail"), wxT("Show Tail of Stack"));

    // appent the sub menu item to the help main menu item
    menuHelp->Append(ID_About, wxT("About"), wxT("About the User and Program"));

    // attaches main menu bar to the frame
    SetMenuBar(menuBar);

    // create status bar
    CreateStatusBar(3);

    // first section of status bar
    SetStatusText(wxT("Ready..."));

    // second section ofthe status bar
    SetStatusText(wxT(" Ean Bynoe"), 1);

    // third section of the status bar
    SetStatusText(wxT(" 400005520"), 2);

    // set up panel for display
    // DO NOT CHANGE THIS SECTION

    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);    // vertical sizer for window
    wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL); // horizontal sizer for window

    // add two textboxes to the panel for data display
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for filename window
    wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for display window

    wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
    wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

    // initialize filename textbox window
    filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

    // initialize the display window
    MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);

    // position the labels and textboxes in the panel
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

// define member functions for the frame class

// definition for the file functions

void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
    // creates a "open file" dialog with 3 file types
    wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString, (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "canel"
    {
        // sets our current document to the file the user selected
        CurrentDocPath = OpenDialog->GetPath();

        // clean up filename textbox and display file name in filename textbox
        filenameTextBox->Clear();
        filenameTextBox->AppendText(CurrentDocPath);

        MainEditBox->LoadFile(CurrentDocPath); // opens that file in the main edit textbox

        // set the song
        SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
    }
}

void ProjectFrame::OnSave(wxCommandEvent &event)
{
    // save to the already-set path fot the document
    MainEditBox->SaveFile(CurrentDocPath);
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
    wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), wxEmptyString, wxEmptyString, (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

    // creates a save dialog with 4 file types
    if (SaveDialog->ShowModal() == wxID_OK) // if the user clicked "OK"
    {
        CurrentDocPath = SaveDialog->GetPath();

        // set the path of our current document to the file the user chose to save under
        MainEditBox->SaveFile(CurrentDocPath); // save the file to the selected path

        // set the song to reflect the file open
        SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
    }
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
    // creats a "open file" dialog with 4 file types
    wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString, (wxT("Text files (*.txt)|*.txt|Data Files (*dat)|*.dat|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

    MainEditBox->Clear();

    MainEditBox->LoadFile(CurrentDocPath);
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
    wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
    Close(TRUE); // Close the window
}

void ProjectFrame::OnAbout(wxCommandEvent &event)
{

    wxMessageBox(wxT("Ean Bynoe\n Billboard Songs from the 1990s\nLinux OpenSuse Leap"), wxT("About"), wxOK | wxICON_INFORMATION, this);
}

void ProjectFrame::OnCreateQ(wxCommandEvent &event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, song, label, heading;
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
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, song, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        queue->enqueue(month, year, artists, song, label, weeks);
    }

    FileOpen.close();
    MainEditBox->AppendText(wxT("Queue was created!"));
}

void ProjectFrame::OnDisplayQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = queue->showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowHeadQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = queue->showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowTailQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = queue->showTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnDequeQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = queue->dequeue();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnCreateDQ(wxCommandEvent &event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, song, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    deque->purge();

    if (!FileOpen)
    {
        MainEditBox->AppendText(wxT("Invalid File!"));
        return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, song, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        if (year > 1994)
        {
            deque->enqueueHead(month, year, artists, song, label, weeks);
        }
        else
        {
            deque->enqueueTail(month, year, artists, song, label, weeks);
        }
    }

    FileOpen.close();
    MainEditBox->AppendText(wxT("Deque was created!"));
}

void ProjectFrame::OnDisplayDQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = deque->showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowHeadDQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = deque->showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowTailDQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = deque->showTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnDequeueHeadDQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = deque->dequeueHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnDequeueTailDQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = deque->dequeueTail();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnCreatePQ(wxCommandEvent &event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, song, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    priorityqueue->purge();
    if (!FileOpen)
    {
        MainEditBox->AppendText(wxT("Invalid File!"));
        return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, song, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        priorityqueue->insert(month, year, artists, song, label, weeks);
    }

    FileOpen.close();
    MainEditBox->AppendText(wxT("Priority Queue was created!"));
}

void ProjectFrame::OnDisplayPQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = priorityqueue->getAllRecords();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowHeadPQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = priorityqueue->getFront();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnShowTailPQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = priorityqueue->getLast();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnDequeuePQ(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = priorityqueue->dequeue();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnCreateStack(wxCommandEvent &event)
{

    ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
    string month, artists, song, label, heading;
    int year, weeks;
    char ch;
    MainEditBox->Clear();

    stack->purge();
    if (!FileOpen)
    {
        MainEditBox->AppendText(wxT("Invalid File!"));
        return;
    }

    getline(FileOpen, heading, '\n');

    while (!FileOpen.eof())
    {
        getline(FileOpen, month, '*');
        FileOpen >> year >> ch;
        getline(FileOpen, artists, '*');
        getline(FileOpen, song, '*');
        getline(FileOpen, label, '*');
        FileOpen >> weeks;

        if (FileOpen.eof())
        {
            break;
        }

        stack->push(month, year, artists, song, label, weeks);
    }

    FileOpen.close();
    MainEditBox->AppendText(wxT("Stack was created!"));
}

void ProjectFrame::OnPopStack(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = stack->pop();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnDisplayStack(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = stack->showAll();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnHeadStack(wxCommandEvent &event)
{

    MainEditBox->Clear();
    string records = stack->showHead();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}

void ProjectFrame::OnTailStack(wxCommandEvent &event)
{
    MainEditBox->Clear();
    string records = stack->getLast();
    wxString wxrecords(records.c_str(), wxConvUTF8);
    MainEditBox->AppendText(wxrecords);
}
