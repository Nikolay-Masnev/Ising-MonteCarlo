#include "Lattice.h"

using namespace std;

class Average : public Lattice{
private:
	int64_t NumSamples;
	double Energy, Magnetization, Capacity;
public:
	Average(int64_t N, double JB, int L) : Lattice(JB, L), NumSamples(N){}
	void MetA();
	double Average_Magnetization()const{ return Magnetization;}
	double Average_Energy()const{ return Energy;}
	double Average_Capacity()const{ return Capacity;}
};

class Plot_Data{
public:		
	void Plot(int64_t N, double m_JB_min, double m_JB_max, double m_step, int L);
};
