#ifndef DATADIALOG_H
#define DATADIALOG_H

struct data // data that is needed
    {
        int IDNo;
        
    }; 
 typedef struct data Data; 
  
  
    
    
  
//Define a dialog box class with the 4 data fields (Attributes) - inheriting from wxDialog, of course 
class DataDialog: public wxDialog
    {
        public:
                DataDialog(const wxString& title, const wxPoint& pos, const wxSize& size);
                
                //text boxes
                wxSpinCtrl* IDEditBox;
                

    };

    
    
    
    
    
//-----------------------------------------------------------------------------------------
// The constructor function for the DataDialog class - this is where it all happens
//-----------------------------------------------------------------------------------------
DataDialog::DataDialog ( const wxString& title, const wxPoint& pos, 
                        const wxSize& size): wxDialog((wxDialog *)NULL, -1, title, pos, size)
    {
      
        //The new new panel for the DataDialog box
        wxPanel    *panel = new wxPanel(this, -1);
 
        
        
        //------------------------------------------------------------------------------------------
        //Define and position the StaticTexts - the labels
        //------------------------------------------------------------------------------------------
        wxStaticText *IDLabel 	  = new wxStaticText(panel, wxID_ANY, wxT(" Id Number"), 
                                                     wxPoint(15, 25) );
        
        
        

        //------------------------------------------------------------------------------------------
        //Define and position the Data Boxes
        //------------------------------------------------------------------------------------------
          IDEditBox  =  new wxSpinCtrl(panel, wxID_ANY, wxT("54712"), wxPoint(100, 25), 
                                          wxSize(150, -1), wxSP_ARROW_KEYS, 15678, 75000, 10203);
         
        //------------------------------------------------------------------------------------------
        // Define and position the Response buttons (OK and CANCEL)
        //------------------------------------------------------------------------------------------
    
        // The OK button
        wxButton* ok = new wxButton(panel, wxID_OK, wxT("&OK"), wxPoint(110, 180), 
                                    wxDefaultSize, 0);

        // The CANCEL button
        wxButton* cancel = new wxButton ( panel, wxID_CANCEL, wxT("&CANCEL"), 
                                          wxPoint(230, 180), wxDefaultSize, 0 );
    
        // Centre the dialog on the parent's window
        Centre();

        // Maximize(); // Maximize the window
    
  }
  

  
  
 
  
  

//-----------------------------------------------------------------------------------------
// We can also grab the data from the DataDialog box and send it back as a string
//-----------------------------------------------------------------------------------------

wxString getDataString(struct data dataRec)
    {
        wxString str = wxT("\n\n");
        
        wxString num;
        num << dataRec.IDNo;
        
         str.Append(num);
          str.Append(wxT("\t"));
        
        
        
        return str;
    }








#endif
