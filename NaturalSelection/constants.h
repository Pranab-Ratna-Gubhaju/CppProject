
//#include "environment.h"
#ifndef CONST
#define CONST

//##############################################   TRAITS OFF    ################################################################################
/*
namespace calcc
{
	const int GEN_NO = 30;
	const int SENSE_CONSTANT = 50;
	const float SIZE_SPEED_CONSTANT = 3.0f;
	const float RATIO_TO_REPRODUCE = 0.6f;
	//const int LINEAR_FOOD_GROWTH =30;
	//const int LINEAR_FOOD_GROWTH =15;
	const int LINEAR_FOOD_GROWTH =15;

	const int NUTRIENT_TO_ENERGY = 100;
	const int BIRTHS_POSSIBLE = 3;
	const int TIME_STEP_FOR_FOOD_GROWTH =1;

	const int SIZE_MUTATION = 0;
	const int SPEED_MUTATION = 0;
	const int SENSE_MUTATION = 0;

	//const float SIZE_VARIANCE = 625.0f;
	const float SIZE_VARIANCE = 0.0f;
	//const float SPEED_VARIANCE = 12.0f;
	const float SPEED_VARIANCE = 0.0f;
	//const float SENSE_VARIANCE = 25.0f;
	const float SENSE_VARIANCE = 0.0f;

	const float SIGMOID_a = 8.0f;
	const float SIGMOID_b = +3.0f;
}
namespace movement
{
	//
	const int timestep_per_time = 1;
	const int MOVEMENT_PER_TIMESTEP = 5; // move 5 times each timesteps
	//
	const int MOVEMENT_PER_AGE = 10;   // increase age after 10 random movements
	const int MOVEMENT_PER_REPRODUCE = 8 ;
	//
	const int timestep_per_age = MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP;   // increase age after 2 timesteps
	//
}

namespace env
{
	const int INITIAL_NUTRIENT = 5;
	const int NUTRIENT_LIMIT = 10;
	const int DEFAULT_ENV_X = 5;
	const int DEFAULT_ENV_Y = 5;
	const int DEFAULT_POPULATION_ARTIMAL = 10;
	const int DEFAULT_POPULATION_F_RESOURCE = 20;
}

namespace traits
{

	const int NUM_TRAITS =3;
	const int SIZE_LIMIT = 2000;
	const int SPEED_LIMIT = 200;
	const int SENSE_LIMIT = 300;
	const int AGE_LIMIT = 15;
	const int ENERGY_LIMIT = 6000;		//
	const int REPRODUCTIVITY_LIMIT = 100;
	const int INITIAL_SIZE = (SIZE_LIMIT / 4);
	const int INITIAL_SPEED = (SPEED_LIMIT / 4);
	const int INITIAL_SENSE = (SENSE_LIMIT/3);
	const int INITIAL_ENERGY = (ENERGY_LIMIT / 3);
	const int INITIAL_REPRODUCTIVITY = (REPRODUCTIVITY_LIMIT / 2);	//__________________________________
	const bool INITIAL_rR = 0;

	const int INITIAL_AGE = (AGE_LIMIT / 2);		//
	const int AGE_TRAIT_INIIALIZED = 0;		//
	const int MOVE_STEP_LENGTH = 1;                          ///Const
	const int VISIBILITY_RADIUS = 3*MOVE_STEP_LENGTH ;





	const int NUM_TRAITS_ENUM = 7;
	const enum trait_value { SIZE, SPEED, SENSE , ENERGY , REPRODUCTIVITY ,AGE , NUTRIENT };  //dont change
	const char*const trait_name[NUM_TRAITS_ENUM] = { "Size","Speed","Sense","Energy","Reproductivity","Nutrient" };


}
namespace randoms
{
	const int INITIAL_SIZE_VARIATION = 0;
	const int INITIAL_SPEED_VARIATION = 0;
	//const int INITIAL_SPEED_VARIATION = 2;

	const int INITIAL_SENSE_VARIATION = 0;
	const int INITIAL_ENERGY_VARIATION = 200;
	const int INITIAL_REPRODUCTIVITY_VARIATION = 5;   //________________________
	const int INITIAL_AGE_VARIATION = 2;
	const int DEATH_AGE_VARIATION = 1;

	const int INITIAL_NUTRIENT_VARIATION = 1;
	const int MUTATION_SIZE_STRENGTH = 10;
	const int MUTAION_SPEED_STRENGTH = 4;
}

const int random_upto(const int n_);  // outputs random number from -n_ to +n_
const int random_to(const int n_);  // outputs random number from 0 to +n_
//const float Energy(int speed_, )





class Location
{
private:
	int x;
	int y;
public:
	Location(int x_, int y_) :x(x_), y(y_) {}
	int x_coor() const { return x; }
	int y_coor() const { return y; }

};

*/




//##############################################   SPEED    ################################################################################
///*
namespace calcc
{
	const int GEN_NO = 30;
	const int SENSE_CONSTANT = 50;
	const float SIZE_SPEED_CONSTANT = 3.0f;
	const float RATIO_TO_REPRODUCE = 0.6f;
	//const int LINEAR_FOOD_GROWTH =30;
	//const int LINEAR_FOOD_GROWTH =15;
	const int LINEAR_FOOD_GROWTH =15;

	const int NUTRIENT_TO_ENERGY = 100;
	const int BIRTHS_POSSIBLE = 3;
	const int TIME_STEP_FOR_FOOD_GROWTH =1;

	const int SIZE_MUTATION = 4;
	const int SPEED_MUTATION = 2;
	const int SENSE_MUTATION = 3;

	//const float SIZE_VARIANCE = 625.0f;
	const float SIZE_VARIANCE = 0.0f;
	const float SPEED_VARIANCE = 12.0f;
	//const float SPEED_VARIANCE = 0.0f;
	//const float SENSE_VARIANCE = 25.0f;
	const float SENSE_VARIANCE = 0.0f;
	
	const float SIGMOID_a = 8.0f;
	const float SIGMOID_b = +3.0f;
}
namespace movement
{
	//
	const int timestep_per_time = 1;
	const int MOVEMENT_PER_TIMESTEP = 5; // move 5 times each timesteps
	//
	const int MOVEMENT_PER_AGE = 10;   // increase age after 10 random movements
	const int MOVEMENT_PER_REPRODUCE = 8 ;
	//
	const int timestep_per_age = MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP;   // increase age after 2 timesteps
	//
}

namespace env
{
	const int INITIAL_NUTRIENT = 5;
	const int NUTRIENT_LIMIT = 10;
	const int DEFAULT_ENV_X = 5;
	const int DEFAULT_ENV_Y = 5;
	const int DEFAULT_POPULATION_ARTIMAL = 10;
	const int DEFAULT_POPULATION_F_RESOURCE = 20;
}

namespace traits
{
	
	const int NUM_TRAITS =3;
	const int SIZE_LIMIT = 2000;
	const int SPEED_LIMIT = 200;
	const int SENSE_LIMIT = 300;
	const int AGE_LIMIT = 15;		
	const int ENERGY_LIMIT = 6000;		//					
	const int REPRODUCTIVITY_LIMIT = 100;
	const int INITIAL_SIZE = (SIZE_LIMIT / 4);
	const int INITIAL_SPEED = (SPEED_LIMIT / 4);
	const int INITIAL_SENSE = (SENSE_LIMIT/3);
	const int INITIAL_ENERGY = (ENERGY_LIMIT / 3);
	const int INITIAL_REPRODUCTIVITY = (REPRODUCTIVITY_LIMIT / 2);	//__________________________________
	const bool INITIAL_rR = 0;

	const int INITIAL_AGE = (AGE_LIMIT / 2);		//
	const int AGE_TRAIT_INIIALIZED = 0;		//
	const int MOVE_STEP_LENGTH = 1;                          ///Const 
	const int VISIBILITY_RADIUS = 3*MOVE_STEP_LENGTH ;





	const int NUM_TRAITS_ENUM = 7;
	const enum trait_value { SIZE, SPEED, SENSE , ENERGY , REPRODUCTIVITY ,AGE , NUTRIENT };  //dont change
	const char*const trait_name[NUM_TRAITS_ENUM] = { "Size","Speed","Sense","Energy","Reproductivity","Nutrient" };


}
namespace randoms
{
	const int INITIAL_SIZE_VARIATION = 20; 
	const int INITIAL_SPEED_VARIATION = 15;
	//const int INITIAL_SPEED_VARIATION = 2;

	const int INITIAL_SENSE_VARIATION = 2;
	const int INITIAL_ENERGY_VARIATION = 200;
	const int INITIAL_REPRODUCTIVITY_VARIATION = 5;   //________________________
	const int INITIAL_AGE_VARIATION = 2;
	const int DEATH_AGE_VARIATION = 1;
	
	const int INITIAL_NUTRIENT_VARIATION = 1;
	const int MUTATION_SIZE_STRENGTH = 10;
	const int MUTAION_SPEED_STRENGTH = 4;
}
	
const int random_upto(const int n_);  // outputs random number from -n_ to +n_
const int random_to(const int n_);  // outputs random number from 0 to +n_
//const float Energy(int speed_, )





class Location
{
private:
	int x;
	int y;
public:
	Location(int x_, int y_) :x(x_), y(y_) {}
	int x_coor() const { return x; }
	int y_coor() const { return y; }

};

//*/



//##############################################   SIZE   ################################################################################
/*
namespace calcc
{
	const int GEN_NO = 30;
	const int SENSE_CONSTANT = 50;
	const float SIZE_SPEED_CONSTANT = 3.0f;
	const float RATIO_TO_REPRODUCE = 0.6f;
	//const int LINEAR_FOOD_GROWTH =30;
	//const int LINEAR_FOOD_GROWTH =15;
	const int LINEAR_FOOD_GROWTH =15;

	const int NUTRIENT_TO_ENERGY = 100;
	const int BIRTHS_POSSIBLE = 3;
	const int TIME_STEP_FOR_FOOD_GROWTH =1;

	const int SIZE_MUTATION = 4;
	const int SPEED_MUTATION = 2;
	const int SENSE_MUTATION = 3;

	const float SIZE_VARIANCE = 625.0f;
	//const float SIZE_VARIANCE = 0.0f;
	//const float SPEED_VARIANCE = 12.0f;
	const float SPEED_VARIANCE = 0.0f;
	//const float SENSE_VARIANCE = 25.0f;
	const float SENSE_VARIANCE = 0.0f;
	
	const float SIGMOID_a = 8.0f;
	const float SIGMOID_b = +3.0f;
}
namespace movement
{
	//
	const int timestep_per_time = 1;
	const int MOVEMENT_PER_TIMESTEP = 5; // move 5 times each timesteps
	//
	const int MOVEMENT_PER_AGE = 10;   // increase age after 10 random movements
	const int MOVEMENT_PER_REPRODUCE = 8 ;
	//
	const int timestep_per_age = MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP;   // increase age after 2 timesteps
	//
}

namespace env
{
	const int INITIAL_NUTRIENT = 5;
	const int NUTRIENT_LIMIT = 10;
	const int DEFAULT_ENV_X = 500;
	const int DEFAULT_ENV_Y = 500;
	const int DEFAULT_POPULATION_ARTIMAL = 10;
	const int DEFAULT_POPULATION_F_RESOURCE = 20;
}

namespace traits
{
	
	const int NUM_TRAITS =3;
	const int SIZE_LIMIT = 2000;
	const int SPEED_LIMIT = 200;
	const int SENSE_LIMIT = 300;
	const int AGE_LIMIT = 15;		
	const int ENERGY_LIMIT = 6000;		//					
	const int REPRODUCTIVITY_LIMIT = 100;
	const int INITIAL_SIZE = (SIZE_LIMIT / 4);
	const int INITIAL_SPEED = (SPEED_LIMIT / 4);
	const int INITIAL_SENSE = (SENSE_LIMIT/3);
	const int INITIAL_ENERGY = (ENERGY_LIMIT / 3);
	const int INITIAL_REPRODUCTIVITY = (REPRODUCTIVITY_LIMIT / 2);	//__________________________________
	const bool INITIAL_rR = 0;

	const int INITIAL_AGE = (AGE_LIMIT / 2);		//
	const int AGE_TRAIT_INIIALIZED = 0;		//
	const int MOVE_STEP_LENGTH = 1;                          ///Const 
	const int VISIBILITY_RADIUS = 3*MOVE_STEP_LENGTH ;





	const int NUM_TRAITS_ENUM = 7;
	const enum trait_value { SIZE, SPEED, SENSE , ENERGY , REPRODUCTIVITY ,AGE , NUTRIENT };  //dont change
	const char*const trait_name[NUM_TRAITS_ENUM] = { "Size","Speed","Sense","Energy","Reproductivity","Nutrient" };


}
namespace randoms
{
	const int INITIAL_SIZE_VARIATION = 20; 
	//const int INITIAL_SPEED_VARIATION = 15;
	const int INITIAL_SPEED_VARIATION = 2;

	const int INITIAL_SENSE_VARIATION = 2;
	const int INITIAL_ENERGY_VARIATION = 200;
	const int INITIAL_REPRODUCTIVITY_VARIATION = 5;   //________________________
	const int INITIAL_AGE_VARIATION = 2;
	const int DEATH_AGE_VARIATION = 1;
	
	const int INITIAL_NUTRIENT_VARIATION = 1;
	const int MUTATION_SIZE_STRENGTH = 10;
	const int MUTAION_SPEED_STRENGTH = 4;
}
	
const int random_upto(const int n_);  // outputs random number from -n_ to +n_
const int random_to(const int n_);  // outputs random number from 0 to +n_
//const float Energy(int speed_, )





class Location
{
private:
	int x;
	int y;
public:
	Location(int x_, int y_) :x(x_), y(y_) {}
	int x_coor() const { return x; }
	int y_coor() const { return y; }

};

*/

//##############################################   SENSE   ################################################################################
/*
namespace calcc
{
	const int GEN_NO = 30;
	const int SENSE_CONSTANT = 50;
	const float SIZE_SPEED_CONSTANT = 3.0f;
	const float RATIO_TO_REPRODUCE = 0.6f;
	//const int LINEAR_FOOD_GROWTH =30;
	//const int LINEAR_FOOD_GROWTH =15; 
	const int LINEAR_FOOD_GROWTH =8;

	const int NUTRIENT_TO_ENERGY = 100;
	const int BIRTHS_POSSIBLE = 3;
	const int TIME_STEP_FOR_FOOD_GROWTH =1;

	const int SIZE_MUTATION = 0;
	//const int SIZE_MUTATION = 0;
	const int SPEED_MUTATION = 0;
	const int SENSE_MUTATION = 3;

	//const float SIZE_VARIANCE = 625.0f;
	const float SIZE_VARIANCE = 0.0f;
	//const float SPEED_VARIANCE = 12.0f;
	const float SPEED_VARIANCE = 0.0f;
	const float SENSE_VARIANCE =49.0f;
	//const float SENSE_VARIANCE = 0.0f;

	const float SIGMOID_a = 8.0f;
	const float SIGMOID_b = 3.0f;
}
namespace movement
{
	//
	const int timestep_per_time = 1;
	const int MOVEMENT_PER_TIMESTEP = 5; // move 5 times each timesteps
	//
	const int MOVEMENT_PER_AGE = 10;   // increase age after 10 random movements
	const int MOVEMENT_PER_REPRODUCE = 8 ;
	//
	const int timestep_per_age = MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP;   // increase age after 2 timesteps
	//
}

namespace env
{
	const int INITIAL_NUTRIENT = 5;
	const int NUTRIENT_LIMIT = 10;
	const int DEFAULT_ENV_X = 5;
	const int DEFAULT_ENV_Y = 5;
	const int DEFAULT_POPULATION_ARTIMAL = 10;
	const int DEFAULT_POPULATION_F_RESOURCE = 20;
}

namespace traits
{

	const int NUM_TRAITS =3;
	const int SIZE_LIMIT = 2000;
	const int SPEED_LIMIT = 200;
	const int SENSE_LIMIT = 300;
	const int AGE_LIMIT = 15;
	const int ENERGY_LIMIT = 6000;		//
	const int REPRODUCTIVITY_LIMIT = 100;
	const int INITIAL_SIZE = (SIZE_LIMIT / 4);
	const int INITIAL_SPEED = (SPEED_LIMIT / 4);
	const int INITIAL_SENSE = (SENSE_LIMIT/3);
	const int INITIAL_ENERGY = (ENERGY_LIMIT / 3);
	const int INITIAL_REPRODUCTIVITY = (REPRODUCTIVITY_LIMIT / 2);	//__________________________________
	const bool INITIAL_rR = 0;

	const int INITIAL_AGE = (AGE_LIMIT / 2);		//
	const int AGE_TRAIT_INIIALIZED = 0;		//
	const int MOVE_STEP_LENGTH = 1;                          ///Const
	const int VISIBILITY_RADIUS = 2*MOVE_STEP_LENGTH ;





	const int NUM_TRAITS_ENUM = 7;
	const enum trait_value { SIZE, SPEED, SENSE , ENERGY , REPRODUCTIVITY ,AGE , NUTRIENT };  //dont change
	const char*const trait_name[NUM_TRAITS_ENUM] = { "Size","Speed","Sense","Energy","Reproductivity","Nutrient" };


}
namespace randoms
{
	const int INITIAL_SIZE_VARIATION = 1;
	//const int INITIAL_SPEED_VARIATION = 15;
	const int INITIAL_SPEED_VARIATION = 1;

	const int INITIAL_SENSE_VARIATION = 5;
	const int INITIAL_ENERGY_VARIATION = 200;
	const int INITIAL_REPRODUCTIVITY_VARIATION = 5;   //________________________
	const int INITIAL_AGE_VARIATION = 2;
	const int DEATH_AGE_VARIATION = 1;

	const int INITIAL_NUTRIENT_VARIATION = 1;
	const int MUTATION_SIZE_STRENGTH = 10;
	const int MUTAION_SPEED_STRENGTH = 4;
}

const int random_upto(const int n_);  // outputs random number from -n_ to +n_
const int random_to(const int n_);  // outputs random number from 0 to +n_
//const float Energy(int speed_, )





class Location
{
private:
	int x;
	int y;
public:
	Location(int x_, int y_) :x(x_), y(y_) {}
	int x_coor() const { return x; }
	int y_coor() const { return y; }

};

*/
























//##############################################SIZE AND SPEED################################################################################
/*
namespace calcc
{
	const int GEN_NO = 30;
	const int SENSE_CONSTANT = 50;
	const float SIZE_SPEED_CONSTANT = 3.0f;
	const float RATIO_TO_REPRODUCE = 0.6f;
	//const int LINEAR_FOOD_GROWTH =30;
	const int LINEAR_FOOD_GROWTH =15;

	const int NUTRIENT_TO_ENERGY = 100;
	const int BIRTHS_POSSIBLE = 3;
	const int TIME_STEP_FOR_FOOD_GROWTH =1;

	const int SIZE_MUTATION = 4;
	const int SPEED_MUTATION = 2;
	const int SENSE_MUTATION = 3;

	const float SIZE_VARIANCE = 625.0f;
	//const float SIZE_VARIANCE = 0.0f;
	const float SPEED_VARIANCE = 12.0f;
	//const float SPEED_VARIANCE = 0.0f;
	//const float SENSE_VARIANCE = 25.0f;
	const float SENSE_VARIANCE = 0.0f;
	
	const float SIGMOID_a = 8.0f;
	const float SIGMOID_b = +3.0f;
}
namespace movement
{
	//
	const int timestep_per_time = 1;
	const int MOVEMENT_PER_TIMESTEP = 5; // move 5 times each timesteps
	//
	const int MOVEMENT_PER_AGE = 10;   // increase age after 10 random movements
	const int MOVEMENT_PER_REPRODUCE = 8 ;
	//
	const int timestep_per_age = MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP;   // increase age after 2 timesteps
	//
}

namespace env
{
	const int INITIAL_NUTRIENT = 5;
	const int NUTRIENT_LIMIT = 10;
	const int DEFAULT_ENV_X = 5;
	const int DEFAULT_ENV_Y = 5;
	const int DEFAULT_POPULATION_ARTIMAL = 10;
	const int DEFAULT_POPULATION_F_RESOURCE = 20;
}

namespace traits
{
	
	const int NUM_TRAITS =3;
	const int SIZE_LIMIT = 2000;
	const int SPEED_LIMIT = 200;
	const int SENSE_LIMIT = 300;
	const int AGE_LIMIT = 15;		
	const int ENERGY_LIMIT = 6000;		//					
	const int REPRODUCTIVITY_LIMIT = 100;
	const int INITIAL_SIZE = (SIZE_LIMIT / 4);
	const int INITIAL_SPEED = (SPEED_LIMIT / 4);
	const int INITIAL_SENSE = (SENSE_LIMIT/3);
	const int INITIAL_ENERGY = (ENERGY_LIMIT / 3);
	const int INITIAL_REPRODUCTIVITY = (REPRODUCTIVITY_LIMIT / 2);	//__________________________________
	const bool INITIAL_rR = 0;

	const int INITIAL_AGE = (AGE_LIMIT / 2);		//
	const int AGE_TRAIT_INIIALIZED = 0;		//
	const int MOVE_STEP_LENGTH = 1;                          ///Const 
	const int VISIBILITY_RADIUS = 3*MOVE_STEP_LENGTH ;





	const int NUM_TRAITS_ENUM = 7;
	const enum trait_value { SIZE, SPEED, SENSE , ENERGY , REPRODUCTIVITY ,AGE , NUTRIENT };  //dont change
	const char*const trait_name[NUM_TRAITS_ENUM] = { "Size","Speed","Sense","Energy","Reproductivity","Nutrient" };


}
namespace randoms
{
	const int INITIAL_SIZE_VARIATION = 20 ; 
	const int INITIAL_SPEED_VARIATION = 15;
	const int INITIAL_SENSE_VARIATION = 2;
	const int INITIAL_ENERGY_VARIATION = 200;
	const int INITIAL_REPRODUCTIVITY_VARIATION = 5;   //________________________
	const int INITIAL_AGE_VARIATION = 2;
	const int DEATH_AGE_VARIATION = 1;
	
	const int INITIAL_NUTRIENT_VARIATION = 1;
	const int MUTATION_SIZE_STRENGTH = 10;
	const int MUTAION_SPEED_STRENGTH = 4;
}
	
const int random_upto(const int n_);  // outputs random number from -n_ to +n_
const int random_to(const int n_);  // outputs random number from 0 to +n_
//const float Energy(int speed_, )





class Location
{
private:
	int x;
	int y;
public:
	Location(int x_, int y_) :x(x_), y(y_) {}
	int x_coor() const { return x; }
	int y_coor() const { return y; }

};
*/











#endif
