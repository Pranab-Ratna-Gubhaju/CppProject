#include "calc.h"
using namespace calcc;

int cost(float size, float speed, float sense)
{
	float fac = 100000.0f;
	return fac * SIZE_SPEED_CONSTANT * ((size / SIZE_LIMIT) * (size / SIZE_LIMIT) * (size / SIZE_LIMIT)) *
		((speed / SPEED_LIMIT) * (speed / SPEED_LIMIT)) +
		(10.0f * SENSE_CONSTANT * (sense / SENSE_LIMIT));
}

int cost(Artimal& a)
{
	float fac = 100000.0f;
	float size = a.Size();
	float speed = a.Speed();
	float sense = a.Sense();
	return fac * SIZE_SPEED_CONSTANT* ((size /SIZE_LIMIT)* (size / SIZE_LIMIT) * (size / SIZE_LIMIT)) *
		((speed/SPEED_LIMIT) * (speed / SPEED_LIMIT))  +
		(10.0f*SENSE_CONSTANT * (sense/SENSE_LIMIT));

}
float competitive_value(int size_, int speed_)
{
	float fac = 100.0f;
	float size = size_;
	float speed = speed_;
	return fac * (speed / SPEED_LIMIT) * (size / SIZE_LIMIT) ;
}

float competitive_value(Artimal& a)
{
	float fac = 100.0f;
	float size = a.Size();
	float speed = a.Speed();
	return fac * (size / SIZE_LIMIT) * (speed / SPEED_LIMIT);
}


float sigmoid(float a)
{
	float x = a * (-SIGMOID_a);
	x += SIGMOID_b;
	return (1 / (1 + exp(x)));
}

float avg(std::vector<Artimal>&a,int i)
{
	float sum = 0;
	switch (i) 
	{
	case(SIZE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += a[i].Size();
		}
		return  sum / a.size();
	case(SPEED):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += a[i].Speed();
		}
		return  sum / a.size();
	case(SENSE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += a[i].Sense();
		}
		return  sum / a.size();	
	case(ENERGY):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += a[i].Energy();
		}
		return  sum / a.size();	
	case(AGE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += a[i].Age();
		}
		return  sum / a.size();


	}
}
float sd(std::vector<Artimal>&a,int i)
{
	float sum = 0;
	switch (i) 
	{
	case(SIZE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += (a[i].Size()-avg(a,SIZE))* (a[i].Size() - avg(a, SIZE));
		}
		return  sqrt(sum / a.size());
	case(SPEED):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += (a[i].Speed() - avg(a, SPEED)) * (a[i].Speed() - avg(a, SPEED));
		}
		return  sqrt(sum / a.size());
	case(SENSE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += (a[i].Sense() - avg(a, SENSE)) * (a[i].Sense() - avg(a, SENSE));
		}
		return  sqrt(sum / a.size());
	case(ENERGY):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += (a[i].Energy() - avg(a, ENERGY)) * (a[i].Energy() - avg(a, ENERGY));
		}
		return  sqrt(sum / a.size());
	case(AGE):
		for (int i = 0; i < a.size(); ++i)
		{
			sum += (a[i].Age() - avg(a, AGE)) * (a[i].Age() - avg(a, AGE));
		}
		return  sqrt(sum / a.size());


	}
}

std::vector<float> gaussian(std::vector<Artimal>& a, int i)
{
	std::vector<float> distribution;
	float sum = 0;
	switch (i)
	{
	case(SIZE):
		for (int i = 0; i < a.size(); ++i)
		{
			distribution.push_back((a[i].Size()-avg(a,SIZE))/sd(a,SIZE));
		}
		return  distribution;
	case(SPEED):
		for (int i = 0; i < a.size(); ++i)
		{
			distribution.push_back((a[i].Speed() - avg(a, SPEED)) / sd(a, SPEED));
		}
		return  distribution;
	case(SENSE):
		for (int i = 0; i < a.size(); ++i)
		{
			distribution.push_back((a[i].Sense() - avg(a, SENSE)) / sd(a, SENSE));
		}
		return  distribution;
	case(ENERGY):
		for (int i = 0; i < a.size(); ++i)
		{
			distribution.push_back((a[i].Energy() - avg(a, ENERGY)) / sd(a, ENERGY));
		}
		return  distribution;
	case(AGE):
		for (int i = 0; i < a.size(); ++i)
		{
			distribution.push_back((a[i].Age() - avg(a, AGE)) / sd(a, AGE));
		}
		return  distribution;


	}
}









