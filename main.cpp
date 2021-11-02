#include "Average.h"
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void Read_Params(int64_t &sweeps, double &JB_min, double &JB_max, double &step, int &L)
{
	ifstream file("Parameters.txt");
	vector<double> values(5);
	int counter = 0;
	string line;
	while(getline(file,line))
	{
		istringstream iss(line);
		iss >> values[counter];
		cout <<"Parameter " << counter + 1 << " " << values[counter] << endl;
		counter++;
	}
	L = (int)values[0];
	sweeps = (int64_t)values[1];
	JB_min = values[2];
	JB_max = values[3];
	step = values[4];

}

int main(int argc, char *argv[]){
	auto start = chrono::steady_clock::now();
	int64_t sweeps;
	double JB_min, JB_max, step;
	int L;
	Read_Params(sweeps, JB_min, JB_max, step, L);
	Plot_Data Data;
	Data.Plot(sweeps, JB_min, JB_max, step, L);
	auto end = chrono::steady_clock::now();
	std::chrono::duration<double, ratio<60>> elapsed_seconds = end-start;
	std::cout << "elapsed time: " << elapsed_seconds.count()<< " minutes" << endl;
	return 0;
}
