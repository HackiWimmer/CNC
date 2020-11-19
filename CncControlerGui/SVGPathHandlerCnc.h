#ifndef SVG_PATH_HANDLER_CNC_H
#define SVG_PATH_HANDLER_CNC_H

#include "SVGPathHandlerBase.h"
#include "SerialPort.h"
#include "CncUnitCalculator.h"
#include "CncPathListRunner.h"
#include "CncCommon.h"

class CncControl;

//////////////////////////////////////////////////////////////////
class SVGPathHandlerCnc : public SVGPathHandlerBase
						, public CncPathListRunner
{
	private:
		
		typedef CncUnitCalculatorBase::Unit Unit;
		
		CncControl* 			cncControl;
		bool 					initialized;
		bool 					debugState;

		// spool path to cnc control
		bool moveLinearZ  (double z);
		bool moveLinearXY (double x, double y, bool alreadyRendered);
		bool moveLinearXYZ(double x, double y, double z, bool alreadyRendered);
		
		// path handling
		bool beginCurrentPath();
		bool repeatCurrentPath();
		bool closeCurrentPath();
		
	protected:
	
		// debug functions
		virtual void appendDebugValueDetail(const char* key, wxVariant value);
		virtual void appendDebugValueDetail(const CncPathListEntry& cpe);
		virtual void appendDebugValueDetail(const CncCurveLib::ParameterSet& ps);
		
		virtual bool isInitialized() { return initialized; }
		
		// z axis management
		virtual bool isZAxisUp();
		virtual bool isZAxisDown();
		virtual bool physicallyMoveZAxisUp();
		virtual bool physicallyMoveZAxisDown();
		
	public:
		
		SVGPathHandlerCnc(CncControl* cnc);
		virtual ~SVGPathHandlerCnc();
		virtual const char* getName()		{ return "SVGPathHandlerCnc"; }

		Unit getUnit() 						{ return svgRootNode.getOutputUnit(); }
		double getW() 						{ return svgRootNode.getWidth();      }
		double getH() 						{ return svgRootNode.getHeight();     }
		const char* getViewBox() 			{ return svgRootNode.getViewbox().getViewBoxStr().c_str(); }
		const SVGRootNode& getSvgRootNode()	{ return svgRootNode; }
		
		void setDebugState(bool state)		{ debugState = state; }
		
		virtual void initNextClientId(long id);
		
		virtual void setSvgRootNode(const SVGRootNode& srn);
		virtual void logMeasurementStart();
		virtual void logMeasurementEnd();

		// path handling
		virtual void prepareWork();
		virtual bool initNextPath();
		virtual bool finishCurrentPath();
		virtual bool runCurrentPath();
		virtual void finishWork();
};

#endif
