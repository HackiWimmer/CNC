#ifndef TEST_CNC_PATH_LIST_MANAGER_H
#define TEST_CNC_PATH_LIST_MANAGER_H

#include "Test_Base.h"
#include "PathHandlerBase.h"

////////////////////////////////////////////////////////////////////////////
class TEST_CNC_PATH_LIST_MANAGER : public TEST_BASE {
	
	public:
		////////////////////////////////////////////////////////////////////
		TEST_CNC_PATH_LIST_MANAGER(UnitTests* frame)
		: TEST_BASE(frame)
		{}
		
		////////////////////////////////////////////////////////////////////
		virtual ~TEST_CNC_PATH_LIST_MANAGER() {}
		
		////////////////////////////////////////////////////////////////////
		virtual const char* name() { return "TEST_CNC_PATH_LIST_MANAGER"; }
		
	protected:
		////////////////////////////////////////////////////////////////////
		virtual bool runTest() {
			CncPathListManager plm;

			/*
			// set start position
			plm.setStartPos({10.0, 15.0});
			
			// calculate first move
			*/
			/*
			// setup path points
			for ( unsigned int i=0; i<10; i++ )
				plm.calculateAndAddEntry({plm.getStartPos().getX() + i*10.0,
				                          plm.getStartPos().getY() + i*20.0,
										  plm.getStartPos().getZ() + i},
										  true, (i != 0)
										);
			
			// trace initial behaviour
			std::clog << plm << std::endl;
			
			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "Erase first entry - result: " << plm.eraseEntryAndRecalcuate(plm.begin()) << endl;
			if ( plm.getPathListSize() != size - 1)
				cerr << "Size isn't decremented!" << endl;
				
			clog << plm << endl;
			
			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "Erase last entry - result: " << plm.eraseEntryAndRecalcuate(plm.end() - 1) << endl;
			if ( plm.getPathListSize() != size - 1)
				cerr << "Size isn't decremented!" << endl;
				
			clog << plm << endl;
			
			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "Erase the 4. entry - result: " << plm.eraseEntryAndRecalcuate(plm.begin() + 4) << endl;
			if ( plm.getPathListSize() != size - 1)
				cerr << "Size isn't decremented!" << endl;
				
			clog << plm << endl;
			
			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "Error case: Erase entry == begin - 1 - result: " << plm.eraseEntryAndRecalcuate(plm.begin() - 1) << endl;
			if ( plm.getPathListSize() != size - 1)
				cerr << "Size isn't decremented!" << endl;
				
			clog << plm << endl;

			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "Error case: Erase entry == end - result: " << plm.eraseEntryAndRecalcuate(plm.end()) << endl;
			if ( plm.getPathListSize() != size - 1)
				cerr << "Size isn't decremented!" << endl;
				
			clog << plm << endl;
			
			PARAGRAPH();
			size = plm.getPathListSize();
			clog << "reverse path: " << plm.reversePath() << endl;
			if ( plm.getPathListSize() != size )
				cerr << "Somthing is lost . . ." << endl;
				
			clog << plm << endl;
			*/
			return true;
		}
};

#endif
