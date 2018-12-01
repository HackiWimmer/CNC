#ifndef SVG_PATH_HANDLER_CNC_H
#define SVG_PATH_HANDLER_CNC_H

#include "SVGPathHandlerBase.h"
#include "SerialPort.h"
#include "CncToolCorrection.h"
#include "CncUnitCalculator.h"
#include "SvgCncParameters.h"
#include "SvgViewBox.h"
#include "CncCommon.h"

class CncControl;

//////////////////////////////////////////////////////////////////
class SVGPathHandlerCnc : public SVGPathHandlerBase {
//////////////////////////////////////////////////////////////////
	
	private:
		
		typedef CncUnitCalculatorBase::Unit Unit;
		
		CncControl* 		cncControl;
		SvgOriginalPathInfo origPathInfo;
		double 				toolRadius;
		bool 				zAxisDown;
		bool 				initialized;
		bool 				debugState;
		double 				width, height;
		SvgCncParameters 	currentCncParameters;
		SVGRootNode			svgRootNode;
		
		// spool path to cnc control
		bool moveLinearXY(double x, double y, bool alreadyRendered);
		
		// path handling
		bool beginCurrentPath();
		bool repeatCurrentPath();
		bool spoolCurrentPath(bool firstRun);
		bool closeCurrentPath();
		
	protected:
	
		// debug functions
		virtual void appendDebugValueDetail(const char* key, wxVariant value);
		virtual void appendDebugValueDetail(const CncPathListEntry& cpe);
		virtual void appendDebugValueDetail(const CncCurveLib::ParameterSet& ps);
		
		virtual bool isInitialized();
		
		// z axis management
		virtual void simulateZAxisUp();
		virtual void simulateZAxisDown();
		virtual bool isZAxisUp();
		virtual bool isZAxisDown();
		bool moveUpZ();
		bool moveDownZ();
		
	public:
		SVGPathHandlerCnc(CncControl* cnc);
		virtual ~SVGPathHandlerCnc();
		virtual const char* getName() { return "SVGPathHandlerCnc"; }
		virtual void initNextClientId(long id);
		
		// Getter and setter
		void setSvgRootNode(const SVGRootNode& srn);
		
		Unit getUnit() 						{ return svgRootNode.getOutputUnit(); }
		double getW() 						{ return svgRootNode.getWidth();      }
		double getH() 						{ return svgRootNode.getHeight();     }
		const char* getViewBox() 			{ return svgRootNode.getViewbox().getViewBoxStr().c_str(); }
		const SVGRootNode& getSvgRootNode()	{ return svgRootNode; }

		SvgCncParameters& getSvgCncParameters();
		void setCncWorkingParameters(SvgCncParameters& cwp);
		void setDebugState(bool state) { debugState = state; }
		
		// path handling
		virtual void prepareWork();
		virtual bool initNextPath();
		virtual bool initNextPath(const SvgOriginalPathInfo& sopi);
		virtual bool finishCurrentPath();
		virtual bool runCurrentPath();
		virtual void finishWork();
		
		virtual void logMeasurementStart();
		virtual void logMeasurementEnd();
};

#endif