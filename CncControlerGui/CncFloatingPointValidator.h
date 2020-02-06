#ifndef CNC_FLOAT_VALIDATOR_H
#define CNC_FLOAT_VALIDATOR_H

#include <wx/event.h>
#include <wx/utils.h> 
#include <wx/textentry.h>
#include <wx/valnum.h>


class CncFloatingPointValidator : public wxFloatingPointValidator<float>  {
	
	protected:

		float minValue;
		float maxValue;

	public:

		CncFloatingPointValidator(int precision, float *value = NULL, int style = wxNUM_VAL_DEFAULT);
		~CncFloatingPointValidator();

		float getMin() { return minValue; }
		float getMax() { return maxValue; }

		void SetMin(ValueType min);
		void SetMax(ValueType max);
		void SetRange(ValueType min, ValueType max);
};

#endif
