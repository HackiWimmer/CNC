//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterUnitTest.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERUNITTEST_BASE_CLASSES_H
#define _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERUNITTEST_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/checkbox.h>
#include <wx/timer.h>
#if wxVERSION_NUMBER >= 2900
#include <wx/persist.h>
#include <wx/persist/toplevel.h>
#include <wx/persist/bookctrl.h>
#include <wx/persist/treebook.h>
#endif

#ifdef WXC_FROM_DIP
#undef WXC_FROM_DIP
#endif
#if wxVERSION_NUMBER >= 3100
#define WXC_FROM_DIP(x) wxWindow::FromDIP(x, NULL)
#else
#define WXC_FROM_DIP(x) x
#endif


class CncUnitTestsBase : public wxDialog
{
protected:
    wxStaticText* m_staticText3357;
    wxComboBox* m_unitTestSelector;
    wxButton* m_btUnitTestClear;
    wxButton* m_btUnitTestRun;
    wxTextCtrl* m_testResultStreamPlaceholder;
    wxStaticText* m_unitTestStatus;
    wxCheckBox* m_unitTestFreezeOutput;
    wxCheckBox* m_unitTestAutoRun;
    wxTimer* m_unitTestStartupTimer;

protected:
    virtual void onShow(wxShowEvent& event) { event.Skip(); }
    virtual void selectTest(wxCommandEvent& event) { event.Skip(); }
    virtual void clearView(wxCommandEvent& event) { event.Skip(); }
    virtual void onStartupTimer(wxTimerEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText3357() { return m_staticText3357; }
    wxComboBox* GetUnitTestSelector() { return m_unitTestSelector; }
    wxButton* GetBtUnitTestClear() { return m_btUnitTestClear; }
    wxButton* GetBtUnitTestRun() { return m_btUnitTestRun; }
    wxTextCtrl* GetTestResultStreamPlaceholder() { return m_testResultStreamPlaceholder; }
    wxStaticText* GetUnitTestStatus() { return m_unitTestStatus; }
    wxCheckBox* GetUnitTestFreezeOutput() { return m_unitTestFreezeOutput; }
    wxCheckBox* GetUnitTestAutoRun() { return m_unitTestAutoRun; }
    wxTimer* GetUnitTestStartupTimer() { return m_unitTestStartupTimer; }
    CncUnitTestsBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CNC Controller Unit Tests . . ."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER|wxMAXIMIZE_BOX|wxSYSTEM_MENU|wxCLOSE_BOX);
    virtual ~CncUnitTestsBase();
};

#endif
