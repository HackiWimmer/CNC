#include <wx/propgrid/manager.h>
#include "wxCrafterImages.h"
#include "CncConfigCommon.h"
#include "CncConfig.h"
#include "MainFrameProxy.h"
#include "CncPreprocessor.h"
#include "CncConfigProperty.h"

extern wxPropertyGridManager* 	globlSetupGrid;

////////////////////////////////////////////////////////////////////////
void CncConfig::pgChangedWorkingCfgPage(wxPropertyGridEvent& event) {
////////////////////////////////////////////////////////////////////////
	wxPGProperty* p = event.GetProperty();
	if ( p == NULL )
		return;
		
	wxString name(p->GetName());
	
	if ( name == CncWork_Ctl_REPLY_THRESHOLD_METRIC ) {
		CncConfig::getGlobalCncConfig()->calculateThresholds();
		APP_PROXY::releaseControllerSetupFromConfig();
		
	} 
	else if ( name == CncWork_Wpt_MAX_THICKNESS_CROSS ) {
		CncConfig::getGlobalCncConfig()->initZAxisValues();
		APP_PROXY::changeCrossingThickness();
		
	}
	else if ( name == CncWork_Ctl_PRE_PROSSOR_ANALYSE ) {
		wxPGProperty* p = getProperty(CncWork_Ctl_PRE_PROSSOR_ANALYSE); 
		wxASSERT(p); 
		const bool analyse = p->GetValue().GetBool();
		
		p = getProperty(CncWork_Ctl_PRE_PROSSOR_SKIP_EMPTY); 
		wxASSERT(p); 
		p->Enable(analyse);
		
		p = getProperty(CncWork_Ctl_PRE_PROSSOR_COMBINE_MOVES); 
		wxASSERT(p); 
		p->Enable(analyse);
	}
	else if ( name == CncWork_Ctl_PRE_PROSSOR_USE_OPERATING_TRACE ) {
		APP_PROXY::getCncPreProcessor()->enableOperatingTrace	(THE_CONFIG->getPreProcessorUseOperatingTrace());
		CNC_PRINT_LOCATION
	}
	else if ( name == CncWork_Ctl_PRE_PROSSOR_CNT_PATH_LIST_ENTRIES ) {
		APP_PROXY::getCncPreProcessor()->enablePathListEntries(THE_CONFIG->getPreProcessorCntPathListEntries());
	}
	else if ( name == CncWork_Ctl_PRE_PROSSOR_CNT_SEQUENCE_MOVES ) {
		APP_PROXY::getCncPreProcessor()->enableMoveSequences	(THE_CONFIG->getPreProcessorCntMoveSequneces());
	}
}
////////////////////////////////////////////////////////////////////////
void CncConfig::pgChangingWorkingCfgPage(wxPropertyGridEvent& event) {
////////////////////////////////////////////////////////////////////////
	// Currently nothing todo
}
////////////////////////////////////////////////////////////////////////
void CncConfig::pgSelectedWorkingCfgPage(wxPropertyGridEvent& event) {
////////////////////////////////////////////////////////////////////////
	// Currently nothing todo
}
////////////////////////////////////////////////////////////////////////
void CncConfig::pgButtonWorkingCfgPage(wxCommandEvent& event) {
////////////////////////////////////////////////////////////////////////
	// Currently nothing todo
}
////////////////////////////////////////////////////////////////////////
void CncConfig::setupWorkingCfgPage(wxConfigBase& config) {
////////////////////////////////////////////////////////////////////////
	wxPropertyGridPage* page	= NULL;
	wxPGProperty* root 			= NULL;
	wxString curCatName;
	
	wxArrayString pgParameterMgrArr;
	wxArrayInt pgParameterMgrIntArr;
	wxFloatingPointValidator<double> validator(3, NULL, wxNUM_VAL_DEFAULT);
	
	//......................
	curCatName.assign("Working Settings");
	page = globlSetupGrid->AddPage(curCatName, ImageLibConfig().Bitmap(_("BMP_WORK_CFG")));
	root = page->Append( new wxPropertyCategory(curCatName));
	
	PGFuncPtrStore fps;
	fps.name.assign(curCatName);
	fps.propertyChanged 		= &CncConfig::pgChangedWorkingCfgPage;
	fps.propertyChanging		= &CncConfig::pgChangingWorkingCfgPage;
	fps.propertySelected		= &CncConfig::pgSelectedWorkingCfgPage;
	fps.propertyCommandButton	= &CncConfig::pgButtonWorkingCfgPage;
	CncConfig::registerPageRoot(root, fps);
	{
		wxPGProperty* prop = NULL;
		
		//...................
		wxPGProperty* ctl = NULL;
		curCatName.assign("Controller");
		ctl = root->AppendChild( new wxPropertyCategory(curCatName));
		registerCategory(curCatName, ctl);
		{
			//...............
			pgParameterMgrArr.Clear();
			pgParameterMgrIntArr.Clear();
			pgParameterMgrArr.Add(_("0.001")); 
			pgParameterMgrArr.Add(_("0.005")); 
			pgParameterMgrArr.Add(_("0.010")); 
			pgParameterMgrArr.Add(_("0.020")); 
			pgParameterMgrArr.Add(_("0.030")); 
			pgParameterMgrArr.Add(_("0.040")); 
			pgParameterMgrArr.Add(_("0.050")); 
			pgParameterMgrArr.Add(_("0.060")); 
			pgParameterMgrArr.Add(_("0.070")); 
			pgParameterMgrArr.Add(_("0.080")); 
			pgParameterMgrArr.Add(_("0.090")); 
			pgParameterMgrArr.Add(_("0.100")); 
			pgParameterMgrArr.Add(_("0.200"));
			pgParameterMgrArr.Add(_("0.300"));
			pgParameterMgrArr.Add(_("0.400"));
			pgParameterMgrArr.Add(_("0.500"));
			pgParameterMgrArr.Add(_("0.600"));
			pgParameterMgrArr.Add(_("0.700"));
			pgParameterMgrArr.Add(_("0.800"));
			pgParameterMgrArr.Add(_("0.900"));
			pgParameterMgrArr.Add(_("1.000"));
			pgParameterMgrArr.Add(_("2.000"));
			pgParameterMgrArr.Add(_("5.000"));

			prop = ctl->AppendChild( new wxEnumProperty("Position - Reply Threshold [mm]", NEXT_PROP_ID, pgParameterMgrArr, pgParameterMgrIntArr, 15));
			prop->Enable(true);
			prop->SetEditor( wxT("ComboBox") );
			CncConfig::registerProperty(CncWork_Ctl_REPLY_THRESHOLD_METRIC, prop);
			
			prop = ctl->AppendChild( new wxStringProperty(" --> Position - Reply Threshold [impulse]", NEXT_PROP_ID, ""));
			prop->Enable(false);
			prop->SetHelpString("");
			prop->SetEditor( wxT("TextCtrl") );
			prop->SetValue("");
			registerProperty(CncWork_Ctl_REPLY_THRESHOLD_SETPS, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Avoid sending of duplicate Setter values", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_AVOID_DUP_SETTER_VALUES, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Position out of range -> Interrupt", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_INTERRUPT_BY_POS_OUTOFRANGE, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Request idle requests", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_REQUEST_IDLE_REQUESTS, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Inverse direction X", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_INVERSE_CTL_DIRECTION_X, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Inverse direction Y", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_INVERSE_CTL_DIRECTION_Y, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Inverse direction Z", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_INVERSE_CTL_DIRECTION_Z, prop);
		}
		
		//...................
		ctl = NULL;
		curCatName.assign("Preprocessor");
		ctl = root->AppendChild( new wxPropertyCategory(curCatName));
		registerCategory(curCatName, ctl);
		{
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Analyse Pathes", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_ANALYSE, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Skip empty moves", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_SKIP_EMPTY, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Combine moves", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_COMBINE_MOVES, prop);
			
			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Display operating trace information by default", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_USE_OPERATING_TRACE, prop);

			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Connect List 'PathListEnties' by default", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_CNT_PATH_LIST_ENTRIES, prop);

			//...............
			prop = ctl->AppendChild( new wxBoolProperty("Connect List 'MoveSequences' by default", NEXT_PROP_ID, true));
			prop->Enable(true);
			prop->SetHelpString(_T(""));
			prop->SetEditor( wxT("CheckBox") );
			CncConfig::registerProperty(CncWork_Ctl_PRE_PROSSOR_CNT_SEQUENCE_MOVES, prop);
		}
	}
}
