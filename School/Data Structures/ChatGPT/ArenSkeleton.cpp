#include <wx/wxprec.h>


#include <wx/wx.h>


#include <iostream>
#include <fstream>
#include <string>


//Include the ADTS Header files
//#include "Node.h"
//#include "Queue.h"
//#include "PQueue.h"
//#include "Deque.h"
//#include "Stack.h"

using namespace std;



/*
Step 2 Naming inherited application class from wxApp
*/

class ProjectApp: public wxApp
{
    virtual bool OnInit();
};



/*
Step 3 Declare the inherited main frame class from wxFrame.
*/
class ProjectFrame: public wxFrame
    {
        private:
                DECLARE_EVENT_TABLE() // TO declare event items

        public:
            ProjectFrame(const wxString& title, const wxPoint& pos, const wxSize& size);


        //Functions for File menu Items
        void OnOpenFile(wxCommandEvent& event);
        void OnDisplay(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event); //handle for Quit function

        //Functions for Queue Menu Items
        void OnCreateQueue(wxCommandEvent& event);
        void OnDisplayAll(wxCommandEvent& event);
        void OnShowHead(wxCommandEvent& event);
        void OnShowTail(wxCommandEvent& event);
        void OnDequeue(wxCommandEvent& event);

        //Function for Deque Menu Items
        void OnCreateDeque(wxCommandEvent& event);
        void OnDisplayAllD(wxCommandEvent& event);
        void OnShowHeadD(wxCommandEvent& event);
        void OnShowTailD(wxCommandEvent& event):
        void OnDequeueHeadD(wxCommandEvent& event);
        void OnDequeueTailD(wxCommandEvent& event);

        //Functions for Priority Queue Menu Items
        void OnCreatePQ(wxCommandEvent& event);
        void OnDisplayAllPQ(wxCommandEvent& event);
        void OnShowHeadPQ(wxCommandEvent& event);
        void OnShowTailPQ(wxCommandEvent& event);
        void OnDequeuePQ(wxCommandEvent& event);

        //Functions for Stack Menu Items
        void OnCreateStack(wxCommandEvent& event);
        void OnPop(wxCommandEvent& event);
        void OnDisplayAllS(wxCommandEvent& event);
        void OnShowHeadS(wxCommandEvent& event);
        void OnShowTailS(wxCommandEvent& event);


        //Public Attributes
        wxTextCtrl* MianEditBox;
        wxTextCtrl* filenameTextBox;
        wxString CurrentDocPath; // The path to the file we have open

    };

/**
Step 4 Declare the compiler directives
**/

DECLARE_APP(ProjectApp)      //Declare App class
Implement_APP(MyApp)         //create appl class object

enum
    {
        //File menu items
            ID_OpenFile = wxID_HIGHEST + 1,     //File menu enumaeration
            ID_Display,
            ID_Save,
            ID_SaveAs,
            ID_Exit,

        //Queue Menu Items
            ID_CreateQueue,
            ID_DisplayAll,
            ID_ShowHead,
            ID_ShowTail,
            ID_Dequeue,

        //Deque Menu Items
            ID_CreateDeque,
            ID_DisplayAllD,
            ID_ShowHeadD,
            ID_ShowTailD,
            ID_DequeueHeadD,
            ID_DequeueTailD,

        //Priority Queue Items
            ID_CreatePriorityQueue,
            ID_DisplayAllQ,
            ID_ShowHeadQ,
            ID_ShowTailQ,
            ID_DequeueQ,

        //Stack Menu Items
            ID_CreateStack,
            ID_Pop,
            ID_DisplayAllS,
            ID_ShowHeadS,
            ID_ShowTailS,

    };

/**
Step 5 Define the event table
**/
BEGIN_EVENT_TABLE (ProjectFrame, wxFrame)
    //Events for the "File" menu items
    EVT_MENU (wxID_OpenFile, ProjectFrame::OnOpenFile) //File Menu
    EVT_MENU (wxID_Display, ProjectFrame::OnDisplay)
    EVT_MENU (wxID_Save, ProjectFrame::OnSave)
    EVT_MENU (wxID_SaveAs, ProjectFrame::OnSaveAs)
    EVT_MENU (wxID_Exit, ProjectFrame::OnExit)

    //Events for the "Queue" menu items
    EVT_MENU (wxID_CreateQueue, ProjectFrame::OnCreateQueue) //Queue menu
    EVT_MENU (wxID_DisplayAll, ProjectFrame::OnDisplayAll)
    EVT_MENU (wxID_ShowHead, ProjectFrame::OnShowHead)
    EVT_MENU (wxID_ShowTail, ProjectFrame::OnShowTail)
    EVT_MENU (wxID_Dequeue, ProjectFrame::OnDequeue)

    //Events for the "Deque" menu items
    EVT_MENU (wxID_CreateDequeD, ProjectFrame::OnCreateDequeD)
    EVT_MENU (wxID_DiisplayAllD, ProjectFrame::OnDisplayAllD)
    EVT_MENU (wxID_ShowHeadD, ProjectFrame::OnShowHeadD)
    EVT_MENU (wxID_ShowTailD, ProjectFrame::OnShowTailD)
    EVT_MENU (wxID_DequeueHeadD, ProjectFrame::OnDequeueHeadD)
    EVT_MENU (wxID_DequeueTailD, ProjectFrame::OnDequeueTailD)

    //Events for the "Priority" menu items
    EVT_MENU (wxID_CreatePQ, ProjectFrame::OnCreatePQ)
    EVT_MENU (wxID_DisplayAllPQ, ProjectFrame::OnDisplayAllPQ)
    EVT_MENU (wxID_ShowHeadPQ, ProjectFrame::OnShowHeadPQ)
    EVT_MENU (wxID_ShowTailPQ, ProjectFrame::OnShowTailPQ)
    EVT_MENU (wxID_DequeuePQ, ProjectFrame::OnDequeuePQ)

    //Events for the "Stack" menu items
    EVT_MENU (wxID_CreateStack, ProjectFrame::OnCreateStack)
    EVT_MENU (wxID_Pop, ProjectFrame::OnPop)
    EVT_MENU (wxID_DisplayAllS, ProjectFrame::OnDisplayAllS)
    EVT_MENU (wxID_ShowHeadS, ProjectFrame::OnShowHeadS)
    EVT_MENU (wxID_ShowTailS, ProjectFrame::OnShowTailS)


END_EVENT_TABLE()



/**
Step 6 Define the App class function to initialize the app
**/
bool ProjectApp::OnInit()
    {
        //  Create the main application window
        ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Data Structures"), wxPoint(50,50), wxSize(840,600) );

        //Display the window
        frame->Show(TRUE);

        SetTopWindow(frame);

        //start the event loop
        return TRUE;

    }

/**
Step 8 Define the constructor functions for the frame class
**/
ProjectFrame::ProjectFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
            :wxFrame((wxFrame *)NULL, -1, title, pos, size)
   {
        //Create the menu items for menu bar
        wxMenu *menuFile = new wxMenu;
        wxMenu *menuHelp = new wxMenu;
        wxMenu *menuQueue = new wxMenu;
        wxMenu *menuDeque = new wxMenu;
        wxMenu *menuPriorityQueue = new wxMenu;
        wxMenu *menuStack = new wxMenu;

        //Create the menu to the menu bar
        wxMenuBar *menuBar = new wxMenuBar();

        //Apend the menu to the menu bar
        menuBar->Append(menuFile, wxT("&File"));
        menuBar->Append(menuHelp, wxT("&Help"));
        menuBar->Append(menuQueue, wxT("Queue"));
        menuBar->Append(menuDeque, wxT("Deque"));
        menuBar->Append(menuPriorityQueue, wxT("Priority Queue"));
        menuBar->Append(menuStack, wxT("Stack"));
        
        menuHelp->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog") );

        //Append the sub-menu items to the file Main menu item
        menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file") );
        menuFile->Append(ID_Display, wxT("&Display File..."), wxT("Display contents of opened file") );
        menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file") );
        menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file") );
        menuFile->Append(ID_Exit, wxT("&Exit"), wxT("Close and EXIT Program") );

        //Append the sub-menu items to the "Queue" main menu item
        menuQueue->Append(ID_CreateQueue, wxT("&Create Queue..."), wxT("Creating a Queue") );
        menuQueue->Append(ID_DisplayAll, wxT("&Display File..."), wxT("Display contents of opened file") );
        menuQueue->Append(ID_ShowHead, wxT("&Show Head"), wxT("Show the head of the opened file") );
        menuQueue->Append(ID_ShowTail, wxT("&Show Tail"), wxT("Show the tail of the opened file") );
        menuQueue->Append(ID_Dequeue, wxT("&Dequeue"), wxT("Add to the head or tail of the opened file") );

        //Append the sub-menu items to the "Deque" main menu item
        menuDeque->Append(ID_CreateDeque, wxT("&Create Deque"), wxT("Open an Existing file") );
        menuDeque->Append(ID_DisplayAllD, wxT("&Display File..."), wxT("Display contents of opened file") );
        menuDeque->Append(ID_ShowHeadD, wxT("&Show Head"), wxT("Shows the head of the file") );
        menuDeque->Append(ID_ShowTailD, wxT("&Show Tail"), wxT("Show the tail of the file") );
        menuDeque->Append(ID_DequeueHeadD, wxT("&Dequeue Head"), wxT("Dequeue the head of the file") );
        menuDeque->Append(ID_DequeueTailD, wxT("&DEqueue Tail"), wxT("Dequeue the tail of the file") );

        //Append the sub-menu items to the "Priority Queue" main menu item
        menuPriorityQueue->Append(ID_CreatePQ, wxT("&Create PQ"), wxT("Create a Priority Queue") );
        menuPriorityQueue->Append(ID_DisplayAllPQ, wxT("&Display File..."), wxT("Display contents of the opened file in descending order") );
        menuPriorityQueue->Append(ID_ShowHeadPQ, wxT("&Show Head"), wxT("Show the head of the opened file") );
        menuPriorityQueue->Append(ID_ShowTailPQ, wxT("&Show Tail"), wxT("Show the tail of the opened file") );
        menuPriorityQueue->Append(ID_DequeuePQ, wxT("&Dequeue"), wxT("Add to the head or tail of the opened file") );

        //Append the sub-menu items to the "Stack" main menu item
        menuStack->Append(ID_CreateStack, wxT("&Create Stack"), wxT("Creating a Stack") );
        menuStack->Append(ID_Pop, wxT("Pop"), wxT("Pop the last entry made to the stack") );
        menuStack->Append(ID_DisplayAllS, wxT("&Display File..."), wxT("Display contents of opened file") );
        menuStack->Append(ID_ShowHeadS, wxT("&Show Head"), wxT("Show the head of the opened file") );
        menuStack->Append(ID_ShowTailS, wxT("&Show Tail"), wxT("Show the tail of the opened file") );


    //append the sub menu items to the queue main menu item
    menuQueue->Append (ID_CreateQ, wxT("Create Queue"), wxT("Create Queue") );
    menuQueue->Append (ID_DisplayQ, wxT("Display All"), wxT("Show contents of Queue") );
    menuQueue->Append (ID_ShowHeadQ, wxT("Show Head"), wxT("Display Top of Queue") );
    menuQueue->Append (ID_ShowTailQ, wxT("Show Tail"), wxT("Display Bottom of Queue") );
    menuQueue->Append (ID_DequeQ, wxT("Dequeue"), wxT("Remove an Element from Queue") );

    //append the sub menu items to the deque main menu item
    menuDeque->Append (ID_CreateDQ, wxT("Create Deque"), wxT("Create Deque") );
    menuDeque->Append (ID_DisplayDQ, wxT("Display All"), wxT("Display Deque") );
    menuDeque->Append (ID_ShowHeadDQ, wxT("Show Head"), wxT("Display Top of Deque") );
    menuDeque->Append (ID_ShowTailDQ, wxT("Show Tail"), wxT("Display Bottom of Deque") );
    menuDeque->Append (ID_DequeueHeadDQ, wxT("Dequeue Head"), wxT("Remove an Element from Top of Deque") );
    menuDeque->Append (ID_DequeueTailDQ, wxT("Dequeue Tail"), wxT("Remove an Element from Bottom of Deque") );

    //append the sub menu items to the priority queue main menu item
    menuPriorityQueue->Append (ID_CreatePQ, wxT("Create Priority Queue"), wxT("Create Priority Queue") );
    menuPriorityQueue->Append (ID_DisplayPQ, wxT("Display All"), wxT("Display Priority Queue") );
    menuPriorityQueue->Append (ID_ShowHeadPQ, wxT("Show Head"), wxT("Display Top of Priority Queue") );
    menuPriorityQueue->Append (ID_ShowTailPQ, wxT("Show Tail"), wxT("Display Bottom of Priority Queue") );
    menuPriorityQueue->Append (ID_DequeuePQ, wxT("Dequeue"), wxT("Remove an Element from Priority Queue") );

    //append the sub menu items to the stack main menu item
    menuStack->Append (ID_CreateStack, wxT("Create Stack"), wxT("Create Stack") );
    menuStack->Append (ID_PopStack, wxT("Pop Stack"), wxT("Remove the Top Element from Stack") );
    menuStack->Append (ID_DisplayStack, wxT("Display All"), wxT("Show Contents of Stack") );
    menuStack->Append (ID_HeadStack, wxT("Show Head"), wxT("Show Head of Stack") );
    menuStack->Append (ID_TailStack, wxT("Show Tail"), wxT("Show Tail of Stack") );


        //attach this menu bar to the frame
        SetMenuBar(menuBar);

        //Create a status menuBar
        CreateStatusBar(3);

        //Put something in the first section of the status bar
	SetStatusText( wxT("Ready..."));
	
	//Put something in the Second section of the status bar
	SetStatusText( wxT("    Aren Brathwaite"), 1 );
	
	//Put something in the Third section of the status bar
	SetStatusText( wxT("    400011023"), 2 );


        //Set up the panel for the data dispaly
        wxPanel *panel = new wxPanel(this, -1);
        wxBoxsizer *vbox = new wxBoxsizer(wxVERTICAL); //vertical sizer for the menu bar
        wxBoxsizer *hbox = new wxBoxsizer(wxHORIZONTAL); //horizontal sizer for the menu bar

        //Adding 2 text boxes to the panel for data display
        wxBoxsizer *hbox2 = new wxBoxsizer(wxHORIZONTAL); //sizer for filename window
        wxBoxsizer *hbox3 = new wxBoxsizer(wxHORIZONTAL); //sizer for display window

        wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
        wxStaticText *displayLabel = new wx wxStaticText(panel, wxID_ANY, wxT("Display"));

        //Initialize the filename window
        filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet...") );

        //Initialize the display window
        MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Avaliable Yet..."),
                                     wxPoint(-1, -1), wxSize(-1, -1), wxTe_MULTILINE | wxTE_RICH);

        //Posiotion the labels and textboxes in the panel
        hbox1->Add(fileLabel, 0, wxRIGHT, 8);
        hbox1->Add(filenameTextBox, 1);
        vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10)

        vbox->Add(-1, 10);
        hbox2->Add(displayLabel, 0);
        vbox->Add(hbox2, 0, wxLEFT | wxTop, 10);
        vbox->Add(-1, 10);

        hbox3->Add(MainEditBox);
        vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

        vbox->Add(-1, 25);
        panel->SetSizer(vbox);

        Centre();

    }


/**
Step 7 Define member functions for the entire class
**/
void ProjectFrame::OnOpenFile(wxCommandEvent& event)
    {
        //Creates a "open file" dialog with 3 file types
        wxFileDialog *OpenDialog = new wxFileDialog(this,
                (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                (wxT("Data Files (*.dat) | *.dat|Text files (*.txt) |*.txt| All files (*.*)|(*.*)") ),
                wxFD_OPEN, wxDefaultPosition);

        if (OpenDialog->ShowModal() == wxID_OK) //if the user clicks"Open" instead on "cancel"
            {
                //Sets our current doc to the file the user selected
                CurrentDocPath = OpenDialog->GetPath();

                //Clean up filename textbox and Display file name in filename textbox
                filenameTextBox->Clear();
                filenameTextBox->AppendText(CurrentDocPath);

                MainEditBox->LoadFile(CurrentDocPath); //opens the file in the MainEditBox

                //Set the title
                SetTitle(wxString(wxT("COMP2611 - Data Structures : 400011023")) );
            }
    }


void ProjectFrame::OnSave(wxCommandEvent& event )
    {
        //Save to the already set path for the document
        MainEditBox->SaveFile(CurrentDocPath);
    }


void ProjectFrame::OnSaveAs(wxCommandEvent& event)
    {
        wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                                                    wxEmptyString, wxEmptyString,
                                                    (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                                                    wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

        //Creates a Save Dialog with 4 files types
        if (SaveDialog->ShowModal() == wxID_OK) //If the user clicked "OK"
            {
                CurrentDocPath = SaveDialog->GetPath();

                //set the path of our current document to the file the user chose to save under
                MainEditBox->SaveFile(CurrentDocPath); //Save the file to the selected path

                //Set the Title to reflect the file open
                SetTitle(wxString(wxT("COMP2611 - Data Structures : 400011023")) );

            }
    }

void ProjectFrame::OnDisplay(wxCommandEvent& event)
    {
        //Creates a "open file" dialog with 4 files types
        wxFileDialog *OpenDialog = new wxFileDialog (this, (wxT("Choose a file to open")),
                    wxEmptyString, wxEmptyString,
                    (WxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat | All files (*.*)|*.*") ),
                    wxFD_OPEN, wxDefaultPosition);

        MainEditBox->Clear();

        MainEditBox->LoadedFile(CurrentDocPath);
    }


void ProjectFrame::OnExit(wxCommandEvent& event)
    {
        wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this,);
        Close(TRUE); //close the window
    }

//member functions for Queue class
void ProjectFrame::OnCreateQueue(){}
void ProjectFrame::OnDisplayAll(){}
void ProjectFrame::OnShowHead(){}
void ProjectFrame::OnShowTail(){}
void ProjectFrame::OnDequeue(){}

//member functions for Deque class
void ProjectFrame::OnCreateDequeD(){}
void ProjectFrame::OnDisplayAllD(){}
void ProjectFrame::OnShowHeadD(){}
void ProjectFrame::OnShowTailD(){}
void ProjectFrame::OnDequeueHeadD(){}
void ProjectFrame::OnDequeueTailD(){}

//member functions for Priority Queue class
void ProjectFrame::OnCreatePQ(){}
void ProjectFrame::OnDisplayAllPQ(){}
void ProjectFrame::OnShowHeadPQ(){}
void ProjectFrame::OnShowTailPQ(){}
void ProjectFrame::OnDequeuePQ(){}

//member functions for stack class
void ProjectFrame::OnCreateStack(){}
void ProjectFrame::OnPop(){}
void ProjectFrame::OnDisplayAllS(){}
void ProjectFrame::OnShowHeadS(){}
void ProjectFrame::OnShowTailS(){}
