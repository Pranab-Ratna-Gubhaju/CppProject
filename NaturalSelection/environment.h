#include "range.h"
#include "artimal.h"
#include "constants.h"
#include<vector>
#include<sstream>

#ifndef ENVIRON
#define ENVIRON

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>


using namespace env; //uses env constants


//class Artimal;
class F_resource;
//class Location;
class Environment
{
private:
	//Grid
	int x;
	int y;
	//properties
	int temperature = 20;

public:
	//constains
	std::vector<Artimal>rabbits;
	std::vector<F_resource>foods;
	std::vector<Artimal> temp;

	std::vector<float>avg_size;	
	std::vector<float>avg_speed;
	std::vector<float>avg_sense;
	
	std::vector<float>num;

	std::vector<float>sd_size;
	std::vector<float>avg_age;
	//methods
	Environment(int = DEFAULT_POPULATION_ARTIMAL, int = DEFAULT_POPULATION_F_RESOURCE,
		int = DEFAULT_ENV_X, int = DEFAULT_ENV_Y);// arguments:num of artimals , num of food at begining ,grid (x) , grid(y)
	int x_limit() { return x; }
	int y_limit() { return y; }
	int n_artimals() { return (this->return_artimals().size()+temp.size()); }
	int n_foods() { return this->return_foods().size(); }


	void randomize_location();
	void random_move();
	void random_move2();
	void random_move3();
	void random_move4();

	float e_distance(Location, Location);
	int s_distance(Location, Location);

	bool See(Artimal&);		//returns true if there is food within visibility region
	std::vector<Location> seen_location(Artimal&);   // returns vector array of visible food location
	std::vector<Location> seen_nearest_location(Artimal&);
	std::vector<Location> seen_nearest_location_senseless(Artimal&);
	void devour(Artimal&, Location&);
	void Reproduce(Artimal&);

	void update_history();
	void display_history();


	void GrowFood();
	void GrowFood(int);
	
	void Startsim(int);
	void Startsim2(int);
	void Pausesim(){}
	void Stopsim(){}

	std::vector<Artimal>& return_artimals();
	std::vector<F_resource>& return_foods();
	~Environment();
	

};

class F_resource		//food resource
{
private:
	Range nutrient;
	static int num;
	Location loc;
	Location _location() const { return ((*this).loc); }

public:
	F_resource();							//not necessarily required
	F_resource(int);
	F_resource(const F_resource&);
	Location location() const;
	bool set_location(Environment*, int = 0, int = 0);
	int Nutrient() const { return nutrient.Strength(); }
	static void n_food() { std::cout << std::endl << "No. of f_resources:" << num; }
	~F_resource(); 

};



#endif
