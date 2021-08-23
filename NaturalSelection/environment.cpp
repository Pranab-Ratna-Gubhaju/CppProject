#include <cmath>
#include "constants.h"
#include "environment.h"
#include "artimal.h"
#include "calc.h"

#include<vector>

using namespace std;
using namespace env;
using namespace randoms;
using namespace traits;
using namespace movement;
using namespace calcc;


const unsigned int window_size_x = 750;  // x size of the grid in pixels
const unsigned int window_size_y = 300;  // y size of the grid in pixels
sf::RenderWindow window(sf::VideoMode(window_size_x, window_size_y), "E-Sim");
//window.setFramerateLimit(60);

//bool stopSimulation = false;

//cell size
const unsigned int cell_size_x = 50;
const unsigned int cell_size_y = 50;
const unsigned int Nx = window_size_x / cell_size_x;
const unsigned int Ny = window_size_y / cell_size_y;
sf::VertexArray cell(sf::Quads, Nx* Ny * 4);

const int simulation_speed = 10;
const int generationNo = GEN_NO;
int generation = 0;
bool wait = false;

const sf::Color food_color(sf::Color::Yellow);
const sf::Color artimal_color(sf::Color::White);
const sf::Color nofood_color(sf::Color::Green);

sf::Font font;

//F_resource API's
int F_resource::num = 0;


F_resource::F_resource() :
	nutrient(INITIAL_NUTRIENT + random_upto(INITIAL_NUTRIENT_VARIATION), NUTRIENT, NUTRIENT_LIMIT), loc(Location(-1, -1))
{
	num++;
}
F_resource::F_resource(int nutrient_) :
	nutrient(nutrient_, NUTRIENT, NUTRIENT_LIMIT), loc(Location(-1, -1))
{
	num++;
}
F_resource::F_resource(const F_resource&f) :
	nutrient(f.Nutrient(), NUTRIENT, NUTRIENT_LIMIT), loc(f._location())
{
	num++;
}
F_resource::~F_resource()
{	
	num--;
}
Location F_resource::location() const
{

	try
	{
		//if (loc == nullptr) throw notInEnvironmentError();

		if (loc.x_coor() == -1 || loc.y_coor() == -1) throw notInEnvironmentError();
		//exit(0);
		return ((*this).loc);
	}
	catch (const notInEnvironmentError& ee)
	{
		ee.msg();
		return ((*this).loc);
	}

}

bool F_resource::set_location(Environment* env, int x_, int y_)
{
	try
	{
		//loc = new Location(x_, y_);
		if (x_ > env->x_limit() || y_ > env->y_limit() || x_ < 0 || y_ < 0) throw Error();
		loc = Location(x_, y_);

		return 1;
		//return *loc;
	}
	catch (Error e)
	{
		e.msg();
		return 0;
	}
}


//Environment object API's


Environment::Environment(int pop_a, int  pop_r,
	int x_, int y_): rabbits(pop_a)// arguments:num of artimals, num of food in env ,grid (x) , grid(y)
	, foods(pop_r)// arguments:num of artimals, num of food in env ,grid (x) , grid(y)
{
	x = x_;
	y = y_;
}
void Environment::randomize_location()
{
	//std::vector<Artimal>::iterator pA;
	for (Artimal& a: rabbits)
	{
		
		a.set_location(this, (random_upto(this->x_limit())+ this->x_limit())/2,
			(random_upto(this->y_limit())+ this->y_limit())/2);
		a.update_history(*this);
	}
	for (F_resource& f: foods)
	{
		f.set_location(this, (random_upto(this->x_limit())+ this->x_limit())/2,
			(random_upto(this->y_limit())+ this->y_limit())/2);
	}
}

void Environment::random_move()   
{
	for (Artimal& a : rabbits)
	{
		for (int i = 0; i < MOVE_STEP_LENGTH; ++i)
		{
			int x1 = random_upto(1);
			int y1 = random_upto(1);
			int x2 = a.location().x_coor() + x1;
			int y2 = a.location().y_coor() + y1;

			while (x2 < 0 || y2 < 0 || x2 > this->x_limit() || y2 > this->y_limit()
				|| (y1 == 0 && x1 == 0))
			{
				x1 = random_upto(1);
				y1 = random_upto(1);
				x2 = a.location().x_coor() + x1;
				y2 = a.location().y_coor() + y1;
			}
			a.set_location(this, a.location().x_coor() + x1,
				a.location().y_coor() + y1);
			/*
			while (a.location().x_coor()<0   ||  a.location().y_coor()<0  || 
				a.location().x_coor() > this->x_limit()  ||  a.location().y_coor() > this->y_limit()
				|| (y1 == 0 && x1 == 0))
			{
				x1 = random_upto(1);
				y1 = random_upto(1);
				a.set_location(this, a.location().x_coor() + x1,
					a.location().y_coor() + y1);

			}
			*/
		}
	}

}
void Environment::random_move2()   
{
	for (Artimal& a : rabbits)
	{
		if ((*this).See(a))
		{
			//std::vector<Location> L = (*this).seen_location(a);
			std::vector<Location> nL = (*this).seen_nearest_location(a);
			int target_index = (random_to(nL.size() - 1));
			Location target_loc = nL[target_index];
			int distance = int(s_distance(target_loc, a.location()));

			int movement_required = distance / MOVE_STEP_LENGTH;
			cout<<endl<< "movement required for a with size "<<a.Size()<<"::"<<movement_required;
			cout << endl << "target: " << target_loc.x_coor() << " , " << target_loc.y_coor();;

			if (movement_required == 0)
			{
				
				(*this).devour(a, target_loc);
				cout << endl << "Devoured by a with size:" << a.Size() << endl;
				//if (Energy == MAX || (*this).See(a)==0) random move
				// continue the process
				//Energy++ 
				
			}
			else 
			{
				for (int i = 0; i < MOVE_STEP_LENGTH; ++i)  //	moves in the direction of target
				{
					a.set_location(this, (a.location().x_coor()+(target_loc.x_coor() - a.location().x_coor()) / movement_required),
						a.location().y_coor()+(target_loc.y_coor() - a.location().y_coor()) / movement_required);
				}
			}

		}
		//else random_move();
		///*
		else
		{
			for (int i = 0; i < MOVE_STEP_LENGTH; ++i)
			{
				int x1 = random_upto(1);
				int y1 = random_upto(1);
				int x2 = a.location().x_coor() + x1;
				int y2 = a.location().y_coor() + y1;

				while (x2 < 0 || y2 < 0 || x2 > this->x_limit() || y2 > this->y_limit()
				//	)
					|| (y1 == 0 && x1 == 0))
				{
					x1 = random_upto(1);
					y1 = random_upto(1);
					x2 = a.location().x_coor() + x1;
					y2 = a.location().y_coor() + y1;
				}
				a.set_location(this, a.location().x_coor() + x1,
					a.location().y_coor() + y1);
			}

		}
		//*/
	}

}

void Environment::random_move4()   
{
	//for (Artimal& a : rabbits)
	
	for(int i=0; i< rabbits.size() ; ++i)
	{
		std::vector<Location> nL = (*this).seen_nearest_location(rabbits[i]);
		std::vector<Location> L = (*this).seen_nearest_location_senseless(rabbits[i]);
		if (rabbits[i].willReproduce())
		{
			(*this).Reproduce(rabbits[i]);
			rabbits[i].delta_Energy(-1200);
			rabbits[i].set_Recently_Reproduced();
			rabbits[i].clear_movement_to_reproduce();
			//rabbits[i].update_last_history(*this);
		}
		//if ((*this).See(a))
		else if((*this).See(rabbits[i]) 
			//)
			&& (nL.size()>0))
		{
			//std::vector<Location> L = (*this).seen_location(a);
			// 
			//std::vector<Location> nL = (*this).seen_nearest_location(rabbits[i]);
			// 
			//std::vector<Location> nL;
			//for (int j=0;;++j) 
			int target_index = (random_to(nL.size() - 1));
			//Location target_loc_ = nL[target_index];
			Location target_loc = nL[target_index];
			int distance = int(s_distance(target_loc, rabbits[i].location()));
			int movement_required = distance / MOVE_STEP_LENGTH;
			cout << endl << rabbits[i].location().x_coor() << "," << rabbits[i].location().y_coor();
			cout << endl << "Size " <<rabbits[i].Size() <<" ->sees foods: ";
			for (int i = 0; i < nL.size(); ++i)
				cout << "("<<nL[i].x_coor()<<","<< nL[i].y_coor()<<"),";
			cout <<endl<< "Compared: ";
			for (int i = 0; i < L.size(); ++i)
				cout << "("<<L[i].x_coor()<<","<< L[i].y_coor()<<"),";

			cout<<endl<< "movement required for a with size "<<rabbits[i].Size()<<"::"<<movement_required;
			cout << endl << "target: " << target_loc.x_coor() << " , " << target_loc.y_coor();;

			if (movement_required == 0)
			{
				
				(*this).devour(rabbits[i], target_loc);
				cout << endl << "Devoured by a with size:" << rabbits[i].Size() << endl;
				//if (Energy == MAX || (*this).See(a)==0) random move
				// continue the process
				//Energy++ 
			}
			else 
			{
				for (int k = 0; k < MOVE_STEP_LENGTH; ++k)  //	moves in the direction of target
				{
					rabbits[i].set_location(this, (rabbits[i].location().x_coor()+(target_loc.x_coor() - rabbits[i].location().x_coor()) / movement_required),
						rabbits[i].location().y_coor()+(target_loc.y_coor() - rabbits[i].location().y_coor()) / movement_required);
				}
				rabbits[i].delta_Energy(-cost(rabbits[i]));
			}

		}
		//else random_move();
		///*
		else
		{
			for (int k = 0; k < MOVE_STEP_LENGTH; ++k)
			{
				int x1 = random_upto(1);
				int y1 = random_upto(1);
				int x2 = rabbits[i].location().x_coor() + x1;
				int y2 = rabbits[i].location().y_coor() + y1;

				while (x2 < 0 || y2 < 0 || x2 > this->x_limit() || y2 > this->y_limit()
				//	)
					|| (y1 == 0 && x1 == 0))
				{
					x1 = random_upto(1);
					y1 = random_upto(1);
					x2 = rabbits[i].location().x_coor() + x1;
					y2 = rabbits[i].location().y_coor() + y1;
				}
				rabbits[i].set_location(this, rabbits[i].location().x_coor() + x1,
					rabbits[i].location().y_coor() + y1);
				//cout << endl << "a with size:" << rabbits[i].Size();
				//cout << endl << "Energy Removed: " << cost(rabbits[i]);
				//cout << endl << "Energy " << rabbits[i].Energy() << endl;
			}
			rabbits[i].delta_Energy(-cost(rabbits[i]));

		}
		//*/
	}

}

std::vector<Artimal>::iterator pA;
void Environment::random_move3()   
{
	//for (int i=0; i <rabbits.size();++i)
	/*
	for (Artimal& a : rabbits)
	{
		if (a.willReproduce())
		{
			(*this).Reproduce(a);
			a.delta_Energy(-1200);
			cout << endl << "a with size:" << a.Size();
			cout << endl << "Energy Removed: " << 1200;
			cout << endl << "Energy " << a.Energy() << endl;
			//a.set_Recently_Reproduced();
		}
		
		else if ((*this).See(a))
		{
			//std::vector<Location> L = (*this).seen_location(a);
			std::vector<Location> nL = (*this).seen_nearest_location(a);
			int target_index = (random_to(nL.size() - 1));
			Location target_loc = nL[target_index];
			int distance = int(s_distance(target_loc, a.location()));

			int movement_required = distance / MOVE_STEP_LENGTH;
			cout<<endl<< "movement required for a with size "<<a.Size()<<"::"<<movement_required;

			if (movement_required == 0)
			{
				
				(*this).devour(a, target_loc);
				//cout << endl << "Devoured by a with size:" << a.Size() << endl;
				//if (Energy == MAX || (*this).See(a)==0) random move
				// continue the process
				//Energy++ 
				
			}
			else 
			{
				for (int i = 0; i < MOVE_STEP_LENGTH; ++i)  //	moves in the direction of target
				{
					a.set_location(this, (a.location().x_coor()+(target_loc.x_coor() - a.location().x_coor()) / movement_required),
						a.location().y_coor()+(target_loc.y_coor() - a.location().y_coor()) / movement_required);
					a.delta_Energy(-cost(a));
					
					cout << endl << "a with size:" << a.Size();
					cout << endl << "Energy Removed: " << cost(a);
					cout << endl << "Energy " << a.Energy() << endl;
				}
			}

		}
		//else random_move();
		///*
		else
		{
			for (int i = 0; i < MOVE_STEP_LENGTH; ++i)
			{
				int x1 = random_upto(1);
				int y1 = random_upto(1);
				int x2 = a.location().x_coor() + x1;
				int y2 = a.location().y_coor() + y1;

				while (x2 < 0 || y2 < 0 || x2 > this->x_limit() || y2 > this->y_limit()
				//	)
					|| (y1 == 0 && x1 == 0))
				{
					x1 = random_upto(1);
					y1 = random_upto(1);
					x2 = a.location().x_coor() + x1;
					y2 = a.location().y_coor() + y1;
				}
				a.set_location(this, a.location().x_coor() + x1,
					a.location().y_coor() + y1);
				a.delta_Energy(-cost(a));
				cout << endl << "a with size:" << a.Size();
				cout << endl << "Energy Removed: " << cost(a);
				cout << endl << "Energy " << a.Energy() << endl;
			}

		}
		
	}
	*/
	///*
	
	for (int i = 0;i< rabbits.size() ;++i)
	{
		if (rabbits[i].willReproduce())
		{
			(*this).Reproduce(rabbits[i]);
			rabbits[i].delta_Energy(-1200);
			rabbits[i].set_Recently_Reproduced();
			rabbits[i].update_last_history(*this);
		}
		
		else if ((*this).See(rabbits[i]))
		{
			//std::vector<Location> L = (*this).seen_location(a);
			std::vector<Location> nL = (*this).seen_nearest_location(rabbits[i]);
			int target_index = (random_to(nL.size() - 1));
			Location target_loc = nL[target_index];
			int distance = int(s_distance(target_loc, rabbits[i].location()));

			int movement_required = distance / MOVE_STEP_LENGTH;
			cout<<endl<< "movement required for a with size "<< rabbits[i].Size()<<"::"<<movement_required;
			cout<<endl<< "target: "<< target_loc.x_coor() << " , " << target_loc.y_coor();;
			

			if (movement_required == 0)
			{
				
				(*this).devour(rabbits[i], target_loc);
				//rabbits[i].update_last_history(*this);
				//cout << endl << "Devoured by a with size:" << a.Size() << endl;
				//if (Energy == MAX || (*this).See(a)==0) random move
				// continue the process
				//Energy++ 
				
			}
			else 
			{
				for (int i = 0; i < MOVE_STEP_LENGTH; ++i)  //	moves in the direction of target
				{
					rabbits[i].set_location(this, (rabbits[i].location().x_coor()+
						(target_loc.x_coor() - rabbits[i].location().x_coor()) / movement_required),
						rabbits[i].location().y_coor()+(target_loc.y_coor() -
							rabbits[i].location().y_coor()) / movement_required);
					//cout << endl << "Energy1 " << rabbits[i].Energy();
	
					//cout << endl << "a with size:" << rabbits[i].Size();
					//cout << endl << "Energy Removed: " << cost(rabbits[i]);
					//cout << endl << "Energy " << rabbits[i].Energy() << endl;
				}
				rabbits[i].delta_Energy(-cost(rabbits[i]));
				//rabbits[i].update_last_history(*this);
			}

		}
		//else random_move();
		
		else
		{
			for (int i = 0; i < MOVE_STEP_LENGTH; ++i)
			{
				int x1 = random_upto(1);
				int y1 = random_upto(1);
				int x2 = rabbits[i].location().x_coor() + x1;
				int y2 = rabbits[i].location().y_coor() + y1;

				while (x2 < 0 || y2 < 0 || x2 > this->x_limit() || y2 > this->y_limit()
				//	)
					|| (y1 == 0 && x1 == 0))
				{
					x1 = random_upto(1);
					y1 = random_upto(1);
					x2 = rabbits[i].location().x_coor() + x1;
					y2 = rabbits[i].location().y_coor() + y1;
				}
				rabbits[i].set_location(this, rabbits[i].location().x_coor() + x1,
					rabbits[i].location().y_coor() + y1);

				//cout << endl << "Energy1 " << rabbits[i].Energy() ;
				//cout << endl << "a with size:" << rabbits[i].Size();
				//cout << endl << "Energy Removed: " << cost(rabbits[i]);
				//cout << endl << "Energy " << rabbits[i].Energy() << endl;
			}
			rabbits[i].delta_Energy(-cost(rabbits[i]));
			//rabbits[i].update_last_history(*this);

		}
		cout <<endl<< rabbits[i].location().x_coor() << " , " << rabbits[i].location().y_coor();
		
	}
	//*/

}
int deca = LINEAR_FOOD_GROWTH;


void Environment::Startsim(int time_step_)
{
	window.setFramerateLimit(60);
	if (!font.loadFromFile("Fonts/arial.ttf")) {
		std::cout << "Error loading font from file" << std::endl;
		system("pause");
	}
	std::stringstream oss;
	std::string str = "Rabbits ";

	sf::Text text, text2, text3;
	text.setFont(font);
	text.setString(str);
	text.setCharacterSize(25);
	text.setPosition(window_size_x * .5, 70);

	text2.setFont(font);
	text2.setString("Empty cell");
	text2.setCharacterSize(25);
	text2.setPosition(window_size_x * .5, 0);

	text3.setFont(font);
	text3.setString("Food");
	text3.setCharacterSize(25);
	text3.setPosition(window_size_x * .5, 35);

	sf::RectangleShape emptyicon(sf::Vector2f(30, 30));
	emptyicon.setFillColor(nofood_color);
	emptyicon.setPosition(window_size_x * .5 - 30, 0);

	sf::RectangleShape foodicon(sf::Vector2f(30, 30));
	foodicon.setFillColor(food_color);
	foodicon.setPosition(window_size_x * .5 - 30, 35);

	sf::RectangleShape rabbiticon(sf::Vector2f(30, 30));
	rabbiticon.setFillColor(artimal_color);
	rabbiticon.setPosition(window_size_x * 0.5 - 30, 70);

	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed || e.key.code == sf::Keyboard::Escape) window.close(); 

		}

			while (generation != generationNo) {



				for (int i = 1; i <= time_step_; ++i)
				{


					//for (int j = 0; j < MOVEMENT_PER_TIMESTEP; ++j)
					for (int j = 0; j < MOVEMENT_PER_TIMESTEP; ++j)
					{
						for (int m = 0; (rabbits.size() > 1) && (m < (rabbits.size() - 1)); ++m)
						{

							if ((rabbits.size() > 1) && (competitive_value(rabbits[m]) < competitive_value(rabbits[m + 1])))
							{
								Artimal temp = rabbits[m];
								rabbits[m] = rabbits[m + 1];
								rabbits[m + 1] = temp;
							}
						}

						for (int k = 0; k < rabbits.size(); ++k)
						{

							pA = rabbits.begin() + k;
							if (rabbits[k].Energy() < cost(rabbits[k]))
							{
								cout << endl << "Deleted with size " << rabbits[k].Size();
								rabbits.erase(pA);

								--k;
							}
						}
						(*this).random_move4();
						for (int k = 0; k < rabbits.size(); ++k) {
							rabbits[k].increase_movement();
							rabbits[k].increase_movement_to_reproduce();
						}
						//cout << endl << " SIZEEEE" << temp.size();
						//if(temp.size()>=1) cout <<endl <<"location:" << temp[temp.size() - 1].location().x_coor()<<" , " << temp[temp.size() - 1].location().y_coor();
						//cout << endl << " SIZEEEE" << temp.size();
						//cout <<endl<< "HISTORY SIZE:" << rabbits[0].history.size();

						for (int i = 0; i < temp.size(); ++i)
						{
							rabbits.push_back(temp[i]);
							cout << endl << "size:" << rabbits.size();

						}
						//cout <<endl <<"HISTORY SIZE:" << rabbits[0].history.size();
						temp.erase(temp.begin(), temp.end());
						//cout << endl << " SIZEEEE" << temp.size();
						//cout<<endl << rabbits[0].location().x_coor() << " , " << rabbits[0].location().y_coor();
						//cout<<endl << rabbits[1].location().x_coor() << " , " << rabbits[1].location().y_coor();
						cout << "Total rabbits:" << n_artimals();
						//for (int i = 0; i < rabbits.size(); ++i) rabbits[i].update_history(*this);

						for (int k = 0; k < rabbits.size(); ++k)
						{
							if ((rabbits[k].Movement() % MOVEMENT_PER_AGE) == 0)
							{
								pA = rabbits.begin() + k;
								(rabbits[k].Age_range())++;
								//rabbits[k].update_last_history(*this);
								//cout << "SIZE:" << rabbits[0].history.size();
								if (rabbits[k].Age() >= rabbits[k].Age_range().limit())
								{
									rabbits.erase(pA);
									--k;
								}
							}
						}
						///////////Implement Food Search //////////////////
						for (int k = 0; k < rabbits.size(); ++k)
						{

							if ((rabbits[k].Movement_to_reproduce() >= MOVEMENT_PER_REPRODUCE))
							{
								if (rabbits[k].return_rR() == 1)
								{
									rabbits[k].clear_Recently_Reproduced();
									//rabbits[k].update_last_history(*this);
								}

							}
						}

						//cout << "SIZE:" << rabbits[0].history.size();
						// 
						//if ((i%4==0)&& (LINEAR_FOOD_GROWTH<4)) --LINEAR_FOOD_GROWTH;
						GrowFood();

						//if ((i%4==0) && (deca>4)) --deca;
						//GrowFood(deca);


						//draw
						unsigned int counter = 0;
						for (int row = 0; row < (DEFAULT_ENV_X + 1); row++) {
							for (int column = 0; column < (DEFAULT_ENV_Y + 1); column++) {

								cell[counter].position = sf::Vector2f(row * cell_size_x, column * cell_size_y);
								cell[counter + 1].position = sf::Vector2f((row + 1) * cell_size_x, column * cell_size_y);
								cell[counter + 2].position = sf::Vector2f((row + 1) * cell_size_x, (column + 1) * cell_size_y);
								cell[counter + 3].position = sf::Vector2f(row * cell_size_x, (column + 1) * cell_size_y);



								for (int fn = 0; fn < foods.size(); ++fn)
								{
									Location Lf = foods[fn].location();
									//cout << endl << i << ":" << "x = " << La.x_coor() << ", y = " << La.y_coor();

									if (row == Lf.x_coor() && column == Lf.y_coor()) {

										cell[counter].color = food_color;
										cell[counter + 1].color = food_color;
										cell[counter + 2].color = food_color;
										cell[counter + 3].color = food_color;
										break;

									}
									else {


										cell[counter].color = nofood_color;
										cell[counter + 1].color = nofood_color;
										cell[counter + 2].color = nofood_color;
										cell[counter + 3].color = nofood_color;
									}
								}



								for (int an = 0; an < rabbits.size(); ++an)
								{
									Location La = rabbits[an].location();
									if (row == La.x_coor() && column == La.y_coor()) {

										cell[counter].color = artimal_color;
										cell[counter + 1].color = artimal_color;
										cell[counter + 2].color = artimal_color;
										cell[counter + 3].color = artimal_color;
										break;

									}

								}




								counter = counter + 4;
							}//column

						}//row

						oss.str("");
						oss << rabbits.size();
						str = str + "Rabbits: " + oss.str();
						text.setString(str);
						str.clear();



						window.draw(cell);
						window.draw(text);
						window.draw(text2);
						window.draw(text3);
						window.draw(emptyicon);
						window.draw(foodicon);
						window.draw(rabbiticon);
						window.display();
						window.clear();


					}//j

					//cout<<"SIZE:"<<rabbits[0].history.size();
					//cout << endl << "SIZE:" << rabbits[0].history.size()<<endl;
					//cout << rabbits[0].Size();
					 //rabbits[0].display_history(*this);

					update_history();
					//if ((i % TIME_STEP_FOR_FOOD_GROWTH) == 0) GrowFood();


				}//i
				generation++;
			}
		
	}
}

void Environment::Startsim2(int time_step_)
{

	for (int i = 1; i <= time_step_; ++i)
	{


		//for (int j = 0; j < MOVEMENT_PER_TIMESTEP; ++j)
		for (int j = 0; j < MOVEMENT_PER_TIMESTEP; ++j)
		{
			for (int m = 0; (rabbits.size() > 1) && (m < (rabbits.size() - 1)); ++m)
			{

				if ((rabbits.size() > 1) && (competitive_value(rabbits[m]) < competitive_value(rabbits[m + 1])))
				{
					Artimal temp = rabbits[m];
					rabbits[m] = rabbits[m + 1];
					rabbits[m + 1] = temp;
				}
			}

			for (int k = 0; k < rabbits.size(); ++k)
			{

				pA = rabbits.begin() + k;
				if (rabbits[k].Energy() < cost(rabbits[k]))
				{
					cout << endl << "Deleted with size " << rabbits[k].Size();
					rabbits.erase(pA);

					--k;
				}
			}
			(*this).random_move4();
			//cout << endl << " SIZEEEE" << temp.size();
			//if(temp.size()>=1) cout <<endl <<"location:" << temp[temp.size() - 1].location().x_coor()<<" , " << temp[temp.size() - 1].location().y_coor();
			//cout << endl << " SIZEEEE" << temp.size();
			//cout <<endl<< "HISTORY SIZE:" << rabbits[0].history.size();
			for (int i = 0; i < temp.size(); ++i)
			{
				rabbits.push_back(temp[i]);
				cout << endl << "size:" << rabbits.size();

			}
			//cout <<endl <<"HISTORY SIZE:" << rabbits[0].history.size();
			temp.erase(temp.begin(), temp.end());
			//cout << endl << " SIZEEEE" << temp.size();
			//cout<<endl << rabbits[0].location().x_coor() << " , " << rabbits[0].location().y_coor();
			//cout<<endl << rabbits[1].location().x_coor() << " , " << rabbits[1].location().y_coor();
			cout << "Total rabbits:" << n_artimals();
			for (int i = 0; i < rabbits.size(); ++i) rabbits[i].update_history(*this);
		}
		if ((i % (MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP)) == 0)
		{
			for (int k = 0; k < rabbits.size(); ++k)
			{

				pA = rabbits.begin() + k;
				(rabbits[k].Age_range())++;
				rabbits[k].update_last_history(*this);
				//cout << "SIZE:" << rabbits[0].history.size();
				if (rabbits[k].Age() == rabbits[k].Age_range().limit())
				{
					rabbits.erase(pA);
					--k;
				}
			}
			///////////Implement Food Search //////////////////
			for (Artimal& a : rabbits)
				if (a.return_rR() == 1)
				{
					a.clear_Recently_Reproduced();
					a.update_last_history(*this);
				}

			//cout << "SIZE:" << rabbits[0].history.size();

		}
		//cout<<"SIZE:"<<rabbits[0].history.size();
		//cout << endl << "SIZE:" << rabbits[0].history.size()<<endl;
		//cout << rabbits[0].Size();
		 //rabbits[0].display_history(*this);

		update_history();
		if ((i % TIME_STEP_FOR_FOOD_GROWTH) == 0) GrowFood();


	}
}

void Environment::update_history()
{
	avg_size.push_back(avg(rabbits,SIZE));
	sd_size.push_back(sd(rabbits, SIZE));
	avg_speed.push_back(avg(rabbits,SPEED));
	avg_sense.push_back(avg(rabbits,SENSE));
	avg_age.push_back(avg(rabbits,AGE));
	num.push_back(rabbits.size());
}

void Environment::display_history()
{
	cout << endl << endl << "average size over time: [ ";
	for (float f : avg_size) cout  << f << " ,";
	cout << "\b ]";

	cout << endl << endl << "average speed over time: [ ";
	for (float f : avg_speed) cout  << f << " ,";
	cout << "\b ]";

	cout << endl << endl << "average sense over time: [ ";
	for (float f : avg_sense) cout << f << " ,";
	cout << "\b ]";

	cout << endl << endl << "average age over time: [ ";
	for (float f : avg_age) cout  << f << " ,";
	cout << "\b ]";

	cout << endl << endl << "number of rabbits over time: [ ";
	for (float f : num) cout << f << " ,";
	cout << "\b ]";
}

std::vector<F_resource>::iterator pF;
void Environment::devour(Artimal& a, Location& l)
{
	for (int k = 0; k < foods.size(); ++k)
	{

		pF = foods.begin() + k;
		
		if ((foods[k].location().x_coor()==l.x_coor())&& (foods[k].location().y_coor() == l.y_coor())
			&& a.Energy() != ENERGY_LIMIT
			)
		{
			a.delta_Energy(NUTRIENT_TO_ENERGY*foods[k].Nutrient());
			//cout << endl << "Devoured by a with size:" << a.Size();
			//cout << endl << "Energy Added: " << NUTRIENT_TO_ENERGY * foods[k].Nutrient();
			//cout << endl << "Energy " << a.Energy() << endl;
			foods.erase(pF);
			
			--k;
		}
	}
	
}

 
void Environment::Reproduce(Artimal& a_)
{
	Artimal a(a_);
	Traits t = a.return_traits();
	//cout << "Reproducing:" << t.Sense()<<t.Size()<<t.Speed();
	//int s = rabbits.size();
	
	int children = (random_to(BIRTHS_POSSIBLE - 1) + 1);
	//int children = 1;
	//sArtimal& a1 = a;
	//cout << endl << "Reproducing:a with size:" << a.Size();
	for (int i = 0; i < children ; ++i)
	{
		//cout << "Children: " << children;
		//cout << endl << "Reproducing:a with size:" << a.Size();
		//mutation(t);
		Artimal a_child(t.mutate(*this));
		//cout << endl << "child_a with size:" << a_child.Size();
		//cout << endl << "Energy " << a_child.Energy() << endl;
		//cout << endl << "p_Energy " << a1.Energy() << endl;
		//a_child.setEnergy();
		
		a_child.set_location(this, (a.location().x_coor()),
			(a.location().y_coor()));
		//cout << endl << "p_Energy " << a1.Energy() << endl;
		//cout << endl << "p_Size " << a1.Size() << endl;
		//cout <<endl<< "x:" << a_child.location().x_coor()<<",y:" << a_child.location().y_coor();
		//cout <<endl<< n_artimals();
		//pA = rabbits.end();
		
		//rabbits.push_back(a_child);
		(*this).temp.push_back(a_child);
		cout << endl << "size:"<<temp.size();

		//cout << endl<<n_artimals();
		cout << endl << "child_a with size:" << a_child.Size();
		//cout << endl << "Energy " << a_child.Energy();
		//cout << endl << "p_Energy " << a1.Energy() << endl;
		
		//a.delta_Energy(-1200);
		//scout << endl << "a with size:" << a1.Size();
		//cout << endl << "Energy Removed: " << 1200;
		//cout << endl << "Energy " << a1.Energy() << endl;
		
		
	}
	cout << endl << "Reproduced by a with size " << a.Size() << ": " << children << endl;
	cout << n_artimals();
	//for (int i = s; i < (s + children); ++i)
	//	rabbits[s].set_location(this, (random_upto(this->x_limit()) + this->x_limit()) / 2,
	//		(random_upto(this->y_limit()) + this->y_limit()) / 2);

}

void Environment::GrowFood()
{
	int s = foods.size();
	int k = LINEAR_FOOD_GROWTH;
	for (int i=0 ; i<k; ++i)
	{
		F_resource f;
		f.set_location(this, (random_upto(this->x_limit()) + this->x_limit()) / 2,
			(random_upto(this->y_limit()) + this->y_limit()) / 2);
		foods.push_back(f);
	}
	cout << endl << "Foods added: " << LINEAR_FOOD_GROWTH;
}
void Environment::GrowFood(int l)
{
	int s = foods.size();
	int k = l;
	for (int i=0 ; i<k; ++i)
	{
		F_resource f;
		f.set_location(this, (random_upto(this->x_limit()) + this->x_limit()) / 2,
			(random_upto(this->y_limit()) + this->y_limit()) / 2);
		foods.push_back(f);
	}
	cout << endl << "Foods added: " << LINEAR_FOOD_GROWTH;
}


float Environment::e_distance(Location l1, Location l2)
{
	return sqrt((l1.x_coor() - l2.x_coor()) * (l1.x_coor() - l2.x_coor()) + (l1.y_coor() - l2.y_coor()) * (l1.y_coor() - l2.y_coor()));
}
int Environment::s_distance(Location l1, Location l2)
{
	//return 
	int x1 = l1.x_coor() - l2.x_coor();
	int y1 = l1.y_coor() - l2.y_coor();
	return max(abs(x1), abs(y1));
}

bool Environment::See(Artimal& a)
{
	Location l = a.location();
	for (F_resource& f : foods)
		//if (e_distance(f.location(), l) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) return 1;
		//if ((e_distance(f.location(), l)) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) return 1;
		if ((s_distance(f.location(), l)) <= (VISIBILITY_RADIUS )) return 1;
	return 0;
}

std::vector<Location> Environment::seen_location(Artimal& a)
{
	std::vector<Location> L;
	Location l = a.location();
	for (F_resource& f : foods)
		//if (e_distance(f.location(), l) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) L.push_back(f.location());
		//if (int(e_distance(f.location(), l)) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) L.push_back(f.location());
		if ((s_distance(f.location(), l)) <= (VISIBILITY_RADIUS))  L.push_back(f.location());
	return L;
}
std::vector<Location> Environment::seen_nearest_location(Artimal& a)
{
	std::vector<Location> L = (*this).seen_location(a);
	std::vector<Location> nL;
	Location l = a.location();
	//int distance;
	//if(L.size()>0)
	if (L.size() > 0)
	{
		int distance = int(s_distance(L[0], l));

		//else
		//{
		for (int i = 0; i < L.size(); ++i)
		{

			if ((s_distance(L[i], l)) == distance) nL.push_back(L[i]);
			else if (int(s_distance(L[i], l)) < distance)
			{
				distance = int(s_distance(L[i], l));
				nL.erase(nL.begin(), nL.end());
				nL.push_back(L[i]);
			}
		}

		//}
			//if (e_distance(f.location(), l) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) nL.push_back(f.location());
		//if (nL.size() > 0) return nL;
		if (int(s_distance(nL[0], l)) <= 1) return nL;
		else
		{
			float s = sigmoid(float(a.Sense()) / float(SENSE_LIMIT));
			int c = s * 100;
			std::vector<Location>::iterator pL;
			for (int j = 0; j < nL.size(); ++j)
			{
				pL = nL.begin();
				const int r = random_to(100);
				if (r > c)
				{
					nL.erase(pL + j);
					--j;
				}
			}
		}
	}
	return nL;
}

std::vector<Location> Environment::seen_nearest_location_senseless(Artimal& a)
{
	std::vector<Location> L = (*this).seen_location(a);
	std::vector<Location> nL;
	Location l = a.location();
	//int distance;
	//if(L.size()>0)
	if (L.size() > 0)
	{
		int distance = int(s_distance(L[0], l));

		//else
		//{
		for (int i = 0; i < L.size(); ++i)
		{

			if ((s_distance(L[i], l)) == distance) nL.push_back(L[i]);
			else if (int(s_distance(L[i], l)) < distance)
			{
				distance = int(s_distance(L[i], l));
				nL.erase(nL.begin(), nL.end());
				nL.push_back(L[i]);
			}
		}

		//}
			//if (e_distance(f.location(), l) < (VISIBILITY_RADIUS * sqrt(2) + 0.1f)) nL.push_back(f.location());
		//if (nL.size() > 0) return nL;
		//if (int(s_distance(nL[0], l)) <= 1) return nL;
		//else
		//{
		//	float s = sigmoid(float(a.Sense()) / float(SENSE_LIMIT));
		//	int c = s * 100;
		//	std::vector<Location>::iterator pL;
		//	for (int j = 0; j < nL.size(); ++j)
		//	{
		//		pL = nL.begin();
		//		const int r = random_to(100);
		//		if (r > c)
		//		{
		//			nL.erase(pL + j);
		//			--j;
		//		}
		//	}
		//}
	}
	return nL;
}




//std::vector<Artimal>::iterator pA;
/*
void Environment::Startsim(int time_step_)
{

	for (int i = 1; i <= time_step_; ++i)
	{

		for (int j = 0; j < MOVEMENT_PER_TIMESTEP; ++j)
		{
			for (int k = 0; k < rabbits.size(); ++k)
			{

				pA = rabbits.begin() + k;
				if (rabbits[k].Energy() < cost(rabbits[k]))
				{
					cout << endl << "Deleted with size " << rabbits[k].Size();
					rabbits.erase(pA);

					--k;
				}
			}
			(*this).random_move3();
			for (int i = 0; i < rabbits.size(); ++i) rabbits[i].update_history(*this);
			//cout << "SIZE:" << rabbits[0].history.size();

		}
		//cout<<"SIZE:"<<rabbits[0].history.size();
		//cout <<endl<< "SIZE:" << rabbits[0].history.size()<<endl;
		 rabbits[0].display_history(*this);
			if ((i % (MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP)) == 0)
			{
				for (int k = 0; k < rabbits.size(); ++k)
				{

					pA = rabbits.begin() + k;
					(rabbits[k].Age_range())++;
					rabbits[k].update_last_history(*this);
					//cout << "SIZE:" << rabbits[0].history.size();
					if (rabbits[k].Age() == rabbits[k].Age_range().limit())
					{
						rabbits.erase(pA);
						--k;
					}
				}
				///////////Implement Food Search //////////////////
			}
			//for (Artimal& a : rabbits)
			//	if (a.return_rR() == 1)
			//	{
			//		a.clear_Recently_Reproduced();
			//		a.update_last_history(*this);
			//	}
			if ((i % TIME_STEP_FOR_FOOD_GROWTH) == 0) GrowFood();

		
	}
}*/





std::vector<Artimal>& Environment::return_artimals()
{
	return rabbits;
}
std::vector<F_resource>& Environment::return_foods()
{
	return foods;
}

Environment::~Environment()
{
	//delete []rabbits;
	//delete []foods;
}











