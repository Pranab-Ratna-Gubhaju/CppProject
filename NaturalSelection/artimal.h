#include<iostream>
#include<ctime>
#include<random>
#include "range.h"
#include "constants.h"
#include "error.h"

#ifndef ARTIMAL             // aka Artificial Animal
#define ARTIMAL


/*#####   CONATAINS ARTIMAL AND TRAIT CLASS 
#######*/

typedef Range Trait;
using namespace traits;

class Environment;
class Traits;
class History;
class Artimal
{
	
private:
	Trait size;
	Trait speed;
	Trait sense;

	Range reproductivity;//
	Range energy;//
	Range age;			//
	Location loc;
	bool rR ; //recentlyReproduced
	static int num;
	Location _location() const{ return ((*this).loc); }

	int movement;
	int movement_to_reproduce;
	
	
public:

	std::vector<History> history;
	Artimal();							//not necessarily required
	Artimal(int size_,int speed_,int sense_,int energy_,int reproductivity_,int age_,int movement_,int movement_to_reproduce);		//not necessarily required
	Artimal(const Traits&);
	Artimal(const Artimal&);
	Traits return_traits();
	Location location() const;
	bool set_location(Environment*,int=0,int=0 );
	//Location set_location(int=0,int=0 );

	int Size() const { return size.Strength(); }
	int Speed() const { return speed.Strength(); }
	int Sense() const { return sense.Strength(); }

	int Movement() const { return movement; }
	int Movement_to_reproduce() const { return movement_to_reproduce; }

	int Energy() const { return energy.Strength(); }
	void delta_Energy(int i) { energy.delta_change(i); }
	int Reproductivity() const { return reproductivity.Strength(); }
	int Age() const { return age.Strength(); }		//
	Range& Age_range()  { return age; }
	
	bool return_rR() const { return rR; }
	void set_Recently_Reproduced() { rR = 1; }
	void clear_Recently_Reproduced() { rR = 0; }
	bool willReproduce();
	void display_all();

	void update_history(Environment& e);
	void update_last_history(Environment& e);
	void display_history(Environment& e);
	static void n_artimal() { std::cout << std::endl << "No. of artimals:" << num; } //returns number of artimal objects created

	
	void increase_movement() { ++movement; }
	void increase_movement_to_reproduce() { ++movement_to_reproduce; }
	void clear_movement_to_reproduce() { movement_to_reproduce = 0; }


	~Artimal() {/*delete loc;*/ num--; }
};									   

class Traits  //collection of traits that can be used to initialize artimal objects
{
private:
	Trait size;
	Trait speed;
	Trait sense;
	//Trait sense;
public:
	Traits();
	Traits(int size_, int speed_, int sense_);
	const Trait Size_range() const { return size; }
	const Trait Speed_range() const { return speed; }
	const Trait Sense_range() const { return sense; }
	int Size() const { return size.Strength(); }
	int Speed() const { return speed.Strength(); }
	int Sense() const { return sense.Strength(); }
	//const int Size () { return size.Strength(); }
	//const int Speed () { return speed.Strength(); }

	Traits mutate(Environment& );

};

class History
{
private:
	int gen;
	Location location;
	int energy;
	int age;
	int rR;
	static int num;
public:
	History(Environment& e,Artimal &a);
	int Energy() const { return energy; }
	int Age()  { return age; }
	int rencentlyReproduced() { return rR; }
	Location Location() const { return location; }
	void genUp()  { gen++; }
	
};




#endif // !ART_ANIMAL

