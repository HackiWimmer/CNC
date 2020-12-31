#ifndef BIN_PARSE_HANDLER_BASE_H
#define BIN_PARSE_HANDLER_BASE_H

#include <map>
#include <sstream>
#include "CncCommon.h"
#include "CncCommandDecoder.h"
#include "PathHandlerBase.h"

typedef cnc::LineNumberTranslater LineNumberTranslater;

///////////////////////////////////////////////////////////////////////////////////////////
class BinaryPathHandlerBase : public PathHandlerBase {
	
	private:
		
		LineNumberTranslater	lineNumberTranslater;
		unsigned long			totalLineNumberOffset;
		unsigned long			lineNumberCounter;
		
	protected:
		
		virtual bool			processLinearMove(bool alreadyRendered) { return true; }
		void					resetLineNumberTranslation();
		void					translateLineNumber(unsigned long offset);
		
	public:
		BinaryPathHandlerBase();
		virtual ~BinaryPathHandlerBase();
		
		virtual const char*		getName() const { return "BinaryPathHandlerBase"; }
		
		// common interface
		virtual bool			processCommand(const unsigned char* buffer, int nbBytes) { return true; };
		
		// view interface
		virtual const wxString& getViewContent(wxString& content) 		{ return content; }
		const cnc::LineNumberTranslater& getLineNumberTranslater() 		{ return lineNumberTranslater; }
};

///////////////////////////////////////////////////////////////////////////////////////////
class BinaryPathHandlerHexView : public BinaryPathHandlerBase {
	
	public:
		enum FormatType {Raw, CStyle};
	
	private:
		std::stringstream hexContent;
		FormatType formatType;
		
	public:
		
		explicit BinaryPathHandlerHexView(FormatType ft = FormatType::Raw);
		virtual ~BinaryPathHandlerHexView() {}
		
		virtual bool prepareWork(); 
		virtual bool finishWork();
		
		virtual bool processCommand(const unsigned char* buffer, int nbBytes);
		
		virtual const wxString& getViewContent(wxString& content) { content.assign(hexContent.str()); return content; }
};

///////////////////////////////////////////////////////////////////////////////////////////
class BinaryPathHandlerHumanReadableView : public BinaryPathHandlerBase 
										 , public CncCommandDecoder::CallbackInterface
{
	
	public:
		enum FormatType {Steps, Metric};

	private:
		std::stringstream readableContent;
		FormatType formatType;
		
		bool displaySetter(const unsigned char* buffer, int nbBytes);
		bool displaySteps(const unsigned char* buffer, int nbBytes);
		bool displayMetric(const unsigned char* buffer, int nbBytes);
		
		bool displayMoveSequence(const unsigned char* buffer, int nbBytes);
		
	public:
		
		explicit BinaryPathHandlerHumanReadableView(FormatType ft);
		virtual ~BinaryPathHandlerHumanReadableView() {}
		
		virtual void notifyMove(int32_t dx, int32_t dy, int32_t dz);

		virtual void notifyMoveSequenceBegin(const CncCommandDecoder::MoveSequenceInfo& sequence);
		virtual void notifyMoveSequenceNext(const CncCommandDecoder::MoveSequenceInfo& sequence);
		virtual void notifyMoveSequenceEnd(const CncCommandDecoder::MoveSequenceInfo& sequence);

		virtual bool prepareWork(); 
		virtual bool finishWork();
		
		virtual bool processCommand(const unsigned char* buffer, int nbBytes);

		virtual const wxString& getViewContent(wxString& content) { content.assign(readableContent.str()); return content; }
};

#endif