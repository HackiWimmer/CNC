#include "ManuallyPathHandlerCnc.h"

/////////////////////////////////////////////////////////////
ManuallyPathHandlerCnc::ManuallyPathHandlerCnc(CncControl* cnc)
: PathHandlerBase()
, cncControl(cnc)
, lastSpeedMode(CncSpeedRapid)
, lastSpeedValue(0.0)
/////////////////////////////////////////////////////////////
{
	changeInputUnit(Unit::mm);
}
/////////////////////////////////////////////////////////////
ManuallyPathHandlerCnc::~ManuallyPathHandlerCnc() {
/////////////////////////////////////////////////////////////
}
//////////////////////////////////////////////////////////////////
void ManuallyPathHandlerCnc::logMeasurementStart() {
//////////////////////////////////////////////////////////////////
	wxASSERT(cncControl);
	cncControl->startSerialMeasurement();
}
//////////////////////////////////////////////////////////////////
void ManuallyPathHandlerCnc::logMeasurementEnd() {
//////////////////////////////////////////////////////////////////
	wxASSERT(cncControl);
	cncControl->stopSerialMeasurement();
}
//////////////////////////////////////////////////////////////////
bool ManuallyPathHandlerCnc::prepareWork() {
//////////////////////////////////////////////////////////////////
	wxASSERT( cncControl != NULL );
	cncControl->resetDurationCounter();
	return true;
}
//////////////////////////////////////////////////////////////////
bool ManuallyPathHandlerCnc::finishWork() {
//////////////////////////////////////////////////////////////////
	return true;
}
//////////////////////////////////////////////////////////////////
void ManuallyPathHandlerCnc::switchToolState(bool state) {
//////////////////////////////////////////////////////////////////
	#warning tool state
	state == true ? cncControl->switchToolOn() : cncControl->switchToolOff();
}
//////////////////////////////////////////////////////////////////
bool ManuallyPathHandlerCnc::processLinearMove(const MoveDefinition& md) {
//////////////////////////////////////////////////////////////////
	wxASSERT( cncControl != NULL );
	
	// tool handling
	switchToolState(md.toolState);
	
	// speed handling
	if ( md.speedMode != lastSpeedMode || md.f != lastSpeedValue ) {
		if ( cncControl->changeCurrentFeedSpeedXYZ_MM_MIN(md.f, md.speedMode) == false )
			return false;
	}
	
	// move
	if ( md.absoluteMove == true ) {
		currentPos.setX(md.x);
		currentPos.setY(md.y);
		currentPos.setZ(md.z);
	} else {
		currentPos.incX(md.x);
		currentPos.incY(md.y);
		currentPos.incZ(md.z);
	}
	
	bool ret = processLinearMove(false);
	if ( ret == false && md.correctLimit == true ) {
		ret = cncControl->correctLimitPositions();
	}
	
	switchToolState(false);
	
	return ret;
}
//////////////////////////////////////////////////////////////////
bool ManuallyPathHandlerCnc::processLinearMove(bool alreadyRendered) {
//////////////////////////////////////////////////////////////////
	return cncControl->moveAbsLinearMetricXYZ(currentPos.getX(), currentPos.getY(), currentPos.getZ(), alreadyRendered);
}