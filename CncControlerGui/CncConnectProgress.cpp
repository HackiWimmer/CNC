#include <iostream>
#include "wxCrafterImages.h"
#include "MainFrameProxy.h"
#include "CncConnectProgress.h"

/////////////////////////////////////////////////////////////////////////
CncConnectProgress::CncConnectProgress(wxWindow* parent)
: CncConnectProgressBase(parent)
, pngAnimation(NULL)
/////////////////////////////////////////////////////////////////////////
{
	createAnimationControl();
}
/////////////////////////////////////////////////////////////////////////
CncConnectProgress::~CncConnectProgress() {
/////////////////////////////////////////////////////////////////////////
	stopAnimationControl();
}
/////////////////////////////////////////////////////////////////////////
void CncConnectProgress::initDialog(wxInitDialogEvent& event) {
/////////////////////////////////////////////////////////////////////////
	startAnimationControl();
}
/////////////////////////////////////////////////////////////////////////
void CncConnectProgress::show(wxShowEvent& event) {
/////////////////////////////////////////////////////////////////////////
}
/////////////////////////////////////////////////////////////////////////
void CncConnectProgress::startupTimer(wxTimerEvent& event) {
/////////////////////////////////////////////////////////////////////////
	bool ret = APP_PROXY::connectSerialPort();
	EndModal(ret == true ? wxID_OK : wxID_CANCEL);
}
///////////////////////////////////////////////////////////////////
void CncConnectProgress::observeTimer(wxTimerEvent& event) {
///////////////////////////////////////////////////////////////////
	std::cerr << " Connect progress aborted by observer. Timeout reached!" << std::endl;
	EndModal(wxID_CANCEL);
}
///////////////////////////////////////////////////////////////////
void CncConnectProgress::createAnimationControl() {
///////////////////////////////////////////////////////////////////
	if ( pngAnimation != NULL )
		delete pngAnimation;
		
	pngAnimation = NULL;
	
	wxBitmap bmp = ImageLib16().Bitmap("ANIMATION_SPRITE");
	if ( bmp.IsOk() ) {
		pngAnimation = new wxPNGAnimation(m_connectActivityPanel, bmp, wxHORIZONTAL, wxSize(120,7), 0);
	}
}
///////////////////////////////////////////////////////////////////
void CncConnectProgress::startAnimationControl() {
///////////////////////////////////////////////////////////////////
	if ( pngAnimation != NULL ) {
		if ( pngAnimation->IsRunning() )
			pngAnimation->Stop();
			
		pngAnimation->Start(70);
		pngAnimation->Refresh();
		pngAnimation->Update();
	}
}
///////////////////////////////////////////////////////////////////
void CncConnectProgress::stopAnimationControl() {
///////////////////////////////////////////////////////////////////
	if ( pngAnimation != NULL ) {
		if ( pngAnimation->IsRunning() ) {
			pngAnimation->Stop();
			pngAnimation->Refresh();
			pngAnimation->Update();
		}
	}
}

