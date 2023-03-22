requirements for the header of the widgets file to compile a cpp file

[header] #include <wx/wx.h> 
 class My App: public wxApp
 {
	public"
		virtual bool Online();
 };


 This is more or less equivalent to a global function that calls the classes to a constructor


[step 2.] Declare the inherited main from class from wxFrame[red]. In this class also will All the events handles be declared



[function] class MyFrame: public wxFrame
				{
					private:
							DECLARE_EVEMT_TABLE()   <!-- this handles events -->

					public:
							<!-- constructor -->
							MyFrame(const wxString& title);
4444444
				};
