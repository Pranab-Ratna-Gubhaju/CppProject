#include<iostream>
#include "range.h"
#include "error.h"


Range::Range(const int strength_,const int T_V,const int S_L):sl(S_L)  //T_V is trait_value , S_L is STRENGTH_LIMIT
{
	
	try {
		if (strength_ > S_L || strength_ < 0) throw StrengthError(strength_, T_V);
		strength = strength_;
	}
	catch (const StrengthError& se)
	{
		se.msg();
		if(strength_>0)
		{
			std::cout << std::endl << "Strength set to maximum:";
			strength = S_L;
		}
		else
		{
			std::cout << std::endl << "Strength set to minimum:";
			strength = 0;
		}

		//exit(0);
	}
	catch (const Error& e)
	{
		e.msg();
	}
}
int Range::limit() const { return sl; }




