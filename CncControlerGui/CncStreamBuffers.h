#ifndef CNC_STREAM_BUFFERS_H
#define CNC_STREAM_BUFFERS_H

#include <sstream>
#include <wx/textctrl.h>

///////////////////////////////////////////////////////////////////
class LoggerStreamBuf : public std::streambuf {
	
	private:
		char 				type;
		
	protected:
		
		wxTextCtrl* 		ctl;
		wxTextAttr 			textAttr;
		
	public:
		enum Type { STD = 'C', LOG = 'L', ERR = 'E', EX1 = '1', TRC = 'T', MSG = 'M', SPY = 'S' };
		
		static wxString 	startupBuffer;
		static wxTextAttr 	defaultAttr;
		
		///////////////////////////////////////////////////////////
		LoggerStreamBuf(char t, wxTextCtrl* c, const wxTextAttr& ta);
		virtual ~LoggerStreamBuf() {}
		
		virtual int overflow (int c = EOF);
		
		void setTextAttr(const wxTextAttr& ta);
		void setTextControl(wxTextCtrl* c);
		
		const wxTextAttr& getTextAttr() 	const 	{ return textAttr; }
		wxTextCtrl* getTextControl()		const 	{ return ctl; }
		void ungregisterTextControl() 				{ ctl = NULL; }
};

///////////////////////////////////////////////////////////
namespace StartupBuffer {
	
	void append(LoggerStreamBuf::Type t, const char* text);
	bool trace(wxTextCtrl* ctl);
	
};

///////////////////////////////////////////////////////////////////
class CncCoutBuf : public LoggerStreamBuf {
	public:
		///////////////////////////////////////////////////////////
		CncCoutBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::STD, c, wxTextAttr(wxColour(232, 232, 232))) {}
		virtual ~CncCoutBuf() {}
};

///////////////////////////////////////////////////////////////////
class CncClogBuf : public LoggerStreamBuf {
	public:
		CncClogBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::LOG, c, wxTextAttr(wxColour(0, 157, 157))) {}
		virtual ~CncClogBuf() {}
};

///////////////////////////////////////////////////////////////////
class CncCerrBuf : public LoggerStreamBuf {
	public:
		CncCerrBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::ERR, c, wxTextAttr(wxColour(255, 64, 64))) {}
		virtual ~CncCerrBuf() {}
};

///////////////////////////////////////////////////////////////////
class CncCex1Buf : public LoggerStreamBuf {
	public:
		CncCex1Buf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::EX1, c, wxTextAttr(wxColour(255, 201, 14))) {}
		virtual ~CncCex1Buf() {}
};

///////////////////////////////////////////////////////////////////
class CncCtrcBuf : public LoggerStreamBuf {
	public:
		CncCtrcBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::TRC, c, LoggerStreamBuf::defaultAttr) {}
		virtual ~CncCtrcBuf() {}
};

///////////////////////////////////////////////////////////////////
class CncCmsgBuf : public LoggerStreamBuf {
	public:
		CncCmsgBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::MSG, c, LoggerStreamBuf::defaultAttr) {}
		virtual ~CncCmsgBuf() {}
};

///////////////////////////////////////////////////////////////////
class CncCspyBuf : public LoggerStreamBuf {
	
	public:
		static wxTextAttr lineNumberAttr;
		
		//////////////////////////////////////////////////////////
		CncCspyBuf(wxTextCtrl* c) 
		: LoggerStreamBuf(LoggerStreamBuf::Type::SPY, c, LoggerStreamBuf::defaultAttr) {}
		
		//////////////////////////////////////////////////////////
		virtual ~CncCspyBuf() {}
		
		///////////////////////////////////////////////////////////
		virtual int overflow (int c = EOF);
		
		///////////////////////////////////////////////////////////
		int insertLineNumber(bool first = false);
};

///////////////////////////////////////////////////////////////////
class CncBasicLogStream : public std::stringstream {
	
	protected:
		LoggerStreamBuf* logStreamBuffer;
	
	public:
		//////////////////////////////////////////////////////////
		CncBasicLogStream() 
		: std::stringstream() 
		, logStreamBuffer(NULL)
		{}
		
		//////////////////////////////////////////////////////////
		virtual ~CncBasicLogStream() {
		}
		
		//////////////////////////////////////////////////////////
		void ungregisterTextControl() {
			if ( logStreamBuffer != NULL )
				logStreamBuffer->ungregisterTextControl();
		}
		
		//////////////////////////////////////////////////////////
		void setLogStreamBuffer(LoggerStreamBuf* lsb) {
			logStreamBuffer = lsb;
		}
		
		//////////////////////////////////////////////////////////
		void resetTextAttr() {
			setTextAttr(LoggerStreamBuf::defaultAttr); 
		}
		
		//////////////////////////////////////////////////////////
		void setTextAttr(const wxTextAttr& ta) {
			if ( logStreamBuffer != NULL )
				logStreamBuffer->setTextAttr(ta);
		}
		
		//////////////////////////////////////////////////////////
		void setTextColour(const wxColour& c) {
			if ( logStreamBuffer != NULL )
				logStreamBuffer->setTextAttr(c);
		}
		
		//////////////////////////////////////////////////////////
		const wxColour& getTextColour() const { 
			if ( logStreamBuffer != NULL )
				logStreamBuffer->getTextAttr().GetTextColour();
				
			return LoggerStreamBuf::defaultAttr.GetTextColour();
		}
		
		//////////////////////////////////////////////////////////
		void red() 		{ setTextColour(wxColour(255, 128, 128)); }
		void black() 	{ setTextColour(*wxBLACK); }
		void blue() 	{ setTextColour(wxColour(0, 162, 232)); }
		void green() 	{ setTextColour(wxColour(0, 128, 64)); }
		void white() 	{ setTextColour(*wxWHITE); }
		void gray() 	{ setTextColour(*wxLIGHT_GREY); }
};

///////////////////////////////////////////////////////////////////
class CncTraceLogStream : public CncBasicLogStream {
	
	protected:
		
		wxColour infoColour;
		wxColour warningColour;
		wxColour errorColour;
		
		///////////////////////////////////////////////////////////
		virtual void logMessage(const char* m) {
			clear();
			
			if ( m == NULL )
				return;
				
			wxString msg(m);
			msg.Replace("\n", " ", true);
			msg.Replace("\r", "", true);
			
			if ( getTextControl() != NULL )
				getTextControl()->AppendText(msg);
		}
		
		///////////////////////////////////////////////////////////
		wxTextCtrl* getTextControl() const {
			if ( logStreamBuffer != NULL )
				return logStreamBuffer->getTextControl();
				
			return NULL;
		}
		
	public:
		///////////////////////////////////////////////////////////
		CncTraceLogStream() 
		: CncBasicLogStream()
		, infoColour(*wxWHITE)
		, warningColour(255, 201, 14)
		, errorColour(*wxRED)
		{}

		///////////////////////////////////////////////////////////
		CncTraceLogStream(const CncTraceLogStream& ctb) 
		: CncBasicLogStream()
		, infoColour(*wxWHITE)
		, warningColour(255, 201, 14)
		, errorColour(*wxRED)
		{}

		///////////////////////////////////////////////////////////
		virtual ~CncTraceLogStream() 
		{}

		///////////////////////////////////////////////////////////
		void clear() {
			if ( getTextControl() != NULL ) {
				getTextControl()->Clear();
			}
		}
		
		///////////////////////////////////////////////////////////
		void logInfoMessage(const char* m) {
			if ( getTextControl() != NULL ) {
				getTextControl()->SetDefaultStyle(wxTextAttr(infoColour));
				logMessage(m);
			}
		}
		
		///////////////////////////////////////////////////////////
		void logWarningMessage(const char* m) {
			if ( getTextControl() != NULL ) {
				getTextControl()->SetDefaultStyle(wxTextAttr(warningColour));
				logMessage(m);
			}
		}
		
		///////////////////////////////////////////////////////////
		void logErrorMessage(const char* m) {
			if ( getTextControl() != NULL ) {
				getTextControl()->SetDefaultStyle(wxTextAttr(errorColour));
				logMessage(m);
			}
		}
		
		///////////////////////////////////////////////////////////
		void setInfoColour(const wxColour& c) 		{ infoColour = c; }
		void setWarningColour(const wxColour& c) 	{ warningColour = c; }
		void setErrorColour(const wxColour& c) 		{ errorColour = c; }
		
		///////////////////////////////////////////////////////////
		void logInfo(const char* m) 	{ logInfoMessage(m); }
		void logWarning(const char* m) 	{ logWarningMessage(m); }
		void logError(const char* m) 	{ logErrorMessage(m); }
		
		///////////////////////////////////////////////////////////
		void logInfoMessage(const std::stringstream& ss) 	{ logInfoMessage(ss.str().c_str()); }
		void logWarningMessage(const std::stringstream& ss)	{ logWarningMessage(ss.str().c_str()); }
		void logErrorMessage(const std::stringstream& ss) 	{ logErrorMessage(ss.str().c_str()); }
		void logInfo(const std::stringstream& ss) 			{ logInfoMessage(ss.str().c_str()); }
		void logWarning(const std::stringstream& ss)		{ logWarningMessage(ss.str().c_str()); }
		void logError(const std::stringstream& ss) 			{ logErrorMessage(ss.str().c_str()); }
		
		///////////////////////////////////////////////////////////
		const char* getCurrentMessage() const {
			if ( getTextControl() == NULL)
				return "";
				
			return getTextControl()->GetValue();
		}
};

///////////////////////////////////////////////////////////////////
class CncMsgLogStream : public CncTraceLogStream {
	
	protected:
		///////////////////////////////////////////////////////////
		virtual void logMessage(const char* m) {
			if ( m == NULL )
				return;
				
			if ( getTextControl() != NULL )
				getTextControl()->AppendText(m);
		}
		
	public:
		///////////////////////////////////////////////////////////
		CncMsgLogStream() 
		: CncTraceLogStream()
		{
			setInfoColour(*wxBLACK);
			setWarningColour(wxColour(128, 64, 0));
		}
		
		///////////////////////////////////////////////////////////
		CncMsgLogStream(const CncMsgLogStream& cmb) 
		: CncTraceLogStream()
		{
			setInfoColour(*wxBLACK);
		}

		///////////////////////////////////////////////////////////
		virtual ~CncMsgLogStream() 
		{}
};

///////////////////////////////////////////////////////////////////
class CncSerialSpyStream : public CncTraceLogStream {
	
	protected:
		///////////////////////////////////////////////////////////
		virtual void logMessage(const char* m) {
			if ( m == NULL )
				return;
				
			if ( getTextControl() != NULL )
				getTextControl()->AppendText(m);
		}
		
		///////////////////////////////////////////////////////////
		virtual void logTime(bool lineFeed = true) {
			wxDateTime now = wxDateTime::UNow();
			(*this) << now.Format(":: %H:%M:%S.%l");
			
			if ( lineFeed == true )
				(*this) << '\n';
		}
		
	public:
	
		static const char* hLine;
		static const char* mLine;
		///////////////////////////////////////////////////////////
		CncSerialSpyStream() 
		: CncTraceLogStream()
		{}

		///////////////////////////////////////////////////////////
		CncSerialSpyStream(const CncSerialSpyStream& cmb) 
		: CncTraceLogStream()
		{}

		///////////////////////////////////////////////////////////
		virtual ~CncSerialSpyStream() {
		}
		
		///////////////////////////////////////////////////////////
		void initializeResult() {
			wxColour c = getTextColour();
			blue();
			logTime(true);
			setTextColour(c);
		}
		///////////////////////////////////////////////////////////
		void addMarker(const wxString& mt) {
			wxColour c = getTextColour();
			red();
			(*this) <<  CncSerialSpyStream::mLine;
			(*this) << ":: " << mt << "\n";
			(*this) <<  CncSerialSpyStream::mLine;
			setTextColour(c);
		}
		
		///////////////////////////////////////////////////////////
		void enableMessage(const char* additional = NULL) {
			wxColour c = getTextColour();
			blue();
			(*this) <<  CncSerialSpyStream::hLine;
			logTime(false);
			(*this) << " Serial Spy enabled . . .\n";
			if ( additional != NULL ) (*this) << additional;
			(*this) <<  CncSerialSpyStream::hLine;
			setTextColour(c);
		}
		
		///////////////////////////////////////////////////////////
		void disableMessage(const char* additional = NULL) {
			wxColour c = getTextColour();
			blue();
			(*this) <<  CncSerialSpyStream::hLine;
			logTime(false);
			(*this) << " Serial Spy disabled . . .\n";
			if ( additional != NULL ) (*this) << additional;
			(*this) <<  CncSerialSpyStream::hLine;
			setTextColour(c);
		}
		
		///////////////////////////////////////////////////////////
		void finalizeOK(const char* msg = NULL) {
			wxColour c = getTextColour();
			green();
			if ( msg != NULL )
				(*this) << msg;
				
			(*this) << "OK\n";
			(*this) <<  CncSerialSpyStream::hLine;
			setTextColour(c);
		}
		
		///////////////////////////////////////////////////////////
		void finalizeERROR(const char* msg = NULL ) {
			wxColour c = getTextColour();
			red();
			
			if ( msg != NULL )
				(*this) << msg;
				
			(*this) << "ERROR\n";
			(*this) <<  CncSerialSpyStream::hLine;
			setTextColour(c);
		}
};

#endif