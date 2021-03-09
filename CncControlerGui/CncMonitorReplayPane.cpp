#include "wxCrafterMotionMonitor.h"
#include "CncMotionMonitor.h"
#include "CncConfig.h"
#include "MainFrameProxy.h"
#include "CncMonitorReplayPane.h"

bool CncMonitorReplayPane::Processing::running = false;

///////////////////////////////////////////////////////////////////
CncMonitorReplayPane::Decorate::Decorate(CncMonitorReplayPane* p) 
: pane(p)
///////////////////////////////////////////////////////////////////
{
	APP_PROXY::enableControls(false);
	APP_PROXY::enableBtnEmergenyStop(false);
	APP_PROXY::enableBtnRcPause(false);
	APP_PROXY::enableBtnRcStop(false);
}
///////////////////////////////////////////////////////////////////
CncMonitorReplayPane::Decorate::~Decorate() {
///////////////////////////////////////////////////////////////////
	pane->GetReplayStart()->Enable(true);
	pane->GetReplayPrev()->Enable(true);
	pane->GetReplayNext()->Enable(true);
	pane->GetReplayEnd()->Enable(true);
	pane->GetReplayPlayAll()->Enable(true);
	pane->GetReplayPlayCurrentId()->Enable(pane->GetCbStepUnit()->GetSelection() != Unit_Id);
	pane->GetReplayPause()->Enable(true);
	pane->GetReplayStop()->Enable(true);

	APP_PROXY::enableControls(true);
}


///////////////////////////////////////////////////////////////////
CncMonitorReplayPane::CncMonitorReplayPane(wxWindow* parent)
: CncMonitorReplayPaneBase(parent)
, abort				(false)
, processing		(false)
, motionMonitor		(NULL)
///////////////////////////////////////////////////////////////////
{
	m_cbStepUnit->SetSelection(Unit_Id);
	m_replayPlayCurrentId->Enable(false);
}
///////////////////////////////////////////////////////////////////
CncMonitorReplayPane::~CncMonitorReplayPane() {
///////////////////////////////////////////////////////////////////
	abort = true;
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::enable(bool state) {
///////////////////////////////////////////////////////////////////
	GetReplayStart()->Enable(state);
	GetReplayPrev()->Enable(state);
	GetReplayNext()->Enable(state);
	GetReplayEnd()->Enable(state);
	GetReplayPlayAll()->Enable(state);
	GetReplayPlayCurrentId()->Enable(state);
	GetReplayPause()->Enable(state);
	GetReplayStop()->Enable(state);
	GetCbStepUnit()->Enable(state);
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::updateControls() {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return;
	
	GetCurrentVertexId()->ChangeValue(wxString::Format("%ld", motionMonitor->getVirtualEndAsNormalizedId()));
	GetCurrentVertex()->ChangeValue(wxString::Format("%ld", motionMonitor->getVirtualEnd()));
	GetTotalVerties()->ChangeValue(wxString::Format("%ld", motionMonitor->getPathItemCount()));
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::notifyCncPathChanged() {
///////////////////////////////////////////////////////////////////
	if ( APP_PROXY::isProcessing() == true )
		return;
	
	updateControls();
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::setMotionMonitor(CncMotionMonitor* mm) {
///////////////////////////////////////////////////////////////////
	motionMonitor = mm;
	wxASSERT(motionMonitor != NULL);
	
	motionMonitor->registerMonitorCallback(this);
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::display() {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return;
		
	motionMonitor->normalizeAllSelectionEffects();
	motionMonitor->update(true);
	
	APP_PROXY::tryToSelectClientId(motionMonitor->getVirtualEndAsNormalizedId(), ClientIdSelSource::ID::TSS_REPLAY);
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayPlay(bool stopByIdChange) {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return;
	
	// decorate
	Processing p(this);
	DecoratePlay dp(this);
	
	abort = false;
	
	// define start position
	long start = motionMonitor->getVirtualEnd();
	if ( start >= motionMonitor->getPathItemCount() - 1 )
		start = 0;
	
	motionMonitor->setVirtualEnd(start);
	
	// define start id
	long id = motionMonitor->getVirtualEndAsNormalizedId();
	if ( id != motionMonitor->previewNextVertexNormalizedId() )
		id = motionMonitor->previewNextVertexNormalizedId();
	
	// spool
	while ( motionMonitor->getVirtualEnd() < motionMonitor->getPathItemCount() - 1 ) {
		
		const bool fine = GetCbStepUnit()->GetSelection() != Unit_Id;
		
		if ( fine ) {
			// is slow enough
			motionMonitor->incVirtualEnd();
		}
		else {
			motionMonitor->incVirtualEndById();
			// slow down this mode a little bit
			Sleep(600);
		}
		
		display();
		
		// to keep the app online
		APP_PROXY::dispatchAll();
		
		if ( stopByIdChange == true )
			if ( id != motionMonitor->previewNextVertexNormalizedId() )
				break;
		
		if ( abort == true )
			break;
	}
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayPlayAll(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	replayPlay(false);
	motionMonitor->setVirtualEndToLast();
	display();
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayPlayCurrentId(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	replayPlay(true);
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayPause(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	abort = true; 
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayStop(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	abort = true;
	 
	if ( motionMonitor == NULL )
		return;
		
	if ( m_cbStepUnit->GetSelection() == Unit_Id ) 
		motionMonitor->setVirtualEndToLast();
		
	display();
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayStart(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return;
	
	motionMonitor->setVirtualEndToFirst();
	display();
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayLeftDownPrev(wxMouseEvent& event) {
///////////////////////////////////////////////////////////////////
	if ( Processing::isRunning() == true )
		return;
	
	Processing p(this);
	DecoratePrev dp(this);
	
	abort = false;
	int count = 0;
	while( decrement(GetCbStepUnit()->GetSelection() != Unit_Id) ) {
		
		if      ( count < 1 ) { count++;	wxThread::This()->Sleep(350); }
		else if ( count < 2 ) { count++;	wxThread::This()->Sleep(150); }
		else if ( count < 3 ) { count++;	wxThread::This()->Sleep( 50); }
		
		APP_PROXY::dispatchAll();
	}
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayLeftDownNext(wxMouseEvent& event) {
///////////////////////////////////////////////////////////////////
	if ( Processing::isRunning() == true )
		return;
	
	Processing p(this);
	DecorateNext dn(this);
	
	abort = false;
	int count = 0;
	while( increment(GetCbStepUnit()->GetSelection() != Unit_Id) ) {
		
		if      ( count < 1 ) { count++;	wxThread::This()->Sleep(350); }
		else if ( count < 2 ) { count++;	wxThread::This()->Sleep(150); }
		else if ( count < 3 ) { count++;	wxThread::This()->Sleep( 50); }
		
		APP_PROXY::dispatchAll();
	}
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::replayEnd(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return;
	
	if ( motionMonitor->getPathItemCount() <= 0 )
		return;
		
	motionMonitor->setVirtualEndToLast();
	display();
}

///////////////////////////////////////////////////////////////////
bool CncMonitorReplayPane::increment(bool fine) {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return false;
	
	if ( abort == true )
		return false;
	
	const long idx = motionMonitor->getVirtualEnd();
	if ( idx <= 0 )
		return false;
		
	if ( idx >= motionMonitor->getPathItemCount() )
		motionMonitor->setVirtualEnd(1);
		
	// increment
	if ( fine == true )	motionMonitor->incVirtualEnd();
	else				motionMonitor->incVirtualEndById();
	
	display();
	
	return true;
}
///////////////////////////////////////////////////////////////////
bool CncMonitorReplayPane::decrement(bool fine) {
///////////////////////////////////////////////////////////////////
	if ( motionMonitor == NULL )
		return false;
	
	if ( abort == true )
		return false;
		
	const long idx = motionMonitor->getVirtualEnd();
	
	if ( idx <= 1 )
		return false;
	
	// decrement
	if ( fine == true )		motionMonitor->decVirtualEnd();
	else					motionMonitor->decVirtualEndById();
	
	display();
	
	return true;
}
///////////////////////////////////////////////////////////////////
void CncMonitorReplayPane::selectReplayUnit(wxCommandEvent& event) {
///////////////////////////////////////////////////////////////////
	m_replayPlayCurrentId->Enable(m_cbStepUnit->GetSelection() != Unit_Id);
}
