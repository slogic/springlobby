#ifndef SPRINGLOBBY_HEADERGUARD_FILELISTCTRL_H
#define SPRINGLOBBY_HEADERGUARD_FILELISTCTRL_H

#include "filelistfilter.h"

#include "../customlistctrl.h"
#include <vector>
#include <wx/intl.h>

class wxMenu;
class wxListEvent;
class wxCommandEvent;
class FileListDialog;


class FileListCtrl : public customListCtrl
{
  public:
    FileListCtrl( wxWindow* parent, FileListDialog* fld );
    ~FileListCtrl();

    typedef std::vector<wxString> HashVector;

    void Sort();

    void OnListRightClick( wxListEvent& event );
    void OnMouseMotion(wxMouseEvent& event);
    void OnColClick( wxListEvent& event );
    void GetSelectedHashes(HashVector&);
    void SetColumnWidths();

  protected:
    static int wxCALLBACK CompareNameUP(long item1, long item2, long sortData);
    static int wxCALLBACK CompareNameDOWN(long item1, long item2, long sortData);
    static int wxCALLBACK CompareCountryUP(long item1, long item2, long sortData);
    static int wxCALLBACK CompareCountryDOWN(long item1, long item2, long sortData);
    static int wxCALLBACK CompareRankUP(long item1, long item2, long sortData);
    static int wxCALLBACK CompareRankDOWN(long item1, long item2, long sortData);

    struct {
      int col;
      bool direction;
    } m_sortorder[3];

    wxMenu* m_popup;
//    Ui& m_ui;
//    static Ui* m_ui_for_sort;

    FileListDialog* m_parent_dialog;
    static FileListDialog* s_parent_dialog;

    DECLARE_EVENT_TABLE()
};

enum
{
    BLIST_LIST = wxID_HIGHEST,
    BLIST_DLMOD,
    BLIST_DLMAP
};

#endif // SPRINGLOBBY_HEADERGUARD_BATTLELISTCTRL_H