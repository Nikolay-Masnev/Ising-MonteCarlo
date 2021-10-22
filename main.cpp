#include "Average.h"
#include <iostream>
#include <chrono>

int main(int argc, char *argv[]){
	auto start = std::chrono::steady_clock::now();
	Plot_Data Data;
	Data.Plot(1000000000, 0.1, 4.0, 0.1, 512);
	auto end = std::chrono::steady_clock::now();
	std::chrono::duration<double, ratio<60>> elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count()<< " minutes" << endl;
	return 0;
}
