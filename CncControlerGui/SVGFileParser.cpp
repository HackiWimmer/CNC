#include <iostream>
#include <wx/string.h>
#include <wx/tokenzr.h>
#include <wx/xml/xml.h>
#include <wx/filename.h>
#include "CncSourceEditor.h"
#include "OSD/webviewOSD.h"
#include "SvgEditPopup.h"
#include "SvgViewBox.h"
#include "SVGElementConverter.h"
#include "CncUnitCalculator.h"
#include "MainFrameProxy.h"
#include "CncFileNameService.h"
#include "CncConfig.h"
#include "CncControl.h"
#include "SVGPathHandlerCnc.h"
#include "SvgColourScheme.h"
#include "SVGFileParser.h"

//////////////////////////////////////////////////////////////////
SVGFileParser::SVGFileParser(const wxString& fn, CncControl* cnc) 
: SVGNodeParser		()
, FileParser		(fn)
, cncControl		(cnc)
, pathHandler		(new SVGPathHandlerCnc(cnc))
, svgUserAgent		()
, currentNodeName	()
, debugBase			(NULL)
, debugPath			(NULL)
, debugDetail		(NULL)
{
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	pathHandler->setFileParser(this);
}
//////////////////////////////////////////////////////////////////
SVGFileParser::~SVGFileParser() {
//////////////////////////////////////////////////////////////////
	delete pathHandler;
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::logMeasurementStart() {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	pathHandler->logMeasurementStart();
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::logMeasurementEnd() {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	pathHandler->logMeasurementEnd();
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::initNextClientId(long id) {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	pathHandler->initNextClientId(id);
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::evaluateProcessingCallback() {
//////////////////////////////////////////////////////////////////
	return evaluateProcessingState();
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::selectSourceControl(unsigned long pos) {
//////////////////////////////////////////////////////////////////
	// default handling
	if ( inboundSourceControl == NULL ) {
		FileParser::selectSourceControl(pos);
		return;
	}
	
	inboundSourceControl->selectLineNumber(pos, currentNodeName);
}
////////////////////////////////////////////////////////////////////////////
void SVGFileParser::enableUserAgentControls(bool state) {
////////////////////////////////////////////////////////////////////////////
	SvgUserAgentOutputControls soc;
	
	if ( state == true ) {
		soc.detailInfo 			= APP_PROXY::GetDvListCtrlSvgUADetailInfo();
		soc.inboundPathList		= APP_PROXY::GetDvListCtrlSvgUAInboundPathList();
		soc.useDirectiveList	= APP_PROXY::GetDvListCtrlSvgUAUseDirective();
	} 
	else {
		soc.detailInfo 			= NULL;
		soc.inboundPathList		= NULL;
		soc.useDirectiveList	= NULL;
	}
	
	svgUserAgent.setOutputControls(soc);
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::setPathHandler(PathHandlerBase* ph) {
//////////////////////////////////////////////////////////////////
	std::cerr	<< CNC_LOG_FUNCT << ": Invalid call, this class didn't support this method!" 
				<< std::endl
				<< "Nothig will be set." 
				<< std::endl
				;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::addPathElement(char c, unsigned int count, double values[]) {
//////////////////////////////////////////////////////////////////
	// part of preprocessing
	// append to user agent only
	return svgUserAgent.addPathElement(c, count, values);
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::determineUnit(const wxString& uw, const wxString& uh, Unit& u) {
//////////////////////////////////////////////////////////////////
	Unit unitW = Unit::px; 
	Unit unitH = Unit::px; 

	if ( CncUnitCalculatorBase::determineUnit(uw, unitW) == false )
		return false;
		
	if ( CncUnitCalculatorBase::determineUnit(uh, unitH) == false )
		return false;
		
	if ( unitW == unitH ) {
		u = unitH;
		return true;
	}
		
	std::cerr << "unitW(" << unitW << ") != unitH(" << unitH << ")" << std::endl;
	return false;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::setSVGRootNode(const wxString& w, const wxString& h, const wxString& vb) {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	
	double width=0, height=0;
	wxString s, unitW, unitH;
	int sPos = -1;
	s = w;
	for ( int i=0; i<(int)s.Length();i++ ) {
		if ( s[i] == ' ' || s[i] == '\t' )
			continue;
		
		if ( isalpha(s[i]) && sPos < 0 ) {
			sPos = i;
			s.SubString(0, i - 1).ToDouble(&width);
			unitW = s.SubString(i, s.Length() -1);
		}
	}
	if ( sPos == -1 ) {
			s.SubString(0, s.Length() - 1).ToDouble(&width);
			unitW = "px";
	}

	sPos = -1;
	s = h;
	for ( int i=0; i<(int)s.Length();i++ ) {
		if ( s[i] == ' ' || s[i] == '\t' )
			continue;
		
		if ( isalpha(s[i]) && sPos < 0 ) {
			sPos = i;
			s.SubString(0, i - 1).ToDouble(&height);
			unitH = s.SubString(i, s.Length() -1);
		}
	}
	if ( sPos == -1 ) {
			s.SubString(0, s.Length() - 1).ToDouble(&height);
			unitH = "px";
	}
	
	Unit unit;
	if ( determineUnit(unitW, unitH, unit) == false )
		return false;
	
	SVGRootNode svgRootNode(width, height, unit, vb);
	
	std::stringstream ss; ss << svgRootNode;
	APP_PROXY::GetSvgRootNode()->ChangeValue(ss.str());

	// reporting
	typedef CncUnitCalculator<float> UC;
	APP_PROXY::parsingSynopsisTraceAddSeparator("RootNode:");
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format("Translated RootNode: %s",  ss.str()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Input Unit        : %s",  UC::getUnitAsStr(svgRootNode.getInputUnit())));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Output Unit       : %s",  UC::getUnitAsStr(svgRootNode.getOutputUnit())));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Width        [px] : %12.3lf", svgRootNode.getWidth()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Heigth       [px] : %12.3lf", svgRootNode.getHeight()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Width        [mm] : %12.3lf", svgRootNode.getWidth_MM()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Heigth       [mm] : %12.3lf", svgRootNode.getHeight_MM()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Scale X           : %12.3lf", svgRootNode.getScaleX()));
	APP_PROXY::parsingSynopsisTraceAddInfo(wxString::Format(" Scale Y           : %12.3lf", svgRootNode.getScaleY()));
	
	pathHandler->setSvgRootNode(svgRootNode);
	
	wxString ret;
	svgUserAgent.initalize();
	svgUserAgent.addTransform(svgRootNode.getRootTransformation(ret));
	
	return true;
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::broadcastDebugState(bool state) {
//////////////////////////////////////////////////////////////////
	pathHandler->setDebugState(state);
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::debugXMLAttribute(wxXmlAttribute *attribute, wxString& attrString) {
//////////////////////////////////////////////////////////////////
	if ( attribute == NULL )
		return;
	
	attrString << attribute->GetName();
	attrString << "=";
	attrString << attribute->GetValue();
	attrString << " ";
	
	// recursion call to get the compelete depth
	debugXMLAttribute(attribute->GetNext(), attrString);
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::registerXMLNode(wxXmlNode *child) {
//////////////////////////////////////////////////////////////////
	static SvgColourAttributeDecoder	cad;
	static SvgColourDecoder				cs;
	
	wxXmlAttribute* attr = child->GetAttributes();
	svgUserAgent.setNodeType(child->GetName());
	svgUserAgent.addXMLAttributes(attr);
	
	SvgCncContext& cwp = pathHandler->getSvgCncContext();
	cwp.setCurrentLineNumber(getCurrentLineNumber());
	
	if ( THE_CONFIG->getSvgUseColourScheme() == true ) {
		
		const wxString& style = svgUserAgent.getCurrentAttribute("style", "");
		if ( style.IsEmpty() == false ) {
			cad.reset();
			cad.decode(style);
			cwp.setFillColour(cad.getFillColour());
			cwp.setStrokeColour(cad.getStrokeColour());
		}
		
		const wxString& fill = svgUserAgent.getCurrentAttribute("fill", "");
		if ( fill.IsEmpty() == false ) {
			cs.setColour(fill);
			cwp.setFillColour(cs.getColour());
		}
		
		const wxString& stroke = svgUserAgent.getCurrentAttribute("stroke", "");
		if ( stroke.IsEmpty() == false ) {
			cs.setColour(stroke);
			cwp.setStrokeColour(cs.getColour());
		}
		
		cwp.determineColourEffects();
	}
	
	// ----------------------------------------------------------
	if ( runInfo.getCurrentDebugState() == true ) {
		appendDebugValueBase("Reverse Path", cwp.getCorrectionType());
		
		wxString content;
		debugXMLAttribute(attr, content);
		appendDebugValueBase("Attributes", content);
	}
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::clearControls() {
//////////////////////////////////////////////////////////////////
	FileParser::clearControls();
	svgUserAgent.clearControls();
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::initNextRunPhase(FileParserRunInfo::RunPhase p) {
//////////////////////////////////////////////////////////////////
	FileParser::initNextRunPhase(p);
	pathHandler->setDebugState(runInfo.getCurrentDebugState());
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::spool() {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	UserAgentVector uav = svgUserAgent.getList();
	
	pathHandler->prepareWork();

	// over all stored pathes#
	SVGUserAgentInfo uai;
	for ( UserAgentVector::iterator itUav = uav.begin(); itUav != uav.end(); ++itUav ) {
		uai = *itUav;
		
		if ( uai.nodeName == SvgNodeTemplates::CncBreakBlockNodeName ) {
			std::cout << " CncBreak at line " << uai.lineNumber << " detected. Processing will stop here." << std::endl;
			break;
		}
		
		if ( uai.nodeName == SvgNodeTemplates::CncPauseBlockNodeName ) {
			pathHandler->processWait(uai.cncPause.microseconds);
		}
		
		pathHandler->setSvgCncContext(uai.cncParameters);
		// important! the current node name has to be set before setCurrentLineNumer() 
		// to get a correct result in this overlaoded function
		currentNodeName.assign(uai.nodeName);
		registerNextDebugNode(uai.nodeName);
		
		if ( runInfo.getCurrentDebugState() == true ) {
			DcmItemList dil;
			uai.getBaseDetails(dil);
			appendDebugValueBase(dil);
			
			dil.clear();
			uai.getPathDetails(dil);
			appendDebugValuePath(dil);
		}
		
		if ( performPath(uai) == false ) {
			
			// in this case to stop here is valid
			if ( runInfo.getStopFlag() == true )
				return true;
				
			std::cerr << "SVGFileParser::performPath: Failed" << std::endl;
			std::cerr << "Line number: " << uai.lineNumber << ", Node Type: " << uai.nodeName << std::endl;
			return false;
		}
		
		if ( evaluateDebugState() == false )
			return false;
	}
	
	pathHandler->finishWork();
	
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::performPath(SVGUserAgentInfo& uai) {
//////////////////////////////////////////////////////////////////
	bool isSymbol = false;
	
	// Skip this special symbol generally
	if ( uai.isMemberOfSymbol("CncHelperGrid") ) {
		return true;
		
	// check if symbol to skip directly path processing
	} else if ( uai.isMemberOfSymbol() ) {
		isSymbol = true;
		
	// First prepare element
	} else {
		
		// always reset the svg matrix
		pathHandler->getSvgTransformMatrix().unchanged();
		
		if ( uai.hasTransform() ) {
			// transform collected transformations
			if ( prepareTransformMatrix(uai) == false )
				return false;
		}
	} 
	
	if ( isSymbol == false ) {
		// spool this path directly
		if ( spoolPath(uai) == false )
			return false;
	}
	
	// spool this path by id (use directive)
	if ( performPathByIds(uai) == false ) {
		std::cerr << "SVGFileParser::performPathByIds: Failed" << std::endl;
		return false;
	}
			
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::prepareTransformMatrix(SVGUserAgentInfo& uai) {
//////////////////////////////////////////////////////////////////
	for (TransformVector::iterator it=uai.transformList.begin(); it!=uai.transformList.end(); ++it) {
		if ( pathHandler->getSvgTransformMatrix().performTransformAsStringList(*it) == false ) {
			return false;
		}
	}
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::performPathByIds(SVGUserAgentInfo& uai) {
//////////////////////////////////////////////////////////////////
	DoubleStringMap ids = uai.ids;
	
	for ( DoubleStringMap::iterator itIds = ids.begin(); itIds != ids.end(); ++itIds ) {
		// over all use directives
		UseDirectiveVector udv = svgUserAgent.getUseInfoVector();

		for ( UseDirectiveVector::iterator it=udv.begin(); it!=udv.end(); ++it ) {
			UseDirective ud = *it;
			//cout << ud.id << endl;
			
			// if current path matches this the current use directive
			if ( ud.id == itIds->first ) {
				if ( performUse(uai, ud) == false )
					return false;
			}
		}
	}
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::performUse(SVGUserAgentInfo& uai, UseDirective& ud) {
//////////////////////////////////////////////////////////////////
	DoubleStringMap::iterator it;
	it = ud.attributes.find("transform");
	
	if ( it != ud.attributes.end() ) {
		
		#warning - the use transformation did not work correctly
		
		
		// reset the svg matrix
		pathHandler->getSvgTransformMatrix().unchanged();
		
		// first transform from use directive
		if ( pathHandler->getSvgTransformMatrix().performTransformAsStringList(it->second) == false )
			return false;
		
		// second transform rest
		if ( prepareTransformMatrix(uai) == false )
			return false;
		
		//spool path 
		if ( spoolPath(uai, it->second) == false )
			return false;
			
	} else {
		
		//spool path 
		if ( spoolPath(uai, "") == false )
			return false;
	}

	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::spoolPath(SVGUserAgentInfo& uai, const wxString& transform) {
//////////////////////////////////////////////////////////////////
	if ( uai.shouldProceed() == false )
		return true;
		
	static SvgOriginalPathInfo sopi;
	sopi.pathData.assign(uai.originalPath);
	sopi.transformInfo.assign(uai.getTransformInfoAsString());
	sopi.useTransformInfo.assign(transform);
	
	if ( pathHandler->initNextPath(sopi) == false )
		return false;
	
	initNextClientId(uai.lineNumber);
		
	for ( auto itPiv = uai.pathInfoList.begin(); itPiv != uai.pathInfoList.end(); ++itPiv ) {
		if ( pathHandler->processCommand_2DXY(itPiv->cmd, itPiv->count, itPiv->values) == false ) {
			std::cerr << "SVGFileParser::spoolPath failed" << std::endl;
			uai.debug(*itPiv, std::cerr);
			return false;
		}
		
		if ( evaluateProcessingState() == false )
			return false;
	}
	
	if ( pathHandler->finishCurrentPath() == false )
		return false;
		
	// path is now recorded and tried out, now run the controller 
	if ( pathHandler->runCurrentPath() == false )
		return false;
		
	if ( evaluateProcessingState() == false )
		return false;
		
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::preprocess() {
//////////////////////////////////////////////////////////////////
	wxASSERT(pathHandler);
	
	wxXmlDocument doc;
	if ( !doc.Load(fileName) )
		return false;
		
	// Start processing the XML file.
	if ( doc.GetRoot()->GetName().Upper() != "SVG") {
		std::cerr << CNC_LOG_FUNCT << ": Can't evaluate svg tag\n";
		return false;
	}
	
	const wxString w = doc.GetRoot()->GetAttribute("width");
	const wxString h = doc.GetRoot()->GetAttribute("height");
	const wxString v = doc.GetRoot()->GetAttribute("viewBox");
	
	if ( setSVGRootNode(w, h, v) == false ) {
		std::cerr << CNC_LOG_FUNCT << ": setSVGRootNode() failed\n";
		return false;
	}
	
	// main entry point foor evaluateing all XML nodes
	wxXmlNode *child = doc.GetRoot()->GetChildren();
	const bool ret = processXMLNode(child);
	
	if ( ret == false ) {
		std::cerr	<< CNC_LOG_FUNCT << " will return false"						<< std::endl
					<< " Current line numer: "	<< getCurrentLineNumber()			<< std::endl
					<< " Duration counter: "	<< cncControl->getDurationCounter()	<< std::endl
					<< " File parsing stopped"	<< std::endl
					;
	}
	else {
		// fill the user agent controls
		svgUserAgent.expand();
	}
	
	return ret;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::postprocess() {
//////////////////////////////////////////////////////////////////
	if ( cncControl == NULL )
		return true;
	
	const SVGRootNode& rn 	= pathHandler->getSvgRootNode();
	CncUnitCalculator<float> to_mm(rn.getOutputUnit(), Unit::mm);
	
	const CncDoublePosition min(cncControl->getMinPositionsMetric());
	const CncDoublePosition max(cncControl->getMaxPositionsMetric());
	
	const double cncDistX 	= max.getX() - min.getX();
	const double cncDistY 	= max.getY() - min.getY();
	const double svgDistX 	= rn.getWidth_MM()  * rn.getScaleX();
	const double svgDistY 	= rn.getHeight_MM() * rn.getScaleY();
	
	const double cncMinX	= min.getX();
	const double cncMaxX	= max.getX();

	// if the Y axis will be reversed svg is also a right hand coord system
	const bool cnv = CncConfig::getGlobalCncConfig()->getSvgConvertToRightHandFlag();
	const double cncMinY	= min.getY() * (cnv ? +1 : -1);
	const double cncMaxY	= max.getY() * (cnv ? +1 : -1);
	
	const double svgMinX	= to_mm.convert(rn.getViewbox().getMinX());
	const double svgMaxX	= to_mm.convert(rn.getViewbox().getMaxX());
	const double svgMinY	= to_mm.convert(rn.getViewbox().getMinY());
	const double svgMaxY	= to_mm.convert(rn.getViewbox().getMaxY());
	
	bool ret = true;
	auto check_1_Less_2 = [&](double d1, double d2, const char* msg) {
		if ( d1 > d2 ) {
			if ( ret == true ) {
				APP_PROXY::parsingSynopsisTraceAddSeparator("Post Processing Error Summary:");
			}
			
			APP_PROXY::parsingSynopsisTraceAddError(wxString::Format("%s %12.3lf > %12.3lf", msg, d1, d2));
			ret = false;
		}
	};
	
	const char type = 'I';
	APP_PROXY::parsingSynopsisTraceAddSeparator("Boundings:");
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" CNC distance x, y  [mm]: %12.3lf, %12.3lf", cncDistX, cncDistY));
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" SVG distance x, y  [mm]: %12.3lf, %12.3lf", svgDistX, svgDistY));
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" CNC min      x, y  [mm]: %12.3lf, %12.3lf", cncMinX, cncMinY));
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" SVG min      x, y  [mm]: %12.3lf, %12.3lf", svgMinX, svgMinY));
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" CNC max      x, y  [mm]: %12.3lf, %12.3lf", cncMaxX, cncMaxY));
	APP_PROXY::parsingSynopsisTraceAddEntry(type, wxString::Format(" SVG max      x, y  [mm]: %12.3lf, %12.3lf", svgMaxX, svgMaxY));

	check_1_Less_2(cncDistX, svgDistX, " CNC distance X out of range:  ");
	check_1_Less_2(cncDistY, svgDistY, " CNC distance Y out of range:  ");
	check_1_Less_2(svgMinX,  cncMinX,  " CNC min bound X out of range: ");
	check_1_Less_2(svgMinY,  cncMinY,  " CNC min bound Y out of range: ");
	check_1_Less_2(cncMaxX,  svgMaxX,  " CNC max bound X out of range: ");
	check_1_Less_2(cncMaxY,  svgMaxY,  " CNC max bound Y out of range: ");
	
	if ( ret == false )  
		std::cerr << "SVG post processing decteced error(s). For more details please visit the parsing synopsis trace\n";
	
	return ret;
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::processXMLNode(wxXmlNode *child) {
//////////////////////////////////////////////////////////////////
	
	while ( child ) {
		// important! the current node name has to be set before setCurrentLineNumer() 
		// to get a correct result in this overloaded functions
		currentNodeName.assign(child->GetName());
		setCurrentLineNumber(child->GetLineNumber());
		registerXMLNode(child);
		
		// ----------------------------------------------------------
		if ( currentNodeName.IsSameAs("PATH", false) ) {
			registerNextDebugNode(currentNodeName);
			
			const wxString data(child->GetAttribute("d", ""));
			if ( evaluatePath(data)  == false )
				return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("SYMBOL", false) ) {
			wxString a(child->GetAttribute("id", ""));
			svgUserAgent.addID(a, child->GetName().c_str());
			
			a.assign(child->GetAttribute("transform", ""));
			svgUserAgent.addTransform(a);
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("G", false) ) {
			wxString a(child->GetAttribute("id", ""));
			svgUserAgent.addID(a, child->GetName().c_str());
			
			a.assign(child->GetAttribute("transform", ""));
			svgUserAgent.addTransform(a);
			
			a.assign(child->GetAttribute("style", ""));
			svgUserAgent.addStyle(a);
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("CIRCLE", false) ) {
			registerNextDebugNode(currentNodeName);
			
			wxString ret; 
			if ( SVGElementConverter::convertCircleToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("ELLIPSE", false) ) {
			registerNextDebugNode(currentNodeName);
			
			wxString ret; 
			if ( SVGElementConverter::convertEllipseToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("LINE", false) ) {
			registerNextDebugNode(currentNodeName);
			
			wxString ret; 
			if ( SVGElementConverter::convertLineToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("POLYGON", false ) ) {
			registerNextDebugNode(currentNodeName);

			wxString ret; 
			if ( SVGElementConverter::convertPolygonToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("POLYLINE", false) ) {
			registerNextDebugNode(currentNodeName);
			
			wxString ret; 
			if ( SVGElementConverter::convertPolylineToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("RECT", false) ) {
			registerNextDebugNode(currentNodeName);

			wxString ret; 
			if ( SVGElementConverter::convertRectToPathData(child, ret) )
				if ( evaluatePath(ret) == false )
					return false;
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.IsSameAs("USE", false) ) {
			registerNextDebugNode(currentNodeName);
			
			UseDirectiveVector& udv = svgUserAgent.getUseInfoVector();
			UseDirective ud;
			evaluateUse(child->GetAttributes(), ud.attributes);
			udv.push_back(svgUserAgent.evaluateUseDirective(ud));
		}
		// ----------------------------------------------------------
		else if ( currentNodeName.StartsWith("Cnc") ) {
			
			// ------------------------------------------------------
			if ( currentNodeName.IsSameAs(SvgNodeTemplates::CncParameterBlockNodeName) ) {
				if ( evaluateCncParameters(child) == false )
					return false;
					
				registerNextDebugNode(currentNodeName);
				svgUserAgent.initNextCncParameterNode(pathHandler->getSvgCncContext());
			}
			// ------------------------------------------------------
			else if ( currentNodeName.IsSameAs(SvgNodeTemplates::CncBreakBlockNodeName) ) {
				registerNextDebugNode(currentNodeName);
				
				SvgCncBreak scb;
				scb.currentLineNumber = getCurrentLineNumber();
				svgUserAgent.initNextCncBreakNode(scb);
			}
			// ------------------------------------------------------
			else if ( currentNodeName.IsSameAs(SvgNodeTemplates::CncPauseBlockNodeName) ) {
				registerNextDebugNode(currentNodeName);
			
				SvgCncPause scp;
				scp.currentLineNumber = getCurrentLineNumber();
				double p = 0.0;
				if ( child->GetAttribute("p", "0.0").ToDouble(&p) )
					scp.microseconds = (int64_t)(p * 1000 * 1000);
				
				svgUserAgent.initNextCncPauseNode(scp);
			}
			// ------------------------------------------------------
			else if ( currentNodeName.IsSameAs("CNC", false) ) {
				cnc::cex1 << "Obsolete Node. <CNC> isn't longer supported. Line number: " << child->GetLineNumber() << std::endl;
			}
		}
		
		// check the debug state before the next node
		if ( evaluateDebugState() == false )
			return false;
			
		// recursion call to get the complete depth
		wxXmlNode* last = child;
		
		// GetChildren() returns the first child of this node
		if ( processXMLNode(child->GetChildren()) == false ) {
			return false;
		}
		
		// close the id, transform and style attribute (on demand)
		if ( last != NULL ) {
			wxString a(last->GetAttribute("id", ""));
			if ( a.IsEmpty() == false )
				svgUserAgent.removeId(a);
				
			a.assign(last->GetAttribute("transform", ""));
			if ( a.IsEmpty() == false )
				svgUserAgent.removeLastTransform();
			
			// only style attributes from <g> are colleted before
			if ( last->GetName().Upper() == "G" ) {
				a.assign(last->GetAttribute("style", ""));
				if ( a.IsEmpty() == false )
					svgUserAgent.removeLastStyle();
			}
		}
		
		if ( cncControl->isInterrupted() == true )
			return false;
		
		child = child->GetNext();
		
		// check the debug state before the next node
		if ( evaluateDebugState() == false )
			return false;
	}
	
	return true;
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::evaluateUse(wxXmlAttribute *attribute, DoubleStringMap& dsm) {
//////////////////////////////////////////////////////////////////
	if ( attribute == NULL )
		return;
		
	dsm[attribute->GetName()] = attribute->GetValue();
	evaluateUse(attribute->GetNext(), dsm);
}
//////////////////////////////////////////////////////////////////
void SVGFileParser::initNextPath(const wxString& data) {
//////////////////////////////////////////////////////////////////
	svgUserAgent.initNextPath(pathHandler->getSvgCncContext(), data);
}
//////////////////////////////////////////////////////////////////
bool SVGFileParser::evaluateCncParameters(wxXmlNode *child) {
//////////////////////////////////////////////////////////////////
	wxASSERT(cncControl);
	SvgCncContext& cwp = pathHandler->getSvgCncContext();
	
	wxString attr = child->GetAttribute("reverse", "no");
	cwp.setReverseFlag(attr);
	
	attr = child->GetAttribute("correction", "none");
	cwp.setCorrectionType(attr);
	
	attr = child->GetAttribute("depth", wxString::Format("Z%lf", 0.0));
	cwp.setCurrentZDepth(attr);
	
	return true;
}
