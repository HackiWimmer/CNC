#ifndef SVG_CONTROL_POPUP_H
#define SVG_CONTROL_POPUP_H

#include <wx/menu.h>
#include "CncSourceEditor.h"

enum {
	STC_PM_COMMENT = 0,
	STC_PM_UNCOMMENT,
	STC_PM_SELECT_NODE,
	STC_PM_SELECT_NODE_BLOCK,
	STC_PM_CNC_PARAM_RESET,
	STC_PM_CNC_PARAM_PRINT,
	STC_PM_CNC_PARAM_HELP,
	STC_PM_CNC_PARAM_BLOCK,
	STC_PM_CNC_BREAK_BLOCK,
	STC_PM_CNC_PAUSE_BLOCK,
	STC_PM_CIRCLE,
	STC_PM_ELLIPSE,
	STC_PM_LINE,
	STC_PM_POLYGON,
	STC_PM_POLYLINE,
	STC_PM_RECT,
	STC_PM_PATH,
	STC_PM_PATH_ELLIPTICALARC,
	STC_PM_PATH_QUADRATICBEZIER,
	STC_PM_PATH_CUBICBEZIER,
	STC_PM_COPY,
	STC_PM_PASTE,
	STC_PM_UNDO,
	STC_PM_REDO,
	STC_PM_SELECT_ALL,
	STC_PM_CUT,
	STC_PM_DELETE,
	STC_OPEN_IN_BROWSER
};

class SvgNodeTemplates {
	private:
		static wxString _ret;
		 
	public:
		
		static const char* CncParameterResetBlockNodeName;
		static const char* CncParameterPrintBlockNodeName;
		static const char* CncParameterBlockNodeName;
		static const char* CncBreakBlockNodeName;
		static const char* CncPauseBlockNodeName;

		static const char* getSamplesAsString();
		static const char* getCncParameterHelp();
		static const char* getCncParameterBlock();
		static const char* getCncParameterPrint();
		static const char* getCncParameterReset();
		static const char* getCncBreakBlock();
		static const char* getCncPauseBlock();
		static const char* getCircleTemplate();
		static const char* getEllipseTemplate();
		static const char* getRectTemplate();
		static const char* getLineTemplate();
		static const char* getPolygonTemplate();
		static const char* getPolylineTemplate();
		static const char* getPathTemplate();
		static const char* getEllipticalARCPattern();
		static const char* getQuadraticBezierPattern();
		static const char* getCubicBezierPattern();
};
	
class SvgEditPopup {
	
	private:
	
		static unsigned int _idOffset;
		
		///////////////////////////////////////////////////////////////////
		static unsigned int getNextIdOffset() {
			_idOffset += 100;
			return _idOffset;
		}
		
		///////////////////////////////////////////////////////////////////
		static bool hasSelection(wxStyledTextCtrl* ctl) {
			if ( ctl == NULL )
				return false;
				
			long s, e;
			ctl->GetSelection(&s, &e);
			return (e != s);
		}
		
		///////////////////////////////////////////////////////////////////
		static void overAllMenuItems(wxMenu* m);
		
	public:
		
		///////////////////////////////////////////////////////////////////
		struct EditSearchParam {
			struct In {
				wxString searchStart;
				wxString searchEnd;
			} in;
			
			struct Out {
				int startPos;
				int EndPos;
			} out;
			
		};
		
		
		///////////////////////////////////////////////////////////////////
		static wxMenu* createMenu(wxStyledTextCtrl* ctl, wxMenu* popup, bool extended);
		
		///////////////////////////////////////////////////////////////////
		static bool searchCurrentNode(wxStyledTextCtrl* ctl, EditSearchParam& parameter);
		static bool getCurrentSvgNode(wxStyledTextCtrl* ctl, wxString& node);
		
		///////////////////////////////////////////////////////////////////
		static bool commentCurrentSvgNode(wxStyledTextCtrl* ctl);
		static bool uncommentCurrentSvgNode(wxStyledTextCtrl* ctl);
		static bool selectCurrentSvgNode(wxStyledTextCtrl* ctl);
		static bool selectCurrentSvgNodeBlock(wxStyledTextCtrl* ctl);
		
		///////////////////////////////////////////////////////////////////
		static void enablePathGeneratorMenuItem(wxMenu* menu);

};

#endif