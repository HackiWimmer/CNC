#include <wx/file.h>
#include "SerialEmulatorBinaryStreamer.h"

///////////////////////////////////////////////////////////////////
SerialEmulatorBinaryStreamer::SerialEmulatorBinaryStreamer(CncControl* cnc)
: SerialEmulatorNULL(cnc)
, CncBinaryTemplateStreamer()
, fileName("")
///////////////////////////////////////////////////////////////////
{
}
///////////////////////////////////////////////////////////////////
SerialEmulatorBinaryStreamer::~SerialEmulatorBinaryStreamer() {
///////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////
bool SerialEmulatorBinaryStreamer::isOutputAsTemplateAvailable() {
///////////////////////////////////////////////////////////////////

	std::cout << getPortName() << " = "<< wxFile::Exists(getPortName()) << std::endl;

	switch ( inboundFormat ) {
		case TplBinary:
		case TplUnknown:
		case TplTest:		return false;
		default:			return wxFile::Exists(getPortName());
	}
	
	return false; 
}
///////////////////////////////////////////////////////////////////
bool SerialEmulatorBinaryStreamer::connect(const char* fileName) {
///////////////////////////////////////////////////////////////////
	this->fileName.assign(fileName);
	
	setConnected(true);
	return isConnected();
}
///////////////////////////////////////////////////////////////////
void SerialEmulatorBinaryStreamer::disconnect() {
/////////////////////////////////////////////////////////////////
	setConnected(false);
}
///////////////////////////////////////////////////////////////////
bool SerialEmulatorBinaryStreamer::writeSetterRawCallback(unsigned char *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	return appendDataBlock(buffer, nbByte);
}
///////////////////////////////////////////////////////////////////
bool SerialEmulatorBinaryStreamer::writeMoveRawCallback(unsigned char *buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	return appendDataBlock(buffer, nbByte);
}
///////////////////////////////////////////////////////////////////
bool SerialEmulatorBinaryStreamer::writeMoveSequenceRawCallback(unsigned char* buffer, unsigned int nbByte) {
///////////////////////////////////////////////////////////////////
	//std::cout << nbByte << " -> " << (int)buffer[0] << " " << (int)buffer[1] << " " << (int)buffer[2] << " " << (int)buffer[3] << " " << (int)buffer[4] << " " << std::endl;
	return appendDataBlock(buffer, nbByte);
}
///////////////////////////////////////////////////////////////////
void SerialEmulatorBinaryStreamer::processTrigger(const Serial::Trigger::BeginRun& tr) {
///////////////////////////////////////////////////////////////////
	if ( isReadyToStream() )
		CncBinaryTemplateStreamer::finalize();
	
	CncBinaryTemplateStreamer::ParameterSet ps = tr.parameter;
	ps.fullFileName = fileName;
	
	inboundFormat = cnc::getTemplateFormatFromExtention(ps.SRC.fileType);
	
	if ( initNextSourceTemplateFileName(ps) == false) {
		std::cerr << "SerialEmulatorStreamer::processTrigger(BeginRun): initNextSourceTemplateFileName failed" << std::endl;
		disconnect();
	}
}
///////////////////////////////////////////////////////////////////
void SerialEmulatorBinaryStreamer::processTrigger(const Serial::Trigger::EndRun& tr) {
///////////////////////////////////////////////////////////////////
	if ( CncBinaryTemplateStreamer::finalize() == false ) {
		std::cerr << "SerialEmulatorStreamer::processTrigger(TrEndRun): finalize() failed" << std::endl;
	}
}
///////////////////////////////////////////////////////////////////
void SerialEmulatorBinaryStreamer::processTrigger(const Serial::Trigger::NextPath& tr) {
///////////////////////////////////////////////////////////////////
	//std::clog << "SerialEmulatorStreamer::processTrigger(TrNextPath)" << std::endl;
}

