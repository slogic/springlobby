
#ifndef __TAB_HOTKEY_h__
#define __TAB_HOTKEY_h__

#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>

#include <list>
#include <vector>
#include <memory>

#include "../../wxkeybinder/keybinder.h"

#include "hotkey_parser.h"
#include "HotkeyTypes.h"
#include "commandlist.h"


class hotkey_panel : public wxScrolledWindow
{
public:
	hotkey_panel(wxWindow *parent, wxWindowID id = 1, const wxString &title = wxT("Hotkeys"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0);
	~hotkey_panel(void);

	void SaveSettings();
	void UpdateControls(int=0/*unused*/);

	//static bool isDefaultBinding( const wxString& command, const wxString& springKey );

	bool HasProfileBeenModifiedOrSelected() const;
	void ResetProfileBeenModifiedOrSelected();
	//static bool isBindingInProfile( const key_binding& springprofile, const wxString& command, const wxString& springkey );

private:
	void selectProfileFromUikeys();
	wxString getNextFreeProfileName();
	void updateTreeView();

	static key_binding_collection getProfilesFromSettings();
	//static bool compareBindings( const key_binding& springBindings, const key_binding& kbBindings );
	static key_binding getBindingsFromProfile( const wxKeyProfile& profile );
	wxKeyProfile buildNewProfile( const wxString& name, const wxString& description, bool readOnly );
	void putKeybindingsToProfile( wxKeyProfile& profile, const key_binding& bindings );
	void addCommandToAllPanelProfiles( const CommandList::Command& cmd );

	wxKeyConfigPanel*	m_pKeyConfigPanel;
	hotkey_parser		m_uikeys_manager;

	void ButtonAddSelectionCommandClicked( wxCommandEvent& event );
	void ButtonAddCustomCommandClicked( wxCommandEvent& event );
	void OnAddCommand( const wxString& cmd );
};

#endif
