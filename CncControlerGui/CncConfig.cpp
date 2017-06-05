#include "CncConfig.h"

wxComboBox* CncConfig::gblCurveLibSelector = NULL;

////////////////////////////////////////////////////////////////////////
float CncConfig::getDefaultCurveLibResolution() {
////////////////////////////////////////////////////////////////////////
	return CncSvgCurveLib::getDefaultResolution();
}
////////////////////////////////////////////////////////////////////////
float CncConfig::getCurveLibResolution() { 
////////////////////////////////////////////////////////////////////////
	return CncSvgCurveLib::getResolution(); 
}
////////////////////////////////////////////////////////////////////////
void CncConfig::setCurveLibResolution(double v) { 
////////////////////////////////////////////////////////////////////////
	CncSvgCurveLib::setResolution((float)v); 
	updateCurveLibResolutionSelector();
}
////////////////////////////////////////////////////////////////////////
void CncConfig::updateCurveLibResolutionSelector() { 
////////////////////////////////////////////////////////////////////////
	if ( CncConfig::gblCurveLibSelector != NULL ) {
		wxString label(wxString::Format("%.3f", CncSvgCurveLib::getResolution()));
		CncConfig::gblCurveLibSelector->SetStringSelection(label);
	}
}