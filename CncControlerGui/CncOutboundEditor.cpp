#include "MainFrame.h"
#include "CncOutboundEditor.h"

///////////////////////////////////////////////////////////////////
CncOutboundEditor::CncOutboundEditor(wxWindow *parent) 
: CncBaseEditor(parent)
///////////////////////////////////////////////////////////////////
{
	initialize();
}
///////////////////////////////////////////////////////////////////
CncOutboundEditor::~CncOutboundEditor() {
///////////////////////////////////////////////////////////////////
}
///////////////////////////////////////////////////////////////////
void CncOutboundEditor::clearContent() {
///////////////////////////////////////////////////////////////////
	setupTextStyle();
	
	Enable(true);
	
	ClearAll();
	AppendText("<\n\tCurrently no serial outbound content available\n");
	AppendText("/>\n");
	
	Enable(hasEditMode());
}
///////////////////////////////////////////////////////////////////
const char* CncOutboundEditor::getExtention() {
///////////////////////////////////////////////////////////////////
	return cnc::getExtention(fileInfo.format);
}
///////////////////////////////////////////////////////////////////
void CncOutboundEditor::initialize() {
///////////////////////////////////////////////////////////////////
	flags.handleBreakpoints		= false;
	flags.handleKeyCommands		= false;
	
	svgPopupMenu				= NULL;
	
	ctlEditMode					= THE_APP->GetOutboundEditMode();
	ctlColunmPostion			= THE_APP->GetOutboundPosition();
	ctlStatus					= THE_APP->GetOutboundEditStatus();
}