//
//
//  COMP2611 - Project #2
//
//  Created by Shimer Lyttle on 03/20/2023.
//  Copyright (c) 2023 University of the West Indies. All rights reserved.
//

// ==============================================================================
/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>
#include <wx/wfstream.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

// Other miscellaneous functions' protypes, if required

// Include the ADTs header files
// #include "Node.h" 
// #include "Deque.h"
// #include "Queue.h"
// #include "Stack.h"
#include "BSTree.h"
#include "AVLTree.h"
// #include "Edit.h"
#include "RedBlackTreeTest.h"

// Global pointers for the ADT containers
// template <typename K>
//  Deque* deque=new Deque();
//  Stack* stack=new Stack();
//  PQueue* pqueue=new PQueue();
// record<K>* rec = new record<K>();
// AVL *avl = new AVL();

/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
	  the function to execute the program
*************************************************************************************
*************************************************************************************/
class ProjectApp : public wxApp
{
	virtual bool OnInit();
};

/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class
	   also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
class ProjectFrame : public wxFrame
{
private:
	DECLARE_EVENT_TABLE() // To declare events items

public:
	ProjectFrame(const wxString &title, const wxPoint &pos,
				 const wxSize &size);

	// Functions for File Menu Items
	void OnOpenFile(wxCommandEvent &event);
	void OnDisplay(wxCommandEvent &event);
	void OnSave(wxCommandEvent &event);
	void OnSaveAs(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event);

	// Functions for Edit Menu Items
	void OnECreateADTs(wxCommandEvent &event);
	void OnERecordAdd(wxCommandEvent &event);
	void OnERecordDelete(wxCommandEvent &event);

	// Functions for Binary Search Trees Menu Items
	void OnBSTInorder(wxCommandEvent &event);
	void OnBSTPreorder(wxCommandEvent &event);
	void OnBSTPostorder(wxCommandEvent &event);

	// Functions for AVL Tree Menu Items
	void OnAVLTInorder(wxCommandEvent &event);
	void OnAVLTPreorder(wxCommandEvent &event);
	void OnAVLTPostorder(wxCommandEvent &event);

	// Function for the RE Tree Menu Items
	void OnRBTInorder(wxCommandEvent &event);
	void OnRBTPreorder(wxCommandEvent &event);
	void OnRBTPostorder(wxCommandEvent &event);

	// Functions for the Splay Tree Menu Items
	void OnSTInorder(wxCommandEvent &event);
	void OnSTPreorder(wxCommandEvent &event);
	void OnSTPostorder(wxCommandEvent &event);

	// Functions for the Heap Menu Items
	void OnHDisplay(wxCommandEvent &event);
	void OnHSort(wxCommandEvent &event);

	// Functions for the Set Menu Items
	void OnSDisplaySetA(wxCommandEvent &event);
	void OnSDisplaySetB(wxCommandEvent &event);
	void OnSDisplayIntersect(wxCommandEvent &event);
	void OnSDisplayUnion(wxCommandEvent &event);

	// Function for Help Menu Item
	void OnAbout(wxCommandEvent &event);

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

	// Edit menu items
	ID_ECreateADTs,
	ID_ERecordAdd,
	ID_ERecordDelete,

	// Binary Search Tree menu items
	ID_BSTInorder,
	ID_BSTPreorder,
	ID_BSTPostorder,

	// AVL Tree menu items
	ID_AVLTInorder,
	ID_AVLTPreorder,
	ID_AVLTPostorder,

	// Red-Black Tree menu items
	ID_RBTInorder,
	ID_RBTPreorder,
	ID_RBTPostorder,

	// Spray Tree menu items
	ID_STInorder,
	ID_STPreorder,
	ID_STPostorder,

	// Heap menu items
	ID_HDisplayAll,
	ID_HSort,

	// Set menu items
	ID_SDisplayA,
	ID_SDisplayB,
	ID_SDisplayIntersect,
	ID_SDisplayUnion,

	// Help menu items
	ID_About,

};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile)
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// Events for the "Edit" menu items
EVT_MENU(ID_ECreateADTs, ProjectFrame::OnECreateADTs)
EVT_MENU(ID_ERecordAdd, ProjectFrame::OnERecordAdd)
EVT_MENU(ID_ERecordDelete, ProjectFrame::OnERecordDelete)

// Events for the "Binary Search Tree" menu items
EVT_MENU(ID_BSTInorder, ProjectFrame::OnBSTInorder)
EVT_MENU(ID_BSTPreorder, ProjectFrame::OnBSTPreorder)
EVT_MENU(ID_BSTPostorder, ProjectFrame::OnBSTPostorder)

// Events for the "AVL Tree" menu items
EVT_MENU(ID_AVLTInorder, ProjectFrame::OnAVLTInorder)
EVT_MENU(ID_AVLTPreorder, ProjectFrame::OnAVLTPreorder)
EVT_MENU(ID_AVLTPostorder, ProjectFrame::OnAVLTPostorder)

// Events for the "Red-Black Tree" menu items
EVT_MENU(ID_RBTInorder, ProjectFrame::OnRBTInorder)
EVT_MENU(ID_RBTPreorder, ProjectFrame::OnRBTPreorder)
EVT_MENU(ID_RBTPostorder, ProjectFrame::OnRBTPostorder)

// Event for the "Splay Tree" menu items
EVT_MENU(ID_STInorder, ProjectFrame::OnSTInorder)
EVT_MENU(ID_STPreorder, ProjectFrame::OnSTPreorder)
EVT_MENU(ID_STPostorder, ProjectFrame::OnSTPostorder)

// Event for the "Heap" menu items
EVT_MENU(ID_HDisplayAll, ProjectFrame::OnHDisplay)
EVT_MENU(ID_HSort, ProjectFrame::OnHSort)

// Event for the "Set" menu items
EVT_MENU(ID_SDisplayA, ProjectFrame::OnSDisplaySetA)
EVT_MENU(ID_SDisplayB, ProjectFrame::OnSDisplaySetB)
EVT_MENU(ID_SDisplayIntersect, ProjectFrame::OnSDisplayIntersect)
EVT_MENU(ID_SDisplayUnion, ProjectFrame::OnSDisplayUnion)

// Event for the "Help" menu items
EVT_MENU(ID_About, ProjectFrame::OnAbout)
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
	ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"),
										   wxPoint(50, 50),
										   wxSize(840, 600));

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
	wxMenu *menuHelp = new wxMenu;
	wxMenu *menuEdit = new wxMenu;
	wxMenu *menuBST = new wxMenu;
	wxMenu *menuAVLT = new wxMenu;
	wxMenu *menuRBT = new wxMenu;
	wxMenu *menuST = new wxMenu;
	wxMenu *menuHeap = new wxMenu;
	wxMenu *menuSet = new wxMenu;

	// Create a Main menu bar
	wxMenuBar *menuBar = new wxMenuBar;

	// Append the main menu items to the Menu Bar
	menuBar->Append(menuFile, wxT("File"));
	menuBar->Append(menuEdit, wxT("Edit"));
	menuBar->Append(menuBST, wxT("BST"));
	menuBar->Append(menuRBT, wxT("RB-Tree"));
	menuBar->Append(menuAVLT, wxT("AVL-Tree"));
	menuBar->Append(menuST, wxT("Splay-Tree"));
	menuBar->Append(menuSet, wxT("Set"));
	menuBar->Append(menuHeap, wxT("MinHeap"));
	menuBar->Append(menuHelp, wxT("Help"));

	// Append the sub-menu items to the File Main Menu item
	menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file"));
	menuFile->Append(ID_Display, wxT("&Display File..."), wxT("Display contents of opened file"));
	menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
	menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));
	menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

	// Append the sub-menu items to the Edit Main Menu items
	menuEdit->Append(ID_ECreateADTs, wxT("Create ADTs..."), wxT("Populates all the ADTs"));
	menuEdit->Append(ID_ERecordAdd, wxT("Add Record..."), wxT(""));
	menuEdit->Append(ID_ERecordDelete, wxT("Delete Record..."), wxT(""));

	// Append the sub-menu items of the Binary Search Tree Main Menu items
	menuBST->Append(ID_BSTInorder, wxT("Inorder..."), wxT(""));
	menuBST->Append(ID_BSTPreorder, wxT("Preorder..."), wxT(""));
	menuBST->Append(ID_BSTPostorder, wxT("Postorder..."), wxT(""));

	// Append the sub-menu items to the AVL Tree Main Menu items
	menuAVLT->Append(ID_AVLTInorder, wxT("Inorder..."), wxT(""));
	menuAVLT->Append(ID_AVLTPreorder, wxT("Preorder..."), wxT(""));
	menuAVLT->Append(ID_AVLTPostorder, wxT("Postorder..."), wxT(""));

	// Append the sub-menu items to the RB Tree Main Menu items
	menuRBT->Append(ID_RBTInorder, wxT("Inorder..."), wxT(""));
	menuRBT->Append(ID_RBTPreorder, wxT("Preorder..."), wxT(""));
	menuRBT->Append(ID_RBTPostorder, wxT("Postorder..."), wxT(""));

	// Append the sub-menu items to the Splay Tree Main Menu items
	menuST->Append(ID_STInorder, wxT("Inorder..."), wxT(""));
	menuST->Append(ID_STPreorder, wxT("Preorder..."), wxT(""));
	menuST->Append(ID_STPostorder, wxT("Postorder..."), wxT(""));

	// Append the sub-menu items to the Heap Main Menu items
	menuHeap->Append(ID_HDisplayAll, wxT("Display All..."), wxT(""));
	menuHeap->Append(ID_HSort, wxT("Heap Sort..."), wxT(""));

	// Append the sub-menu items to the Set Main Menu items
	menuSet->Append(ID_SDisplayA, wxT("Display SetA..."), wxT(""));
	menuSet->Append(ID_SDisplayB, wxT("Display SetB..."), wxT(""));
	menuSet->Append(ID_SDisplayIntersect, wxT("Display Intersection..."), wxT(""));
	menuSet->Append(ID_SDisplayUnion, wxT("Display Union..."), wxT(""));

	// Append the sub-menu items to the Help Main Menu items
	menuHelp->Append(ID_About, wxT("About..."), wxT(""));
	menuHelp->Append(ID_Exit, wxT("Exit..."), wxT(""));

	// ... and now... attach this main menu bar to the frame
	SetMenuBar(menuBar);

	// Create a status bar just for fun
	CreateStatusBar(3);

	// Put something in the first section of the status bar
	SetStatusText(wxT("Ready..."));

	// Put something in the Second section of the status bar
	SetStatusText(wxT("    Shimer Lyttle"), 1);

	// Put something in the Third section of the status bar
	SetStatusText(wxT("    400006782"), 2);

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
struct log
{
	char month[10];
	int year;
	char artist[50];
	char songTitle[50];
	char label[15];
	int topOfCharts;
};

typedef struct log logs;

//===================================================================================
//=========== Definition for the File Functions =====================================
//===================================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
	// Creates a "open file" dialog with 2 file types (*.dat and *.*)
	wxFileDialog *OpenDialog = new wxFileDialog(this,
												(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
												(wxT("Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
												wxFD_OPEN, wxDefaultPosition);

	if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
	{
		// Sets our current document to the file the user selected
		CurrentDocPath = OpenDialog->GetPath();

		// Clean up filename textbox and Display file name in filename textbox
		filenameTextBox->Clear();
		filenameTextBox->AppendText(CurrentDocPath);

		// ---------------------------------------------------------------
		// Insert code HERE to display that file in the MainEditBox
		// ---------------------------------------------------------------
		// Open the file for reading
		wxFileInputStream input(CurrentDocPath);
		if (!input.IsOk())
		{
			wxMessageBox("Failed to open file.", "Error", wxOK | wxICON_ERROR);
			return;
		}

		// Read the contents of the file into a vector of log structures
		vector<logs> logsList;
		while (!input.Eof())
		{
			logs logEntry;
			input.Read(&logEntry, sizeof(logEntry));
			logsList.push_back(logEntry);
		}

		// Display the contents of the log entries in the MainEditBox
		MainEditBox->Clear();
		for (const logs &logEntry : logsList)
		{
			wxString entryText = wxString::Format(wxT("%s %d %s %s %s %d\n"),
												  logEntry.month, logEntry.year, logEntry.artist, logEntry.songTitle,
												  logEntry.label, logEntry.topOfCharts);
			MainEditBox->AppendText(entryText);
			// return newRecord->template createNode<T>(entryText);
		}

		// Set the Title
		SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
	}
	// Clean up the dialog
	OpenDialog->Destroy();
}

void ProjectFrame::OnSave(wxCommandEvent &event)
{
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
	// If no file has been opened, show an error message and return
    if (CurrentDocPath.IsEmpty())
    {
        wxMessageBox("No file has been opened.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Open the file for reading
    wxFileInputStream input(CurrentDocPath);
    if (!input.IsOk())
    {
        wxMessageBox("Failed to open file.", "Error", wxOK | wxICON_ERROR);
        return;
    }

    // Read the contents of the file into a vector of log structures
    vector<logs> logsList;
    while (!input.Eof())
    {
        logs logEntry;
        input.Read(&logEntry, sizeof(logEntry));
        logsList.push_back(logEntry);
    }

    // Display the contents of the log entries in the MainEditBox
    MainEditBox->Clear();
    for (const logs& logEntry : logsList)
    {
        wxString entryText = wxString::Format(wxT("%s %d %s %s %s %d\n"),
            logEntry.month, logEntry.year, logEntry.artist, logEntry.songTitle,
            logEntry.label, logEntry.topOfCharts);
        MainEditBox->AppendText(entryText);
    }
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
	wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE); // Close the window
}

// Functions for Edit Menu Items
void ProjectFrame::OnECreateADTs(wxCommandEvent &event)
{
	// Open the data file for reading
    std::ifstream inputFile("Catalog.dat");
    if (!inputFile.is_open()) {
        // Handle error opening file
        return;
    }

	// Data structures to hold created ADT objects
    vector<string> data;
    // vector<Heap<string>> heap;
    AVLTree<string> avlTree;
    BinarySearchTree<string> bstTree;
    // set<string> set;
    RedBlackTree<string> rbTree;

	 // Read data records from file and create ADT objects
    int num;
    while (inputFile >> num) {
        // // Store data in vector
        // data.push_back(num);

        // // Create and populate Heap
        // Heap<string> heap(data);
        // heap.push_back(heap);

        // Create and populate AVL Tree
        AVLTree<string> avlTree;
		for (string i : data) {
        avlTree.insert(i);
		}

        // // Create and populate Binary Search Tree
        BinarySearchTree<string> bstTree(data);
		for (string i : data) {
        bstTree.insert(i);
		}

        // // Create and populate Set
        // set.insert(num);

        // Create and populate Red-Black Tree
        RedBlackTree<string> rbTree;
        for (string i : data) {
			rbTree.insert(i);
		}
	}
}

void ProjectFrame::OnERecordAdd(wxCommandEvent &event)
{
}

void ProjectFrame::OnERecordDelete(wxCommandEvent &event)
{
}

// Functions for Binary Search Trees Menu Items
void ProjectFrame::OnBSTInorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnBSTPreorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnBSTPostorder(wxCommandEvent &event)
{
}

// Functions for AVL Tree Menu Items
void ProjectFrame::OnAVLTInorder(wxCommandEvent &event)
{
	// MainEditBox->Clear();

	// string record = avl->inOrder();
	// wxString wxRecords(record.c_str(), wxConvUTF8);

	// MainEditBox->AppendText(wxT("\n AVL Tree Inorder\n\n"));
	// MainEditBox->AppendText(wxRecords);
}

void ProjectFrame::OnAVLTPreorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnAVLTPostorder(wxCommandEvent &event)
{
}

// Function for the RE Tree Menu Items
void ProjectFrame::OnRBTInorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnRBTPreorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnRBTPostorder(wxCommandEvent &event)
{
}

// Functions for the Splay Tree Menu Items
void ProjectFrame::OnSTInorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnSTPreorder(wxCommandEvent &event)
{
}

void ProjectFrame::OnSTPostorder(wxCommandEvent &event)
{
}

// Functions for the Heap Menu Items
void ProjectFrame::OnHDisplay(wxCommandEvent &event)
{
}

void ProjectFrame::OnHSort(wxCommandEvent &event)
{
}

// Functions for the Set Menu Items
void ProjectFrame::OnSDisplaySetA(wxCommandEvent &event)
{
}

void ProjectFrame::OnSDisplaySetB(wxCommandEvent &event)
{

	// Node* n=new Node();
	// n.readfile();
}

void ProjectFrame::OnSDisplayIntersect(wxCommandEvent &event)
{
}

void ProjectFrame::OnSDisplayUnion(wxCommandEvent &event)
{
}

// Function for Help Menu Item
void ProjectFrame::OnAbout(wxCommandEvent &event){

}