#include <wx/dcclient.h>

#include "3D/GLContextCncPath.h"
#include "3D/GLContextTestCube.h"
#include "3D/GLOpenGLPathBufferStore.h"
#include "CncMotionVertexTrace.h"
#include "GL3DDrawPane.h"
#include "CncConfig.h"
#include "CncCommon.h"
#include "MainFrame.h"
#include "GlobalStrings.h"
#include "CncMotionMonitor.h"

#include "3D/GLInclude.h"

extern GlobalConstStringDatabase 	globalStrings;

// ----------------------------------------------------------------------------
// GlutInitManager
// ----------------------------------------------------------------------------
class GlutLibInitManager {
	public:
		//////////////////////////////////////////////////////
		GlutLibInitManager() {
			
			// init glut lib a the startup
			int   argc = 2;
			char* argv[2] = { globalStrings.programTitel.char_str(), wxString("-gldebug").char_str() };
			glutInit(&argc, argv);
			/*
			glutInitDisplayMode (GL_DOUBLE | GLUT_DEPTH | GLUT_RGB);
			 */
		}
		//////////////////////////////////////////////////////
		~GlutLibInitManager() {
		}
		
}; GlutLibInitManager _glim;

// ----------------------------------------------------------------------------
// CncMotionMonitor Event Table
// ----------------------------------------------------------------------------
wxDEFINE_EVENT(wxEVT_MONTION_MONITOR_TIMER, wxTimerEvent);

wxBEGIN_EVENT_TABLE(CncMotionMonitor, wxGLCanvas)
	EVT_PAINT(CncMotionMonitor::onPaint)
	EVT_SIZE(CncMotionMonitor::onSize)
	EVT_ERASE_BACKGROUND(CncMotionMonitor::onEraseBackground)
	EVT_MOUSE_EVENTS(CncMotionMonitor::onMouse)
	EVT_KEY_DOWN(CncMotionMonitor::onKeyDown)
	EVT_LEAVE_WINDOW(CncMotionMonitor::onLeave)
	EVT_TIMER(wxEVT_MONTION_MONITOR_TIMER, CncMotionMonitor::onCameraRotationTimer)
wxEND_EVENT_TABLE()

//////////////////////////////////////////////////
CncMotionMonitor::CncMotionMonitor(wxWindow *parent, int *attribList) 
: CncGlCanvas(parent, attribList)
, monitor(new GLContextCncPath(this))
, testCube(new GLContextTestCube(this))
, cameraRotationTimer(this, wxEVT_MONTION_MONITOR_TIMER)
, cameraRotationStepWidth(0)
, cameraRotationSpeed(100)
, isShown(false)
, zoom(2.0f)
, currentClientID(-1L)
{
//////////////////////////////////////////////////
	GLContextBase::globalInit(); 
	monitor->init();
	testCube->init();
	
	// Important: initialize the CncGlCanvas context
	context = monitor;
	
	// publish initial zoom factor
	monitor->setZoomFactor(zoom);
	monitor->registerCallback(this);
	
	// deactivate process mode by default
	popProcessMode();
	
	createRuler();
}
//////////////////////////////////////////////////
CncMotionMonitor::~CncMotionMonitor() {
//////////////////////////////////////////////////
	if ( monitor != NULL ) 
		delete monitor;
	
	if ( testCube != NULL ) 
		delete testCube;
}
//////////////////////////////////////////////////
void CncMotionMonitor::notifyCncPathChanged() {
//////////////////////////////////////////////////
	// currently nothing to do
	// std::clog << "CncMotionMonitor::notifyCncPathChanged()" << std::endl;
}
//////////////////////////////////////////////////
unsigned int CncMotionMonitor::calculateScaleDisplay(unsigned int height) {
//////////////////////////////////////////////////
	float fact = ( monitor->getCurrentScaleFactor() * 1000 ) / ( monitor->getMaxScaleFactor() * 1000 );
	//std::cerr <<  monitor->getCurrentScaleFactor() << ", " <<  monitor->getMaxScaleFactor() << ", " << fact << std::endl;
	return (unsigned int)(fact * height);
}
//////////////////////////////////////////////////
void CncMotionMonitor::initVertexListCtr() {
//////////////////////////////////////////////////
	wxASSERT(THE_APP->getMotionVertexTrace());
	THE_APP->getMotionVertexTrace()->getVertexDataList()->setVertexBufferStore(monitor->getVertexBufferStore());
	THE_APP->getMotionVertexTrace()->getVertexIndexList()->setVertexBufferStore(monitor->getVertexBufferStore());
}
//////////////////////////////////////////////////
void CncMotionMonitor::enable(bool state) {
//////////////////////////////////////////////////
	monitor->enable(state);
}
//////////////////////////////////////////////////
void CncMotionMonitor::decorateProbeMode(bool state) {
//////////////////////////////////////////////////
	monitor->decorateProbeMode(state);
}
//////////////////////////////////////////////////
void CncMotionMonitor::clear() {
//////////////////////////////////////////////////
	monitor->clearPathData();
	display();
}
//////////////////////////////////////////////////
void CncMotionMonitor::createRuler() {
//////////////////////////////////////////////////
	CncMetricRulerSetup mrs;
	
	const double dimX = GBL_CONFIG->getMaxDimensionX();
	const double dimY = GBL_CONFIG->getMaxDimensionY();
	const double dimZ = GBL_CONFIG->getMaxDimensionZ();
	
	mrs.setupSize(dimX, dimY, dimZ);
	
	mrs.createHelpLinesXY(monitor->getXYPlane().helpLinesX, monitor->getXYPlane().helpLinesY);
	mrs.createHelpLinesXZ(monitor->getXZPlane().helpLinesX, monitor->getXZPlane().helpLinesZ);
	mrs.createHelpLinesYZ(monitor->getYZPlane().helpLinesY, monitor->getYZPlane().helpLinesZ);
	
	mrs.createRulerX(monitor->getRulerX());
	mrs.createRulerY(monitor->getRulerY());
	mrs.createRulerZ(monitor->getRulerZ());
	
	mrs.check(monitor, std::cerr);
	
	//#warning
	//mrs.trace(monitor, std::cout);
}
//////////////////////////////////////////////////
void CncMotionMonitor::setModelType(const GLContextBase::ModelType mt) {
//////////////////////////////////////////////////
	monitor->setModelType(mt);
	monitor->setViewMode(GLContextBase::ViewMode::V3D_ISO1, true);
	monitor->reshapeViewMode();
}
//////////////////////////////////////////////////
void CncMotionMonitor::reconstruct() {
//////////////////////////////////////////////////
	display();
	
#warning reimpl. CncMotionMonitor::reconstruct
/*
	GLI::GLCncPath tmpPath, curPath = monitor->getPathData();
	// copy the current path
	tmpPath.swap(curPath);
	// clear the real monitor path data - keep in mind curPath is only a local copy
	monitor->clearPathData();
	
	pushProcessMode();
	
		// reconstruct
		GLI::GLCncPathVertices d;
		for ( GLI::GLCncPath::iterator it = tmpPath.begin(); it != tmpPath.end(); ++it )
			appendVertice(it->getId(), it->getX(), it->getY(), it->getZ(), it->getCncMode());
		
		// redraw the scene with new properties
		display();
	
	popProcessMode();
	 */ 
}
//////////////////////////////////////////////////
void CncMotionMonitor::display() {
//////////////////////////////////////////////////
	onPaint();
}
//////////////////////////////////////////////////
void CncMotionMonitor::appendVertex(const GLI::VerticeLongData& vd) {
//////////////////////////////////////////////////
	// Convert the given steps (abs) to a glpos (rel):
	
	// To do this first we need to normalize the values for x, y and z 
	// to a common unit like [mm], because [steps] are depends on 
	// the corresponding pitch which is configured for each axis separatly 
	const float x = vd.getX() / GBL_CONFIG->getDispFactX3D(); 
	const float y = vd.getY() / GBL_CONFIG->getDispFactY3D();
	const float z = vd.getZ() / GBL_CONFIG->getDispFactZ3D();
	
	appendVertex(vd.getId(), vd.getSpeedMode(), x, y, z);
}
//////////////////////////////////////////////////
void CncMotionMonitor::appendVertex(long clientId, CncSpeedMode sm, const CncLongPosition& pos) {
//////////////////////////////////////////////////
	// Convert the given steps (abs) to a glpos (rel):
	
	// To do this first we need to normalize the values for x, y and z 
	// to a common unit like [mm], because [steps] are depends on 
	// the corresponding pitch which is configured for each axis separatly 
	const float x = pos.getX() / GBL_CONFIG->getDispFactX3D(); 
	const float y = pos.getY() / GBL_CONFIG->getDispFactY3D();
	const float z = pos.getZ() / GBL_CONFIG->getDispFactZ3D();
	
	appendVertex(clientId, sm, x, y, z);
}
//////////////////////////////////////////////////
void CncMotionMonitor::appendVertex(long id, CncSpeedMode sm, float x, float y, float z) {
//////////////////////////////////////////////////
	// x, y, z have to be given as glpos
	typedef GLI::GLCncPathVertices::FormatType PathVerticeType;
	
	static wxColour 		colour;
	static PathVerticeType	formatType;
	/*
	// decorate
	switch ( sm ) {
		case CncSpeedWork:			colour		= getContextOptions().workColour;
									formatType	= PathVerticeType::FT_SOLID;
									break;
										
		case CncSpeedRapid:			colour 		= getContextOptions().rapidColour;
									formatType	= ( getContextOptions().showFlyPath == true ? PathVerticeType::FT_DOT : PathVerticeType::FT_TRANSPARENT );
									break;
										
		case CncSpeedMax:			colour 		= getContextOptions().maxColour;
									formatType	= PathVerticeType::FT_SOLID;
									break;
										
		case CncSpeedUserDefined:	colour 		= getContextOptions().userColour;
									formatType	= PathVerticeType::FT_SOLID;
									break;
	}
	*/
	#warning !!!!
	// append
	// todo - avoid duplicates last != new
	static GLOpenGLPathBuffer::CncVertex vertex;
	monitor->appendPathData(vertex.set('R', id, x, y, z)); 
}
/////////////////////////////////////////////////////////////////
void CncMotionMonitor::centerViewport() {
/////////////////////////////////////////////////////////////////
	monitor->centerViewport();
	display();
}
/////////////////////////////////////////////////////////////////
void CncMotionMonitor::resetRotation() {
/////////////////////////////////////////////////////////////////
	monitor->getModelRotation().reset2DDefaults();
	display();
}
/////////////////////////////////////////////////////////////////
void CncMotionMonitor::onPaint() {
/////////////////////////////////////////////////////////////////
	if ( IsShownOnScreen() == false )
		return;

	monitor->SetCurrent(*this);
	monitor->init();

	const wxSize cs = GetClientSize();
	
	if ( isShown )	monitor->reshape(cs.GetWidth(), cs.GetHeight());
	else 			monitor->reshapeViewMode(cs.GetWidth(), cs.GetHeight());
	
	monitor->display();
	
	// update additional controls
	notifyChange();
	
	// The first onPaint() if IsShownOnScreen() == true have to reshape the view mode
	// later this should not appear to support custom origin positions
	// see if above
	isShown = IsShownOnScreen();
	
	if ( isShown )
		SwapBuffers();
}
//////////////////////////////////////////////////
void CncMotionMonitor::onPaint(wxPaintEvent& event) {
//////////////////////////////////////////////////
	// This is required even though dc is not used otherwise.
	const wxPaintDC dc(this);
	onPaint();
}
//////////////////////////////////////////////////
void CncMotionMonitor::onSize(wxSizeEvent& event) {
//////////////////////////////////////////////////
	const wxSize cs = GetClientSize();
	
	monitor->reshapeViewMode(cs.GetWidth(), cs.GetHeight());
	monitor->display();
	
	event.Skip();
}
//////////////////////////////////////////////////
void CncMotionMonitor::onEraseBackground(wxEraseEvent& event) {
//////////////////////////////////////////////////
	// update background 
	monitor->display();
	
	// and avoid flashing on MSW
}
//////////////////////////////////////////////////
void CncMotionMonitor::onLeave(wxMouseEvent& event) {
//////////////////////////////////////////////////
	mouseMoveMode = false;
}
//////////////////////////////////////////////////
void CncMotionMonitor::onMouse(wxMouseEvent& event) {
//////////////////////////////////////////////////
	CncGlCanvas::onMouse(event);
}
//////////////////////////////////////////////////
void CncMotionMonitor::onKeyDown(int keyCode) {
//////////////////////////////////////////////////
	static const int delta = 10;
	const wxSize cs = GetClientSize();
	
	int ox = monitor->getLastReshapeX();
	int oy = monitor->getLastReshapeY();
	if ( ox == 0 )	ox = cs.GetWidth()/2;
	if ( oy == 0 )	oy = cs.GetHeight()/2;
	
	switch ( keyCode ) {
		
		case 'C':			monitor->centerViewport();
							display();
							break;
					
		case WXK_UP:		oy += delta; monitor->reshape(cs.GetWidth(), cs.GetHeight(), ox, oy);
							display();
							break;
							
		case WXK_DOWN:		oy -= delta; monitor->reshape(cs.GetWidth(), cs.GetHeight(), ox, oy);
							display();
							break;
		
		case WXK_LEFT:		ox -= delta; 
							monitor->reshape(cs.GetWidth(), cs.GetHeight(), ox, oy);
							display();
							break;
							
		case WXK_RIGHT:		ox += delta; 
							monitor->reshape(cs.GetWidth(), cs.GetHeight(), ox, oy);
							display();
							break;
	}
}
//////////////////////////////////////////////////
void CncMotionMonitor::onKeyDown(wxKeyEvent& event) {
//////////////////////////////////////////////////
	onKeyDown(event.GetKeyCode());
}
//////////////////////////////////////////////////
void CncMotionMonitor::setCameraRotationSpeed(int speed) {
//////////////////////////////////////////////////
	cameraRotationSpeed = speed;
	
	// update timer settings on demand
	if ( cameraRotationTimer.IsRunning() ) {
		cameraRotationTimer.Stop();
		cameraRotationTimer.Start(cameraRotationSpeed);
	}
}
//////////////////////////////////////////////////
void CncMotionMonitor::cameraRotationTimerHandler(CncMotionMonitor::CameraMode cm) {
//////////////////////////////////////////////////
	if ( cameraRotationTimer.IsRunning() ) {
		cameraRotationTimer.Stop();
	}
	
	typedef CncMotionMonitor::CameraMode Mode;
	switch ( cm ) {
		case Mode::CM_OFF:					return;
		case Mode::CM_CLOCKWISE:			cameraRotationStepWidth = +1; break;
		case Mode::CM_COUNTER_CLOCKWISE:	cameraRotationStepWidth = -1; break;
	}
	
	monitor->setViewMode(GLContextBase::ViewMode::V2D_CAM_ROT_XY_ZTOP);
	monitor->reshapeViewMode();
	
	cameraRotationTimer.Start(cameraRotationSpeed);
}
//////////////////////////////////////////////////
void CncMotionMonitor::onCameraRotationTimer(wxTimerEvent& event) {
//////////////////////////////////////////////////
	int pos = monitor->getCameraPosition().getCurXYPlaneEyeAngle() + cameraRotationStepWidth;
	
	// update the camera postion
	rotateCamera(pos);
	
	// update the option pane
	notifyCameraAngleChange(pos);
}
//////////////////////////////////////////////////
void CncMotionMonitor::rotateCamera(int angle) {
//////////////////////////////////////////////////
	// important to have the right view
	monitor->setViewMode(GLContextBase::ViewMode::V2D_CAM_ROT_XY_ZTOP);
	monitor->reshapeViewMode();

	// rotate
	monitor->getCameraPosition().rotateXYPlanTopZ_3D(angle, 
													 monitor->getCameraPosition().getCurXYPlaneEyeRadius(),
													 monitor->getCameraPosition().getEyeZ());
	// redraw
	display();
}
//////////////////////////////////////////////////
void CncMotionMonitor::updateMonitorAndOptions() {
//////////////////////////////////////////////////
	Refresh();
	getContextOptions().notifyChange();
}
//////////////////////////////////////////////////
void CncMotionMonitor::normalizeMonitor() {
//////////////////////////////////////////////////
	monitor->normalizeRotation();
	monitor->normalizeCamera();
	Refresh();
}
//////////////////////////////////////////////////
void CncMotionMonitor::pushProcessMode() {
//////////////////////////////////////////////////
	//set processing flags
	normalizeMonitor();
	resetCurrentClientId();
	
	monitor->deactivateNotifications();
}
//////////////////////////////////////////////////
void CncMotionMonitor::popProcessMode() {
//////////////////////////////////////////////////
	monitor->activateNotifications();
}


