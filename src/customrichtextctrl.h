#ifndef CUSTOMRICHTEXTCTRL_H_
#define CUSTOMRICHTEXTCTRL_H_

#include <wx/richtext/richtextctrl.h>

class wxFocusEvent;

class customRichtextCtrl : public wxRichTextCtrl
{
public:
	customRichtextCtrl(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& value = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, 
			long style = 0, const wxValidator& validator = wxDefaultValidator, const wxString& name = wxTextCtrlNameStr);
	virtual ~customRichtextCtrl();
	void OnFocusLost(wxFocusEvent& event);
	void OnFocusGained(wxFocusEvent& event);
	
protected:
	DECLARE_EVENT_TABLE();
};

#endif /*CUSTOMRICHTEXTCTRL_H_*/
