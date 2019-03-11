#include "CncControl.h"
#include "MainFrame.h"
#include "SerialSpyPort.h"

///////////////////////////////////////////////////////////////////
SerialSpyPort::SerialSpyPort(CncControl* cnc)
///////////////////////////////////////////////////////////////////
: Serial(cnc)
{
}
///////////////////////////////////////////////////////////////////
SerialSpyPort::SerialSpyPort(const char *portName)
///////////////////////////////////////////////////////////////////
: Serial(portName)
{
}
///////////////////////////////////////////////////////////////////
SerialSpyPort::~SerialSpyPort() {
///////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////
void SerialSpyPort::spyReadData(void *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	if ( traceSpyInfo == true ) {
		if ( nbByte <= 0 )
			return;

		if ( spyRead == true ) {
			lastFetchResult.index += nbByte;
			cnc::spy << wxString::Format(" Serial::<< {0x%02X %02X %04X} 0x[ ", lastFetchResult.ret, lastFetchResult.pid, lastFetchResult.index);
			
			const unsigned char* b = (const unsigned char*) buffer;
			for ( unsigned int i=0; i<nbByte; i++ ) {
				cnc::spy << wxString::Format("%02X ", b[i]);
			}
			cnc::spy << ']';
			
			// special handling to show text messages
			if ( nbByte == 1 && ( lastFetchResult.pid == PID_TEXT || lastFetchResult.pid == PID_MSG ) ) {
				if ( b[0] >= 32 && b[0] <= 127 ) 
					cnc::spy << wxString::Format(" '%c'", b[0]);
			}
			
			cnc::spy << std::endl;
		}
	}
}
///////////////////////////////////////////////////////////////////
void SerialSpyPort::spyWriteData(void *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	if ( traceSpyInfo == true ) {
		if ( nbByte == 0 )
			return;
			
		if ( spyWrite == true ) {
			cnc::spy << " Serial::>> {0xFF 01 0001} 0x[ ";
			
			const unsigned char* b = (const unsigned char*) buffer;
			for ( unsigned int i=0; i<nbByte; i++ ) {
				cnc::spy << wxString::Format("%02X ", b[i]);
			}
			cnc::spy << ']' << std::endl;
		}
	}
	
	// Artificially waste time
	THE_APP->waitActive(cncControl->getStepDelay(), false);
}
///////////////////////////////////////////////////////////////////
int SerialSpyPort::readData(void *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	int ret = Serial::readData(buffer, nbByte);
	spyReadData(buffer, ret);
	
	return ret;
}
///////////////////////////////////////////////////////////////////
bool SerialSpyPort::writeData(void *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	spyWriteData(buffer, nbByte);
	bool ret = Serial::writeData(buffer, nbByte);
	
	return ret;
}