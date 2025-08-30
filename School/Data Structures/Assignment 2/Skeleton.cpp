<<<<<<< Updated upstream
// /************************************************************************************
//   Step 1: Always include the header file wx.h
// *************************************************************************************/

// #include <wx/wxprec.h>
// #include <wx/spinctrl.h>
// #include <wx/textctrl.h>
// #include <wx/combobox.h>
=======
/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/

#include <wx/wxprec.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>
>>>>>>> Stashed changes

// #ifndef WX_PRECOMP
// #include <wx/wx.h>
// #endif

<<<<<<< Updated upstream
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <sstream>

// using namespace std;
// // todo: add a DataDialog

// // #include "BinarySearchTree.h"
// // #include "AVL Tree.h"
// // #include "Red-BlackTree.h"
// // #include "SplayTree.h"
// // #include "Set.h"
// // #include "MinHeapTree.h"

// // Global pointers for the ADT containers
// // RBT *rbt = new RBT();
// // AVLTree *avl = new AVL();
// // BSTree *bst = new BST();
// // SplayTree *splay = new SplayTree();
// // BinHeap *heap = new BinHeap();

// /************************************************************************************
// *************************************************************************************
//   Step 2: Name an inherited application class from wxApp and declare it with
// 	  the function to execute the program
// *************************************************************************************
// *************************************************************************************/
// class SkeletonApp : public wxApp
=======
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// todo: add a DataDialog

#include "BinarySearchTree.h"
#include "AVL Tree.h"
#include "Red-BlackTree.h"
#include "SplayTree.h"
#include "Set.h"
#include "MinHeapTree.h"

RBT *rbt = new RBT();
AVLTree *avl = new AVL();
BSTree *bst = new BST();
SplayTree *splay = new SplayTree();
BinHeap *heap = new BinHeap();


/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
	  the function to execute the program
*************************************************************************************
*************************************************************************************/
class SkeletonApp : public wxApp
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
	ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

	// Public attributes

	// Functions for File Menu Items
	void OnOpenFile(wxCommandEvent &event);
	void OnDisplayFile(wxCommandEvent &event);
	void OnSave(wxCommandEvent &event);
	void OnSaveAs(wxCommandEvent &event);
	void OnExit(wxCommandEvent &event); // handle for Quit function

	// Functions for the Edit Items
	void OnCreateADT(wxCommandEvent &event);
	void OnAddRecord(wxCommandEvent &event);
	void OnDeleteRecord(wxCommandEvent &event);

	// Functions for BST Menu Items
	void OnInorderBST(wxCommandEvent &event);
	void OnPreorderBST(wxCommandEvent &event);
	void OnPostorderBST(wxCommandEvent &event);

	// Functions for the AVL Tree Items
	void OnInOrderAVL(wxCommandEvent &event);
	void OnPreOrderAVL(wxCommandEvent &event);
	void OnPostOrderAVL(wxCommandEvent &event);

	// Functions for the RB Tree Items
	void OnInOrderRB(wxCommandEvent &event);
	void OnPreOrderRB(wxCommandEvent &event);
	void OnPostorderRB(wxCommandEvent &event);

	// Functions for the Splay Tree Items
	void OnInorderST(wxCommandEvent &event);
	void OnPreOrderST(wxCommandEvent &event);
	void OnPostorderST(wxCommandEvent &event);

	// Functions for the Head Items
	void OnDisplayAll(wxCommandEvent &event);
	void OnHeapSort(wxCommandEvent &event);

	// Functions for the Set Items
	void OnDisplaySetA(wxCommandEvent &event);
	void OnDisplaySetB(wxCommandEvent &event);
	void OnDisplayInformation(wxCommandEvent &event);
	void DisplayUnion(wxCommandEvent &event);

	// Functions for the Help Items
	void onAbout(wxCommandEvent &event);
	void onExitHelp(wxCommandEvent &event);

	// Etc., etc...

	//----------------------------------------------------------------
	//       To be added on
	//----------------------------------------------------------------
	wxTextCtrl *MainEditBox;
	wxTextCtrl *filenameTextBox;
	wxString CurrentDocPath; // The Path to the file we have open
};

/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(SkeletonApp)   // Declare Application class
IMPLEMENT_APP(SkeletonApp) // Create Application class object

enum
{
	// File menu items
	ID_OpenFile = wxID_HIGHEST + 1, // File menu item
	ID_Display,
	ID_Save,
	ID_SaveAs,
	ID_Exit,

	// Edit menu items
	ID_CreateADT,
	ID_AddRecord,
	ID_DeleteRecord,

	// BST menu items
	ID_InorderBST,
	ID_PreorderBST,
	ID_PostorderBST,

	// AVL menu items
	ID_InorderAVL,
	ID_PreorderAVL,
	ID_PostorderAVL,

	// RB Tree items
	ID_InorderRB,
	ID_PreorderRB,
	ID_PostorderRB,

	// Slay Tree items
	ID_InorderST,
	ID_PreorderST,
	ID_PostorderST,

	// Head items
	ID_DisplayAll,
	ID_HeapSort,

	// Set items
	ID_DisplaySetA,
	ID_DisplaySetB,
	ID_DisplayInformation,
	ID_DisplayUnion,

	// Help items
	ID_About,
	ID_ExitHelp,
	// Etc., etc.

};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// Events for the Edit Items
EVT_MENU(ID_CreateADT, ProjectFrame::OnCreateADT)
EVT_MENU(ID_AddRecord, ProjectFrame::OnAddRecord)
EVT_MENU(ID_DeleteRecord, ProjectFrame::OnDelete)

// Events for the BST items
EVT_MENU(ID_InorderBST, ProjectFrame::OnInorderBST)
EVT_MENU(ID_PreorderBST, ProjectFrame::OnPreorderBST)
EVT_MENU(ID_PostorderBST, ProjectFrame::OnPostorderBST)

// Events for the AVL
EVT_MENU(ID_InorderAVL, ProjectFrame::OnInorderAVL)
EVT_MENU(ID_PreorderAVL, ProjectFrame::OnPreorderAVL)
EVT_MENU(ID_PostorderAVL, ProjectFrame::OnPostorderAVL)

// Events for the RB Tree
EVT_MENU(ID_InorderRB, ProjectFrame::OnInorderRB)
EVT_MENU(ID_PreorderRB, ProjectFrame::OnPreorderRB)
EVT_MENU(ID_PostorderRB, ProjectFrame::OnPostorderRB)

// Events for the Head Items
EVT_MENU(ID_DisplayAll, ProjectFrame::OnDisplayAll)
EVT_MENU(ID_HeapSort, ProjectFrame::OnHeapSort)

// Events for the Help Items
EVT_MENU(ID_About, ProjectFrame::OnAbout);
EVT_MENU(ID_ExitHelp, ProjectFrame::OnExitHelp);

// Etc., etc.

END_EVENT_TABLE()

/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool SkeletonApp::OnInit()
{
	// Create the main application window
	ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"), wxPoint(50, 50), wxSize(800, 640));

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
ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
{
	// Set the frame icon - optional
	//    SetIcon(wxIcon(wxT("uwiIcon.xpm")));

	/* checkover: look to see if im missing the top of this function */
	// Create the menu bar
	wxMenu *menuFile = new wxMenu;
	wxMenu *menuEdit = new wxMenu;
	wxMenu *menuBST = new wxMenu;
	wxMenu *menuAVL = new wxMenu;
	wxMenu *menuRB = new wxMenu;
	wxMenu *menuSplay = new wxMenu;
	wxMenu *menuHeap = new wxMenu;
	wxMenu *menuAbout = new wxMenu;
	wxMenuBar *menuBar = new wxMenuBar;

	// Append the main menu items to the Menu Bar
	menuBar->Append(menuFile, wxT("File"));
	menuBar->Append(menuEdit, wxT("Edit"));
	menuBar->Append(menuBST, wxT("BST"));
	menuBar->Append(menuAVL, wxT("AVL"));
	menuBar->Append(menuRB, wxT("RB"));
	menuBar->Append(menuSplay, wxT("Splay"));
	menuBar->Append(menuHeap, wxT("Heap"));
	menuBar->Append(menuAbout, wxT("About"));

	// Append the sub-menu items to the File Main Menu item
	menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file"));
	menuFile->Append(ID_Display, wxT("&Display"), wxT("Display contents of opened file"));
	menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
	menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));
	menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

	// Append the sub-menu items to the Edit Main Menu item
	menuEdit->Append(ID_CreateADT, wxT("&Create ADT"), wxT(" "));
	menuEdit->Append(ID_AddRecord, wxT("&Add Record"), wxT(" "));
	menuEdit->Append(ID_DeleteRecord, wxT("&Delete Record"), wxT(" "));

	// Append the sub-menu items to the  Binary Search Tree item
	menuBST->Append(ID_InorderBST, wxT("&Inorder Binary Search Tree"), wxT(""));
	menuBST->Append(ID_PreorderBST, wxT("&Preorder Binary Search Tree"), wxT(""));
	menuBST->Append(ID_PostorderBST, wxT("&Postorder Binary Search Tree"), wxT(""));

	// Append the sub-menu items to the  AVL Tree item
	menuAVL->Append(ID_InorderBST, wxT("&Inorder AVL Tree"), wxT(""));
	menuAVL->Append(ID_PreorderBST, wxT("&Preorder AVL Tree"), wxT(""));
	menuAVL->Append(ID_PostorderBST, wxT("&Postorder AVL Tree"), wxT(""));

	// Append the sub-menu items to the RB Tree item
	menuRB->Append(ID_InorderBST, wxT("&Inorder  RB Tree"), wxT(""));
	menuRB->Append(ID_PreorderBST, wxT("&Preorder  RB Tree"), wxT(""));
	menuRB->Append(ID_PostorderBST, wxT("&Postorder  RB Tree"), wxT(""));

	// Append the  sub-menu items to the Splay Tree item
	menuSplay->Append(ID_InorderBST, wxT("&Inorder  Splay Tree"), wxT(""));
	menuSplay->Append(ID_PreorderBST, wxT("&Preorder  Splay Tree"), wxT(""));
	menuSplay->Append(ID_PostorderBST, wxT("&Postorder  Splay Tree"), wxT(""));

	// Append the sub-menu items to the Heap item
	menuHeap->Append(ID_DisplayAll, wxT("&Display All of Heap"), wxT(""));
	menuHeap->Append(ID_HeapSort, wxT("&Sort Heap"), wxT(""));

	// Append the sub-menu items ot the About item
	menuAbout->Append(ID_About, wxT("&About"), wxT(""));
	menuAbout->Append(ID_ExitHelp, wxT("&Exit Help"), wxT(""));

	// Create a status bar just for fun
	// InitStatusBar();

	CreateStatusBar(3);

	// Put something in the first section of the status bar
	SetStatusText(wxT("Ready..."));

	// Put something in the Second section of the status bar
	SetStatusText(wxT("Ean Bynoe"), 1);

	// Put something in the Third section of the status bar
	SetStatusText(wxT("400005520"), 2);

	// ... and now... attach this main menu bar to the frame
	SetMenuBar(menuBar);

	// Set up the panel for data display
	//===============================================================================
	//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================
	//================== Add it to your constructor function ========================
	//===============================================================================

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
	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);

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

/***************************************************************************
  Step 7:  Define member functions for the Frame class
***************************************************************************
***************************************************************************/

//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================

struct Record
{
public:
	char month[10];
	int year;
	char artist[50];
	char title[50];
	char label[15];
	int numweeks;
};
typedef struct Record record;

// Functions for the File Menu
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

		// todo
		// ---------------------------------------------------------------
		// Insert code HERE to display that file in the MainEditBox
		// ---------------------------------------------------------------
		string test = "";
		Record rec;
		ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);
		while (!infile.eof())
		{
			infile.read(reinterpret_cast<char *>(&rec), sizeof(rec));
			test.append(rec.month + "\t" + to_string(rec.year) + "\t" + rec.artist + "\t" + rec.title + "\t" + rec.label + "\t" + rec.numweeks + "\n");
		}
		infile.close();

		// convers record to a wxString variable
		wxString wxRecord(test.c_str(), wxConvUTF8);
		MainEditBox->Clear();

		// display the wxString variable in the MainEditBox
		MainEditBox->AppendText(wxRecord);

		// Set the Title
		SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
	}
}

void ProjectFrame::OnSave(wxCommandEvent &event)
{
	// Grab the file name in the filenameTextBox to save the contents to.
	MainEditBox->SaveFile(filenameTextBox->GetValue());
}

void ProjectFrame::OnSaveAs(wxCommandEvent &event)
{
	wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), wxEmptyString, wxEmptyString, (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

	// Creates a Save Dialog with 3 file types
	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
	{
		CurrentDocPath = SaveDialog->GetPath();

		// set the path of our current document to the file the user chose to save under
		MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

		// Set the Title to reflect the file open
		SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
	}
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
	string test = "";
	Record record;

	ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);
	if (!infile)
	{
		MainEditBox->AppendText(wxT("\n\n\nNo Data file is open...\n\n\n")) return;
	}
	MainEdit->Clear();
	while (!infile.eof())
	{
		infile.read(reinterpret_cast<char *>(&record), sizeof(Record));
		test.append(rec.month + "\t" + to_string(rec.year) + "\t" + rec.artist + "\t" + rec.title + "\t" + rec.label + "\t" + rec.numweeks + "\n");
	}
	infile.close();

	// convert the record to a string variable
	wxString wxRecord(test.c_str(), wxConvUTF8);

	MainEditBox->Clear();

	MainEditBox->AppendText(wxRecord);
}

void ProjectFrame::OnExit(wxCommandEvent &event)
{
	wxMessageBox(wxT("\nGood-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE); // Close the window
}

// Functions for the Edit items
// void ProjectFrame::OnCreateADT(wxCommandEvent &event)
>>>>>>> Stashed changes
// {
// 	virtual bool OnInit();
// };

// /************************************************************************************
// *************************************************************************************
//    Step 3: Declare the inherited main frame class from wxFrame. In this class
// 	   also will ALL the events handlers be declared
// *************************************************************************************
// *************************************************************************************/
// class ProjectFrame : public wxFrame
// {
// private:
// 	DECLARE_EVENT_TABLE() // To declare events items

// public:
// 	ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

// 	// Public attributes

// 	// Functions for File Menu Items
// 	void OnOpenFile(wxCommandEvent &event);
// 	void OnDisplayFile(wxCommandEvent &event);
// 	void OnSave(wxCommandEvent &event);
// 	void OnSaveAs(wxCommandEvent &event);
// 	void OnExit(wxCommandEvent &event); // handle for Quit function

// 	// Functions for the Edit Items
// 	// void OnCreateADT(wxCommandEvent &event);
// 	// void OnAddRecord(wxCommandEvent &event);
// 	// void OnDeleteRecord(wxCommandEvent &event);

// 	// Functions for BST Menu Items
// 	// void OnInorderBST(wxCommandEvent &event);
// 	// void OnPreorderBST(wxCommandEvent &event);
// 	// void OnPostorderBST(wxCommandEvent &event);

// 	// Functions for the AVL Tree Items
// 	// void OnInOrder(wxCommandEvent &event);
// 	// void OnPreOrderAVL(wxCommandEvent &event);
// 	// void OnPostOrderAVL(wxCommandEvent &event);

// 	// Functions for the RB Tree Items
// 	// void OnInOrderRB(wxCommandEvent &event);
// 	// void OnPreOrderRB(wxCommandEvent &event);
// 	// void OnPostorderRB(wxCommandEvent &event);

// 	// Functions for the Splay Tree Items
// 	// void OnInorderST(wxCommandEvent &event);
// 	// void OnPreOrderST(wxCommandEvent &event);
// 	// void OnPostorderST(wxCommandEvent &event);

// 	// Functions for the Head Items
// 	// void OnDisplayAll(wxCommandEvent &event);
// 	// void OnHeapSort(wxCommandEvent &event);

// 	// Functions for the Set Items
// 	// void OnDisplaySetA(wxCommandEvent &event);
// 	// void OnDisplaySetB(wxCommandEvent &event);
// 	// void OnDisplayInformation(wxCommandEvent &event);
// 	// void OnDisplayUnion(wxCommandEvent &event);

// 	// Functions for the Help Items
// 	// void OnAbout(wxCommandEvent &event);
// 	// void OnExitHelp(wxCommandEvent &event);

// 	// Etc., etc...

// 	//----------------------------------------------------------------
// 	//       To be added on
// 	//----------------------------------------------------------------
// 	// Public attributes
// 	wxTextCtrl *MainEditBox;
// 	wxTextCtrl *filenameTextBox;
// 	wxString CurrentDocPath; // The Path to the file we have open
// };

// /************************************************************************************
// *************************************************************************************
//   Step 4. Declare the compiler directives
// *************************************************************************************
// *************************************************************************************/
// DECLARE_APP(SkeletonApp)   // Declare Application class
// IMPLEMENT_APP(SkeletonApp) // Create Application class object

// enum
// {
// 	// File menu items
// 	ID_OpenFile = wxID_HIGHEST + 1, // File menu item
// 	ID_Display,
// 	ID_Save,
// 	ID_SaveAs,
// 	ID_Exit,

// 	// Edit menu items
// 	ID_CreateADT,
// 	ID_AddRecord,
// 	ID_DeleteRecord,

// 	// BST menu items
// 	ID_InorderBST,
// 	ID_PreorderBST,
// 	ID_PostorderBST,

// 	// AVL menu items
// 	ID_InOrder,
// 	ID_PreorderAVL,
// 	ID_PostorderAVL,

// 	// RB Tree items
// 	ID_InorderRB,
// 	ID_PreorderRB,
// 	ID_PostorderRB,

// 	// Slay Tree items
// 	ID_InorderST,
// 	ID_PreorderST,
// 	ID_PostorderST,

// 	// Head items
// 	ID_DisplayAll,
// 	ID_HeapSort,

// 	// Set items
// 	ID_DisplaySetA,
// 	ID_DisplaySetB,
// 	ID_DisplayInformation,
// 	ID_DisplayUnion,

// 	// Help items
// 	ID_About,
// 	ID_ExitHelp,
// 	// Etc., etc.

// };

// BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// // Events for the "File" menu items
// EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
// EVT_MENU(ID_Display, ProjectFrame::OnDisplayFile)
// EVT_MENU(ID_Save, ProjectFrame::OnSave)
// EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
// EVT_MENU(ID_Exit, ProjectFrame::OnExit)

// // Events for the Edit Items
// // EVT_MENU(ID_CreateADT, ProjectFrame::OnCreateADT)
// // EVT_MENU(ID_AddRecord, ProjectFrame::OnAddRecord)
// // EVT_MENU(ID_DeleteRecord, ProjectFrame::OnDeleteRecord)

// // Events for the BST items
// // EVT_MENU(ID_InorderBST, ProjectFrame::OnInorderBST)
// // EVT_MENU(ID_PreorderBST, ProjectFrame::OnPreorderBST)
// // EVT_MENU(ID_PostorderBST, ProjectFrame::OnPostorderBST)

// // Events for the AVL
// // EVT_MENU(ID_InOrderAVL, ProjectFrame::OnInOrderAVL)
// // EVT_MENU(ID_PreorderAVL, ProjectFrame::OnPreorderAVL)
// // EVT_MENU(ID_PostorderAVL, ProjectFrame::OnPostorderAVL)

// // Events for the RB Tree
// // EVT_MENU(ID_InorderRB, ProjectFrame::OnInOrderRB)
// // EVT_MENU(ID_PreorderRB, ProjectFrame::OnPreOrderRB)
// // EVT_MENU(ID_PostorderRB, ProjectFrame::OnPostOrderRB)

// // Events for the Head Items
// // EVT_MENU(ID_DisplayAll, ProjectFrame::OnDisplayAll)
// // EVT_MENU(ID_HeapSort, ProjectFrame::OnHeapSort)

// // Events for the Help Items
// // EVT_MENU(ID_About, ProjectFrame::OnAbout)
// // EVT_MENU(ID_ExitHelp, ProjectFrame::OnExitHelp)

// END_EVENT_TABLE()

// /************************************************************************************
// *************************************************************************************
//   Step 5.  Define the Application class function to initialize the application
// *************************************************************************************
// *************************************************************************************/
// bool SkeletonApp::OnInit()
// {
// 	// Create the main application window
// 	ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures"), wxPoint(50, 50), wxSize(800, 640));

// 	// Display the window
// 	frame->Show(TRUE);

// 	SetTopWindow(frame);

// 	return TRUE;
// }

// /************************************************************************************
// *************************************************************************************
//   Step 6:   Define the Constructor functions for the Frame class
// *************************************************************************************
// *************************************************************************************/
// ProjectFrame::ProjectFrame(const wxString &title, const wxPoint &pos, const wxSize &size) : wxFrame((wxFrame *)NULL, -1, title, pos, size)
// {
// 	// Set the frame icon - optional
// 	//    SetIcon(wxIcon(wxT("uwiIcon.xpm")));

// 	/* checkover: look to see if im missing the top of this function */

// 	// Create the main menu items
// 	wxMenu *menuFile = new wxMenu;
// 	wxMenu *menuEdit = new wxMenu;
// 	wxMenu *menuBST = new wxMenu;
// 	wxMenu *menuAVL = new wxMenu;
// 	wxMenu *menuRB = new wxMenu;
// 	wxMenu *menuSplay = new wxMenu;
// 	wxMenu *menuHeap = new wxMenu;
// 	wxMenu *menuAbout = new wxMenu;

// 	// Create the menu bar
// 	wxMenuBar *menuBar = new wxMenuBar;

// 	// Append the main menu items to the Menu Bar
// 	menuBar->Append(menuFile, wxT("File"));
// 	menuBar->Append(menuEdit, wxT("Edit"));
// 	menuBar->Append(menuBST, wxT("BST"));
// 	menuBar->Append(menuAVL, wxT("AVL"));
// 	menuBar->Append(menuRB, wxT("RB"));
// 	menuBar->Append(menuSplay, wxT("Splay"));
// 	menuBar->Append(menuHeap, wxT("Heap"));
// 	menuBar->Append(menuAbout, wxT("About"));

// 	// Append the sub-menu items to the File Main Menu item
// 	menuFile->Append(ID_OpenFile, wxT("&Open File..."), wxT("Open an Existing file"));
// 	menuFile->Append(ID_Display, wxT("&Display"), wxT("Display contents of opened file"));
// 	menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
// 	menuFile->Append(ID_SaveAs, wxT("Save &As..."), wxT("Save display as a new file"));
// 	menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

// 	// Append the sub-menu items to the Edit Main Menu item
// 	menuEdit->Append(ID_CreateADT, wxT("&Create ADT"), wxT(" "));
// 	menuEdit->Append(ID_AddRecord, wxT("&Add Record"), wxT(" "));
// 	menuEdit->Append(ID_DeleteRecord, wxT("&Delete Record"), wxT(" "));

// 	// Append the sub-menu items to the  Binary Search Tree item
// 	menuBST->Append(ID_InorderBST, wxT("&Inorder Binary Search Tree"), wxT(""));
// 	menuBST->Append(ID_PreorderBST, wxT("&Preorder Binary Search Tree"), wxT(""));
// 	menuBST->Append(ID_PostorderBST, wxT("&Postorder Binary Search Tree"), wxT(""));

// 	// Append the sub-menu items to the  AVL Tree item
// 	menuAVL->Append(ID_InorderBST, wxT("&Inorder AVL Tree"), wxT(""));
// 	menuAVL->Append(ID_PreorderBST, wxT("&Preorder AVL Tree"), wxT(""));
// 	menuAVL->Append(ID_PostorderBST, wxT("&Postorder AVL Tree"), wxT(""));

// 	// Append the sub-menu items to the RB Tree item
// 	menuRB->Append(ID_InorderBST, wxT("&Inorder  RB Tree"), wxT(""));
// 	menuRB->Append(ID_PreorderBST, wxT("&Preorder  RB Tree"), wxT(""));
// 	menuRB->Append(ID_PostorderBST, wxT("&Postorder  RB Tree"), wxT(""));

// 	// Append the  sub-menu items to the Splay Tree item
// 	menuSplay->Append(ID_InorderBST, wxT("&Inorder  Splay Tree"), wxT(""));
// 	menuSplay->Append(ID_PreorderBST, wxT("&Preorder  Splay Tree"), wxT(""));
// 	menuSplay->Append(ID_PostorderBST, wxT("&Postorder  Splay Tree"), wxT(""));

// 	// Append the sub-menu items to the Heap item
// 	menuHeap->Append(ID_DisplayAll, wxT("&Display All of Heap"), wxT(""));
// 	menuHeap->Append(ID_HeapSort, wxT("&Sort Heap"), wxT(""));

// 	// Append the sub-menu items ot the About item
// 	menuAbout->Append(ID_About, wxT("&About"), wxT(""));
// 	menuAbout->Append(ID_ExitHelp, wxT("&Exit Help"), wxT(""));

// 	// Create a status bar just for fun
// 	// InitStatusBar();

// 	CreateStatusBar(3);

// 	// Put something in the first section of the status bar
// 	SetStatusText(wxT("Ready..."));

// 	// Put something in the Second section of the status bar
// 	SetStatusText(wxT("\t\t\tEan Bynoe"), 1);

// 	// Put something in the Third section of the status bar
// 	SetStatusText(wxT("\t\t400005520"), 2);

// 	// ... and now... attach this main menu bar to the frame
// 	SetMenuBar(menuBar);

// 	// Set up the panel for data display
// 	//===============================================================================
// 	//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================
// 	//================== Add it to your constructor function ========================
// 	//===============================================================================

// 	wxPanel *panel = new wxPanel(this, -1);
// 	wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);	  // Vertical sizer for main window
// 	wxBoxSizer *hbox1 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for main window

// 	// Add two textboxes to the panel for data display
// 	wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for filename window
// 	wxBoxSizer *hbox3 = new wxBoxSizer(wxHORIZONTAL); // Horizontal sizer for display window

// 	wxStaticText *fileLabel = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
// 	wxStaticText *displayLabel = new wxStaticText(panel, wxID_ANY, wxT("Display"));

// 	// Initialize the filename textbox window
// 	filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

// 	// Initialize the display window
// 	MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."), wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);

// 	// Position the labels and textboxes in the panel
// 	hbox1->Add(fileLabel, 0, wxRIGHT, 8);
// 	hbox1->Add(filenameTextBox, 1);
// 	vbox->Add(hbox1, 0, wxEXPAND | wxLEFT | wxRIGHT | wxTOP, 10);

// 	vbox->Add(-1, 10);
// 	hbox2->Add(displayLabel, 0);
// 	vbox->Add(hbox2, 0, wxLEFT | wxTOP, 10);
// 	vbox->Add(-1, 10);

// 	hbox3->Add(MainEditBox, 1, wxEXPAND);
// 	vbox->Add(hbox3, 1, wxLEFT | wxRIGHT | wxEXPAND, 10);

// 	vbox->Add(-1, 25);
// 	panel->SetSizer(vbox);

// 	Centre();
// }

// /***************************************************************************
//   Step 7:  Define member functions for the Frame class
// ***************************************************************************
// ***************************************************************************/

// //=========================================================================
// //======== Definition for the File Functions ==============================
// //=========================================================================

// struct Record
// {
// public:
// 	char month[10];
// 	int year;
// 	char artist[50];
// 	char title[50];
// 	char label[15];
// 	int numweeks;
// };
// typedef struct Record record;

// // Functions for the File Menu
// void ProjectFrame::OnOpenFile(wxCommandEvent &event)
// {
// 	// Creates an "open file" dialog with a filter for .dat files
// 	wxFileDialog *OpenDialog = new wxFileDialog(this,
// 												(wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
// 												(wxT("Data Files (*.dat)|*.dat")), wxFD_OPEN, wxDefaultPosition);

// 	if (OpenDialog->ShowModal() == wxID_OK) // if the user clicks "Open" instead of "Cancel"
// 	{
// 		// Sets our current document to the file the user selected
// 		CurrentDocPath = OpenDialog->GetPath();

// 		// Clean up filename textbox and display file name in filename textbox
// 		filenameTextBox->Clear();
// 		filenameTextBox->AppendText(CurrentDocPath);

// 		// Open the file
// 		std::ifstream file(CurrentDocPath.mb_str());

// 		// Check if the file was opened successfully
// 		if (file.is_open())
// 		{
// 			// Clear the MainEditBox
// 			MainEditBox->Clear();

// 			// Read the file line by line and append each line to the MainEditBox
// 			std::string line;
// 			while (std::getline(file, line))
// 			{
// 				MainEditBox->AppendText(wxString(line));
// 				MainEditBox->AppendText("\n"); // add newline character at the end of each line
// 			}

// 			// Close the file
// 			file.close();
// 		}
// 		else
// 		{
// 			// Display an error message if the file could not be opened
// 			wxMessageBox(wxT("Failed to open file."), wxT("Error"), wxICON_ERROR);
// 		}

// 		// Set the Title
// 		SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
// 	}
// }

// void ProjectFrame::OnSave(wxCommandEvent &event)
// {
// 	// Grab the file name in the filenameTextBox to save the contents to.
// 	MainEditBox->SaveFile(filenameTextBox->GetValue());
// }

// void ProjectFrame::OnSaveAs(wxCommandEvent &event)
// {
// 	wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")), wxEmptyString, wxEmptyString, (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")), wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

// 	// Creates a Save Dialog with 3 file types
// 	if (SaveDialog->ShowModal() == wxID_OK) // If the user clicked "OK"
// 	{
// 		CurrentDocPath = SaveDialog->GetPath();

// 		// set the path of our current document to the file the user chose to save under
// 		MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

// 		// Set the Title to reflect the file open
// 		SetTitle(wxString(wxT("COMP2611 - Data Structures : 400005520")));
// 	}
// }

// void ProjectFrame::OnDisplayFile(wxCommandEvent &event)
// {
// 	string test = "";

// 	Record record;

// 	ifstream infile(CurrentDocPath.mb_str(), ios::in | ios::binary);
// 	if (!infile)
// 	{
// 		MainEditBox->AppendText(wxT("\n\n\nNo Data file is open...\n\n\n"));
// 		return;
// 	}
// 	MainEditBox->Clear();
// 	wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")), wxEmptyString, wxEmptyString, (wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

// 	while (!infile.eof())
// 	{
// 		infile.read(reinterpret_cast<char *>(&record), sizeof(Record));
// 		test.append(record.month + /* "\t" + */ to_string(record.year) + /*"\t" */ record.artist + /* "\t" + */ record.title + /* "\t" + */ record.label + /* "\t" + */ to_string(record.numweeks) + "\n");
// 		cout << test << endl;
// 	}
// 	infile.close();

// 	// convert the record to a string variable
// 	wxString wxRecord(test.c_str, wxConvUTF8);
// 	MainEditBox->Clear();

// 	MainEditBox->AppendText(wxRecord);
// }

// /* void ProjectFrame::OnDisplayFile(wxCommandEvent &event)
// {
// 	// Creates a "open file" dialog with 4 file types
// 	wxFileDialog *OpenDialog = new wxFileDialog(this, (wxT("Choose a file to open")),
// 												wxEmptyString, wxEmptyString,
// 												(wxT("Text files (*.txt)|*.txt|Data Files (*.dat)|*.dat|All files (*.*)|*.*")),
// 												wxFD_OPEN, wxDefaultPosition);

// 	MainEditBox->Clear();

// 	MainEditBox->LoadFile(CurrentDocPath);
// } */

// void ProjectFrame::OnExit(wxCommandEvent &event)
// {
// 	wxMessageBox(wxT("\nGood-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
// 	Close(TRUE); // Close the window
// }

// // Functions for the Edit items

// /* void ProjectFrame::OnCreateADT(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// 	ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
// 	MainEditBox->Clear();
// 	 ifstream FileOpen(CurrentDocPath.mb_str(), ios::in);
// 	MainEditBox->Clear();
// }
// void ProjectFrame::OnAddRecord(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// }
// void ProjectFrame::OnDeleteRecord(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// } */

// // // Functions for the BST Menu Items
// /* void ProjectFrame::OnInorderBST(wxCommandEvent &event)
// {
// 	// Record record;

// 	MainEditBox->Clear();
// 	string test = bst->inOrder();

// 	// converts to string
// 	wxString wxRecord(test.c_str(), wxConvUTF8);

// 	MainEditBox->AppendText(wxRecord);
// }

<<<<<<< Updated upstream
=======
// // Functions for the BST Menu Items
void ProjectFrame::OnInOrderBST(wxCommandEvent &event)
{
	Record record;
	string test, heading;


	MainEditBox->Clear();
}
>>>>>>> Stashed changes
// void ProjectFrame::OnPreOrderBST(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();

// 	string test = bst->preOrder();

// 	wxString wxRecord(record.c_str(), wxConvUTF8);
// 	MainEditBox->AppendText(wxRecord);
// }
// void ProjectFrame::OnPostorderBST(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();

<<<<<<< Updated upstream
// 	string record = bst->postOrder();
=======
// // Functions for the AVL Items
// void ProjectFrame::OnInOrderAVL(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// }
// void ProjectFrame::OnPreOrderAVL(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// }
// void ProjectFrame::OnPostorderAVL(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// }
>>>>>>> Stashed changes

// 	wxString wxRecord(record.c_str(), wxConvUTF8);

// 	MainEditBox->AppendText(wxRecord);
// } */

// // Functions for the AVL Items
// /* void ProjectFrame::OnInOrderAVL(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// } */
// /* void ProjectFrame::OnPreOrderAVL(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void ProjectFrame::OnPostOrderAVL(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
//  */
// // Functions for the RB Tree
// /* void ProjectFrame::OnInOrderRB(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void ProjectFrame::OnPreOrderRB(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void ProjectFrame::OnPostorderRB(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// } */

// // Functions foe the Splay
// /* void ProjectFrame::OnInOrderST(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void ProjectFrame::OnPreOrderST(wxCommandEvent &event)
// {
// 	MainEditBox->Clear();
// }
// void ProjectFrame::OnPostorderST(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// } */

// // Functions for the Heap Items
// /* void ProjectFrame::OnDisplayAll(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void ProjectFrame::OnHeapSort(wxCommandEvent &event)
// {
// 	 // MainEditBox->Clear();
// }*/

// // Functions for the Set Items
// /* void OnDisplaySetA(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void OnDisplaySetB(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void OnDisplayInformation(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// }
// void OnDisplayUnion(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// } */

// // Functions for the Help Items
<<<<<<< Updated upstream
// // void OnAbout(wxCommandEvent &event)
// // {
// // 	// MainEditBox->SetValue(wxString::Format(""));
// // 	// wxMessageBox(wxT("This program is a data structure assignment.\n\nAuthor: Ean Bynoe\nStudent ID: 400005520\nCourse: Data Structures"));
// // }

// /* void OnExitHelp(wxCommandEvent &event)
// {
// 	// MainEditBox->Clear();
// 	wxMessageBox(wxT("\nGood-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION);
// 	close(TRUE);
// } */




































#include <wx/wxprec.h>
# include <wx/spinctrl.h>
# include <wx/textctrl.h>
# include <wx/combobox.h>
#ifndef WX_PRECOMP
#  include <wx/wx.h>
#endif
#include <fstream>
#include <string>
#include <iostream>
// #include "BSTree.h"



//Pointers

// BST* bst = new BST();
/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
      the function to execute the program
*************************************************************************************
*************************************************************************************/
class SkeletonApp: public wxApp
  {
     virtual bool OnInit();
  };





/************************************************************************************
*************************************************************************************
   Step 3: Declare the inherited main frame class from wxFrame. In this class
       also will ALL the events handlers be declared
*************************************************************************************
*************************************************************************************/
class ProjectFrame: public wxFrame
  {
     private:
        DECLARE_EVENT_TABLE() //To declare events items

     public:
        ProjectFrame(const wxString& title, const wxPoint& pos,
            const wxSize& size);

        //Functions for File Menu Items
        void OnOpenFile(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        void OnSaveAs(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);     //handle for Quit function

        //Function for the Edit Menu item
        void OnCreateADTs(wxCommandEvent& event);
        void OnAddRecord(wxCommandEvent& event);
        void OnDeleteRecord(wxCommandEvent& event);

        //Functions for BST Menu Items
		void OnInorderBST(wxCommandEvent& event);
        void OnPreorderBST(wxCommandEvent& event);
        void OnPostorderBST(wxCommandEvent& event);


        //Functions for AVL tree Menu Items
        void OnInorderAVL(wxCommandEvent& event);
        void OnPreorderAVL(wxCommandEvent& event);
        void OnPostorderAVL(wxCommandEvent& event);


        //Functions for Heap Menu Items
		void OnDisplayAllHeap(wxCommandEvent& event);
        void OnSortHeap(wxCommandEvent& event);


        //Functions for Red Black tree Menu Items
        void OnInorderRBT(wxCommandEvent& event);
        void OnPreorderRBT(wxCommandEvent& event);
        void OnPostorderRBT(wxCommandEvent& event);

        //Functions for Splay tree Menu Items
        void OnInorderSplay(wxCommandEvent& event);
        void OnPreorderSplay(wxCommandEvent& event);
        void OnPostorderSplay(wxCommandEvent& event);

        //Functions for Set tree Menu Items
		void OnDisplaySetA(wxCommandEvent& event);
        void OnDisplaySetB(wxCommandEvent& event);
        void OnDisplayIntersection(wxCommandEvent& event);
        void OnDisplayUnion(wxCommandEvent& event);

        //Function for Help Menu Item
		void OnAbout(wxCommandEvent& event);

        //----------------------------------------------------------------
        //       To be added on
        //----------------------------------------------------------------
        wxTextCtrl* MainEditBox;
        wxTextCtrl* filenameTextBox;
        wxString    CurrentDocPath;    // The Path to the file we have open

  };



/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(SkeletonApp)        // Declare Application class
IMPLEMENT_APP(SkeletonApp)      // Create Application class object


enum
    {
          // File menu items
        ID_OpenFile  = wxID_HIGHEST + 1,        //File menu item
        ID_Display,
        ID_Save,
        ID_SaveAs,
        ID_Exit,


        // Edit menu items
         ID_CreateADTs,
        ID_AddRecord,
        ID_DeleteRecord,

        // BST submenu items
        ID_InorderBST,
        ID_PreorderBST,
        ID_PostorderBST,

        // AVL Tree submenu items
        ID_InorderAVL,
        ID_PreorderAVL,
        ID_PostorderAVL,

        // Heap submenu items
        ID_DisplayAllHeap,
        ID_SortHeap,


        // RBT items
        ID_InorderRBT,
        ID_PreorderRBT,
        ID_PostorderRBT,

        //Splay Tree
        ID_InorderSplay,
        ID_PreorderSplay,
        ID_PostorderSplay,

        //Set
        ID_DisplaySetA,
        ID_DisplaySetB,
        ID_DisplayIntersection,
        ID_DisplayUnion,

        // Help submenu items
        ID_About,

    };



BEGIN_EVENT_TABLE ( ProjectFrame, wxFrame )
      // Events for the "File" menu items
      EVT_MENU ( ID_OpenFile,   ProjectFrame::OnOpenFile )   //File Menu
      EVT_MENU ( ID_Save,       ProjectFrame::OnSave )
      EVT_MENU ( ID_SaveAs,     ProjectFrame::OnSaveAs )
      EVT_MENU ( ID_Exit,       ProjectFrame::OnExit )

 // Events for the "BST" menu items
	//   EVT_MENU ( ID_InorderBST, ProjectFrame::OnInorderBST)
    //   EVT_MENU ( ID_PreorderBST,  ProjectFrame::OnPreorderBST)
    //   EVT_MENU ( ID_PostorderBST,  ProjectFrame::OnPostorderBST)


      //Events For the "Help" menu item
      EVT_MENU(ID_About,      ProjectFrame::OnAbout)

END_EVENT_TABLE ()





/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool SkeletonApp::OnInit()
  {
      // Create the main application window
      ProjectFrame *frame = new ProjectFrame( wxT("COMP2611 - Data Structures"),
                    wxPoint(50,50),
                    wxSize(800,640) );

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
ProjectFrame::ProjectFrame ( const wxString& title, const wxPoint& pos, const wxSize& size)
            : wxFrame((wxFrame *)NULL, -1, title, pos, size)
  {
    // Set the frame icon - optional
//    SetIcon(wxIcon(wxT("uwiIcon.xpm")));


    // Create the main-menu items
    wxMenu *menuFile    =   new wxMenu;
    wxMenu *menuEdit    =   new wxMenu;
    wxMenu *menuBST = new wxMenu;
    wxMenu *menuAVL = new wxMenu;
    wxMenu *menuHeap = new wxMenu;
    wxMenu *menuRedBlack = new wxMenu;
    wxMenu *menuSplay = new wxMenu;
    wxMenu *menuSets = new wxMenu;
    wxMenu *menuHelp = new wxMenu;




    //Create a Main menu bar
    wxMenuBar *menuBar = new wxMenuBar;


    //Append the main menu items to the Menu Bar
    menuBar->Append( menuFile,   wxT("File") );
    menuBar->Append( menuEdit,   wxT("Edit") );
    menuBar->Append(menuBST,wxT("&BST"));
    menuBar->Append(menuAVL,wxT("&AVL Tree"));
    menuBar->Append(menuHeap,wxT("&Heap"));
    menuBar->Append(menuRedBlack,wxT("&Red-Black Tree"));
    menuBar->Append(menuSplay,wxT("&Splay Tree"));
    menuBar->Append(menuSets,wxT("&Sets"));
    menuBar->Append(menuHelp,wxT("&Help"));



    //Append the sub-menu items to the File Main Menu item
    menuFile->Append( ID_OpenFile,  wxT("&Open File..."),   wxT("Open an Existing file") );
    menuFile->Append(ID_Display, wxT("&Display File"),wxT("Display contents of opened file"));
    menuFile->Append( ID_Save,      wxT("&Save"),           wxT("Save opened file") );
    menuFile->Append( ID_SaveAs,    wxT("Save &As..."),     wxT("Save display as a new file") );
    menuFile->Append( ID_Exit,      wxT("E&xit"),           wxT("Close and EXIT Program") );


    //Append the sub-menu items to the Edit Main Menu item, etc
    menuEdit->Append( ID_CreateADTs,   wxT("&Create ADTs..."), wxT("Create an ADT"));
	menuEdit->Append( ID_AddRecord,  wxT("&Add Record"), wxT("Add a record to the ADT"));
    menuEdit->Append( ID_DeleteRecord,  wxT("&Delete Record"), wxT("Deletes a record from the ADT"));

     // BST Sub-menu items
	menuBST->Append( ID_InorderBST,   wxT("&Inorder..."), wxT("Display the inorder traversal result of the BST"));
	menuBST->Append( ID_PreorderBST,  wxT("&Preorder"), wxT("Display the preordewr traversal result of the BST"));
    menuBST->Append( ID_PostorderBST,  wxT("&Postorder"), wxT("Display the postorder traversal result of the BST"));

    // AVL Tree Sub-menu items
	menuAVL->Append( ID_InorderAVL,   wxT("&Inorder..."), wxT("Display the inorder traversal result of the AVL"));
	menuAVL->Append( ID_PreorderAVL,  wxT("&Preorder"), wxT("Display the preordewr traversal result of the AVL"));
    menuAVL->Append( ID_PostorderAVL,  wxT("&Postorder"), wxT("Display the postorder traversal result of the AVL"));

        // Heap Sub-menu items
	menuHeap->Append( ID_DisplayAllHeap, wxT("Display All..."), wxT("Display ALL the inorder in the MinHeap tree"));
	menuHeap->Append( ID_SortHeap,  wxT("Heap Sort"), wxT("Display the results of Heap Sort of the MinHeap tree"));

    // RBT Sub-menu items
	menuRedBlack->Append( ID_InorderRBT,   wxT("&Inorder..."), wxT("Display the inorder traversal result of the RBT"));
	menuRedBlack->Append( ID_PreorderRBT,  wxT("&Preorder"), wxT("Display the preordewr traversal result of the RBT"));
    menuRedBlack->Append( ID_PostorderRBT,  wxT("&Postorder"), wxT("Display the postorder traversal result of the RBT"));

    // Splay Tree Sub-menu items
	menuSplay->Append( ID_InorderSplay,   wxT("&Inorder..."), wxT("Display the inorder traversal result of the Splay Tree"));
	menuSplay->Append( ID_PreorderSplay,  wxT("&Preorder"), wxT("Display the preordewr traversal result of the Splay Tree"));
    menuSplay->Append( ID_PostorderSplay,  wxT("&Postorder"), wxT("Display the postorder traversal result of the Splay Tree"));

    // Sets Tree Sub-menu items
	menuSets->Append(ID_DisplaySetA,  wxT("Display SetA"), wxT("Display ALL records in Set A"));
	menuSets->Append(ID_DisplaySetB, wxT("Display Set B"), wxT("Display ALL records in Set B"));
	menuSets->Append(ID_DisplayIntersection, wxT("Display Intersection"), wxT("Display the Intersection records of Set A and Set B"));
	menuSets->Append(ID_DisplayUnion, wxT("Display Union"), wxT("Display the Union records of Set A and Set B"));

    // Help Sub-menu items
    menuHelp->Append(ID_About, wxT("About"), wxT("Dialog box with the 'About' information"));

    // Create a status bar just for fun
	CreateStatusBar(3);

	//Put something in the first section of the status bar
	SetStatusText( wxT("Ready..."));

	//Put something in the Second section of the status bar
	SetStatusText( wxT("    Nathan Ruck"), 1 );

	//Put something in the Third section of the status bar
	SetStatusText( wxT("    400013218"), 2 );




    // ... and now... attach this main menu bar to the frame
    SetMenuBar( menuBar );






    //Set up the panel for data display
//===============================================================================
//================= DO NOT CHANGE THE CODE IN THIS SECTION ======================
//================== Add it to your constructor function ========================
//===============================================================================

    wxPanel     *panel     = new wxPanel(this, -1);
    wxBoxSizer  *vbox      = new wxBoxSizer(wxVERTICAL);          //Vertical sizer for main window
    wxBoxSizer  *hbox1     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for main window

    //Add two textboxes to the panel for data display
    wxBoxSizer  *hbox2     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for filename window
    wxBoxSizer  *hbox3     = new wxBoxSizer(wxHORIZONTAL);        //Horizontal sizer for display window

    wxStaticText *fileLabel     = new wxStaticText(panel, wxID_ANY, wxT("File Name"));
    wxStaticText *displayLabel  = new wxStaticText(panel, wxID_ANY, wxT("Display"));

    //Initialize the filename textbox window
    filenameTextBox = new wxTextCtrl(panel, wxID_ANY, wxT("No File Opened Yet..."));

    //Initialize the display window
    MainEditBox = new wxTextCtrl(panel, wxID_ANY, wxT("No Data Available Yet..."),
                      wxPoint(-1, -1), wxSize(-1, -1), wxTE_MULTILINE | wxTE_RICH);


    //Position the labels and textboxes in the panel
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

   struct test {
        public :
            int gID;
            char fName[10];
            char sName[10];
            char des[15];
            char memb[10];
            char booking[10];

        };

        typedef struct test tests;



/***************************************************************************
  Step 7:  Define member functions for the Frame class
***************************************************************************
***************************************************************************/

//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================

void ProjectFrame::OnOpenFile(wxCommandEvent& event )
    {
        // Creates a "open file" dialog with 2 file types (*.dat and *.*)
        wxFileDialog *OpenDialog = new wxFileDialog( this,
            (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
            (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")),
              wxFD_OPEN, wxDefaultPosition);

        if (OpenDialog->ShowModal() == wxID_OK)    // if the user click "Open" instead of "cancel"
            {
                // Sets our current document to the file the user selected
                CurrentDocPath = OpenDialog->GetPath();

                //Clean up filename textbox and Display file name in filename textbox
                filenameTextBox->Clear();
                filenameTextBox->AppendText(CurrentDocPath);



                MainEditBox->LoadFile(CurrentDocPath);

                // Set the Title
                SetTitle(wxString(wxT("COMP2611 - Data Structures : 400013218")));
            }

    }





void ProjectFrame::OnSave(wxCommandEvent& event )
    {
        // Grab the file name in the filenameTextBox to save the contents to.
        MainEditBox->SaveFile(filenameTextBox->GetValue());
    }





void ProjectFrame::OnSaveAs(wxCommandEvent& event)
    {
        wxFileDialog *SaveDialog = new wxFileDialog(this, (wxT("Save File As...?")),
                            wxEmptyString, wxEmptyString,
                            (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|")),
                            wxFD_SAVE | wxFD_OVERWRITE_PROMPT, wxDefaultPosition);

        // Creates a Save Dialog with 3 file types
        if (SaveDialog->ShowModal() == wxID_OK)     // If the user clicked "OK"
            {
                CurrentDocPath = SaveDialog->GetPath();

                // set the path of our current document to the file the user chose to save under
                MainEditBox->SaveFile(CurrentDocPath); // Save the file to the selected path

                // Set the Title to reflect the file open
                SetTitle(wxString(wxT("COMP2611 - Data Structures : 123456789")));
            }

    }


void ProjectFrame::OnExit(wxCommandEvent& event)
    {
        wxMessageBox(wxT("\nGood-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
        Close(TRUE); // Close the window
    }

//=============================================================================
//============== Definition for the BST Functions =============================
//=============================================================================
/* void ProjectFrame::OnInorderBST(wxCommandEvent& event)
        {
            //clear MainEditBox
            MainEditBox->Clear();

            std::string record = bst->inOrder();
            //convert to string
            wxString wxRecord(record.c_str(), wxConvUTF8);

             //display the record in the MainEditBox
        MainEditBox->AppendText(wxT("\n\nBinary Search Tree Inorder Traversal:\n\n"));
        MainEditBox->AppendText(wxRecord);
    }
void ProjectFrame::OnPreorderBST(wxCommandEvent& event)
        {
            MainEditBox->Clear();

            std::string record = bst->preOrder();
            //convert to string
            wxString wxRecord(record.c_str(), wxConvUTF8);

             MainEditBox->AppendText(wxT("\n\nBinary Search Tree Preorder Traversal:\n\n"));
            MainEditBox->AppendText(wxRecord);
    }
void ProjectFrame::OnPostorderBST(wxCommandEvent& event)
        {
            MainEditBox->Clear();

            std::string record = bst->postOrder();
            //convert to string
            wxString wxRecord(record.c_str(), wxConvUTF8);
 MainEditBox->AppendText(wxT("\n\nBinary Search Tree Post-order Traversal:\n\n"));
            MainEditBox->AppendText(wxRecord);
    }
 */


//=============================================================================
//============== Definition for the Help Functions ===========================
//=============================================================================
 void ProjectFrame::OnAbout(wxCommandEvent& event)
{
	wxMessageBox(wxT("This programmer of this project is Nathan Ruck. This Project was designed to showcase the different capabilities of the Abstract data type trees"), wxT("OK"), wxOK | wxICON_INFORMATION, this);

}
=======
void onAbout(wxCommandEvent &event)
{
	MainEditBox->Clear();
	MainEditBox->setValue(wxString::Format(""));
	wxMessageBox(wxT("Name: Ean Bynoe.\nStudent ID: 400005520\n Course: Data Structures\n Assignment: 2"));
}
void onExitHelp(wxCommandEvent &event)
{
	MainEditBox->Clear();
	wxMessageBox(wxT("\nGood-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
	Close(TRUE);
}
>>>>>>> Stashed changes
