#include<iostream>


#include "artimal.h"
#include "range.h"
#include "error.h"
#include "constants.h"
#include "environment.h"
#include "calc.h"
#include "plot.h"


int main()
{
	std::srand(time(0));   //for generating random number
	using namespace std;
	using namespace traits;
	using namespace env;
	using namespace movement;
	//typedef Range Trait;ss
	const int simulation_speed = 4;     //use only even number when used in a for loop 

	Environment env(20, 15);
	env.randomize_location();
	std::vector<Artimal>& rabbits = env.return_artimals();
	std::vector<F_resource>& foods = env.return_foods();

	std::vector<Artimal>::iterator pA;
	std::vector<F_resource>::iterator pF;
	//Artimal z = rabbits[1];
	///*
	//int k = int(222222222222);
	//cout << k;


	for (int i = 0; i < foods.size(); ++i)
	{
		Location La = foods[i].location();
		cout << endl << i << ":" << "x = " << La.x_coor() << ", y = " << La.y_coor();
	}
	for (int i = 0; i < rabbits.size(); ++i)
	{
		Location La = rabbits[i].location();
		//Location Lf = foods[i].location();
		rabbits[i].display_all();
		cout << endl << i << ":" << "x = " << La.x_coor() << ", y = " << La.y_coor();
		//cout << endl << "x = " << Lf.x_coor() << ", y = " << Lf.y_coor();
		cout << endl << "_____" << endl;

	}
	cout << endl << endl << "rabbits:" << env.n_artimals() << ", foods:" << env.n_foods() << endl;


	//*/
	/*
	for(int i=0; i<5;++i)
	{
		for (int i = 0; i < MOVEMENT_PER_AGE; ++i)	env.random_move();
		for (Artimal& a : rabbits)s
		{
			a.Age_range()++;

		}
	}

	*/
	env.update_history();
	env.Startsim(simulation_speed);

	/*
	for(int i=0; i<5;++i)
	{
		for (int i = 0; i < MOVEMENT_PER_TIMESTEP; ++i)	env.random_move();
		if ((i % (MOVEMENT_PER_AGE / MOVEMENT_PER_TIMESTEP)) == 0)
		{
			for (int i = 0; i < rabbits.size(); ++i)
			{
				pA = rabbits.begin() + i;
				rabbits[i].Age_range()++;
				if (rabbits[i].Age() == rabbits[i].Age_range().limit())
					rabbits.erase(pA);

		}


			//for (Artimal& a : rabbits)
			//{
			//	pA = ;
			//	a.Age_range()++;

			//}
		}
	}
	*/


	///*
	for (int i = 0; i < rabbits.size(); ++i)
	{
		Location La = rabbits[i].location();
		//Location Lf = foods[i].location();
		rabbits[i].display_all();
		cout << endl << i << ":" << "x = " << La.x_coor() << ", y = " << La.y_coor();
		//cout << endl << "x = " << Lf.x_coor() << ", y = " << Lf.y_coor();
		cout << endl;
	}

	cout << endl << "END";
	cout << endl << endl << "rabbits:" << env.n_artimals() << ", foods:" << env.n_foods() << endl;
	//rabbits[3].display_history(env);
	cout << "Average size:" << avg(rabbits, SIZE);
	cout << "random:" << random_to(100);
	//cout << "Sense:"<<rabbits[0].Sense();
	//cout << "sigmoid:" << float(rabbits[0].Sense()) / (SENSE_LIMIT);
	//cout << "Sigmoid:" << sigmoid(1)<<endl;
	env.display_history();
	//cout << "sigmoid b:" << (exp((-8*(float(rabbits[0].Sense()) / SENSE_LIMIT))+3));
	//*/
	//rabbits[20].display_history(env);

		// Make three vectors, each of length 100 filled with 1s, 2s, and 3s
	//std::vector<int>avg_size = env.avg_size;
	//std::vector<float>avg_speed;
	//std::vector<float>avg_sense;

	//std::vector<int>num;



	
	// Wrap into a vector
	std::vector<std::pair<std::string, std::vector<float>>> vals = { {"Speed", env.avg_size}, {"Size", env.avg_speed}, {"Sense", env.avg_sense},{"Population", env.num} };

	// Write the vector to CSV

	write_csv("Plot.csv", vals);

	return 0;
	//*/



	/*
	//############ important block #################//
	Environment env(10, 10,10,10);
	env.randomize_location();
	std::vector<Artimal>& rabbits = env.return_artimals();
	std::vector<F_resource>& foods = env.return_foods();
	for (int i = 0; i < 10; ++i)
	{
		Location La = rabbits[i].location();
		Location Lf = foods[i].location();
		cout << endl << i << ":" << "x = " << La.x_coor() << ", y = " << La.y_coor();
		cout << endl << "x = " << Lf.x_coor() << ", y = " << Lf.y_coor();
		cout << endl;
	}

	//for (int t = 0; t < 10; ++t)
	env.random_move();
	for (int i = 0; i < 10; ++i)
	{
		Location La = rabbits[i].location();
		Location Lf = foods[i].location();
		rabbits[i].display_all();
		cout << endl <<i<<":"<< "x = " << La.x_coor() << ", y = " << La.y_coor();
		cout << endl << "x = " << Lf.x_coor() << ", y = " << Lf.y_coor();
		cout << endl;
	}
	Artimal::n_artimal();
	//############ important block #################//
	*/

	/*
	Artimal artimal2[500];
	for (int i = 0; i <500; ++i)
	{
		cout << artimal2[i].Size()<<" ";
		cout << artimal2[i].Speed()<<" "<<(i+1)<<endl;
	}
	*/


	/*Artimal artimal[] = {1,2,3,4,5};
	for (int i = 0; i < 5; ++i)
	{
		cout << artimal[i].Size() << endl;s
	}*/
	//F_resource K(2000);
	//cout <<endl<< K.Nutrient();

	/*{
		{
			Environment env(1, 50, 500, 500);
			std::vector<Artimal>&art = env.return_artimals();
			std::vector<F_resource>&fo = env.return_foods();
			std::vector<Artimal>::iterator pA;
			//pA = art.begin() + 3;
			Artimal an(300, 75);
			F_resource f;ss
			Location l1 = an.location();

			an.set_location(&env, 700, 700);
			f.set_location(&env, 200, 200);

			(env.return_artimals()).pop_back();
			fo.push_back(f);
			//Location l = env.return_artimals()[].location();
			//cout << l.x_coor();

			art.push_back(Artimal(200, 90));
			cout<< endl<< env.n_artimals();
			cout <<endl<< endl<< env.n_foods()<<endl;
			F_resource::n_food();
			Artimal::n_artimal();
		}
		Artimal::n_artimal();
	}
	*/


	//art.erase(art.begin(),art.begin()+3);
	//cout << art.size();
	//cout << endl << art[0].Size();
	//*/

	//cout << endl << art[50].Size();
	//for (int i = 0; i < 100; ++i)
	//{
	//	cout<<endl << art[i].Size()<<i;
	//

	//Artimal::n_artimal();
	//F_resource::n_food();


	{
		//Trait Size(2100,SIZE,SIZE_LIMIT);
		//Trait Speed(200,SPEED,SPEED_LIMIT);
		//Traits traits(-2, 300);
		//Artimal artimal(traits);
		//const Traits t = artimal.return_traits();
		//std::cout << t.Size() << " " << t.Speed();
		////std::cout << std::endl << t.Size() << " " << t.Speed();
		//Artimal::n_artimal
		//int i = 0;
		//while (i < 50)
		//{
		//	std::cout << random_upto(10)<<i<<endl;
		//	++i;
		//}
	}
	//Artimal::n_artimal();






	return 0;
}



