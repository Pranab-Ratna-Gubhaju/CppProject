#include <string>
#include <fstream>
#include <vector>
#include <utility> // std::pair

#ifndef PLOT_             // aka Artificial Animal
#define PLOT_


void write_csv(std::string filename, std::vector<std::pair<std::string, std::vector<float>>> dataset);
#endif
