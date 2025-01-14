
/************************************************************************************
  Step 1: Always include the header file wx.h
*************************************************************************************/
#include <wx/wxprec.h>
#include <wx/spinctrl.h>
#include <wx/textctrl.h>
#include <wx/combobox.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include <fstream>
#include <string>
#include <iostream>
#include "DataDialog.h"

using namespace std;

#include "BSTree.h"
#include "AVLTree.h"
#include "RBTree.h"
#include "SplayTree.h"
#include "HeapTree.h"
#include "BTree.h"
// #include "Set.h"

// Pointers

BST *bst = new BST();
AVL *avl = new AVL();
RBT *rbt = new RBT();
SplayTree *splay = new SplayTree();
BinHeap *heap = new BinHeap();
// BTree* btree = new BTree();
// Set* set = new Set();

//
// declare the variables in the record and their size
class Catalog
{
public:
    int gID;
};

// make all ADTs global objects
/*
 BSTree* bst = newBSTree();
 AVL* avl = newAVL();
 */
/************************************************************************************
*************************************************************************************
  Step 2: Name an inherited application class from wxApp and declare it with
      the function to execute the program
*************************************************************************************
*************************************************************************************/
class MyApp : public wxApp
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
    wxTextCtrl *MainEditBox;
    wxTextCtrl *filenameTextBox;
    wxString CurrentFilePath; // The Path to the file we have open

    // Functions for File Menu Items
    void OnOpenFile(wxCommandEvent &event);
    void OnDisplay(wxCommandEvent &event);
    void OnSave(wxCommandEvent &event);
    void OnSaveAs(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);

    // void OnReadRec(wxCommandEvent& event); //reads files

    // Functions for Edit Items
    void OnCreateADT(wxCommandEvent &event);
    void OnAddRecordADT(wxCommandEvent &event);
    void OnDeleteRecordADT(wxCommandEvent &event);

    // Functions for BST Menu Items
    void OnInorderBST(wxCommandEvent &event);
    void OnPreorderBST(wxCommandEvent &event);
    void OnPostorderBST(wxCommandEvent &event);

    // Functions for AVL tree Menu Items
    //  void OnInorderAVL(wxCommandEvent& event);
    //  void OnPreorderAVL(wxCommandEvent& event);
    //  void OnPostorderAVL(wxCommandEvent& event);

    // Functions for Red Black tree Menu Items
    void OnInorderRBT(wxCommandEvent &event);
    void OnPreorderRBT(wxCommandEvent &event);
    void OnPostorderRBT(wxCommandEvent &event);

    // Functions for Splay tree Menu Items
    void OnInorderSplay(wxCommandEvent &event);
    void OnPreorderSplay(wxCommandEvent &event);
    void OnPostorderSplay(wxCommandEvent &event);

    // Functions for Heap Menu Items
    void OnDisplayAllHeap(wxCommandEvent &event);
    void OnSortHeap(wxCommandEvent &event);

    // Functions for Set tree Menu Items
    void OnDisplaySetA(wxCommandEvent &event);
    void OnDisplaySetB(wxCommandEvent &event);
    void OnDisplayIntersection(wxCommandEvent &event);
    void OnDisplayUnion(wxCommandEvent &event);

    // Function for Help Menu Item
    void OnAbout(wxCommandEvent &event);
    // void OnExit(wxCommandEvent& event);
};

/************************************************************************************
*************************************************************************************
  Step 4. Declare the compiler directives
*************************************************************************************
*************************************************************************************/
DECLARE_APP(MyApp)   // Declare Application class
IMPLEMENT_APP(MyApp) // Create Application class object

enum
{
    // File menu items
    ID_OpenFile = wxID_HIGHEST + 1, // File menu item
    ID_Display,
    ID_Save,
    ID_SaveAs,
    ID_Exit,
    // ID_ReadRec,

    // Edit submenu items
    ID_CreateADT,
    ID_AddRecordADT,
    ID_DeleteRecordADT,

    // BST submenu items
    ID_InorderBST,
    ID_PreorderBST,
    ID_PostorderBST,

    // AVL Tree submenu items
    ID_InorderAVL,
    ID_PreorderAVL,
    ID_PostorderAVL,

    // RBT items
    ID_InorderRBT,
    ID_PreorderRBT,
    ID_PostorderRBT,

    // Splay Tree
    ID_InorderSplay,
    ID_PreorderSplay,
    ID_PostorderSplay,

    // Heap submenu items
    ID_DisplayAllHeap,
    ID_SortHeap,

    // Set
    ID_DisplaySetA,
    ID_DisplaySetB,
    ID_DisplayIntersection,
    ID_DisplayUnion,

    // Help submenu items
    ID_About,
    // ID_Exit,

};

BEGIN_EVENT_TABLE(ProjectFrame, wxFrame)
// Events for the "File" menu items
EVT_MENU(ID_OpenFile, ProjectFrame::OnOpenFile) // File Menu
EVT_MENU(ID_Display, ProjectFrame::OnDisplay)
EVT_MENU(ID_Save, ProjectFrame::OnSave)
EVT_MENU(ID_SaveAs, ProjectFrame::OnSaveAs)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)
// EVT_MENU ( ID_ReadRec, ProjectFrame::OnReadRec)

// Events for the "Edit" menu items
EVT_MENU(ID_CreateADT, ProjectFrame::OnCreateADT)
EVT_MENU(ID_AddRecordADT, ProjectFrame::OnAddRecordADT)
EVT_MENU(ID_DeleteRecordADT, ProjectFrame::OnDeleteRecordADT)

// Events for the "BST" menu items
EVT_MENU(ID_InorderBST, ProjectFrame::OnInorderBST)
EVT_MENU(ID_PreorderBST, ProjectFrame::OnPreorderBST)
EVT_MENU(ID_PostorderBST, ProjectFrame::OnPostorderBST)

// Events for the "AVL Tree" menu items
EVT_MENU(ID_InorderAVL, ProjectFrame::OnInorderAVL)
EVT_MENU(ID_PreorderAVL, ProjectFrame::OnPreorderAVL)
EVT_MENU(ID_PostorderAVL, ProjectFrame::OnPostorderAVL)

// Events for the "Red Black Tree" menu items
EVT_MENU(ID_InorderRBT, ProjectFrame::OnInorderRBT)
EVT_MENU(ID_PreorderRBT, ProjectFrame::OnPreorderRBT)
EVT_MENU(ID_PostorderRBT, ProjectFrame::OnPostorderRBT)

// Events for the "Splay Tree" menu items
EVT_MENU(ID_InorderSplay, ProjectFrame::OnInorderSplay)
EVT_MENU(ID_PreorderSplay, ProjectFrame::OnPreorderSplay)
EVT_MENU(ID_PostorderSplay, ProjectFrame::OnPostorderSplay)

// Events for the "Heap" menu items
//   EVT_MENU(ID_DisplayAllHeap,    ProjectFrame::OnDeleteRecordHeap)
EVT_MENU(ID_SortHeap, ProjectFrame::OnSortHeap)

// Events for the "Set" menu items
EVT_MENU(ID_DisplaySetA, ProjectFrame::OnDisplaySetA)
EVT_MENU(ID_DisplaySetB, ProjectFrame::OnDisplaySetB)
EVT_MENU(ID_DisplaySetA, ProjectFrame::OnDisplaySetA)
EVT_MENU(ID_DisplayIntersection, ProjectFrame::OnDisplayIntersection)
EVT_MENU(ID_DisplayUnion, ProjectFrame::OnDisplayUnion)

// Events For the "Help" menu item
EVT_MENU(ID_About, ProjectFrame::OnAbout)
EVT_MENU(ID_Exit, ProjectFrame::OnExit)

END_EVENT_TABLE()

/************************************************************************************
*************************************************************************************
  Step 5.  Define the Application class function to initialize the application
*************************************************************************************
*************************************************************************************/
bool MyApp::OnInit()
{
    // Create the main application window
    ProjectFrame *frame = new ProjectFrame(wxT("COMP2611 - Data Structures Project #2"),
                                           wxPoint(50, 50),
                                           wxSize(1024, 720));

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
    SetIcon(wxIcon(wxT("uwiIcon.xpm")));

    // Create the main-menu items
    wxMenu *menuFile = new wxMenu;
    wxMenu *menuEdit = new wxMenu;
    wxMenu *menuBST = new wxMenu;
    wxMenu *menuAVL = new wxMenu;
    wxMenu *menuRedBlack = new wxMenu;
    wxMenu *menuSplay = new wxMenu;
    wxMenu *menuHeap = new wxMenu;
    wxMenu *menuSets = new wxMenu;
    wxMenu *menuHelp = new wxMenu;

    // Create a Menu bar
    wxMenuBar *menuBar = new wxMenuBar;

    // Append the main menu items to the Menu Bar
    menuBar->Append(menuFile, wxT("&File"));
    menuBar->Append(menuEdit, wxT("&Edit"));
    menuBar->Append(menuBST, wxT("&BST"));
    menuBar->Append(menuAVL, wxT("&AVL Tree"));
    menuBar->Append(menuRedBlack, wxT("&RB Tree"));
    menuBar->Append(menuSplay, wxT("&Splay Tree"));
    menuBar->Append(menuHeap, wxT("&Heap"));
    menuBar->Append(menuSets, wxT("&Sets"));
    menuBar->Append(menuHelp, wxT("&Help"));

    // Append the sub-menu items to the Main Menu items

    // File Sub-Menu items
    menuFile->Append(ID_OpenFile, wxT("&Open File"), wxT("Open an Existing file"));
    menuFile->Append(ID_Display, wxT("&Display File"), wxT("Display contents of opened file"));
    menuFile->Append(ID_Save, wxT("&Save"), wxT("Save opened file"));
    menuFile->Append(ID_SaveAs, wxT("Sa&ve As"), wxT("Save display as a new file"));
    menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

    // Edit Sub-menu items
    menuEdit->Append(ID_CreateADT, wxT("&Create ADT..."), wxT("Create Edit from the File uploaded"));
    menuEdit->Append(ID_AddRecordADT, wxT("&Add a Record..."), wxT("Manually add a record to ADT"));
    menuEdit->Append(ID_DeleteRecordADT, wxT("&Delete a Record "), wxT("Delete a specified record from ADT"));

    // BST Sub-menu items
    menuBST->Append(ID_InorderBST, wxT("&Inorder..."), wxT("Display the in order traversal result of the BST"));
    menuBST->Append(ID_PreorderBST, wxT("&Preorder"), wxT("Display the preorder traversal result of the BST"));
    menuBST->Append(ID_PostorderBST, wxT("&Postorder"), wxT("Display the postorder traversal result of the BST"));

    // AVL Tree Sub-menu items
    menuAVL->Append(ID_InorderAVL, wxT("&Inorder..."), wxT("Display the in order traversal result of the AVL"));
    menuAVL->Append(ID_PreorderAVL, wxT("&Preorder"), wxT("Display the preorder traversal result of the AVL"));
    menuAVL->Append(ID_PostorderAVL, wxT("&Postorder"), wxT("Display the postorder traversal result of the AVL"));

    // RBT Sub-menu items
    menuRedBlack->Append(ID_InorderRBT, wxT("&Inorder..."), wxT("Display the inorder traversal result of the RBT"));
    menuRedBlack->Append(ID_PreorderRBT, wxT("&Preorder"), wxT("Display the preordewr traversal result of the RBT"));
    menuRedBlack->Append(ID_PostorderRBT, wxT("&Postorder"), wxT("Display the postorder traversal result of the RBT"));

    // Splay Tree Sub-menu items
    menuSplay->Append(ID_InorderSplay, wxT("&Inorder..."), wxT("Display the inorder traversal result of the Splay Tree"));
    menuSplay->Append(ID_PreorderSplay, wxT("&Preorder"), wxT("Display the preordewr traversal result of the Splay Tree"));
    menuSplay->Append(ID_PostorderSplay, wxT("&Postorder"), wxT("Display the postorder traversal result of the Splay Tree"));

    // Heap Sub-menu items
    menuHeap->Append(ID_DisplayAllHeap, wxT("Display All..."), wxT("Display ALL the inorder in the MinHeap tree"));
    menuHeap->Append(ID_SortHeap, wxT("Heap Sort"), wxT("Display the results of Heap Sort of the MinHeap tree"));

    // Sets Tree Sub-menu items
    menuSets->Append(ID_DisplaySetA, wxT("Display SetA"), wxT("Display ALL records in Set A"));
    menuSets->Append(ID_DisplaySetB, wxT("Display Set B"), wxT("Display ALL records in Set B"));
    menuSets->Append(ID_DisplayIntersection, wxT("Display Intersection"), wxT("Display the Intersection records of Set A and Set B"));
    menuSets->Append(ID_DisplayUnion, wxT("Display Union"), wxT("Display the Union records of Set A and Set B"));

    // Help Sub-menu items
    menuHelp->Append(ID_About, wxT("About"), wxT("Dialog box with the 'About' information"));
    menuFile->Append(ID_Exit, wxT("E&xit"), wxT("Close and EXIT Program"));

    // Attach the main menu bar to the frame
    SetMenuBar(menuBar);

    // Create a status bar
    CreateStatusBar(3);

    // Put text in the First Section of status bar
    SetStatusText(wxT("Ready..."));

    // Put text in the Second Section of status bar
    SetStatusText(wxT("Ean Bynoe"), 1);

    // Put text in the Third Section of status bar
    SetStatusText(wxT("400005520"), 2);

    // Set up the panel for data display
    //===============================================================================
    //================= DO NOT CHANGE THE CODE IN THIS SECTION ======================
    //===============================================================================

    wxPanel *panel = new wxPanel(this, -1);
    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);    // Vertical sizer for main window
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

//=====================================================================
//=========== Other Support Functions =================================
//=====================================================================

struct song
{
public:
    string Month;
    int Year;
    string Artist;
    string SongTitle;
    string RecordLabel;
    int WeeksAtNumberOne;
};

typedef struct song songs;

/**************************************************************************
***************************************************************************
  Step 7:  Define member functions for the Frame class
***************************************************************************
***************************************************************************/

//=========================================================================
//======== Definition for the File Functions ==============================
//=========================================================================
/*
void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
    // Creates a "open file" dialog with 3 file types
    wxFileDialog *OpenDialog = new wxFileDialog(this,
                                                (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                                (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
        // Sets our current document to the file the user selected
        CurrentFilePath = OpenDialog->GetPath();

        // Clean up filename textbox and Display file name in filename textbox
        filenameTextBox->Clear();
        filenameTextBox->AppendText(CurrentFilePath);

        // MainEditBox->LoadFile(CurrentFilePath);   //Opens that file in the MainEditBox

        string record = "";

        song songs;

        // open the file
        ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);

        // Put all the values in the variable "record" so you can display them in the MainEditBox
        while (!infile.eof())
        {

            infile.read(reinterpret_cast<char *>(&songs), sizeof(song));
            record.append(songs.Month + " " + to_string(songs.Year) + " " + songs.Artist + " " + songs.SongTitle + " " + songs.RecordLabel + " " + to_string(songs.WeeksAtNumberOne) + "\n");
        }
        infile.close();

        // Convert record to a wxString variable
        wxString wxRecord(record.c_str(), wxConvUTF8);

        MainEditBox->Clear();

        // Now display the wxString variable in the MainEditBox
        MainEditBox->AppendText(wxRecord);
    }
}
 */
void ProjectFrame::OnSave(wxCommandEvent &event)
{
    // Save to the already-set path for the document
    MainEditBox->SaveFile();
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
        CurrentFilePath = SaveDialog->GetPath();

        // set the path of our current document to the file the user chose to save under
        MainEditBox->SaveFile(CurrentFilePath); // Save the file to the selected path

        // Set the Title to reflect the file open
        SetTitle(wxString(wxT("Dummy Text")));
    }
}

void ProjectFrame::OnDisplay(wxCommandEvent &event)
{
    string record = "";

    song songs;

    // open the file
    ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);

    if (!infile)
    {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));
        return;
    }
    MainEditBox->Clear();

    while (!infile.eof())
    {
        infile.read(reinterpret_cast<char *>(&songs), sizeof(song));
        record.append(songs.Month + " " + to_string(songs.Year) + " " + songs.Artist + " " + songs.SongTitle + " " + songs.RecordLabel + " " + to_string(songs.WeeksAtNumberOne) + "\n");
    }
    infile.close();

    // Convert record to a wxString variable
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->Clear();

    // Now display the wxString variable in the MainEditBox
    MainEditBox->AppendText(wxRecord);

} // End while

void ProjectFrame::OnExit(wxCommandEvent &event)
{
    wxMessageBox(wxT("Good-bye!"), wxT("Exit"), wxOK | wxICON_INFORMATION, this);
    Close(TRUE); // Close the window
}

void ProjectFrame::OnOpenFile(wxCommandEvent &event)
{
    // Creates a "open file" dialog with 3 file types
    wxFileDialog *OpenDialog = new wxFileDialog(this,
                                                (wxT("Choose a file to open")), wxEmptyString, wxEmptyString,
                                                (wxT("Data Files (*.dat)|*.dat|Text files (*.txt)|*.txt|All files (*.*)|*.*")), wxFD_OPEN, wxDefaultPosition);

    if (OpenDialog->ShowModal() == wxID_OK) // if the user click "Open" instead of "cancel"
    {
        // Sets our current document to the file the user selected
        CurrentFilePath = OpenDialog->GetPath();

        // Clean up filename textbox and Display file name in filename textbox
        filenameTextBox->Clear();
        filenameTextBox->AppendText(CurrentFilePath);

        // MainEditBox->LoadFile(CurrentFilePath);   //Opens that file in the MainEditBox

        string record = "";

        song songs;

        // open the file
        ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);

        // Put all the values in the variable "record" so you can display them in the MainEditBox
        while (!infile.eof())
        {
            record.append(songs.Month + " " + to_string(songs.Year) + " " + songs.Artist + " " + songs.SongTitle + " " + songs.RecordLabel + " " + to_string(songs.WeeksAtNumberOne) + "\n");
            infile.read(reinterpret_cast<char *>(&songs), sizeof(song));
        }
        infile.close();

        // Convert record to a wxString variable
        wxString wxRecord(record.c_str(), wxConvUTF8);

        MainEditBox->Clear();

        // Now display the wxString variable in the MainEditBox
        MainEditBox->AppendText(wxRecord);
    }
}

//=============================================================================
//============== Definition for the BST Functions =============================
//=============================================================================
void ProjectFrame::OnCreateADT(wxCommandEvent &event)
{
    song songs;

    string record, heading;

    // clear main filenameTextBox
    MainEditBox->Clear();

    // open file
    ifstream infile(CurrentFilePath.mb_str(), ios::in | ios::binary);

    if (!infile)
    {
        MainEditBox->AppendText(wxT("\n\n\t\t\t\tNo Data file opened as yet...\n\n"));

        return;
    }
    // clear MainEditBox
    MainEditBox->Clear();

    while (!infile.eof())
    {

        infile.read(reinterpret_cast<char *>(&songs), sizeof(song));
        record.append(songs.Month + " " + to_string(songs.Year) + " " + songs.Artist + " " + songs.SongTitle + " " + songs.RecordLabel + " " + to_string(songs.WeeksAtNumberOne) + "\n");

        // Convert record to a wxString variable
        // wxString wxRecord(record.c_str(), wxConvUTF8);

        // Now display the wxString variable in the MainEditBox
        // MainEditBox->AppendText(wxRecord);

        // record = "";

        BSTNode *node;
        bst->insert(record);

        // AVLNode* node;
        // avl->insert(songs.gID);

        // RBTNode* node;
        // rbt->insert(songs.gID);
    }

    // SplayNode* node;
    // splay->Insert(songs.gID);
    // infile.close();

    // insert the record into all the appropriate ADTs
    // bst->insert(....); //inserting data?

    // Convert record to a wxString variable
    wxString wxRecord(record.c_str(), wxConvUTF8);

    // MainEditBox->Clear();

    // Now display the wxString variable in the MainEditBox
    MainEditBox->AppendText(wxRecord);

    infile.close();

    // MainEditBox->LoadFile(CurrentFilePath);
    // record = "";
}

void ProjectFrame::OnAddRecordADT(wxCommandEvent &event)
{
    Data dataRec;
    MainEditBox->Clear();

    DataDialog *datadialog = new DataDialog(wxT("COMP2611 - Add Record"), wxPoint(200, 300), wxSize(550, 250));

    if (datadialog->ShowModal() == wxID_OK)
    {

        dataRec.IDNo = datadialog->IDEditBox->GetValue(); // for idnumber

        //----------------------------------------------------------------
        //--- Now you have the data in dataRec, do something with it ----
        //----------------------------------------------------------------
        // Clear the main edit box and display the record just grabbed
        MainEditBox->Clear();

        MainEditBox->AppendText(getDataString(dataRec));

        int IDNo = dataRec.IDNo;

        // bst->insert(IDNo);
        // avl->insert(IDNo);

        // heap->addMinHeap(IDNo);
    }

    else // if (datadialog->ShowModal() == wxID_CANCEL)
        datadialog->Close();
    datadialog->Destroy(); // Destroy the dialog box
}

void ProjectFrame::OnDeleteRecordADT(wxCommandEvent &event)
{
    Data dataRec;
    MainEditBox->Clear();

    DataDialog *datadialog = new DataDialog(wxT("COMP2611 - Add Record"), wxPoint(200, 300), wxSize(550, 250));

    if (datadialog->ShowModal() == wxID_OK)
    {

        dataRec.IDNo = datadialog->IDEditBox->GetValue(); // for idnumber

        //----------------------------------------------------------------
        //--- Now you have the data in dataRec, do something with it ----
        //----------------------------------------------------------------
        // Clear the main edit box and display the record just grabbed
        MainEditBox->Clear();

        MainEditBox->AppendText(getDataString(dataRec));

        int IDNo = dataRec.IDNo;

        // bst->remove(IDNo);
        // avl->remove(IDNo);
    }

    else // if (datadialog->ShowModal() == wxID_CANCEL)
        datadialog->Close();
    datadialog->Destroy(); // Destroy the dialog box
}

void ProjectFrame::OnInorderBST(wxCommandEvent &event)
{
    // clear MainEditBox
    MainEditBox->Clear();

    string record = bst->inOrder();
    // convert to string
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

void ProjectFrame::OnPreorderBST(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = bst->preOrder();
    // convert to string
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

void ProjectFrame::OnPostorderBST(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = bst->postOrder();
    // convert to string
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the AVL Tree Functions ========================
//=============================================================================
/* void ProjectFrame::OnInorderAVL(wxCommandEvent& event)
        {
            MainEditBox->Clear();

            string record = avl->inOrder();

             wxString wxRecord(record.c_str(), wxConvUTF8);

            MainEditBox->AppendText(wxRecord);

    }

void ProjectFrame::OnPreorderAVL(wxCommandEvent& event)
        {
            MainEditBox->Clear();

            string record = avl->preOrder();

             wxString wxRecord(record.c_str(), wxConvUTF8);

            MainEditBox->AppendText(wxRecord);

    }

void ProjectFrame::OnPostorderAVL(wxCommandEvent& event)
        {
            MainEditBox->Clear();

            string record = avl->postOrder();

             wxString wxRecord(record.c_str(), wxConvUTF8);

            MainEditBox->AppendText(wxRecord);

    }
 */
//=============================================================================
//============== Definition for the Heap Functions ============================
//=============================================================================

void ProjectFrame::OnDisplayAllHeap(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = heap->displayHeap();
    // convert to string
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

void ProjectFrame::OnSortHeap(wxCommandEvent &event)
{

    MainEditBox->Clear();

    string record = heap->sortMinHeap();
    // convert to string
    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the Red Black Tree Functions ==================
//=============================================================================

void ProjectFrame::OnInorderRBT(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = rbt->inOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}
void ProjectFrame::OnPreorderRBT(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = rbt->preOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}
void ProjectFrame::OnPostorderRBT(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = rbt->postOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the Splay Functions ===========================
//=============================================================================
void ProjectFrame::OnInorderSplay(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = splay->InOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}
void ProjectFrame::OnPreorderSplay(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = splay->PreOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}
void ProjectFrame::OnPostorderSplay(wxCommandEvent &event)
{
    MainEditBox->Clear();

    string record = splay->PostOrder();

    wxString wxRecord(record.c_str(), wxConvUTF8);

    MainEditBox->AppendText(wxRecord);
}

//=============================================================================
//============== Definition for the Set Functions =============================
//=============================================================================
void ProjectFrame::OnDisplaySetA(wxCommandEvent &event)
{
}
void ProjectFrame::OnDisplaySetB(wxCommandEvent &event)
{
}
void ProjectFrame::OnDisplayIntersection(wxCommandEvent &event)
{
}
void ProjectFrame::OnDisplayUnion(wxCommandEvent &event)
{
}

//=============================================================================
//============== Definition for the Help Functions ===========================
//=============================================================================
void ProjectFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox(wxT("This software was developed by Ean Bynoe, who is persuing a Bachelor's Degree in Computer Science and Mathematics."), wxT("OK"), wxOK | wxICON_INFORMATION, this);
}

// g++ gui.cpp -o gui `wx-config --libs --cxxflags`
