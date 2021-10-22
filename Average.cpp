#include "Average.h"
#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

void Average::MetA(){
	int64_t Z = 0;
	int64_t M = pow(Get_Side(),2);
	double E_0 = Lattice_Energy();
	double E = E_0;
	double sqr_E = pow(E, 2);
	double av_M = 0;
	double av_sqr_E = 0;
	double av_E = 0;
	double av_C = 0;
	int point[2];
	for(int64_t i = 0; i < NumSamples; i++){
		Random_Point(point);
		if(Accept_or_Ignore(point)){
			M -= 2 * Get_Spin(point);
			E += dE(point);
			sqr_E = pow(E, 2);
			av_sqr_E += sqr_E;
			av_M += abs(M);
			av_E += E;
			Z++;
			Spin_Flip(point);
		}
	}
	if(Z == 0){
		av_M = 1;
		av_E = -1;
		av_C = 0;
	}
	else{
		av_sqr_E /= (pow(E_0, 2) * Z);
		av_M /= (Z * pow(Get_Side(),2));
		av_E /= (Z * abs(E_0));
		av_C = (av_sqr_E - pow(av_E, 2)) * pow(Get_JB(), 2);
	}
	Magnetization = av_M;
	Energy = av_E;
	Capacity = av_C;
}
void Plot_Data::Plot(int64_t N, double m_JB_min, double m_JB_max, double m_step, int L){
		double JB = m_JB_min;
		double step = m_step;
		ofstream f_E("Energy.txt");
		ofstream f_M("Magnetization.txt");
		ofstream f_C("Capacity.txt");
		for(JB; JB <= m_JB_max; JB+= step){
			Average av(N,JB, L);
			av.MetA();
			f_E << 1/JB << ' ' << av.Average_Energy()  << endl;
			f_M << 1/JB << ' ' << av.Average_Magnetization() << endl;
			f_C << 1/JB << ' ' << av.Average_Capacity() << endl;
		}
		f_E.close();
		f_M.close();
		f_C.close();
}
