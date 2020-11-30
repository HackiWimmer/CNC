//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterReferencePosition.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERREFERENCEPOSITION_BASE_CLASSES_H
#define _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERREFERENCEPOSITION_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/dialog.h>
#include <wx/iconbndl.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/statbmp.h>
#include <wx/radiobox.h>
#include <wx/panel.h>
#include <wx/tglbtn.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/timer.h>
#include <wx/listbox.h>
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


class CncReferencePositionBase : public wxDialog
{
protected:
    wxStaticText* m_staticText5505;
    wxStaticLine* m_staticLine5357;
    wxStaticText* m_staticText53555;
    wxStaticBitmap* m_staticBitmap58442;
    wxRadioBox* m_rbStepSensitivity;
    wxStaticText* m_staticText5355;
    wxStaticBitmap* m_staticBitmap5844;
    wxRadioBox* m_rbStepMode;
    wxPanel* m_navigationPanelPlaceholder;
    wxStaticLine* m_staticLine535015;
    wxStaticBitmap* m_staticBitmap5847;
    wxStaticText* m_staticText5340;
    wxStaticText* m_modeSelected;
    wxStaticText* m_modeText;
    wxStaticText* m_staticText5460;
    wxBitmapToggleButton* m_btMode1;
    wxStaticText* m_staticText5467;
    wxBitmapToggleButton* m_btMode2;
    wxStaticText* m_staticText5469;
    wxBitmapToggleButton* m_btMode3;
    wxStaticText* m_staticText5471;
    wxBitmapToggleButton* m_btMode4;
    wxStaticText* m_staticText5473;
    wxBitmapToggleButton* m_btMode5;
    wxStaticText* m_staticText5475;
    wxBitmapToggleButton* m_btMode6;
    wxStaticLine* m_staticLine53501;
    wxStaticText* m_staticText5486;
    wxTextCtrl* m_workpiceThickness;
    wxStaticText* m_staticText5497;
    wxStaticText* m_staticText5488;
    wxTextCtrl* m_measurePlateThickness;
    wxStaticText* m_staticText5499;
    wxStaticLine* m_staticLine5350;
    wxStaticText* m_staticText132;
    wxStaticText* m_staticText137;
    wxTextCtrl* m_previewX;
    wxStaticText* m_staticText1371;
    wxTextCtrl* m_previewY;
    wxStaticText* m_staticText13712;
    wxTextCtrl* m_previewZ;
    wxStaticText* m_staticText137123;
    wxStaticLine* m_staticLine74514;
    wxStaticBitmap* m_infoBitmap;
    wxStaticLine* m_staticLine74384;
    wxStaticText* m_staticText7442;
    wxStaticText* m_staticText7444;
    wxStaticText* m_staticText7446;
    wxBitmapToggleButton* m_btZeroX;
    wxBitmapToggleButton* m_btZeroY;
    wxBitmapToggleButton* m_btZeroZ;
    wxStaticLine* m_staticLine7438;
    wxButton* m_btSet;
    wxButton* m_btCancel;
    wxStaticLine* m_staticLine7451;
    wxTimer* m_infoTimer;

protected:
    virtual void init(wxInitDialogEvent& event) { event.Skip(); }
    virtual void show(wxShowEvent& event) { event.Skip(); }
    virtual void selectStepSensitivity(wxCommandEvent& event) { event.Skip(); }
    virtual void selectStepMode(wxCommandEvent& event) { event.Skip(); }
    virtual void mode1(wxCommandEvent& event) { event.Skip(); }
    virtual void mode2(wxCommandEvent& event) { event.Skip(); }
    virtual void mode3(wxCommandEvent& event) { event.Skip(); }
    virtual void mode4(wxCommandEvent& event) { event.Skip(); }
    virtual void mode5(wxCommandEvent& event) { event.Skip(); }
    virtual void mode6(wxCommandEvent& event) { event.Skip(); }
    virtual void updateWorkpieceThickness(wxCommandEvent& event) { event.Skip(); }
    virtual void selectInformation(wxMouseEvent& event) { event.Skip(); }
    virtual void toggleZeroX(wxCommandEvent& event) { event.Skip(); }
    virtual void toggleZeroY(wxCommandEvent& event) { event.Skip(); }
    virtual void toggleZeroZ(wxCommandEvent& event) { event.Skip(); }
    virtual void set(wxCommandEvent& event) { event.Skip(); }
    virtual void cancel(wxCommandEvent& event) { event.Skip(); }
    virtual void onInfoTimer(wxTimerEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText5505() { return m_staticText5505; }
    wxStaticLine* GetStaticLine5357() { return m_staticLine5357; }
    wxStaticText* GetStaticText53555() { return m_staticText53555; }
    wxStaticBitmap* GetStaticBitmap58442() { return m_staticBitmap58442; }
    wxRadioBox* GetRbStepSensitivity() { return m_rbStepSensitivity; }
    wxStaticText* GetStaticText5355() { return m_staticText5355; }
    wxStaticBitmap* GetStaticBitmap5844() { return m_staticBitmap5844; }
    wxRadioBox* GetRbStepMode() { return m_rbStepMode; }
    wxPanel* GetNavigationPanelPlaceholder() { return m_navigationPanelPlaceholder; }
    wxStaticLine* GetStaticLine535015() { return m_staticLine535015; }
    wxStaticBitmap* GetStaticBitmap5847() { return m_staticBitmap5847; }
    wxStaticText* GetStaticText5340() { return m_staticText5340; }
    wxStaticText* GetModeSelected() { return m_modeSelected; }
    wxStaticText* GetModeText() { return m_modeText; }
    wxStaticText* GetStaticText5460() { return m_staticText5460; }
    wxBitmapToggleButton* GetBtMode1() { return m_btMode1; }
    wxStaticText* GetStaticText5467() { return m_staticText5467; }
    wxBitmapToggleButton* GetBtMode2() { return m_btMode2; }
    wxStaticText* GetStaticText5469() { return m_staticText5469; }
    wxBitmapToggleButton* GetBtMode3() { return m_btMode3; }
    wxStaticText* GetStaticText5471() { return m_staticText5471; }
    wxBitmapToggleButton* GetBtMode4() { return m_btMode4; }
    wxStaticText* GetStaticText5473() { return m_staticText5473; }
    wxBitmapToggleButton* GetBtMode5() { return m_btMode5; }
    wxStaticText* GetStaticText5475() { return m_staticText5475; }
    wxBitmapToggleButton* GetBtMode6() { return m_btMode6; }
    wxStaticLine* GetStaticLine53501() { return m_staticLine53501; }
    wxStaticText* GetStaticText5486() { return m_staticText5486; }
    wxTextCtrl* GetWorkpiceThickness() { return m_workpiceThickness; }
    wxStaticText* GetStaticText5497() { return m_staticText5497; }
    wxStaticText* GetStaticText5488() { return m_staticText5488; }
    wxTextCtrl* GetMeasurePlateThickness() { return m_measurePlateThickness; }
    wxStaticText* GetStaticText5499() { return m_staticText5499; }
    wxStaticLine* GetStaticLine5350() { return m_staticLine5350; }
    wxStaticText* GetStaticText132() { return m_staticText132; }
    wxStaticText* GetStaticText137() { return m_staticText137; }
    wxTextCtrl* GetPreviewX() { return m_previewX; }
    wxStaticText* GetStaticText1371() { return m_staticText1371; }
    wxTextCtrl* GetPreviewY() { return m_previewY; }
    wxStaticText* GetStaticText13712() { return m_staticText13712; }
    wxTextCtrl* GetPreviewZ() { return m_previewZ; }
    wxStaticText* GetStaticText137123() { return m_staticText137123; }
    wxStaticLine* GetStaticLine74514() { return m_staticLine74514; }
    wxStaticBitmap* GetInfoBitmap() { return m_infoBitmap; }
    wxStaticLine* GetStaticLine74384() { return m_staticLine74384; }
    wxStaticText* GetStaticText7442() { return m_staticText7442; }
    wxStaticText* GetStaticText7444() { return m_staticText7444; }
    wxStaticText* GetStaticText7446() { return m_staticText7446; }
    wxBitmapToggleButton* GetBtZeroX() { return m_btZeroX; }
    wxBitmapToggleButton* GetBtZeroY() { return m_btZeroY; }
    wxBitmapToggleButton* GetBtZeroZ() { return m_btZeroZ; }
    wxStaticLine* GetStaticLine7438() { return m_staticLine7438; }
    wxButton* GetBtSet() { return m_btSet; }
    wxButton* GetBtCancel() { return m_btCancel; }
    wxStaticLine* GetStaticLine7451() { return m_staticLine7451; }
    wxTimer* GetInfoTimer() { return m_infoTimer; }
    CncReferencePositionBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("CNC Reference Position (0, 0, 0)"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP);
    virtual ~CncReferencePositionBase();
};


class CncStartPositionResolverBase : public wxDialog
{
protected:
    wxStaticBitmap* m_staticBitmap7832;
    wxStaticText* m_staticText78442;
    wxTextCtrl* m_currentPositionX;
    wxTextCtrl* m_currentPositionY;
    wxTextCtrl* m_currentPositionZ;
    wxStaticText* m_staticText7874;
    wxStaticText* m_staticText78464;
    wxTextCtrl* m_referencePositionX;
    wxTextCtrl* m_referencePositionY;
    wxTextCtrl* m_referencePositionZ;
    wxStaticText* m_staticText7879;
    wxStaticText* m_staticText78486;
    wxTextCtrl* m_distanceX;
    wxTextCtrl* m_distanceY;
    wxTextCtrl* m_distanceZ;
    wxStaticText* m_staticText7885;
    wxStaticText* m_staticText7857;
    wxListBox* m_sequenceList;
    wxStaticLine* m_staticLine7836;
    wxButton* m_button7828;
    wxButton* m_button7830;

protected:
    virtual void onOk(wxCommandEvent& event) { event.Skip(); }
    virtual void onCancel(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticBitmap* GetStaticBitmap7832() { return m_staticBitmap7832; }
    wxStaticText* GetStaticText78442() { return m_staticText78442; }
    wxTextCtrl* GetCurrentPositionX() { return m_currentPositionX; }
    wxTextCtrl* GetCurrentPositionY() { return m_currentPositionY; }
    wxTextCtrl* GetCurrentPositionZ() { return m_currentPositionZ; }
    wxStaticText* GetStaticText7874() { return m_staticText7874; }
    wxStaticText* GetStaticText78464() { return m_staticText78464; }
    wxTextCtrl* GetReferencePositionX() { return m_referencePositionX; }
    wxTextCtrl* GetReferencePositionY() { return m_referencePositionY; }
    wxTextCtrl* GetReferencePositionZ() { return m_referencePositionZ; }
    wxStaticText* GetStaticText7879() { return m_staticText7879; }
    wxStaticText* GetStaticText78486() { return m_staticText78486; }
    wxTextCtrl* GetDistanceX() { return m_distanceX; }
    wxTextCtrl* GetDistanceY() { return m_distanceY; }
    wxTextCtrl* GetDistanceZ() { return m_distanceZ; }
    wxStaticText* GetStaticText7885() { return m_staticText7885; }
    wxStaticText* GetStaticText7857() { return m_staticText7857; }
    wxListBox* GetSequenceList() { return m_sequenceList; }
    wxStaticLine* GetStaticLine7836() { return m_staticLine7836; }
    wxButton* GetButton7828() { return m_button7828; }
    wxButton* GetButton7830() { return m_button7830; }
    CncStartPositionResolverBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = _("Cnc Start Position Resolver"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxDEFAULT_DIALOG_STYLE);
    virtual ~CncStartPositionResolverBase();
};

#endif
