#ifndef GLOBAL_STRINGS_H
#define GLOBAL_STRINGS_H

#include "wx/string.h"
#include "Version.h"

////////////////////////////////////////////////////////////////////
namespace VersionInfo {

	const wxString major			= CNC_VERSION_MAJOR_STR;
	const wxString minor			= CNC_VERSION_MINOR_STR;
	const wxString index			= CNC_VERSION_INDEX_STR;

	const wxString text 			= "";
	const wxString number			= CNC_VERSION_STR;
};

////////////////////////////////////////////////////////////////////
struct GlobalConstStringDatabase {
	
	#ifdef DEBUG
		const wxString buildFlag		= wxString("d");
	#else
	
		#ifdef GPROF
			const wxString buildFlag	= wxString("g");
		#else
			const wxString buildFlag	= wxString("r");
		#endif
		
	#endif

	// common
	const wxString programTitel			= wxString(CNC_DESCRIPTION_STR);
	const wxString copyRight			= wxString(CNC_COPYRIGHT_STR);
	const wxString versionNumber		= VersionInfo::number;
	const wxString programVersion		= wxString(wxString::Format("%s.%s", versionNumber, buildFlag));
	
	// config
	const wxString renderSelectorFormat = wxString("%0.3lf mm - %u PPI");
	
	// position spy
	const wxString posSpyRefFormat		= wxString("%+08ld");
	const wxString pathListRefFormat	= wxString("%+08ld");
	const wxString moveSeqRefFormat		= wxString("%+08ld");
	const wxString gcodeSeqRefFormat	= wxString("%+08ld");
	const wxString vertexTraceFormat	= wxString("%+08ld");
	
};

#endif
