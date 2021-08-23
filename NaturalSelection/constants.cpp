#include<iostream>
#include<cstdlib>
#include<ctime>
#include<random>



const int random_upto(const int n_)  // outputs random number from -n_ to +n_
{
	//std::srand(time(0));
	const int n = 2 * n_;
	return ((std::rand() % (n + 1))) - n_;
}
const int random_to(const int n_)
{
	return ((std::rand() % (n_ + 1)));
}