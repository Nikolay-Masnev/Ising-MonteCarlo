#include "Lattice.h"
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;

void Lattice::Lattice_Init(){
	for(int i = 0; i < L; i++){
		for(int j = 0; j < L; j++){
			m_Lattice[i][j] = 1;
		}
	}
}

double Lattice::dE(int *point)const{
	double dE = 0;
	int x, y;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			x = point[0] + i;
			y = point[1] + j;
			if( x >= 0 && y >= 0 && x <= L-1 && y <= L-1 && abs(i) + abs(j) == 1){
				dE += 2 * JB * m_Lattice[x][y] * m_Lattice[point[0]][point[1]];
			}
		}
	}
	return dE;
}

double Lattice::Lattice_Energy()const{
	double E = 0;
	for(int i = 0; i < L; i++){
		for(int j = 0; j < L; j++){
			int point[2];
			point[0] = i;
			point[1] = j;
			E += (-dE(point)) / 2;
		}
	}
	return E / 2;
}


bool Lattice::Accept_or_Ignore(int *point){
	double R = exp((-1)*dE(point));
	if(R > 1 || Random_Number() < R){
		return true;
	}
	else{
		return false;
	}
}
void Lattice::Random_Point(int *point){
	for(int i = 0; i < 2; i++){
		point[i] = gis_int(gen);
	}
}
void Lattice::Spin_Flip(int *point){
	m_Lattice[point[0]][point[1]] *= -1;
}
