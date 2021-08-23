#include<iostream>
#include "artimal.h"
//#include<random>
#include "constants.h"
#include "range.h"
#include "error.h"
#include "calc.h"
//
#include "environment.h"

typedef Range Trait;
using namespace randoms;
using namespace calcc;
using namespace movement;



//Artimal object API's
int Artimal::num = 0;
Artimal::Artimal() :
	size(INITIAL_SIZE + random_upto(INITIAL_SIZE_VARIATION), SIZE, SIZE_LIMIT),
	speed(INITIAL_SPEED + random_upto(INITIAL_SPEED_VARIATION), SPEED, SPEED_LIMIT),
	sense(INITIAL_SENSE + random_upto(INITIAL_SENSE_VARIATION), SENSE, SENSE_LIMIT),
	energy(INITIAL_ENERGY + random_upto(INITIAL_ENERGY_VARIATION), ENERGY, ENERGY_LIMIT),
	reproductivity(INITIAL_REPRODUCTIVITY + random_upto(INITIAL_REPRODUCTIVITY_VARIATION), REPRODUCTIVITY, REPRODUCTIVITY_LIMIT),
	age(INITIAL_AGE + random_upto(INITIAL_AGE_VARIATION), AGE, AGE_LIMIT + random_upto(DEATH_AGE_VARIATION)),
	loc(Location(-1, -1)), movement(random_to(MOVEMENT_PER_TIMESTEP)), movement_to_reproduce(random_to(MOVEMENT_PER_REPRODUCE))
{
	rR = INITIAL_rR;
	//loc=nullptr;
	
	 num++;
}

Artimal::Artimal(int size_, int speed_,int sense_,int energy_,int reproductivity_,int age_,int movement_,int movement_to_reproduce_) : 
size(size_, SIZE, SIZE_LIMIT), 
speed(speed_, SPEED, SPEED_LIMIT),
sense(sense_, SENSE, SENSE_LIMIT),
energy(energy_, ENERGY, ENERGY_LIMIT),
reproductivity(reproductivity_, REPRODUCTIVITY, REPRODUCTIVITY_LIMIT),
age(age_) ,loc(Location(-1, -1)),movement(movement_),movement_to_reproduce(movement_to_reproduce_)
{
	rR = INITIAL_rR ;
	//loc=nullptr;
	
	 num++;
}
Artimal::Artimal(const Artimal& a):size(a.Size(), SIZE, SIZE_LIMIT),
speed(a.Speed(), SPEED, SPEED_LIMIT),sense(a.Sense(),SENSE,SENSE_LIMIT),
energy(a.Energy(), ENERGY, ENERGY_LIMIT),
reproductivity(a.Reproductivity(),REPRODUCTIVITY,REPRODUCTIVITY_LIMIT), 
age(a.Age(), AGE, AGE_LIMIT), loc(a._location()),movement(a.movement),movement_to_reproduce(a.movement_to_reproduce)
{
	rR = a.return_rR();
	history = a.history;
	num++;
}
Artimal::Artimal(const Traits& t) : 
size(t.Size_range()),
speed(t.Speed_range()),sense(t.Sense_range()) ,age(AGE_TRAIT_INIIALIZED,AGE,AGE_LIMIT),
energy(INITIAL_ENERGY,ENERGY,ENERGY_LIMIT),  reproductivity(INITIAL_REPRODUCTIVITY,REPRODUCTIVITY,REPRODUCTIVITY_LIMIT)
, loc(Location(-1, -1)),movement(0),movement_to_reproduce(0)
{
	
	rR = 1;
	//loc=nullptr;
	
	 num++;
} 
void Artimal::display_all()
{
	std::cout <<std::endl<< "Object Properties Summarized(Artimal):";
	std::cout << std::endl << "Age:" << ((*this).Age());
	std::cout << std::endl << "Size:" << ((*this).Size());
	std::cout << std::endl << "Speed:" << ((*this).Speed());
	std::cout << std::endl << "Sense:" << ((*this).Sense());
	std::cout << std::endl << "Energy:" << ((*this).Energy());
	std::cout << std::endl << "probab:" << sigmoid(float(Sense()) / float(SENSE_LIMIT));
	std::cout << std::endl << "Reproductivity:" << ((*this).Reproductivity());
}
Traits  Artimal::return_traits() //Traits object used to initialize Artimal
{
	return Traits::Traits((*this).Size(), (*this).Speed(), (*this).Sense());
}
Location Artimal::location() const
{

	try
	{
		//if (loc == nullptr) throw notInEnvironmentError();
		
		if (loc.x_coor()==-1 || loc.y_coor() ==-1) throw notInEnvironmentError();
		//exit(0);
		return ((*this).loc);
	}
	catch (const notInEnvironmentError& ee)
	{
		ee.msg();
		return ((*this).loc);
	}

}

bool Artimal::set_location(Environment* env , int x_,int y_)
{
	try 
	{
		//loc = new Location(x_, y_);
		if (x_ > env->x_limit() || y_ > env->y_limit() || x_<0 || y_<0) throw Error();
		loc =  Location(x_, y_);

		return 1;
		//return *loc;
	}
	///*
	catch(Error e)
	{
		e.msg();
		return 0;
	}
	//*/
}
bool Artimal::willReproduce()
{
   return ((energy.Strength() >= int(RATIO_TO_REPRODUCE *ENERGY_LIMIT)) && (!rR));
}

void Artimal::update_history(Environment &e)
{

	history.push_back(History(e,(*this)));
	cout << endl << "History Updated- No. of snaps:" << history.size() <<
		", age: " << history[history.size() - 1].Age() <<
		",  Energy: " << history[history.size() - 1].Energy() <<
		",  rR: " << history[history.size() - 1].rencentlyReproduced() <<
		",  location: " << history[history.size() - 1].Location().x_coor() << "," << history[history.size() - 1].Location().y_coor();
}
void Artimal::update_last_history(Environment &e)
{
	int i = history.size();
	history.pop_back();
	history.push_back(History(e, (*this)));
	cout << endl << "History Last Updated- No. of snaps:" << history.size()<<" Present ," <<i  << " Previous" <<
		", age: " << history[history.size() - 1].Age() <<
		",  Energy: " << history[history.size() - 1].Energy() <<
		",  rR: " << history[history.size() - 1].rencentlyReproduced() <<
		",  location: " << history[history.size() - 1].Location().x_coor() << "," << history[history.size() - 1].Location().y_coor();
}


void Artimal::display_history(Environment& e)
{
	int i = 1;
	for (History& h : history)
	{
		cout << endl << "step :" << i;
		cout << endl << "size:" << Size();
		cout << endl << "speed:" << Speed();
		
		cout << endl << "rR: " << (h.rencentlyReproduced()) ;
		cout << endl << "Age:" << (h.Age());
		cout << endl << "Energy:" << (h.Energy());
		cout << endl << "Location: x= " << (h.Location().x_coor()) << ", y= " << h.Location().y_coor() << endl;
		++i;
	}
}

//Trait object API's
Traits::Traits(): 
size(1000, SIZE, SIZE_LIMIT), 
speed(50, SPEED, SPEED_LIMIT),  
sense(50, SENSE, SENSE_LIMIT) 
{};

Traits::Traits(int size_, int speed_,int sense_) : 
size(size_, SIZE, SIZE_LIMIT), 
speed(speed_, SPEED, SPEED_LIMIT),
sense(sense_, SENSE, SENSE_LIMIT)
{};

Traits Traits::mutate(Environment & e)
{
	std::vector<float> normal_size = gaussian(e.return_artimals(), SIZE);	
	std::vector<float> normal_speed = gaussian(e.return_artimals(), SPEED);
	std::vector<float> normal_sense = gaussian(e.return_artimals(), SENSE);
	int i1 = random_to(normal_size.size()-1);
	//cout << endl << endl << "gaussian size : [ ";
	//for (float f : normal_size) cout << f << " ,";
	//cout << "\b ]";

	//cout << endl << endl << "gaussian speed : [ ";
	//for (float f : normal_speed) cout << f << " ,";
	//cout << "\b ]";

	//cout << endl << endl << "gaussian sense : [ ";
	//for (float f : normal_sense) cout << f << " ,";
	//cout << "\b ]";
	cout <<endl<<"LOOOOOOOOkKKKK"<< "1. " << normal_size[i1];
	int i2 = random_to(normal_speed.size()-1);
	int i3 = random_to(normal_sense.size()-1);
	int delta_size = (sd(e.return_artimals(),SIZE)!=0) ? (sqrt(SIZE_VARIANCE) * normal_size[i1]):(random_upto(SIZE_MUTATION));
	int delta_speed = (sd(e.return_artimals(), SPEED) != 0) ? (sqrt(SPEED_VARIANCE) * normal_speed[i2]): (random_upto(SPEED_MUTATION));
	int delta_sense = (sd(e.return_artimals(), SENSE) != 0) ? (sqrt(SENSE_VARIANCE) * normal_sense[i3]):(random_upto(SENSE_MUTATION));
	//cout <<endl<< "size: " << size.Strength() + delta_size << " sd: " << sd(e.return_artimals(), SIZE);
	//cout <<endl<< "speed: " << speed.Strength() + delta_speed<<" sd: "<<sd(e.return_artimals(),SPEED);
	//cout <<endl<< "sense: " << sense.Strength() + delta_sense << " sd: "<< sd(e.return_artimals(), SENSE);
	return Traits(size.Strength() + delta_size, speed.Strength() + delta_speed, sense.Strength()+delta_sense);
	

}


History::History(Environment & e,Artimal &a) :location(a.location()),
age(a.Age()), energy(a.Energy()), gen(1), rR(a.return_rR())
{
}
