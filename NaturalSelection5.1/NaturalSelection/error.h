#ifndef ERROR
#define ERROR
#include<iostream>



using std::cout;
using std::endl;


class Error
{
private:
public:
	virtual void msg() const;
};

class StrengthError :public Error
{
private:
	int ervalue;//error value
	int trait_type;
public:
	StrengthError(const int ervalue_, const int trait_type_);
	void msg() const;
};

class notInEnvironmentError :public Error
{
private:

public:
	//StrengthError(const int ervalue_, const int trait_type_);
	void msg() const;
};


#endif
