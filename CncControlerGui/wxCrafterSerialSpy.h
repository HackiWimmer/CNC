//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterSerialSpy.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERSERIALSPY_BASE_CLASSES_H
#define _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERSERIALSPY_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/tglbtn.h>
#include <wx/button.h>
#include <wx/statline.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/bmpbuttn.h>
#include <wx/infobar.h>
#include <wx/imaglist.h>
#include <wx/bitmap.h>
#include <map>
#include <wx/icon.h>
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


class CncSerialSpyPanelBase : public wxPanel
{
protected:
    wxPanel* m_panel9492;
    wxBitmapToggleButton* m_enableSerialSpy;
    wxButton* m_MarkSerialSpy;
    wxStaticLine* m_staticLine9487;
    wxButton* m_clearSerialSpy;
    wxStaticLine* m_staticLine94873;
    wxComboBox* m_cbSerialSpyMode;
    wxStaticLine* m_staticLine9489;
    wxBitmapToggleButton* m_liveDecoding;
    wxBitmapToggleButton* m_autoScroling;
    wxBitmapToggleButton* m_autoColumnSizing;
    wxBitmapToggleButton* m_clearSerialSpyOnConnect;
    wxBitmapToggleButton* m_clearSerialSpyBeforNextRun;
    wxStaticLine* m_staticLine9495;
    wxBitmapButton* m_openDetails;
    wxPanel* m_serialSpyPlaceholder;
    wxInfoBar* m_infobar;

protected:
    virtual void enableSerialSpy(wxCommandEvent& event) { event.Skip(); }
    virtual void markSerialSpy(wxCommandEvent& event) { event.Skip(); }
    virtual void clearSerialSpy(wxCommandEvent& event) { event.Skip(); }
    virtual void selectSerialSpyMode(wxCommandEvent& event) { event.Skip(); }
    virtual void onLiveDecoding(wxCommandEvent& event) { event.Skip(); }
    virtual void onAutoScrolling(wxCommandEvent& event) { event.Skip(); }
    virtual void onAutoColumnSize(wxCommandEvent& event) { event.Skip(); }
    virtual void openSpyDetailWindow(wxCommandEvent& event) { event.Skip(); }

public:
    wxBitmapToggleButton* GetEnableSerialSpy() { return m_enableSerialSpy; }
    wxButton* GetMarkSerialSpy() { return m_MarkSerialSpy; }
    wxStaticLine* GetStaticLine9487() { return m_staticLine9487; }
    wxButton* GetClearSerialSpy() { return m_clearSerialSpy; }
    wxStaticLine* GetStaticLine94873() { return m_staticLine94873; }
    wxComboBox* GetCbSerialSpyMode() { return m_cbSerialSpyMode; }
    wxStaticLine* GetStaticLine9489() { return m_staticLine9489; }
    wxBitmapToggleButton* GetLiveDecoding() { return m_liveDecoding; }
    wxBitmapToggleButton* GetAutoScroling() { return m_autoScroling; }
    wxBitmapToggleButton* GetAutoColumnSizing() { return m_autoColumnSizing; }
    wxBitmapToggleButton* GetClearSerialSpyOnConnect() { return m_clearSerialSpyOnConnect; }
    wxBitmapToggleButton* GetClearSerialSpyBeforNextRun() { return m_clearSerialSpyBeforNextRun; }
    wxStaticLine* GetStaticLine9495() { return m_staticLine9495; }
    wxBitmapButton* GetOpenDetails() { return m_openDetails; }
    wxPanel* GetPanel9492() { return m_panel9492; }
    wxPanel* GetSerialSpyPlaceholder() { return m_serialSpyPlaceholder; }
    wxInfoBar* GetInfobar() { return m_infobar; }
    CncSerialSpyPanelBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxTAB_TRAVERSAL);
    virtual ~CncSerialSpyPanelBase();
};


class ImageLibSpy : public wxImageList
{
protected:
    // Maintain a map of all bitmaps representd by their name
    std::map<wxString, wxBitmap> m_bitmaps;
    // The requested image resolution (can be one of @2x, @1.5x, @1.25x or an empty string (the default)
    wxString m_resolution;
    int m_imagesWidth;
    int m_imagesHeight;


protected:

public:
    ImageLibSpy();
    const wxBitmap& Bitmap(const wxString &name) const {
        if ( !m_bitmaps.count(name + m_resolution) )
            return wxNullBitmap;
        return m_bitmaps.find(name + m_resolution)->second;
    }

    void SetBitmapResolution(const wxString &res = wxEmptyString) {
        m_resolution = res;
    }

    virtual ~ImageLibSpy();
};

#endif
