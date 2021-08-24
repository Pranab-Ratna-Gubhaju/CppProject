#ifndef RANGE
#define RANGE

const int STRENGTH_LIMIT = 1000;

class Range
{
private:
	int strength;
	int sl;
public:
	//Range(const int, const int = STRENGTH_LIMIT);
	Range(const int,const int = -1,const int = STRENGTH_LIMIT);  //value, trait_value, strength_limit
	//int Strength() { return strength; }
	int Strength() const { return strength; }
	void delta_change(int i) { strength = strength + i; if (strength < 0)  strength = 0; else if (strength > sl) strength = sl; }
	int limit() const;
	int operator++(int) { if (strength < sl)strength++; else strength=sl; return strength; }
	int operator++() { int temp = strength; if (strength < sl)strength++; else strength = sl;; return temp; }

};




#endif
