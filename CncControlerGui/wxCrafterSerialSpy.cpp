//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: wxCrafterSerialSpy.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "wxCrafterSerialSpy.h"


// Declare the bitmap loading function
extern void wxC9ED9XInitBitmapResources();

static bool bBitmapLoaded = false;


CncSerialSpyPanelBase::CncSerialSpyPanelBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9XInitBitmapResources();
        bBitmapLoaded = true;
    }
    this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    
    wxFlexGridSizer* flexGridSizer27261 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer27261->SetFlexibleDirection( wxBOTH );
    flexGridSizer27261->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer27261->AddGrowableCol(0);
    flexGridSizer27261->AddGrowableRow(1);
    this->SetSizer(flexGridSizer27261);
    
    m_panel9492 = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_panel9492->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    
    flexGridSizer27261->Add(m_panel9492, 0, wxALL|wxEXPAND, WXC_FROM_DIP(0));
    
    wxFlexGridSizer* flexGridSizer27302 = new wxFlexGridSizer(1, 9, 0, 0);
    flexGridSizer27302->SetFlexibleDirection( wxBOTH );
    flexGridSizer27302->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer27302->AddGrowableCol(5);
    flexGridSizer27302->AddGrowableRow(0);
    m_panel9492->SetSizer(flexGridSizer27302);
    
    m_enableSerialSpy = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("16-connected")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_enableSerialSpy->SetToolTip(_("Enable Serial Spy"));
    m_enableSerialSpy->SetValue(false);
    
    flexGridSizer27302->Add(m_enableSerialSpy, 0, wxALL, WXC_FROM_DIP(0));
    m_enableSerialSpy->SetMinSize(wxSize(26,26));
    
    m_MarkSerialSpy = new wxButton(m_panel9492, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    #if wxVERSION_NUMBER >= 2904
    m_MarkSerialSpy->SetBitmap(wxXmlResource::Get()->LoadBitmap(wxT("book-add")), wxLEFT);
    m_MarkSerialSpy->SetBitmapMargins(2,2);
    #endif
    m_MarkSerialSpy->SetToolTip(_("Add a Marker"));
    
    flexGridSizer27302->Add(m_MarkSerialSpy, 0, wxALL, WXC_FROM_DIP(0));
    m_MarkSerialSpy->SetMinSize(wxSize(26,26));
    
    m_staticLine9487 = new wxStaticLine(m_panel9492, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(-1,-1)), wxLI_VERTICAL);
    
    flexGridSizer27302->Add(m_staticLine9487, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    m_clearSerialSpy = new wxButton(m_panel9492, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    #if wxVERSION_NUMBER >= 2904
    m_clearSerialSpy->SetBitmap(wxXmlResource::Get()->LoadBitmap(wxT("16-clean")), wxLEFT);
    m_clearSerialSpy->SetBitmapMargins(2,2);
    #endif
    m_clearSerialSpy->SetToolTip(_("Clear the Spy Trace"));
    
    flexGridSizer27302->Add(m_clearSerialSpy, 0, wxALL, WXC_FROM_DIP(0));
    m_clearSerialSpy->SetMinSize(wxSize(26,26));
    
    m_staticLine94873 = new wxStaticLine(m_panel9492, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(-1,-1)), wxLI_VERTICAL);
    
    flexGridSizer27302->Add(m_staticLine94873, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    wxArrayString m_cbSerialSpyModeArr;
    m_cbSerialSpyModeArr.Add(wxT("Spy - In"));
    m_cbSerialSpyModeArr.Add(wxT("Spy - Out"));
    m_cbSerialSpyModeArr.Add(wxT("Spy - In/Out"));
    m_cbSerialSpyMode = new wxComboBox(m_panel9492, wxID_ANY, wxT(""), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(-1,-1)), m_cbSerialSpyModeArr, wxCB_READONLY);
    wxFont m_cbSerialSpyModeFont(8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Segoe UI"));
    m_cbSerialSpyMode->SetFont(m_cbSerialSpyModeFont);
    m_cbSerialSpyMode->SetSelection(2);
    
    flexGridSizer27302->Add(m_cbSerialSpyMode, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    m_staticLine9489 = new wxStaticLine(m_panel9492, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(-1,-1)), wxLI_VERTICAL);
    
    flexGridSizer27302->Add(m_staticLine9489, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    wxFlexGridSizer* flexGridSizer4706 = new wxFlexGridSizer(1, 8, 0, 0);
    flexGridSizer4706->SetFlexibleDirection( wxBOTH );
    flexGridSizer4706->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    
    flexGridSizer27302->Add(flexGridSizer4706, 1, wxALL|wxEXPAND|wxALIGN_RIGHT, WXC_FROM_DIP(0));
    
    m_liveDecoding = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("brick-edit")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_liveDecoding->SetToolTip(_("Live Decoding"));
    m_liveDecoding->SetValue(true);
    
    flexGridSizer4706->Add(m_liveDecoding, 0, wxALL, WXC_FROM_DIP(0));
    m_liveDecoding->SetMinSize(wxSize(26,26));
    
    m_liveDebug = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("bug-error")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_liveDebug->SetToolTip(_("Further consider Debug Entries"));
    m_liveDebug->SetValue(false);
    
    flexGridSizer4706->Add(m_liveDebug, 0, wxALL, WXC_FROM_DIP(0));
    m_liveDebug->SetMinSize(wxSize(26,26));
    
    m_autoScroling = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("auto-scroll")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_autoScroling->SetToolTip(_("Auto Scrolling"));
    m_autoScroling->SetValue(true);
    
    flexGridSizer4706->Add(m_autoScroling, 0, wxALL, WXC_FROM_DIP(0));
    m_autoScroling->SetMinSize(wxSize(26,26));
    
    m_autoColumnSizing = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("format-table-column-width")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_autoColumnSizing->SetToolTip(_("Auto Column Sizing"));
    m_autoColumnSizing->SetValue(true);
    
    flexGridSizer4706->Add(m_autoColumnSizing, 0, wxALL, WXC_FROM_DIP(0));
    m_autoColumnSizing->SetMinSize(wxSize(26,26));
    
    m_clearSerialSpyOnConnect = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("brick-delete")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_clearSerialSpyOnConnect->SetToolTip(_("Clear on Connect"));
    m_clearSerialSpyOnConnect->SetValue(true);
    
    flexGridSizer4706->Add(m_clearSerialSpyOnConnect, 0, wxALL, WXC_FROM_DIP(0));
    m_clearSerialSpyOnConnect->SetMinSize(wxSize(26,26));
    
    m_clearSerialSpyBeforNextRun = new wxBitmapToggleButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("script-delete")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), 0);
    m_clearSerialSpyBeforNextRun->SetToolTip(_("Clear before next Run"));
    m_clearSerialSpyBeforNextRun->SetValue(false);
    
    flexGridSizer4706->Add(m_clearSerialSpyBeforNextRun, 0, wxALL, WXC_FROM_DIP(0));
    m_clearSerialSpyBeforNextRun->SetMinSize(wxSize(26,26));
    
    m_staticLine9495 = new wxStaticLine(m_panel9492, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(-1,-1)), wxLI_VERTICAL);
    
    flexGridSizer4706->Add(m_staticLine9495, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    m_openDetails = new wxBitmapButton(m_panel9492, wxID_ANY, wxXmlResource::Get()->LoadBitmap(wxT("document-open-6")), wxDefaultPosition, wxDLG_UNIT(m_panel9492, wxSize(26,26)), wxBU_AUTODRAW);
    m_openDetails->SetToolTip(_("Open Details"));
    
    flexGridSizer4706->Add(m_openDetails, 0, wxALL, WXC_FROM_DIP(1));
    m_openDetails->SetMinSize(wxSize(26,26));
    
    wxFlexGridSizer* flexGridSizer9518 = new wxFlexGridSizer(3, 1, 0, 0);
    flexGridSizer9518->SetFlexibleDirection( wxBOTH );
    flexGridSizer9518->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer9518->AddGrowableCol(0);
    flexGridSizer9518->AddGrowableRow(0);
    
    flexGridSizer27261->Add(flexGridSizer9518, 0, wxALL|wxEXPAND, WXC_FROM_DIP(0));
    
    wxFlexGridSizer* flexGridSizer9514 = new wxFlexGridSizer(2, 1, 0, 0);
    flexGridSizer9514->SetFlexibleDirection( wxBOTH );
    flexGridSizer9514->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer9514->AddGrowableCol(0);
    flexGridSizer9514->AddGrowableRow(0);
    
    flexGridSizer9518->Add(flexGridSizer9514, 0, wxALL|wxEXPAND, WXC_FROM_DIP(0));
    
    m_serialSpyPlaceholder = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxTAB_TRAVERSAL);
    m_serialSpyPlaceholder->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
    
    flexGridSizer9514->Add(m_serialSpyPlaceholder, 0, wxALL|wxEXPAND, WXC_FROM_DIP(0));
    
    m_infobar = new wxInfoBar(this, wxID_ANY);
    m_infobar->SetSize(wxDLG_UNIT(this, wxSize(-1,-1)));
    
    flexGridSizer9514->Add(m_infobar, 0, wxALL|wxEXPAND, WXC_FROM_DIP(4));
    
    m_staticLine9537 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxLI_HORIZONTAL);
    
    flexGridSizer9518->Add(m_staticLine9537, 0, wxALL|wxEXPAND, WXC_FROM_DIP(1));
    
    wxFlexGridSizer* flexGridSizer9520 = new wxFlexGridSizer(1, 4, 0, 0);
    flexGridSizer9520->SetFlexibleDirection( wxBOTH );
    flexGridSizer9520->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer9520->AddGrowableCol(2);
    flexGridSizer9520->AddGrowableRow(0);
    
    flexGridSizer9518->Add(flexGridSizer9520, 1, wxALL|wxEXPAND, WXC_FROM_DIP(5));
    
    flexGridSizer9520->Add(3, 0, 1, wxALL, WXC_FROM_DIP(0));
    
    m_staticText9524 = new wxStaticText(this, wxID_ANY, _("Update Interval:"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_staticText9524->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    wxFont m_staticText9524Font(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Segoe UI"));
    m_staticText9524->SetFont(m_staticText9524Font);
    
    flexGridSizer9520->Add(m_staticText9524, 0, wxALL, WXC_FROM_DIP(3));
    
    m_sliderUpdateInterval = new wxSlider(this, wxID_ANY, 800, 100, 1000, wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), wxSL_HORIZONTAL);
    m_sliderUpdateInterval->SetToolTip(_("Update Interval"));
    
    flexGridSizer9520->Add(m_sliderUpdateInterval, 0, wxALL|wxEXPAND, WXC_FROM_DIP(0));
    
    m_staticText9539 = new wxStaticText(this, wxID_ANY, _("[ms]"), wxDefaultPosition, wxDLG_UNIT(this, wxSize(-1,-1)), 0);
    m_staticText9539->SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_3DLIGHT));
    wxFont m_staticText9539Font(9, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Segoe UI"));
    m_staticText9539->SetFont(m_staticText9539Font);
    
    flexGridSizer9520->Add(m_staticText9539, 0, wxALL, WXC_FROM_DIP(3));
    
    SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_BTNTEXT));
    SetName(wxT("CncSerialSpyPanelBase"));
    SetSize(wxDLG_UNIT(this, wxSize(500,300)));
    if (GetSizer()) {
         GetSizer()->Fit(this);
    }
    // Connect events
    m_enableSerialSpy->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::enableSerialSpy), NULL, this);
    m_MarkSerialSpy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::markSerialSpy), NULL, this);
    m_clearSerialSpy->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::clearSerialSpy), NULL, this);
    m_cbSerialSpyMode->Connect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(CncSerialSpyPanelBase::selectSerialSpyMode), NULL, this);
    m_liveDecoding->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onLiveDecoding), NULL, this);
    m_liveDebug->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onLiveDebug), NULL, this);
    m_autoScroling->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onAutoScrolling), NULL, this);
    m_autoColumnSizing->Connect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onAutoColumnSize), NULL, this);
    m_openDetails->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::openSpyDetailWindow), NULL, this);
    m_sliderUpdateInterval->Connect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    m_sliderUpdateInterval->Connect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    m_sliderUpdateInterval->Connect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    
}

CncSerialSpyPanelBase::~CncSerialSpyPanelBase()
{
    m_enableSerialSpy->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::enableSerialSpy), NULL, this);
    m_MarkSerialSpy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::markSerialSpy), NULL, this);
    m_clearSerialSpy->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::clearSerialSpy), NULL, this);
    m_cbSerialSpyMode->Disconnect(wxEVT_COMMAND_COMBOBOX_SELECTED, wxCommandEventHandler(CncSerialSpyPanelBase::selectSerialSpyMode), NULL, this);
    m_liveDecoding->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onLiveDecoding), NULL, this);
    m_liveDebug->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onLiveDebug), NULL, this);
    m_autoScroling->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onAutoScrolling), NULL, this);
    m_autoColumnSizing->Disconnect(wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::onAutoColumnSize), NULL, this);
    m_openDetails->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(CncSerialSpyPanelBase::openSpyDetailWindow), NULL, this);
    m_sliderUpdateInterval->Disconnect(wxEVT_SCROLL_THUMBTRACK, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    m_sliderUpdateInterval->Disconnect(wxEVT_SCROLL_THUMBRELEASE, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    m_sliderUpdateInterval->Disconnect(wxEVT_SCROLL_CHANGED, wxScrollEventHandler(CncSerialSpyPanelBase::onUpdateIntervalSlider), NULL, this);
    
}

ImageLibSpy::ImageLibSpy()
    : wxImageList(16, 16, true)
    , m_imagesWidth(16)
    , m_imagesHeight(16)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxC9ED9XInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_IN"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_IN"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_IN@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_IN@2x"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_OUT"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_OUT"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_OUT@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_OUT@2x"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_RET_OK"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_RET_OK"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_RET_WARNING"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_RET_WARNING"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_RET_ERROR"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_RET_ERROR"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_MARKER"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_MARKER"), bmp));
        }
    }
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_MARKER@2x"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_MARKER@2x"), bmp));
        }
    }
    
    {
        wxBitmap bmp;
        wxIcon icn;
        bmp = wxXmlResource::Get()->LoadBitmap(wxT("BMP_DEBUG"));
        if(bmp.IsOk()) {
            if((m_imagesWidth == bmp.GetWidth()) && (m_imagesHeight == bmp.GetHeight())){
                icn.CopyFromBitmap(bmp);
                this->Add(icn);
            }
            m_bitmaps.insert(std::make_pair(wxT("BMP_DEBUG"), bmp));
        }
    }
    
}

ImageLibSpy::~ImageLibSpy()
{
}