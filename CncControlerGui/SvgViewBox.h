#ifndef SVG_VIEW_BOX_H
#define SVG_VIEW_BOX_H

#include <cfloat>
#include <wx/tokenzr.h>
#include "CncUnitCalculator.h"

////////////////////////////////////////////////////////////////////////////
class SVGViewbox {
	
	private:
		wxString viewBoxStr;
		double x;
		double y;
		double w;
		double h;
		
		double minX;
		double maxX;
		double minY;
		double maxY;
		
	public:
		///////////////////////////////////////////////////////////////////
		explicit SVGViewbox(const wxString& vb) 
		: viewBoxStr(vb)
		, x(DBL_MAX)	, y(DBL_MAX)
		, w(DBL_MAX)	, h(DBL_MAX)
		, minX(0.0)		, maxX(0.0)
		, minY(0.0)		, maxY(0.0)
		{
			setup(viewBoxStr);
		}
		
		///////////////////////////////////////////////////////////////////
		~SVGViewbox() {}
		
		///////////////////////////////////////////////////////////////////
		void setup(const wxString& vb) {
			viewBoxStr.assign(vb);
			
			wxStringTokenizer tokenizer(viewBoxStr, " ,");
			unsigned int counter = 0;
			while ( tokenizer.HasMoreTokens() ) {
				wxString token = tokenizer.GetNextToken();
				if ( token.IsEmpty() == false ) {
					switch ( counter++ ) {
						case 0:		token.ToDouble(&x); break;
						case 1:		token.ToDouble(&y); break;
						case 2:		token.ToDouble(&w); break;
						case 3:		token.ToDouble(&h); break;
						default:	std::cerr << "SvgViewBox::SvgViewBox: Invalid token count: "<< counter << std::endl;;
					}
				}
			}
			
			// calculate further members
			if ( isValid() ) {
				minX = x;
				minY = y;
				maxX = x + w;
				maxY = y + h;
			}
		}
		
		////////////////////////////////////////////////////////////////
		friend std::ostream &operator<< (std::ostream &ostr, const SVGViewbox &a) {
			ostr << a.getViewBoxStr() << ": " 	<< a.getX() 	<< ", " 
												<< a.getY() 	<< ", " 
												<< a.getW() 	<< ", " 
												<< a.getH() 	<< " | "
												<< a.getMinX() 	<< ", "
												<< a.getMaxX() 	<< ", "
												<< a.getMinY() 	<< ", "
												<< a.getMaxY();
			return ostr;
		}
		
		///////////////////////////////////////////////////////////////////
		const bool hasX() 		const 	{ return x != DBL_MAX; }
		const bool hasY() 		const 	{ return y != DBL_MAX; }
		const bool hasW() 		const	{ return w != DBL_MAX; }
		const bool hasH() 		const	{ return h != DBL_MAX; }
		const bool isValid() 	const	{ return (hasX() && hasY() && hasW() && hasH()); }
		
		///////////////////////////////////////////////////////////////////
		const double getX() 	const	{ return x; }
		const double getY() 	const	{ return y; }
		const double getW() 	const	{ return w; }
		const double getH() 	const	{ return h; }
		
		const double getMinX() 	const	{ return minX; }
		const double getMaxX() 	const	{ return maxX; }
		const double getMinY() 	const	{ return minY; }
		const double getMaxY() 	const	{ return maxY; }
		
		const wxString& getViewBoxStr() const { return viewBoxStr; }
};

////////////////////////////////////////////////////////////////////////////
class SVGRootNode {
	
	private:
		typedef CncUnitCalculatorBase::Unit Unit;
		
		double 		width;
		double 		height;
		
		SVGViewbox 	viewBox;
		
		float 		scaleX;
		float 		scaleY;
		
		CncUnitCalculator<float> unitCalculator;
		
		void setup();
		void convertToUnit(const Unit unit);
		void convertToMillimeter();
		
	public:
		
		SVGRootNode();
		SVGRootNode(double svgWidth, double svgHeight, Unit unit);
		SVGRootNode(double svgWidth, double svgHeight, Unit unit, const wxString& vb);
		explicit SVGRootNode(const SVGRootNode& n); 
		~SVGRootNode() {}
		
		const SVGViewbox& getViewbox()		const { return viewBox; }
		const double getWidth()				const { return width;   }
		const double getHeight()			const { return height;  }
		const float getScaleX()				const { return scaleX;  }
		const float getScaleY()				const { return scaleY;  }
		
		const Unit getInputUnit()			const { return unitCalculator.getInputUnit();  }
		const Unit getOutputUnit()			const { return unitCalculator.getOutputUnit(); }
		
		const double getWidth_MM()			const { return unitCalculator.convert(width);  }
		const double getHeight_MM()			const { return unitCalculator.convert(height); }
		
		const wxString& getRootTransformation(wxString& ret) const;
		
		friend std::ostream &operator<< (std::ostream &ostr, const SVGRootNode &a) {
			typedef CncUnitCalculator<float> UC;
			
			ostr 	<< " <svg"
					<< " width=\""  << a.getWidth()		<< UC::getUnitAsStr(a.getOutputUnit()) << "\""
					<< " height=\"" << a.getHeight()	<< UC::getUnitAsStr(a.getOutputUnit()) << "\"";
			
			ostr 	<< " viewBox=\"" << a.getViewbox().getViewBoxStr() << "\"";

			wxString ret;
			ostr 	<< " transform=\"" << a.getRootTransformation(ret) << "\"";
			
			ostr	<< "/>";
			
			return ostr;
		}
};

////////////////////////////////////////////////////////////////////////////
struct SVGRootNodeTest {
	
	static void test();
};

#endif


/*
#include <iostream>


struct ResultSet {
	
	//Unit 	unit;
	
	float 	minX;
	float 	minY;
	float 	maxX;
	float 	maxY;
	
	float 	width;
	float 	height;
	
	float	scaleX;
	float	scaleY;
};


//------------------------------------------------------------------
bool calculateResultSet(ResultSet& rs, float docW, float docH) {
	return calculateResultSet(rs, docW, docH, 0, 0, docW, docH);
}

//------------------------------------------------------------------
bool calculateResultSet(ResultSet& rs, float docW, float docH, float vbX, float vbY, float vbW, float vbH) {
	
	
	std::cout << docW << ", ";
	std::cout << docH << ", ";
	std::cout << vbX << ", ";
	std::cout << vbY << ", ";;
	std::cout << vbW << ", ";
	std::cout << vbH << "  ->  ";


	
	
	
	
	
	
	
	
	
	rs.minX 	= vbX;
	rs.minY 	= vbY;
	
	rs.width 	= vbW;
	rs.height 	= vbH;
	
	rs.maxX 	= rs.minX + rs.width;
	rs.maxY 	= rs.minY + rs.height;
	
	rs.scaleX 	= docW / vbW;
	rs.scaleY 	= docH / vbH;
	
	
	return true;
}


void print(const ResultSet& rs) {
	
	std::cout << rs.minX << ", ";
	std::cout << rs.minY << ", ";
	std::cout << rs.width << ", ";
	std::cout << rs.width << ", ";
	std::cout << rs.maxX << ", ";
	std::cout << rs.maxY << ", ";
	std::cout << rs.scaleX << ", ";
	std::cout << rs.scaleY << std::endl;
			
}



int main() {
	
	
	ResultSet rs;
	
	
	calculateResultSet(rs, 200, 100, 0, 0, 200, 100); print(rs);
	calculateResultSet(rs, 200, 100, 0, 0, 400, 200); print(rs);
	calculateResultSet(rs, 200, 100, 0, 0, 100,  50); print(rs);
	calculateResultSet(rs, 200, 100, 0, 0, 100, 100); print(rs);
	calculateResultSet(rs, 200, 100, 0, 0, 100, 100); print(rs);
	calculateResultSet(rs, 200, 100, -10, -10, 100, 100); print(rs);
	calculateResultSet(rs, 200, 100, 10, 10, 100, 100); print(rs);
	
	
	
	return 0;
}
*/