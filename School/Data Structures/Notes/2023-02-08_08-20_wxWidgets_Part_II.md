# [notes]   wxWidgets Part 2 ( labels, text boxes, client area)


# Labels 
	1. Immutable texts

# Text boxes
	1. Mutable text

# Client area


[alt] (C:\Users\eanby\Music\Personal Workspace02\Notes\wxWidgets part 2.jpg)



## Labels - Immutable text

	* defined in "Your frame" constructor function
	* define as a pointer of type wxStaticText
	* Contains parameters
    	* wxPanel pointer -	Defined for the GUI frame
    	* wxID_ANY	- Fixed parameter
    	* "Label string" - Immtable text 
    	* wxPOint	- (x,y) position of label



[alt] [source(image_missing)]


#									 labels -  immutable text

Define a panel to represent the GUI space, which is not taken by the reserved areas ([green] The Client Area).

[example]	
	wxPanel *panel = new wxPanel (this, -1)

Define and position the labels 
[example_1.1]	
	wxStaticText *label = new wxStaticText (panel, wxID_ANY, wxT("Label A"), wxPoint(5,25));

[example_1.2]	
	wxStaticText *blabel = new wxStaticText (panel, wxID_ANY, wxT("Label B"), wxPoint (35, 65));



#							 		Texts  - Mutable Text

	* Declared as a pointer attribute of "Your Frame" class of type [red] wxTextCtrl
	* Define in "Your Frame" constructor function
	* Contains parameters

[example]
	wxTextCtrl *textBox = new wxTextCtrl (panel, ID_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxSize (300, 300), wxTE_MULTILINE);


[EXAMPLE]
[green] Single Line Text Box

textBox1 = new wxTextCtrl (panel, wxID_ANY,wxT("TextBox 1"), wxPoint(65,20), wxSize(200, -1));

[green] Multiple Line Text Box

textBox2 = new wxTextCtrl (panel, wxID_ANY,wxT("TextBox 2"), wxPoint(wxPoint975,165), wxSize(400,150),wxTE_MULTILINE| wxHSCROLL, wxVSCROLL);





# 											The Client Area



[alt] (missing 2 slides)

Defined as a wxPanel object

[Example] 
	wxPanel *panel = new wxPanel(this, -1)
		