#include "artimal.h"

#ifndef CALC
#define CALC

int cost(float size_, float speed_, float sense_);
int cost(Artimal&);
float competitive_value(float size_, float speed_);
float competitive_value(Artimal& a);
float avg(std::vector<Artimal>&,int );
float sd(std::vector<Artimal>&, int);
std::vector<float> gaussian(std::vector<Artimal>& a, int i);
float sigmoid(float);





#endif