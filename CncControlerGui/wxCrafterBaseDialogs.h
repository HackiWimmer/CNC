//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterBaseDialogs.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERBASEDIALOGS_BASE_CLASSES_H
#define _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERBASEDIALOGS_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/listbook.h>
#include <wx/panel.h>
#include <wx/imaglist.h>
#include <wx/listctrl.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/radiobox.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/timer.h>
#include <wx/statbmp.h>
#include <wx/mstream.h>
#include <wx/filename.h>
#include <wx/animate.h>
#include <wx/simplebook.h>
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


class CncOSEnvironmentDialogBase : public wxDialog
{
protected:
    wxListbook* m_listbook;
    wxPanel* m_panelContext;
    wxListCtrl* m_cncContextListPlaceholder;
    wxStaticText* m_staticText72944;
    wxTextCtrl* m_cncContextPara;
    wxStaticText* m_staticText72966;
    wxTextCtrl* m_cncContextValue;
    wxPanel* m_panelOSEnvironment;
    wxListCtrl* m_osEnvironmentList;
    wxStaticText* m_staticText7294;
    wxTextCtrl* m_osEnvParam;
    wxStaticText* m_staticText7296;
    wxTextCtrl* m_osEnvValue;
    wxPanel* m_paneAppEnvironment;
    wxListCtrl* m_appEnvironmentList;
    wxStaticText* m_staticText72942;
    wxTextCtrl* m_appEnvParam;
    wxStaticText* m_staticText72964;
    wxTextCtrl* m_appEnvValue;
    wxPanel* m_panelModules;
    wxRadioBox* m_modulesSortedBy;
    wxListCtrl* m_moduleList;
    wxStaticText* m_staticText7315;
    wxTextCtrl* m_modAddress;
    wxStaticText* m_staticText7319;
    wxTextCtrl* m_modName;
    wxStaticText* m_staticText7323;
    wxTextCtrl* m_modVersion;
    wxStaticText* m_staticText7327;
    wxTextCtrl* m_modPath;
    wxPanel* m_panelVersions;
    wxStaticText* m_staticText7990;
    wxListCtrl* m_versionInfoList;
    wxStaticLine* m_staticLine7334;
    wxButton* m_btClose;

protected:
    virtual void onSize(wxSizeEvent& event) { event.Skip(); }
    virtual void selectOSEnvironmentItem(wxListEvent& event) { event.Skip(); }
    virtual void selectAppEnvironmentItem(wxListEvent& event) { event.Skip(); }
    virtual void sortModules(wxCommandEvent& event) { event.Skip(); }
    virtual void selectModulesItem(wxListEvent& event) { event.Skip(); }
    virtual void onClose(wxCommandEvent& event) { event.Skip(); }

public:
    wxListCtrl* GetCncContextListPlaceholder() { return m_cncContextListPlaceholder; }
    wxStaticText* GetStaticText72944() { return m_staticText72944; }
    wxTextCtrl* GetCncContextPara() { return m_cncContextPara; }
    wxStaticText* GetStaticText72966() { return m_staticText72966; }
    wxTextCtrl* GetCncContextValue() { return m_cncContextValue; }
    wxPanel* GetPanelContext() { return m_panelContext; }
    wxListCtrl* GetOsEnvironmentList() { return m_osEnvironmentList; }
    wxStaticText* GetStaticText7294() { return m_staticText7294; }
    wxTextCtrl* GetOsEnvParam() { return m_osEnvParam; }
    wxStaticText* GetStaticText7296() { return m_staticText7296; }
    wxTextCtrl* GetOsEnvValue() { return m_osEnvValue; }
    wxPanel* GetPanelOSEnvironment() { return m_panelOSEnvironment; }
    wxListCtrl* GetAppEnvironmentList() { return m_appEnvironmentList; }
    wxStaticText* GetStaticText72942() { return m_staticText72942; }
    wxTextCtrl* GetAppEnvParam() { return m_appEnvParam; }
    wxStaticText* GetStaticText72964() { return m_staticText72964; }
    wxTextCtrl* GetAppEnvValue() { return m_appEnvValue; }
    wxPanel* GetPaneAppEnvironment() { return m_paneAppEnvironment; }
    wxRadioBox* GetModulesSortedBy() { return m_modulesSortedBy; }
    wxListCtrl* GetModuleList() { return m_moduleList; }
    wxStaticText* GetStaticText7315() { return m_staticText7315; }
    wxTextCtrl* GetModAddress() { return m_modAddress; }
    wxStaticText* GetStaticText7319() { return m_staticText7319; }
    wxTextCtrl* GetModName() { return m_modName; }
    wxStaticText* GetStaticText7323() { return m_staticText7323; }
    wxTextCtrl* GetModVersion() { return m_modVersion; }
    wxStaticText* GetStaticText7327() { return m_staticText7327; }
    wxTextCtrl* GetModPath() { return m_modPath; }
    wxPanel* GetPanelModules() { return m_panelModules; }
    wxStaticText* GetStaticText7990() { return m_staticText7990; }
    wxListCtrl* GetVersionInfoList() { return m_versionInfoList; }
    wxPanel* GetPanelVersions() { return m_panelVersions; }
    wxListbook* GetListbook() { return m_listbook; }
    wxStaticLine* GetStaticLine7334() { return m_staticLine7334; }
    wxButton* GetBtClose() { return m_btClose; }
    CncOSEnvironmentDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Cnc Application Environment"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,600), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP|wxRESIZE_BORDER);
    virtual ~CncOSEnvironmentDialogBase();
};


class CncConnectProgressBase : public wxDialog
{
protected:
    wxTimer* m_observeTimer;
    wxTimer* m_startupTimer;
    wxStaticBitmap* m_staticBitmap5593;
    wxStaticText* m_staticText5589;
    wxPanel* m_connectActivityPanel;

protected:
    virtual void initDialog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void show(wxShowEvent& event) { event.Skip(); }
    virtual void observeTimer(wxTimerEvent& event) { event.Skip(); }
    virtual void startupTimer(wxTimerEvent& event) { event.Skip(); }

public:
    wxTimer* GetObserveTimer() { return m_observeTimer; }
    wxTimer* GetStartupTimer() { return m_startupTimer; }
    wxStaticBitmap* GetStaticBitmap5593() { return m_staticBitmap5593; }
    wxStaticText* GetStaticText5589() { return m_staticText5589; }
    wxPanel* GetConnectActivityPanel() { return m_connectActivityPanel; }
    CncConnectProgressBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CNC Serial Connect Progress"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxSTAY_ON_TOP|wxCAPTION);
    virtual ~CncConnectProgressBase();
};


class CncUsbConnectionDetectedBase : public wxDialog
{
protected:
    wxStaticBitmap* m_staticBitmap5919;
    wxStaticText* m_staticText5921;
    wxStaticText* m_portName;
    wxButton* m_ignore;
    wxButton* m_connect;

protected:
    virtual void initDilaog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void ignore(wxCommandEvent& event) { event.Skip(); }
    virtual void connect(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticBitmap* GetStaticBitmap5919() { return m_staticBitmap5919; }
    wxStaticText* GetStaticText5921() { return m_staticText5921; }
    wxStaticText* GetPortName() { return m_portName; }
    wxButton* GetIgnore() { return m_ignore; }
    wxButton* GetConnect() { return m_connect; }
    CncUsbConnectionDetectedBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("New controller connection is available . . ."), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CncUsbConnectionDetectedBase();
};


class CncLastProcessingTimestampSummaryBase : public wxDialog
{
protected:
    wxListCtrl* m_tsSummary;
    wxButton* m_btClose;

protected:
    virtual void onInitDilaog(wxInitDialogEvent& event) { event.Skip(); }
    virtual void onClose(wxCommandEvent& event) { event.Skip(); }

public:
    wxListCtrl* GetTsSummary() { return m_tsSummary; }
    wxButton* GetBtClose() { return m_btClose; }
    CncLastProcessingTimestampSummaryBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Last Processing Timestamp Summary"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CncLastProcessingTimestampSummaryBase();
};


class CncAutoProgressDialogBase : public wxDialog
{
protected:
    wxAnimationCtrl* m_animationCtrl;

protected:

public:
    wxAnimationCtrl* GetAnimationCtrl() { return m_animationCtrl; }
    CncAutoProgressDialogBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT(""), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxSTAY_ON_TOP);
    virtual ~CncAutoProgressDialogBase();
};


class CncExternalViewBoxBase : public wxDialog
{
protected:
    wxPanel* m_caption;
    wxStaticBitmap* m_staticBitmap85;
    wxStaticText* m_windowTitle;
    wxPanel* m_moveArea;
    wxButton* m_btMinMax;
    wxButton* m_btClose;
    wxSimplebook* m_viewBook;
    wxPanel* m_page1;
    wxPanel* m_placeholder1;
    wxStaticText* m_staticText93;
    wxPanel* m_page2;
    wxPanel* m_placeholder2;
    wxStaticText* m_staticText935;
    wxPanel* m_page3;
    wxPanel* m_placeholder3;
    wxStaticText* m_staticText93510;
    wxPanel* m_page4;
    wxPanel* m_placeholder4;
    wxStaticText* m_staticText9351015;
    wxPanel* m_status;
    wxTextCtrl* m_statusTextLeft;
    wxTextCtrl* m_statusTextMid;
    wxTextCtrl* m_statusTextRight;

protected:
    virtual void onShow(wxShowEvent& event) { event.Skip(); }
    virtual void onStartMove(wxMouseEvent& event) { event.Skip(); }
    virtual void onStopMove(wxMouseEvent& event) { event.Skip(); }
    virtual void onMotion(wxMouseEvent& event) { event.Skip(); }
    virtual void onMinMax(wxCommandEvent& event) { event.Skip(); }
    virtual void onCloseFromButton(wxCommandEvent& event) { event.Skip(); }
    virtual void onViewBookChnaged(wxNotebookEvent& event) { event.Skip(); }

public:
    wxStaticBitmap* GetStaticBitmap85() { return m_staticBitmap85; }
    wxStaticText* GetWindowTitle() { return m_windowTitle; }
    wxPanel* GetMoveArea() { return m_moveArea; }
    wxButton* GetBtMinMax() { return m_btMinMax; }
    wxButton* GetBtClose() { return m_btClose; }
    wxPanel* GetCaption() { return m_caption; }
    wxStaticText* GetStaticText93() { return m_staticText93; }
    wxPanel* GetPlaceholder1() { return m_placeholder1; }
    wxPanel* GetPage1() { return m_page1; }
    wxStaticText* GetStaticText935() { return m_staticText935; }
    wxPanel* GetPlaceholder2() { return m_placeholder2; }
    wxPanel* GetPage2() { return m_page2; }
    wxStaticText* GetStaticText93510() { return m_staticText93510; }
    wxPanel* GetPlaceholder3() { return m_placeholder3; }
    wxPanel* GetPage3() { return m_page3; }
    wxStaticText* GetStaticText9351015() { return m_staticText9351015; }
    wxPanel* GetPlaceholder4() { return m_placeholder4; }
    wxPanel* GetPage4() { return m_page4; }
    wxSimplebook* GetViewBook() { return m_viewBook; }
    wxTextCtrl* GetStatusTextLeft() { return m_statusTextLeft; }
    wxTextCtrl* GetStatusTextMid() { return m_statusTextMid; }
    wxTextCtrl* GetStatusTextRight() { return m_statusTextRight; }
    wxPanel* GetStatus() { return m_status; }
    CncExternalViewBoxBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("no caption available"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(800,600), long style = wxSTAY_ON_TOP);
    virtual ~CncExternalViewBoxBase();
};

#endif
