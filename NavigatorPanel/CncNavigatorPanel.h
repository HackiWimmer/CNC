#ifndef CNC_NAVIGATOR_PANEL_H
#define CNC_NAVIGATOR_PANEL_H

#include <wx/panel.h>
#include <wx/event.h>

// ----------------------------------------------------------------------------
class CncNavigatorPanelEvent;
wxDECLARE_EVENT(wxEVT_CNC_NAVIGATOR_PANEL, CncNavigatorPanelEvent);

// ----------------------------------------------------------------------------
class CncNavigatorPanel : public wxPanel {
	
	public:
		
		enum Direction { UD, NN, SS, EE, WW, NW, NE, SW, SE, CP, CN };
		
		struct Config {
			bool innerCircle 		= false;
			bool shortFormat		= false;
			
			wxColour colNN			= wxColour(89, 89, 255);
			wxColour colSS			= colNN;
			wxColour colEE			= wxColour(255, 64, 64);
			wxColour colWW			= colEE;
			wxColour colCP			= wxColour(27, 139, 61);
			wxColour colCN			= colCP;
		};
		
		CncNavigatorPanel(wxWindow *parent, const Config& cfg);
		virtual ~CncNavigatorPanel();
		
		static const char* getDirectionAsString(const Direction d);
		
	protected:
		
		virtual void enterPanel(const CncNavigatorPanelEvent& event)		{ postEvent(event); }
		virtual void leavePanel(const CncNavigatorPanelEvent& event)		{ postEvent(event); }
		virtual void setFocus(const CncNavigatorPanelEvent& event)			{ postEvent(event); }
		virtual void killFocus(const CncNavigatorPanelEvent& event)			{ postEvent(event); }
		virtual void enterRegion(const CncNavigatorPanelEvent& event)		{ postEvent(event); }
		virtual void leaveRegion(const CncNavigatorPanelEvent& event)		{ postEvent(event); }
		virtual void leftDownRegion(const CncNavigatorPanelEvent& event)	{ postEvent(event); }
		virtual void leftUpRegion(const CncNavigatorPanelEvent& event)		{ postEvent(event); }
		virtual void activateRegion(const CncNavigatorPanelEvent& event)	{ postEvent(event); }
		virtual void deactivateRegion(const CncNavigatorPanelEvent& event)	{ postEvent(event); }
		
	private:
		
		struct Current {
			Direction 	direction	= UD;
			bool		acitvated	= false;
		};
		
		struct MouseInfo {
			int			normalizedX	= 0;
			int 		normalizedY	= 0;
			bool 		leftDown	= false;
			bool 		leftUp		= false;
		};
		
		struct OuterCircleRegion {
			Direction 	direction	= UD;
			double 		startAngle	= 0.0;
			double 		midAngle	= 0.0;
			double 		stopAngle	= 0.0;
		};
		
		typedef std::vector<OuterCircleRegion> OuterRegions;
		
		CncNavigatorPanelEvent*	navEvent;
		wxRect 					navRectangle;
		int 					innerRadius;
		int 					outerRadius;
		OuterRegions 			outerRegions;
		Config 					config;
		Current					current;
		
		CncNavigatorPanelEvent& getEvent(int id = 0); 
		double adjustAngle(double angle, double dx, double dy);
		void onMouse(const MouseInfo& mi);
		void postEvent(const CncNavigatorPanelEvent& event);
	
		void onPaint(wxPaintEvent& event);
		void onMouse(wxMouseEvent& event);
		void onSize(wxSizeEvent& event);
		void onKeyDown(wxKeyEvent& event);
		void onEnter(wxMouseEvent& event);
		void onLeave(wxMouseEvent& event);
		void onSetFocus(wxFocusEvent& event);
		void onKillFocus(wxFocusEvent& event);
		void onEraseBackground(wxEraseEvent& event);
		
		wxDECLARE_NO_COPY_CLASS(CncNavigatorPanel);
		wxDECLARE_EVENT_TABLE();
};

// ----------------------------------------------------------------------------
class CncNavigatorPanelEvent : public wxCommandEvent {
	
	public:
		
		enum Id {
			CNP_COORDINATES 		= 100,
			CNP_ENTER_PANEL			= 200, 
			CNP_LEAVE_PANEL			= 201,
			CNP_SET_FOCUS			= 202, 
			CNP_KILL_FOCUS			= 203,
			CNP_ENTER_REGION		= 300, 
			CNP_LEAVE_REGION		= 301,
			CNP_LEFT_DOWN_REGION	= 400,
			CNP_LEFT_UP_REGION		= 401,
			CNP_ACTIVATE_REGION		= 500,
			CNP_DEACTIVATE_REGION	= 501
		};
		
		static const char* getEventIdAsString(Id id) {
			switch ( id ) {
				case CNP_COORDINATES:				return "CNP_COORDINATES";
				case CNP_ENTER_PANEL:				return "CNP_ENTER_PANEL";
				case CNP_LEAVE_PANEL:				return "CNP_LEAVE_PANEL";
				case CNP_SET_FOCUS:					return "CNP_SET_FOCUS";
				case CNP_KILL_FOCUS:				return "CNP_KILL_FOCUS";
				case CNP_ENTER_REGION:				return "CNP_ENTER_REGION";
				case CNP_LEAVE_REGION:				return "CNP_LEAVE_REGION";
				case CNP_LEFT_DOWN_REGION:			return "CNP_LEFT_DOWN_REGION";
				case CNP_LEFT_UP_REGION:			return "CNP_LEFT_UP_REGION";
				case CNP_ACTIVATE_REGION:			return "CNP_ACTIVATE_REGION";
				case CNP_DEACTIVATE_REGION:			return "CNP_DEACTIVATE_REGION";
			}
			
			return "CNP_???";
		}
		
		CncNavigatorPanelEvent(wxEventType eventType = wxEVT_CNC_NAVIGATOR_PANEL, int id = 0) 
		: wxCommandEvent(eventType, id)
		, radius(0.0)
		, angle(0.0)
		, mouseX(0)
		, mouseY(0)
		, direction(CncNavigatorPanel::Direction::UD)
		, activated(false)
		{}
		
		explicit CncNavigatorPanelEvent(const CncNavigatorPanelEvent& event) 
		: wxCommandEvent(event)
		, radius(event.radius)
		, angle(event.angle)
		, mouseX(event.mouseX)
		, mouseY(event.mouseY)
		, direction(event.direction)
		, activated(event.activated)
		{}
		
		virtual ~CncNavigatorPanelEvent() {
		}
		
		virtual wxEvent *Clone() const {
			return new CncNavigatorPanelEvent(*this);
		}
		
		void reset() {
			radius		= 0.0;
			angle		= 0.0;
			mouseX		= 0;
			mouseY		= 0;
			direction	= CncNavigatorPanel::Direction::UD;
			activated	= false;
		}
		
		const CncNavigatorPanelEvent* getNavigatorPanel() const { return static_cast<CncNavigatorPanelEvent*>(GetEventObject()); }
		
		double 							radius;
		double 							angle;
		
		int 							mouseX;
		int 							mouseY;
		
		CncNavigatorPanel::Direction	direction;
		bool							activated;
		
};

#endif