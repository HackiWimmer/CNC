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
#include <wx/bmpbuttn.h>
#include <wx/tglbtn.h>
#include <wx/splitter.h>
#include <wx/listctrl.h>
#include <wx/simplebook.h>
#include <wx/checkbox.h>
#include <wx/choicebk.h>
#include <wx/propgrid/manager.h>
#include <wx/propgrid/property.h>
#include <wx/propgrid/advprops.h>
#include <wx/scrolwin.h>
#include <wx/slider.h>
#include "CncZView.h"
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
    wxPanel* m_panelParsingSynopsis;
    wxPanel* m_plParsingSynopsis;
    wxBitmapButton* m_bmpButton304911;
    wxStaticText* m_staticText61381422;
    wxBitmapToggleButton* m_btConnectOperatingTrace4;
    wxBitmapButton* m_btClearOperatingTrace105;
    wxBitmapButton* m_btClearOperatingTrace116;
    wxBitmapButton* m_btClearOperatingTrace7;
    wxStaticLine* m_staticLine275;
    wxPanel* m_motionSynopsisPlaceholder;
    wxPanel* m_panelOperatingTrace;
    wxPanel* m_plOperatingTrace;
    wxBitmapButton* m_bmpButton304910;
    wxStaticText* m_staticText6138142;
    wxBitmapToggleButton* m_btConnectOperatingTrace;
    wxBitmapButton* m_btClearOperatingTrace10;
    wxBitmapButton* m_btClearOperatingTrace11;
    wxBitmapButton* m_btClearOperatingTrace;
    wxStaticLine* m_staticLine249;
    wxPanel* m_operatingTracePlaceholder;
    wxPanel* m_panelPathListEntries;
    wxPanel* m_plPathListView;
    wxBitmapButton* m_bmpButton3049;
    wxStaticText* m_staticText61381;
    wxStaticText* m_staticText7891;
    wxTextCtrl* m_pathListRowCount;
    wxStaticLine* m_staticLine7903;
    wxBitmapToggleButton* m_btConnectPathListEntries;
    wxBitmapButton* m_btClearPathListEntries;
    wxStaticLine* m_staticLine285;
    wxBitmapButton* m_btPathListEntryFirst;
    wxBitmapButton* m_btPathListEntryPrev;
    wxBitmapButton* m_btPathListEntryNext;
    wxBitmapButton* m_btPathListEntryLast;
    wxStaticLine* m_staticLine219;
    wxSplitterWindow* m_pathListDetails;
    wxPanel* m_splitterPage387;
    wxListCtrl* m_pathListEntriesPlaceholder;
    wxPanel* m_splitterPage383;
    wxTextCtrl* m_textCtrl395;
    wxPanel* m_panelMoveSequences;
    wxPanel* m_plMoveSequences;
    wxBitmapButton* m_bmpButton304;
    wxStaticText* m_staticText613814;
    wxStaticText* m_staticText78912;
    wxTextCtrl* m_moveSequenceRowCount;
    wxStaticLine* m_staticLine7901;
    wxBitmapToggleButton* m_btConnectMoveSequences;
    wxBitmapButton* m_btClearMoveSequences;
    wxStaticLine* m_staticLine2854;
    wxBitmapButton* m_btMoveSeqFirst;
    wxBitmapButton* m_btMoveSeqPrev;
    wxBitmapButton* m_btMoveSeqNext;
    wxBitmapButton* m_btMoveSeqLast;
    wxStaticLine* m_staticLine188;
    wxSplitterWindow* m_splitter196;
    wxPanel* m_splitterPageOverview;
    wxStaticText* m_staticText186;
    wxStaticText* m_staticText225;
    wxListCtrl* m_moveSequencesListPlaceholder;
    wxPanel* m_splitterPageContent;
    wxStaticText* m_contentLabel;
    wxStaticText* m_staticText222;
    wxListCtrl* m_moveSequencesPlaceholder;
    wxTextCtrl* m_selectedClientIds;

protected:
    virtual void onDetachParsingSynopsisView(wxCommandEvent& event) { event.Skip(); }
    virtual void connectParsingSynopis(wxCommandEvent& event) { event.Skip(); }
    virtual void copyParsingSynopis(wxCommandEvent& event) { event.Skip(); }
    virtual void saveParsingSynopsis(wxCommandEvent& event) { event.Skip(); }
    virtual void clearParsingSynopis(wxCommandEvent& event) { event.Skip(); }
    virtual void onDetachOperatingTraceView(wxCommandEvent& event) { event.Skip(); }
    virtual void connectOperatingTrace(wxCommandEvent& event) { event.Skip(); }
    virtual void copyOperatingTrace(wxCommandEvent& event) { event.Skip(); }
    virtual void saveOperatingTrace(wxCommandEvent& event) { event.Skip(); }
    virtual void clearOperatingTrace(wxCommandEvent& event) { event.Skip(); }
    virtual void onDetachPathListEntriesView(wxCommandEvent& event) { event.Skip(); }
    virtual void connectPathListEntries(wxCommandEvent& event) { event.Skip(); }
    virtual void clearPathListEntries(wxCommandEvent& event) { event.Skip(); }
    virtual void onPathListEntryFirst(wxCommandEvent& event) { event.Skip(); }
    virtual void onPathListEntryPrev(wxCommandEvent& event) { event.Skip(); }
    virtual void onPathListEntryNext(wxCommandEvent& event) { event.Skip(); }
    virtual void onPathListEntryLast(wxCommandEvent& event) { event.Skip(); }
    virtual void onDetachMoveSequenceView(wxCommandEvent& event) { event.Skip(); }
    virtual void connectMoveSequences(wxCommandEvent& event) { event.Skip(); }
    virtual void clearMoveSequences(wxCommandEvent& event) { event.Skip(); }
    virtual void onMoveSequenceEntryFirst(wxCommandEvent& event) { event.Skip(); }
    virtual void onMoveSequenceEntryPrev(wxCommandEvent& event) { event.Skip(); }
    virtual void onMoveSequenceEntryNext(wxCommandEvent& event) { event.Skip(); }
    virtual void onMoveSequenceEntryLast(wxCommandEvent& event) { event.Skip(); }

public:
    wxBitmapButton* GetBmpButton304911() { return m_bmpButton304911; }
    wxStaticText* GetStaticText61381422() { return m_staticText61381422; }
    wxBitmapToggleButton* GetBtConnectOperatingTrace4() { return m_btConnectOperatingTrace4; }
    wxBitmapButton* GetBtClearOperatingTrace105() { return m_btClearOperatingTrace105; }
    wxBitmapButton* GetBtClearOperatingTrace116() { return m_btClearOperatingTrace116; }
    wxBitmapButton* GetBtClearOperatingTrace7() { return m_btClearOperatingTrace7; }
    wxStaticLine* GetStaticLine275() { return m_staticLine275; }
    wxPanel* GetMotionSynopsisPlaceholder() { return m_motionSynopsisPlaceholder; }
    wxPanel* GetPlParsingSynopsis() { return m_plParsingSynopsis; }
    wxPanel* GetPanelParsingSynopsis() { return m_panelParsingSynopsis; }
    wxBitmapButton* GetBmpButton304910() { return m_bmpButton304910; }
    wxStaticText* GetStaticText6138142() { return m_staticText6138142; }
    wxBitmapToggleButton* GetBtConnectOperatingTrace() { return m_btConnectOperatingTrace; }
    wxBitmapButton* GetBtClearOperatingTrace10() { return m_btClearOperatingTrace10; }
    wxBitmapButton* GetBtClearOperatingTrace11() { return m_btClearOperatingTrace11; }
    wxBitmapButton* GetBtClearOperatingTrace() { return m_btClearOperatingTrace; }
    wxStaticLine* GetStaticLine249() { return m_staticLine249; }
    wxPanel* GetOperatingTracePlaceholder() { return m_operatingTracePlaceholder; }
    wxPanel* GetPlOperatingTrace() { return m_plOperatingTrace; }
    wxPanel* GetPanelOperatingTrace() { return m_panelOperatingTrace; }
    wxBitmapButton* GetBmpButton3049() { return m_bmpButton3049; }
    wxStaticText* GetStaticText61381() { return m_staticText61381; }
    wxStaticText* GetStaticText7891() { return m_staticText7891; }
    wxTextCtrl* GetPathListRowCount() { return m_pathListRowCount; }
    wxStaticLine* GetStaticLine7903() { return m_staticLine7903; }
    wxBitmapToggleButton* GetBtConnectPathListEntries() { return m_btConnectPathListEntries; }
    wxBitmapButton* GetBtClearPathListEntries() { return m_btClearPathListEntries; }
    wxStaticLine* GetStaticLine285() { return m_staticLine285; }
    wxBitmapButton* GetBtPathListEntryFirst() { return m_btPathListEntryFirst; }
    wxBitmapButton* GetBtPathListEntryPrev() { return m_btPathListEntryPrev; }
    wxBitmapButton* GetBtPathListEntryNext() { return m_btPathListEntryNext; }
    wxBitmapButton* GetBtPathListEntryLast() { return m_btPathListEntryLast; }
    wxStaticLine* GetStaticLine219() { return m_staticLine219; }
    wxListCtrl* GetPathListEntriesPlaceholder() { return m_pathListEntriesPlaceholder; }
    wxPanel* GetSplitterPage387() { return m_splitterPage387; }
    wxTextCtrl* GetTextCtrl395() { return m_textCtrl395; }
    wxPanel* GetSplitterPage383() { return m_splitterPage383; }
    wxSplitterWindow* GetPathListDetails() { return m_pathListDetails; }
    wxPanel* GetPlPathListView() { return m_plPathListView; }
    wxPanel* GetPanelPathListEntries() { return m_panelPathListEntries; }
    wxBitmapButton* GetBmpButton304() { return m_bmpButton304; }
    wxStaticText* GetStaticText613814() { return m_staticText613814; }
    wxStaticText* GetStaticText78912() { return m_staticText78912; }
    wxTextCtrl* GetMoveSequenceRowCount() { return m_moveSequenceRowCount; }
    wxStaticLine* GetStaticLine7901() { return m_staticLine7901; }
    wxBitmapToggleButton* GetBtConnectMoveSequences() { return m_btConnectMoveSequences; }
    wxBitmapButton* GetBtClearMoveSequences() { return m_btClearMoveSequences; }
    wxStaticLine* GetStaticLine2854() { return m_staticLine2854; }
    wxBitmapButton* GetBtMoveSeqFirst() { return m_btMoveSeqFirst; }
    wxBitmapButton* GetBtMoveSeqPrev() { return m_btMoveSeqPrev; }
    wxBitmapButton* GetBtMoveSeqNext() { return m_btMoveSeqNext; }
    wxBitmapButton* GetBtMoveSeqLast() { return m_btMoveSeqLast; }
    wxStaticLine* GetStaticLine188() { return m_staticLine188; }
    wxStaticText* GetStaticText186() { return m_staticText186; }
    wxStaticText* GetStaticText225() { return m_staticText225; }
    wxListCtrl* GetMoveSequencesListPlaceholder() { return m_moveSequencesListPlaceholder; }
    wxPanel* GetSplitterPageOverview() { return m_splitterPageOverview; }
    wxStaticText* GetContentLabel() { return m_contentLabel; }
    wxStaticText* GetStaticText222() { return m_staticText222; }
    wxListCtrl* GetMoveSequencesPlaceholder() { return m_moveSequencesPlaceholder; }
    wxPanel* GetSplitterPageContent() { return m_splitterPageContent; }
    wxSplitterWindow* GetSplitter196() { return m_splitter196; }
    wxTextCtrl* GetSelectedClientIds() { return m_selectedClientIds; }
    wxPanel* GetPlMoveSequences() { return m_plMoveSequences; }
    wxPanel* GetPanelMoveSequences() { return m_panelMoveSequences; }
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
    wxPanel* m_parsingSynopsisListPlaceholder;

protected:

public:
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
    wxPGProperty* m_pgPropDrawGuidePathes;
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
    wxButton* m_btnOrigin;
    wxButton* m_btnGuidePathes;
    wxButton* m_btnRuler;
    wxButton* m_btnHelpLines;
    wxButton* m_btnPosMarker;
    wxButton* m_btnHardwareBox;
    wxButton* m_btnBoundBox;
    wxButton* m_btnFlyPath;
    wxStaticLine* m_staticLine372;
    wxBitmapToggleButton* m_btnMillingCutter;
    wxButton* m_btnRefresh;
    wxButton* m_btnClear;
    wxPanel* m_rotatePaneZ3D;
    wxStaticText* m_staticText487556;
    wxPanel* m_rotatePaneY3D;
    wxStaticText* m_staticText48755;
    wxPanel* m_rotatePaneX3D;
    wxStaticText* m_staticText4875;
    wxPanel* m_drawPanePanel;
    wxPanel* m_drawPane3DPlaceHolder;
    wxPanel* m_DrawPaneZView;
    CncZView* m_zView;
    wxStaticText* m_infoToolDiameter;
    wxPanel* m_scalePane3D;
    wxButton* m_optionDlg;
    wxStaticLine* m_staticLine32511;
    wxButton* m_3D_Reset;
    wxStaticLine* m_staticLine325112;
    wxButton* m_3D_Top;
    wxButton* m_3D_Bottom;
    wxButton* m_3D_Front;
    wxButton* m_3D_Rear;
    wxButton* m_3D_Left;
    wxButton* m_3D_Right;
    wxStaticLine* m_staticLine32512;
    wxButton* m_3D_Perspective1;
    wxButton* m_3D_Perspective2;
    wxButton* m_3D_Perspective3;
    wxButton* m_3D_Perspective4;
    wxStaticLine* m_staticLine325;

protected:
    virtual void onToggleOrigin(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleGuidePathes(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleRuler(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleHelpLines(wxCommandEvent& event) { event.Skip(); }
    virtual void onTogglePosMarker(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleHardwareBox(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleBoundBox(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleFlyPathes(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowMillingCutter(wxCommandEvent& event) { event.Skip(); }
    virtual void onRefreshMonitor(wxCommandEvent& event) { event.Skip(); }
    virtual void onClearMonitor(wxCommandEvent& event) { event.Skip(); }
    virtual void onToggleOptionPane(wxCommandEvent& event) { event.Skip(); }
    virtual void onResetView(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromTop(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromBottom(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromFront(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromRear(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromLeft(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromRight(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromPerspective1(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromPerspective2(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromPerspective3(wxCommandEvent& event) { event.Skip(); }
    virtual void onShowFromPerspective4(wxCommandEvent& event) { event.Skip(); }

public:
    wxButton* GetBtnOrigin() { return m_btnOrigin; }
    wxButton* GetBtnGuidePathes() { return m_btnGuidePathes; }
    wxButton* GetBtnRuler() { return m_btnRuler; }
    wxButton* GetBtnHelpLines() { return m_btnHelpLines; }
    wxButton* GetBtnPosMarker() { return m_btnPosMarker; }
    wxButton* GetBtnHardwareBox() { return m_btnHardwareBox; }
    wxButton* GetBtnBoundBox() { return m_btnBoundBox; }
    wxButton* GetBtnFlyPath() { return m_btnFlyPath; }
    wxStaticLine* GetStaticLine372() { return m_staticLine372; }
    wxBitmapToggleButton* GetBtnMillingCutter() { return m_btnMillingCutter; }
    wxButton* GetBtnRefresh() { return m_btnRefresh; }
    wxButton* GetBtnClear() { return m_btnClear; }
    wxPanel* GetRotatePaneZ3D() { return m_rotatePaneZ3D; }
    wxStaticText* GetStaticText487556() { return m_staticText487556; }
    wxPanel* GetRotatePaneY3D() { return m_rotatePaneY3D; }
    wxStaticText* GetStaticText48755() { return m_staticText48755; }
    wxPanel* GetRotatePaneX3D() { return m_rotatePaneX3D; }
    wxStaticText* GetStaticText4875() { return m_staticText4875; }
    wxPanel* GetDrawPane3DPlaceHolder() { return m_drawPane3DPlaceHolder; }
    CncZView* GetZView() { return m_zView; }
    wxStaticText* GetInfoToolDiameter() { return m_infoToolDiameter; }
    wxPanel* GetDrawPaneZView() { return m_DrawPaneZView; }
    wxPanel* GetDrawPanePanel() { return m_drawPanePanel; }
    wxPanel* GetScalePane3D() { return m_scalePane3D; }
    wxButton* GetOptionDlg() { return m_optionDlg; }
    wxStaticLine* GetStaticLine32511() { return m_staticLine32511; }
    wxButton* Get3D_Reset() { return m_3D_Reset; }
    wxStaticLine* GetStaticLine325112() { return m_staticLine325112; }
    wxButton* Get3D_Top() { return m_3D_Top; }
    wxButton* Get3D_Bottom() { return m_3D_Bottom; }
    wxButton* Get3D_Front() { return m_3D_Front; }
    wxButton* Get3D_Rear() { return m_3D_Rear; }
    wxButton* Get3D_Left() { return m_3D_Left; }
    wxButton* Get3D_Right() { return m_3D_Right; }
    wxStaticLine* GetStaticLine32512() { return m_staticLine32512; }
    wxButton* Get3D_Perspective1() { return m_3D_Perspective1; }
    wxButton* Get3D_Perspective2() { return m_3D_Perspective2; }
    wxButton* Get3D_Perspective3() { return m_3D_Perspective3; }
    wxButton* Get3D_Perspective4() { return m_3D_Perspective4; }
    wxStaticLine* GetStaticLine325() { return m_staticLine325; }
    GL3DDrawPaneBase(wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(200,-1), long style = wxTAB_TRAVERSAL);
    virtual ~GL3DDrawPaneBase();
};

#endif
