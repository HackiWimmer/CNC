#ifndef SVG_PATH_FRAGMENT_H
#define SVG_PATH_FRAGMENT_H

#include "SvgTransformMatrix.h"
#include "CncClipperWrapper.h"
#include "SvgGeneratorBase.h"

////////////////////////////////////////////////////////////////////////////////////
class SvgPathFragment : public SvgGeneratorBase {
	
	protected:
		SVGUnit inputUnit;
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& printf(double val);
		
	public:
		////////////////////////////////////////////////////////////////////////////
		SvgPathFragment(SVGUnit i = mm) 
		: SvgGeneratorBase()
		, inputUnit(i)
		{
		}
		
		////////////////////////////////////////////////////////////////////////////
		virtual ~SvgPathFragment() {
		}
		
		////////////////////////////////////////////////////////////////////////////
		virtual void setColour(const wxColour& c) {
			SvgGeneratorBase::setColour(c);
		}
		
		////////////////////////////////////////////////////////////////////////////
		virtual void setXmlPattern(const wxString& pattern) {
			SvgGeneratorBase::setXmlPattern(pattern);
		}
		
		////////////////////////////////////////////////////////////////////////////
		static const wxString& convertToString(SVGUnit inputUnit, double val);
		static double convertToDouble(SVGUnit inputUnit, double val);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& absMove(double toX, double toY);
		const wxString& relMove(double dx, double dy);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& absLine(double toX, double toY);
		const wxString& relLine(double dx, double dy);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& ellipticalArg(double r);
		const wxString& ellipticalArg(double rx, double ry);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& addRect(double td, double width, double height, double rx, double ry, bool correctRadius);
		const wxString& addSquareRect(double td, double width, double height, bool correctRadius);
		const wxString& addRoundRect(double td, double width, double height, bool correctRadius);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& addPoint(double x, double y);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& addLine(double td, double x1, double y1, double x2, double y2, bool correctRadius);
		
};

#endif