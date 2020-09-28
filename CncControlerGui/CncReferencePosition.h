#ifndef CNCREFERENCEPOSITION_H
#define CNCREFERENCEPOSITION_H

#include "wxCrafterReferencePosition.h"
#include "CncControl.h"
#include "CncNavigatorPanel.h"

class CncReferencePosition : public CncReferencePositionBase
{
	public:
		CncReferencePosition(wxWindow* parent);
		virtual ~CncReferencePosition();
		
		void setMessage(const wxString& msg);
		void setMeasurePlateThickness(const double mpt);

		CncRefPositionMode getReferenceMode();
		void shiftReferenceMode();
		double getWorkpieceThickness();
		
		bool shouldZeroX() 	{ return m_btZeroX->GetValue(); }
		bool shouldZeroY() 	{ return m_btZeroY->GetValue(); }
		bool shouldZeroZ() 	{ return m_btZeroZ->GetValue(); }
	
	protected:
		virtual void selectStepMode(wxCommandEvent& event);
		virtual void onInfoTimer(wxTimerEvent& event);
		virtual void selectInformation(wxMouseEvent& event);
		virtual void selectStepSensitivity(wxCommandEvent& event);
		virtual void init(wxInitDialogEvent& event);
		virtual void show(wxShowEvent& event);
		virtual void cancel(wxCommandEvent& event);
		virtual void set(wxCommandEvent& event);
		virtual void mode1(wxCommandEvent& event);
		virtual void mode2(wxCommandEvent& event);
		virtual void mode3(wxCommandEvent& event);
		virtual void mode4(wxCommandEvent& event);
		virtual void mode5(wxCommandEvent& event);
		virtual void mode6(wxCommandEvent& event);
		
		virtual void toggleZeroX(wxCommandEvent& event) 	{ determineZeroMode(); }
		virtual void toggleZeroY(wxCommandEvent& event) 	{ determineZeroMode(); }
		virtual void toggleZeroZ(wxCommandEvent& event) 	{ determineZeroMode(); }

		void onNavigatorPanel(CncNavigatorPanelEvent& event);
		
		short evaluateMode();
		void setMode(short mode);
		
	private:
		
		CncNavigatorPanel* navigationPanel;
		wxString infoMessage;
		
		bool isWorkpieceThicknessNeeded();
		void determineZeroMode();
		void showInformation();
};
#endif // CNCREFERENCEPOSITION_H
