#ifndef CNC_CURVE_LIB_H
#define CNC_CURVE_LIB_H

#include <iostream>

class CncCurveLib {

	public:

		const float PI = 3.14159265359f;

		struct Point{

			public:

				Point() 					: x(0),  y(9)  	{}
				Point(float x1, float y1)	: x(x1), y(y1) 	{}
				Point(double x1, double y1)	: x((float)x1), y((float)y1) 	{}
				Point(const Point& o)		: x(o.x), y(o.y){}

				float x;
				float y;

				double xDbl() { return (double)x; }
				double yDbl() { return (double)y; }

				bool operator == (const Point &v) { return ( x == v.x ) && ( y == v.y ); }
				bool operator != (const Point &v) { return !this->operator==(v); }
		};

		struct ParameterSet {

			Point	p0;
			Point 	p1;
			Point 	p2;
			Point 	p3;

			double 	rx;
			double 	ry;
			double 	xAxisRotation;

			bool 	largeArcFlag;
			bool 	sweepFlag;

			struct EllipticalArcReturnInfo {

				CncCurveLib::Point ellipticalArcCenter;

				float ellipticalArcStartAngle 	=   0;
				float ellipticalArcEndAngle 	=   0;
				float ellipticalArcAngle 		=   0;
				float resultantRx 				=   0;
				float resultantRy 				=   0;

			} EARI;

			struct RenderInfo {
				float curveLength				=   0;
				unsigned int samples			=   0;
				unsigned int steps				=   0;
				float increment					= 0.0;
				float resolution				= 1.0;
			} RI;

		};

		struct Setup {

			struct Approximation {
				unsigned int samples	= 50;
			} approximation;

			struct Resolution {
				float size				= 0.2;
			} resolution;

		} setup;


		class Caller {

			public:
				Caller() {}
				virtual ~Caller() {}
				
				friend CncCurveLib;
				
			protected:
				virtual bool callback(const CncCurveLib::Point& p) = 0;
		
		};

		CncCurveLib(Caller* c)
		: caller(c)
		{
			renderFunc = &CncCurveLib::getPointOnLine;
		}

		virtual ~CncCurveLib() {}

		// common interface
		void init(const CncCurveLib::Setup& s);
		const CncCurveLib::Setup& getSetup() { return setup; }

		bool render(CncCurveLib::ParameterSet& ps);


		const Point getPointOnLine                 (CncCurveLib::ParameterSet& ps, float t);
		const Point getPointOnEllipticalArc        (CncCurveLib::ParameterSet& ps, float t);
		const Point getPointOnQuadraticBezierCurve (CncCurveLib::ParameterSet& ps, float t);
		const Point getPointOnCubicBezierCurve     (CncCurveLib::ParameterSet& ps, float t);

	protected:

		Caller* caller;

		const Point (CncCurveLib::*renderFunc) 	   (CncCurveLib::ParameterSet& ps, float t);

		bool callback(const CncCurveLib::Point& p);

		float clamp(float val, float minVal, float maxVal);
		float toRadians(float angle);
		float angleBetween(const CncCurveLib::Point& v0, const CncCurveLib::Point& v1);
		float distance(const CncCurveLib::Point& p0, const CncCurveLib::Point& p1);

};


class CncLineCurve : public CncCurveLib {

	public:
		CncLineCurve(Caller* c)
		: CncCurveLib(c) {
			renderFunc = &CncCurveLib::getPointOnLine;
		}
		virtual ~CncLineCurve() {}

};

class CncEllipticalCurve : public CncCurveLib {

	public:
		CncEllipticalCurve(Caller* c)
		: CncCurveLib(c) {
			renderFunc = &CncCurveLib::getPointOnEllipticalArc;
		}
		virtual ~CncEllipticalCurve() {}

};

class CncQuadraticBezierCurve : public CncCurveLib {

	public:
		CncQuadraticBezierCurve(Caller* c)
		: CncCurveLib(c) {
			renderFunc = &CncCurveLib::getPointOnQuadraticBezierCurve;
		}
		virtual ~CncQuadraticBezierCurve() {}

};

class CncCubicBezierCurve : public CncCurveLib {

	public:
		CncCubicBezierCurve(Caller* c)
		: CncCurveLib(c) {
			renderFunc = &CncCurveLib::getPointOnCubicBezierCurve;
		}
		virtual ~CncCubicBezierCurve() {}

};


#endif