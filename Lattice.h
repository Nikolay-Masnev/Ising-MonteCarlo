#include <random>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;
class Lattice
{
private:
	const int L;
	vector<vector<int>> m_Lattice;
	double JB;
	random_device rd;
	mt19937 gen{rd()};
	uniform_real_distribution<> gis_real{0.0,1.0};
	uniform_int_distribution<> gis_int{0, L - 1 };
public:
	Lattice(double m_JB, int Side) : L(Side), JB(m_JB), m_Lattice(L, vector<int>(L)){
		Lattice_Init();
	}
	void Spin_Flip(int *point);
	void Lattice_Init();
	double Random_Number(){return gis_real(gen);};
	void Random_Point(int *point);
	bool Accept_or_Ignore(int *point);
	int Get_Spin(int *point)const{return m_Lattice[point[0]][point[1]];}
	int Get_Side()const{return L;};
	double Get_JB()const{return JB;}
	double dE(int *point)const;
	double Lattice_Energy()const;
};
