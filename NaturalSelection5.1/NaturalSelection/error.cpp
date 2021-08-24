#include<iostream>
#include "error.h"
#include "constants.h"

//using namespace traits;

void Error::msg() const
{
	cout <<endl <<"BaseError Catched";
}

StrengthError::StrengthError(const int ervalue_, const int trait_type_)
{
	ervalue = ervalue_;
	trait_type = trait_type_;
}

void StrengthError::msg() const
{
	//cout << "err:StrengthError Catched" << " in" << " with value " << ervalue << endl;
	cout <<endl<< "err:StrengthError Catched" << " in trait \'" 
		<< traits::trait_name[trait_type] << "\' with value " << ervalue ;
	//exit(0);
}

void notInEnvironmentError::msg() const
{
	//cout << "err:StrengthError Catched" << " in" << " with value " << ervalue << endl;
	cout << endl << "err::notInEnvironment Catched , Object not inside any Environment";
	//exit(0);
}

 