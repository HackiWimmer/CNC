//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterMotionMonitor.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#ifndef _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERMOTIONMONITOR_BASE_CLASSES_H
#define _CNCGUICONTROLLER_CNCCONTROLERGUI_WXCRAFTERMOTIONMONITOR_BASE_CLASSES_H

#include <wx/settings.h>
#include <wx/xrc/xmlres.h>
#include <wx/xrc/xh_bmp.h>
#include <wx/panel.h>
#include <wx/artprov.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/combobox.h>
#include <wx/arrstr.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/textctrl.h>
#include <wx/listbook.h>
#include <wx/imaglist.h>
#include <wx/tglbtn.h>
#include <wx/bmpbuttn.h>
#include <wx/listctrl.h>
#include <wx/splitter.h>
#include <wx/simplebook.h>
#include <wx/checkbox.h>
#include <wx/choicebk.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#include <wx/scrolwin.h>
#include <wx/slider.h>
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


class CncMonitorReplayPaneBase : public wxPanel
{
protected:
    wxStaticText* m_staticText8079;
    wxComboBox* m_cbStepUnit;
    wxStaticLine* m_staticLine7085;
    wxButton* m_replayStart;
    wxButton* m_replayPrev;
    wxButton* m_replayNext;
    wxButton* m_replayEnd;
    wxStaticLine* m_staticLine7069;
    wxButton* m_replayPlayAll;
    wxButton* m_replayPlayCurrentId;
    wxButton* m_replayPause;
    wxButton* m_replayStop;
    wxTextCtrl* m_currentVertexId;
    wxStaticText* m_staticText7081;
    wxTextCtrl* m_currentVertex;
    wxStaticText* m_staticText7075;
    wxTextCtrl* m_totalVerties;

protected:
    virtual void selectReplayUnit(wxCommandEvent& event) { event.Skip(); }
    virtual void replayStart(wxCommandEvent& event) { event.Skip(); }
    virtual void replayLeftUpPrev(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeavePrev(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeftDownPrev(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeftDClickPrev(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeftUpNext(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeaveNext(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeftDownNext(wxMouseEvent& event) { event.Skip(); }
    virtual void replayLeftDClickNext(wxMouseEvent& event) { event.Skip(); }
    virtual void replayEnd(wxCommandEvent& event) { event.Skip(); }
    virtual void replayPlayAll(wxCommandEvent& event) { event.Skip(); }
    virtual void replayPlayCurrentId(wxCommandEvent& event) { event.Skip(); }
    virtual void replayPause(wxCommandEvent& event) { event.Skip(); }
    virtual void replayStop(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText8079() { return m_staticText8079; }
    wxComboBox* GetCbStepUnit() { return m_cbStepUnit; }
    wxStaticLine* GetStaticLine7085() { return m_staticLine7085; }
    wxButton* GetReplayStart() { return m_replayStart; }
    wxButton* GetReplayPrev() { return m_replayPrev; }
    wxButton* GetReplayNext() { return m_replayNext; }
    wxButton* GetReplayEnd() { return m_replayEnd; }
    wxStaticLine* GetStaticLine7069() { return m_staticLine7069; }
    wxButton* GetReplayPlayAll() { return m_replayPlayAll; }
    wxButton* GetReplayPlayCurrentId() { return m_replayPlayCurrentId; }
    wxButton* GetReplayPause() { return m_replayPause; }
    wxButton* GetReplayStop() { return m_replayStop; }
    wxTextCtrl* GetCurrentVertexId() { return m_currentVertexId; }
    wxStaticText* GetStaticText7081() { return m_staticText7081; }
    wxTextCtrl* GetCurrentVertex() { return m_currentVertex; }
    wxStaticText* GetStaticText7075() { return m_staticText7075; }
    wxTextCtrl* GetTotalVerties() { return m_totalVerties; }
    CncMonitorReplayPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~CncMonitorReplayPaneBase();
};


class CncPreprocessorBase : public wxPanel
{
protected:
    wxListbook* m_listbookPreProcessor;
    wxPanel* m_panel7622;
    wxStaticText* m_staticText61381;
    wxStaticText* m_staticText7891;
    wxTextCtrl* m_pathListRowCount;
    wxStaticLine* m_staticLine7903;
    wxBitmapToggleButton* m_btConnectPathListEntries;
    wxStaticLine* m_staticLine78021113;
    wxBitmapButton* m_btClearPathListEntries;
    wxListCtrl* m_pathListEntriesPlaceholder;
    wxPanel* m_panel7630;
    wxStaticText* m_staticText613814;
    wxStaticText* m_staticText78912;
    wxTextCtrl* m_moveSequenceRowCount;
    wxStaticLine* m_staticLine7901;
    wxBitmapToggleButton* m_btConnectMoveSequences;
    wxBitmapButton* m_btClearMoveSequences;
    wxStaticLine* m_staticLine188;
    wxStaticText* m_staticText186;
    wxListCtrl* m_moveSequencesListPlaceholder;
    wxStaticText* m_contentLabel;
    wxListCtrl* m_moveSequencesPlaceholder;

protected:
    virtual void connectPathListEntries(wxCommandEvent& event) { event.Skip(); }
    virtual void clearPathListEntries(wxCommandEvent& event) { event.Skip(); }
    virtual void connectMoveSequences(wxCommandEvent& event) { event.Skip(); }
    virtual void clearMoveSequences(wxCommandEvent& event) { event.Skip(); }

public:
    wxStaticText* GetStaticText61381() { return m_staticText61381; }
    wxStaticText* GetStaticText7891() { return m_staticText7891; }
    wxTextCtrl* GetPathListRowCount() { return m_pathListRowCount; }
    wxStaticLine* GetStaticLine7903() { return m_staticLine7903; }
    wxBitmapToggleButton* GetBtConnectPathListEntries() { return m_btConnectPathListEntries; }
    wxStaticLine* GetStaticLine78021113() { return m_staticLine78021113; }
    wxBitmapButton* GetBtClearPathListEntries() { return m_btClearPathListEntries; }
    wxListCtrl* GetPathListEntriesPlaceholder() { return m_pathListEntriesPlaceholder; }
    wxPanel* GetPanel7622() { return m_panel7622; }
    wxStaticText* GetStaticText613814() { return m_staticText613814; }
    wxStaticText* GetStaticText78912() { return m_staticText78912; }
    wxTextCtrl* GetMoveSequenceRowCount() { return m_moveSequenceRowCount; }
    wxStaticLine* GetStaticLine7901() { return m_staticLine7901; }
    wxBitmapToggleButton* GetBtConnectMoveSequences() { return m_btConnectMoveSequences; }
    wxBitmapButton* GetBtClearMoveSequences() { return m_btClearMoveSequences; }
    wxStaticLine* GetStaticLine188() { return m_staticLine188; }
    wxStaticText* GetStaticText186() { return m_staticText186; }
    wxListCtrl* GetMoveSequencesListPlaceholder() { return m_moveSequencesListPlaceholder; }
    wxStaticText* GetContentLabel() { return m_contentLabel; }
    wxListCtrl* GetMoveSequencesPlaceholder() { return m_moveSequencesPlaceholder; }
    wxPanel* GetPanel7630() { return m_panel7630; }
    wxListbook* GetListbookPreProcessor() { return m_listbookPreProcessor; }
    CncPreprocessorBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(700,700), long style = wxTAB_TRAVERSAL);
    virtual ~CncPreprocessorBase();
};


class CncMotionVertexTraceBase : public wxPanel
{
protected:
    wxStaticText* m_staticText7928;
    wxSplitterWindow* m_splitter7938;
    wxPanel* m_vertexSplitterPageData;
    wxStaticText* m_staticText7954;
    wxPanel* m_motionVertexDataListPlaceholder;
    wxPanel* m_vertexSplitterPageIndex;
    wxStaticText* m_staticText7956;
    wxPanel* m_motionVertexIndexListPlaceholder;

protected:

public:
    wxStaticText* GetStaticText7928() { return m_staticText7928; }
    wxStaticText* GetStaticText7954() { return m_staticText7954; }
    wxPanel* GetMotionVertexDataListPlaceholder() { return m_motionVertexDataListPlaceholder; }
    wxPanel* GetVertexSplitterPageData() { return m_vertexSplitterPageData; }
    wxStaticText* GetStaticText7956() { return m_staticText7956; }
    wxPanel* GetMotionVertexIndexListPlaceholder() { return m_motionVertexIndexListPlaceholder; }
    wxPanel* GetVertexSplitterPageIndex() { return m_vertexSplitterPageIndex; }
    wxSplitterWindow* GetSplitter7938() { return m_splitter7938; }
    CncMotionVertexTraceBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxTAB_TRAVERSAL);
    virtual ~CncMotionVertexTraceBase();
};


class CncParsingSynopsisTraceBase : public wxPanel
{
protected:
    wxStaticText* m_staticText7928;
    wxPanel* m_parsingSynopsisListPlaceholder;

protected:

public:
    wxStaticText* GetStaticText7928() { return m_staticText7928; }
    wxPanel* GetParsingSynopsisListPlaceholder() { return m_parsingSynopsisListPlaceholder; }
    CncParsingSynopsisTraceBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500,300), long style = wxTAB_TRAVERSAL);
    virtual ~CncParsingSynopsisTraceBase();
};


class CncStatisticsPaneBase : public wxPanel
{
protected:
    wxSimplebook* m_contextBook;
    wxPanel* m_panelStatistics;
    wxListCtrl* m_statisticSummaryListCtrl;
    wxCheckBox* m_checkBoxStatisticUpdate;
    wxPanel* m_panelReplay;
    wxPanel* m_panel7059;
    wxPanel* m_replayPlaceholder;

protected:

public:
    wxListCtrl* GetStatisticSummaryListCtrl() { return m_statisticSummaryListCtrl; }
    wxCheckBox* GetCheckBoxStatisticUpdate() { return m_checkBoxStatisticUpdate; }
    wxPanel* GetPanelStatistics() { return m_panelStatistics; }
    wxPanel* GetPanel7059() { return m_panel7059; }
    wxPanel* GetReplayPlaceholder() { return m_replayPlaceholder; }
    wxPanel* GetPanelReplay() { return m_panelReplay; }
    wxSimplebook* GetContextBook() { return m_contextBook; }
    CncStatisticsPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~CncStatisticsPaneBase();
};


class GL3DOptionPaneBase : public wxPanel
{
protected:
    wxChoicebook* m_choicebook6345;
    wxPanel* m_panel3DOptions;
    wxPropertyGridManager* m_pgMgr3543;
    wxPGProperty* m_pgCatDisplayOptions;
    wxPGProperty* m_pgPropDrawType;
    wxPGProperty* m_pgPropAutoScaling;
    wxPGProperty* m_pgPropDrawOrigin;
    wxPGProperty* m_pgPropDrawFlyPath;
    wxPGProperty* m_pgPropDrawHelpLines;
    wxPGProperty* m_pgPropPositionMarker;
    wxPGProperty* m_pgPropZoom;
    wxPGProperty* m_pgCatRuler;
    wxPGProperty* m_pgPropDrawRuler;
    wxPGProperty* m_pgPropRulerOffset;
    wxPGProperty* m_pgCatPathColour;
    wxPGProperty* m_pgPropFlyAlpha;
    wxPGProperty* m_pgPropFlyColour;
    wxPGProperty* m_pgPropWorkColour;
    wxPGProperty* m_pgPropUserColour;
    wxPGProperty* m_pgPropMaxColour;
    wxPGProperty* m_pgPropHighLightColour;
    wxPGProperty* m_pgCatHL3D;
    wxPGProperty* m_pgPropHLXYPlane;
    wxPGProperty* m_pgPropHLXZPlane;
    wxPGProperty* m_pgPropHLYZPlane;
    wxPGProperty* m_pgCatBoundBox;
    wxPGProperty* m_pgPropDrawBoundBox;
    wxPGProperty* m_pgPropBoundBoxColour;
    wxPGProperty* m_pgCatRenderOptions;
    wxPGProperty* m_pgPropSmoothing;
    wxCheckBox* m_cbAutoUpdate;
    wxPanel* m_panelAnimation;
    wxScrolledWindow* m_scrollWin7039;
    wxStaticText* m_staticText6443;
    wxBitmapButton* m_btResetCameraPos2;
    wxSlider* m_sliderCameraRotation;
    wxBitmapToggleButton* m_btCameraRotationClockwise;
    wxBitmapToggleButton* m_btCameraRotationAnticlockwise;
    wxStaticText* m_staticText3684;
    wxSlider* m_sliderCameraRotationSpeed;
    wxStaticLine* m_staticLine64453;
    wxStaticText* m_staticText6441;
    wxBitmapButton* m_btResetCameraPos1;
    wxSlider* m_sliderModelRotationX;
    wxButton* m_btModelRotationResetX;
    wxSlider* m_sliderModelRotationY;
    wxButton* m_btModelRotationResetY;
    wxSlider* m_sliderModelRotationZ;
    wxButton* m_btModelRotationResetZ;
    wxStaticLine* m_staticLine6445345;
    wxSlider* m_sliderModelRotationXYZ;
    wxButton* m_btModelRotationResetXYZ;
    wxStaticLine* m_staticLine644534;

protected:
    virtual void propertyChanged(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void propertyChanging(wxPropertyGridEvent& event) { event.Skip(); }
    virtual void resetCameraPostion(wxCommandEvent& event) { event.Skip(); }
    virtual void cameraRotationChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void autoCameraRotationClockwise(wxCommandEvent& event) { event.Skip(); }
    virtual void autoCameraRotationAnticlockwise(wxCommandEvent& event) { event.Skip(); }
    virtual void cameraRotationSpeedChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void resetModelPostion(wxCommandEvent& event) { event.Skip(); }
    virtual void modelRotationXChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void resetModelRotationX(wxCommandEvent& event) { event.Skip(); }
    virtual void modelRotationYChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void resetModelRotationY(wxCommandEvent& event) { event.Skip(); }
    virtual void modelRotationZChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void resetModelRotationZ(wxCommandEvent& event) { event.Skip(); }
    virtual void modelRotationXYZChanged(wxScrollEvent& event) { event.Skip(); }
    virtual void resetModelRotationXYZ(wxCommandEvent& event) { event.Skip(); }

public:
    wxPropertyGridManager* GetPgMgr3543() { return m_pgMgr3543; }
    wxCheckBox* GetCbAutoUpdate() { return m_cbAutoUpdate; }
    wxPanel* GetPanel3DOptions() { return m_panel3DOptions; }
    wxStaticText* GetStaticText6443() { return m_staticText6443; }
    wxBitmapButton* GetBtResetCameraPos2() { return m_btResetCameraPos2; }
    wxSlider* GetSliderCameraRotation() { return m_sliderCameraRotation; }
    wxBitmapToggleButton* GetBtCameraRotationClockwise() { return m_btCameraRotationClockwise; }
    wxBitmapToggleButton* GetBtCameraRotationAnticlockwise() { return m_btCameraRotationAnticlockwise; }
    wxStaticText* GetStaticText3684() { return m_staticText3684; }
    wxSlider* GetSliderCameraRotationSpeed() { return m_sliderCameraRotationSpeed; }
    wxStaticLine* GetStaticLine64453() { return m_staticLine64453; }
    wxStaticText* GetStaticText6441() { return m_staticText6441; }
    wxBitmapButton* GetBtResetCameraPos1() { return m_btResetCameraPos1; }
    wxSlider* GetSliderModelRotationX() { return m_sliderModelRotationX; }
    wxButton* GetBtModelRotationResetX() { return m_btModelRotationResetX; }
    wxSlider* GetSliderModelRotationY() { return m_sliderModelRotationY; }
    wxButton* GetBtModelRotationResetY() { return m_btModelRotationResetY; }
    wxSlider* GetSliderModelRotationZ() { return m_sliderModelRotationZ; }
    wxButton* GetBtModelRotationResetZ() { return m_btModelRotationResetZ; }
    wxStaticLine* GetStaticLine6445345() { return m_staticLine6445345; }
    wxSlider* GetSliderModelRotationXYZ() { return m_sliderModelRotationXYZ; }
    wxButton* GetBtModelRotationResetXYZ() { return m_btModelRotationResetXYZ; }
    wxStaticLine* GetStaticLine644534() { return m_staticLine644534; }
    wxScrolledWindow* GetScrollWin7039() { return m_scrollWin7039; }
    wxPanel* GetPanelAnimation() { return m_panelAnimation; }
    wxChoicebook* GetChoicebook6345() { return m_choicebook6345; }
    GL3DOptionPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1,-1), long style = wxTAB_TRAVERSAL);
    virtual ~GL3DOptionPaneBase();
};


class GL3DDrawPaneBase : public wxPanel
{
protected:
    wxPanel* m_rotatePaneZ3D;
    wxStaticText* m_staticText487556;
    wxPanel* m_rotatePaneY3D;
    wxStaticText* m_staticText48755;
    wxPanel* m_rotatePaneX3D;
    wxStaticText* m_staticText4875;
    wxPanel* m_drawPane3DPlaceHolder;
    wxPanel* m_scalePane3D;

protected:

public:
    wxPanel* GetRotatePaneZ3D() { return m_rotatePaneZ3D; }
    wxStaticText* GetStaticText487556() { return m_staticText487556; }
    wxPanel* GetRotatePaneY3D() { return m_rotatePaneY3D; }
    wxStaticText* GetStaticText48755() { return m_staticText48755; }
    wxPanel* GetRotatePaneX3D() { return m_rotatePaneX3D; }
    wxStaticText* GetStaticText4875() { return m_staticText4875; }
    wxPanel* GetDrawPane3DPlaceHolder() { return m_drawPane3DPlaceHolder; }
    wxPanel* GetScalePane3D() { return m_scalePane3D; }
    GL3DDrawPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(200,-1), long style = wxTAB_TRAVERSAL);
    virtual ~GL3DDrawPaneBase();
};

#endif
