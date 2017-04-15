#ifndef SVG_PATH_GENERATOR_H
#define SVG_PATH_GENERATOR_H

#include <vector>
#include <wx/string.h>
#include "SvgUnitCalculator.h"


////////////////////////////////////////////////////////////////////////////////////
class SvgGeneratorBase {
	protected:
	
		std::vector<wxString> errors;
		
		////////////////////////////////////////////////////////////////////////////
		SvgGeneratorBase() {}
		virtual ~SvgGeneratorBase() {}
		
		void clearErrors() { errors.clear(); }
		void addError(const wxString& et) { errors.push_back(et); }
		
	public:
	
		////////////////////////////////////////////////////////////////////////////
		virtual bool hasError() { return (errors.size() != 0); }
		
		////////////////////////////////////////////////////////////////////////////
		virtual const wxString& getErrorInfo() {
			static wxString s;
			
			s.clear();
			for (std::vector<wxString>::iterator it = errors.begin() ; it != errors.end(); ++it)
				s << *it << '\n';
				
			return s;
		}
};

////////////////////////////////////////////////////////////////////////////////////
class SvgPathFragment : public SvgGeneratorBase {
	
	protected:
		SVGUnit inputUnit;
		
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
		const wxString& absMove(double toX, double toY);
		const wxString& relMove(double dx, double dy);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& absLine(double toX, double toY);
		const wxString& relLine(double dx, double dy);
		
		////////////////////////////////////////////////////////////////////////////
		const wxString& ellipticalArg(double r);
		const wxString& ellipticalArg(double rx, double ry);
};

////////////////////////////////////////////////////////////////////////////////////
class SvgPathString : public SvgGeneratorBase {
	
	protected:
		SVGUnit inputUnit;
		wxString pathStr;
		SvgPathFragment generator;
		
		void initPath();
		void finishPath();
		
	public:
		////////////////////////////////////////////////////////////////////////////
		SvgPathString(SVGUnit i = mm) 
		: SvgGeneratorBase()
		, inputUnit(i)
		, pathStr()
		, generator(i)
		{
			initPath();
		}
		////////////////////////////////////////////////////////////////////////////
		virtual ~SvgPathString() {
		}
		
		////////////////////////////////////////////////////////////////////////////
		SvgPathFragment& fGen() { return generator; }
		
		////////////////////////////////////////////////////////////////////////////
		void add(const wxString& pf);
		bool addPocketWhole(double td, double r);
		bool addPocketWhole(double td, double rx, double ry);
		
		const wxString& get();
		
		////////////////////////////////////////////////////////////////////////////
		virtual bool hasError() { return (SvgGeneratorBase::hasError() || fGen().hasError()); }
		
		////////////////////////////////////////////////////////////////////////////
		virtual const wxString& getErrorInfo() {
			static wxString s;
			
			s << fGen().getErrorInfo();
			s << SvgGeneratorBase::getErrorInfo();
			
			return s;
		}
};

////////////////////////////////////////////////////////////////////////////////////
class SvgPathGroup : public SvgGeneratorBase {
	
	protected:
		SVGUnit inputUnit;
		wxString pathGroup;
		wxString transform;
		SvgPathString generator;
		
		void initGroup();
		void finishGroup();
		
	public:
		////////////////////////////////////////////////////////////////////////////
		SvgPathGroup(SVGUnit i = mm) 
		: SvgGeneratorBase()
		, inputUnit(i)
		, pathGroup()
		, transform()
		, generator(i)
		{
		}
		////////////////////////////////////////////////////////////////////////////
		virtual ~SvgPathGroup() {
		}
		
		////////////////////////////////////////////////////////////////////////////
		SvgPathString& pGen()   { return generator; }
		SvgPathFragment& fGen() { return generator.fGen(); }
		
		////////////////////////////////////////////////////////////////////////////
		void add(const wxString& ps);
		const wxString& get();
		
		////////////////////////////////////////////////////////////////////////////
		void translate(double xy);
		void translate(double x, double y);
		
		////////////////////////////////////////////////////////////////////////////
		void scale(double xy);
		void scale(double x, double y);
		
		////////////////////////////////////////////////////////////////////////////
		virtual bool hasError() { return (SvgGeneratorBase::hasError() || fGen().hasError() || pGen().hasError()); }
		
		////////////////////////////////////////////////////////////////////////////
		virtual const wxString& getErrorInfo() {
			static wxString s;
			
			s << fGen().getErrorInfo();
			s << pGen().getErrorInfo();
			s << SvgGeneratorBase::getErrorInfo();
			
			return s;
		}
};

#endif