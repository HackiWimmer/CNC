#include <iostream>
#include "CncCommon.h"
#include "SVGElementConverter.h"
#include "SVGNodeParser.h"

//////////////////////////////////////////////////////////////////
SVGNodeParser::SVGNodeParser()
: pathHandler(NULL)
{
//////////////////////////////////////////////////////////////////
	
}
//////////////////////////////////////////////////////////////////
SVGNodeParser::~SVGNodeParser() {
//////////////////////////////////////////////////////////////////
	
}
///////////////////////////////////////////////////////////////////////
inline int SVGNodeParser::getCommandParaCount(char c) {
/*
 Folgende Buchstaben bzw. Pfadverläufe sind möglich:

    moveto: M, m - Startpunkt (das Aufsetzen des imaginären Stiftes)
    lineto: L, l und H, h und V, v - eine gerade Linie
    closepath: Z, z - eine Pfad schließen
    cubic Bézier curve: C, c und S, s - eine kubische Bézier-Kurve
    quadratic Bézier curve: Q, q und T, t - eine quadratische Bézier-Kurve
    elliptical arc curve: A, a - einen elliptischen Bogen
*/
	int ret = -1;
	switch ( c ) {
		case 'z':
		case 'Z': ret = 0; break;
		case 'h':
		case 'H':
		case 'v':
		case 'V': ret = 1; break;
		case 'm':
		case 'M':
		case 'l':
		case 'L':
		case 't': 
		case 'T': ret = 2; break;
		case 'q':
		case 'Q':
		case 's':
		case 'S': ret = 4; break;
		case 'c':
		case 'C': ret = 6; break;
		case 'a':
		case 'A': ret = 7; break;

		default: ret = -1;
	} 
	return ret;
}
//////////////////////////////////////////////////////////////////
bool SVGNodeParser::evaluatePath(const wxString& data) {
//////////////////////////////////////////////////////////////////
	appendDebugValueBase("Resulting Path", data);
	initNextPath(data);
	
	int sPos = -1;
	wxString token;
	for (unsigned int i=0; i<data.Length(); i++ ) {
		
		if ( data[i] == '-' || data[i] == '+' || data[i] == 'e' || data[i] == 'E' ) 
			continue;
			
		if ( isalpha(data[i]) && sPos < 0 ) {
			sPos = i;
		} else if ( isalpha(data[i]) ) {
			token = data.SubString(sPos, i - 1);
			token.Trim(true).Trim(false);
			if ( processPathCommand(token) == false )
				return false;
				
			sPos = i;
		} 
		
		if ( i == data.Length() - 1 ) {
			token = data.SubString(sPos, i);
			token.Trim(true).Trim(false);
			if ( processPathCommand(token) == false )
				return false;
		}
	}
	
	return true;
}
//////////////////////////////////////////////////////////////////
bool SVGNodeParser::processPathCommand(const wxString& para) {
//////////////////////////////////////////////////////////////////
	if ( para.Length() == 0 )
		return true;

	clearDebugControlPath();
	appendDebugValuePath("Path Fragment", para);
	
	double values[MAX_PARAMETER_VALUES];
	
	wxString token;
	char c 						= '\0';
	unsigned int sPos 			= 0;
	unsigned int valueCounter 	= 0;
	unsigned int commandCounter = 0;
	int parameterCount 			= -1;

	for (unsigned int i=sPos; i<para.Length(); i++) {
		
		if ( i == 0 ) {
			c = para[0].GetValue();
			sPos++;
			if ( (parameterCount = getCommandParaCount(c) ) < 0 ) {
				std::cerr << "Not known command: " << c << std::endl;
				std::cerr << "Current line numer: " << getCurrentLineNumber() << std::endl;
				break;
			}
		} else {
			if ( para[i] == ' ' || para[i] == ',' || para[i] == '-' || para[i] == '+' ) {
				// handle exponential presentation
				if ( (para[i] == '-' || para[i] == '+') && ( para[i-1] == 'e' || para[i-1] == 'E') ) 
					continue;
				
				if ( i != sPos ) {
					token = para.SubString(sPos, i - 1);
					token.ToDouble(&values[valueCounter++]);
					appendDebugValuePath("token", token);

					if ( valueCounter == MAX_PARAMETER_VALUES ) {
						std::cerr << "Max parameters count reached for: " << para.c_str() << std::endl;
						return false;
					}
				}
				if ( para[i] == '-'|| para[i] == '+' )	sPos = i;
				else									sPos = i + 1;
				
			} else if ( i == para.Length() - 1 ) {
				token = para.SubString(sPos, i);
				token.ToDouble(&values[valueCounter++]);
				appendDebugValuePath("token", token);
			}
		}
		
		if ( (int)valueCounter ==  parameterCount ) {
			commandCounter++;
			if ( commandCounter == 2 && ( c == 'm' || c == 'M' ) ) {
				// M - 1 = L or m - 1 = l
				c = c - 1;
			}
			
			bool ret = addPathElement(c, valueCounter, values);
			evaluateDebugState();
			
			if ( shouldStop() == true )
				return false;
			
			if ( ret == false )
				return false;

			valueCounter = 0;
		} 
	}
	
	bool ret = true;
	if ( valueCounter != 0 ) {
		std::cerr << "SVGFileParser:" << std::endl;
		std::cerr << "Parameters count error in: " << para.c_str() << std::endl;
		std::cerr << "Defined parameter count: " << parameterCount << "; Current value count: " << valueCounter << std::endl;
		std::cerr << "Current line numer: " << getCurrentLineNumber() << std::endl;
		std::cerr << "Stored value list: " << std::endl;

		for (unsigned int i=0; i<valueCounter; i++) {
			std::cerr << "[" << i << "]=" << values[i] << "\t";
		}	
		std::cerr << std::endl;
		
		ret = false;
	}
	
	return ret;
}
//////////////////////////////////////////////////////////////////
bool SVGNodeParser::processSvgNode(const wxString& node) {
//////////////////////////////////////////////////////////////////
	if ( pathHandler == NULL ) {
		cerr << "SVGParser::processSvgNode: Failed: Member pathHandler is NULL " << endl;
		return false;
	}
	
	pathHandler->initNextPath();

	wxString path;
	SvgNodeAttributeMap aMap;
	if ( SVGElementConverter::convertNodeToPathData(node, path, aMap) ) {
		
		// reset transform
		SVGTransformMatrix& tm = pathHandler->getSvgTransformMatrix();
		tm.unchanged();
		
		// perform transform
		SvgNodeAttributeMap::iterator it = aMap.find("transform");
		if ( it != aMap.end() ) {
			if ( tm.performTransformAsStringList(it->second) == false )
				return false;
		}
		
		// perform path
		bool ret = evaluatePath(path);
		pathHandler->finishCurrentPath();
		return ret;
	}

	cerr << "SVGParser::processSvgNode: Failed: "<< endl;
	cerr << SVGElementConverter::getErrorInfo() << endl;
	cerr << "Node: " << node << endl;
	SVGElementConverter::resetErrorInfo();
	
	return false;
}
//////////////////////////////////////////////////////////////////
bool SVGNodeParser::addPathElement(char c, unsigned int count, double values[]) {
//////////////////////////////////////////////////////////////////
	if ( pathHandler == NULL ) {
		cerr << "SVGParser::addPathElement: Failed: Member pathHandler is NULL " << endl;
		return false;
	}

	return pathHandler->process(c, count, values);
}