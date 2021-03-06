//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2013 by Eran Ifrah
// file name            : cl_aui_dock_art.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef CLAUIDOCKART_H
#define CLAUIDOCKART_H

#include <wx/window.h>
#include <wx/aui/framemanager.h>
#include <wx/colour.h>
#include <wx/dcgraph.h>
#include <wx/dc.h>
#include <wx/gdicmn.h>
#include <wx/aui/dockart.h>
#include <wx/aui/auibar.h>

class clAuiDockArt : public wxAuiDefaultDockArt {
	
	private:
		
		wxBitmap m_dockCloseBmp;
		wxBitmap m_dockMoreBmp;
		wxBitmap m_dockExpandeBmp;
		wxBitmap m_dockMinimizeBmp;
		
		static wxString wxAuiChopText(wxDC& dc, const wxString& text, int max_size);
		static bool GetGCDC(wxDC& dc, wxGCDC& gdc);
	
	public:
		clAuiDockArt();
		virtual ~clAuiDockArt();
		
		virtual void DrawBorder(wxDC& dc, wxWindow* window, const wxRect& rect, wxAuiPaneInfo& pane);
		virtual void DrawCaption(wxDC& dc, wxWindow *window,
								 const wxString& text,
								 const wxRect& rect,
								 wxAuiPaneInfo& pane);

		virtual void DrawPaneButton(wxDC& dc, wxWindow *window,
									int button,
									int button_state,
									const wxRect& _rect,
									wxAuiPaneInfo& pane);
		virtual void DrawBackground(wxDC& dc, wxWindow* window, int orientation, const wxRect& rect);
		
		virtual void DrawSash(wxDC& dc, wxWindow* window, int orientation, const wxRect &rect);
};

#endif // CLAUIDOCKART_H
